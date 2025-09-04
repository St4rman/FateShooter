// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProjectFatePickUpComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AProjectFateCharacter;
class UPrimitiveComponent;
struct FHitResult;
#ifdef PROJECTFATE_ProjectFatePickUpComponent_generated_h
#error "ProjectFatePickUpComponent.generated.h already included, missing '#pragma once' in ProjectFatePickUpComponent.h"
#endif
#define PROJECTFATE_ProjectFatePickUpComponent_generated_h

#define FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_12_DELEGATE \
PROJECTFATE_API void FOnPickUp_DelegateWrapper(const FMulticastScriptDelegate& OnPickUp, AProjectFateCharacter* PickUpCharacter);


#define FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnSphereBeginOverlap);


#define FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUProjectFatePickUpComponent(); \
	friend struct Z_Construct_UClass_UProjectFatePickUpComponent_Statics; \
public: \
	DECLARE_CLASS(UProjectFatePickUpComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectFate"), NO_API) \
	DECLARE_SERIALIZER(UProjectFatePickUpComponent)


#define FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UProjectFatePickUpComponent(UProjectFatePickUpComponent&&); \
	UProjectFatePickUpComponent(const UProjectFatePickUpComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UProjectFatePickUpComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UProjectFatePickUpComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UProjectFatePickUpComponent) \
	NO_API virtual ~UProjectFatePickUpComponent();


#define FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_14_PROLOG
#define FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTFATE_API UClass* StaticClass<class UProjectFatePickUpComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectFate_Source_ProjectFate_ProjectFatePickUpComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
