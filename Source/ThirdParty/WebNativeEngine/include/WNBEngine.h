// Copyright (c) 2026 StarTechnology. All rights reserved.
//
// WebNativeEngine - 纯 C++ 核心库（零 Unreal Engine 依赖）
// 提供浏览器插件核心算法：授权验证、机器指纹、时间校验、本地加密。
// 该库由外部编译器构建（MSVC/Clang），不包含任何 UE 头文件/API。
// 本文件是库的公共接口（API surface），随库二进制分发。

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#ifdef _WIN32
#define WNB_API __declspec(dllexport)
#else
#define WNB_API
#endif

namespace wnb
{

// ============================================================
// 授权
// ============================================================

enum class LicenseStatus : int
{
	NotChecked = 0,   // 未检查
	Valid,            // 授权有效（未到期）
	Expired,          // 已到期
	NoLicense,        // 未找到授权文件
	Invalid,          // 授权文件无效/签名错误
	TimeTampered      // 时间校验异常
};

struct LicenseInfo
{
	std::string LicenseKey;
	std::string CustomerName;
	std::string CustomerCompany;
	std::string CustomerTaxId;
	std::string CustomerEmail;
	std::string LicenseType;      // trial / annual / decade / perpetual / enterprise
	std::string IssueDate;        // ISO 8601
	std::string ExpireDate;       // ISO 8601
	std::string MachineId;        // 机器指纹
	std::string TimeAnchor;       // 时间锚点
	std::vector<std::string> Features;
	std::string SignatureBase64;  // 签名（Base64）

	// 运行时解析出的 unix 时间戳（秒）；ExpireTimestamp == 0 表示永久授权
	int64_t IssueTimestamp = 0;
	int64_t ExpireTimestamp = 0;
	int32_t DaysRemaining = 0;
};

// 日志回调（可选）：UE 层传入后把库内日志转发到 UE_LOG；默认无输出
using LogFn = void (*)(int Level, const char* Message, void* UserData);

WNB_API void SetLogCallback(LogFn InFn, void* InUserData);

// ---- 授权文件解析 ----

// 解析 .license 文件内容。返回 true 表示结构解析成功。
WNB_API bool LicenseParseContent(
	const std::string& FileContent,
	LicenseInfo& OutInfo);

// 校验 jsonContent 与签名是否匹配。
WNB_API bool LicenseVerifySignature(
	const std::string& JsonContent,
	const std::string& SignatureBase64);

// ---- 机器指纹 ----

// 生成机器指纹。
WNB_API std::string LicenseGetMachineId();

// ---- 时间校验 ----

// 到期检查。OutStatus 输出 Valid 或 Expired；永久授权返回 Valid。
WNB_API bool LicenseCheckExpiry(
	const LicenseInfo& Info,
	int64_t NowUnixSeconds,
	LicenseStatus& OutStatus);

// 时间一致性检查。
WNB_API bool LicenseCheckTimeTampering(
	const LicenseInfo& Info,
	int64_t LastRunUnixSeconds,
	int64_t BootUnixSeconds,
	int64_t NowUnixSeconds);

// 系统启动时间（unix 秒）
WNB_API int64_t LicenseGetSystemBootTime();

// ---- 本地运行记录加密 ----

// 本地加密 / 解密。
WNB_API std::string LicenseEncrypt(const std::string& PlainText);
WNB_API std::string LicenseDecrypt(const std::string& CipherBase64);

// ---- 授权状态管理 ----
WNB_API LicenseStatus LicenseLoadAndCheck(
	const std::string& FileContent,
	bool bCheckMachineBinding);

WNB_API LicenseStatus LicenseGetStatus();

WNB_API void LicenseSetRunRecordPath(const std::string& Path);

// 设置机器绑定标记。合法标记成功绑定；缺失/非法则不绑定。
WNB_API void LicenseSetBindMachineToken(const std::string& MetaContent);

// 打包机校验：标记必须由授权服务器 RSA 签发，且标记内 machine_id 等于指定机器
// （当前打包机）。防止复制他人标记到本机打包 —— 不匹配返回 false。
WNB_API bool LicenseValidateBuildMetaForMachine(
	const std::string& MetaContent,
	const std::string& MachineId);

WNB_API void LicensePeriodicCheck();

WNB_API void LicenseReset();

WNB_API bool WNBGetRuntimeBadge(const char** OutText);

WNB_API void WNBSetRuntimeContext(bool bIsEditor);

WNB_API bool WNBGetEngineInfo(const char** OutInfo);

WNB_API bool WNBGetSessionId(char* OutBuf, int32_t OutBufLen);

// ============================================================
// 基础工具（对外暴露，便于 UE 层复用）
// ============================================================

WNB_API std::string Base64Encode(const uint8_t* Data, size_t Length);
WNB_API bool Base64Decode(const std::string& In, std::vector<uint8_t>& Out);
WNB_API void Sha256(const uint8_t* Data, size_t Length, uint8_t OutHash[32]);
WNB_API std::string ToHexUpper(const uint8_t* Data, size_t Length);

// ============================================================
// 浏览器引擎（CEF 核心）
// 由 UE 层薄封装调用；所有回调在 CEF 线程触发，须自行线程安全处理。
// ============================================================

struct WNBRect
{
	int X = 0;
	int Y = 0;
	int Width = 0;
	int Height = 0;
};

struct WNBSize
{
	int Width = 0;
	int Height = 0;
};

// Linux DMA-BUF 加速帧描述（对应 CEF OnAcceleratedPaint native pixmap）
struct WNBDmaBufPlane
{
	int FileDescriptor = -1;  // DMA-BUF fd
	int Stride = 0;
	int Offset = 0;
	int Size = 0;
};

struct WNBDmaBufFrame
{
	uint64_t Modifier = 0;
	bool bBGRA = true;
	WNBDmaBufPlane Planes[4];
	int PlaneCount = 0;
	WNBSize SourceSize;
};

// 拖拽源数据（平面结构；供 UE 层 Slate 拖拽展示使用）
struct WNBDragData
{
	const char* Url = nullptr;
	const char* Title = nullptr;
	bool bHasImage = false;
	int ImagePixelWidth = 0;
	int ImagePixelHeight = 0;
	int ImageDisplayWidth = 0;
	int ImageDisplayHeight = 0;
	int ImageHotspotX = 0;
	int ImageHotspotY = 0;
	const uint8_t* ImagePixels = nullptr;  // BGRA8 预乘，仅回调期间有效
	int ImagePixelsSize = 0;
};

struct WNBBrowserCreateParams
{
	const char* InitialURL = nullptr;
	WNBSize ViewSize{ 1280, 720 };
	int FrameRate = 60;
	bool bUseGpuAcceleratedRendering = true;
	bool bAllowCpuRenderFallback = true;
	bool bTransparentBackground = true;
	int MessageDispatchBudgetPerFrame = 5000;
	bool bShowPerformanceMonitor = false;
	bool bShowDownloadNotification = true;
};

// 回调（全部在 CEF 线程触发，库内不做线程切换）
struct WNBBrowserCallbacks
{
	void* UserData = nullptr;

	// CPU 帧（BGRA8）。Buffer 仅回调期间有效。bPopup=true 时是独立 popup 帧。
	void (*OnCpuFrame)(void* UserData, const uint8_t* Buffer, int Width, int Height,
		const WNBRect* DirtyRects, int DirtyCount, bool bPopup, int PopupX, int PopupY) = nullptr;

	// GPU 加速帧（Windows：共享 NT handle；Linux：DMA-BUF）。
	// 返回 true=已复制成功；*bRetryLater=true 表示本次不是真正失败（稍后重试），
	// 不计入 GPU fallback 连续失败计数（与 UE 侧 CopyAcceleratedFrame 语义一致）。
	bool (*OnSharedFrame)(void* UserData, void* SharedHandle, int Width, int Height,
		const WNBRect* DirtyRects, int DirtyCount, bool* bRetryLater) = nullptr;
	bool (*OnDmaBufFrame)(void* UserData, const WNBDmaBufFrame* Frame,
		const WNBRect* DirtyRects, int DirtyCount, bool* bRetryLater) = nullptr;

	// 浏览器创建/关闭（CEF UI 线程触发）。BrowserId 供 Linux 单进程消息桥映射。
	void (*OnBrowserCreated)(void* UserData, int BrowserId) = nullptr;

	// JS -> UE 消息
	void (*OnMessage)(void* UserData, const char* FunctionName, const char* MessageBody) = nullptr;
	void (*OnLoadStateChanged)(void* UserData, bool bIsLoading, bool bCanGoBack, bool bCanGoForward) = nullptr;
	void (*OnUrlChanged)(void* UserData, const char* Url) = nullptr;
	void (*OnBeforePopup)(void* UserData, const char* TargetUrl, const char* TargetFrameName) = nullptr;
	void (*OnLoadEnd)(void* UserData, const char* Url, int HttpStatusCode) = nullptr;
	void (*OnCursorChanged)(void* UserData, int CursorType) = nullptr;
	void (*OnDraggableRegionsChanged)(void* UserData, const WNBRect* Regions, int Count) = nullptr;
	void (*OnDownloadStateChanged)(void* UserData, const char* Url, bool bComplete, bool bCanceled, int Percent,
		int64_t ReceivedBytes, int64_t TotalBytes, int InterruptReason, bool bInterrupted) = nullptr;
	void (*OnBrowserClosed)(void* UserData) = nullptr;

	// CPU 渲染降级请求（GPU 连续失败时触发，由 UE 层决定是否降级）
	void (*OnCpuRenderFallbackRequested)(void* UserData) = nullptr;
	// UE 层查询是否应丢弃帧（控件隐藏/挂起/关闭时）
	bool (*ShouldDropPaintCallbacks)(void* UserData) = nullptr;

	// 拖拽源会话开始（CEF UI 线程）。Data 仅在回调期间有效；
	// UE 层返回 true=接管拖拽（启动 Slate 拖拽），返回 false=取消。
	bool (*OnStartDragging)(void* UserData, const WNBDragData* Data, int AllowedOps, int X, int Y) = nullptr;
	// 拖拽光标更新（CEF UI 线程；UE 层拖拽会话中可忽略或用于光标反馈）
	void (*OnDragCursorUpdated)(void* UserData, int Operation) = nullptr;

	// IME 组合范围/选区变化（CEF UI 线程；UE 层 Slate IME 上下文更新）
	void (*OnImeCompositionRangeChanged)(void* UserData, int From, int To,
		const WNBRect* Bounds, int BoundsCount) = nullptr;
	void (*OnTextSelectionChanged)(void* UserData, const char* SelectedText, int From, int To) = nullptr;

	// 文件对话框请求（CEF UI 线程触发；Linux 等无可用原生对话框的平台）。
	// 实现方必须【异步】弹出对话框（不阻塞 CEF UI 线程），完成后调用
	// WNBFileDialogComplete(RequestId, Files, bSuccess) 回传结果。
	// Title/DefaultFilePath 与 vector 指针仅在回调期间有效，实现方须立即拷贝。
	// 返回 true=已受理（等待完成回调）；返回 false=拒绝处理（按取消处理）。
	// Mode: 0=OpenFile 1=OpenMultiple 2=OpenFolder 3=SaveFile
	bool (*OnFileDialogRequest)(void* UserData, uint64_t RequestId, int Mode,
		const char* Title, const char* DefaultFilePath,
		const std::vector<std::string>* AcceptExtensions,
		const std::vector<std::string>* AcceptFilters,
		const std::vector<std::string>* AcceptDescriptions) = nullptr;
};

struct WNBBrowserImpl;
using WNBBrowserHandle = WNBBrowserImpl*;
#define WNB_INVALID_BROWSER (WNBBrowserHandle)nullptr

// ---- 生命周期 ----
WNB_API WNBBrowserHandle WNBCreateBrowser(const WNBBrowserCreateParams& Params, const WNBBrowserCallbacks& Cbs);
WNB_API void WNBDestroyBrowser(WNBBrowserHandle H);
WNB_API bool WNBIsValid(WNBBrowserHandle H);

// ---- 导航 ----
WNB_API void WNBLoadURL(WNBBrowserHandle H, const char* URL);
WNB_API void WNBGoBack(WNBBrowserHandle H);
WNB_API void WNBGoForward(WNBBrowserHandle H);
WNB_API void WNBReload(WNBBrowserHandle H, bool bIgnoreCache);
WNB_API const char* WNBGetCurrentURL(WNBBrowserHandle H);  // 内部缓存，仅回调内/立即使用

// ---- JavaScript / 消息 ----
WNB_API void WNBExecuteJavaScript(WNBBrowserHandle H, const char* Script);
WNB_API void WNBSendMessageToJavaScript(WNBBrowserHandle H, const char* FunctionName, const char* MessageBody);
WNB_API void WNBFlushMessagesToJS(WNBBrowserHandle H);

// ---- 开发者工具 ----
WNB_API void WNBShowDevTools(WNBBrowserHandle H);
WNB_API void WNBCloseDevTools(WNBBrowserHandle H);
WNB_API void WNBToggleDevTools(WNBBrowserHandle H);

// ---- 视图/渲染状态 ----
WNB_API void WNBSetViewSize(WNBBrowserHandle H, int Width, int Height);
WNB_API void WNBSetWindowlessRenderingSuspended(WNBBrowserHandle H, bool bSuspended);
WNB_API void WNBRequestCpuRenderingFallback(WNBBrowserHandle H);

// ---- 输入事件（坐标系为浏览器视口本地坐标）----
// Modifiers 位掩码: bit0=Shift bit1=Ctrl bit2=Alt bit3=Meta/Cmd bit4=CapsLock
WNB_API void WNBForwardMouseMove(WNBBrowserHandle H, int X, int Y, uint32_t Modifiers, bool bLeaving);
WNB_API void WNBForwardMouseButton(WNBBrowserHandle H, int X, int Y, int Button, bool bMouseUp, int ClickCount, uint32_t Modifiers);
WNB_API void WNBForwardMouseWheel(WNBBrowserHandle H, int X, int Y, float DeltaX, float DeltaY, uint32_t Modifiers);
WNB_API void WNBForwardKeyDown(WNBBrowserHandle H, int NativeKeyCode, const char* Key, uint32_t Modifiers, bool bSystemKey, uint16_t CharCode);
WNB_API void WNBForwardKeyUp(WNBBrowserHandle H, int NativeKeyCode, const char* Key, uint32_t Modifiers);
WNB_API void WNBForwardKeyChar(WNBBrowserHandle H, uint16_t CharCode, uint32_t Modifiers);

// ---- 焦点/触摸/光标（UE 层 Slate 事件转发）----
WNB_API void WNBSendFocus(WNBBrowserHandle H, bool bFocused);
WNB_API void WNBSendTouchEvent(WNBBrowserHandle H, int X, int Y, int Id, float Pressure, int Type, uint32_t Modifiers);
WNB_API int WNBGetCursorType(WNBBrowserHandle H);  // cef_cursor_type_t 数值
WNB_API void WNBSetHidden(WNBBrowserHandle H, bool bHidden);

// ---- IME（UE 层 Slate IME 上下文 → CEF）----
WNB_API void WNBImeSetComposition(WNBBrowserHandle H, const char* Text);
WNB_API void WNBImeCancelComposition(WNBBrowserHandle H);

// ---- Linux 单进程外部 BeginFrame（CEF OSR 需要主机驱动）----
WNB_API void WNBSendExternalBeginFrame(WNBBrowserHandle H);

// ---- 拖拽目标/源操作（UE 层 Slate 拖拽会话期间调用）----
WNB_API void WNBDragTargetDragEnter(WNBBrowserHandle H, int X, int Y, uint32_t Modifiers);
WNB_API void WNBDragTargetDragOver(WNBBrowserHandle H, int X, int Y, uint32_t Modifiers);
WNB_API void WNBDragTargetDragLeave(WNBBrowserHandle H);
WNB_API void WNBDragTargetDrop(WNBBrowserHandle H, int X, int Y, uint32_t Modifiers);
WNB_API void WNBDragSourceEndedAt(WNBBrowserHandle H, int X, int Y, int Operation);
WNB_API void WNBDragSourceSystemDragEnded(WNBBrowserHandle H);
WNB_API void WNBSetLastMousePosition(WNBBrowserHandle H, int X, int Y);

// ---- 帧/消息消费（游戏线程轮询，保持 UE 侧原有时序）----
// 取出最新合成 CPU 帧（BGRA8）与脏区域；无新帧返回 false。
WNB_API bool WNBConsumeCpuFrame(WNBBrowserHandle H, std::vector<uint8_t>& OutFrame,
	int& OutWidth, int& OutHeight, std::vector<WNBRect>& OutDirtyRects);
// 取出排队中的 JS->UE 消息（最多 MaxMessages 条），返回实际条数。
WNB_API int WNBDrainQueuedMessages(WNBBrowserHandle H, int MaxMessages,
	std::vector<std::pair<std::string, std::string>>& OutMessages);
// 浏览器标识（CEF GetIdentifier）
WNB_API int WNBGetIdentifier(WNBBrowserHandle H);

// ---- 全局浏览器生命周期（进程退出时）----
WNB_API int WNBRequestCloseAllBrowsers();
WNB_API int WNBGetTrackedBrowserCount();
WNB_API void WNBClearTrackedBrowsersForShutdown();

// ---- 文件对话框结果回传 ----
// UE 层弹完对话框后调用（任意线程安全）；库内自动投递回 CEF UI 线程执行
// Callback->Continue/Cancel。Files 必须为绝对路径（UTF-8）；bSuccess=false 表示取消。
WNB_API void WNBFileDialogComplete(uint64_t RequestId, const std::vector<std::string>& Files, bool bSuccess);

} // namespace wnb
