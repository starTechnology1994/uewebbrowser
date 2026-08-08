// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WebNativeJsonLibrary.h"

#ifdef WEBNATIVEBROWSERCORE_WebNativeJsonLibrary_generated_h
#error "WebNativeJsonLibrary.generated.h already included, missing '#pragma once' in WebNativeJsonLibrary.h"
#endif
#define WEBNATIVEBROWSERCORE_WebNativeJsonLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FJsonObjectWrapper;

// ********** Begin Class UWebNativeJsonLibrary ****************************************************
#define FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRemoveField); \
	DECLARE_FUNCTION(execSetJsonObjectArray); \
	DECLARE_FUNCTION(execSetJsonObjectField); \
	DECLARE_FUNCTION(execSetJsonBoolArray); \
	DECLARE_FUNCTION(execSetJsonFloatArray); \
	DECLARE_FUNCTION(execSetJsonIntArray); \
	DECLARE_FUNCTION(execSetJsonStringArray); \
	DECLARE_FUNCTION(execSetJsonBoolField); \
	DECLARE_FUNCTION(execSetJsonFloatField); \
	DECLARE_FUNCTION(execSetJsonIntField); \
	DECLARE_FUNCTION(execSetJsonStringField); \
	DECLARE_FUNCTION(execGetFieldNames); \
	DECLARE_FUNCTION(execHasField); \
	DECLARE_FUNCTION(execGetJsonObjectArray); \
	DECLARE_FUNCTION(execGetJsonObjectField); \
	DECLARE_FUNCTION(execGetJsonBoolArray); \
	DECLARE_FUNCTION(execGetJsonFloatArray); \
	DECLARE_FUNCTION(execGetJsonIntArray); \
	DECLARE_FUNCTION(execGetJsonStringArray); \
	DECLARE_FUNCTION(execGetJsonBoolField); \
	DECLARE_FUNCTION(execGetJsonFloatField); \
	DECLARE_FUNCTION(execGetJsonIntField); \
	DECLARE_FUNCTION(execGetJsonStringField); \
	DECLARE_FUNCTION(execCreateEmptyJsonObject); \
	DECLARE_FUNCTION(execJsonObjectToString); \
	DECLARE_FUNCTION(execLoadJsonFromString);


WEBNATIVEBROWSERCORE_API UClass* Z_Construct_UClass_UWebNativeJsonLibrary_NoRegister();

#define FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWebNativeJsonLibrary(); \
	friend struct Z_Construct_UClass_UWebNativeJsonLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend WEBNATIVEBROWSERCORE_API UClass* Z_Construct_UClass_UWebNativeJsonLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UWebNativeJsonLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/WebNativeBrowserCore"), Z_Construct_UClass_UWebNativeJsonLibrary_NoRegister) \
	DECLARE_SERIALIZER(UWebNativeJsonLibrary)


#define FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebNativeJsonLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UWebNativeJsonLibrary(UWebNativeJsonLibrary&&) = delete; \
	UWebNativeJsonLibrary(const UWebNativeJsonLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebNativeJsonLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebNativeJsonLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebNativeJsonLibrary) \
	NO_API virtual ~UWebNativeJsonLibrary();


#define FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h_20_PROLOG
#define FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h_23_INCLASS_NO_PURE_DECLS \
	FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UWebNativeJsonLibrary;

// ********** End Class UWebNativeJsonLibrary ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WNFabTmp_56_096ed726_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
