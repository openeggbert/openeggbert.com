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
<th>Based on</th>
<td>SDL 3</td>
</tr>
<tr>
<th>Licence</th>
<td>GPLv3 or later</td>
</tr>
</table>

CNA is an [XNA](Technologies/Libraries/XNA/index.html) 4.0-like game framework written in [C++](Technologies/Programming_languages/C++/index.html) and built on top of [SDL 3](Technologies/Libraries/SDL/index.html). It serves as the graphics, input, audio and windowing layer for [Mobile Eggbert](Projects/Mobile_Eggbert/index.html) (C++ version) and [Free Eggbert](Projects/Free_Eggbert/index.html).

CNA provides a familiar XNA-style API so that code originally written for XNA 4.0 (such as the decompiled Speedy Blupi for Windows Phone) can be ported to C++ while keeping the same structure.

## Role in the stack

```
SDL 3
  └── CNA  (XNA-like API)
        └── Free Direct  (DirectX 3-like API)
              └── Free Eggbert / Mobile Eggbert (C++)
```

## Platforms

SDL 3 supports many platforms, so CNA inherits support for: [Windows](Technologies/Platforms/Windows/index.html), [Linux](Technologies/Platforms/Linux/index.html), [MacOS](Technologies/Platforms/MacOS/index.html), [Android](Technologies/Platforms/Android/index.html), Web (via Emscripten) and others.
