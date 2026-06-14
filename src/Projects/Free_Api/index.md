---
title: Free API
breadcrumb:
- label: Projects
  href: Projects/index.html
- label: Free API
  href: Projects/Free_Api/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">Free API</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://freeapi.openeggbert.com" target="_blank">https://freeapi.openeggbert.com</a></td>
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
<td>Subset of <a href="Technologies/Libraries/Windows_API/index.html">Windows API</a> (~1998 Win32 era)</td>
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

**Free API** is an experimental C++ project that reimplements a minimal subset of the [Windows API](Technologies/Libraries/Windows_API/index.html) (WinAPI), roughly targeting functionality available around 1998 (Win32 era). It allows [Free Eggbert](Projects/Free_Eggbert/index.html) (the decompiled Speedy Blupi) to run on non-Windows platforms without depending on Windows or compatibility layers like Wine.

## Architecture

```
WinAPI (subset ~1998)
      ↓
  Free API
      ↓
    SDL 3
```

## Implemented features

**Application entry:**
- `WinMain` abstraction (mapping to `main`)

**Windowing:**
- Window creation (`CreateWindowEx`), message loop (`PeekMessage`, `DispatchMessage`), window procedures (`WNDPROC`)

**Input (SDL 3 → WinAPI message translation):**
- Mouse motion → `WM_MOUSEMOVE`
- Mouse buttons → `WM_LBUTTONDOWN/UP`, `WM_RBUTTONDOWN/UP`, `WM_MBUTTONDOWN/UP`
- Keyboard → `WM_KEYDOWN` / `WM_KEYUP` with `VK_*` codes (letters, digits, navigation, function keys F1–F12, control keys)
- Text input → `WM_CHAR`
- Window focus → `WM_ACTIVATEAPP`

**MIDI music (`mmsystem.h`) — TinySoundFont + TinyMidiLoader:**
- MCI_OPEN/PLAY/CLOSE for MIDI sequencer files
- Renders MIDI to stereo float PCM via TinySoundFont and feeds it to an SDL 3 audio stream
- Requires a SoundFont 2 (.sf2) file for audio synthesis
- Supports MIDI Type 0 and 1 files

**Multimedia timer:**
- `timeSetEvent` / `timeKillEvent` implemented with `SDL_AddTimer` / `SDL_RemoveTimer`

**System utilities:**
- `GetTickCount`, `Sleep`, `OutputDebugString`

## Debug options

| Environment variable | Effect |
| --- | --- |
| `FREE_API_DEBUG_INPUT=1` | Log all translated input messages |
| `FREE_API_DEBUG_MIDI=1` | Log per-call MIDI debug info |

## SoundFont requirement

A SoundFont 2 (.sf2) file is required for MIDI music playback. Lookup order:
1. `FREE_API_SOUNDFONT` environment variable
2. `assets/soundfont/default.sf2`
3. `soundfont/default.sf2`

Free SoundFonts: [GeneralUser GS](https://schristiancollins.com/generaluser.php), [FluidR3_GM](https://packages.debian.org/fluid-soundfont-gm)

## Platform support

| Platform | Status |
| --- | --- |
| Linux | Supported via SDL 3 |
| Windows | Supported via SDL 3 |
| macOS | Supported via SDL 3 |
| Android | Supported (SoundFont must be packaged in assets) |
| Web (Emscripten) | Supported (may need user gesture for audio) |

## Build

```bash
cmake -B build
cmake --build build
```
