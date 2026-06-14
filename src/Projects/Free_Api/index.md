---
title: Free API
breadcrumb:
- label: Projects
  href: Projects/index.html
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
<th>Reimplements</th>
<td>Subset of <a href="Technologies/Libraries/Windows_API/index.html">Windows API</a></td>
</tr>
<tr>
<th>Licence</th>
<td>GPLv3 or later</td>
</tr>
</table>

Free API is a partial reimplementation of the [Windows API](Technologies/Libraries/Windows_API/index.html) used by the original [Speedy Blupi (Epsitec)](Blupi/Games/Speedy_Blupi_(Windows)/index.html) game. It allows the decompiled source code of [Free Eggbert](Projects/Free_Eggbert/index.html) to compile and run on non-Windows platforms without depending on the actual Windows API or compatibility layers like Wine.

Only the subset of Windows API calls that Speedy Blupi actually uses is reimplemented.
