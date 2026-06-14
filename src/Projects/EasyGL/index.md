---
title: EasyGL
breadcrumb:
- label: Projects
  href: Projects/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">EasyGL</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://easygl.openeggbert.com" target="_blank">https://easygl.openeggbert.com</a></td>
</tr>
<tr>
<th>Programming language</th>
<td>C++</td>
</tr>
<tr>
<th>C++ standard</th>
<td>C++20</td>
</tr>
<tr>
<th>Targets</th>
<td>OpenGL, OpenGL ES</td>
</tr>
<tr>
<th>Built on</th>
<td><a href="Projects/MetaGL/index.html">MetaGL</a></td>
</tr>
<tr>
<th>Used by</th>
<td><a href="Projects/CNA/index.html">CNA</a> (EasyGL backend)</td>
</tr>
</table>

**EasyGL** is a toolkit-independent C++20 wrapper over OpenGL and OpenGL ES. It provides a small, modern API for common rendering tasks while keeping platform integration in the host application.

The host application owns window creation, GL context creation/activation, event processing, and swap/present. EasyGL does not create windows or contexts — it only wraps OpenGL calls.

## Architecture

```
Host application (SDL, GLFW, Qt, ...)
      └── provides GL context + GetProcAddress callback
              └── EasyGL  (OOP wrapper, namespace easygl)
                      └── MetaGL  (function pointers + type-safe API, namespace metagl)
                              └── actual OpenGL driver
```

## Public API overview

| Class | Description |
| --- | --- |
| `easygl::Device` | Initialization, state, draw commands |
| `easygl::Capabilities` / `easygl::ContextInfo` | Runtime capability/context inspection |
| `easygl::Shader`, `easygl::Program` | Shader compile/link/use |
| `easygl::Buffer`, `easygl::VertexArray` | GPU vertex resources |
| `easygl::Texture` | GPU texture resources |
| `easygl::Feature` | Explicit feature queries and gating |

## Quick start

```cpp
#include <easygl/easygl.hpp>

// After host creates and activates a GL context:
easygl::Device device;
device.initialize(my_get_proc_address);

// Check feature support at runtime:
if (device.supports(easygl::Feature::PolygonMode)) { ... }
```

## Build

```bash
cmake -S . -B build \
  -DEASYGL_BUILD_TESTS=ON \
  -DEASYGL_BUILD_EXAMPLES=ON
cmake --build build
```

## Notes

OpenGL/OpenGL ES differences are handled through capability checks. Some features are OpenGL-only (e.g. polygon mode); query support at runtime via `device.supports(...)`. No windowing toolkit lock-in — SDL, GLFW, Qt etc. stay in host code.
