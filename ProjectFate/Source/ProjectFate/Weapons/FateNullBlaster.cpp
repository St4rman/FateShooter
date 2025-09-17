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

		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, HitResult.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 1.0f);

		OutHitData.HitLocation = HitResult.Location;
		OutHitData.Shooter	= Character;
	}
	CreateBlackHole();
	
}

void AFateNullBlaster::CreateBlackHole()
{
	if (Character->IsLocallyControlled())
	{
		//pull character towards / physics
		UE_LOG(LogTemp, Warning, TEXT("Server"));
		DrawDebugLine(GetWorld(), OutHitData.HitLocation, OutHitData.HitLocation + FVector(0, 0, 9000), FColor::Blue, false, 5.0f, 0, 1.0f);
		
	} else
	{
		//hvisual
		UE_LOG(LogTemp, Warning, TEXT("Client"));
	}
}
