#include "FateSoundComp.h"

#include "Kismet/GameplayStatics.h"


UFateSoundComp::UFateSoundComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}



void UFateSoundComp::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);
}

void UFateSoundComp::PlaySoundAtLocation(USoundBase* SoundToPlay, FVector Location)
{
	if (GetOwner()->HasAuthority())
	{
		C_PlaySoundAtLocation(SoundToPlay, Location);
	}
}

void UFateSoundComp::C_PlaySoundAtLocation_Implementation(USoundBase* SoundToPlay, FVector Location)
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundToPlay, Location);
}

