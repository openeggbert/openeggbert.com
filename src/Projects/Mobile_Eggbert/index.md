---
title: Mobile Eggbert
breadcrumb:
- label: Projects
  href: Projects/index.html
- label: Mobile Eggbert
  href: Projects/Mobile_Eggbert/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<style>
            table a {
           max-width: 200px;
           overflow: hidden;
           white-space: nowrap;
           text-overflow: ellipsis;
           display: inline-block;
       }
        </style>

<table class="infobox">
<tr>
<th colspan="2">Mobile Eggbert</th>
</tr>
<tr>
<th>Release date (C#)</th>
<td>25th November 2024</td>
</tr>
<tr>
<th>Release date (C++)</th>
<td>Not yet</td>
</tr>
<tr>
<th>Github (C++)</th>
<td><a href="https://github.com/openeggbert/mobile-eggbert" target="_blank">https://github.com/openeggbert/mobile-eggbert</a>
</td>
</tr>
<tr>
<th>Github (C# Core)</th>
<td><a href="https://github.com/openeggbert/mobile-eggbert-core" target="_blank">https://github.com/openeggbert/mobile-eggbert-core</a>
</td>
</tr>
<tr>
<th>Github (C# MonoGame Android)</th>
<td><a href="https://github.com/openeggbert/mobile-eggbert-monogame-android" target="_blank">https://github.com/openeggbert/mobile-eggbert-monogame-android</a>
</td>
</tr>
<tr>
<th>Github (C# MonoGame Desktop)</th>
<td><a href="https://github.com/openeggbert/mobile-eggbert-monogame-desktop" target="_blank">https://github.com/openeggbert/mobile-eggbert-monogame-desktop</a>
</td>
</tr>
<tr>
<th>Github (C# FNA Desktop)</th>
<td><a href="https://github.com/openeggbert/mobile-eggbert-fna-desktop" target="_blank">https://github.com/openeggbert/mobile-eggbert-fna-desktop</a>
</td>
</tr>
<tr>
<th>Github (C# KNI Web)</th>
<td><a href="https://github.com/openeggbert/mobile-eggbert-kni-web" target="_blank">https://github.com/openeggbert/mobile-eggbert-kni-web</a>
</td>
</tr>
<tr>
<th>Programming languages</th>
<td><a href="Technologies/Programming_languages/C_Sharp/index.html">C#</a>, <a href="Technologies/Programming_languages/C++/index.html">C++</a></td>
</tr>
<tr>
<th>Game frameworks</th>
<td>MonoGame, FNA, KNI, CNA, XNA 4.0, SDL 3</td>
</tr>
<tr>
<th>Website</th>
<td><a href="https://mobileeggbert.openeggbert.com" target="_blank">https://mobileeggbert.openeggbert.com</a></td>
</tr>
<tr>
<th>CNA library website</th>
<td><a href="https://cna.openeggbert.com" target="_blank">https://cna.openeggbert.com</a> | <a href="https://libcna.com" target="_blank">https://libcna.com</a></td>
</tr>
</table>

Mobile Eggbert is a [2D](Article_does_not_yet_exist_or_link_is_broken/index.html) [platformer](Article_does_not_yet_exist_or_link_is_broken/index.html) [game](Article_does_not_yet_exist_or_link_is_broken/index.html) based on [Speedy Blupi for Windows Phone](Blupi/Games/Speedy_Blupi_(Windows_Phone)/index.html). <br> The [ILSpy](Article_does_not_yet_exist_or_link_is_broken/index.html) decompiler was used to get back the [C Sharp|C#](Technologies/Programming_languages/C_Sharp/index.html) [source code](Article_does_not_yet_exist_or_link_is_broken/index.html) of [Speedy Blupi for Windows Phone](Blupi/Games/Speedy_Blupi_(Windows_Phone)/index.html). The decompiled source code is not the same, as the original was. Comments and names of local variables are lost. <br> The discontinued [XNA](Technologies/Libraries/XNA/index.html) 4 game framework is replaced by [MonoGame](Article_does_not_yet_exist_or_link_is_broken/index.html) game framework. MonoGame is almost a [drop-in replacement](Article_does_not_yet_exist_or_link_is_broken/index.html) for the XNA. There are several implementations of XNA 4.0 game framework (like [FNA](Article_does_not_yet_exist_or_link_is_broken/index.html) or others). <br> See also: [Alternative implementations of XNA](Article_does_not_yet_exist_or_link_is_broken/index.html) <br> Work on Mobile Eggbert started on 23rd November 2024. <br> Already on 23rd November 2024 the game was successfully decompiled and made runnable without any errors on desktop (Windows and Linux). The support for mouse and keyboard was added. <br> On 25th November Mobile Eggbert was released for Windows and Linux: [https://drive.openeggbert.com/Mobile_Eggbert/](https://drive.openeggbert.com/Mobile_Eggbert/)

- It works without any issues.

## Why Mobile Eggbert was created

Mobile Eggbert was started, because:

1. [Windows Phone](Technologies/Platforms/Windows_Phone/index.html) is a discontinued closed-source proprietary mobile [operating system](Article_does_not_yet_exist_or_link_is_broken/index.html) (developed by [Microsoft](Technologies/Other/Microsoft/index.html) company for [smart phones](Article_does_not_yet_exist_or_link_is_broken/index.html)).
2. Devices with Windows Phones are no more produced. Windows Phone operating system cannot be installed on other modern devices.
3. Without physical device with Windows Phone installed the emulator is the only way to run Speedy Blupi (2013) nowdays. But the emulator probably will not work in the future, as it is a closed-source proprietary technology.
4. Because the source code of Speedy Blupi (2013) is not available, it is not possible to make improvements or bug fixes.

## Current status

Mobile Eggbert works on Windows and Linux. <br> Mobile Eggbert starts on Android, but it is buggy: scaling is wrong, touch controls are not working correctly, worlds are not loading.

## Issues and the future

Mobile Eggbert is buggy on Android and must be fixed. <br> Accelerometer support is not yet available. It will be added for the Android platform. <br> Local variables must be renamed to the correct names. <br> Comments must be added. <br> Some refactoring is planned. <br> Porting to FNA or an alternative XNA 4.0 is planned to be done. <br> If the C# version will be kept, then there will be probably 3 modules: mobile-eggbert-core, mobile-eggbert-desktop and mobile-eggbert-android. <br> Mobile Eggbert is being just rewritten to C++. MonoGame is replaced by CNA.

## Reasons to Rewrite Mobile Eggbert in C++ and CNA

- **Performance Gains** – C++ allows for more efficient memory management and CPU usage, improving the game's responsiveness.
- **Direct Hardware Access** – CNA (built on SDL 3) provides direct access to graphics, input, and sound hardware, leading to better optimization.
- **Cross-Platform Compatibility** – SDL-based frameworks ensure support across Windows, Linux, and macOS without relying on .NET.
- **Future-Proofing** – XNA has been deprecated, and MonoGame is tied to .NET, which evolves frequently. C++ offers long-term stability.
- **Console Support** – SDL-based frameworks are commonly used for developing console games.
- **Better Dependency Management** – C++ eliminates .NET version dependency issues encountered with MonoGame.

## Reasons not to Rewrite Mobile Eggbert in C++ and CNA

- **Development Complexity** – C++ requires manual memory management and has a steeper learning curve compared to C#.
- **Less Built-in Features** – CNA may require more custom coding for engine components that MonoGame provides natively.
- **Longer Development Time** – Transitioning to C++ might take longer due to lower-level coding requirements.

## External links

- [https://docs.monogame.net/articles/getting_started/index.html](https://docs.monogame.net/articles/getting_started/index.html)
- [https://www.codeproject.com/Articles/754354/Port-a-2D-libgdx-game-to-MonoGame](https://www.codeproject.com/Articles/754354/Port-a-2D-libgdx-game-to-MonoGame)
