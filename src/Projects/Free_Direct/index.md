---
title: Free Direct
breadcrumb:
- label: Projects
  href: Projects/index.html
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
<th>Based on</th>
<td><a href="Projects/CNA/index.html">CNA</a></td>
</tr>
<tr>
<th>Licence</th>
<td>GPLv3 or later</td>
</tr>
</table>

Free Direct is a [DirectX](Technologies/Libraries/DirectX/index.html) 3-like wrapper around [CNA](Projects/CNA/index.html). It reimplements the DirectX 3 API used by the original [Speedy Blupi (Epsitec)](Blupi/Games/Speedy_Blupi_(Windows)/index.html) game, allowing the decompiled source code of [Free Eggbert](Projects/Free_Eggbert/index.html) to run on modern platforms without DirectX.

## Role in the stack

```
SDL 3
  └── CNA  (XNA-like API)
        └── Free Direct  (DirectX 3-like API)
              └── Free Eggbert
```
