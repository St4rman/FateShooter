#include "FateWeaponBase.h"
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
	Character = TargetCharacter;

	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<AFateWeaponBase>())
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
	return true;
}

void AFateWeaponBase::Fire()
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
			const FVector SpawnLocation = WeaponMesh->GetSocketLocation("Muzzle");
    	  
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			World->SpawnActor<AProjectFateProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
    			
		}
	}
}

