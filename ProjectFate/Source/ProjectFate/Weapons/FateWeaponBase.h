#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectFate/ProjectFatePickUpComponent.h"
#include "ProjectFate/Interfaces/WeaponInterface.h"
#include "InputMappingContext.h"
#include "ProjectFate/Interfaces/WeaponInterface.h"
#include "ProjectFate/CoreHelpers/CoreHelper.h"
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
	
	void SetOwningPawn(AProjectFateCharacter* NewPawn);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="PickUpWeapon")
	UProjectFatePickUpComponent* PickupComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	TEnumAsByte<EWeaponType> WeaponType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	FString ThirdPersonSocketName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon")
	FString FirstPersonSocketName;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	
	AProjectFateCharacter* Character;

	FActorSpawnParameters ActorSpawnParams;
	FRotator SpawnRCache;
	FVector  SpawnLCache;

public:

	void Fire(const AProjectFateCharacter* OwningCharacter);
	void DoShootFlair() const;

	UFUNCTION()
	virtual void FireProjectile();
	
	// UFUNCTION()
	virtual void FireHitScan();
};
