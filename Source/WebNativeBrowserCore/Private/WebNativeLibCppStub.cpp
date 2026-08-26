// Copyright (c) 2026 StarTechnology. All rights reserved.
//
// libc++ 19+ ABI compatibility stub for Linux cross-compilation.
//
// CEF's libcef_dll_wrapper.a is compiled with Chromium's clang/libc++ 19+
// (or similar), which adds __libcpp_verbose_abort to the C++ ABI.  UE's
// bundled libc++ (particularly for the Linux cross-compilation toolchain)
// is older and does not provide this symbol, so linking fails with:
//   undefined symbol: std::__1::__libcpp_verbose_abort(char const*, ...)
//
// We cannot simply link a newer libc++.a because UE already links its own
// libc++.a — that would produce duplicate symbol errors for std::logic_error,
// std::runtime_error, etc.
//
// Instead we supply a minimal stub here.  The function is only called on
// fatal conditions (e.g. bounds-check or precondition violation inside
// libc++), so delegating to std::abort() is the correct fallback.

#include <cstdlib>

#if defined(PLATFORM_LINUX)
#if PLATFORM_LINUX

// Mimic libc++ namespace layout (libc++ uses inline namespace __1 for ABI
// versioning when _LIBCPP_ABI_NAMESPACE is set).
//
// We deliberately avoid including any libc++ headers so this stub works
// even when the host toolchain is libstdc++.

namespace std {
inline namespace __1 {

#if __clang_major__ >= 20
[[noreturn]] void __libcpp_verbose_abort(const char* /*format*/, ...) noexcept
#else
[[noreturn]] void __libcpp_verbose_abort(const char* /*format*/, ...)
#endif
{
	std::abort();
}

}  // inline namespace __1
}  // namespace std

#endif  // PLATFORM_LINUX
#endif  // defined(PLATFORM_LINUX)
