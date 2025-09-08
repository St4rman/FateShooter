#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectFate/ProjectFatePickUpComponent.h"
#include "InputMappingContext.h"
#include "FateWeaponBase.generated.h"



UCLASS()
class PROJECTFATE_API AFateWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AProjectFateProjectile> ProjectileClass;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* FireAction;

	
	
	AFateWeaponBase();
	
	UFUNCTION(BlueprintCallable, Category="Weapon")
	bool AttachWeapon(AProjectFateCharacter* TargetCharacter);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="PickUpWeapon")
	UProjectFatePickUpComponent* PickupComponent;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	
	AProjectFateCharacter* Character;

public:
	virtual void Tick(float DeltaTime) override;

	void Fire();
};
