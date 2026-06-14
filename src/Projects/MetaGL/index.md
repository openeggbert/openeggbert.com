---
title: MetaGL
breadcrumb:
- label: Projects
  href: Projects/index.html
- label: MetaGL
  href: Projects/MetaGL/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">MetaGL</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://metagl.openeggbert.com" target="_blank">https://metagl.openeggbert.com</a></td>
</tr>
<tr>
<th>Programming language</th>
<td>C++</td>
</tr>
<tr>
<th>C++ standard</th>
<td>C++23</td>
</tr>
<tr>
<th>Targets</th>
<td>OpenGL ES 3.0+</td>
</tr>
<tr>
<th>Used by</th>
<td><a href="Projects/EasyGL/index.html">EasyGL</a></td>
</tr>
</table>

**MetaGL** is a low-level, type-safe C++23 wrapper targeting OpenGL ES 3.0 or higher. It is the foundation layer used by [EasyGL](Projects/EasyGL/index.html) and provides:

- Runtime OpenGL function loading via a host-supplied `GetProcAddress` callback
- Type-safe `enum class` wrappers for OpenGL constants (buffer targets, shader types, texture formats, etc.)
- Thin inline-style wrapper functions in the `metagl` namespace (`metagl::GlBindBuffer`, `metagl::GlClear`, …)
- No windowing, no context creation — the host application owns the GL context lifecycle

## Architecture

```
Host application
      └── provides GL context + GetProcAddress callback
              └── EasyGL   (OOP wrapper, namespace easygl)
                      └── MetaGL  (function pointers + type-safe API, namespace metagl)
                              └── actual OpenGL driver
```

## Public API overview

| Header | Contents |
| --- | --- |
| `metagl/Types.hpp` | Primitive GL type aliases (`GLuint`, `GLint`, `GlGetProcAddressFn`, …) |
| `metagl/Enums.hpp` | Type-safe `enum class` wrappers for GL constants |
| `metagl/Functions.hpp` | Declarations of all `metagl::Gl*` wrapper functions |
| `metagl/Loader.hpp` | `metagl::Initialize()` / `metagl::IsInitialized()` |
| `metagl/metagl.hpp` | Umbrella header |

## Usage

```cpp
#include <metagl/metagl.hpp>

// Initialize once after host creates the GL context:
metagl::Initialize(my_get_proc_address);

// Use type-safe wrappers:
metagl::GlClearColor(0.2f, 0.3f, 0.3f, 1.0f);
metagl::GlClear(metagl::ClearBufferBit::Color | metagl::ClearBufferBit::Depth);

metagl::GLuint shader = metagl::GlCreateShader(metagl::ShaderType::Vertex);
```

## Design notes

Raw OpenGL values (`GL_ARRAY_BUFFER`, `GL_VERTEX_SHADER`, …) stay internal to MetaGL. Callers use `enum class` values; conversions to `GLenum` happen inside `metagl::detail`. No OpenGL headers are exposed in public headers. Plain OpenGL and OpenGL ES older than 3.0 are not supported.

## Build

MetaGL is intended to be consumed as a CMake subdirectory:

```cmake
add_subdirectory(../meta-gl meta-gl)
target_link_libraries(my-target PRIVATE meta-gl::meta-gl)
```
