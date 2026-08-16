// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WebNativeJsonLibrary.h"
#include "JsonObjectWrapper.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeWebNativeJsonLibrary() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
JSONUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FJsonObjectWrapper();
UPackage* Z_Construct_UPackage__Script_WebNativeBrowserCore();
WEBNATIVEBROWSERCORE_API UClass* Z_Construct_UClass_UWebNativeJsonLibrary();
WEBNATIVEBROWSERCORE_API UClass* Z_Construct_UClass_UWebNativeJsonLibrary_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UWebNativeJsonLibrary Function CreateEmptyJsonObject *********************
struct Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics
{
	struct WebNativeJsonLibrary_eventCreateEmptyJsonObject_Parms
	{
		FJsonObjectWrapper ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventCreateEmptyJsonObject_Parms, ReturnValue), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 219379207
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "CreateEmptyJsonObject", Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::WebNativeJsonLibrary_eventCreateEmptyJsonObject_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::WebNativeJsonLibrary_eventCreateEmptyJsonObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWebNativeJsonLibrary::execCreateEmptyJsonObject)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJsonObjectWrapper*)Z_Param__Result=UWebNativeJsonLibrary::CreateEmptyJsonObject();
	P_NATIVE_END;
}
// ********** End Class UWebNativeJsonLibrary Function CreateEmptyJsonObject ***********************

// ********** Begin Class UWebNativeJsonLibrary Function GetField **********************************
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics
{
	struct WebNativeJsonLibrary_eventGetField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		int32 OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetField_Parms, OutValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetField", Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::WebNativeJsonLibrary_eventGetField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::WebNativeJsonLibrary_eventGetField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetField_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UWebNativeJsonLibrary Function GetField ************************************

// ********** Begin Class UWebNativeJsonLibrary Function GetFieldNames *****************************
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics
{
	struct WebNativeJsonLibrary_eventGetFieldNames_Parms
	{
		FJsonObjectWrapper JsonObject;
		TArray<FString> FieldNames;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FieldNames;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetFieldNames_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_FieldNames_Inner = { "FieldNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_FieldNames = { "FieldNames", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetFieldNames_Parms, FieldNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldNames_MetaData), NewProp_FieldNames_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetFieldNames_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetFieldNames_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_FieldNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_FieldNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetFieldNames", Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::WebNativeJsonLibrary_eventGetFieldNames_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::WebNativeJsonLibrary_eventGetFieldNames_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonBoolArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<bool> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FBoolPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonBoolArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonBoolArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonBoolArray", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::WebNativeJsonLibrary_eventGetJsonBoolArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::WebNativeJsonLibrary_eventGetJsonBoolArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonBoolField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		bool OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_OutValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonBoolField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_OutValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonBoolField_Parms*)Obj)->OutValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonBoolField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_OutValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonBoolField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonBoolField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonBoolField", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::WebNativeJsonLibrary_eventGetJsonBoolField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::WebNativeJsonLibrary_eventGetJsonBoolField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonFloatArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<float> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonFloatArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonFloatArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonFloatArray", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::WebNativeJsonLibrary_eventGetJsonFloatArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::WebNativeJsonLibrary_eventGetJsonFloatArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonFloatField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		float OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonFloatField_Parms, OutValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonFloatField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonFloatField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonFloatField", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::WebNativeJsonLibrary_eventGetJsonFloatField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::WebNativeJsonLibrary_eventGetJsonFloatField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonIntArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<int32> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonIntArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonIntArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonIntArray", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::WebNativeJsonLibrary_eventGetJsonIntArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::WebNativeJsonLibrary_eventGetJsonIntArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonIntField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		int32 OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonIntField_Parms, OutValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonIntField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonIntField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonIntField", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::WebNativeJsonLibrary_eventGetJsonIntField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::WebNativeJsonLibrary_eventGetJsonIntField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonObjectArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<FJsonObjectWrapper> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(0, nullptr) }; // 219379207
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) }; // 219379207
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonObjectArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonObjectArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonObjectArray", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::WebNativeJsonLibrary_eventGetJsonObjectArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::WebNativeJsonLibrary_eventGetJsonObjectArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonObjectField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		FJsonObjectWrapper OutObject;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutObject;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_OutObject = { "OutObject", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonObjectField_Parms, OutObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutObject_MetaData), NewProp_OutObject_MetaData) }; // 219379207
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonObjectField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonObjectField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_OutObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonObjectField", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::WebNativeJsonLibrary_eventGetJsonObjectField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::WebNativeJsonLibrary_eventGetJsonObjectField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonStringArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<FString> OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_OutValue_Inner = { "OutValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringArray_Parms, OutValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonStringArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonStringArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_OutValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonStringArray", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::WebNativeJsonLibrary_eventGetJsonStringArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::WebNativeJsonLibrary_eventGetJsonStringArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics
{
	struct WebNativeJsonLibrary_eventGetJsonStringField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		FString OutValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_OutValue = { "OutValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventGetJsonStringField_Parms, OutValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutValue_MetaData), NewProp_OutValue_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventGetJsonStringField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventGetJsonStringField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_OutValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "GetJsonStringField", Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::WebNativeJsonLibrary_eventGetJsonStringField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::WebNativeJsonLibrary_eventGetJsonStringField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics
{
	struct WebNativeJsonLibrary_eventHasField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventHasField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventHasField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventHasField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventHasField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "HasField", Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::WebNativeJsonLibrary_eventHasField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::WebNativeJsonLibrary_eventHasField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_HasField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_HasField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics
{
	struct WebNativeJsonLibrary_eventJsonObjectToString_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString OutJsonString;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutJsonString;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventJsonObjectToString_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::NewProp_OutJsonString = { "OutJsonString", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventJsonObjectToString_Parms, OutJsonString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutJsonString_MetaData), NewProp_OutJsonString_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventJsonObjectToString_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventJsonObjectToString_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::NewProp_OutJsonString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "JsonObjectToString", Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::WebNativeJsonLibrary_eventJsonObjectToString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::WebNativeJsonLibrary_eventJsonObjectToString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics
{
	struct WebNativeJsonLibrary_eventLoadJsonFromString_Parms
	{
		FString JsonString;
		FJsonObjectWrapper OutJsonObject;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonString;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutJsonObject;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::NewProp_JsonString = { "JsonString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventLoadJsonFromString_Parms, JsonString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonString_MetaData), NewProp_JsonString_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::NewProp_OutJsonObject = { "OutJsonObject", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventLoadJsonFromString_Parms, OutJsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutJsonObject_MetaData), NewProp_OutJsonObject_MetaData) }; // 219379207
void Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventLoadJsonFromString_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventLoadJsonFromString_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::NewProp_JsonString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::NewProp_OutJsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "LoadJsonFromString", Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::WebNativeJsonLibrary_eventLoadJsonFromString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::WebNativeJsonLibrary_eventLoadJsonFromString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics
{
	struct WebNativeJsonLibrary_eventRemoveField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventRemoveField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventRemoveField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventRemoveField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventRemoveField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "RemoveField", Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::WebNativeJsonLibrary_eventRemoveField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::WebNativeJsonLibrary_eventRemoveField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics
{
	struct WebNativeJsonLibrary_eventSetField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		int32 Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetField_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetField", Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::WebNativeJsonLibrary_eventSetField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::WebNativeJsonLibrary_eventSetField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetField_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UWebNativeJsonLibrary Function SetField ************************************

// ********** Begin Class UWebNativeJsonLibrary Function SetJsonBoolArray **************************
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonBoolArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<bool> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonBoolArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonBoolArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonBoolArray", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::WebNativeJsonLibrary_eventSetJsonBoolArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::WebNativeJsonLibrary_eventSetJsonBoolArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonBoolField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		bool Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_Value_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonBoolField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_Value_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonBoolField_Parms*)Obj)->Value = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonBoolField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_Value_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonBoolField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonBoolField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonBoolField", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::WebNativeJsonLibrary_eventSetJsonBoolField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::WebNativeJsonLibrary_eventSetJsonBoolField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonFloatArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<float> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonFloatArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonFloatArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonFloatArray", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::WebNativeJsonLibrary_eventSetJsonFloatArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::WebNativeJsonLibrary_eventSetJsonFloatArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonFloatField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		float Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonFloatField_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonFloatField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonFloatField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonFloatField", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::WebNativeJsonLibrary_eventSetJsonFloatField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::WebNativeJsonLibrary_eventSetJsonFloatField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonIntArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<int32> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonIntArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonIntArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonIntArray", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::WebNativeJsonLibrary_eventSetJsonIntArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::WebNativeJsonLibrary_eventSetJsonIntArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonIntField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		int32 Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonIntField_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonIntField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonIntField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonIntField", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::WebNativeJsonLibrary_eventSetJsonIntField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::WebNativeJsonLibrary_eventSetJsonIntField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonObjectArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<FJsonObjectWrapper> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(0, nullptr) }; // 219379207
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 219379207
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonObjectArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonObjectArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonObjectArray", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::WebNativeJsonLibrary_eventSetJsonObjectArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::WebNativeJsonLibrary_eventSetJsonObjectArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonObjectField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		FJsonObjectWrapper Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonObjectField_Parms, Value), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 219379207
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonObjectField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonObjectField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonObjectField", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::WebNativeJsonLibrary_eventSetJsonObjectField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::WebNativeJsonLibrary_eventSetJsonObjectField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonStringArray_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		TArray<FString> Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringArray_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringArray_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_Value_Inner = { "Value", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringArray_Parms, Value), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonStringArray_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonStringArray_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_Value_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonStringArray", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::WebNativeJsonLibrary_eventSetJsonStringArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::WebNativeJsonLibrary_eventSetJsonStringArray_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
struct Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics
{
	struct WebNativeJsonLibrary_eventSetJsonStringField_Parms
	{
		FJsonObjectWrapper JsonObject;
		FString FieldName;
		FString Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
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
	static const UECodeGen_Private::FStructPropertyParams NewProp_JsonObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringField_Parms, JsonObject), Z_Construct_UScriptStruct_FJsonObjectWrapper, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonObject_MetaData), NewProp_JsonObject_MetaData) }; // 219379207
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringField_Parms, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WebNativeJsonLibrary_eventSetJsonStringField_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
void Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WebNativeJsonLibrary_eventSetJsonStringField_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WebNativeJsonLibrary_eventSetJsonStringField_Parms), &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_JsonObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UWebNativeJsonLibrary, nullptr, "SetJsonStringField", Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::WebNativeJsonLibrary_eventSetJsonStringField_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::WebNativeJsonLibrary_eventSetJsonStringField_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField_Statics::FuncParams);
	}
	return ReturnFunction;
}
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
void UWebNativeJsonLibrary::StaticRegisterNativesUWebNativeJsonLibrary()
{
	UClass* Class = UWebNativeJsonLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CreateEmptyJsonObject", &UWebNativeJsonLibrary::execCreateEmptyJsonObject },
		{ "GetField", &UWebNativeJsonLibrary::execGetField },
		{ "GetFieldNames", &UWebNativeJsonLibrary::execGetFieldNames },
		{ "GetJsonBoolArray", &UWebNativeJsonLibrary::execGetJsonBoolArray },
		{ "GetJsonBoolField", &UWebNativeJsonLibrary::execGetJsonBoolField },
		{ "GetJsonFloatArray", &UWebNativeJsonLibrary::execGetJsonFloatArray },
		{ "GetJsonFloatField", &UWebNativeJsonLibrary::execGetJsonFloatField },
		{ "GetJsonIntArray", &UWebNativeJsonLibrary::execGetJsonIntArray },
		{ "GetJsonIntField", &UWebNativeJsonLibrary::execGetJsonIntField },
		{ "GetJsonObjectArray", &UWebNativeJsonLibrary::execGetJsonObjectArray },
		{ "GetJsonObjectField", &UWebNativeJsonLibrary::execGetJsonObjectField },
		{ "GetJsonStringArray", &UWebNativeJsonLibrary::execGetJsonStringArray },
		{ "GetJsonStringField", &UWebNativeJsonLibrary::execGetJsonStringField },
		{ "HasField", &UWebNativeJsonLibrary::execHasField },
		{ "JsonObjectToString", &UWebNativeJsonLibrary::execJsonObjectToString },
		{ "LoadJsonFromString", &UWebNativeJsonLibrary::execLoadJsonFromString },
		{ "RemoveField", &UWebNativeJsonLibrary::execRemoveField },
		{ "SetField", &UWebNativeJsonLibrary::execSetField },
		{ "SetJsonBoolArray", &UWebNativeJsonLibrary::execSetJsonBoolArray },
		{ "SetJsonBoolField", &UWebNativeJsonLibrary::execSetJsonBoolField },
		{ "SetJsonFloatArray", &UWebNativeJsonLibrary::execSetJsonFloatArray },
		{ "SetJsonFloatField", &UWebNativeJsonLibrary::execSetJsonFloatField },
		{ "SetJsonIntArray", &UWebNativeJsonLibrary::execSetJsonIntArray },
		{ "SetJsonIntField", &UWebNativeJsonLibrary::execSetJsonIntField },
		{ "SetJsonObjectArray", &UWebNativeJsonLibrary::execSetJsonObjectArray },
		{ "SetJsonObjectField", &UWebNativeJsonLibrary::execSetJsonObjectField },
		{ "SetJsonStringArray", &UWebNativeJsonLibrary::execSetJsonStringArray },
		{ "SetJsonStringField", &UWebNativeJsonLibrary::execSetJsonStringField },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UWebNativeJsonLibrary;
UClass* UWebNativeJsonLibrary::GetPrivateStaticClass()
{
	using TClass = UWebNativeJsonLibrary;
	if (!Z_Registration_Info_UClass_UWebNativeJsonLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("WebNativeJsonLibrary"),
			Z_Registration_Info_UClass_UWebNativeJsonLibrary.InnerSingleton,
			StaticRegisterNativesUWebNativeJsonLibrary,
			sizeof(TClass),
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
UClass* Z_Construct_UClass_UWebNativeJsonLibrary_NoRegister()
{
	return UWebNativeJsonLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWebNativeJsonLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Built-in JSON Blueprint Function Library.\n * pure-Blueprint projects can package without extra plugins. Everything here\n * is backed by the engine's built-in Json / JsonUtilities runtime modules,\n * which are always available on every target platform.\n *\n * Works both in Blueprints (Edit > Plugins search \"WebNative|Json\") and in\n * C++ (call UWebNativeJsonLibrary::Xxx directly).\n */" },
		{ "IncludePath", "WebNativeJsonLibrary.h" },
		{ "ModuleRelativePath", "Public/WebNativeJsonLibrary.h" },
		{ "ToolTip", "Built-in JSON Blueprint Function Library.\npure-Blueprint projects can package without extra plugins. Everything here\nis backed by the engine's built-in Json / JsonUtilities runtime modules,\nwhich are always available on every target platform.\n\nWorks both in Blueprints (Edit > Plugins search \"WebNative|Json\") and in\nC++ (call UWebNativeJsonLibrary::Xxx directly)." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_CreateEmptyJsonObject, "CreateEmptyJsonObject" }, // 3173813284
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetField, "GetField" }, // 3563902221
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetFieldNames, "GetFieldNames" }, // 874156015
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolArray, "GetJsonBoolArray" }, // 676138588
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonBoolField, "GetJsonBoolField" }, // 1018172717
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatArray, "GetJsonFloatArray" }, // 558483530
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonFloatField, "GetJsonFloatField" }, // 2221495997
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntArray, "GetJsonIntArray" }, // 680265858
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonIntField, "GetJsonIntField" }, // 3567694838
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectArray, "GetJsonObjectArray" }, // 2091288870
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonObjectField, "GetJsonObjectField" }, // 3570499188
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringArray, "GetJsonStringArray" }, // 2373711713
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_GetJsonStringField, "GetJsonStringField" }, // 3216125478
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_HasField, "HasField" }, // 559694318
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_JsonObjectToString, "JsonObjectToString" }, // 4236188559
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_LoadJsonFromString, "LoadJsonFromString" }, // 2919095860
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_RemoveField, "RemoveField" }, // 1997140696
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetField, "SetField" }, // 382571408
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolArray, "SetJsonBoolArray" }, // 1366234497
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonBoolField, "SetJsonBoolField" }, // 2794895844
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatArray, "SetJsonFloatArray" }, // 1684129331
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonFloatField, "SetJsonFloatField" }, // 3155449051
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntArray, "SetJsonIntArray" }, // 4257689303
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonIntField, "SetJsonIntField" }, // 117442360
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectArray, "SetJsonObjectArray" }, // 4061424657
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonObjectField, "SetJsonObjectField" }, // 1120719794
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringArray, "SetJsonStringArray" }, // 3687596440
		{ &Z_Construct_UFunction_UWebNativeJsonLibrary_SetJsonStringField, "SetJsonStringField" }, // 2989620819
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWebNativeJsonLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UWebNativeJsonLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_WebNativeBrowserCore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWebNativeJsonLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWebNativeJsonLibrary_Statics::ClassParams = {
	&UWebNativeJsonLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWebNativeJsonLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UWebNativeJsonLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWebNativeJsonLibrary()
{
	if (!Z_Registration_Info_UClass_UWebNativeJsonLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWebNativeJsonLibrary.OuterSingleton, Z_Construct_UClass_UWebNativeJsonLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWebNativeJsonLibrary.OuterSingleton;
}
UWebNativeJsonLibrary::UWebNativeJsonLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWebNativeJsonLibrary);
UWebNativeJsonLibrary::~UWebNativeJsonLibrary() {}
// ********** End Class UWebNativeJsonLibrary ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_WNFabTmp_56_6193e3bf_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h__Script_WebNativeBrowserCore_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWebNativeJsonLibrary, UWebNativeJsonLibrary::StaticClass, TEXT("UWebNativeJsonLibrary"), &Z_Registration_Info_UClass_UWebNativeJsonLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWebNativeJsonLibrary), 4010307677U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_WNFabTmp_56_6193e3bf_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h__Script_WebNativeBrowserCore_1164524548(TEXT("/Script/WebNativeBrowserCore"),
	Z_CompiledInDeferFile_FID_WNFabTmp_56_6193e3bf_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h__Script_WebNativeBrowserCore_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_WNFabTmp_56_6193e3bf_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowserCore_Public_WebNativeJsonLibrary_h__Script_WebNativeBrowserCore_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
