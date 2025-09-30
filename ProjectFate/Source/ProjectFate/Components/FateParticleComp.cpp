#include "FateParticleComp.h"

#include "NiagaraFunctionLibrary.h"
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

void UFateParticleComp::TickComponent(float DeltaTime, ELevelTick TickType,  FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UFateParticleComp::SpawnFateParticles(const FHitData InHit)
{
	ServerFireParticles(InHit);
}

void UFateParticleComp::ServerFireParticles_Implementation(const FHitData InHit)
{
	//do rpc here
	NMC_ServerFire(InHit);
}

void UFateParticleComp::NMC_ServerFire_Implementation(const FHitData InHit)
{
	//ALL CLIENTS SHOULD FIRE THIS
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), InHit.HitEffect , InHit.HitLocation);
}



