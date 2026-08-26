// Copyright (c) 2026 StarTechnology. All rights reserved.
//
// Stub d3dx12.h for WebNativeBrowser plugin.
//
// UE 5.1-5.4: D3D12RHI's public header ID3D12DynamicRHI.h includes
// WindowsD3D12ThirdParty.h which includes <d3dx12.h>. The real d3dx12.h
// is a private dependency of D3D12RHI and not exported to dependent
// modules. Even if the include path is added, the real d3dx12.h has
// MSVC conformance bugs (D3D12_PROPERTY_LAYOUT_FORMAT_TABLE explicit
// overrides, missing Microsoft::WRL::ComPtr).
//
// This empty stub shadows the real d3dx12.h. Our plugin only uses raw
// d3d12.h types (ID3D12Resource, ID3D12Device, ID3D12CommandQueue, etc.),
// never the CD3DX12_* helper classes from d3dx12.h.
//
// UE 5.5+: D3D12RHI no longer includes d3dx12.h in its public headers,
// so this stub is harmless (never included).
#pragma once
