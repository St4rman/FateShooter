#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../CoreHelpers/CoreStructs.h"
#include "FateParticleComp.generated.h"


class UNiagaraSystem;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTFATE_API UFateParticleComp : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UFateParticleComp();

	UPROPERTY(EditAnywhere)
	UNiagaraComponent* NiagaraComponent;
	
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* Lazer;

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SpawnFateParticles(const FHitData InHit, bool HasLaser);

	UFUNCTION(Server, Reliable)
	void ServerFireParticles(const FHitData InHit ,bool HasLaser);
	void ServerFireParticles_Implementation(const FHitData InHit,bool HasLaser);

	UFUNCTION(NetMulticast, Reliable)
	void NMC_ServerFire(const FHitData InHit, bool HasLaser);
	void NMC_ServerFire_Implementation(const FHitData InHit, bool HasLaser);

	UFUNCTION(BlueprintCallable)
	UNiagaraComponent* GetNiagaraComponent(){ return NiagaraComponent; }

	UFUNCTION(BlueprintCallable)
	void SpawnEffectAtPosition(const FVector Location, const FRotator Rotation, UNiagaraSystem* EffectToSpawn, const int Scale); 

	UFUNCTION(Server, Reliable)
	void SeverSpawnAtLocation(const FVector Location, const FRotator Rotation, UNiagaraSystem* EffectToSpawn, const int Scale);
	void SeverSpawnAtLocation_Implementation(const FVector Location, const FRotator Rotation, UNiagaraSystem* EffectToSpawn, const int Scale);

	UFUNCTION(NetMulticast, Unreliable)
	void Nmc_ServerSpawnAtLocation(const FVector Location, const FRotator Rotation, UNiagaraSystem* EffectToSpawn, const int Scale);
	void Nmc_ServerSpawnAtLocation_Implementation(const FVector Location, const FRotator Rotation, UNiagaraSystem* EffectToSpawn, const int Scale);
	
	
};
