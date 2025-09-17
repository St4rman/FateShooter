// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectFateCharacter.h"
#include "ProjectFateProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Weapons/FateWeaponBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PawnMovementComponent.h"
class UCharacterMovementComponent;

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AProjectFateCharacter

AProjectFateCharacter::AProjectFateCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));
	
	Mesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ThirdPerson3P"));
	Mesh3P->SetOnlyOwnerSee(false);
	Mesh3P->SetupAttachment(GetCapsuleComponent());
	Mesh3P->SetRelativeLocation(FVector(0, 0, -90.0f));
	Mesh3P->SetRelativeRotation(FRotator(0.f, -90.0f, 0.f));
	
}

//////////////////////////////////////////////////////////////////////////// Input

void AProjectFateCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AProjectFateCharacter::PostInitializeComponents()
{
	MovementComp = GetCharacterMovement();
	MovementComp->GravityScale = 2.2f;
	MovementComp->MaxAcceleration = 5000.0f;
	
	MovementComp->GroundFriction = 4.0f;
	MovementComp->MaxWalkSpeed= 1000.0f;
	MovementComp->BrakingDecelerationWalking = 100.f;
	
	MovementComp->JumpZVelocity = 800.0f;
	MovementComp->AirControl = 0.6f;

	ACharacter::PostInitializeComponents();
	
}

void AProjectFateCharacter::TryWeaponFire()
{
	if (CurrentWeapon != nullptr)
	{
		if (!HasAuthority())
		{
			CurrentWeapon->Fire(this);
		}
		ServerWpnFire();
	}
	
}

void AProjectFateCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProjectFateCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AProjectFateCharacter::Look);

		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &AProjectFateCharacter::TryWeaponFire);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void AProjectFateCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	MovementCache = MovementVector;
	
	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AProjectFateCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

/*
 * Quake like camera lean
 */
bool AProjectFateCharacter::ShouldCamLean()
{
	float CurrentVelocity = GetVelocity().Length();
	bool bShouldLean = false;
	bShouldLean = ! MovementComp->IsFalling() && CurrentVelocity > 200.0f && MovementCache.X != 0.0f;
	return bShouldLean;
}

bool AProjectFateCharacter::ServerWpnFire_Validate()
{
	// UE_LOG(LogTemp, Warning, TEXT("Server_OnFire Validation called"));
	if (CurrentWeapon)
	{
		return true;
	}
	return false;
}


void AProjectFateCharacter::ServerWpnFire_Implementation()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Fire(this);
	}
}

