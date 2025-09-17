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

protected:
	FHitData OutHitData;
};
