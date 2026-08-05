// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWebNativeBrowser_init() {}
	WEBNATIVEBROWSER_API UFunction* Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserBeforePopupEvent__DelegateSignature();
	WEBNATIVEBROWSER_API UFunction* Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserLoadEndEvent__DelegateSignature();
	WEBNATIVEBROWSER_API UFunction* Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserLoadStateChangedEvent__DelegateSignature();
	WEBNATIVEBROWSER_API UFunction* Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserMessageReceivedEvent__DelegateSignature();
	WEBNATIVEBROWSER_API UFunction* Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserUrlChangedEvent__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_WebNativeBrowser;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_WebNativeBrowser()
	{
		if (!Z_Registration_Info_UPackage__Script_WebNativeBrowser.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserBeforePopupEvent__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserLoadEndEvent__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserLoadStateChangedEvent__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserMessageReceivedEvent__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_WebNativeBrowser_WebNativeBrowserUrlChangedEvent__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/WebNativeBrowser",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xD3CD73A4,
				0xC66FDB2E,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_WebNativeBrowser.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_WebNativeBrowser.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_WebNativeBrowser(Z_Construct_UPackage__Script_WebNativeBrowser, TEXT("/Script/WebNativeBrowser"), Z_Registration_Info_UPackage__Script_WebNativeBrowser, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xD3CD73A4, 0xC66FDB2E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
