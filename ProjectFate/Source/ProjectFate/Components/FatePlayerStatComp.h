#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"
#include "FatePlayerStatComp.generated.h"


class AProjectFateCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTFATE_API UFatePlayerStatComp : public UActorComponent
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(Replicated, VisibleAnywhere)
	float Health; 
	
public:

	UFatePlayerStatComp();
	

protected:
	
	virtual void BeginPlay() override;
	
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerLowerHealth(float InDmg, AProjectFateCharacter* Instigator);
	bool ServerLowerHealth_Validate(float InDmg, AProjectFateCharacter* Instigator);
	void ServerLowerHealth_Implementation(float InDmg, AProjectFateCharacter* Instigator);

	

public:
	UFUNCTION(BlueprintCallable)
	void LowerHealth(float IncomingDamage, AProjectFateCharacter* Instigator);

	UFUNCTION(BlueprintCallable)
	float GetHealth() const {return Health;}
};


