// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "ProjectFate/ProjectFateCharacter.h"
#include "GravityStar.generated.h"

UCLASS()
class PROJECTFATE_API AGravityStar : public AActor
{
	GENERATED_BODY()

public:
	
	AGravityStar();

protected:
	
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UPhysicsConstraintComponent> SpringConstraint;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ExplodeForce = 8000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeTime = 3.0f;

	
	
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	// TObjectPtr<UProjectileMovementComponent> MovementComponent;
	//
	// UPROPERTY(visibleAnywhere, BlueprintReadOnly)
	// TObjectPtr<UParticleSystemComponent> ParticleComp;

	FTimerHandle TimerHandle_Lifetime;

	UPROPERTY()
	TObjectPtr<AProjectFateCharacter> PlayerCharacter;

	FVector GravityDirCache = FVector::DownVector;
	FVector GravityDir;
	bool bIsActive = false; 

	void ResetPlayer();

public:
	void PostInitializeComponents() override;
	
	UFUNCTION()
	void InGravityStar(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

