---
title: CNA
breadcrumb:
- label: Projects
  href: Projects/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">CNA</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://cna.openeggbert.com" target="_blank">https://cna.openeggbert.com</a> | <a href="https://libcna.com" target="_blank">https://libcna.com</a></td>
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
<th>Built on</th>
<td><a href="Technologies/Libraries/SDL/index.html">SDL 3</a>, <a href="Projects/Sharp_Runtime/index.html">Sharp Runtime</a></td>
</tr>
<tr>
<th>Reimplements</th>
<td><a href="Technologies/Libraries/XNA/index.html">XNA 4.0</a> API</td>
</tr>
<tr>
<th>Licence</th>
<td>GPLv3 or later</td>
</tr>
</table>

**CNA** is a C++ reimplementation of the [XNA 4.0](Technologies/Libraries/XNA/index.html) programming model, built on SDL 3 and a pluggable graphics backend layer. It is a framework/runtime and abstraction layer — not a game — designed to preserve XNA-style APIs (`Microsoft::Xna::Framework`) while using modern C++ internals.

CNA serves as the graphics, input, audio and windowing layer for [Mobile Eggbert](Projects/Mobile_Eggbert/index.html) (C++ version), [Galaxy Eggbert](Projects/Galaxy_Eggbert/index.html), [MeshCraft](Projects/MeshCraft/index.html), and [Free Eggbert](Projects/Free_Eggbert/index.html).

## Architecture

```
Game / Application Code
      ↓
CNA API Layer  (Microsoft::Xna::Framework)
      ↓
Graphics backend (SDL_RENDERER / EASYGL / VULKAN)
      ↓
SDL 3 / OpenGL / Vulkan
```

## Features

**XNA API Compatibility (incremental):**
- Core game loop (`Game`, `GameTime`)
- `GraphicsDevice` abstraction with backend delegation
- `SpriteBatch` with `Begin(...)` / `Draw(...)` / `End()` workflow
- `Texture2D` abstraction
- Input and audio surfaces

**Backends:**
| Backend | Status |
| --- | --- |
| SDL_RENDERER | Implemented — focused on 2D rendering |
| EASYGL | Implemented — OpenGL via [EasyGL](Projects/EasyGL/index.html) |
| VULKAN | Architecture scaffold present, incomplete |

**Platforms:**
| Platform | Status |
| --- | --- |
| Linux | Supported |
| Windows | Supported (SDL_RENDERER backend) |
| Android | Planned |
| Web (Emscripten) | Architecture future-friendly |

## Role in the stack

```
Sharp Runtime  (System::* types)
      └── CNA  (XNA-like API)
            ├── Free Direct  (DirectX 3-like API)
            │     └── Free Eggbert
            ├── Mobile Eggbert (C++)
            ├── Galaxy Eggbert
            └── MeshCraft
```

## Build

```bash
git submodule update --init --recursive
cmake -S . -B build -DCNA_GRAPHICS_BACKEND=EASYGL
cmake --build build --target CNA CnaTests
ctest --test-dir build --output-on-failure
```
