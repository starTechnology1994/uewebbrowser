# WebNative Browser 更新日志

## [2.0.0] - 2026-11-10

### 新增

**Linux GPU 加速选路**

- 新增三档加速路径：DMA-BUF（零拷贝共享纹理）、GPU-Raster（GPU 绘制 + 整帧读回）、CPU（软件渲染），按显卡能力自动选路，失败只降不升
- NVIDIA 独占 DRM 时自动跳过 DMA-BUF 改走 GPU-Raster，解决无头服务器上 dma-buf 内容对第三方不可见导致的空帧问题
- CEF 的 GPU 渲染能力与共享纹理交付解耦：`shared_texture=0` 时 CEF 仍使用 GPU 渲染，不再退化为软件光栅
- 新增配置项 `gpu_raster`、`shared_texture`，支持环境变量 `WNB_GPU_RASTER` / `WNB_SHARED_TEXTURE` 现场覆盖

**命中检测性能**

- alpha 掩码归约改用 SSE2 `pmaxub` 逐字节取块内最大值，与逐像素实现结果严格一致（非采样），1080p 约 -59%、4K 约 -53% 耗时
- CEF 报告无脏区时复用上一帧掩码，消除周期性全量重扫卡顿
- 模板控件 `MouseTransparencyMaskBlockSize` 默认值由 1 调整为 8

**诊断能力**

- 新增 `[WNB] GPU detect`（显卡厂商识别）、`[WNB] accel plan`（最终加速档位）、`[WNB] accel tier`（实际降级）、`[WNB][ALPHA]`（掩码开销）等日志

### 优化

- Linux dma-buf 上传路径优先选用 `HOST_CACHED` 主机可见内存，非一致内存拷贝后补充 flush
- dma-buf CPU 映射按对象身份缓存复用（上限 4 条 LRU），避免每帧重新缺页；补充 `DMA_BUF_IOCTL_SYNC` 保证一致性
- 空帧探测改为时间窗判定（默认 2 秒），避免 CEF 合成器预热期的少量空帧被误判为通道失效
- 调整 D3D12 等待轮询间隔，降低空闲期 CPU 唤醒次数

### 修复

- 修复 `shared_texture=0` 时 GPU 浏览器被误降级重建为 CPU 浏览器（实例数翻倍、帧率骤降）的问题
- 修复 `offgpu=true` 与残留 `gpu_raster=1` 同时存在时，CEF 命令行与 UE 侧渲染模式不一致的问题
- 修复 Linux 页面加载后加速帧延迟到达时被过早降级的问题

### 新增配置项

| 配置键 | 默认值 | 说明 |
| --- | --- | --- |
| `gpu_raster` | 自动 | 仅 Linux，是否启用 GPU 光栅 |
| `shared_texture` | 自动 | 仅 Linux，是否请求 dma-buf 共享纹理 |
| `alpha_mask_reduce` | `simd` | 掩码归约方式：`simd` / `sample` / `full` |
| `alpha_mask_sample` | `4` | `sample` 模式的每块采样点数 |
| `alpha_mask_skip_empty` | `true` | 无脏区时复用上一帧掩码 |
| `alpha_mask_confirm` | `true` | `sample` 模式下对可疑块精确复扫 |
| `accel_fallback_after_pageload` | `2.0` | 页面加载后无加速帧的降级宽限（秒） |
| `accel_watchdog_timeout` | `3.0` | 无加速帧的兜底超时（秒） |
| `empty_frame_grace` | `true` | 空帧探测是否使用时间窗 |

详见 [06-CEF 参数配置](https://github.com/starTechnology1994/uewebbrowser/wiki/06-CEF-Configuration) 第 5.3 ~ 5.5 节。

---

## [1.0.0] - 2026-07-12

### 新增

**引擎与平台**

- 支持 Unreal Engine 5.1 至 5.8，Windows x64 和 Linux x86_64 双平台
- 内嵌 Chromium 浏览器内核，完整支持 HTML5 / CSS3 / ES2024+ 标准
- 以 UMG Slate 控件形式嵌入浏览器，与 UE UI 体系无缝集成，支持任意缩放和叠加
- 支持透明背景网页叠加渲染，实现网页内容与 3D 场景的混合显示
- 支持同时创建多个独立浏览器实例，每个实例拥有完全隔离的缓存、Cookie 和日志目录
- 引擎关闭时自动清理当前实例的缓存和日志（可配置开启/关闭）

**网页渲染能力**

- 支持网页视频播放（B 站、YouTube 等主流平台），含弹幕和倍速播放
- 支持音频播放，含 Web Audio API 高精度音频处理
- 支持受保护媒体内容播放（Widevine DRM）
- 支持 WebGL 1.0 / 2.0 硬件加速 3D 渲染
- 支持 WebRTC 实时音视频通信
- 支持 WebSocket 实时双向数据通道
- 支持 CSS 动画、CSS Transform、requestAnimationFrame 等动态效果
- 支持网页全屏切换

**UE ↔ Web 双向通信**

- 基于消息通道的 JS ↔ UE 双向通信,极高性能
- 支持任意 JSON 格式数据交互
- 支持批量消息收发，降低高频调用开销
- 提供 14 个官方 HTML5 示例页面，覆盖窗口管理、交互表单、WebSocket 聊天、视频播放等场景

**交互与输入**

- 完整支持鼠标操作（移动、点击、双击、滚轮、右键菜单）
- 支持键盘输入，含文本输入、快捷键
- 支持触摸屏操作（触控点击、拖拽、双指缩放），可配置开启/关闭
- 支持 Ctrl + 鼠标滚轮缩放网页（可配置开启/关闭）
- 支持 F5 键刷新网页（可配置开启/关闭）

**文件与剪贴板**

- 支持网页文件上传（调用系统原生文件选择器）
- 支持网页文件下载，含下载进度条通知（可配置显示/隐藏）
- 支持多文件并发下载
- 支持剪贴板读写（复制/粘贴文字和图片）

**权限与安全**

- 提供 18 项可配置的网页权限开关（麦克风、摄像头、剪贴板、地理位置、桌面通知、文件系统访问、指针锁定、键盘锁定、本地字体枚举等）
- 支持媒体设备权限全局策略（允许 / 拒绝 / 弹窗询问）
- 支持其他权限弹窗全局策略（允许 / 拒绝 / 弹窗询问）
- 支持配置 CEF 内核命令行参数，满足安全加固和定制化需求

**弹窗与新窗口**

- 网页弹窗统一转为标签页形式内嵌显示，不弹出外部浏览器窗口
- 支持标签页之间切换和关闭

**开发者工具**

- 支持远程 DevTools 调试（通过浏览器访问 `http://localhost:<端口>`）
- 支持配置调试端口范围，多实例自动分配可用端口
- 支持实时性能监控叠加层（FPS、内存、渲染模式）

**品牌**

- 支持离线验证机制

### 已知问题


- 在部分 Linux 国产 GPU 平台上，视频解码可能回退到 CPU 软解，表现为播放高码率视频时偶有卡顿。
- 部分 Linux 旧发行版因 GLIBC 版本低于最低要求（2.17）而无法运行。CentOS 8 / RHEL 8 等已 EOL 的系统（GLIBC 2.28）可以运行，但不建议用于生产环境。详情参见 README_CN.md 中的 Linux 发行版兼容性表。
