
#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
// #include "ProjectFate/ProjectFateCharacter.h"
#include "CoreStructs.generated.h"

class AProjectFateCharacter;
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OutHit")
	FVector HitLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OutHit")
	FVector HitDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OutHit")
	AProjectFateCharacter* Shooter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OutHit")
	UNiagaraSystem* HitEffect;

	
	FHitData()
	{
		HitLocation		= FVector::ZeroVector;
		HitDirection	= FVector::ZeroVector;
		Shooter			= nullptr;
		HitEffect		= nullptr;
	}
};
