---
title: Free Eggbert
breadcrumb:
- label: Projects
  href: Projects/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">Free Eggbert</th>
</tr>
<tr>
<th>Licence</th>
<td>GPLv3 or later</td>
</tr>
<tr>
<th>Programming language</th>
<td>C++</td>
</tr>
<tr>
<th>Used Libraries</th>
<td>DirectX, WineLib, FreeDirect, SDL 3</td>
</tr>
<tr>
<th>Project launched</th>
<td>Spring 2024</td>
</tr>
<tr>
<th>Released date</th>
<td> Not yet release</td>
</tr>
<tr>
<th>Development status</th>
<td>Decompilation of EXE files</td>
</tr>
</table>

Free Eggbert is the revival of the computer games Speedy Blupi demo/1/2 and Speedy Eggbert demo/1/2. <br> <br> Free Eggbert is the [decompilation](Technologies/Other/Reverse_engineering/index.html) of these games using tools like Ghidra and IDA. It's free and open-source.

- Reverse engineering and knowledge of X86 assembly is used.

## Origin

Probably in [2024](Article_does_not_yet_exist_or_link_is_broken/index.html) [HMVocaloid](Article_does_not_yet_exist_or_link_is_broken/index.html) started the decompilation of the [EXE](Technologies/Platforms/Windows/EXE/index.html) files of the game Speedy Eggbert 2. <br> The source code of the game [Planet Blupi](Blupi/Games/Planet_Blupi/index.html) was used, because [Speedy Blupi](Blupi/Games/Speedy_Blupi_(Windows)/index.html) I is the [fork](Article_does_not_yet_exist_or_link_is_broken/index.html) of Planet Blupi. Speedy Blupi II is the fork of Speedy Blupi I. <br> Source code of Planet Blupi was published in 2017. <br> [Ghidra](Article_does_not_yet_exist_or_link_is_broken/index.html), the decompilation tool, was used too. <br> Later, [jummy0](Article_does_not_yet_exist_or_link_is_broken/index.html) joined this decompilation project. Latest commits published by jummy0 are in December 2024.

- Based on information on Discord it seems, that jummy0 lost his files related to the decompilation. This means broken, lost or stolen computer.

## Repositories

- [https://github.com/HMVocaloid/Speedy-Eggbert-2-Source-Code-Decomp](https://github.com/HMVocaloid/Speedy-Eggbert-2-Source-Code-Decomp)
- [https://github.com/jummy0/sb2-decomp](https://github.com/jummy0/sb2-decomp)
- [https://github.com/openeggbert/sb2-decomp](https://github.com/openeggbert/sb2-decomp)

## Why the decompilation started

- Both the games Speedy Blupi I and Speedy Blupi II are closed-source.
- Modifications of Speedy Blupi are possible only by hex editing of the EXE files
- Bugs in Speedy Blupi cannot be fixed
- Existing features of Speedy Blupi cannot be improved
- New features cannot be added to Speedy Blupi

## Compilation options

Compilation option: represents set of features, which are supported by the generated executable file.

- Speedy Blupi Demo
- Speedy Blupi I
- Speedy Blupi II
- Speedy Eggbert Demo
- Speedy Eggbert VALUEWARE
- Speedy Eggbert 1
- Speedy Eggbert 2
- Free Eggbert 3 - new features, which are not available in the original games developed by Daniel Roux

## Legacy mode

If legacy mode is enabled in [CONFIG.DEF](Blupi/Games/Speedy_Blupi_(Windows)/CONFIG.DEF/index.html), then the game will behave as much as possible as the original games developed by Daniel Roux. <br> If legacy mode is disabled, then all the game new features, graphics, sounds, music, etc. of the game will be present and activated <br> The third possibility is to set the value of LegacyMode, which contains comma separated list of the game only features, which will be additionally activated and supported. This means, that Legacy mode is enabled, but some new features are activated. <br> For example disable cheat, even the game behaves like Speedy Eggbert I

## Future

Free Eggbert will be one computer game, which will be able to be behave like one of these games Speedy Blupi/Eggbert I/II/1/2. <br> There will be created a DirectX 3 implementation based on SDL 3 named Free Direct.

- SDL 3 supoprts many platforms like Windows, Linux, MacOS, Android, iPhone, Web and others

Windows API will be replaced by Free API, which will be partial reimplementation of Windows API.

## Game space (proposal)

Game space is a directory with the defined structure. <br> Player has one or more game spaces. <br> Each game space has a feature level. <br> Game space can be cloned. You can have several game spaces with the same Feature level.

## Source code

```

        action.h
        actions.h
        blupi.cpp

        int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
        This is the entry point for whole game and is the part of the Windows API.
        Its goals: Initialize the game, do the benchmark, set the timer, launch the game loop

        static BOOL DoInit(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow)
        Reads the config file (config.def)
        Creates the window or fullscreen
        Set the cursor to the type: WAIT
        Create objects

        button.cpp
        button.h
        cursor1.cur
        ddraw.h
        ddutil.cpp
        ddutil.h
        decblupi.cpp
        decmove.h
        decor.cpp
        decor.h
        dectables.cpp
        dectables.h
        def.h
        dplay.h
        dsound.h
        event.cpp
        event.h
        fifo.h
        jauge.cpp
        jauge.h
        menu.cpp
        menu.h
        misc.cpp
        misc.h
        movie.cpp
        movie.h
        network.cpp
        network.h
        ping.asm
        pixmap.cpp
        pixmap.h
        resource.h
        resource1.h
        sound.cpp
        sound.h
        text.cpp
        text.h
        texttables.h
        wave.cpp
        wave.h
```
