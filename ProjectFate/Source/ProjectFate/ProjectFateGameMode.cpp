// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectFateGameMode.h"
#include "ProjectFateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectFateGameMode::AProjectFateGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
