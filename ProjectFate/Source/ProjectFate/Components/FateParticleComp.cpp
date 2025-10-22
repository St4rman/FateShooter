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

void UFateParticleComp::SpawnFateParticles(const FHitData InHit,  bool HasLaser)
{
	ServerFireParticles(InHit, HasLaser);
}

void UFateParticleComp::ServerFireParticles_Implementation(const FHitData InHit, bool HasLaser)
{
	//do rpc here
	NMC_ServerFire(InHit, HasLaser);
}

void UFateParticleComp::NMC_ServerFire_Implementation(const FHitData InHit, bool HasLaser)
{
	
	if (InHit.Shooter !=nullptr)
	{
		AFateWeaponBase* currentWeapon = InHit.Shooter->GetCurrentWeapon();
		UNiagaraSystem* FireEffectMuzzle = currentWeapon->GetFireEffectMuzzle();
		FVector SpawnLocation = currentWeapon->GetMesh()->GetSocketLocation("Muzzle");
	
		const FRotator SpawnRotation = UKismetMathLibrary::MakeRotFromX(InHit.Shooter->GetActorForwardVector());
		if (FireEffectMuzzle != nullptr)
		{
			NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(FireEffectMuzzle,  currentWeapon->GetMesh(), "Muzzle", SpawnLocation, SpawnRotation, EAttachLocation::Type::KeepWorldPosition, true);
		}
		if (Lazer != nullptr && HasLaser)
		{
			auto LazerEffect = UNiagaraFunctionLibrary::SpawnSystemAttached(Lazer,currentWeapon->GetMesh(), "Muzzle", SpawnLocation, SpawnRotation, EAttachLocation::Type::KeepWorldPosition, true);
			FVector LocationCache;
			if (InHit.HitLocation == FVector::ZeroVector)
			{
				LocationCache = SpawnLocation + InHit.HitDirection* currentWeapon->WeaponRange; 
			}
			else
			{
				LocationCache = InHit.HitLocation;
			}
			LazerEffect->SetVariableVec3("Location", LocationCache);
		}
	}
	
}

void UFateParticleComp::SpawnEffectAtPosition(const FVector Location, const FRotator Rotation, UNiagaraSystem* EffectToSpawn, const int Scale)
{
	//tell the server to fire off a netmulticast to the players
	SeverSpawnAtLocation(Location, Rotation, EffectToSpawn, Scale);
}

void UFateParticleComp::SeverSpawnAtLocation_Implementation(const FVector Location, const FRotator Rotation, UNiagaraSystem* EffectToSpawn, const int Scale)
{
	//multicast to clients to spawn the shit
	Nmc_ServerSpawnAtLocation(Location, Rotation, EffectToSpawn, Scale);
}

void UFateParticleComp::Nmc_ServerSpawnAtLocation_Implementation(const FVector Location,  const FRotator Rotation, UNiagaraSystem* EffectToSpawn, const int Scale)
{
	if (EffectToSpawn != nullptr)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), EffectToSpawn , Location, Rotation, FVector(Scale));
	}
}

