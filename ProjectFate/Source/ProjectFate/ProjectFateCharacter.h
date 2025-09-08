// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CoreHelpers/CoreHelper.h"
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

	UFUNCTION(BlueprintCallable)
	bool ShouldCamLean();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DoCamLean();

	UFUNCTION(BlueprintCallable)
	void SetLocomotionMode(ELocomotionMode To) { CurrentLocomotionMode = To; }
	
	UFUNCTION(BlueprintCallable)
	ELocomotionMode GetCurrentLocomotionMode() { return  CurrentLocomotionMode; }


	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTest();
	bool ServerTest_Validate(){return true;}
	void ServerTest_Implementation(){ UE_LOG(LogTemp, Warning, TEXT("ServerTest Validate")); }
};