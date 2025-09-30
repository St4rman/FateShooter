#include "FateNullBlaster.h"
#include "Kismet/KismetMathLibrary.h"

struct FHitData;

AFateNullBlaster::AFateNullBlaster()
{
	AmmoCounter = 0;
	PrimaryActorTick.bCanEverTick = true;
}

//this should be running on the server
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

		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, true, 1, 0, 0);
		bool bIsHit = GetWorld()->LineTraceSingleByChannel(HitResult,TraceStart, TraceEnd, ECC_WorldStatic, QueryParams);

		//if hit populate data
		if (bIsHit)
		{
			OutHitData.HitLocation = HitResult.Location;
			OutHitData.Shooter	= Character;		
		}

		ShowSparks(OutHitData);
	}
	
	AmmoCounter +=1;

	if (AmmoCounter == 4)
	{
		AmmoCounter = 0;
		CreateBlackHole();
	}
	// Multi_OnFire();
}

void AFateNullBlaster::CreateBlackHole()
{
	const FTransform SpawnTM = FTransform(FRotator::ZeroRotator, OutHitData.HitLocation);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Instigator = Character;
	GetWorld()->SpawnActor<AActor>(GravityWell, SpawnTM, SpawnParams);
	
}

bool AFateNullBlaster::Multi_OnFire_Validate()
{
	return true;
}

void AFateNullBlaster::Multi_OnFire_Implementation()
{
	
	if (HitEffect != nullptr)
	{
		UNiagaraComponent* temp = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), HitEffect, GetActorLocation(), FRotator(0), FVector(1), false , true);
		temp->SetIsReplicated(true);
	}
}

void AFateNullBlaster::ShowSparks_Implementation(FHitData HitData)
{
}



