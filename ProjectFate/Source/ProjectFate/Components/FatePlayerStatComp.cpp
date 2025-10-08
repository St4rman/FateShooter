#include "FatePlayerStatComp.h"


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


void UFatePlayerStatComp::ServerLowerHealth_Implementation(float InDmg)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		LowerHealth(InDmg);
	}
}

bool UFatePlayerStatComp::ServerLowerHealth_Validate(float InDmg)
{
	return true;
}

void UFatePlayerStatComp::LowerHealth(float IncomingDamage)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, "UFatePlayerStatComp::LowerHealth");
	if (GetOwnerRole() < ROLE_Authority)
	{
		ServerLowerHealth(IncomingDamage);
	}
	
	else
	{
		if (Health - IncomingDamage <0 )
		{
			Health = 0;
		}
		Health -= IncomingDamage;	
	}
}



