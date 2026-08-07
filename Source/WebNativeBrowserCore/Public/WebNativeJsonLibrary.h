// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "WebNativeJsonLibrary.generated.h"

/**
 * Built-in JSON Blueprint Function Library.
 * pure-Blueprint projects can package without extra plugins. Everything here
 * is backed by the engine's built-in Json / JsonUtilities runtime modules,
 * which are always available on every target platform.
 *
 * Works both in Blueprints (Edit > Plugins search "WebNative|Json") and in
 * C++ (call UWebNativeJsonLibrary::Xxx directly).
 */
UCLASS()
class WEBNATIVEBROWSERCORE_API UWebNativeJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// ------------------------------------------------------------------
	// Load / Convert
	// ------------------------------------------------------------------

	/** Parses a JSON string into a JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Load Json From String"))
	static UPARAM(DisplayName = "Success") bool LoadJsonFromString(
		const FString& JsonString,
		UPARAM(DisplayName = "JsonObject") FJsonObjectWrapper& OutJsonObject);

	/** Serializes a JsonObject back to a JSON string. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Json Object To String"))
	static UPARAM(DisplayName = "Success") bool JsonObjectToString(
		const FJsonObjectWrapper& JsonObject,
		UPARAM(DisplayName = "String") FString& OutJsonString);

	/** Creates an empty JsonObject. Use it as the starting point, then chain Set Json Xxx Field nodes to build up fields. */
	UFUNCTION(BlueprintPure, Category = "WebNative|Json", meta = (DisplayName = "Create Json Object"))
	static UPARAM(DisplayName = "JsonObject") FJsonObjectWrapper CreateEmptyJsonObject();

	// ------------------------------------------------------------------
	// Get (strongly typed fields)
	// ------------------------------------------------------------------

	/** Gets a string field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Get Json String Field"))
	static UPARAM(DisplayName = "Success") bool GetJsonStringField(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") FString& OutValue);

	/** Gets an int32 field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Get Json Int Field"))
	static UPARAM(DisplayName = "Success") bool GetJsonIntField(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") int32& OutValue);

	/** Gets a float field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Get Json Float Field"))
	static UPARAM(DisplayName = "Success") bool GetJsonFloatField(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") float& OutValue);

	/** Gets a bool field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Get Json Bool Field"))
	static UPARAM(DisplayName = "Success") bool GetJsonBoolField(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") bool& OutValue);

	/** Gets a string array field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Get Json String Array"))
	static UPARAM(DisplayName = "Success") bool GetJsonStringArray(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") TArray<FString>& OutValue);

	/** Gets an int32 array field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Get Json Int Array"))
	static UPARAM(DisplayName = "Success") bool GetJsonIntArray(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") TArray<int32>& OutValue);

	/** Gets a float array field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Get Json Float Array"))
	static UPARAM(DisplayName = "Success") bool GetJsonFloatArray(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") TArray<float>& OutValue);

	/** Gets a bool array field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Get Json Bool Array"))
	static UPARAM(DisplayName = "Success") bool GetJsonBoolArray(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") TArray<bool>& OutValue);

	/** Gets a nested object field from the JsonObject as another JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Get Json Object Field"))
	static UPARAM(DisplayName = "Success") bool GetJsonObjectField(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") FJsonObjectWrapper& OutObject);

	/** Gets an array of nested objects from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Get Json Object Array"))
	static UPARAM(DisplayName = "Success") bool GetJsonObjectArray(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") TArray<FJsonObjectWrapper>& OutValue);

	/** Checks whether the field exists on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Has Json Field"))
	static UPARAM(DisplayName = "Success") bool HasField(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName);

	/** Gets all field names on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Get Json Field Names"))
	static UPARAM(DisplayName = "Success") bool GetFieldNames(
		const FJsonObjectWrapper& JsonObject,
		UPARAM(DisplayName = "FieldNames") TArray<FString>& FieldNames);

	// ------------------------------------------------------------------
	// Get / Set (wildcard, any type, converts to/from user structs)
	// ------------------------------------------------------------------

	/**
	 * Reads a field into any supported type.
	 * - FieldName empty: converts the whole JsonObject into a struct.
	 * - FieldName set: converts that single field into the output type.
	 * The output pin is a wildcard: connect any variable/struct to choose the type.
	 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category = "WebNative|Json", meta = (CustomStructureParam = "OutValue", AutoCreateRefTerm = "OutValue"))
	static UPARAM(DisplayName = "Success") bool GetField(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		UPARAM(DisplayName = "Value") int32& OutValue);
	DECLARE_FUNCTION(execGetField);

	/**
	 * Sets a field to any supported value type.
	 * - FieldName empty: converts the whole struct into the JsonObject.
	 * - FieldName set: sets that single field from the value.
	 * The value pin is a wildcard: connect any variable/struct to choose the type.
	 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category = "WebNative|Json", meta = (CustomStructureParam = "Value", AutoCreateRefTerm = "Value"))
	static UPARAM(DisplayName = "Success") bool SetField(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const int32& Value);
	DECLARE_FUNCTION(execSetField);

	// ------------------------------------------------------------------
	// Struct <-> JSON string (serialize / deserialize)
	// Temporarily commented out: WebNative plugin does not need struct conversion.
	// Uncomment to restore StructToJsonString / JsonStringToStruct nodes.
	// ------------------------------------------------------------------

	// UFUNCTION(BlueprintCallable, CustomThunk, Category = "WebNative|Json", meta = (DisplayName = "Struct To Json String", CustomStructureParam = "Struct", AutoCreateRefTerm = "Struct"))
	// static UPARAM(DisplayName = "Success") bool StructToJsonString(
	// 	const int32& Struct,
	// 	UPARAM(DisplayName = "JsonString") FString& OutJsonString);
	// DECLARE_FUNCTION(execStructToJsonString);

	// UFUNCTION(BlueprintCallable, CustomThunk, Category = "WebNative|Json", meta = (DisplayName = "Json String To Struct", CustomStructureParam = "OutStruct", AutoCreateRefTerm = "OutStruct"))
	// static UPARAM(DisplayName = "Success") bool JsonStringToStruct(
	// 	const FString& JsonString,
	// 	UPARAM(DisplayName = "Struct") int32& OutStruct);
	// DECLARE_FUNCTION(execJsonStringToStruct);

	// ------------------------------------------------------------------
	// Set (strongly typed fields, JsonObject modified in place)
	// ------------------------------------------------------------------

	/** Sets a string field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Set Json String Field"))
	static UPARAM(DisplayName = "Success") bool SetJsonStringField(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const FString& Value);

	/** Sets an int32 field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Set Json Int Field"))
	static UPARAM(DisplayName = "Success") bool SetJsonIntField(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const int32 Value);

	/** Sets a float field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Set Json Float Field"))
	static UPARAM(DisplayName = "Success") bool SetJsonFloatField(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const float Value);

	/** Sets a bool field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Set Json Bool Field"))
	static UPARAM(DisplayName = "Success") bool SetJsonBoolField(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const bool Value);

	/** Sets a string array field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Set Json String Array"))
	static UPARAM(DisplayName = "Success") bool SetJsonStringArray(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const TArray<FString>& Value);

	/** Sets an int32 array field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Set Json Int Array"))
	static UPARAM(DisplayName = "Success") bool SetJsonIntArray(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const TArray<int32>& Value);

	/** Sets a float array field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Set Json Float Array"))
	static UPARAM(DisplayName = "Success") bool SetJsonFloatArray(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const TArray<float>& Value);

	/** Sets a bool array field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Set Json Bool Array"))
	static UPARAM(DisplayName = "Success") bool SetJsonBoolArray(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const TArray<bool>& Value);

	/** Sets a nested object field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Set Json Object Field"))
	static UPARAM(DisplayName = "Success") bool SetJsonObjectField(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const FJsonObjectWrapper& Value);

	/** Sets an array of nested objects field on the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json Array", meta = (DisplayName = "Set Json Object Array"))
	static UPARAM(DisplayName = "Success") bool SetJsonObjectArray(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const TArray<FJsonObjectWrapper>& Value);

	/** Removes a field from the JsonObject. */
	UFUNCTION(BlueprintCallable, Category = "WebNative|Json", meta = (DisplayName = "Remove Json Field"))
	static UPARAM(DisplayName = "Success") bool RemoveField(
		UPARAM(DisplayName = "JsonObject", ref) FJsonObjectWrapper& JsonObject,
		const FString& FieldName);

private:
	/** Converts a single JSON field to a UProperty (used by GetField). */
	static bool JsonFieldToProperty(const FString& FieldName, const FJsonObjectWrapper& SourceObject, FProperty* TargetProperty, void* TargetValuePtr);

	/** Converts a UProperty to a JSON field (used by SetField). */
	static bool PropertyToJsonField(const FString& FieldName, FProperty* SourceProperty, const void* SourceValuePtr, FJsonObjectWrapper& TargetObject);
};
