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
