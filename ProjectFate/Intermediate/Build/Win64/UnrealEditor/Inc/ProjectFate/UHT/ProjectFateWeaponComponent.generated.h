// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProjectFateWeaponComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AProjectFateCharacter;
#ifdef PROJECTFATE_ProjectFateWeaponComponent_generated_h
#error "ProjectFateWeaponComponent.generated.h already included, missing '#pragma once' in ProjectFateWeaponComponent.h"
#endif
#define PROJECTFATE_ProjectFateWeaponComponent_generated_h

#define FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEndPlay); \
	DECLARE_FUNCTION(execFire); \
	DECLARE_FUNCTION(execAttachWeapon);


#define FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUProjectFateWeaponComponent(); \
	friend struct Z_Construct_UClass_UProjectFateWeaponComponent_Statics; \
public: \
	DECLARE_CLASS(UProjectFateWeaponComponent, USkeletalMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectFate"), NO_API) \
	DECLARE_SERIALIZER(UProjectFateWeaponComponent)


#define FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UProjectFateWeaponComponent(UProjectFateWeaponComponent&&); \
	UProjectFateWeaponComponent(const UProjectFateWeaponComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UProjectFateWeaponComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UProjectFateWeaponComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UProjectFateWeaponComponent) \
	NO_API virtual ~UProjectFateWeaponComponent();


#define FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h_11_PROLOG
#define FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h_14_INCLASS_NO_PURE_DECLS \
	FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTFATE_API UClass* StaticClass<class UProjectFateWeaponComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectFate_Source_ProjectFate_ProjectFateWeaponComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
