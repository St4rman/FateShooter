#include "FateNullBlaster.h"

AFateNullBlaster::AFateNullBlaster()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFateNullBlaster::FireHitScan()
{
	Super::FireHitScan();
	UE_LOG(LogTemp, Warning,  TEXT("Fired Off Null Blaster child Function"));
}



