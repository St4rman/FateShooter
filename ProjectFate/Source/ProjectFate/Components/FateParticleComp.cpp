#include "FateParticleComp.h"
#include "ProjectFate/ProjectFateCharacter.h"

UFateParticleComp::UFateParticleComp()
{
	SetIsReplicatedByDefault(true);
	PrimaryComponentTick.bCanEverTick = true;
}

void UFateParticleComp::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UFateParticleComp::TickComponent(float DeltaTime, ELevelTick TickType,  FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFateParticleComp::SpawnFateParticles(const FHitData InHit)
{
	FString String = FString::Printf(TEXT("shot by %s"), *InHit.Shooter->GetName());
	DrawDebugString(GetWorld(), InHit.HitLocation, String, nullptr, FColor::Blue, 2.0F, true);
}

