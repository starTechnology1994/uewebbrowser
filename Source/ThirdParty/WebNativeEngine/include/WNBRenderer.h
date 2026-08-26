// Copyright (c) 2026 StarTechnology. All rights reserved.
//
// 渲染进程处理器。
// Linux --single-process 模式下，CEF 没有独立 Helper 子进程，插件 DLL 的
// CefApp 必须同时充当 CefRenderProcessHandler。
// UE 层只需在 CefApp::GetRenderProcessHandler 中返回 WNBGetRenderProcessHandler()。

#pragma once

#include "include/cef_render_process_handler.h"

#include "WNBEngine.h"

namespace wnb
{

// 渲染进程处理器单例（线程安全；可跨多个 CefApp 共享）
WNB_API CefRefPtr<CefRenderProcessHandler> WNBGetRenderProcessHandler();

// 设置单进程模式（Linux --single-process）。UE 层在 CEF 初始化前调用。
// 单进程模式下 JS->UE 消息绕过 Mojo IPC 直接路由到对应 BrowserEngine。
WNB_API void WNBSetSingleProcessMode(bool bSingleProcess);

} // namespace wnb
