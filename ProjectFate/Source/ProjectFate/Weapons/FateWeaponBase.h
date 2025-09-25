#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectFate/ProjectFatePickUpComponent.h"
#include "ProjectFate/Interfaces/WeaponInterface.h"
#include "InputMappingContext.h"
#include "ProjectFate/Interfaces/WeaponInterface.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "ProjectFate/CoreHelpers/CoreHelper.h"
#include "FateWeaponBase.generated.h"

class AProjectFateProjectile;


UCLASS()
class PROJECTFATE_API AFateWeaponBase : public AActor, public IWeaponInterface
{
	GENERATED_BODY()

public:
	AFateWeaponBase();
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	UAnimMontage* FireAnimation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;
	
	UFUNCTION(BlueprintCallable, Category="PickUpWeapon")
	bool AttachWeapon(AProjectFateCharacter* TargetCharacter);
	
	void SetOwningPawn(AProjectFateCharacter* NewPawn);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="PickUpWeapon")
	UProjectFatePickUpComponent* PickupComponent;

	//PROPERTIES 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Variables")
	USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(EditDefaultsOnly, Category="Weapon Variables")
	TSubclassOf<class AProjectFateProjectile> ProjectileClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Variables")
	TEnumAsByte<EWeaponType> WeaponType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Variables")
	float WeaponRange;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Variables")
	float WeaponRecoil;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Variables")
	float WeaponFiringRate;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Variables")
	UTexture2D* CrossHairTexture;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Weapon Variables")
	FName SocketName = TEXT("GripPoint");
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="AnimBlueprint")
	TEnumAsByte<EWeaponAnimType> WeaponAnimType;
	
	UPROPERTY(EditAnywhere, Category="Firing")
	UNiagaraSystem* FireEffectMuzzle;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	AProjectFateCharacter* Character;
	FCollisionQueryParams QueryParams;
	FActorSpawnParameters ActorSpawnParams;

	
public:

	void Fire(const AProjectFateCharacter* OwningCharacter);
	void DoShootFlair() const;
	UFUNCTION()
	virtual void FireProjectile();

	virtual void FireHitScan();

	UFUNCTION(BlueprintNativeEvent)
	void DoUIFlair();

	
};
