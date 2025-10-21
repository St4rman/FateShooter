// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FateWeaponBase.h"
#include "FateRocketL.generated.h"
class AProjectFateProjectile;

UCLASS()
class PROJECTFATE_API AFateRocketL : public AFateWeaponBase
{
	GENERATED_BODY()

public:
	
	AFateRocketL();
	virtual void FireProjectile() override;

	// UPROPERTY(EditAnywhere)
	// TSubclassOf<class AProjectFateProjectile> ProjectileClass;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
