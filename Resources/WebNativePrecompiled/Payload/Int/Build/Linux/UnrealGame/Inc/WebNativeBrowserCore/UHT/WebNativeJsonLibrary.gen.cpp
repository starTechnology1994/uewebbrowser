// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WebNativeJsonLibrary.h"
#include "JsonObjectWrapper.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeWebNativeJsonLibrary() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary(ETypeConstructPhase);
JSONUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FJsonObjectWrapper(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_WebNativeBrowserCore(ETypeConstructPhase);
WEBNATIVEBROWSERCORE_API UClass* Z_Construct_UClass_UWebNativeJsonLibrary(ETypeConstructPhase);
WEBNATIVEBROWSERCORE_API UClass* Z_Construct_UClass_UWebNativeJsonLibrary(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UWebNativeJsonLibrary Function CreateEmptyJsonObject *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventCreateEmptyJsonObject_Parms
	{
		FJsonObjectWrapper ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Creates an empty JsonObject. Use it as the starting point, then chain Set Json Xxx Field nodes to build up fields. */" },
		{ "DisplayName", "Create Json Object" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Creates an empty JsonObject. Use it as the starting point, then chain Set Json Xxx Field nodes to build up fields." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateEmptyJsonObject constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateEmptyJsonObject constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateEmptyJsonObject Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventCreateEmptyJsonObject_Parms, ReturnValue), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CreateEmptyJsonObject Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "CreateEmptyJsonObject", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventCreateEmptyJsonObject_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventCreateEmptyJsonObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execCreateEmptyJsonObject)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJsonObjectWrapper*)Z_Param__Result=UWebNativeJsonLibrary::CreateEmptyJsonObject();
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function CreateEmptyJsonObject ***********************

// ********** Begin Class UWebNativeJsonLibrary Function GetField **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		int32 OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AutoCreateRefTerm", "OutValue" },
		{ "Category", "WebNative|Json" },
		{ "Comment", "/**\n\x09 * Reads a field into any supported type.\n\x09 * - FieldName empty: converts the whole JsonObject into a struct.\n\x09 * - FieldName set: converts that single field into the output type.\n\x09 * The output pin is a wildcard: connect any variable/struct to choose the type.\n\x09 */" },
		{ "CustomStructureParam", "OutValue" },
		{ "CustomThunk", "true" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Reads a field into any supported type.\n- FieldName empty: converts the whole JsonObject into a struct.\n- FieldName set: converts that single field into the output type.\nThe output pin is a wildcard: connect any variable/struct to choose the type." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetField constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetField constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetField Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetField_Parms, OutValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetField Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UWebNativeJsonLibrary Function GetField ************************************

// ********** Begin Class UWebNativeJsonLibrary Function GetFieldNames *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetFieldNames_Parms
	{
		FJsonObjectWrapper JsonObject;
		TArray<FString> FieldNames;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Gets all field names on the JsonObject. */" },
		{ "DisplayName", "Get Json Field Names" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets all field names on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldNames_MetaData[] = {
		{ "DisplayName", "FieldNames" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFieldNames constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FieldNames;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetFieldNames_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFieldNames constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFieldNames Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetFieldNames_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldNames_Inner = { "FieldNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_FieldNames = { "FieldNames", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetFieldNames_Parms, FieldNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldNames_MetaData), NewProp_FieldNames_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetFieldNames_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetFieldNames Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetFieldNames", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetFieldNames_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetFieldNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetFieldNames)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_TARRAY_REF(FString,Z_Param_Out_FieldNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetFieldNames(Z_Param_Out_JsonObject,Z_Param_Out_FieldNames);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetFieldNames *******************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonBoolArray **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonBoolArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<bool> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Gets a bool array field from the JsonObject. */" },
		{ "DisplayName", "Get Json Bool Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets a bool array field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonBoolArray constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FBoolPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonBoolArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonBoolArray constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonBoolArray Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonBoolArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonBoolArray Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonBoolArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonBoolArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonBoolArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonBoolArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(bool,Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonBoolArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonBoolArray ****************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonBoolField **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonBoolField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		bool OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Gets a bool field from the JsonObject. */" },
		{ "DisplayName", "Get Json Bool Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets a bool field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonBoolField constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_OutValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonBoolField_Parms*)Obj)->OutValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonBoolField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonBoolField constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonBoolField Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonBoolField_Parms), &UHT_STATICS::NewProp_OutValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonBoolField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonBoolField Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonBoolField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonBoolField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonBoolField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonBoolField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_UBOOL_REF(Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonBoolField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonBoolField ****************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonFloatArray *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonFloatArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<float> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Gets a float array field from the JsonObject. */" },
		{ "DisplayName", "Get Json Float Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets a float array field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonFloatArray constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonFloatArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonFloatArray constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonFloatArray Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonFloatArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonFloatArray Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonFloatArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonFloatArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonFloatArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonFloatArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(float,Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonFloatArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonFloatArray ***************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonFloatField *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonFloatField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		float OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Gets a float field from the JsonObject. */" },
		{ "DisplayName", "Get Json Float Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets a float field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonFloatField constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonFloatField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonFloatField constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonFloatField Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatField_Parms, OutValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonFloatField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonFloatField Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonFloatField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonFloatField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonFloatField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonFloatField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonFloatField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonFloatField ***************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonIntArray ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonIntArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<int32> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Gets an int32 array field from the JsonObject. */" },
		{ "DisplayName", "Get Json Int Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets an int32 array field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonIntArray constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonIntArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonIntArray constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonIntArray Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonIntArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonIntArray Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonIntArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonIntArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonIntArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonIntArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(int32,Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonIntArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonIntArray *****************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonIntField ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonIntField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		int32 OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Gets an int32 field from the JsonObject. */" },
		{ "DisplayName", "Get Json Int Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets an int32 field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonIntField constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonIntField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonIntField constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonIntField Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntField_Parms, OutValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonIntField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonIntField Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonIntField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonIntField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonIntField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonIntField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonIntField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonIntField *****************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonObjectArray ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonObjectArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<FJsonObjectWrapper> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Gets an array of nested objects from the JsonObject. */" },
		{ "DisplayName", "Get Json Object Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets an array of nested objects from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonObjectArray constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonObjectArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonObjectArray constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonObjectArray Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(0, nullptr) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonObjectArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonObjectArray Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonObjectArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonObjectArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonObjectArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonObjectArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(FJsonObjectWrapper,Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonObjectArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonObjectArray **************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonObjectField ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonObjectField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		FJsonObjectWrapper OutObject;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Gets a nested object field from the JsonObject as another JsonObject. */" },
		{ "DisplayName", "Get Json Object Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets a nested object field from the JsonObject as another JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutObject_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonObjectField constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutObject;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonObjectField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonObjectField constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonObjectField Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutObject = { "OutObject", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectField_Parms, OutObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutObject_MetaData), NewProp_OutObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonObjectField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonObjectField Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonObjectField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonObjectField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonObjectField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonObjectField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_OutObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonObjectField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutObject);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonObjectField **************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonStringArray ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonStringArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<FString> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Gets a string array field from the JsonObject. */" },
		{ "DisplayName", "Get Json String Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets a string array field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonStringArray constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonStringArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonStringArray constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonStringArray Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonStringArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonStringArray Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonStringArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonStringArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonStringArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonStringArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(FString,Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonStringArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonStringArray **************************

// ********** Begin Class UWebNativeJsonLibrary Function GetJsonStringField ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventGetJsonStringField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		FString OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Gets a string field from the JsonObject. */" },
		{ "DisplayName", "Get Json String Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Gets a string field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutValue_MetaData[] = {
		{ "DisplayName", "Value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJsonStringField constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventGetJsonStringField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJsonStringField constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJsonStringField Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringField_Parms, OutValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonStringField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetJsonStringField Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonStringField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventGetJsonStringField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventGetJsonStringField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetJsonStringField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::GetJsonStringField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_OutValue);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function GetJsonStringField **************************

// ********** Begin Class UWebNativeJsonLibrary Function HasField **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventHasField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Checks whether the field exists on the JsonObject. */" },
		{ "DisplayName", "Has Json Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Checks whether the field exists on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasField constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventHasField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasField constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasField Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventHasField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventHasField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventHasField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HasField Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "HasField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventHasField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventHasField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_HasField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execHasField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::HasField(Z_Param_Out_JsonObject,Z_Param_FieldName);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function HasField ************************************

// ********** Begin Class UWebNativeJsonLibrary Function JsonObjectToString ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventJsonObjectToString_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString OutJsonString;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Serializes a JsonObject back to a JSON string. */" },
		{ "DisplayName", "Json Object To String" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Serializes a JsonObject back to a JSON string." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutJsonString_MetaData[] = {
		{ "DisplayName", "String" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function JsonObjectToString constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutJsonString;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventJsonObjectToString_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function JsonObjectToString constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function JsonObjectToString Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventJsonObjectToString_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_OutJsonString = { "OutJsonString", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventJsonObjectToString_Parms, OutJsonString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutJsonString_MetaData), NewProp_OutJsonString_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventJsonObjectToString_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutJsonString,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function JsonObjectToString Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "JsonObjectToString", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventJsonObjectToString_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventJsonObjectToString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execJsonObjectToString)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutJsonString);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::JsonObjectToString(Z_Param_Out_JsonObject,Z_Param_Out_OutJsonString);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function JsonObjectToString **************************

// ********** Begin Class UWebNativeJsonLibrary Function LoadJsonFromString ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventLoadJsonFromString_Parms
	{
		FString JsonString;
		FJsonObjectWrapper OutJsonObject;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Parses a JSON string into a JsonObject. */" },
		{ "DisplayName", "Load Json From String" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Parses a JSON string into a JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonString_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutJsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadJsonFromString constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonString;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutJsonObject;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventLoadJsonFromString_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadJsonFromString constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadJsonFromString Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_JsonString = { "JsonString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventLoadJsonFromString_Parms, JsonString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonString_MetaData), NewProp_JsonString_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_OutJsonObject = { "OutJsonObject", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventLoadJsonFromString_Parms, OutJsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutJsonObject_MetaData), NewProp_OutJsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventLoadJsonFromString_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonString,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutJsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function LoadJsonFromString Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "LoadJsonFromString", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventLoadJsonFromString_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventLoadJsonFromString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execLoadJsonFromString)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonString);
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_OutJsonObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::LoadJsonFromString(Z_Param_JsonString,Z_Param_Out_OutJsonObject);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function LoadJsonFromString **************************

// ********** Begin Class UWebNativeJsonLibrary Function RemoveField *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventRemoveField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Removes a field from the JsonObject. */" },
		{ "DisplayName", "Remove Json Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Removes a field from the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveField constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventRemoveField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveField constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveField Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventRemoveField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventRemoveField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventRemoveField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RemoveField Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "RemoveField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventRemoveField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventRemoveField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execRemoveField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::RemoveField(Z_Param_Out_JsonObject,Z_Param_FieldName);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function RemoveField *********************************

// ********** Begin Class UWebNativeJsonLibrary Function SetField **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		int32 Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AutoCreateRefTerm", "Value" },
		{ "Category", "WebNative|Json" },
		{ "Comment", "/**\n\x09 * Sets a field to any supported value type.\n\x09 * - FieldName empty: converts the whole struct into the JsonObject.\n\x09 * - FieldName set: sets that single field from the value.\n\x09 * The value pin is a wildcard: connect any variable/struct to choose the type.\n\x09 */" },
		{ "CustomStructureParam", "Value" },
		{ "CustomThunk", "true" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets a field to any supported value type.\n- FieldName empty: converts the whole struct into the JsonObject.\n- FieldName set: sets that single field from the value.\nThe value pin is a wildcard: connect any variable/struct to choose the type." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetField constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetField constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetField Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetField_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetField Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Class UWebNativeJsonLibrary Function SetField ************************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonBoolArray **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonBoolArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<bool> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Sets a bool array field on the JsonObject. */" },
		{ "DisplayName", "Set Json Bool Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets a bool array field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonBoolArray constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonBoolArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonBoolArray constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonBoolArray Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonBoolArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonBoolArray Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonBoolArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonBoolArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonBoolArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonBoolArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(bool,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonBoolArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonBoolArray ****************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonBoolField **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonBoolField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		bool Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Sets a bool field on the JsonObject. */" },
		{ "DisplayName", "Set Json Bool Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets a bool field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonBoolField constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_Value_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonBoolField_Parms*)Obj)->Value = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonBoolField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonBoolField constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonBoolField Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonBoolField_Parms), &UHT_STATICS::NewProp_Value_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonBoolField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonBoolField Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonBoolField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonBoolField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonBoolField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonBoolField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_UBOOL(Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonBoolField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonBoolField ****************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonFloatArray *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonFloatArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<float> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Sets a float array field on the JsonObject. */" },
		{ "DisplayName", "Set Json Float Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets a float array field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonFloatArray constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonFloatArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonFloatArray constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonFloatArray Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonFloatArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonFloatArray Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonFloatArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonFloatArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonFloatArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonFloatArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(float,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonFloatArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonFloatArray ***************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonFloatField *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonFloatField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		float Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Sets a float field on the JsonObject. */" },
		{ "DisplayName", "Set Json Float Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets a float field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonFloatField constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonFloatField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonFloatField constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonFloatField Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatField_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonFloatField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonFloatField Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonFloatField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonFloatField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonFloatField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonFloatField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonFloatField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonFloatField ***************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonIntArray ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonIntArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<int32> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Sets an int32 array field on the JsonObject. */" },
		{ "DisplayName", "Set Json Int Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets an int32 array field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonIntArray constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonIntArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonIntArray constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonIntArray Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonIntArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonIntArray Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonIntArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonIntArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonIntArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonIntArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(int32,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonIntArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonIntArray *****************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonIntField ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonIntField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		int32 Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Sets an int32 field on the JsonObject. */" },
		{ "DisplayName", "Set Json Int Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets an int32 field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonIntField constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonIntField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonIntField constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonIntField Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntField_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonIntField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonIntField Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonIntField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonIntField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonIntField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonIntField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_PROPERTY(FIntProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonIntField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonIntField *****************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonObjectArray ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonObjectArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<FJsonObjectWrapper> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Sets an array of nested objects field on the JsonObject. */" },
		{ "DisplayName", "Set Json Object Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets an array of nested objects field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonObjectArray constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonObjectArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonObjectArray constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonObjectArray Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(0, nullptr) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonObjectArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonObjectArray Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonObjectArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonObjectArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonObjectArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonObjectArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(FJsonObjectWrapper,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonObjectArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonObjectArray **************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonObjectField ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonObjectField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		FJsonObjectWrapper Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Sets a nested object field on the JsonObject. */" },
		{ "DisplayName", "Set Json Object Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets a nested object field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonObjectField constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonObjectField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonObjectField constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonObjectField Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectField_Parms, Value), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonObjectField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonObjectField Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonObjectField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonObjectField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonObjectField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonObjectField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonObjectField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonObjectField **************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonStringArray ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonStringArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<FString> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json Array" },
		{ "Comment", "/** Sets a string array field on the JsonObject. */" },
		{ "DisplayName", "Set Json String Array" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets a string array field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonStringArray constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonStringArray_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonStringArray constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonStringArray Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonStringArray_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonStringArray Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonStringArray", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonStringArray_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonStringArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonStringArray)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_TARRAY_REF(FString,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonStringArray(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonStringArray **************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonStringField ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics
struct UHT_STATICS
{
	struct WebNativeJsonLibrary_eventSetJsonStringField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		FString Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "WebNative|Json" },
		{ "Comment", "/** Sets a string field on the JsonObject. */" },
		{ "DisplayName", "Set Json String Field" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Sets a string field on the JsonObject." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonObject_MetaData[] = {
		{ "DisplayName", "JsonObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetJsonStringField constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WebNativeJsonLibrary_eventSetJsonStringField_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJsonStringField constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJsonStringField Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 2150a2daa7f5594e535e82b894a37a1391b6d6f8
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringField_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonStringField_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetJsonStringField Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonStringField", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::WebNativeJsonLibrary_eventSetJsonStringField_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::WebNativeJsonLibrary_eventSetJsonStringField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetJsonStringField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper,Z_Param_Out_JsonObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UWebNativeJsonLibrary::SetJsonStringField(Z_Param_Out_JsonObject,Z_Param_FieldName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function SetJsonStringField **************************

// ********** Begin Class UWebNativeJsonLibrary ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UWebNativeJsonLibrary_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/**\n * Built-in JSON Blueprint Function Library.\n * pure-Blueprint projects can package without extra plugins. Everything here\n * is backed by the engine's built-in Json / JsonUtilities runtime modules,\n * which are always available on every target platform.\n *\n * Works both in Blueprints (Edit > Plugins search \"WebNative|Json\") and in\n * C++ (call UWebNativeJsonLibrary::Xxx directly).\n */" },
		{ "IncludePath", "WebNativeJsonLibrary.h" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Built-in JSON Blueprint Function Library.\npure-Blueprint projects can package without extra plugins. Everything here\nis backed by the engine's built-in Json / JsonUtilities runtime modules,\nwhich are always available on every target platform.\n\nWorks both in Blueprints (Edit > Plugins search \"WebNative|Json\") and in\nC++ (call UWebNativeJsonLibrary::Xxx directly)." },
	};
#endif // WITH_METADATA

// ********** Begin Class UWebNativeJsonLibrary constinit property declarations ********************
// ********** End Class UWebNativeJsonLibrary constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CreateEmptyJsonObject"), .Pointer = &UWebNativeJsonLibrary::execCreateEmptyJsonObject },
		{ .NameUTF8 = UTF8TEXT("GetField"), .Pointer = &UWebNativeJsonLibrary::execGetField },
		{ .NameUTF8 = UTF8TEXT("GetFieldNames"), .Pointer = &UWebNativeJsonLibrary::execGetFieldNames },
		{ .NameUTF8 = UTF8TEXT("GetJsonBoolArray"), .Pointer = &UWebNativeJsonLibrary::execGetJsonBoolArray },
		{ .NameUTF8 = UTF8TEXT("GetJsonBoolField"), .Pointer = &UWebNativeJsonLibrary::execGetJsonBoolField },
		{ .NameUTF8 = UTF8TEXT("GetJsonFloatArray"), .Pointer = &UWebNativeJsonLibrary::execGetJsonFloatArray },
		{ .NameUTF8 = UTF8TEXT("GetJsonFloatField"), .Pointer = &UWebNativeJsonLibrary::execGetJsonFloatField },
		{ .NameUTF8 = UTF8TEXT("GetJsonIntArray"), .Pointer = &UWebNativeJsonLibrary::execGetJsonIntArray },
		{ .NameUTF8 = UTF8TEXT("GetJsonIntField"), .Pointer = &UWebNativeJsonLibrary::execGetJsonIntField },
		{ .NameUTF8 = UTF8TEXT("GetJsonObjectArray"), .Pointer = &UWebNativeJsonLibrary::execGetJsonObjectArray },
		{ .NameUTF8 = UTF8TEXT("GetJsonObjectField"), .Pointer = &UWebNativeJsonLibrary::execGetJsonObjectField },
		{ .NameUTF8 = UTF8TEXT("GetJsonStringArray"), .Pointer = &UWebNativeJsonLibrary::execGetJsonStringArray },
		{ .NameUTF8 = UTF8TEXT("GetJsonStringField"), .Pointer = &UWebNativeJsonLibrary::execGetJsonStringField },
		{ .NameUTF8 = UTF8TEXT("HasField"), .Pointer = &UWebNativeJsonLibrary::execHasField },
		{ .NameUTF8 = UTF8TEXT("JsonObjectToString"), .Pointer = &UWebNativeJsonLibrary::execJsonObjectToString },
		{ .NameUTF8 = UTF8TEXT("LoadJsonFromString"), .Pointer = &UWebNativeJsonLibrary::execLoadJsonFromString },
		{ .NameUTF8 = UTF8TEXT("RemoveField"), .Pointer = &UWebNativeJsonLibrary::execRemoveField },
		{ .NameUTF8 = UTF8TEXT("SetField"), .Pointer = &UWebNativeJsonLibrary::execSetField },
		{ .NameUTF8 = UTF8TEXT("SetJsonBoolArray"), .Pointer = &UWebNativeJsonLibrary::execSetJsonBoolArray },
		{ .NameUTF8 = UTF8TEXT("SetJsonBoolField"), .Pointer = &UWebNativeJsonLibrary::execSetJsonBoolField },
		{ .NameUTF8 = UTF8TEXT("SetJsonFloatArray"), .Pointer = &UWebNativeJsonLibrary::execSetJsonFloatArray },
		{ .NameUTF8 = UTF8TEXT("SetJsonFloatField"), .Pointer = &UWebNativeJsonLibrary::execSetJsonFloatField },
		{ .NameUTF8 = UTF8TEXT("SetJsonIntArray"), .Pointer = &UWebNativeJsonLibrary::execSetJsonIntArray },
		{ .NameUTF8 = UTF8TEXT("SetJsonIntField"), .Pointer = &UWebNativeJsonLibrary::execSetJsonIntField },
		{ .NameUTF8 = UTF8TEXT("SetJsonObjectArray"), .Pointer = &UWebNativeJsonLibrary::execSetJsonObjectArray },
		{ .NameUTF8 = UTF8TEXT("SetJsonObjectField"), .Pointer = &UWebNativeJsonLibrary::execSetJsonObjectField },
		{ .NameUTF8 = UTF8TEXT("SetJsonStringArray"), .Pointer = &UWebNativeJsonLibrary::execSetJsonStringArray },
		{ .NameUTF8 = UTF8TEXT("SetJsonStringField"), .Pointer = &UWebNativeJsonLibrary::execSetJsonStringField },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject, "CreateEmptyJsonObject" }, // aae7dd5fe522663e9b40609c0e671e8f17ff5bb9
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetField, "GetField" }, // bf003eb5e008b573bd55d9e789ce32ff9ba8a1d4
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames, "GetFieldNames" }, // 1a24b9f0086dcbed9c323cc3713c5bdb3b5aa035
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray, "GetJsonBoolArray" }, // dd8edd9d17b58d6c22c7bf9aa4b90c0bbe1af357
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField, "GetJsonBoolField" }, // e97f2b1a30247721acfe35a577f5576a90a825bf
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray, "GetJsonFloatArray" }, // ca3ad34e7eb6d60068a4bc525fd7f0d126be6909
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField, "GetJsonFloatField" }, // 057c538a695d727be52c14a9238a58d8c514e98c
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray, "GetJsonIntArray" }, // 9be4670359e1e215ca1eb4e4d70f3cf567c2db7f
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField, "GetJsonIntField" }, // 4f3a422df8974894a2fc847746b1ab2f54a4a301
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray, "GetJsonObjectArray" }, // 5fbd207155af0434f29e7634a2ea9e7b5c30797c
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField, "GetJsonObjectField" }, // 834cc17b9f918dba7c4e76a796862e57e16dec2e
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray, "GetJsonStringArray" }, // 4fba28be6b9f25fe6724e3a032b7fb4f648a0c61
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField, "GetJsonStringField" }, // 9544037b830cd027704f55dec0d58031409a943c
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_HasField, "HasField" }, // cca0666e98c747db4dab336e3384cb5cd49208ee
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString, "JsonObjectToString" }, // 2548ded877b1ab4e1b339fd5b6147157ab38751b
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString, "LoadJsonFromString" }, // 2578619257869c471355f5fb6156f32c762e7e7b
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField, "RemoveField" }, // 2937be4ce3efaa12195e2e9f2a06b27c0a888e8b
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetField, "SetField" }, // 29258d9efb55d1c43fbe10c96e008a71ca9f71d5
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray, "SetJsonBoolArray" }, // 3f66a5b6189875ce63ffd3e49958b8e40f95fecd
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField, "SetJsonBoolField" }, // 063a10ff24cd3f6e78eabc214d33a93cb4607018
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray, "SetJsonFloatArray" }, // 7a965e8c869133d8b631bf8f2044dc470a51b180
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField, "SetJsonFloatField" }, // fee66a3538fa521c3321ff58fd98d4d253a6d696
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray, "SetJsonIntArray" }, // 79f97980289e4ffbddb319a86518c2c2497a20d7
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField, "SetJsonIntField" }, // d28929be92ef34568959a3eac2b1e9587bcc20d1
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray, "SetJsonObjectArray" }, // 9cb3f1bf3822c40692d888c0ff9f43e0deecea96
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField, "SetJsonObjectField" }, // ac34532c5460b2620c17d9a0966642b89d483444
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray, "SetJsonStringArray" }, // 3d3a94fe41da7fb20d350ecd8bf7892872e974bd
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField, "SetJsonStringField" }, // 12640405b52e1f02b6a2df8bf9e85245248c40a8
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWebNativeJsonLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UBlueprintFunctionLibrary,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_WebNativeBrowserCore,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UWebNativeJsonLibrary,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UWebNativeJsonLibrary_StaticRegisterNativesUWebNativeJsonLibrary()
{
	UClass* Class = UWebNativeJsonLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UWebNativeJsonLibrary;
UClass* Z_Construct_UClass_UWebNativeJsonLibrary(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UWebNativeJsonLibrary;
		if (!Z_Registration_Info_UClass_UWebNativeJsonLibrary.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("WebNativeJsonLibrary"),
				Z_Registration_Info_UClass_UWebNativeJsonLibrary.InnerSingleton,
				UWebNativeJsonLibrary_StaticRegisterNativesUWebNativeJsonLibrary,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UWebNativeJsonLibrary.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UWebNativeJsonLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWebNativeJsonLibrary.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UWebNativeJsonLibrary.OuterSingleton;
}
#undef UHT_STATICS
UWebNativeJsonLibrary::UWebNativeJsonLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UWebNativeJsonLibrary);
UWebNativeJsonLibrary::~UWebNativeJsonLibrary() {}
// ********** End Class UWebNativeJsonLibrary ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_WNFabTmp_58_af0dc7eb_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h__Script_WebNativeBrowserCore_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWebNativeJsonLibrary, TEXT("UWebNativeJsonLibrary"), &Z_Registration_Info_UClass_UWebNativeJsonLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWebNativeJsonLibrary), 72737546U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WNFabTmp_58_af0dc7eb_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h__Script_WebNativeBrowserCore_bec83697c08334f08176f9f5dee3ee56c66abba8{
	TEXT("/Script/WebNativeBrowserCore"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
