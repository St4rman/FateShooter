// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectFate_init() {}
	PROJECTFATE_API UFunction* Z_Construct_UDelegateFunction_ProjectFate_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectFate;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectFate()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectFate.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectFate_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectFate",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x5DC162F8,
				0x4C45686C,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectFate.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectFate.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectFate(Z_Construct_UPackage__Script_ProjectFate, TEXT("/Script/ProjectFate"), Z_Registration_Info_UPackage__Script_ProjectFate, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x5DC162F8, 0x4C45686C));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
