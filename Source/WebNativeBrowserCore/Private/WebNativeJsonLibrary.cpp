// Copyright (c) 2026 StarTechnology. All rights reserved.

#include "WebNativeJsonLibrary.h"

// WNW_ENGINE_GTE_5_4 is defined by WebNativeBrowserCore.Build.cs on UE5.4+;
// keep a default so the #if below never sees an undefined macro (C4668).
#ifndef WNW_ENGINE_GTE_5_4
#define WNW_ENGINE_GTE_5_4 0
#endif
#if WNW_ENGINE_GTE_5_4
// 5.4+ moved FBlueprintExceptionInfo / EBlueprintExceptionType into their own
// header; Script.h only forward-declares them (include order cleanups).
#include "Blueprint/BlueprintExceptionInfo.h"
#endif
#include "Json.h"
#include "JsonObjectConverter.h"

#define LOCTEXT_NAMESPACE "WebNativeJsonLibrary"

namespace
{
	/** Re-serializes the wrapper's JsonObject back into its cached JsonString. */
	bool RefreshJsonString(FJsonObjectWrapper& JsonObject)
	{
		if (!JsonObject.JsonObject.IsValid())
		{
			JsonObject.JsonString.Reset();
			return false;
		}

		JsonObject.JsonString.Reset();
		if (!FJsonSerializer::Serialize(
			JsonObject.JsonObject.ToSharedRef(),
			TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>>::Create(&JsonObject.JsonString)))
		{
			FFrame::KismetExecutionMessage(TEXT("WebNativeJson: Failed to serialize JSON Object."), ELogVerbosity::Error);
			return false;
		}
		return true;
	}

	/**
	 * Reads a JSON array field whose elements must all be of ExpectedType into
	 * a typed TArray. Fails (returns false) if the field is not an array or any
	 * element has a different type.
	 */
	template <typename ValueType, typename ConvertFn>
	bool GetJsonPrimitiveArray(
		const FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		TArray<ValueType>& OutValue,
		const EJson ExpectedType,
		ConvertFn&& Converter)
	{
		if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
		{
			return false;
		}
		const TSharedPtr<FJsonValue> JsonValue = JsonObject.JsonObject->TryGetField(FieldName);
		if (!JsonValue.IsValid() || JsonValue->Type != EJson::Array)
		{
			return false;
		}
		const TArray<TSharedPtr<FJsonValue>>& Array = JsonValue->AsArray();
		OutValue.Reset(Array.Num());
		for (const TSharedPtr<FJsonValue>& Item : Array)
		{
			if (!Item.IsValid() || Item->Type != ExpectedType)
			{
				return false;
			}
			OutValue.Add(Converter(Item));
		}
		return true;
	}

	/** Writes a typed TArray as a JSON array field on the wrapper. */
	template <typename ValueType, typename ConvertFn>
	bool SetJsonPrimitiveArray(
		FJsonObjectWrapper& JsonObject,
		const FString& FieldName,
		const TArray<ValueType>& Value,
		ConvertFn&& Converter)
	{
		if (FieldName.IsEmpty())
		{
			return false;
		}
		if (!JsonObject.JsonObject.IsValid())
		{
			JsonObject.JsonObject = MakeShared<FJsonObject>();
		}
		TArray<TSharedPtr<FJsonValue>> JsonArray;
		JsonArray.Reserve(Value.Num());
		for (const ValueType& Item : Value)
		{
			JsonArray.Add(Converter(Item));
		}
		JsonObject.JsonObject->SetArrayField(FieldName, JsonArray);
		return RefreshJsonString(JsonObject);
	}
}

// ------------------------------------------------------------------
// Load / Convert
// ------------------------------------------------------------------

bool UWebNativeJsonLibrary::LoadJsonFromString(const FString& JsonString, FJsonObjectWrapper& OutJsonObject)
{
	if (!OutJsonObject.JsonObjectFromString(JsonString))
	{
		FFrame::KismetExecutionMessage(TEXT("WebNativeJson: Failed to parse the provided JSON string."), ELogVerbosity::Warning);
		return false;
	}
	return true;
}

bool UWebNativeJsonLibrary::JsonObjectToString(const FJsonObjectWrapper& JsonObject, FString& OutJsonString)
{
	if (!JsonObject.JsonObject.IsValid())
	{
		return false;
	}
	return JsonObject.JsonObjectToString(OutJsonString);
}

FJsonObjectWrapper UWebNativeJsonLibrary::CreateEmptyJsonObject()
{
	FJsonObjectWrapper Wrapper;
	Wrapper.JsonObject = MakeShared<FJsonObject>();
	return Wrapper;
}

// ------------------------------------------------------------------
// Get (strongly typed fields)
// ------------------------------------------------------------------

bool UWebNativeJsonLibrary::GetJsonStringField(const FJsonObjectWrapper& JsonObject, const FString& FieldName, FString& OutValue)
{
	if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
	{
		return false;
	}
	const TSharedPtr<FJsonValue> JsonValue = JsonObject.JsonObject->TryGetField(FieldName);
	if (!JsonValue.IsValid())
	{
		return false;
	}
	OutValue = JsonValue->AsString();
	return true;
}

bool UWebNativeJsonLibrary::GetJsonIntField(const FJsonObjectWrapper& JsonObject, const FString& FieldName, int32& OutValue)
{
	if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
	{
		return false;
	}
	const TSharedPtr<FJsonValue> JsonValue = JsonObject.JsonObject->TryGetField(FieldName);
	if (!JsonValue.IsValid() || JsonValue->Type != EJson::Number)
	{
		return false;
	}
	OutValue = FMath::RoundToInt(JsonValue->AsNumber());
	return true;
}

bool UWebNativeJsonLibrary::GetJsonFloatField(const FJsonObjectWrapper& JsonObject, const FString& FieldName, float& OutValue)
{
	if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
	{
		return false;
	}
	const TSharedPtr<FJsonValue> JsonValue = JsonObject.JsonObject->TryGetField(FieldName);
	if (!JsonValue.IsValid() || JsonValue->Type != EJson::Number)
	{
		return false;
	}
	OutValue = static_cast<float>(JsonValue->AsNumber());
	return true;
}

bool UWebNativeJsonLibrary::GetJsonBoolField(const FJsonObjectWrapper& JsonObject, const FString& FieldName, bool& OutValue)
{
	if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
	{
		return false;
	}
	const TSharedPtr<FJsonValue> JsonValue = JsonObject.JsonObject->TryGetField(FieldName);
	if (!JsonValue.IsValid() || JsonValue->Type != EJson::Boolean)
	{
		return false;
	}
	OutValue = JsonValue->AsBool();
	return true;
}

bool UWebNativeJsonLibrary::GetJsonStringArray(const FJsonObjectWrapper& JsonObject, const FString& FieldName, TArray<FString>& OutValue)
{
	if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
	{
		return false;
	}
	const TSharedPtr<FJsonValue> JsonValue = JsonObject.JsonObject->TryGetField(FieldName);
	if (!JsonValue.IsValid() || JsonValue->Type != EJson::Array)
	{
		return false;
	}
	const TArray<TSharedPtr<FJsonValue>>& Array = JsonValue->AsArray();
	OutValue.Reset(Array.Num());
	for (const TSharedPtr<FJsonValue>& Item : Array)
	{
		OutValue.Add(Item->AsString());
	}
	return true;
}

bool UWebNativeJsonLibrary::GetJsonIntArray(const FJsonObjectWrapper& JsonObject, const FString& FieldName, TArray<int32>& OutValue)
{
	return GetJsonPrimitiveArray(
		JsonObject, FieldName, OutValue, EJson::Number,
		[](const TSharedPtr<FJsonValue>& Item) { return FMath::RoundToInt(Item->AsNumber()); });
}

bool UWebNativeJsonLibrary::GetJsonFloatArray(const FJsonObjectWrapper& JsonObject, const FString& FieldName, TArray<float>& OutValue)
{
	return GetJsonPrimitiveArray(
		JsonObject, FieldName, OutValue, EJson::Number,
		[](const TSharedPtr<FJsonValue>& Item) { return static_cast<float>(Item->AsNumber()); });
}

bool UWebNativeJsonLibrary::GetJsonBoolArray(const FJsonObjectWrapper& JsonObject, const FString& FieldName, TArray<bool>& OutValue)
{
	return GetJsonPrimitiveArray(
		JsonObject, FieldName, OutValue, EJson::Boolean,
		[](const TSharedPtr<FJsonValue>& Item) { return Item->AsBool(); });
}

bool UWebNativeJsonLibrary::GetJsonObjectField(const FJsonObjectWrapper& JsonObject, const FString& FieldName, FJsonObjectWrapper& OutObject)
{
	if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
	{
		return false;
	}
	const TSharedPtr<FJsonValue> JsonValue = JsonObject.JsonObject->TryGetField(FieldName);
	if (!JsonValue.IsValid())
	{
		return false;
	}
	const TSharedPtr<FJsonObject> Object = JsonValue->AsObject();
	if (!Object.IsValid())
	{
		return false;
	}
	OutObject.JsonObject = Object;
	return true;
}

bool UWebNativeJsonLibrary::GetJsonObjectArray(const FJsonObjectWrapper& JsonObject, const FString& FieldName, TArray<FJsonObjectWrapper>& OutValue)
{
	if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
	{
		return false;
	}
	const TSharedPtr<FJsonValue> JsonValue = JsonObject.JsonObject->TryGetField(FieldName);
	if (!JsonValue.IsValid() || JsonValue->Type != EJson::Array)
	{
		return false;
	}
	const TArray<TSharedPtr<FJsonValue>>& Array = JsonValue->AsArray();
	OutValue.Reset(Array.Num());
	for (const TSharedPtr<FJsonValue>& Item : Array)
	{
		if (!Item.IsValid() || Item->Type != EJson::Object)
		{
			return false;
		}
		FJsonObjectWrapper Wrapper;
		Wrapper.JsonObject = Item->AsObject();
		OutValue.Add(MoveTemp(Wrapper));
	}
	return true;
}

bool UWebNativeJsonLibrary::HasField(const FJsonObjectWrapper& JsonObject, const FString& FieldName)
{
	return JsonObject.JsonObject.IsValid() && JsonObject.JsonObject->HasField(FieldName);
}

bool UWebNativeJsonLibrary::GetFieldNames(const FJsonObjectWrapper& JsonObject, TArray<FString>& FieldNames)
{
	if (!JsonObject.JsonObject.IsValid())
	{
		return false;
	}
	FieldNames.Reset(JsonObject.JsonObject->Values.Num());
	for (const auto& Field : JsonObject.JsonObject->Values)
	{
		FieldNames.Add(FString(*Field.Key));
	}
	return true;
}

// ------------------------------------------------------------------
// Get / Set (wildcard)
// ------------------------------------------------------------------

DEFINE_FUNCTION(UWebNativeJsonLibrary::execGetField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper, JsonObject);
	P_GET_PROPERTY(FStrProperty, FieldName);

	Stack.StepCompiledIn<FProperty>(nullptr);
	FProperty* ValueProp = Stack.MostRecentProperty;
	void* ValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (!ValueProp || !ValuePtr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(
			EBlueprintExceptionType::AccessViolation,
			LOCTEXT("GetField_MissingOutputProperty", "Failed to resolve the output parameter for GetField.")
		);
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}

	bool bResult = false;
	if (FieldName.IsEmpty())
	{
		FStructProperty* StructProperty = CastField<FStructProperty>(ValueProp);
		if (StructProperty && JsonObject.JsonObject.IsValid())
		{
			P_NATIVE_BEGIN
			bResult = FJsonObjectConverter::JsonObjectToUStruct(JsonObject.JsonObject.ToSharedRef(), StructProperty->Struct, ValuePtr);
			P_NATIVE_END
		}
	}
	else
	{
		P_NATIVE_BEGIN
		bResult = JsonFieldToProperty(FieldName, JsonObject, ValueProp, ValuePtr);
		P_NATIVE_END
	}

	*StaticCast<bool*>(RESULT_PARAM) = bResult;
}

DEFINE_FUNCTION(UWebNativeJsonLibrary::execSetField)
{
	P_GET_STRUCT_REF(FJsonObjectWrapper, JsonObject);
	P_GET_PROPERTY(FStrProperty, FieldName);

	Stack.StepCompiledIn<FProperty>(nullptr);
	FProperty* SourceProperty = Stack.MostRecentProperty;
	void* SourceValuePtr = Stack.MostRecentPropertyAddress;

	P_FINISH;

	if (!SourceProperty || !SourceValuePtr)
	{
		const FBlueprintExceptionInfo ExceptionInfo(
			EBlueprintExceptionType::AccessViolation,
			LOCTEXT("SetField_MissingInputProperty", "Failed to resolve the input parameter for SetField.")
		);
		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
	}

	bool bResult = false;
	if (FieldName.IsEmpty())
	{
		FStructProperty* StructProperty = CastField<FStructProperty>(SourceProperty);
		if (StructProperty)
		{
			if (!JsonObject.JsonObject.IsValid())
			{
				JsonObject.JsonObject = MakeShared<FJsonObject>();
			}
			P_NATIVE_BEGIN
			bResult = FJsonObjectConverter::UStructToJsonObject(StructProperty->Struct, SourceValuePtr, JsonObject.JsonObject.ToSharedRef());
			P_NATIVE_END
		}
	}
	else
	{
		P_NATIVE_BEGIN
		bResult = PropertyToJsonField(FieldName, SourceProperty, SourceValuePtr, JsonObject);
		P_NATIVE_END
	}

	// On success, refresh the stored JsonString so the wrapper stays consistent.
	if (bResult)
	{
		P_NATIVE_BEGIN
		bResult = RefreshJsonString(JsonObject);
		P_NATIVE_END
	}

	*StaticCast<bool*>(RESULT_PARAM) = bResult;
}

// ------------------------------------------------------------------
// Struct <-> JSON string
// Temporarily commented out (matches the header). Uncomment to restore.
// ------------------------------------------------------------------

// DEFINE_FUNCTION(UWebNativeJsonLibrary::execStructToJsonString)
// {
// 	Stack.StepCompiledIn<FProperty>(nullptr);
// 	FProperty* ValueProperty = Stack.MostRecentProperty;
// 	void* ValuePtr = Stack.MostRecentPropertyAddress;
//
// 	PARAM_PASSED_BY_REF(OutJsonString, FStrProperty, FString);
//
// 	P_FINISH;
//
// 	if (!ValueProperty || !ValuePtr)
// 	{
// 		const FBlueprintExceptionInfo ExceptionInfo(
// 			EBlueprintExceptionType::AccessViolation,
// 			LOCTEXT("StructToJsonString_MissingInputProperty", "Failed to resolve the input parameter for StructToJsonString.")
// 		);
// 		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
// 	}
//
// 	bool bResult = false;
// 	FStructProperty* const StructProperty = CastField<FStructProperty>(ValueProperty);
// 	if (StructProperty)
// 	{
// 		P_NATIVE_BEGIN
// 		bResult = FJsonObjectConverter::UStructToJsonObjectString(StructProperty->Struct, ValuePtr, OutJsonString);
// 		P_NATIVE_END
// 	}
//
// 	*StaticCast<bool*>(RESULT_PARAM) = bResult;
// }

// DEFINE_FUNCTION(UWebNativeJsonLibrary::execJsonStringToStruct)
// {
// 	P_GET_PROPERTY(FStrProperty, JsonString);
//
// 	Stack.StepCompiledIn<FProperty>(nullptr);
// 	FProperty* OutProperty = Stack.MostRecentProperty;
// 	void* OutValuePtr = Stack.MostRecentPropertyAddress;
//
// 	P_FINISH;
//
// 	if (!OutProperty || !OutValuePtr)
// 	{
// 		const FBlueprintExceptionInfo ExceptionInfo(
// 			EBlueprintExceptionType::AccessViolation,
// 			LOCTEXT("JsonStringToStruct_MissingOutputProperty", "Failed to resolve the output parameter for JsonStringToStruct.")
// 		);
// 		FBlueprintCoreDelegates::ThrowScriptException(P_THIS, Stack, ExceptionInfo);
// 	}
//
// 	bool bResult = false;
// 	FStructProperty* const StructProperty = CastField<FStructProperty>(OutProperty);
// 	if (StructProperty)
// 	{
// 		TSharedPtr<FJsonObject> JsonObject;
// 		const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
// 		P_NATIVE_BEGIN
// 		if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
// 		{
// 			bResult = FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), StructProperty->Struct, OutValuePtr);
// 		}
// 		P_NATIVE_END
// 	}
//
// 	*StaticCast<bool*>(RESULT_PARAM) = bResult;
// }

// ------------------------------------------------------------------
// Set (strongly typed fields)
// ------------------------------------------------------------------

bool UWebNativeJsonLibrary::SetJsonStringField(FJsonObjectWrapper& JsonObject, const FString& FieldName, const FString& Value)
{
	if (FieldName.IsEmpty())
	{
		return false;
	}
	if (!JsonObject.JsonObject.IsValid())
	{
		JsonObject.JsonObject = MakeShared<FJsonObject>();
	}
	JsonObject.JsonObject->SetStringField(FieldName, Value);
	return RefreshJsonString(JsonObject);
}

bool UWebNativeJsonLibrary::SetJsonIntField(FJsonObjectWrapper& JsonObject, const FString& FieldName, const int32 Value)
{
	if (FieldName.IsEmpty())
	{
		return false;
	}
	if (!JsonObject.JsonObject.IsValid())
	{
		JsonObject.JsonObject = MakeShared<FJsonObject>();
	}
	JsonObject.JsonObject->SetNumberField(FieldName, Value);
	return RefreshJsonString(JsonObject);
}

bool UWebNativeJsonLibrary::SetJsonFloatField(FJsonObjectWrapper& JsonObject, const FString& FieldName, const float Value)
{
	if (FieldName.IsEmpty())
	{
		return false;
	}
	if (!JsonObject.JsonObject.IsValid())
	{
		JsonObject.JsonObject = MakeShared<FJsonObject>();
	}
	JsonObject.JsonObject->SetNumberField(FieldName, Value);
	return RefreshJsonString(JsonObject);
}

bool UWebNativeJsonLibrary::SetJsonBoolField(FJsonObjectWrapper& JsonObject, const FString& FieldName, const bool Value)
{
	if (FieldName.IsEmpty())
	{
		return false;
	}
	if (!JsonObject.JsonObject.IsValid())
	{
		JsonObject.JsonObject = MakeShared<FJsonObject>();
	}
	JsonObject.JsonObject->SetBoolField(FieldName, Value);
	return RefreshJsonString(JsonObject);
}

bool UWebNativeJsonLibrary::SetJsonStringArray(FJsonObjectWrapper& JsonObject, const FString& FieldName, const TArray<FString>& Value)
{
	if (FieldName.IsEmpty())
	{
		return false;
	}
	if (!JsonObject.JsonObject.IsValid())
	{
		JsonObject.JsonObject = MakeShared<FJsonObject>();
	}
	TArray<TSharedPtr<FJsonValue>> JsonArray;
	JsonArray.Reserve(Value.Num());
	for (const FString& Item : Value)
	{
		JsonArray.Add(MakeShared<FJsonValueString>(Item));
	}
	JsonObject.JsonObject->SetArrayField(FieldName, JsonArray);
	return RefreshJsonString(JsonObject);
}

bool UWebNativeJsonLibrary::SetJsonIntArray(FJsonObjectWrapper& JsonObject, const FString& FieldName, const TArray<int32>& Value)
{
	return SetJsonPrimitiveArray(
		JsonObject, FieldName, Value,
		[](const int32 Item) { return MakeShared<FJsonValueNumber>(Item); });
}

bool UWebNativeJsonLibrary::SetJsonFloatArray(FJsonObjectWrapper& JsonObject, const FString& FieldName, const TArray<float>& Value)
{
	return SetJsonPrimitiveArray(
		JsonObject, FieldName, Value,
		[](const float Item) { return MakeShared<FJsonValueNumber>(Item); });
}

bool UWebNativeJsonLibrary::SetJsonBoolArray(FJsonObjectWrapper& JsonObject, const FString& FieldName, const TArray<bool>& Value)
{
	return SetJsonPrimitiveArray(
		JsonObject, FieldName, Value,
		[](const bool Item) { return MakeShared<FJsonValueBoolean>(Item); });
}

bool UWebNativeJsonLibrary::SetJsonObjectField(FJsonObjectWrapper& JsonObject, const FString& FieldName, const FJsonObjectWrapper& Value)
{
	if (FieldName.IsEmpty() || !Value.JsonObject.IsValid())
	{
		return false;
	}
	if (!JsonObject.JsonObject.IsValid())
	{
		JsonObject.JsonObject = MakeShared<FJsonObject>();
	}
	JsonObject.JsonObject->SetObjectField(FieldName, Value.JsonObject);
	return RefreshJsonString(JsonObject);
}

bool UWebNativeJsonLibrary::SetJsonObjectArray(FJsonObjectWrapper& JsonObject, const FString& FieldName, const TArray<FJsonObjectWrapper>& Value)
{
	if (FieldName.IsEmpty())
	{
		return false;
	}
	if (!JsonObject.JsonObject.IsValid())
	{
		JsonObject.JsonObject = MakeShared<FJsonObject>();
	}
	TArray<TSharedPtr<FJsonValue>> JsonArray;
	JsonArray.Reserve(Value.Num());
	for (const FJsonObjectWrapper& Item : Value)
	{
		if (!Item.JsonObject.IsValid())
		{
			return false;
		}
		JsonArray.Add(MakeShared<FJsonValueObject>(Item.JsonObject));
	}
	JsonObject.JsonObject->SetArrayField(FieldName, JsonArray);
	return RefreshJsonString(JsonObject);
}

bool UWebNativeJsonLibrary::RemoveField(FJsonObjectWrapper& JsonObject, const FString& FieldName)
{
	if (!JsonObject.JsonObject.IsValid() || FieldName.IsEmpty())
	{
		return false;
	}
	const bool bHadField = JsonObject.JsonObject->HasField(FieldName);
	JsonObject.JsonObject->RemoveField(FieldName);
	if (!bHadField)
	{
		return false;
	}
	return RefreshJsonString(JsonObject);
}

// ------------------------------------------------------------------
// Private helpers
// ------------------------------------------------------------------

bool UWebNativeJsonLibrary::JsonFieldToProperty(
	const FString& FieldName,
	const FJsonObjectWrapper& SourceObject,
	FProperty* TargetProperty,
	void* TargetValuePtr)
{
	check(TargetProperty && TargetValuePtr);

	if (!SourceObject.JsonObject.IsValid())
	{
		return false;
	}

	const TSharedPtr<FJsonValue> JsonValue = SourceObject.JsonObject->TryGetField(FieldName);
	if (!JsonValue.IsValid())
	{
		FFrame::KismetExecutionMessage(*FString::Printf(TEXT("WebNativeJson: Field '%s' was not found on the provided JSON object."), *FieldName), ELogVerbosity::Warning);
		return false;
	}

	return FJsonObjectConverter::JsonValueToUProperty(JsonValue, TargetProperty, TargetValuePtr);
}

bool UWebNativeJsonLibrary::PropertyToJsonField(
	const FString& FieldName,
	FProperty* SourceProperty,
	const void* SourceValuePtr,
	FJsonObjectWrapper& TargetObject)
{
	check(SourceProperty && SourceValuePtr);

	if (!TargetObject.JsonObject.IsValid())
	{
		TargetObject.JsonObject = MakeShared<FJsonObject>();
	}

	TargetObject.JsonObject->SetField(FieldName, FJsonObjectConverter::UPropertyToJsonValue(SourceProperty, SourceValuePtr));
	return true;
}

#undef LOCTEXT_NAMESPACE
