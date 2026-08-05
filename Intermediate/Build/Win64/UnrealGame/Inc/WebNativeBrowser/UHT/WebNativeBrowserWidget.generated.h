// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WebNativeBrowserWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WEBNATIVEBROWSER_WebNativeBrowserWidget_generated_h
#error "WebNativeBrowserWidget.generated.h already included, missing '#pragma once' in WebNativeBrowserWidget.h"
#endif
#define WEBNATIVEBROWSER_WebNativeBrowserWidget_generated_h

#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_10_DELEGATE \
struct _Script_WebNativeBrowser_eventWebNativeBrowserMessageReceivedEvent_Parms \
{ \
	FString FunctionName; \
	FString MessageBody; \
}; \
static inline void FWebNativeBrowserMessageReceivedEvent_DelegateWrapper(const FMulticastScriptDelegate& WebNativeBrowserMessageReceivedEvent, const FString& FunctionName, const FString& MessageBody) \
{ \
	_Script_WebNativeBrowser_eventWebNativeBrowserMessageReceivedEvent_Parms Parms; \
	Parms.FunctionName=FunctionName; \
	Parms.MessageBody=MessageBody; \
	WebNativeBrowserMessageReceivedEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_11_DELEGATE \
struct _Script_WebNativeBrowser_eventWebNativeBrowserLoadStateChangedEvent_Parms \
{ \
	bool bIsLoading; \
	bool bCanGoBack; \
	bool bCanGoForward; \
}; \
static inline void FWebNativeBrowserLoadStateChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& WebNativeBrowserLoadStateChangedEvent, bool bIsLoading, bool bCanGoBack, bool bCanGoForward) \
{ \
	_Script_WebNativeBrowser_eventWebNativeBrowserLoadStateChangedEvent_Parms Parms; \
	Parms.bIsLoading=bIsLoading ? true : false; \
	Parms.bCanGoBack=bCanGoBack ? true : false; \
	Parms.bCanGoForward=bCanGoForward ? true : false; \
	WebNativeBrowserLoadStateChangedEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_12_DELEGATE \
struct _Script_WebNativeBrowser_eventWebNativeBrowserUrlChangedEvent_Parms \
{ \
	FString URL; \
}; \
static inline void FWebNativeBrowserUrlChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& WebNativeBrowserUrlChangedEvent, const FString& URL) \
{ \
	_Script_WebNativeBrowser_eventWebNativeBrowserUrlChangedEvent_Parms Parms; \
	Parms.URL=URL; \
	WebNativeBrowserUrlChangedEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_13_DELEGATE \
struct _Script_WebNativeBrowser_eventWebNativeBrowserBeforePopupEvent_Parms \
{ \
	FString TargetURL; \
	FString TargetFrameName; \
}; \
static inline void FWebNativeBrowserBeforePopupEvent_DelegateWrapper(const FMulticastScriptDelegate& WebNativeBrowserBeforePopupEvent, const FString& TargetURL, const FString& TargetFrameName) \
{ \
	_Script_WebNativeBrowser_eventWebNativeBrowserBeforePopupEvent_Parms Parms; \
	Parms.TargetURL=TargetURL; \
	Parms.TargetFrameName=TargetFrameName; \
	WebNativeBrowserBeforePopupEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_14_DELEGATE \
struct _Script_WebNativeBrowser_eventWebNativeBrowserLoadEndEvent_Parms \
{ \
	FString URL; \
	int32 HttpStatusCode; \
}; \
static inline void FWebNativeBrowserLoadEndEvent_DelegateWrapper(const FMulticastScriptDelegate& WebNativeBrowserLoadEndEvent, const FString& URL, int32 HttpStatusCode) \
{ \
	_Script_WebNativeBrowser_eventWebNativeBrowserLoadEndEvent_Parms Parms; \
	Parms.URL=URL; \
	Parms.HttpStatusCode=HttpStatusCode; \
	WebNativeBrowserLoadEndEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_SPARSE_DATA
#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetViewSize); \
	DECLARE_FUNCTION(execDeprojectCursorToWorld); \
	DECLARE_FUNCTION(execGetRawPlatformCursorPos); \
	DECLARE_FUNCTION(execSetForwardUEKeyEvents); \
	DECLARE_FUNCTION(execSetAutoResizeToWidget); \
	DECLARE_FUNCTION(execSetViewResolution); \
	DECLARE_FUNCTION(execToggleDevTools); \
	DECLARE_FUNCTION(execCloseDevTools); \
	DECLARE_FUNCTION(execShowDevTools); \
	DECLARE_FUNCTION(execSetFocusToGameViewport); \
	DECLARE_FUNCTION(execSendMessageToJS); \
	DECLARE_FUNCTION(execSendMessageToJavaScript); \
	DECLARE_FUNCTION(execExecuteJavaScript); \
	DECLARE_FUNCTION(execReload); \
	DECLARE_FUNCTION(execGoForward); \
	DECLARE_FUNCTION(execGoBack); \
	DECLARE_FUNCTION(execLoadURL);


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetViewSize); \
	DECLARE_FUNCTION(execDeprojectCursorToWorld); \
	DECLARE_FUNCTION(execGetRawPlatformCursorPos); \
	DECLARE_FUNCTION(execSetForwardUEKeyEvents); \
	DECLARE_FUNCTION(execSetAutoResizeToWidget); \
	DECLARE_FUNCTION(execSetViewResolution); \
	DECLARE_FUNCTION(execToggleDevTools); \
	DECLARE_FUNCTION(execCloseDevTools); \
	DECLARE_FUNCTION(execShowDevTools); \
	DECLARE_FUNCTION(execSetFocusToGameViewport); \
	DECLARE_FUNCTION(execSendMessageToJS); \
	DECLARE_FUNCTION(execSendMessageToJavaScript); \
	DECLARE_FUNCTION(execExecuteJavaScript); \
	DECLARE_FUNCTION(execReload); \
	DECLARE_FUNCTION(execGoForward); \
	DECLARE_FUNCTION(execGoBack); \
	DECLARE_FUNCTION(execLoadURL);


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_ACCESSORS
#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWebNativeBrowserWidget(); \
	friend struct Z_Construct_UClass_UWebNativeBrowserWidget_Statics; \
public: \
	DECLARE_CLASS(UWebNativeBrowserWidget, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/WebNativeBrowser"), NO_API) \
	DECLARE_SERIALIZER(UWebNativeBrowserWidget)


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUWebNativeBrowserWidget(); \
	friend struct Z_Construct_UClass_UWebNativeBrowserWidget_Statics; \
public: \
	DECLARE_CLASS(UWebNativeBrowserWidget, UWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/WebNativeBrowser"), NO_API) \
	DECLARE_SERIALIZER(UWebNativeBrowserWidget)


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWebNativeBrowserWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebNativeBrowserWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebNativeBrowserWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebNativeBrowserWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebNativeBrowserWidget(UWebNativeBrowserWidget&&); \
	NO_API UWebNativeBrowserWidget(const UWebNativeBrowserWidget&); \
public: \
	NO_API virtual ~UWebNativeBrowserWidget();


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWebNativeBrowserWidget(UWebNativeBrowserWidget&&); \
	NO_API UWebNativeBrowserWidget(const UWebNativeBrowserWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWebNativeBrowserWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWebNativeBrowserWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWebNativeBrowserWidget) \
	NO_API virtual ~UWebNativeBrowserWidget();


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_16_PROLOG
#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_SPARSE_DATA \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_RPC_WRAPPERS \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_ACCESSORS \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_INCLASS \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_SPARSE_DATA \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_ACCESSORS \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_INCLASS_NO_PURE_DECLS \
	FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WEBNATIVEBROWSER_API UClass* StaticClass<class UWebNativeBrowserWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_WNFabTmp_51_cf7b89f1_HostProject_Plugins_WebNativeBrowser_Source_WebNativeBrowser_Public_WebNativeBrowserWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
