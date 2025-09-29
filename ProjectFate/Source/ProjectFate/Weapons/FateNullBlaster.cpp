#include "FateNullBlaster.h"
#include "Kismet/KismetMathLibrary.h"

struct FHitData;

AFateNullBlaster::AFateNullBlaster()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFateNullBlaster::FireHitScan()
{
	Super::FireHitScan();
	
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		FHitResult HitResult;
		
		APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
		const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
		
		const FVector TraceStart = WeaponMesh->GetSocketLocation("Muzzle");
		const FVector TraceEnd = TraceStart + UKismetMathLibrary::GetForwardVector( SpawnRotation) * WeaponRange;
		
		GetWorld()->LineTraceSingleByChannel(HitResult,TraceStart, TraceEnd, ECC_WorldStatic, QueryParams);
		
		OutHitData.HitLocation = HitResult.Location;
		OutHitData.Shooter	= Character;
	}
	CreateBlackHole();
	
}

void AFateNullBlaster::CreateBlackHole()
{
	if (Character->IsLocallyControlled() /**&& canShootBlackHole**/ )
	{
		//S
		const FTransform SpawnTM = FTransform(FRotator::ZeroRotator, OutHitData.HitLocation);
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.Instigator = Character;
		// GetWorld()->SpawnActor<AActor>(GravityWell, SpawnTM, SpawnParams);
		
	} else
	{
		//hvisual
		UE_LOG(LogTemp, Warning, TEXT("Client"));
	}
}
