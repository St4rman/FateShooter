// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/FateParticleComp.h"
#include "GameFramework/Character.h"
#include "CoreHelpers/CoreHelper.h"
#include "CoreHelpers/CoreStructs.h"
#include "Logging/LogMacros.h"

#include "ProjectFateCharacter.generated.h"

class AFateWeaponBase;
class ACharacter;
class UInputComponent;
class UCharacterMovementComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AProjectFateCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh3P;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Visual, meta = (AllowPrivateAccess = "true"))
	UFateParticleComp* PlayerParticleComp;
	
public:
	AProjectFateCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animation)
	AFateWeaponBase* CurrentWeapon;

protected:
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void PostInitializeComponents() override;
	void TryWeaponFire();
	

	FVector2D MovementCache;
	UCharacterMovementComponent* MovementComp;

	ELocomotionMode CurrentLocomotionMode;

protected:
	
	virtual void NotifyControllerChanged() override;
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	

public:
	
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	USkeletalMeshComponent* GetMesh3P() const { return Mesh3P; }

	
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	UFateParticleComp* GetFateParticleComp()		  const { return PlayerParticleComp; }
	AFateWeaponBase* GetCurrentWeapon()				  const { return CurrentWeapon; }
	
	FVector  GetCameraLocation()	const { return FirstPersonCameraComponent->GetComponentLocation();}
	FRotator GetCameraRotation()	const { return FirstPersonCameraComponent->GetComponentRotation();}
	
	UFUNCTION(BlueprintCallable)
	bool ShouldCamLean();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DoCamLean();

	UFUNCTION(BlueprintCallable)
	void SetLocomotionMode(ELocomotionMode To) { CurrentLocomotionMode = To; }
	
	UFUNCTION(BlueprintCallable)
	ELocomotionMode GetCurrentLocomotionMode() { return  CurrentLocomotionMode; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void CreateHitEffect(FHitData InHit);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerWpnFire();
	bool ServerWpnFire_Validate();
	void ServerWpnFire_Implementation();

	
};