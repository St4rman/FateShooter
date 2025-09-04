// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectFate/ProjectFateGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectFateGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
PROJECTFATE_API UClass* Z_Construct_UClass_AProjectFateGameMode();
PROJECTFATE_API UClass* Z_Construct_UClass_AProjectFateGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectFate();
// End Cross Module References

// Begin Class AProjectFateGameMode
void AProjectFateGameMode::StaticRegisterNativesAProjectFateGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AProjectFateGameMode);
UClass* Z_Construct_UClass_AProjectFateGameMode_NoRegister()
{
	return AProjectFateGameMode::StaticClass();
}
struct Z_Construct_UClass_AProjectFateGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ProjectFateGameMode.h" },
		{ "ModuleRelativePath", "ProjectFateGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProjectFateGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AProjectFateGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectFate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectFateGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AProjectFateGameMode_Statics::ClassParams = {
	&AProjectFateGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AProjectFateGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AProjectFateGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AProjectFateGameMode()
{
	if (!Z_Registration_Info_UClass_AProjectFateGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AProjectFateGameMode.OuterSingleton, Z_Construct_UClass_AProjectFateGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AProjectFateGameMode.OuterSingleton;
}
template<> PROJECTFATE_API UClass* StaticClass<AProjectFateGameMode>()
{
	return AProjectFateGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AProjectFateGameMode);
AProjectFateGameMode::~AProjectFateGameMode() {}
// End Class AProjectFateGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AProjectFateGameMode, AProjectFateGameMode::StaticClass, TEXT("AProjectFateGameMode"), &Z_Registration_Info_UClass_AProjectFateGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AProjectFateGameMode), 409122457U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_1715978889(TEXT("/Script/ProjectFate"),
	Z_CompiledInDeferFile_FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectFate_Source_ProjectFate_ProjectFateGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
