# WebNative Browser Plugin

> **中文文档（Chinese）：[README.md](./README.md)**

WebNativeBrowser is a high-performance, enterprise-grade, cross-platform Web UI and Chromium browser solution for Unreal Engine 5, providing a native browser experience on Windows and Linux (x86_64, ARM64). Linux requires a minimum of **GLIBC 2.17**. See [Technical Specifications → Linux Distribution Compatibility](#linux-distribution-compatibility).

> **Project homepage & source repository**: <https://github.com/starTechnology1994/uewebbrowser>
>
> - Prebuilt plugin downloads: <https://github.com/starTechnology1994/uewebbrowser/releases>
> - Documentation & Wiki: <https://github.com/starTechnology1994/uewebbrowser/wiki>
> - Bilibili video tutorials: <https://space.bilibili.com/3546688536971381>
> - Issue tracker: <https://github.com/starTechnology1994/uewebbrowser/issues>
> - Business contact (licensing, partnership, technical support): **startechnology1994@163.com**
> - WeChat Work: <https://work.weixin.qq.com/ca/cawcdef9a4d05fef8c>
>
> The closed-source release (Fab) is intended for licensed users; the binaries are kept consistent with the public repository, which is used only for publicly available versions and documentation.

---

## Core Features

### Four Solutions for Rapid Development

| Direction                   | Web-side Capabilities                        | UE-side Capabilities                  | Deliverables                         |
| --------------------------- | -------------------------------------------- | ------------------------------------- | ------------------------------------ |
| **Digital Twins**           | Device tree, alerts, work orders, reports, GIS and business workflows | Campus, production line, buildings, equipment and real-time status | A visual, searchable, controllable 3D digital world |
| **Games & Runtime Tools**   | Item libraries, stores, event pages, quest panels and editor tools | Game world, Actors, gameplay and authoritative logic | Rapidly iterated game UI and scene tools |
| **AI Application UI**       | AI assistants, knowledge bases, generative pages and result display | 3D characters, scene feedback and business actions | AI + real-time 3D fusion experience  |
| **Dashboards & Data Screens** | Charts, tables, maps, filters and responsive layouts | 3D situational awareness, object states and spatial expression | Data + 3D linked command cockpit     |

WebNativeBrowser is especially suited to digital twins: let mature web technology carry data and business systems, let Unreal Engine focus on real-time 3D scenes, and use JS ↔ UE messages to drive device selection, camera positioning, status updates, and scene control.

> The AI direction refers to hosting AI application UI, reusing AI-assisted generated front-end assets, and connecting them to the UE scene; the plugin itself does not bundle a large language model or third-party inference services.

### High-Performance GPU-Accelerated Rendering

- Cross-process texture transfer based on GPU shared memory; frames go directly into the UE5 rendering pipeline with zero CPU copy overhead
- Adaptive multi-rendering backends: automatically selects the optimal GPU acceleration scheme per platform
- Persistent texture reuse; zero extra VRAM allocation per rendered frame

### Smart Frame Rate Management

- **Zero cost on static frames**: rendering pauses automatically when the page is idle, with no extra GPU/CPU consumption
- **On-demand rendering for dynamic content**: animations, scrolling, and similar content wake rendering in real time for smooth response
- **Adaptive frame rate for video playback**: automatically matches the video frame rate, avoiding wasted re-compositing

### Cross-Platform

| Platform | Status    |
| -------- | --------- |
| Windows  | Stable    |
| Linux    | Stable    |
| macOS    | Planned   |

### Enterprise Multi-Instance & Pixel Streaming

- Create multiple WebNative Browser widgets in the same UE application for multi-panel, multi-screen, and multi-window scenarios
- Launch multiple independent instances of the same packaged application; actual concurrency depends on page content, video, resolution, and hardware resources
- Can be used as part of the final UE output together with Unreal Engine Pixel Streaming
- Remote keyboard, mouse, touch, and focus in Pixel Streaming follow the project's input configuration
- Remote user local file upload should be handled by the Pixel Streaming frontend and project services; it is not equivalent to the render server's local file picker

### Linux Production Readiness

- Linux x86_64 and ARM64 dual architecture
- Chinese IME, clipboard, keyboard, mouse, and focus interaction
- Runtime/Shipping file picker, upload, and download
- Configurable single-process and multi-process modes for different hardware and deployment environments
- Verified paths for domestic CPUs/GPUs, Kylin, and UOS environments
- Dedicated adaptation completed for Lisca and Moore Threads GPU environments; specific GPU models, drivers, and OS combinations are subject to the release compatibility matrix
- Coverage of multiple browser widgets, multi-instance applications, video, messaging, and shutdown lifecycle

### Native Browser Experience

- Full Chromium engine covering WebRTC, WebGL, MediaSource, Canvas, and other mainstream modern web capabilities
- 4K video and up to 8K application scenarios supported; actual results depend on encoding, page content, GPU, drivers, and output resolution
- Transparent background support (UI overlay scenarios)
- Full keyboard / mouse / touch input support
- Mouse transparent hit-through (configurable alpha threshold)
- Built-in DevTools remote debugger
- Permission management (18 permission policies including camera, microphone, clipboard, notifications, etc.)
- Global alert/confirm/prompt injection (Google-style white dialogs, applied automatically to all web pages)
- File picker (`<input type="file">`; native Windows dialog / Linux Runtime Slate dialog)
- File downloader (system save dialog)
- Page loading placeholder animation (rotating loader shown until the first frame arrives)

### UE-Blueprint Bidirectional Communication

- **UE → JS**: execute arbitrary JavaScript; JSON message bridging
- **JS → UE**: JS sends messages, UE receives them via the `OnMessageReceived` delegate
- **Event-driven**: JS subscribes by function name using `on()` / `off()`
- Supports C++ delegates and Blueprint dynamic delegates; messages are batched for performance

### Built-in JSON Function Library (Out of the Box)

- Built-in C++ JSON Blueprint function library, **ready out of the box** — no third-party JSON plugin (e.g. JsonBlueprintUtilities) required
- Powered by the engine's native Json / JsonUtilities modules, available on Win64 / Linux / LinuxArm64
- Dynamically build, read, and modify nested JSON objects and arrays of any depth (including object arrays) **without pre-defining structs**
- Full operation chain: `Create Json Object` / `Load Json From String` / `Json Object To String` / `Get/Set Json fields and arrays` / `Has Json Field` / `Get Json Field Names` / `Remove Json Field`
- Measured performance: ~0.06 µs per single field read, ~2 µs per deserialize (engine-side built-in Json backend, no per-call allocation overhead)

### Navigation Controls

| Blueprint Function | Description                          |
| ------------------ | ------------------------------------ |
| `LoadURL`          | Load the specified URL               |
| `GoBack`           | Go back to the previous page         |
| `GoForward`        | Go forward to the next page          |
| `Reload`           | Reload the current page (optionally ignore cache) |

### Input Enhancements

| Property             | Description                                                                                         |
| -------------------- | --------------------------------------------------------------------------------------------------- |
| `bForwardUEKeyEvents` | When enabled, keyboard events are also forwarded to CEF while focus is in the UE scene (for double-processing scenarios such as undo/redo) |

### Web-to-UE Scene Placement

- Web pages can act as item libraries, asset libraries, building catalogs, device lists, or runtime toolbars
- Drag-and-drop workflow for placing assets from the web into the UE scene
- Click a web entry to switch to the UE game viewport, then click to place in the scene
- Blueprints can directly call `SetFocusToGameViewport`, `GetRawPlatformCursorPos`, and `DeprojectCursorToWorld`
- Projects can freely combine raycasting, preview volumes, snapping, collision, permission, and Actor creation rules

> WebNativeBrowser handles the message, focus, and cursor-space coordination between Web and UE; final UObject/Actor operations should be executed by the project on the UE game thread, and resource IDs and business parameters from the web page must be validated.

---

## Quick Start

### Getting the Plugin

There are two ways to obtain the plugin; choose either one.

#### Option 1: Download a Prebuilt Release (Recommended)

1. Open the [Releases page](https://github.com/starTechnology1994/uewebbrowser/releases)
2. Download the archive matching your engine version (e.g. `WebNativeBrowser-UE5.1.zip`)
3. Extract it to get the `WebNativeBrowser` folder

#### Option 2: Clone the Source Repository with Git LFS

The plugin contains large CEF files (hundreds of MB) and must be fetched via Git LFS:

```bash
# 1. Install Git LFS (first time only)
git lfs install

# 2. Clone the repository (pick the branch for your engine version, UE5.1 → UE51_WebNative)
git clone -b UE51_WebNative https://github.com/starTechnology1994/uewebbrowser.git

# 3. If large files are still missing after cloning, pull them explicitly
git lfs pull
```

> Branch mapping: UE5.1 → `UE51_WebNative`, UE5.2 → `UE52_WebNative`, …, UE5.8 → `UE58_WebNative`, `main` corresponds to UE5.8.

### Installation

1. Place the `WebNativeBrowser` folder into the project's `Plugins/` directory
2. Start the engine and enable the plugin (Edit → Plugins → search "WebNative Browser")
3. Drag in a **WebNative Browser** widget from the UI widget library
4. Set `InitialURL` to load a web page

### Licensing

For commercial licensing, see [13-Licensing](https://github.com/starTechnology1994/uewebbrowser/wiki/13-Licensing).

---

## JS ↔ UE Bidirectional Communication

The plugin implements bidirectional communication between UE and JS through a `functionName` + `messageBody` message channel.

### JS-side API

The plugin automatically injects the global object `window.WebNative` with the following methods:

```javascript
// ========== Send a message to UE ==========
WebNative.send("FunctionName", "MessageBody");
WebNative.send("FunctionName", { score: 100, player: "Player1" });

// ========== Listen for messages from UE ==========

// via on/off (subscribe by FunctionName)
function handleMessage(body) {
    console.log("Received:", body);
}
WebNative.on("EventName", handleMessage);
WebNative.off("EventName", handleMessage);
```

### UE-side API

**Send a message to JS:**

```cpp
// C++ — send a message to JS
WebView->SendMessageToJS(TEXT("OnGameScore"), TEXT(R"({"score": 9999, "level": 42})"));

// Blueprint — use the SendMessageToJS node
//   FunctionName: "OnPlayerData"
//   MessageBody:  '{"name":"Player1","hp":100}'
```

**Receive messages from JS:**

```cpp
// C++ — bind the delegate
WebView->OnMessageReceived.AddDynamic(this, &UMyWidget::OnWebViewMessage);

void UMyWidget::OnWebViewMessage(const FString& FunctionName, const FString& MessageBody)
{
    if (FunctionName == TEXT("OnLogin"))
    {
        // Parse JSON
        TSharedPtr<FJsonObject> JsonObj;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(MessageBody);
        FJsonSerializer::Deserialize(Reader, JsonObj);

        FString Username = JsonObj->GetStringField(TEXT("username"));
        UE_LOG(LogTemp, Log, TEXT("User logged in: %s"), *Username);
    }
}
```

**Blueprint:** Bind the `OnMessageReceived` event in the Details panel; `FunctionName` and `MessageBody` are passed as parameters.

### Message Type Compatibility

#### JS → UE (`WebNative.send()`)

The `messageBody` parameter of `WebNative.send(functionName, messageBody)` supports the following types:

| Type                     | Example                            | JS-side handling           | UE-side receives                             |
| ------------------------ | ---------------------------------- | -------------------------- | -------------------------------------------- |
| JS object                | `{score: 100, name: "Player1"}`    | Automatic `JSON.stringify()` | JSON string `'{"score":100,"name":"Player1"}'` |
| String                   | `"hello"`                          | Passed through             | Raw string `"hello"`                         |
| Number                   | `42`                               | `String(42)`                | String `"42"`                                |
| Boolean                  | `true`                             | `String(true)`              | String `"true"`                              |
| `null` / `undefined`     | —                                  | Converted to empty string   | Empty string `""`                            |

> **Recommended usage**: pass a JS object directly; the plugin handles JSON serialization automatically. Parse it on the UE side with `FJsonSerializer`.

```javascript
// Recommended: pass an object directly
WebNative.send("OnPlayerScore", { score: 9999, combo: 42 });

// Also possible: pass a JSON string
WebNative.send("OnPlayerScore", JSON.stringify({ score: 9999, combo: 42 }));

// Simple scenarios: pass plain text
WebNative.send("OnChat", "The team is ready");
```

#### UE → JS (`SendMessageToJS`)

The UE side sends a `FString` `MessageBody`. The JS callback always receives the raw string; the plugin never calls `JSON.parse()` on behalf of the business code:

| UE sends              | JS `WebNative.on()` receives |
| --------------------- | ---------------------------- |
| Valid JSON string     | Raw JSON string              |
| Plain text string     | Raw string                   |
| `"10"`                | String `"10"`                |
| Empty string          | Empty string `""`            |

```cpp
// UE side: send JSON
WebView->SendMessageToJS(TEXT("OnGameData"), TEXT(R"({"players":32,"map":"Dust2"})"));
// JS callback receives the raw string: '{"players":32,"map":"Dust2"}'

// UE side: send plain text
WebView->SendMessageToJS(TEXT("OnTips"), TEXT("A new challenger has appeared!"));
// JS callback receives the string: "A new challenger has appeared!"

// UE side: send a number
WebView->SendMessageToJS(TEXT("OnCountdown"), TEXT("10"));
// JS callback receives the string: "10"
```

```javascript
WebNative.on("OnGameData", function(messageBody) {
    // Only parse manually when the business knows for sure this message is JSON.
    const gameData = JSON.parse(messageBody);
    console.log(gameData.players);
});
```

### Complete Example: Web Login

**Web side (login.html):**

```html
<!DOCTYPE html>
<html>
<head><meta charset="utf-8"><title>Login</title></head>
<body>
  <input id="username" type="text" placeholder="Username">
  <input id="password" type="password" placeholder="Password">
  <button onclick="doLogin()">Login</button>
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

    // Listen for the login result from UE
    WebNative.on('LoginResult', function(body) {
      document.getElementById('status').innerText =
        body.success ? 'Login success! ' + body.message : 'Login failed: ' + body.message;
    });
  </script>
</body>
</html>
```

**UE side:**

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

        // Send the result back to the web page
        FString ResultJson = FString::Printf(
            TEXT(R"({"success":%s,"message":"%s"})"),
            bSuccess ? TEXT("true") : TEXT("false"),
            bSuccess ? TEXT("Welcome back!") : TEXT("Incorrect username or password")
        );
        WebView->SendMessageToJS(TEXT("LoginResult"), ResultJson);
    }
}
```

---

## File Downloads

The plugin has a built-in CEF native download flow supporting Windows and Linux. When a user clicks a download link on a web page (`<a download>`, `blob:` URLs, HTTP downloads, etc.):

1. A save dialog appears (native Windows dialog / plugin-provided Runtime Slate dialog on Linux)
2. CEF starts the download and injects `WebNative` download events in real time
3. An optional built-in download progress bar and completion notification toast (white Material style) can be shown

### Built-in UI Switch

Control whether the built-in progress bar/notifications are shown via config (events are always broadcast regardless of this switch):

```ini
[WebNative]
show_download_notification=true   ; default: show built-in UI
; show_download_notification=false ; hide built-in UI, only broadcast events; developers draw their own UI
```

### JS Listening to Download Events

Regardless of `show_download_notification`, the following events are always broadcast via `window.WebNative.emit()`, so web pages can subscribe to build custom UI:

```javascript
// Download progress (fires once per integer percentage point)
WebNative.on('webNativeDownloadProgress', function(body) {
    const data = JSON.parse(body);
    console.log(`Downloading: ${data.filename} ${data.percent}% (${data.received}/${data.total})`);
    // data: { filename, received, total, percent }
});

// Download complete
WebNative.on('webNativeDownloadComplete', function(body) {
    const data = JSON.parse(body);
    console.log(`Complete: ${data.filename} size: ${data.size} path: ${data.path}`);
    // data: { filename, path, size }
});

// Download failed/cancelled
WebNative.on('webNativeDownloadFailed', function(body) {
    const data = JSON.parse(body);
    console.log(`Failed: ${data.filename}`);
    // data: { filename }
});
```

### Event Data Format

| Event                         | Field        | Type   | Description                              |
| ----------------------------- | ------------ | ------ | ---------------------------------------- |
| `webNativeDownloadProgress`   | `filename`   | string | Download file name                       |
|                               | `received`   | number | Bytes received                           |
|                               | `total`      | number | Total bytes (0 when unknown)             |
|                               | `percent`    | number | Progress percentage (0-100)              |
| `webNativeDownloadComplete`   | `filename`   | string | Download file name                       |
|                               | `path`       | string | Absolute save path (forward-slash format) |
|                               | `size`       | number | Downloaded bytes                         |
| `webNativeDownloadFailed`     | `filename`   | string | Download file name                       |

### Platform Differences

| Platform | Save dialog                        | Default directory   |
| -------- | ---------------------------------- | ------------------- |
| Windows  | CEF/Win32 native dialog            | `<Project>/Downloads/` |
| Linux    | Plugin-provided Runtime Slate dialog | `<Project>/Downloads/` |

The Linux dialog module only depends on Runtime Slate — not on `DesktopPlatform`, `SlateFileDialogs`, or `DirectoryWatcher` — so it can be included in Linux Shipping packages. Results return to the CEF UI thread and continue through Chromium's standard file authorization/download flow.

> **Headless note**: a standalone Slate window still requires a usable local windowing and input environment.
> "Remote user local file selection" in pure headless or Pixel Streaming is a different problem; the latter requires a browser-side upload protocol, and the dialog does not map the server file system to the remote client.

---

## Debugging & Logs

### CEF Performance Monitor

Three ways to enable it:

**1. Widget property:**
Select `UWebNativeBrowserWidget` in UMG and check the following in the Details panel:

```
CEF | Rendering → Show Cef Performance Monitor
```

**2. ini config ([DefaultGame.ini](file:Config/DefaultGame.ini)):**

```ini
[WebNative]
show_cef_performance_monitor=true
```

**3. Blueprint:**
Call the `ExecuteJavaScript` node with:

```javascript
"WebNativePerf && WebNativePerf.show();"
```

Once enabled:

A custom Slate performance overlay appears in the top-left corner (semi-transparent black background, green text) showing the following real-time metrics:

| Metric | Description                                                                                                                              |
| ------ | ---------------------------------------------------------------------------------------------------------------------------------------- |
| CEF FPS | The actual frame rate produced by the CEF compositor (sliding-window average based on the `OnAcceleratedPaint` callback count) |
| Frames | Cumulative composited frames since the browser was created                                                                                |
| View   | Current CEF rendering viewport resolution (pixels)                                                                                        |
| Mem    | Physical memory currently used by the UE process (MB), including CEF child process overhead                                               |
| Accel  | Rendering acceleration mode: `SharedTex` (Windows D3D11 shared texture), `DMA-BUF` (Linux Vulkan zero-copy), `CPU` (software render fallback) |

> **Note**: CEF FPS is the full-page compositing rate, not the video frame rate. Video playback is handled independently by the GPU internal decode pipeline and is not rate-limited.

### Log Files

The plugin's UE_LOG output (the `LogWebNative` category) is automatically written to dedicated log files:

```
<Project>/Saved/Logs/cef/WebNativeBrowser.log          # plugin log
<Project>/Saved/Logs/cef/cef.log                    # CEF Chromium log (if any)
```

**Supported log verbosity levels:**

| Level    | Description                        | Example                                                          |
| -------- | ---------------------------------- | ---------------------------------------------------------------- |
| Error    | Failures that require attention    | `CopyDmaBufToTexture FAILED`, `VK_ERROR_DEVICE_LOST`             |
| Warning  | Abnormal but recoverable           | `DMA-BUF copy fence wait TIMED OUT`, `SendMouseClick SKIPPED`    |
| Display  | Key state changes (default)        | `CEF initialized`, `Browser created`                             |
| Verbose  | High-frequency debug information   | Mouse events, per-frame texture submissions, FPS counting        |

**Change the log level at runtime (console commands):**

```
Log LogWebNative Verbose         # highest verbosity (all logs including mouse events)
Log LogWebNative Display         # restore default verbosity
Log LogWebNative Warning         # warnings and errors only
```

**Output included at the `Verbose` level:**

- `SendMouseMove` — mouse move events
- `SendMouseClick` — mouse click events
- `OnMouseButtonDown` — mouse button-down routing
- `OnAcceleratedPaint` — render frame info every 60 frames (Linux DMA-BUF / Windows)
- `SendExternalBeginFrame` — external frame sync calls

### DevTools Debugger

```cpp
// C++
WebView->ShowDevTools();     // open DevTools
WebView->CloseDevTools();    // close DevTools
WebView->ToggleDevTools();   // toggle
```

---

## Advanced Features

### Drag or Click-to-Place from Web to the UE Scene

To speed up game and 3D interactive application development, let the web handle asset libraries, item bars, and complex tool panels while UE focuses on real-time 3D and scene objects. The typical flow:

1. The user drags or clicks an asset entry on the web page.
2. The page sends the asset ID and placement command via `WebNative.send()`.
3. On receiving the message, UE calls `SetFocusToGameViewport()` to hand subsequent input to the game viewport.
4. Calls `GetRawPlatformCursorPos()` and `DeprojectCursorToWorld()` to obtain the current world-space ray.
5. The project performs raycasting, displays a preview volume, and creates the Actor on confirmation.

```javascript
// Event names and business fields are agreed upon by the project
WebNative.send("Placement.Begin", {
  assetId: "Prop.Chair.001",
  mode: "click"
});
```

Public Blueprint/C++ interfaces:

| Interface                                                       | Purpose                                              |
| --------------------------------------------------------------- | ---------------------------------------------------- |
| `SetFocusToGameViewport()`                                      | Switch input focus to the UE game viewport           |
| `GetRawPlatformCursorPos(OutScreenPos)`                         | Get the current platform cursor screen coordinates   |
| `DeprojectCursorToWorld(ScreenPos, OutWorldPos, OutWorldDir)`   | Deproject screen coordinates to a world-space origin and direction |

Drag/click only starts the placement flow. Asset whitelists, UClass/Static Mesh mapping, collision, snapping, undo, network permissions, and final spawning rules must be decided by the project's Blueprints/C++; never let untrusted web pages specify arbitrary object paths.

### Transparent Background Overlay

For overlaying web UI on top of 3D scenes:

```ini
[WebNative]
cef_args=show-background-color background-color=0x00000000
```

```cpp
// Widget property
bTransparentBackground = true;
```

### Video/Audio Permissions

Full WebRTC media permission management:

```ini
[WebNative]
media_permission_policy=allow          # allow | deny | prompt
permission_prompt_policy=allow
allow_microphone=true
allow_camera=true
allow_desktop_capture=true
allow_protected_media=true
```

### Mouse Transparent Hit-Through

Mouse events over transparent areas of the web page pass through to the UE scene:

| Property                           | Value | Description                            |
| ---------------------------------- | ----- | -------------------------------------- |
| bEnableMouseTransparency           | true  | Enable transparent hit-through         |
| MouseTransparencyAlphaThreshold    | 0-255 | Pixels with Alpha less than or equal to this value pass through |
| MouseTransparencyMaskBlockSize     | 1-16  | Transparent mask block size (performance / precision trade-off) |

#### Transparent Scene Primitive Event Bridge (Optional)

| Property | Value | Description |
| ---------------------------------- | ----- | -------------------------------------- |
| `Use 3D Widget Component Mode`     | false | Enable when the WebView is hosted by a world-space UWidgetComponent; pointer routing is handed to UE's 3D hit testing |
| `Enable Transparent Scene Primitive Events` | false | Bridges Begin/End Cursor Over, Clicked and Released of scene Actors/UPrimitiveComponents at transparent pixels of the fullscreen WebUI (explicitly enable it via `SetTransparentScenePrimitiveEventsEnabled(true)`) |

## Configuration Reference

All configuration items live in the `[WebNative]` section of `Config/DefaultGame.ini`. The following lists all **35 configuration items** the plugin reads, grouped by category.

> **Configuration priority**: after packaging, defaults can be overridden in `<Project>/Saved/Config/Windows/Game.ini` (or `Linux/Game.ini`). Just add a `[WebNative]` section with the keys you want to override; keys that are not written keep the `DefaultGame.ini` defaults.
>
> **Example**: suppose the performance monitor is enabled by default and you want to disable it in a packaged build:
>
> ```ini
> ; <Project>/Saved/Config/Windows/Game.ini
> [WebNative]
> show_cef_performance_monitor=false
> ```
>
> This only overrides `show_cef_performance_monitor`; the other 35 items still use the `DefaultGame.ini` defaults.

### General Settings

| Config Key                        | Type | Default   | Description                                                                                                                                                                                                                                                                                                                                                                                           |
| --------------------------------- | ---- | --------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `clear_cache`                     | bool | `false`   | Clears CEF browser cache (cookies, LocalStorage, etc.) on application exit. Deleted safely after CEF has released all file handles                                                                                                                                                                                                                                                                    |
| `clear_log`                       | bool | `true`    | Clears CEF log files on application exit. Deleted safely after CEF has released all file handles                                                                                                                                                                                                                                                                                                      |
| `offgpu`                          | bool | `false`   | Disables GPU-accelerated rendering and forces CPU software rendering. Enable only when GPU is unavailable                                                                                                                                                                                                                                                                                              |
| `touch_events`                    | bool | `true`    | Enables touch input support (mobile/touch devices)                                                                                                                                                                                                                                                                                                                                                    |
| `keyboard_f5`                     | bool | `false`   | Allows F5 to refresh the web page                                                                                                                                                                                                                                                                                                                                                                     |
| `ctrl_scale`                      | bool | `false`   | Allows Ctrl + mouse wheel to zoom the web page                                                                                                                                                                                                                                                                                                                                                        |
| `gpu_shared_mutex_per_adapter`    | bool | `false`   | Limits shared_texture concurrency per GPU adapter (`true`: only 1 instance is GPU-accelerated per physical GPU, the rest fall back to CPU; `false`: all instances can use GPU acceleration; with the pure D3D12 copy path there is no cross-device conflict, **`false` is recommended**)                                                                                                      |
| `multi_open`                      | bool | `false`   | Multi-instance mode: `false` (default) single-instance exclusive-lock mode; when another process already holds the lock it automatically falls back to multi-instance (each instance uses its own cache/log directory to avoid SQLite file-lock conflicts). `true` runs directly in multi-instance mode with independent cache and log directories per instance. **Cloud rendering / cloud gaming**: `multi_open=true` together with `clear_cache=true` and `clear_log=true` is recommended — under cloud rendering each client process is independent and generally does not rely on browser cache; each instance uses its own cache/log directory and clears them at session end |
| `linux_single_process`            | bool | `false`   | Linux only: `true` uses a compatibility-first single-process mode; `false` (default) uses the Helper multi-process mode. Cannot be switched at runtime after CEF initialization; a restart is required after changing it                                                                                                                                                                             |

### Debugging & Performance

| Config Key                          | Type | Default  | Description                                                                                                                               |
| ----------------------------------- | ---- | -------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| `show_cef_performance_monitor`      | bool | `true`   | Shows a real-time performance overlay in the top-left of the browser (FPS, memory, rendering mode)                                        |
| `show_download_notification`        | bool | `true`   | Shows built-in download progress bar and completion/failure notifications (white Material style toast). Set to `false` to only broadcast `WebNative` download events for developers to draw their own UI |
| `debugging_port_min`                | int  | `19223`  | Minimum remote DevTools debugging port. Set to 0 to disable remote debugging                                                              |
| `debugging_port_max`                | int  | `19262`  | Maximum remote DevTools debugging port. The plugin picks the first available port in this range. Access DevTools via `http://localhost:<port>` |

### Media Permission Policies

| Config Key                      | Type   | Allowed Values                  | Description                                        |
| ------------------------------- | ------ | ------------------------------- | -------------------------------------------------- |
| `media_permission_policy`       | string | `allow` / `deny` / `prompt`     | Global policy for media devices (camera/microphone) |
| `permission_prompt_policy`      | string | `allow` / `deny` / `prompt`     | Global policy for permission prompts (notifications/geolocation, etc.) |

### Individual Permission Switches (18 Items)

All keys below are `bool` type; `true` = allowed, `false` = denied.

| Config Key                           | Default    | Permission Description                        |
| ------------------------------------ | ---------- | --------------------------------------------- |
| `allow_microphone`                   | `true`     | Microphone access                             |
| `allow_camera`                       | `true`     | Camera access                                 |
| `allow_desktop_capture`              | `true`     | Screen/window capture (getDisplayMedia)       |
| `allow_clipboard`                    | `true`     | Clipboard read/write                          |
| `allow_geolocation`                  | `true`     | Geolocation                                   |
| `allow_notifications`                | `true`     | Desktop notifications                         |
| `allow_local_network_access`         | `true`     | Local network requests (LAN resources)        |
| `allow_file_system_access`           | `true`     | Local file system access (File System Access API) |
| `allow_pointer_lock`                 | `true`     | Mouse pointer lock (Pointer Lock API, for games) |
| `allow_keyboard_lock`                | `true`     | Keyboard lock (Keyboard Lock API)             |
| `allow_storage_access`               | `true`     | Third-party storage access (Storage Access API) |
| `allow_protected_media`              | `true`     | Protected content playback (EME/Widevine DRM) |
| `allow_local_fonts`                  | `true`     | Local font enumeration (Local Font Access API) |
| `allow_midi_sysex`                   | `false`    | MIDI System Exclusive messages                |
| `allow_multiple_downloads`           | `true`     | Concurrent multi-file downloads               |
| `allow_window_management`            | `true`     | Multi-screen/window management (Window Management API) |
| `allow_extended_reality`             | `false`    | WebXR extended reality (VR/AR)                |
| `allow_other_permission_prompts`     | `false`    | Other uncategorized permission prompts        |

### CEF Command-Line Arguments

| Config Key  | Type   | Description                                                                                                                                                                                                                                                                                                                                                                                       |
| ----------- | ------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `cefcore`   | string | CEF core process arguments (CEF Core Args), affecting all child processes. Common values: `disable-web-security`, `no-proxy-server`, `allow-file-access-from-files`, `allow-universal-access-from-files`                                                                                                                            |
| `cef_args`  | string | CEF browser process arguments (CEF Extra Args), affecting the renderer process only. Common values: `show-background-color`, `background-color=0x00000000` (transparent background). **Site isolation is disabled by default**: the plugin already appends `disable-features=SitePerProcess,IsolateOrigins,OutOfBlinkCors,...`; do not configure `disable-features` again in `cef_args`, otherwise the last value overwrites the built-in full list and re-enables other disabled features required by embedded scenarios |

> **Note**: the difference between `cefcore` and `cef_args`:
>
> - `cefcore` → CEF core command line, shared by all CEF child processes (GPU, network, renderer, etc.)
> - `cef_args` → passed only to the renderer process, e.g., background color, feature flags, etc.

### Linux Single/Multi-Process Configuration

Linux defaults to multi-process mode (`linux_single_process=false`) with better isolation and parallelism; for compatibility-first environments such as domestic CPUs/GPUs, switching to single-process mode is recommended. Clients can choose in the project config:

```ini
[WebNative]
linux_single_process=true
```

| Config Value | CEF arguments and behavior                                                                                                                                                    |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| `true`       | Adds `--single-process` and merges `NetworkService` into the single `--disable-features` argument; suitable for domestic CPU/GPU and compatibility-first environments; uses the single-process compatible shutdown flow on exit |
| `false`      | Does not add `--single-process` and does not disable `NetworkService`; Renderer, GPU, Network, Utility, etc. run as separate CEF Helper processes for better isolation and parallelism |

The config is read at CEF's first initialization and cannot be switched at runtime. After modifying the project's `DefaultGame.ini` or the packaged `Saved/Config/Linux/Game.ini`, fully exit and restart the program.
Multi-process mode relies on the architecture-matched `WebNativeBrowserHelper` shipped with the plugin.

> **Domestic environment compatibility guarantee**: the plugin will not disable or override `linux_single_process=true` on its own. Some domestic CPU + GPU environments need `NetworkService` and CEF to run cooperatively in-process to load network video correctly. Because upstream CEF's `--single-process` diagnostic mode may trigger `SIGTRAP` when calling `CefShutdown()` on Linux, the plugin only skips that call after UE has entered its final shutdown stage and all CEF browsers have requested shutdown, then cleans up leftover Helpers. Browsing, video playback, the message channel, and runtime behavior are unaffected. Multi-process mode still performs the full `CefShutdown()`.

**Why is single-process recommended for domestic environments?**

Chromium 144 splits the network stack into a separate `NetworkService` child process communicating with the main process via Mojo IPC. On domestic CPU (e.g., Phytium, Kunpeng) + domestic GPU (e.g., Lisca) combinations, the Mojo IPC Unix domain socket / eventfd mechanism can hang, causing all subsequent HTTP requests to remain pending — web images fail to fully load, video scripts fail to load, etc.

Single-process mode runs NetworkService in-process, bypassing that IPC communication. The default (`linux_single_process=false`) uses multi-process directly on verified Intel/AMD or server environments; on domestic hardware, switch to single-process mode (`linux_single_process=true`) first, then decide after completing web loading, video playback, message channel, and long-running stability tests.

### Recommended Configuration Examples

**Development environment (debugging fully enabled):**

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
debugging_port_min=19223
debugging_port_max=19262
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

**Production environment (security hardened):**

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

**Cloud rendering (cloud gaming) multi-instance:**

In cloud rendering/cloud gaming scenarios, each client process should be independent and generally does not rely on browser cache. Enable `multi_open=true` with `clear_cache=true` and `clear_log=true` to clear each instance's cache and logs after the session; keep the other security items per the "Production environment (security hardened)" config above:

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

---

## Technical Specifications

| Item       | Description                                  |
| ---------- | -------------------------------------------- |
| Engine     | Unreal Engine 5.1 - UE5.8                    |
| CEF        | Chromium 144 (CEF 131)                       |
| Platforms  | Windows 10+, Linux (Vulkan, GLIBC ≥ 2.17)    |
| Rendering  | D3D11/D3D12 (Windows), Vulkan (Linux)        |
| Max FPS    | 120 FPS                                      |
| C++ Std    | C++17                                        |

### Linux Distribution Compatibility

> **Minimum requirement: GLIBC 2.17**. Below this version the plugin will not start and reports a `GLIBC_X.XX not found` error.

| Distribution                     | GLIBC | Compatible | Notes                             |
| -------------------------------- | ----- | ---------- | --------------------------------- |
| Ubuntu 22.04 / 24.04             | 2.35+ | ✅ Yes     |                                   |
| Ubuntu 20.04                     | 2.31  | ✅ Yes     |                                   |
| Debian 11 (Bullseye)             | 2.31  | ✅ Yes     |                                   |
| Debian 12 (Bookworm)             | 2.36  | ✅ Yes     |                                   |
| CentOS Stream 9 / RHEL 9         | 2.34  | ✅ Yes     |                                   |
| CentOS 8 / RHEL 8                | 2.28  | ✅ Yes     | EOL; upgrade recommended          |
| Kylin V10 SP1 (Entry/Basic)      | 2.28  | ✅ Yes     | x86_64; verify GLIBC ≥ 2.28       |
| Kylin V10 SP1 (2503/Enhanced)    | 2.31  | ✅ Yes     | x86_64 version                    |
| UOS Server 20 (A/Debian-based)   | 2.31  | ✅ Yes     | Kernel 5.x version                |
| UOS Server 20 (E/openEuler)      | 2.28  | ✅ Yes     | x86_64 version                    |
| CentOS 7 / RHEL 7                | 2.17  | ✅ Yes     | Minimum required version; EOL     |

> **Verification note**: on 2026-07-24, `readelf -V` verification on a GLIBC 2.28 environment confirmed the binary only depends on GLIBC 2.17 (the highest version symbol on `libc.so.6` is `GLIBC_2.17`).

---

## FAQ

**Q: Transparent background is set, but clicks are still occasionally blocked and cannot pass through to the UE scene?**

A: There are three common transparent hit-through pitfalls in CEF. Avoid them with the following CSS rules:

1. **Don't use a full-screen `<div>` for visual effects** (e.g., flash effects). Use `body` pseudo-elements instead, covering only the needed area:

```css
/* Wrong — full-screen div blocks clicks */
.flash { position:fixed; inset:0; }

/* Correct — pseudo-elements cover only the sides */
body.flash::before, body.flash::after {
  content:''; position:fixed; top:0; bottom:0; width:60px; pointer-events:none;
}
```

2. **`backdrop-filter` must explicitly add `pointer-events:none`**, and when transparency is 0 it must be set to `none` (not `blur(0px)`):

```css
.overlay-bg {
  backdrop-filter: blur(10px);
  pointer-events: none;  /* must be declared explicitly */
}
```

```js
bg.style.backdropFilter = (alpha > 0) ? `blur(${px}px)` : 'none';
```

3. **Set full-screen mask containers to `pointer-events:none`**, and only give interactive child elements `pointer-events:auto`:

```css
.overlay-panel { pointer-events: none; }   /* full screen: no interception */
.panel-card    { pointer-events: auto; }   /* cards: interactive */
```

**Principle**: create fewer full-screen DOM elements, declare `pointer-events` explicitly on every layer, and turn off `backdrop-filter` when not in use.

**Q: The web page does not render correctly?**
A: Make sure `bUseGpuAcceleratedRendering = true`, and check the CEF initialization log `LogWebNative`.

**Q: How do I check the CEF version and logs?**
A: CEF logs are in `Saved/Logs/cef/cef.log`; you can also open the browser console via `ShowDevTools()`.

**Q: What is the JS message latency?**
A: A single message is <1ms (in-process IPC). Batch send latency:

| Message count | Time     |
| ------------- | -------- |
| 10            | ~5 ms    |
| 100           | ~5 ms    |
| 1,000         | ~6 ms    |
| 10,000        | ~30 ms   |
| 100,000       | ~220 ms  |

**Q: RSS keeps growing during long-running sessions on Linux?**

A: This is a known behavior of the UE5.x Linux engine and is unrelated to the plugin. On Linux, UE5's `FMallocBinned2` uses `FPooledVirtualMemoryAllocator` to manage its memory pools, and under the default configuration `madvise(MADV_DONTNEED)` is never called (`GMemoryRangeDecommitIsNoOp=true`), so freed physical pages are not returned to the OS. The 8MB pool is almost never fully cleared after fragmentation, and RSS only grows.

**Solution (reduces growth by 70-78%):**

Add `-vmapoolevict -vmapoolscale=1.0` to the launch script:

```sh
#!/bin/sh
UE_TRUE_SCRIPT_NAME=$(echo "$0" | xargs readlink -f)
UE_PROJECT_ROOT=$(dirname "$UE_TRUE_SCRIPT_NAME")
chmod +x "$UE_PROJECT_ROOT/YourProject/Binaries/Linux/YourProject"
exec "$UE_PROJECT_ROOT/YourProject/Binaries/Linux/YourProject" YourProject \
    -vmapoolevict -vmapoolscale=1.0 "$@"
```

| Parameter            | Effect                                                              |
| -------------------- | ------------------------------------------------------------------- |
| `-vmapoolevict`      | Enables decommit; calls `madvise(MADV_DONTNEED)` on free to return physical pages to the OS |
| `-vmapoolscale=1.0`  | Prevents exponential pool growth (default is 1.4 in the editor)     |

**Result comparison** (12-minute EmptyProject test):

| Metric             | Without flags   | With flags     | Improvement |
| ------------------ | --------------- | -------------- | ----------- |
| 8MB anon growth    | 1.5/min         | 0.45/min       | ↓ 70%       |
| RSS growth         | 13.2 MB/min     | 2.9 MB/min     | ↓ 78%       |

> **Note**: these flags affect free() performance (one extra syscall per free), but measured frame-rate impact is negligible. `FMemory::Trim()` and `r.Vulkan.*` cvars do not release Linux pool memory.

**Q: Dev builds on some domestic Linux systems (e.g., Kylin) cannot play video or hardware decoding fails?**

A: This is a known limitation of UE Development builds; Shipping packages are unaffected.

**Cause:** UE Development builds install signal handlers (for crash reporting), which are inherited by forked CEF Helper child processes, causing the GPU process to fail to start and hardware video decoding to fail.

| Build config          | linux_single_process | Video/hardware decoding                      |
| --------------------- | -------------------- | -------------------------------------------- |
| **Shipping**          | `false` (default)    | ✅ Normal (multi-process + GPU hardware decode) |
| **Dev**               | `false`              | ❌ May fail (GPU process disturbed by signal handlers) |
| **Dev**               | `true`               | ⚠️ Single-process software rendering (plays but no hardware acceleration) |

**Solution (in order of priority):**

1. **Prefer Shipping packages** — hardware decoding works perfectly with the best experience
2. **When a Dev package is required**, switch to single-process mode:

```ini
[WebNative]
linux_single_process=true
```

> Shipping packages default to multi-process (`linux_single_process=false`) and all GPU hardware decoding features work normally — no changes needed.
