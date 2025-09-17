
#pragma once

#include "CoreMinimal.h"
#include "ProjectFate/ProjectFateCharacter.h"
#include "CoreStructs.generated.h"
/**
 * Class for all structs
 */
class PROJECTFATE_API CoreStructs
{
public:
	CoreStructs();
	~CoreStructs();
};

USTRUCT(BlueprintType)
struct FHitData
{
	GENERATED_USTRUCT_BODY()
	FVector HitLocation;
	AProjectFateCharacter* Shooter;

	FHitData()
	{
		HitLocation = FVector(0, 0, 0);
		Shooter = nullptr;
	}
};
