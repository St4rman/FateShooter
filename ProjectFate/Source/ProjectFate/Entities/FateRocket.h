// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectFate/ProjectFateCharacter.h"
#include "ProjectFate/ProjectFateProjectile.h"
#include "FateRocket.generated.h"

UCLASS()
class PROJECTFATE_API AFateRocket : public AProjectFateProjectile
{
	GENERATED_BODY()

public:
	
	AFateRocket();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMeshComponent;
	
protected:
	
	virtual void BeginPlay() override;
	
	FTimerHandle TimerHandle_Lifetime;
	void PostLifeTimeExpired();

	UFUNCTION()
	void OnExplode(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ExplodeForce = 4000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SplashDamage = 21;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DirectHitDamage = 40;
	
public:
	virtual void PostInitializeComponents() override;
	virtual void Tick(float DeltaTime) override;
	
};

