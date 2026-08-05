# WebNative Browser Changelog

## [1.0.0] - 2026-07-12

### Added

**Engine & Platforms**

- Supports Unreal Engine 5.1 to 5.8, Windows x64 and Linux x86_64
- Embeds the Chromium browser engine with full HTML5 / CSS3 / ES2024+ standards support
- Embeds the browser as a UMG Slate widget, seamlessly integrated with the UE UI system, supporting arbitrary scaling and overlay
- Supports transparent-background web page overlay rendering for mixed web + 3D scene display
- Supports creating multiple independent browser instances at the same time; each instance has fully isolated cache, cookies, and log directories
- Automatically cleans up the current instance's cache and logs on engine shutdown (configurable on/off)

**Web Rendering Capabilities**

- Supports web video playback (Bilibili, YouTube, and other mainstream platforms), including danmaku and playback speed control
- Supports audio playback, including high-precision audio via the Web Audio API
- Supports protected media content playback (Widevine DRM)
- Supports WebGL 1.0 / 2.0 hardware-accelerated 3D rendering
- Supports WebRTC real-time audio/video communication
- Supports WebSocket real-time bidirectional data channels
- Supports CSS animations, CSS Transform, requestAnimationFrame, and other dynamic effects
- Supports fullscreen web page toggling

**UE ↔ Web Bidirectional Communication**

- Message-channel based JS ↔ UE bidirectional communication with extremely high performance
- Supports arbitrary JSON data exchange
- Supports batched message send/receive to reduce overhead of high-frequency calls
- Provides 14 official HTML5 example pages covering window management, interactive forms, WebSocket chat, video playback, and more

**Interaction & Input**

- Full mouse support (move, click, double-click, wheel, context menu)
- Keyboard input support, including text input and shortcuts
- Touch screen support (tap, drag, pinch zoom), configurable on/off
- Ctrl + mouse wheel web page zoom (configurable on/off)
- F5 key web page refresh (configurable on/off)

**Files & Clipboard**

- Web file upload (native system file picker)
- Web file download with download progress bar notifications (configurable show/hide)
- Concurrent multi-file download
- Clipboard read/write (copy/paste text and images)

**Permissions & Security**

- 18 configurable web permission switches (microphone, camera, clipboard, geolocation, desktop notifications, file system access, pointer lock, keyboard lock, local font enumeration, etc.)
- Global media device permission policy (allow / deny / prompt)
- Global policy for other permission prompts (allow / deny / prompt)
- Configurable CEF kernel command-line arguments for security hardening and customization

**Popups & New Windows**

- Web popups are converted to tab-style embedded display instead of opening external browser windows
- Support switching between and closing tabs

**Developer Tools**

- Remote DevTools debugging (via browser access to `http://localhost:<port>`)
- Configurable debug port range; multi-instance automatically allocates available ports
- Real-time performance monitor overlay (FPS, memory, rendering mode)

**Licensing & Branding**

- Offline license verification mechanism

### Known Issues

- On NVIDIA RTX 50-series GPUs with driver 580.88 or newer, running multiple browser instances at the same time may cause the application to crash (a known NVIDIA driver bug, not a plugin issue). Workaround: add `offgpu=true` in the `[WebNative]` section of the config file; normal usage is unaffected. See the FAQ in README.md for details.
- On some domestic Linux GPU platforms, video decoding may fall back to CPU software decoding, which can cause occasional stuttering when playing high-bitrate videos.
- Some older Linux distributions cannot run because their GLIBC is below the minimum requirement (2.17). EOL systems such as CentOS 8 / RHEL 8 (GLIBC 2.28) can run, but are not recommended for production use. See the Linux distribution compatibility table in README.md for details.
