#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectFate/ProjectFatePickUpComponent.h"
#include "ProjectFate/Interfaces/WeaponInterface.h"
#include "InputMappingContext.h"
#include "ProjectFate/Interfaces/WeaponInterface.h"
#include "FateWeaponBase.generated.h"

class AProjectFateProjectile;


UCLASS()
class PROJECTFATE_API AFateWeaponBase : public AActor, public IWeaponInterface
{
	GENERATED_BODY()

public:
	AFateWeaponBase();
	
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AProjectFateProjectile> ProjectileClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	UAnimMontage* FireAnimation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;
	
	UFUNCTION(BlueprintCallable, Category="Weapon")
	bool AttachWeapon(AProjectFateCharacter* TargetCharacter);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="PickUpWeapon")
	UProjectFatePickUpComponent* PickupComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	TEnumAsByte<EWeaponType> WeaponType;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	
	AProjectFateCharacter* Character;

public:

	void Fire(AProjectFateCharacter* OwningCharacter);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_Fire();
	bool Server_Fire_Validation();
	void Server_Fire_Implemetation();
	
};
