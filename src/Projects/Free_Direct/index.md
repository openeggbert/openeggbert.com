---
title: Free Direct
breadcrumb:
- label: Projects
  href: Projects/index.html
- label: Free Direct
  href: Projects/Free_Direct/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">Free Direct</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://freedirect.openeggbert.com" target="_blank">https://freedirect.openeggbert.com</a></td>
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
<th>Reimplements</th>
<td>Subset of DirectX 3 (2D)</td>
</tr>
<tr>
<th>Built on</th>
<td><a href="Technologies/Libraries/SDL/index.html">SDL 3</a></td>
</tr>
<tr>
<th>Licence</th>
<td>MIT</td>
</tr>
</table>

**Free Direct** is a C++ project that reimplements a narrow, game-driven subset of [DirectX](Technologies/Libraries/DirectX/index.html) 3 (2D) using SDL 3 as an internal backend. The goal is not full DirectX compatibility, but a focused, minimal implementation sufficient to run [Speedy Blupi (Epsitec)](Blupi/Games/Speedy_Blupi_(Windows)/index.html) on modern platforms without Windows.

## Architecture

```
DirectX 3 (subset)
      ↓
Free Direct
      ↓
SDL 3
```

## Implemented components

| Component | Status |
| --- | --- |
| **DirectDraw** | Implemented (narrow subset for Speedy Blupi) |
| **DirectSound** | Partially implemented (SDL 3 audio backend) |
| **DirectPlay** | Stubbed (dummy implementations) |
| **Direct3D** | Not implemented (not used by target game) |

**DirectDraw features:**
- Surface creation for primary and system-memory/offscreen surfaces
- `Blt` / `BltFast` with clipping and source color key handling
- `Lock` / `Unlock` for direct pixel access
- Palette support (`CreatePalette`, `SetEntries`, `GetEntries`, `SetPalette`)
- Primary surface presentation through SDL renderer
- 8-bit rendering with palette conversion on present

**DirectSound features:**
- SDL 3-backed audio playback for static PCM buffers
- Supported formats: 8-bit unsigned and 16-bit signed LE, mono/stereo, 11025/22050/44100 Hz
- `Play()`, `Stop()`, `GetStatus()`, `SetVolume()`, `SetPan()`

## Presentation model

- `Blt` / `BltFast` write to CPU pixel buffers and mark the primary surface dirty
- `Flip` or Blt-to-primary triggers presentation: throttle check → dirty check → SDL_Texture upload → SDL_RenderPresent
- VSync is enabled by default via `SDL_SetRenderVSync`
- Target FPS configurable via `FREE_DIRECT_TARGET_FPS=<n>`

## Debug options

| Environment variable | Effect |
| --- | --- |
| `FREE_DIRECT_DEBUG_DDRAW=1` | Log DirectDraw calls |
| `FREE_DIRECT_DEBUG_DSOUND=1` | Log DirectSound calls |
| `FREE_DIRECT_DEBUG_COLORKEY=1` | Log color key diagnostics |
| `FREE_DIRECT_DEBUG_PERF=1` | Log performance counters (presents/s, blts/s) |

## Build

```bash
cmake -B build
cmake --build build
./build/FREE_DIRECT
```
