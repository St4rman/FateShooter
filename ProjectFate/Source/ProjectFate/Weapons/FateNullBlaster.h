#pragma once

#include "CoreMinimal.h"
#include "FateWeaponBase.h"
#include "FateNullBlaster.generated.h"

UCLASS()
class PROJECTFATE_API AFateNullBlaster : public AFateWeaponBase
{
	GENERATED_BODY()

public:
	
	AFateNullBlaster();
	
	virtual void FireHitScan() override;
};
