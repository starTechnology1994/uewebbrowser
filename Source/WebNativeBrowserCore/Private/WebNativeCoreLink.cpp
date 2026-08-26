// Copyright (c) 2026 StarTechnology. All rights reserved.
//
// 模块链接壳：
// SWebNativeBrowser / WebNativeBrowserCoreModule / WebNativeBrowserRHIHelper 的
// 实现位于预编译库 WebNativeCoreUe.lib（含 IMPLEMENT_MODULE 模块注册）。
// 本文件通过全局对象构造函数显式引用库内模块实现符号，强制链接器拉取
// 对应 obj，避免静态库按需拉取（/OPT:REF）裁掉模块注册代码。

#include "WebNativeBrowserCoreModule.h"
#include "SWebNativeBrowser.h"
#include "WebNativeBrowserRHIHelper.h"

// 具有外部链接的全局函数指针，承接库内模块单例函数地址。
// 编译器无法证明没有其他翻译单元读取它，因此写入此变量不能被优化掉，
// 从而在 obj 中留下对 ?Get@FWebNativeBrowserCoreModule@@... 的未解析引用，
// 迫使链接器从 WebNativeCoreUe.lib 拉取含 IMPLEMENT_MODULE 的 obj。
using FWebNativeBrowserCoreModuleGetFn = FWebNativeBrowserCoreModule& (*)();
FWebNativeBrowserCoreModuleGetFn GWebNativeCoreForceLinkModule = nullptr;

namespace
{
	struct FWebNativeCoreLink
	{
		FWebNativeCoreLink()
		{
			// 注意：不能写成 (void)&Get 或赋值给函数内局部 volatile——
			// MSVC /O2 会判定其为无副作用语句并整体删除，导致 obj 里
			// 不产生对库符号的引用，链接器因此不拉取 IMPLEMENT_MODULE
			// 的 obj，最终 exe 缺失模块注册（Plugin 'WebNativeBrowser'
			// failed to load because module 'WebNativeBrowserCore' could
			// not be found）。
			GWebNativeCoreForceLinkModule = &FWebNativeBrowserCoreModule::Get;
		}
	};

	FWebNativeCoreLink GWebNativeCoreLink;
}
