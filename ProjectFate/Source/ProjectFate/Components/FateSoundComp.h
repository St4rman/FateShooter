#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FateSoundComp.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTFATE_API UFateSoundComp : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UFateSoundComp();

protected:
	
	virtual void BeginPlay() override;

public:

	UFUNCTION()
	void PlaySoundAtLocation(USoundBase* SoundToPlay, FVector Location);

	UFUNCTION(NetMulticast, Unreliable)
	void C_PlaySoundAtLocation(USoundBase* SoundToPlay, FVector Location);
	void C_PlaySoundAtLocation_Implementation(USoundBase* SoundToPlay, FVector Location);
};
