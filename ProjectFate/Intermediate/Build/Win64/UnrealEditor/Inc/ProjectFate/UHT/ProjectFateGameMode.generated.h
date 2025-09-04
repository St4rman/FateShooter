// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ProjectFateGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTFATE_ProjectFateGameMode_generated_h
#error "ProjectFateGameMode.generated.h already included, missing '#pragma once' in ProjectFateGameMode.h"
#endif
#define PROJECTFATE_ProjectFateGameMode_generated_h

#define FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectFateGameMode(); \
	friend struct Z_Construct_UClass_AProjectFateGameMode_Statics; \
public: \
	DECLARE_CLASS(AProjectFateGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectFate"), PROJECTFATE_API) \
	DECLARE_SERIALIZER(AProjectFateGameMode)


#define FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AProjectFateGameMode(AProjectFateGameMode&&); \
	AProjectFateGameMode(const AProjectFateGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PROJECTFATE_API, AProjectFateGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectFateGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectFateGameMode) \
	PROJECTFATE_API virtual ~AProjectFateGameMode();


#define FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_9_PROLOG
#define FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTFATE_API UClass* StaticClass<class AProjectFateGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
