#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../CoreHelpers/CoreStructs.h"
#include "FateParticleComp.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTFATE_API UFateParticleComp : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UFateParticleComp();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SpawnFateParticles(const FHitData InHit); 
};
