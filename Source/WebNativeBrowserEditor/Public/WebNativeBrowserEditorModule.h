// Copyright (c) 2026 StarTechnology. All rights reserved.

// WebNativeBrowser Editor Module
// 跨平台兼容 UE 5.1-5.8 的编辑器工具模块

#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "Modules/ModuleManager.h"

class FWebNativeBrowserEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    void RegisterMenus();

#if ENGINE_MAJOR_VERSION == 5
    TSharedPtr<class FUICommandList> PluginCommands;
#endif
};
