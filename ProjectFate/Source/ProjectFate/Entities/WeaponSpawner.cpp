#include "WeaponSpawner.h"

AWeaponSpawner::AWeaponSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	PedestalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PedestalMesh"));
	PedestalMesh->SetupAttachment(RootComponent);
	
	SpawnWeapon();
}

void AWeaponSpawner::OnPickedUp()
{
	//check timer and then spawn
	GetWorld()->GetTimerManager().SetTimer(FSpawnTimer, this, &AWeaponSpawner::SpawnWeapon, 3.0f);
}

void AWeaponSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
}


void AWeaponSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AWeaponSpawner::SpawnWeapon()
{
	if (WeaponToSpawn != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			AFateWeaponBase* SpawnedWeapon = World->SpawnActor<AFateWeaponBase>(WeaponToSpawn, GetActorLocation() + SpawnOffset , FRotator::ZeroRotator, ActorSpawnParams);
			if (SpawnedWeapon!=nullptr)
			{
				SpawnedWeapon->OnWeaponPickupDel.BindUObject(this, &AWeaponSpawner::OnPickedUp);
			}
		}
	}
}