#include "FateNullBlaster.h"

#include "Kismet/KismetMathLibrary.h"

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
		APlayerController* PlayerController = Cast<APlayerController>(Super::Character->GetController());
		const FVector TraceStart = WeaponMesh->GetSocketLocation("Muzzle");
		const FVector TraceEnd = TraceStart + UKismetMathLibrary::GetForwardVector( Super::Character->GetCameraRotation()) * 1000.0f;
		
		GetWorld()->LineTraceSingleByChannel(HitResult,TraceStart, TraceEnd, ECollisionChannel::ECC_WorldStatic, Super::QueryParams);
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, HitResult.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 1.0f);

		// FHitData* CurrentHit = new FHitData(HitResult.Location, Character);
	}
	UE_LOG(LogTemp, Warning,  TEXT("Fired Off Null Blaster child Function"));
}

