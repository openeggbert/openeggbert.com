---
title: Simple3D
breadcrumb:
- label: Projects
  href: Projects/index.html
- label: Simple3D
  href: Projects/Simple3D/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">Simple3D</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://simple3d.openeggbert.com" target="_blank">https://simple3d.openeggbert.com</a> | <a href="https://libsimple3d.com" target="_blank">https://libsimple3d.com</a></td>
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
<th>Licence</th>
<td>MIT</td>
</tr>
<tr>
<th>Based on</th>
<td><a href="https://github.com/u3d-community/U3D" target="_blank">Urho3D / U3D</a> (MIT, © 2008–2022 the Urho3D project)</td>
</tr>
<tr>
<th>Scripting</th>
<td>Lua / LuaJIT</td>
</tr>
<tr>
<th>Physics</th>
<td>Bullet (3D), Box2D (2D)</td>
</tr>
<tr>
<th>Backends</th>
<td>U3D (default), <a href="Projects/Nova3D/index.html">Nova3D</a></td>
</tr>
</table>

**Simple3D** is a clean, minimalistic 3D/2D game framework for C++23 and Lua. It wraps an Urho3D engine fork with a high-level, game-first API that exposes no engine internals. Subclass `Game`, override `Start()` and `Update()`, and ship — without needing to know anything about Urho3D's component model.

Urho3D types (`Urho3D::Node`, `Urho3D::Scene`, `Urho3D::Application`) never appear in public headers. They are hidden behind PIMPL classes. The only exception is math primitives (`Vector2/3/4`, `Color`, `Quaternion`, `Matrix3/3x4/4`, `BoundingBox`, `Rect`) which are re-exported as `Simple3D::` type aliases.

## Architecture

```
Game Code (C++ / Lua)
        ↓
   Simple3D API          ← stable public boundary; no engine types visible here
        ↓
  Urho3D fork (U3D)      ← scene graph, physics, navigation, networking, Lua
        ↓
  XNA C++ runtime        ← rendering, audio, input  (Nova3D backend only)
        ↓
  Vulkan / GLES / bgfx   ← GPU backends
        ↓
  SDL3 / OS              ← windowing, events
```

## Quick start (C++)

```cpp
#include <Simple3D/Simple3D.h>
using namespace Simple3D;

class MyGame : public Game {
public:
    Entity* player;
    Camera* camera;

    void Start() override {
        auto ground = CreateEntity("Ground");
        ground->AddModel("models/ground.obj");
        ground->AddRigidBody(0.0f);
        ground->AddBoxCollider(Vector3(50, 1, 50));

        player = CreateEntity("Player");
        player->AddModel("models/character.fbx");
        player->AddAnimationController();
        player->AddRigidBody(1.0f);
        player->AddCapsuleCollider(0.5f, 1.8f);
        player->SetPosition(0, 2, 0);
        player->AddScript("Scripts/player.lua");

        camera = CreateCamera();
        camera->Follow(player, 6.0f);
        camera->SetSmoothFollow(true);

        PlayMusic("Music/theme.ogg");
    }

    void Update(float dt) override {
        if (IsKeyDown(Key::Escape)) Quit();
    }
};

int main() {
    return CreateGame<MyGame>()->Run();
}
```

## Lua scripting

Per-entity `.lua` scripts with `Start()`, `Update(dt)`, and `Stop()`. Hot-reloadable at runtime without recompiling the engine.

```lua
-- Scripts/player.lua
speed = 6
jumpForce = 8

function Update(dt)
    local move = Vector3(0, 0, 0)
    if Input:IsKeyDown("W") then move.z = move.z + 1 end
    if Input:IsKeyDown("S") then move.z = move.z - 1 end
    if Input:IsKeyDown("A") then move.x = move.x - 1 end
    if Input:IsKeyDown("D") then move.x = move.x + 1 end

    if move:Length() > 0 then
        entity:MoveRelative(move:Normalized() * speed * dt)
        entity:GetAnimationController():Play("run")
    else
        entity:GetAnimationController():Play("idle")
    end

    if Input:IsKeyPressed("Space") and entity:IsOnGround() then
        entity:ApplyImpulse(Vector3(0, jumpForce, 0))
        PlaySound("Sounds/jump.wav")
    end
end
```

## Module status

| Module | Status | Notes |
| --- | --- | --- |
| Core | ✅ Task #1 | Game loop, types, keys, window |
| Entity | ✅ Task #1 | PIMPL over Urho3D::Node |
| Camera | ✅ Task #1 | Follow, LookAt, smooth, ortho |
| Audio | ✅ Task #1 | PlayMusic, PlaySound, volume |
| Input | ✅ Task #1 | Keyboard, mouse |
| UI | ✅ Task #1 | Label (Text element) |
| Physics | 🔄 Task #2 | Bullet via Urho3D |
| Animation | 🔄 Task #2 | AnimationController |
| Lua | 🔄 Task #3 | LuaScriptInstance + custom bindings |
| Navigation | 📋 Task #5 | Recast/Detour via Urho3D |
| Networking | 📋 Task #6 | ENet via Urho3D |
| 2D support | 📋 Task #7 | Sprites, orthographic camera |
| Android | 📋 Task #8 | Nova3D backend |
| Web | 📋 Task #9 | Emscripten |
| Samples | 📋 Task #10–12 | Hello World, 3D platformer, 2D game |

## Build

### Prerequisites

- CMake 3.21+
- C++23 compiler (GCC 13+, Clang 16+, MSVC 2022+)
- U3D built at `/rv/data/library/github.com/u3d-community/U3D/cmake-build-debug` (or set `URHO3D_HOME` / `U3D_HOME`)

### U3D backend (default)

```sh
cmake -S . -B build-u3d
cmake --build build-u3d
```

### Nova3D backend

```sh
cmake -S . -B build-nova3d -DSIMPLE3D_ENGINE=NOVA3D
cmake --build build-nova3d
```

### Web (Emscripten)

```sh
emcmake cmake -S . -B build-web -DSIMPLE3D_ENGINE=U3D
cmake --build build-web
```

### Windows (MinGW cross-compile)

```sh
cmake -S . -B build-windows \
  -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/mingw-w64.cmake \
  -DSIMPLE3D_ENGINE=U3D
cmake --build build-windows
```

## Platforms

Windows, Linux, macOS (via U3D + SDL 3). Android (Task #8, Nova3D backend). Web/Emscripten (Task #9).

## Attribution

Simple3D is built on top of the Urho3D / U3D engine fork (MIT license). Math types are ABI-identical re-exports of Urho3D math. All adapted files carry the original Urho3D copyright notice.

Copyright (c) 2008–2022 the Urho3D project. Copyright (c) 2024–2026 Robert Vokac and the Simple3D contributors.
