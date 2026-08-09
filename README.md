﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿# WebNative Browser Plugin

WebNativeBrowser 是面向 Unreal Engine 5 的高性能企业级跨平台 Web UI
与 Chromium 浏览器解决方案拥有原生级别的性能，提供原生浏览器体验，支持 Windows 和Linux（x86\_64、ARM64）。Linux 最低要求   GLIBC 2.17  ，详见
[技术规格 → Linux 发行版兼容性](#linux-发行版兼容性)。

> 项目主页与源码仓库  ：<https://github.com/starTechnology1994/uewebbrowser>
>
> - 预编译插件下载：<https://github.com/starTechnology1994/uewebbrowser/releases>
> - 文档与 Wiki：<https://github.com/starTechnology1994/uewebbrowser/wiki>
> - 问题反馈：<https://github.com/starTechnology1994/uewebbrowser/issues>
> - 商务联系（授权、合作、技术支持）：：：<startechnology1994@163.com>：：
>
> 闭源发行版（Fab）面向已购买授权的用户；二进制与该仓库内容保持一致，源码仓库仅做对外公开版本与文档维护。

***

## 核心特性

### 面向快速开发的四大解决方案

| 方向       | Web 侧能力                | UE 侧能力             | 适用成果             |
| -------- | ---------------------- | ------------------ | ---------------- |
| 数字孪生     | 设备树、告警、工单、报表、GIS 与业务流程 | 园区、产线、建筑、设备与实时状态   | 可视、可查、可控的三维数字世界  |
| 游戏与运行时工具 | 道具库、商城、活动页、任务面板和编辑工具   | 游戏世界、Actor、玩法和权威逻辑 | 快速迭代的游戏 UI 与场景工具 |
| AI 应用界面  | AI 助手、知识库、生成式页面和结果展示   | 三维角色、场景反馈和业务动作     | AI 与实时三维融合体验     |
| 报表与数据大屏  | 图表、表格、地图、筛选和响应式布局      | 三维态势、对象状态和空间表达     | 数据与三维联动驾驶舱       |

WebNativeBrowser 特别适用于数字孪生：让成熟 Web 技术承载数据与业务系统，让 Unreal Engine 专注实时三维场景，再通过 JS ↔ UE 消息实现设备选择、镜头定位、状态更新和场景控制。

> AI 方向指承载 AI 应用界面、复用 AI 辅助生成的前端成果并连接 UE 场景；插件本身不内置大语言模型或第三方推理服务。

### 高性能 GPU 加速渲染

- 基于 GPU 共享内存的跨进程纹理传输，画面直通 UE5 渲染管线，无 CPU 拷贝开销
- 多渲染后端自适应：根据平台自动选择最优 GPU 加速方案
- 持久纹理复用机制，每帧渲染零额外显存分配

### 智能帧率调节

- 静态画面零开销  ：页面静止时自动暂停渲染，GPU/CPU 无额外消耗
- 动态内容按需渲染  ：动画、滚动等场景实时唤醒，流畅响应
- 视频播放自适应帧率  ：自动匹配视频帧率，避免无效重复合成

### 跨平台

| 平台      | 状态  |
| ------- | --- |
| Windows | 稳定  |
| Linux   | 稳定  |
| macOS   | 计划中 |

### 企业级多开与像素流送

- 支持同一 UE 应用创建多个 WebNative Browser 控件，适用于多面板、多屏和多窗口
- 支持同一打包应用启动多个独立实例；实际并发规模取决于页面、视频、分辨率和硬件资源
- 可作为 UE 最终画面的一部分与 Unreal Engine Pixel Streaming 组合使用
- Pixel Streaming 远端键鼠、触摸和焦点以项目输入配置为准
- 远端用户本机文件上传应由 Pixel Streaming 前端与项目服务处理，不等同于渲染服务器本机文件选择

### Linux 产品化适配

- Linux x86\_64 与 ARM64 双架构
- 中文输入、剪贴板、键盘、鼠标和焦点交互
- Runtime/Shipping 文件选择、上传和下载
- 单进程与多进程可配置，适配不同硬件与部署环境
- 面向国产 CPU/GPU、麒麟和统信等环境提供验证路径
- 已完成砺算,摩尔线程 GPU 环境专项适配；具体显卡型号、驱动和系统组合以发布版兼容性矩阵为准
- 覆盖多浏览器控件、应用多开、视频、消息和退出生命周期

### 原生浏览器体验

- 完整 Chromium 内核，覆盖 WebRTC、WebGL、MediaSource、Canvas 等主流现代 Web 能力
- 支持 4K 视频与最高 8K 应用场景；实际效果取决于编码、页面、GPU、驱动和输出分辨率
- 透明背景支持（UI 叠加层场景）
- 完整的键盘 / 鼠标 / 触摸输入支持
- 鼠标透明穿透（Alpha 阈值可控）
- 内置 DevTools 远程调试器
- 权限管理（摄像头、麦克风、剪贴板、通知等 18 项权限策略）
- 全局 alert/confirm/prompt 注入（Google 风格白色对话框，所有网页自动生效）
- 文件选择器（`<input type="file">`；Windows 原生窗口 / Linux Runtime Slate 窗口）
- 文件下载器（系统保存对话框）
- 网页加载占位动画（首帧到达前显示旋转加载圈）

### UE-Blueprint 双向通信

- UE → JS  ：执行任意 JavaScript 脚本；JSON 消息桥接
- JS → UE  ：JS 端发送消息，UE 端通过 `OnMessageReceived` 委托接收
- 事件驱动  ：JS 端通过 `on()` / `off()` 按函数名订阅
- 支持 C++ 委托和 Blueprint 动态委托，消息批量合并以优化性能

### 内置 JSON 函数库（开箱即用）

- 内置 C++ 实现的 JSON 蓝图函数库，，，开箱即用，，，无需安装 JsonBlueprintUtilities 等任何第三方 JSON 插件
- 基于引擎原生 Json / JsonUtilities 模块，Win64 / Linux / LinuxArm64 全平台可用
- 动态构建、读取和修改任意层级的嵌套 JSON 对象与数组（含对象数组），，，无需预先定义结构体，，
- 覆盖完整操作链：`Create Json Object` / `Load Json From String` / `Json Object To String` / `Get/Set Json 各类型字段与数组` / `Has Json Field` / `Get Json Field Names` / `Remove Json Field`
- 实测性能：单字段读取约 0.06 µs/次，反序列化约 2 µs/次（基于引擎内置 Json 后端，无额外逐次分配开销）

### 导航控制

| 蓝图函数        | 功能              |
| ----------- | --------------- |
| `LoadURL`   | 加载指定 URL        |
| `GoBack`    | 后退到上一页          |
| `GoForward` | 前进到下一页          |
| `Reload`    | 重新加载当前页（可选忽略缓存） |

### 输入增强

| 属性                    | 说明                                         |
| --------------------- | ------------------------------------------ |
| `bForwardUEKeyEvents` | 开启后，焦点在 UE 场景中时键盘事件也转发给 CEF（用于撤销重做等双重处理场景） |

### Web 到 UE 场景放置

- Web 页面可作为道具库、资产库、建筑目录、设备列表或运行时工具栏
- 支持从 Web 拖拽资源进入 UE 场景的放置工作流
- 支持点击 Web 条目后切换到 UE 游戏视口，再在场景中点击放置
- 蓝图可直接调用插件封装函数 `SetFocusToGameViewport`、`GetRawPlatformCursorPos` 和 `DeprojectCursorToWorld`
- 项目可自行组合射线检测、预览体、吸附、碰撞、权限与 Actor 创建规则

> WebNativeBrowser 负责 Web/UE 之间的消息、焦点与光标空间衔接；最终 UObject/Actor 操作应由项目在 UE 游戏线程中执行，并校验网页传入的资源 ID 和业务参数。

***

## 快速开始

### 安装

1. 将插件放入项目的 `Plugins/` 目录
2. 启动引擎，启用插件
3. UI 控件库中拖入   WebNative Browser   控件
4. 设置 `InitialURL` 即可加载网页

### 授权流程

插件采用授权文件机制，编辑器环境需要有效授权才能使用：

| 步骤 | 操作                                                                  |
| -- | ------------------------------------------------------------------- |
| 1  | 启动编辑器运行一次，插件自动在`Saved/licenses/` 生成 `计算机名_用户名_machine_id.dat` 机器码文件 |
| 2  | 将该机器码文件发送给授权方，获取`.license` 授权文件                                     |
| 3  | 将`.license` 文件放入插件目录的 `Content/webnative/licenses/`，重启编辑器后授权生效      |

> `.license`     的放置位置与插件安装位置对应  ，插件会自动查找，以下两种位置均支持：
>
> - 项目级安装  ：`<项目>/Plugins/WebNativeBrowser/Content/webnative/licenses/`
> - 引擎级安装（Fab 商城下载默认）  ：`<UE 引擎目录>/Engine/Plugins/Marketplace/WebNativeBrowser/Content/webnative/licenses/`
>
> 插件通过 `IPluginManager` 定位自身 Content 目录，无论安装在项目还是引擎目录都能找到授权文件，无需修改任何配置。

\*打包时 `.license` 会作为物理文件（NonUFS）随插件复制到目标位置的 `Content/webnative/licenses/`（不进 .pak），客户可随时替换该文件以更换或续期授权。
\*打包后的程序续期，只需将 `.license` 放入 `<项目>/Saved/licenses/` 即可续期，无需重新打包（`Saved/licenses/` 优先级最高，用于按机器授权与续期）。

### 收费标准

WebNativeBrowser 定位为面向 Unreal Engine 5 的高性能企业级跨平台 Web UI
与 Chromium 浏览器解决方案，提供个人版和商业版两种标准授权：

| 授权类型 |     1 年授权 |     10 年授权 | 使用范围               |
| ---- | --------: | ---------: | ------------------ |
| 个人版  | 1,000 RMB |  8,000 RMB | 仅限购买者本人            |
| 商业版  | 2,000 RMB | 15,000 RMB | 同一法律主体内部不限人数、设备和项目 |

授权说明：

- 个人版  ：仅限购买者本人使用，可用于本人独立开发的商业或非商业项目，不得用于企业、工作室或多人团队共同开发，不得转让、转售或共享授权文件。
- 商业版  ：以单一法律主体名义购买，该主体内部不限项目、不限使用人数、支持多设备和最终应用打包分发。“不限人数”不自动覆盖母公司、子公司、关联公司、外包方或客户团队。可按正式销售政策申请合规发票。
- 10 年授权  ：自激活日起连续 120 个月，在授权期内享有对应版本的使用权、适用更新和标准技术支持。它不是源代码授权，也不代表对未来所有 UE、操作系统或硬件环境作无条件支持。
- 续费  ：年费到期后需重新购买授权。到期未续费的插件在编辑器中会显示水印，功能仍可正常使用；已打包发布的程序也会出现水印提示，不影响核心功能。
- 退款  ：授权文件为数字商品，一经交付不支持退款。

法律声明：

- 未经授权使用、复制、传播本插件源代码或二进制文件，均属侵权行为。
- 禁止逆向工程、反编译、反汇编本插件。
- 授权方不对插件适用于特定用途做任何明示或暗示的保证。
- 因使用本插件造成的任何直接或间接损失，授权方不承担责任。

***

## JS ↔ UE 双向通信

插件通过 `functionName` + `messageBody` 消息通道实现 UE 与 JS 之间的双向通信。

### JS 端 API

插件自动注入全局对象 `window.WebNative`，提供以下方法：

```javascript
// ========== 发送消息到 UE ==========
WebNative.send("FunctionName", "MessageBody");
WebNative.send("FunctionName", { score: 100, player: "Player1" });

// ========== 监听 UE 发来的消息 ==========

// 方式: on/off（按 FunctionName 订阅）
function handleMessage(body) {
    console.log("收到:", body);
}
WebNative.on("EventName", handleMessage);
WebNative.off("EventName", handleMessage);
```

### UE 端 API

发送消息到 JS：

```cpp
// C++ — 发送消息给 JS
WebView->SendMessageToJS(TEXT("OnGameScore"), TEXT(R"({"score": 9999, "level": 42})"));

// Blueprint — 调用 SendMessageToJS 节点
//   FunctionName: "OnPlayerData"
//   MessageBody:  '{"name":"Player1","hp":100}'
```

接收 JS 发来的消息：

```cpp
// C++ — 绑定委托
WebView->OnMessageReceived.AddDynamic(this, &UMyWidget::OnWebViewMessage);

void UMyWidget::OnWebViewMessage(const FString& FunctionName, const FString& MessageBody)
{
    if (FunctionName == TEXT("OnLogin"))
    {
        // 解析 JSON
        TSharedPtr<FJsonObject> JsonObj;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(MessageBody);
        FJsonSerializer::Deserialize(Reader, JsonObj);

        FString Username = JsonObj->GetStringField(TEXT("username"));
        UE_LOG(LogTemp, Log, TEXT("User logged in: %s"), *Username);
    }
}
```

Blueprint：

&#x20;在 Details 面板绑定 `OnMessageReceived` 事件，`FunctionName` 和 `MessageBody` 作为参数传入。

### 消息类型兼容性

#### JS → UE（`WebNative.send()`）

`WebNative.send(functionName, messageBody)` 的 `messageBody` 参数兼容以下类型：

| 类型                   | 示例                              | JS 端处理               | UE 端收到                                     |
| -------------------- | ------------------------------- | -------------------- | ------------------------------------------ |
| JS 对象                | `{score: 100, name: "Player1"}` | 自动`JSON.stringify()` | JSON 字符串`'{"score":100,"name":"Player1"}'` |
| 字符串                  | `"hello"`                       | 直接传递                 | 原始字符串`"hello"`                             |
| 数字                   | `42`                            | `String(42)`         | 字符串`"42"`                                  |
| 布尔值                  | `true`                          | `String(true)`       | 字符串`"true"`                                |
| `null` / `undefined` | —                               | 转为空字符串               | 空字符串`""`                                   |

> 推荐用法  ：直接传 JS 对象，插件会自动处理 JSON 序列化。UE 端通过 `FJsonSerializer` 解析即可。

```javascript
// 推荐：直接传对象
WebNative.send("OnPlayerScore", { score: 9999, combo: 42 });

// 也可以：传 JSON 字符串
WebNative.send("OnPlayerScore", JSON.stringify({ score: 9999, combo: 42 }));

// 简单场景：传纯文本
WebNative.send("OnChat", "队伍准备好了");
```

#### UE → JS（`SendMessageToJS`）

UE 端发送 `FString` 类型的 `MessageBody`。JS 回调始终收到原始字符串，插件不会替业务代码调用 `JSON.parse()`：

| UE 端发送      | JS 端`WebNative.on()` 收到 |
| ----------- | ----------------------- |
| 有效 JSON 字符串 | 原始 JSON 字符串             |
| 纯文本字符串      | 原始字符串                   |
| `"10"`      | 字符串`"10"`               |
| 空字符串        | 空字符串`""`                |

```cpp
// UE 端：发送 JSON
WebView->SendMessageToJS(TEXT("OnGameData"), TEXT(R"({"players":32,"map":"Dust2"})"));
// JS 回调收到原始字符串: '{"players":32,"map":"Dust2"}'

// UE 端：发送纯文本
WebView->SendMessageToJS(TEXT("OnTips"), TEXT("新的挑战者出现了!"));
// JS 回调收到字符串: "新的挑战者出现了!"

// UE 端：发送数字
WebView->SendMessageToJS(TEXT("OnCountdown"), TEXT("10"));
// JS 回调收到字符串: "10"
```

```javascript
WebNative.on("OnGameData", function(messageBody) {
    // 只有业务明确知道该消息是 JSON 时才自行解析。
    const gameData = JSON.parse(messageBody);
    console.log(gameData.players);
});
```

### 完整示例：网页登录

网页端（login.html）：

```html
<!DOCTYPE html>
<html>
<head><meta charset="utf-8"><title>Login</title></head>
<body>
  <input id="username" type="text" placeholder="用户名">
  <input id="password" type="password" placeholder="密码">
  <button onclick="doLogin()">登录</button>
  <div id="status"></div>

  <script>
    function doLogin() {
      const user = document.getElementById('username').value;
      const pass = document.getElementById('password').value;
      WebNative.send('OnLogin', JSON.stringify({
        username: user,
        password: pass
      }));
    }

    // 监听 UE 返回的登录结果
    WebNative.on('LoginResult', function(body) {
      document.getElementById('status').innerText =
        body.success ? '登录成功! ' + body.message : '登录失败: ' + body.message;
    });
  </script>
</body>
</html>
```

UE 端：

```cpp
void UMyLoginWidget::OnWebViewMessage(const FString& FunctionName, const FString& MessageBody)
{
    if (FunctionName == TEXT("OnLogin"))
    {
        TSharedPtr<FJsonObject> Json;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(MessageBody);
        FJsonSerializer::Deserialize(Reader, Json);

        FString Username = Json->GetStringField(TEXT("username"));
        FString Password = Json->GetStringField(TEXT("password"));

        bool bSuccess = ValidateLogin(Username, Password);

        // 把结果返回给网页
        FString ResultJson = FString::Printf(
            TEXT(R"({"success":%s,"message":"%s"})"),
            bSuccess ? TEXT("true") : TEXT("false"),
            bSuccess ? TEXT("欢迎回来!") : TEXT("用户名或密码错误")
        );
        WebView->SendMessageToJS(TEXT("LoginResult"), ResultJson);
    }
}
```

***

## 文件下载

插件内置 CEF 原生下载流程，支持 Windows/Linux 双平台。用户点击网页下载链接（`<a download>`、`blob:` URL、HTTP 下载等）后：

1. 弹出保存对话框（Windows 原生对话框 / Linux 插件自带 Runtime Slate 对话框）
2. CEF 开始下载，实时注入 `WebNative` 下载事件
3. 可选显示内置下载进度条和完成通知 toast（白色 Material 风格）

### 内置 UI 开关

通过 config 控制是否显示内置进度条/通知（事件始终广播，不受此开关影响）：

```ini
[WebNative]
show_download_notification=true   ; 默认显示内置 UI
; show_download_notification=false ; 关闭内置 UI，仅广播事件，开发者自行监听绘制
```

### JS 监听下载事件

无论 `show_download_notification` 是否开启，以下事件都会通过 `window.WebNative.emit()` 广播，网页可订阅自定义 UI：

```javascript
// 下载进度（每个整数百分点触发一次）
WebNative.on('webNativeDownloadProgress', function(body) {
    const data = JSON.parse(body);
    console.log(`下载中: ${data.filename} ${data.percent}% (${data.received}/${data.total})`);
    // data: { filename, received, total, percent }
});

// 下载完成
WebNative.on('webNativeDownloadComplete', function(body) {
    const data = JSON.parse(body);
    console.log(`完成: ${data.filename} 大小: ${data.size} 路径: ${data.path}`);
    // data: { filename, path, size }
});

// 下载失败/取消
WebNative.on('webNativeDownloadFailed', function(body) {
    const data = JSON.parse(body);
    console.log(`失败: ${data.filename}`);
    // data: { filename }
});
```

### 事件数据格式

| 事件                          | 字段         | 类型     | 说明            |
| --------------------------- | ---------- | ------ | ------------- |
| `webNativeDownloadProgress` | `filename` | string | 下载文件名         |
| <br />                      | `received` | number | 已接收字节数        |
| <br />                      | `total`    | number | 总字节数（未知时为 0）  |
| <br />                      | `percent`  | number | 进度百分比（0-100）  |
| `webNativeDownloadComplete` | `filename` | string | 下载文件名         |
| <br />                      | `path`     | string | 保存绝对路径（正斜杠格式） |
| <br />                      | `size`     | number | 已下载字节数        |
| `webNativeDownloadFailed`   | `filename` | string | 下载文件名         |

### 平台差异

| 平台      | 保存对话框                  | 默认目录                   |
| ------- | ---------------------- | ---------------------- |
| Windows | CEF/Win32 原生对话框        | `<Project>/Downloads/` |
| Linux   | 插件自带 Runtime Slate 对话框 | `<Project>/Downloads/` |

Linux 对话框模块只依赖 Runtime Slate，不依赖 `DesktopPlatform`、`SlateFileDialogs`
或 `DirectoryWatcher`，因此可以进入 Linux Shipping 包。选择结果会回到 CEF UI
线程并继续使用 Chromium 的标准文件授权/下载流程。

> 无桌面环境注意  ：独立 Slate 窗口仍需要可用的本机窗口与输入环境。
> 纯 headless 或像素流送中的“远端用户本机文件选择”不是同一问题；后者需要浏览器端
> 上传协议，当前对话框不会把服务器文件系统映射到远端客户端。

***

## 调试与日志

### CEF 性能监视器

三种方式开启：

1\. Widget 属性：

选中 UMG 中的 `UWebNativeBrowserWidget`，在 Details 面板勾选：

```
CEF | Rendering → Show Cef Performance Monitor
```

2\. ini 配置（[DefaultGame.ini](file:Config/DefaultGame.ini)）：

```ini
[WebNative]
show_cef_performance_monitor=true
```

3\. 蓝图：

调用 `ExecuteJavaScript` 节点，输入：

```javascript
"WebNativePerf && WebNativePerf.show();"
```

开启后效果：

左上角显示自定义 Slate 性能叠加层（半透明黑底绿字），包含以下实时指标：

| 指标      | 说明                                                                              |
| ------- | ------------------------------------------------------------------------------- |
| CEF FPS | CEF 合成器实际画面产出频率（基于`OnAcceleratedPaint` 回调计数的滑动窗口平均值）                            |
| Frames  | 自浏览器创建以来的累计合成帧数                                                                 |
| View    | 当前 CEF 渲染视口分辨率（像素）                                                              |
| Mem     | UE 进程当前占用的物理内存（MB），包含 CEF 子进程开销                                                 |
| Accel   | 渲染加速模式：`SharedTex`（Windows D3D11 共享纹理）、`DMA-BUF`（Linux Vulkan 零拷贝）、`CPU`（软渲染回退） |

> 注意  ：CEF FPS 是全页面合成频率，不等于视频帧率。视频播放由 GPU 内部解码管线独立处理，帧率不受限制。

### 日志文件

插件的 UE\_LOG 输出（`LogWebNative` 类别）会自动写入独立日志文件：

```
<Project>/Saved/Logs/cef/WebNativeBrowser.log          # 插件日志
<Project>/Saved/Logs/cef/cef.log                    # CEF Chromium 日志（如果有）
```

受支持的日志详细度级别：

| 级别      | 说明         | 示例                                                           |
| ------- | ---------- | ------------------------------------------------------------ |
| Error   | 必须关注的故障    | `CopyDmaBufToTexture FAILED`、`VK_ERROR_DEVICE_LOST`          |
| Warning | 异常但可恢复     | `DMA-BUF copy fence wait TIMED OUT`、`SendMouseClick SKIPPED` |
| Display | 关键状态变化（默认） | `CEF initialized`、`Browser created`                          |
| Verbose | 高频调试信息     | 鼠标事件、每帧纹理提交、FPS 计数                                           |

运行时调整日志级别（控制台命令）：

```
Log LogWebNative Verbose         # 开启最高详细度（含鼠标事件等所有日志）
Log LogWebNative Display         # 恢复默认详细度
Log LogWebNative Warning         # 仅显示警告和错误
```

`Verbose`

&#x20;

级别会输出的内容包括：

- `SendMouseMove` — 鼠标移动事件
- `SendMouseClick` — 鼠标点击事件
- `OnMouseButtonDown` — 鼠标按下路由
- `OnAcceleratedPaint` — 每 60 帧的渲染帧信息（Linux DMA-BUF / Windows）
- `SendExternalBeginFrame` — 外部帧同步调用

### DevTools 调试器

```cpp
// C++
WebView->ShowDevTools();     // 打开 DevTools
WebView->CloseDevTools();    // 关闭 DevTools
WebView->ToggleDevTools();   // 切换开关
```

***

## 高级功能

### 从 Web 拖拽或点击放置到 UE 场景

想加快游戏与三维交互应用开发，可以让 Web 负责资产库、道具栏与复杂工具面板，让 UE 专注实时三维和场景对象。典型流程如下：

1. 用户在 Web 页面拖拽或点击一个资源条目。
2. 页面通过 `WebNative.send()` 发送资源 ID 和放置命令。
3. UE 收到消息后调用 `SetFocusToGameViewport()`，把后续输入交给游戏视口。
4. 调用 `GetRawPlatformCursorPos()` 和 `DeprojectCursorToWorld()` 获取当前世界空间射线。
5. 项目执行射线检测、显示预览体，并在确认时创建 Actor。

```javascript
// 事件名称和业务字段由项目自行约定
WebNative.send("Placement.Begin", {
  assetId: "Prop.Chair.001",
  mode: "click"
});
```

公开蓝图/C++接口：

| 接口                                                            | 用途                 |
| ------------------------------------------------------------- | ------------------ |
| `SetFocusToGameViewport()`                                    | 将输入焦点切换到 UE 游戏视口   |
| `GetRawPlatformCursorPos(OutScreenPos)`                       | 获取当前平台光标屏幕坐标       |
| `DeprojectCursorToWorld(ScreenPos, OutWorldPos, OutWorldDir)` | 将屏幕坐标反投影为世界空间起点和方向 |

拖拽/点击只负责开始放置流程。资源白名单、UClass/Static Mesh 映射、碰撞、吸附、撤销、联网权限和最终生成规则必须由项目蓝图/C++决定，不要让不可信网页直接指定任意对象路径。

### 透明背景叠加层

用于将网页 UI 叠加在 3D 场景上：

```ini
[WebNative]
cef_args=show-background-color background-color=0x00000000
```

```cpp
// Widget 属性
bTransparentBackground = true;
```

### 视频/音频权限

支持完整的 WebRTC 媒体权限管理：

```ini
[WebNative]
media_permission_policy=allow          # allow | deny | prompt
permission_prompt_policy=allow
allow_microphone=true
allow_camera=true
allow_desktop_capture=true
allow_protected_media=true
```

### 鼠标透明穿透

网页透明区域的鼠标事件穿透到 UE 场景：

| 属性                              | 值     | 说明                 |
| ------------------------------- | ----- | ------------------ |
| bEnableMouseTransparency        | true  | 启用透明穿透             |
| MouseTransparencyAlphaThreshold | 0-255 | 透明度阈值，低于此值穿透       |
| MouseTransparencyMaskBlockSize  | 1-8   | 透明掩码块大小（性能 / 精度平衡） |

## 配置参考

所有配置项位于 `Config/DefaultGame.ini` 的 `[WebNative]` 节点下。以下列出插件读取的全部   35 个配置项  ，按功能分类说明。

> 配置优先级  ：打包后可在 `<Project>/Saved/Config/Windows/Game.ini`（或 `Linux/Game.ini`）中覆盖默认值。只需添加 `[WebNative]` 节点并写入要覆盖的键即可，未写入的键保持 `DefaultGame.ini` 的默认值。
>
> 示例  ：假设默认启用了性能监视器，打包后需要关闭：
>
> ```ini
> ; <Project>/Saved/Config/Windows/Game.ini
> [WebNative]
> show_cef_performance_monitor=false
> ```
>
> 这样就只覆盖了 `show_cef_performance_monitor`，其余 35 项仍使用 `DefaultGame.ini` 的默认值。

### 常规设置

| 配置键                            | 类型   | 默认值     | 说明                                                                                                                                                                                                                                                   |
| ------------------------------ | ---- | ------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `clear_cache`                  | bool | `false` | 程序关闭时清除 CEF 浏览器缓存（Cookie、LocalStorage 等）。在 CEF 已释放所有文件句柄后安全删除                                                                                                                                                                                        |
| `clear_log`                    | bool | `true`  | 程序关闭时清除 CEF 日志文件。在 CEF 已释放所有文件句柄后安全删除                                                                                                                                                                                                                |
| `offgpu`                       | bool | `false` | 禁用 GPU 加速渲染，强制使用 CPU 软渲染。仅在 GPU 不可用时开启                                                                                                                                                                                                               |
| `touch_events`                 | bool | `true`  | 启用触摸输入支持（移动端/触屏设备）                                                                                                                                                                                                                                   |
| `keyboard_f5`                  | bool | `false` | 允许 F5 键刷新网页                                                                                                                                                                                                                                          |
| `ctrl_scale`                   | bool | `false` | 允许 Ctrl + 鼠标滚轮缩放网页                                                                                                                                                                                                                                   |
| `gpu_shared_mutex_per_adapter` | bool | `false` | 按 GPU 适配器限制 shared\_texture 并发数（`true`：每物理 GPU 仅 1 个实例 GPU 加速，其余 CPU 降级；`false`：所有实例均可 GPU 加速，纯 D3D12 拷贝路径下已无跨设备冲突，，，推荐，， ，，`false`，，）                                                                                                               |
| `multi_open`                   | bool | `false` | 多实例多开模式：`false`（默认）单实例独占锁模式，检测到其他进程已持有锁时自动回退多开（每实例独立缓存/日志目录，避免 SQLite 文件锁冲突）；`true` 直接以多开模式运行，每实例使用独立缓存与日志目录。。。云渲染/云游戏场景。。：建议 `multi_open=true` 并配合 `clear_cache=true`、`clear_log=true` 使用——云渲染下每个客户端进程相互独立、一般不依赖浏览器缓存，多开实例各自使用独立缓存/日志目录，会话结束时自动清空即可 |
| `linux_single_process`         | bool | `false` | 仅 Linux：`true` 使用兼容性优先的单进程模式；`false`（默认）使用 Helper 多进程模式。CEF 初始化后不能动态切换，修改后需要重启程序                                                                                                                                                                     |

### 调试与性能

| 配置键                            | 类型   | 默认值    | 说明                                                                                    |
| ------------------------------ | ---- | ------ | ------------------------------------------------------------------------------------- |
| `show_cef_performance_monitor` | bool | `true` | 在浏览器左上角显示实时性能叠加层（FPS、内存、渲染模式）                                                         |
| `show_download_notification`   | bool | `true` | 显示内置下载进度条和完成/失败通知（白色 Material 风格 toast）。设为`false` 则仅广播 `WebNative` 下载事件，由开发者自行监听绘制 UI |
| `debugging_port_min`           | int  | `9223` | 远程 DevTools 调试端口范围最小值。设为 0 则禁用远程调试                                                    |
| `debugging_port_max`           | int  | `9262` | 远程 DevTools 调试端口范围最大值。插件会在此范围内选择首个可用端口。设定后可通过`http://localhost:<端口>` 访问 DevTools      |

### 媒体权限策略

| 配置键                        | 类型     | 可选值                         | 说明                  |
| -------------------------- | ------ | --------------------------- | ------------------- |
| `media_permission_policy`  | string | `allow` / `deny` / `prompt` | 媒体设备（摄像头/麦克风）全局权限策略 |
| `permission_prompt_policy` | string | `allow` / `deny` / `prompt` | 权限弹窗（通知/地理位置等）全局策略  |

### 单项权限开关（18 项）

以下配置键均为 `bool` 类型，`true` = 允许，`false` = 禁止。

| 配置键                              | 默认值     | 权限说明                             |
| -------------------------------- | ------- | -------------------------------- |
| `allow_microphone`               | `true`  | 麦克风访问                            |
| `allow_camera`                   | `true`  | 摄像头访问                            |
| `allow_desktop_capture`          | `true`  | 屏幕/窗口捕获（getDisplayMedia）         |
| `allow_clipboard`                | `true`  | 剪贴板读写                            |
| `allow_geolocation`              | `true`  | 地理位置                             |
| `allow_notifications`            | `true`  | 桌面通知                             |
| `allow_local_network_access`     | `true`  | 本地网络请求（局域网资源）                    |
| `allow_file_system_access`       | `true`  | 本地文件系统访问（File System Access API） |
| `allow_pointer_lock`             | `true`  | 鼠标指针锁定（Pointer Lock API，游戏用）     |
| `allow_keyboard_lock`            | `true`  | 键盘锁定（Keyboard Lock API）          |
| `allow_storage_access`           | `true`  | 第三方存储访问（Storage Access API）      |
| `allow_protected_media`          | `true`  | 受保护内容播放（EME/Widevine DRM）        |
| `allow_local_fonts`              | `true`  | 本地字体枚举（Local Font Access API）    |
| `allow_midi_sysex`               | `false` | MIDI System Exclusive 消息         |
| `allow_multiple_downloads`       | `true`  | 多文件并发下载                          |
| `allow_window_management`        | `true`  | 多屏幕/窗口管理（Window Management API）  |
| `allow_extended_reality`         | `false` | WebXR 扩展现实（VR/AR）                |
| `allow_other_permission_prompts` | `false` | 其他未分类权限弹窗                        |

### CEF 命令行参数

| 配置键        | 类型     | 说明                                                                                                                                                                                                                                                                          |
| ---------- | ------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `cefcore`  | string | CEF 核心进程参数（CEF Core Args），影响所有子进程。常用：`disable-web-security`、`no-proxy-server`、`allow-file-access-from-files`、`allow-universal-access-from-files`                                                                                                                            |
| `cef_args` | string | CEF 浏览器进程参数（CEF Extra Args），仅影响渲染进程。常用：`show-background-color`、`background-color=0x00000000`（透明背景）。。。站点隔离已默认禁用。。：插件内置已追加 `disable-features=SitePerProcess,IsolateOrigins,OutOfBlinkCors,...`，无需在 `cef_args` 中重复配置；若重复写 `disable-features` 会以最后值覆盖内置完整列表，导致嵌入式场景所需的其他禁用项重新启用 |

> 注意  ：`cefcore` 和 `cef_args` 的区别：
>
> - `cefcore` → CEF 核心命令行，所有 CEF 子进程（GPU、网络、渲染等）共用
> - `cef_args` → 仅传递给渲染进程（Renderer Process），如背景色、Feature Flag 等

### Linux 单进程/多进程配置

Linux 默认使用多进程模式（`linux_single_process=false`），隔离性和并行能力更好；国产 CPU/GPU 等兼容性优先的环境建议切换到单进程模式。客户可以在项目配置中选择：

```ini
[WebNative]
linux_single_process=true
```

| 配置值     | CEF 参数与行为                                                                                                       |
| ------- | --------------------------------------------------------------------------------------------------------------- |
| `true`  | 添加`--single-process`，并把 `NetworkService` 合并到唯一一条 `--disable-features` 参数中；适合国产 CPU/GPU 和兼容性优先的环境，退出时使用单进程兼容关闭流程 |
| `false` | 不添加`--single-process`，不禁用 `NetworkService`；Renderer、GPU、Network、Utility 等使用 CEF Helper 多进程运行，隔离性和并行能力更好         |

配置在 CEF 第一次初始化时读取，运行过程中不能切换。修改项目的
`DefaultGame.ini` 或打包后的 `Saved/Config/Linux/Game.ini` 后，需要完全退出并重启程序。
多进程模式依赖随插件打包的对应架构 `WebNativeBrowserHelper`。

> 国产化环境兼容保证  ：插件不会自行关闭或替换 `linux_single_process=true`。部分国产 CPU + GPU 环境需要让 `NetworkService` 与 CEF 在进程内协同运行，才能正常加载网络视频。由于上游 CEF 的 `--single-process` 诊断模式在 Linux 调用 `CefShutdown()` 时可能触发 `SIGTRAP`，插件只在 UE 已进入最终退出阶段、所有 CEF Browser 均已请求关闭后跳过该调用，并清理残留 Helper；浏览、视频播放、消息通道及运行期行为不受影响。多进程模式仍执行完整的 `CefShutdown()`。

为什么国产化环境建议使用单进程？

Chromium 144 默认将网络栈拆分为独立的 `NetworkService` 子进程，通过 Mojo IPC 与主进程通信。在国内 CPU（如飞腾、鲲鹏）+ 国产 GPU（如砺算）等硬件组合上，Mojo IPC 的 Unix domain socket / eventfd 机制可能卡死，导致后续 HTTP 请求全部 Pending，表现为网页图片加载不全、视频脚本加载失败等问题。

单进程配置会让 NetworkService 在进程内运行，绕过上述 IPC 通信。默认（`linux_single_process=false`）在验证过的 Intel/AMD
或服务器环境直接使用多进程；国产化硬件建议先切换为单进程模式（`linux_single_process=true`），
完成网页加载、视频播放、消息通道和长时间稳定性测试后再决定是否切换。

### 推荐配置示例

开发环境（调试全开）：

```ini
[WebNative]
clear_cache=true
clear_log=true
offgpu=false
multi_open=false
linux_single_process=false
touch_events=true
keyboard_f5=false
ctrl_scale=false
gpu_shared_mutex_per_adapter=false
show_cef_performance_monitor=true
show_download_notification=true
debugging_port_min=9223
debugging_port_max=9262
media_permission_policy=allow
permission_prompt_policy=allow
allow_microphone=true
allow_camera=true
allow_desktop_capture=true
allow_clipboard=true
allow_geolocation=true
allow_notifications=true
allow_local_network_access=true
allow_file_system_access=true
allow_pointer_lock=true
allow_keyboard_lock=true
allow_storage_access=true
allow_protected_media=true
allow_local_fonts=true
allow_midi_sysex=false
allow_multiple_downloads=true
allow_window_management=true
allow_extended_reality=false
allow_other_permission_prompts=false
cefcore=disable-web-security no-proxy-server allow-file-access-from-files allow-universal-access-from-files allow-running-insecure-content allow-insecure-localhost
cef_args=
```

生产环境（安全加固）：

```ini
[WebNative]
clear_cache=false
clear_log=true
offgpu=false
multi_open=false
linux_single_process=false
touch_events=true
keyboard_f5=false
ctrl_scale=false
gpu_shared_mutex_per_adapter=false
show_cef_performance_monitor=false
show_download_notification=true
debugging_port_min=0
debugging_port_max=0
media_permission_policy=allow
permission_prompt_policy=prompt
allow_microphone=true
allow_camera=true
allow_desktop_capture=false
allow_clipboard=true
allow_geolocation=true
allow_notifications=true
allow_local_network_access=true
allow_file_system_access=false
allow_pointer_lock=true
allow_keyboard_lock=false
allow_storage_access=true
allow_protected_media=true
allow_local_fonts=false
allow_midi_sysex=false
allow_multiple_downloads=true
allow_window_management=true
allow_extended_reality=false
allow_other_permission_prompts=false
cefcore=no-proxy-server
cef_args=
```

云渲染（云游戏）多开：

云渲染/云游戏场景下，每个客户端进程都应相互独立、一般不依赖浏览器缓存。建议启用 `multi_open=true`，并配合 `clear_cache=true`、`clear_log=true` 在会话结束后清空各自缓存与日志；其余安全项按上方"生产环境（安全加固）"配置：

```ini
[WebNative]
multi_open=true
clear_cache=true
clear_log=true
offgpu=false
linux_single_process=false
touch_events=true
keyboard_f5=false
ctrl_scale=false
gpu_shared_mutex_per_adapter=false
show_cef_performance_monitor=false
show_download_notification=true
debugging_port_min=0
debugging_port_max=0
media_permission_policy=allow
permission_prompt_policy=prompt
allow_microphone=true
allow_camera=true
allow_desktop_capture=false
allow_clipboard=true
allow_geolocation=true
allow_notifications=true
allow_local_network_access=true
allow_file_system_access=false
allow_pointer_lock=true
allow_keyboard_lock=false
allow_storage_access=true
allow_protected_media=true
allow_local_fonts=false
allow_midi_sysex=false
allow_multiple_downloads=true
allow_window_management=true
allow_extended_reality=false
allow_other_permission_prompts=false
cefcore=no-proxy-server
cef_args=
```

***

## 技术规格

| 项目     | 说明                                        |
| ------ | ----------------------------------------- |
| 引擎版本   | Unreal Engine 5.1-UE5.8                   |
| CEF 版本 | Chromium 144 (CEF 131)                    |
| 支持平台   | Windows 10+, Linux (Vulkan, GLIBC ≥ 2.17) |
| 渲染后端   | D3D11/D3D12 (Windows), Vulkan (Linux)     |
| 最大帧率   | 120 FP                                    |
| C++ 标准 | C++17                                     |

### Linux 发行版兼容性

> 最低要求：GLIBC 2.17  。低于此版本将无法启动，报 `GLIBC_X.XX not found` 错误。

| 发行版                        | GLIBC | 兼容状态 | 备注                          |
| -------------------------- | ----- | ---- | --------------------------- |
| Ubuntu 22.04 / 24.04       | 2.35+ | ✅ 支持 | <br />                      |
| Ubuntu 20.04               | 2.31  | ✅ 支持 | <br />                      |
| Debian 11 (Bullseye)       | 2.31  | ✅ 支持 | <br />                      |
| Debian 12 (Bookworm)       | 2.36  | ✅ 支持 | <br />                      |
| CentOS Stream 9 / RHEL 9   | 2.34  | ✅ 支持 | <br />                      |
| CentOS 8 / RHEL 8          | 2.28  | ✅ 支持 | 已 EOL，建议升级                  |
| 麒麟 V10 SP1 (入门版/基础版)       | 2.28  | ✅ 支持 | x86\_64 版本，需确认 GLIBC ≥ 2.28 |
| 麒麟 V10 SP1 (2503/增强版)      | 2.31  | ✅ 支持 | x86\_64 版本                  |
| UOS Server 20 (A版/Debian系) | 2.31  | ✅ 支持 | 内核 5.x 版本                   |
| UOS Server 20 (E版/欧拉版)     | 2.28  | ✅ 支持 | x86\_64 版本                  |
| CentOS 7 / RHEL 7          | 2.17  | ✅ 支持 | 最低要求版本，已 EOL                |

> 验证说明  ：2026-07-24 通过 `readelf -V` 在 GLIBC 2.28 环境实测确认，二进制仅依赖 GLIBC 2.17（`libc.so.6` 最高版本符号为 `GLIBC_2.17`）。

***

## 常见问题

Q: 透明背景已设置，但点击仍然有概率被阻挡无法穿透到 UE 场景？

A: CEF 中透明穿透有三个常见陷阱，按以下规则设置 CSS 即可避免：

1. 不要用全屏     `<div>`     做视觉效果  （如闪屏）。用 `body` 伪元素替代，只覆盖需要的区域：

```css
/* 错误 — 全屏 div 阻挡点击 */
.flash { position:fixed; inset:0; }

/* 正确 — 伪元素只覆盖两侧 */
body.flash::before, body.flash::after {
  content:''; position:fixed; top:0; bottom:0; width:60px; pointer-events:none;
}
```

1. `backdrop-filter`     必须显式加     `pointer-events:none`  ，且透明度为 0 时设为 `none`（不是 `blur(0px)`）：

```css
.overlay-bg {
  backdrop-filter: blur(10px);
  pointer-events: none;  /* 必须显式声明 */
}
```

```js
bg.style.backdropFilter = (alpha > 0) ? `blur(${px}px)` : 'none';
```

1. 全屏遮罩容器设     `pointer-events:none`  ，只给需要交互的子元素设 `pointer-events:auto`：

```css
.overlay-panel { pointer-events: none; }   /* 全屏不拦截 */
.panel-card    { pointer-events: auto; }   /* 卡片可交互 */
```

原则

：少创建全屏 DOM 元素，每层都显式声明 `pointer-events`，`backdrop-filter` 不用就关掉。

Q: 网页无法正确渲染？

A: 确保 `bUseGpuAcceleratedRendering = true`，并检查 CEF 初始化日志 `LogWebNative`。

Q: 如何查看 CEF 自身版本和日志？

A: CEF 日志在 `Saved/Logs/cef/cef.log`，也可通过 `ShowDevTools()` 打开浏览器控制台查看。

Q: JS 消息延迟多少？

A: 单条消息 <1ms（进程内 IPC）。批量发送延迟如下：

| 消息数       | 耗时       |
| --------- | -------- |
| <br />    | <br />   |
| 10 条      | \~5 ms   |
| 100 条     | \~5 ms   |
| 1,000 条   | \~6 ms   |
| 10,000 条  | \~30 ms  |
| 100,000 条 | \~220 ms |

Q: Linux 下长时间运行内存（RSS）持续增长怎么办？

A: 这是 UE5.x Linux 引擎的已知行为，与 插件无关。在 Linux 上，UE5 的 `FMallocBinned2` 使用 `FPooledVirtualMemoryAllocator` 管理内存池，默认配置下 `madvise(MADV_DONTNEED)` 从不调用（`GMemoryRangeDecommitIsNoOp=true`），导致 free 后的物理页不归还 OS。8MB 池在碎片化后几乎不会完全清空，RSS 只增不减。

解决方案（降低 70-78% 增长）：

在启动脚本中添加 `-vmapoolevict -vmapoolscale=1.0` 参数：

```sh
#!/bin/sh
UE_TRUE_SCRIPT_NAME=$(echo "$0" | xargs readlink -f)
UE_PROJECT_ROOT=$(dirname "$UE_TRUE_SCRIPT_NAME")
chmod +x "$UE_PROJECT_ROOT/YourProject/Binaries/Linux/YourProject"
exec "$UE_PROJECT_ROOT/YourProject/Binaries/Linux/YourProject" YourProject \
    -vmapoolevict -vmapoolscale=1.0 "$@"
```

| 参数                  | 作用                                                     |
| ------------------- | ------------------------------------------------------ |
| `-vmapoolevict`     | 启用 decommit，free 时调用`madvise(MADV_DONTNEED)` 归还物理页给 OS |
| `-vmapoolscale=1.0` | 阻止内存池指数增长（默认 Editor 为 1.4）                             |

效果对比

（EmptyProject 12 分钟测试）：

| 指标           | 不加参数        | 加参数        | 改善    |
| ------------ | ----------- | ---------- | ----- |
| 8MB anon 增长率 | 1.5/min     | 0.45/min   | ↓ 70% |
| RSS 增长率      | 13.2 MB/min | 2.9 MB/min | ↓ 78% |

> 注意  ：这些参数会影响 free 性能（每次 free 多一次系统调用），但实测对帧率影响可忽略不计。`FMemory::Trim()` 和 `r.Vulkan.*` cvar 对 Linux 池内存释放无效。

Q: 部分国产 Linux 系统（如银河麒麟）Dev 开发包无法播放视频或硬件解码失效？

A: 这是 UE Development 构建的已知限制，Shipping 包不受影响。

原因：

&#x20;UE Development 构建会安装信号处理器（用于崩溃报告），这些处理器会被 fork 出的 CEF Helper 子进程继承，导致 GPU 进程启动异常，硬件视频解码失效。

| 构建配置     | linux\_single\_process | 视频/硬件解码                |
| -------- | ---------------------- | ---------------------- |
| Shipping | `false`（默认）            | ✅ 正常（多进程 + GPU 硬件解码）   |
| Dev      | `false`                | ❌ 可能失效（GPU 进程被信号处理器干扰） |
| Dev      | `true`                 | ⚠️ 单进程软件渲染（可播放但无硬件加速）  |

解决方案（优先级排序）：

1. 优先使用 Shipping 包   — 硬件解码完全正常，体验最佳
2. 必须用 Dev 包时  ，修改配置为单进程模式：

```ini
[WebNative]
linux_single_process=true
```

> Shipping 包默认多进程（`linux_single_process=false`），所有 GPU 硬件解码功能正常，无需修改。

