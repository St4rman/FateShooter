#include "FateRocketL.h"
#include "ProjectFate/ProjectFateProjectile.h"
#include "ProjectFate/Entities/FateRocket.h"

AFateRocketL::AFateRocketL()
{
	PrimaryActorTick.bCanEverTick = true;
	
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
}

void AFateRocketL::FireProjectile()
{
	Super::FireProjectile();

  	
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			const FVector  SpawnLocation = WeaponMesh->GetSocketLocation("Muzzle");
				
			AProjectFateProjectile* Rocket = World->SpawnActor<AProjectFateProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			Rocket->SetShooter(Cast<AProjectFateCharacter>(GetOwner()));
		}
	}
}

void AFateRocketL::BeginPlay()
{
	Super::BeginPlay();
	
}
