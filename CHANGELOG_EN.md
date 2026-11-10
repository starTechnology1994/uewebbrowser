# WebNative Browser Changelog

## [2.0.0] - 2026-11-10

### Added

**Linux GPU acceleration selection**

- New three-tier acceleration path: DMA-BUF (zero-copy shared texture), GPU-Raster (GPU rendering + full-frame readback), CPU (software). Selected automatically by GPU capability; failures only downgrade
- On NVIDIA owning the DRM render node, DMA-BUF is skipped automatically and GPU-Raster is used, fixing the empty-frame problem on headless servers where dma-buf contents are not visible to third-party contexts
- CEF GPU rendering is decoupled from shared-texture delivery: with `shared_texture=0` CEF still renders on the GPU instead of falling back to software raster
- New `gpu_raster` and `shared_texture` options, overridable in the field with `WNB_GPU_RASTER` / `WNB_SHARED_TEXTURE`

**Hit-test performance**

- Alpha-mask reduction now uses SSE2 `pmaxub` byte-wise block maximum, byte-identical to the per-pixel implementation (exact, not sampled): about -59% at 1080p and -53% at 4K
- Reuses the previous mask when CEF reports no dirty rects, removing periodic full-rescan hitches
- Template widget default `MouseTransparencyMaskBlockSize` changed from 1 to 8

**Diagnostics**

- New log lines: `[WNB] GPU detect` (vendor detection), `[WNB] accel plan` (selected tier), `[WNB] accel tier` (actual downgrade), `[WNB][ALPHA]` (mask cost)

### Improved

- Linux dma-buf upload path prefers `HOST_CACHED` host-visible memory, with an explicit flush after copies into non-coherent memory
- dma-buf CPU mappings are cached and reused by object identity (4-entry LRU) instead of re-faulting every frame; adds the missing `DMA_BUF_IOCTL_SYNC`
- Empty-frame probing now uses a time window (2 s default) so a few empty frames during CEF compositor warm-up are not treated as a dead channel
- Tuned the D3D12 wait polling interval to reduce idle CPU wake-ups

### Fixed

- Fixed GPU browsers being wrongly recreated as CPU browsers when `shared_texture=0` (doubled instance count, frame-rate collapse)
- Fixed a mismatch between CEF command line and UE render mode when `offgpu=true` coexists with a leftover `gpu_raster=1`
- Fixed premature downgrade when accelerated frames arrive shortly after page load on Linux

### New options

| Key | Default | Description |
| --- | --- | --- |
| `gpu_raster` | auto | Linux only: enable GPU raster |
| `shared_texture` | auto | Linux only: request dma-buf shared texture |
| `alpha_mask_reduce` | `simd` | Mask reduction: `simd` / `sample` / `full` |
| `alpha_mask_sample` | `4` | Probes per block in `sample` mode |
| `alpha_mask_skip_empty` | `true` | Reuse the previous mask when there are no dirty rects |
| `alpha_mask_confirm` | `true` | Exact re-scan of suspicious blocks in `sample` mode |
| `accel_fallback_after_pageload` | `2.0` | Grace period after page load before downgrading (seconds) |
| `accel_watchdog_timeout` | `3.0` | Fallback timeout without accelerated frames (seconds) |
| `empty_frame_grace` | `true` | Whether empty-frame probing uses a time window |

See sections 5.3-5.5 of [06-CEF Configuration](https://github.com/starTechnology1994/uewebbrowser/wiki/06-CEF-Configuration).

---

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


- On some domestic Linux GPU platforms, video decoding may fall back to CPU software decoding, which can cause occasional stuttering when playing high-bitrate videos.
- Some older Linux distributions cannot run because their GLIBC is below the minimum requirement (2.17). EOL systems such as CentOS 8 / RHEL 8 (GLIBC 2.28) can run, but are not recommended for production use. See the Linux distribution compatibility table in README.md for details.
