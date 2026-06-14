---
title: Galaxy Eggbert
breadcrumb:
- label: Projects
  href: Projects/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">Galaxy Eggbert</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://galaxyeggbert.openeggbert.com" target="_blank">https://galaxyeggbert.openeggbert.com</a></td>
</tr>
<tr>
<th>Programming language</th>
<td>C++</td>
</tr>
<tr>
<th>Based on</th>
<td><a href="Blupi/Games/Speedy_Blupi_(Windows_Phone)/index.html">Speedy Blupi (Dada Games)</a></td>
</tr>
<tr>
<th>Dependencies</th>
<td><a href="Projects/CNA/index.html">CNA</a>, <a href="Projects/Nova3D/index.html">Nova3D</a></td>
</tr>
<tr>
<th>Platforms</th>
<td>Windows, Linux, Android, Web (Emscripten)</td>
</tr>
<tr>
<th>Licence</th>
<td>GPLv3 or later</td>
</tr>
</table>

**Galaxy Eggbert** is the 3D remake of the game [Speedy Blupi](Blupi/Games/Speedy_Blupi_(Windows_Phone)/index.html). It is built using [CNA](Projects/CNA/index.html) as the game framework and [Nova3D](Projects/Nova3D/index.html) for 3D rendering.

## Platforms

| Platform | Backend | Status |
| --- | --- | --- |
| Linux | SDL_Renderer or EasyGL | Supported |
| Windows | SDL_Renderer | Supported |
| Web (Emscripten) | SDL_Renderer | Experimental |
| Android | — | Planned |

## Web build

The web build uses `emscripten_set_main_loop` (backed by `requestAnimationFrame`) instead of a busy loop. A fixed-timestep accumulator ensures gameplay speed is identical to Linux/Windows regardless of the browser's RAF cadence. Save data is stored in IndexedDB (IDBFS), persisted as `/save/.cna_isolated_storage/SpeedyBlupi`.

## Build (Linux)

```bash
cmake -S . -B build-linux \
  -DCNA_BACKEND_SDL_RENDERER=OFF \
  -DCNA_BACKEND_EASY_GL=ON
cmake --build build-linux --target GalaxyEggbert
```

## Build (Web / Emscripten)

```bash
source /path/to/emsdk/emsdk_env.sh
emcmake cmake -S . -B cmake-build-web -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-web -j
emrun cmake-build-web/GalaxyEggbert.html
```
