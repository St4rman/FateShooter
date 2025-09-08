#include "FateWeaponBase.h"
#include "EnhancedInputSubsystems.h"

class UEnhancedInputComponent;

AFateWeaponBase::AFateWeaponBase()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	WeaponMesh->SetupAttachment(RootComponent);

	PickupComponent = CreateDefaultSubobject<UProjectFatePickUpComponent>("PickupComponent");
	PickupComponent->SetupAttachment(WeaponMesh);
	
	PrimaryActorTick.bCanEverTick = true;
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



void AFateWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFateWeaponBase::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
}

