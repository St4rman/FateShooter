// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameFramework/PlayerController.h"
#include "FateGMInterface.generated.h"

class APlayerController;

// This class does not need to be modified.
UINTERFACE()
class UFateGMInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTFATE_API IFateGMInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(Blueprintable, BlueprintNativeEvent, Category = "KillCounter")
	void OnPlayerKill(APlayerState* Player, APlayerState* Target);
};
