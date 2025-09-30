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

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SpawnFateParticles(const FHitData InHit);

	UFUNCTION(Server, Reliable)
	void ServerFireParticles(const FHitData InHit);
	void ServerFireParticles_Implementation(const FHitData InHit);

	UFUNCTION(NetMulticast, Reliable)
	void NMC_ServerFire(const FHitData InHit);
	void NMC_ServerFire_Implementation(const FHitData InHit);

	UFUNCTION(BlueprintCallable)
	UNiagaraComponent* GetNiagaraComponent(){ return NiagaraComponent; }
};
