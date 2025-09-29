#pragma once

#include "CoreMinimal.h"
#include "FateWeaponBase.h"
#include "ProjectFate/CoreHelpers/CoreStructs.h"
#include "FateNullBlaster.generated.h"

UCLASS()
class PROJECTFATE_API AFateNullBlaster : public AFateWeaponBase
{
	GENERATED_BODY()

public:
	
	AFateNullBlaster();
	virtual void FireHitScan() override;
	void CreateBlackHole();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_OnFire();
	bool Multi_OnFire_Validate();
	void Multi_OnFire_Implementation();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> GravityWell;

	UPROPERTY(EditAnywhere)
	int AmmoCounter;

protected:
	FHitData OutHitData;
};
