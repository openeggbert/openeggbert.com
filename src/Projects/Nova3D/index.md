---
title: Nova3D
breadcrumb:
- label: Projects
  href: Projects/index.html
- label: Nova3D
  href: Projects/Nova3D/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">Nova3D</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://nova3d.openeggbert.com" target="_blank">https://nova3d.openeggbert.com</a> | <a href="https://libnova3d.com" target="_blank">https://libnova3d.com</a></td>
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
<th>Licence</th>
<td>MIT</td>
</tr>
<tr>
<th>Based on</th>
<td><a href="https://github.com/u3d-community/U3D" target="_blank">Urho3D / U3D</a> (MIT, © 2008–2022 the Urho3D project)</td>
</tr>
<tr>
<th>Graphics backend</th>
<td><a href="Projects/CNA/index.html">CNA</a> (SDL 3 / OpenGL / OpenGL ES)</td>
</tr>
</table>

**Nova3D** is a modified version of [Urho3D](https://github.com/u3d-community/U3D) — a cross-platform, open-source, MIT-licensed 3D game engine. Nova3D reuses Urho3D source code directly (math, containers, scene graph, resource system, and more), and replaces Urho3D's native OpenGL/Direct3D backends with [CNA](Projects/CNA/index.html) — a C++ reimplementation of the XNA 4.0 API built on SDL 3.

The public C++ API uses `namespace Urho3D`. Game code written against Urho3D is intended to compile against Nova3D with minimal changes.

## Architecture

```
Game code
      ↓
Nova3D public API   (namespace Urho3D, include/Urho3D/)
      ↓
Nova3D scene, resource, renderer, UI, physics
 — adapted from Urho3D source —
      ↓
IGraphicsBackend  (CnaGraphicsAdapter)
      ↓
CNA  —  C++ XNA 4.0 backend  (SDL3 / OpenGL / OpenGL ES)
```

## Public API overview

| Header | Class | Description |
| --- | --- | --- |
| `Urho3D/Context.h` | `Urho3D::Context` | Subsystem registry and event dispatcher |
| `Urho3D/Engine.h` | `Urho3D::Engine` | Main loop and engine lifetime |
| `Urho3D/Application.h` | `Urho3D::Application` | Base class for user applications |
| `Urho3D/Scene/Scene.h` | `Urho3D::Scene` | Root of the scene graph |
| `Urho3D/Scene/Node.h` | `Urho3D::Node` | Scene-graph node with transform hierarchy |
| `Urho3D/Graphics/Camera.h` | `Urho3D::Camera` | Camera component |
| `Urho3D/Graphics/StaticModel.h` | `Urho3D::StaticModel` | Static mesh component |
| `Urho3D/Graphics/Light.h` | `Urho3D::Light` | Light component |
| `Urho3D/Resource/ResourceCache.h` | `Urho3D::ResourceCache` | Resource loading and caching |

## Platforms

Through CNA and SDL 3: [Windows](Technologies/Platforms/Windows/index.html), [Linux](Technologies/Platforms/Linux/index.html), [MacOS](Technologies/Platforms/MacOS/index.html), [Android](Technologies/Platforms/Android/index.html), Web (Emscripten).

## Build

```bash
cmake -S . -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON
ninja -C cmake-build-debug
```

## Attribution

Nova3D directly reuses Urho3D MIT-licensed source for: math, containers, IO, scene graph, resource system, graphics components. All adapted files carry the original Urho3D copyright notice plus the Nova3D contributor notice.

Copyright (c) 2008–2022 the Urho3D project. Copyright (c) 2024–2026 Robert Vokac and the Nova3D contributors.
