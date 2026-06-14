---
title: Goals
breadcrumb:
- label: About
  href: About/index.html
subpages:
- label: Go Up
  href: About/index.html
- label: Sound
  href: About/Goals/Sound/index.html
---

## Create documentation for Speedy Blupi (Epsitec)

Create ultimate specification of [Speedy Blupi](Blupi/Games/Speedy_Blupi_(Windows)/index.html)/[Eggbert](Blupi/Games/Speedy_Eggbert/index.html) games and its related utilities

- This specification should be as sufficient as possible to recreate these games.
- This specification should completely include all the details related to technical information for [graphics](Article_does_not_yet_exist_or_link_is_broken/index.html), [sounds](Article_does_not_yet_exist_or_link_is_broken/index.html), [cheats](Blupi/Games/Speedy_Blupi_(Windows)/Hacks/Cheats/index.html), hacks, [bugs](Blupi/Games/Speedy_Blupi_(Windows)/Bugs/index.html), behaviours.
- This includes also recording videos of the game play - representing various situations of [Blupi](Blupi/index.html) to preserve the rules, how the game works, for the future and also as the specification.
- Identify SB1 and SE1 screens and their buttons and other items on the screen
- Identify SB2 and SE2 screens and their buttons and other items on the screen
- Identify SB1 and SE1 sounds
- Identify SB2 and SE2 sounds
- Identify SB1 and SE1 music
- Identify SB2 and SE2 music
- Describe the custom made save format (BLP files)
- Describe the custom made user info format (BLP files)
- Describe the custom made demo format (BLP files)
- Document mods for Speedy Blupi/Eggbert games (record videos, describe levels, describe modded graphics/music/sounds)
- Record videos playing SB/SE 1/2 (all possible situations) and save them to Open Eggbert channel and videos.openeggbert.com

## Create documentation for Speedy Blupi (DadaGames)

Create ultimate specification of Speedy Blupi for Windows Phone released in 2013.

- This includes also recording the game play to videos.

## Decompilation of Speedy Blupi (Epsitec)

[Decompilation](Technologies/Other/Reverse_engineering/index.html) of Speedy Blupi/Eggbert for [Windows](Technologies/Platforms/Windows/index.html). Then port it to [SDL 3](Article_does_not_yet_exist_or_link_is_broken/index.html) and make it portable.

- [C++](Technologies/Programming_languages/C++/index.html), [DirectX](Technologies/Libraries/DirectX/index.html) 3/5, [Ghidra](Article_does_not_yet_exist_or_link_is_broken/index.html), [IDA](Article_does_not_yet_exist_or_link_is_broken/index.html), [x86](Technologies/Programming_languages/Assembly_Language/X86_instruction_set/index.html) [assembly](Technologies/Programming_languages/Assembly_Language/index.html) language, SDL 3
- https://github.com/HMVocaloid/Speedy-Eggbert-2-Source-Code-Decomp

## Archive of all Speedy Blupi/Eggbert related websites on the Internet

- [Webs related to Speedy Blupi](Article_does_not_yet_exist_or_link_is_broken/index.html)
- https://archive.openeggbert.com/main

## Store the Speedy Blupi/Eggbert related files at drive.openeggbert.com

## Collect videos on the Youtube

- https://youtube.openeggbert.com
- https://github.com/openeggbert/youtubedl-frontend

## Create new game assets

### Music

music ([MIDI](Article_does_not_yet_exist_or_link_is_broken/index.html) or [OGA](Article_does_not_yet_exist_or_link_is_broken/index.html)). [Microsoft Music Producer](Technologies/Applications/Microsoft_Music_Producer/index.html) may be used

### Sounds

sounds ([WAV](Article_does_not_yet_exist_or_link_is_broken/index.html) or [OGA](Article_does_not_yet_exist_or_link_is_broken/index.html))

### Images

images ([BMP](Article_does_not_yet_exist_or_link_is_broken/index.html) or [PNG](Article_does_not_yet_exist_or_link_is_broken/index.html)). [Blender](Technologies/Applications/Blender/index.html) may be used. ''[Inkscape](Article_does_not_yet_exist_or_link_is_broken/index.html) and [Gimp](Article_does_not_yet_exist_or_link_is_broken/index.html) may not be used.

- Goal is to create the completely new graphic. Possible applications to be used for this task are Gimp, Inkscape, Blender and others
  - 3D models will be used to create the new prerendered sprites
  - Game resolution will be 640*480 or 1280*960 (or another technical solution - to be discussed)

## Tasks

- Repack rar files (like mods) to something better (zip?)

## TODO

```

Project A: CATCH: Collect all knowledge related to the Speedy Blupi game engine found on the Internet
Project B: SPECIFY: Create the ultimate specification of Speedy Blupi game engine and its related games, utilities, etc.
Project C: REMAKE: Reimplement the origin Speedy Blupi game engine
Project D: FREE IMAGES: Create free replacements of game images - Vector graphics - with Inkscape or an alternative - format BMP or PNG or JPEG
Project E: FREE SPRITES: Create free replacements of game sprites - 3D graphics - with Blender or an alternative - format BMP or PNG or JPEG
Project F: FREE MUSIC: Create free replacements of game music - format MP3 or OGG
Project G: FREE SOUNDS: Create free replacements of game sounds - format WAV or OGG
Project H: OPEN EGGBERT 3: Propose and implement new features with comparison to the Speedy Blupi game engine
Project I: ANALYSE: Analyse and document all the knowledge related to the Speedy Blupi game engine
Project J: STORE: Implement modding system and Open Eggbert Store - web application
Project K: MODS: Document mods for Speedy Blupi/Eggbert games (record videos, decribe levels, describe modded graphics/music/sounds
Project L: EXE: Reverse engineer the EXE files of Speedy Blupi/Eggbert game engines
Project M: PLUS: Decompile the C++ source code of Speedy Blupi/Eggbert
Project N: XAP: Reverse engineer the XAP file of Speedy Blupi for Windows Phone released in 2013
Project O: INFRA: Infrastructure
```

## Other

It should be the goal to create the ultimate specification of Speedy Blupi/Eggbert demo/1/2. This means described in the details the behaviour, record videos involving various situations in these games.

Speedy Blupi released in 2013 for the Windows Phone is intended only as the inspiration for new Open Eggbert features, but should be described too.

### The recommended way to record Speedy Blupi/Eggbert or Open Eggbert on Linux

**Simple Screen Recorder:**

- Recored a fixed rectangle
- Left: 0 Top: 0 Width: 640 Height: 480
- Frame rate: 60
- Enable "Record cursor"
- Enable "Record audio", Backend: PulseAudio
- Container: WEBM
- Video: Codec: VP8
- Video: Disable "Allow frame skipping"
- Audio Codec: Vorbis

### How to find out the sprite positions in BMP files

Use:

- [https://github.com/openeggbert/sprite-utils](https://github.com/openeggbert/sprite-utils)
- Zoom screen in the operating system
- Verify, that the positions are correct, use Pause key to pause the game play, modify file DATA/CONFIG.DEF and set Timer to the value like 400 ms
