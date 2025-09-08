#pragma once
#include "CoreMinimal.h"

UENUM(BlueprintType)
enum ELocomotionMode : uint8
{
	L_Movement	= 0 UMETA(DisplayName = "Normal Movement", ToolTip = "Free, normal locomotion"),
	L_Jumping	= 1 UMETA(DisplayName = "Jumping", Tooltip = "Jumping, faliing"),
	L_Sliding	= 2 UMETA(DisplayName = "Sliding", Tooltip = "Sliding"),
};

class PROJECTFATE_API CoreHelper
{
};


UENUM(BlueprintType)
enum EWeaponType : uint8
{
	L_Generic    = 0 UMETA(DisplayName = "Generic", ToolTip = "Generic"),
	L_Projectile = 1 UMETA(DisplayName = "Normal Projectile", ToolTip = "Fires a projectile, check your projectile class to make sure you ahve one."),
	L_HitScan	 = 2 UMETA(DisplayName = "Line trace firing", ToolTip = "Fires off a linetrace on the server which then can tell if it hit something or not"),
	L_Melee		 = 3 UMETA(DisplayName = "Melee weapon, close range", ToolTip= "Spawns a Hitbox in front of you when you press the button.")
};