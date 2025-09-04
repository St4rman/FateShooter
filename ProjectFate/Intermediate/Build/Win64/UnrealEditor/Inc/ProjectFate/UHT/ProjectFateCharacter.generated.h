// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProjectFateCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTFATE_ProjectFateCharacter_generated_h
#error "ProjectFateCharacter.generated.h already included, missing '#pragma once' in ProjectFateCharacter.h"
#endif
#define PROJECTFATE_ProjectFateCharacter_generated_h

#define FID_ProjectFate_Source_ProjectFate_ProjectFateCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectFateCharacter(); \
	friend struct Z_Construct_UClass_AProjectFateCharacter_Statics; \
public: \
	DECLARE_CLASS(AProjectFateCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectFate"), NO_API) \
	DECLARE_SERIALIZER(AProjectFateCharacter)


#define FID_ProjectFate_Source_ProjectFate_ProjectFateCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AProjectFateCharacter(AProjectFateCharacter&&); \
	AProjectFateCharacter(const AProjectFateCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectFateCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectFateCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectFateCharacter) \
	NO_API virtual ~AProjectFateCharacter();


#define FID_ProjectFate_Source_ProjectFate_ProjectFateCharacter_h_19_PROLOG
#define FID_ProjectFate_Source_ProjectFate_ProjectFateCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectFate_Source_ProjectFate_ProjectFateCharacter_h_22_INCLASS_NO_PURE_DECLS \
	FID_ProjectFate_Source_ProjectFate_ProjectFateCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTFATE_API UClass* StaticClass<class AProjectFateCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectFate_Source_ProjectFate_ProjectFateCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
