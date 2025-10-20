// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectFate/Weapons/FateWeaponBase.h"
#include "WeaponSpawner.generated.h"

UCLASS()
class PROJECTFATE_API AWeaponSpawner : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PedestalMesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AFateWeaponBase> WeaponToSpawn;
	FActorSpawnParameters ActorSpawnParams;

	UPROPERTY(EditAnywhere)
	FVector SpawnOffset;
	
	
	AWeaponSpawner();
	
	void OnPickedUp();
	
protected:
	virtual void BeginPlay() override;

	void SpawnWeapon();
	FTimerHandle FSpawnTimer;
	
	
public:
	virtual void Tick(float DeltaTime) override;
};
