#include "FatePlayerStatComp.h"

#include "GameFramework/GameMode.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectFate/ProjectFateCharacter.h"
#include "ProjectFate/Interfaces/FateGMInterface.h"


UFatePlayerStatComp::UFatePlayerStatComp()
{
	Health = 100.0f;
}


void UFatePlayerStatComp::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);
	
}

void UFatePlayerStatComp::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFatePlayerStatComp, Health);
}


void UFatePlayerStatComp::ServerLowerHealth_Implementation(float InDmg, AProjectFateCharacter* Instigator)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		LowerHealth(InDmg, Instigator);
	}
}

bool UFatePlayerStatComp::ServerLowerHealth_Validate(float InDmg, AProjectFateCharacter* Instigator)
{
	return true;
}

void UFatePlayerStatComp::LowerHealth(float IncomingDamage, AProjectFateCharacter* Instigator)
{
	if (GetOwnerRole() < ROLE_Authority)
	{
		ServerLowerHealth(IncomingDamage, Instigator);
	}
	
	else
	{
		if (Health - IncomingDamage <=0 )
		{
			Health = 0;
			AProjectFateCharacter* Self = Cast<AProjectFateCharacter>(GetOwner());
			Self->OnPlayerDeath(Instigator->GetPlayerState());
		}
		else
		{
			Health -= IncomingDamage;	
		}
		
	}
}



