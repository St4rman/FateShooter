// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProjectFateWeaponComponent.h"
#include "ProjectFateCharacter.h"
#include "ProjectFateProjectile.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/AnimInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"

UProjectFateWeaponComponent::UProjectFateWeaponComponent()
{
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
}


void UProjectFateWeaponComponent::Fire()
{
	if (Character == nullptr || Character->GetController() == nullptr)
	{
		return;
	}

	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);
	
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
			World->SpawnActor<AProjectFateProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}
	
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, Character->GetActorLocation());
	}
	
	if (FireAnimation != nullptr)
	{
		UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

bool UProjectFateWeaponComponent::AttachWeapon(AProjectFateCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	
	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<UProjectFateWeaponComponent>())
	{
		return false;
	}

	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	if (Character->IsLocallyControlled())
	{
		AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));
	}
	else
	{
		AttachToComponent(Character->GetMesh3P(),AttachmentRules, FName(TEXT("hand_rSocket")));
	}
	
	
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(FireMappingContext, 1);
		}

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UProjectFateWeaponComponent::Fire);
		}
	}

	return true;
}

void UProjectFateWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	
	if (Character != nullptr)
	{
		
		if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->RemoveMappingContext(FireMappingContext);
			}
		}
	}
	Super::EndPlay(EndPlayReason);
}