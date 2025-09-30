#include "FateParticleComp.h"

#include "NiagaraFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "ProjectFate/ProjectFateCharacter.h"
#include "ProjectFate/Weapons/FateWeaponBase.h"

UFateParticleComp::UFateParticleComp()
{
	SetIsReplicatedByDefault(true);
	PrimaryComponentTick.bCanEverTick = true;
	
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>("NiagaraComponent");
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
	//hit effect
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), InHit.HitEffect , InHit.HitLocation);

	//fire barell
	if (InHit.Shooter !=nullptr)
	{
		auto currentWeapon = InHit.Shooter->GetCurrentWeapon();
		UNiagaraSystem* FireEffectMuzzle = currentWeapon->GetFireEffectMuzzle();
		FVector SpawnLocation = currentWeapon->GetMesh()->GetSocketLocation("Muzzle");
	
		const FRotator SpawnRotation = UKismetMathLibrary::MakeRotFromX(InHit.Shooter->GetActorForwardVector());
		if (FireEffectMuzzle != nullptr)
		{
			NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(FireEffectMuzzle,  currentWeapon->GetMesh(), "Muzzle", SpawnLocation, SpawnRotation, EAttachLocation::Type::KeepWorldPosition, true);
		}
	}
	
}