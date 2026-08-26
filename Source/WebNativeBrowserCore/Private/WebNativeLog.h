// Copyright (c) 2026 StarTechnology. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Logging/LogMacros.h"

/**
 * Dedicated log category for the WebNativeBrowser plugin. Using a dedicated
 * category (rather than LogTemp) makes it easy to filter / grep the engine
 * log for plugin-specific events:
 *
 *     LogWebNative VeryVerbose
 *     LogWebNative Verbose
 *     LogWebNative Log
 *     LogWebNative Display
 *     LogWebNative Warning
 *     LogWebNative Error
 */
WEBNATIVEBROWSERCORE_API DECLARE_LOG_CATEGORY_EXTERN(LogWebNative, Log, All);
