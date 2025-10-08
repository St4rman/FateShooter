#include "FatePlayerStatComp.h"

#include "ProjectFate/ProjectFateCharacter.h"


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

	//replicates it to everyone
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
		if (Health - IncomingDamage <0 )
		{
			Health = 0;	
			Cast<AProjectFateCharacter>(GetOwner())->OnPlayerDeath();
		}
		Health -= IncomingDamage;	
	}
}



