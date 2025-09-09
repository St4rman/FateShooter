#include "FateWeaponBase.h"

#include "Kismet/GameplayStatics.h"
#include "ProjectFate/ProjectFateProjectile.h"

class UEnhancedInputComponent;

AFateWeaponBase::AFateWeaponBase()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	WeaponMesh->SetupAttachment(RootComponent);

	PickupComponent = CreateDefaultSubobject<UProjectFatePickUpComponent>("PickupComponent");
	PickupComponent->SetupAttachment(WeaponMesh);
	
	PrimaryActorTick.bCanEverTick = true;

	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);


	
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		
	
}


void AFateWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

void AFateWeaponBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

bool AFateWeaponBase::AttachWeapon(AProjectFateCharacter* TargetCharacter)
{
	SetOwningPawn(TargetCharacter);
	
	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<AFateWeaponBase>())
	{
		return false;
	}
	
	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	//check what is what
	if (Character->IsLocallyControlled())
	{
		AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));
	}
	else
	{
		AttachToComponent(Character->GetMesh3P(),AttachmentRules, FName(TEXT("hand_rSocket")));
	}
	return true;
}

void AFateWeaponBase::SetOwningPawn(AProjectFateCharacter* NewPawn)
{
	if ( Character != NewPawn)
	{
		SetInstigator(NewPawn);
		Character = NewPawn;

		SetOwner(Character);
	}
}

void AFateWeaponBase::Fire(AProjectFateCharacter* OwningCharacter)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("client Code"));
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
	else
	{
		if (ProjectileClass != nullptr)
		{
			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
				const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
				const FVector SpawnLocation = WeaponMesh->GetSocketLocation("Muzzle");
		
				SpawnLCache = SpawnLocation;
				SpawnRCache = SpawnRotation;
				
				World->SpawnActor<AProjectFateProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			}
		}
	}
}

