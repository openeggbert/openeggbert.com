---
title: Troubleshooting
breadcrumb:
- label: Blupi
  href: Blupi/index.html
- label: Games
  href: Blupi/Games/index.html
- label: Speedy Blupi (Windows)
  href: Blupi/Games/Speedy_Blupi_(Windows)/index.html
- label: Troubleshooting
  href: Blupi/Games/Speedy_Blupi_(Windows)/Troubleshooting/index.html
subpages:
- label: Go Up
  href: Blupi/Games/Speedy_Blupi_(Windows)/index.html
---

## Windows (operating system)

Both

[Speedy Blupi](Blupi/Games/Speedy_Blupi_(Windows)/index.html)

I/II and

[Speedy Eggbert](Blupi/Games/Speedy_Eggbert/index.html)

1/2 work on the operating system

[Windows 95](Technologies/Platforms/Windows/Windows_95/index.html)

or later, even including the latest

[Windows 11](Article_does_not_yet_exist_or_link_is_broken/index.html)

.

### DirectPlay is missing

Solution: Install

[DirectPlay](Article_does_not_yet_exist_or_link_is_broken/index.html)

<br>

*DirectPlay is an outdated component that is disabled by default on modern [Windows](Technologies/Platforms/Windows/index.html) systems.*

<br>

*Although DirectPlay is not required for single-player mode, it is necessary for multiplayer functionality. However, having DirectPlay disabled might occasionally cause issues when launching the game.*

<br>

Other issues can be caused by the Antivirus. Or try to change the compatibility mode.

### Blue boxes shown, if launched in windowed mode on Windows operating system

Right-click the game's

[EXE](Article_does_not_yet_exist_or_link_is_broken/index.html)

file and select "Properties".  Go to the Compatibility tab, check "Reduced color mode", and select "16-bit (65536) color".

### DxWnd

[DxWnd](Article_does_not_yet_exist_or_link_is_broken/index.html)

is a Windows hooker intercepts system calls to allow

[Win32](Article_does_not_yet_exist_or_link_is_broken/index.html)

programs to operate within a window. This tool enhances application compatibility, improves video modes, adjusts timing, and emulates CD data and audio tracks. It is particularly useful for running older Windows games.

<br>

[https://sourceforge.net/projects/dxwnd/](https://sourceforge.net/projects/dxwnd/)

### Windowed mode has wrong height  477 instead of the correct one 480

**Wrong resolution:**

640x477

<br>

**Correct resolution:**

640x480

<br>

This bug causes also the strange distortion around the mouse cursor.

<br>

**How to fix:**

Open the EXE file in hex editor, search for the hex bytes

`8d 81 20 fe ff ff`

and replace the

`20`

with

`1d`

. then search for

`8d 81 e0 01 00 00`

and replace the

`e0`

with

`e3`

. This makes the window 3 pixels taller

## Linux (operating system)

### How to run on Linux

Use Wine:

[https://www.winehq.org/](https://www.winehq.org/)

<br>

There are some issues, when you run the Windows version of Speedy Blupi/Eggbert on

[Linux](Technologies/Platforms/Linux/index.html)

via

[Wine](Article_does_not_yet_exist_or_link_is_broken/index.html)

.

### How to run on Linux

Use Windows 95 or

[Windows 98](Article_does_not_yet_exist_or_link_is_broken/index.html)

and

[DOSBox](Article_does_not_yet_exist_or_link_is_broken/index.html)

and

[RetroArch](Article_does_not_yet_exist_or_link_is_broken/index.html)

<a class="ref" href="https://www.youtube.com/watch?v=9xynDgexf5Y">https://www.youtube.com/watch?v=9xynDgexf5Y</a>

<a class="ref" href="https://www.retroarch.com/">https://www.retroarch.com/</a>

<a class="ref" href="https://www.libretro.com/">https://www.libretro.com/</a>

### Background music does not work in Wine

Wine usually outpus this error:

<br>

`0194:err:winediag:MIDIMAP_drvOpen No software synthesizer midi port found, Midi sound output probably won't work.`

#### How to fix it:

1. install [fluidsynth](Article_does_not_yet_exist_or_link_is_broken/index.html) *(for Debian: apt install fluidsynth)*
2. Download a sound font and place it somewhere you like. Examples:
  - Windows General [MIDI](Article_does_not_yet_exist_or_link_is_broken/index.html) [soundfont](Article_does_not_yet_exist_or_link_is_broken/index.html)
    - [https://drive.openeggbert.com/Speedy_Blupi/Troubleshooting/Default_Windows_MIDI_Soundfont/gm.sf2](https://drive.openeggbert.com/Speedy_Blupi/Troubleshooting/Default_Windows_MIDI_Soundfont/gm.sf2) <a class="ref" href="https://musical-artifacts.com/artifacts/713">https://musical-artifacts.com/artifacts/713</a>
  - http://www.vogonsdrivers.com/getfile.php?fileid=500
3. Run:  `fluidsynth -a pulseaudio /path/to/soundfont`
  - Add an `&` at the end, if you want to run it in the background. Or you can configure its autostart at the boot

*Note: Sound game effects works. Format for sound is [WAV](Article_does_not_yet_exist_or_link_is_broken/index.html). Format for background music is MIDI.*

### Multiplayer mode does not work in Wine

#### How to fix it:

Install directplay:

`winetricks directplay`

(Successfully tested)

<br>

https://github.com/RazZziel/wine-dplay

<br>

https://github.com/solemnwarning/ipxwrapper

### Saving custom levels to XCH files does not work in Wine

### Loading custom levels from XCH files does not work in Wine

### Blue boxes shown, if launched in windowed mode on Linux via Wine

Maybe several different solutions exist, one of the is:

> apt install xserver-xephyr
>         
> 
> <br>
> 
> 
>         #Working on LXQT:
>         
> 
> <br>
> 
> 
>         Xephyr :1 -ac -screen 800x600x16 & DISPLAY=:1 xfwm4 & DISPLAY=:1 wine egames.exe

See more at: https://wiki.winehq.org/256_Color_Mode

### Play MIDI on Linux (stub)

https://www.reddit.com/r/linuxquestions/comments/x91k5c/simple_midi_player_on_linux/

<br>

`timidity`

## Other operating systems

### How to run on Android

External link: https://www.reddit.com/r/EmulationOnAndroid/

<br>

Use one of these:

1. [ExaGear](Article_does_not_yet_exist_or_link_is_broken/index.html) <a class="ref" href="https://www.reddit.com/r/EmulationOnAndroid/comments/8c5c6p/classic_pc_game_speedy_eggbert_works_on_android/">https://www.reddit.com/r/EmulationOnAndroid/comments/8c5c6p/classic_pc_game_speedy_eggbert_works_on_android/</a><a class="ref" href="https://www.exagear.wiki/index.php?title=Installation_instructions">https://www.exagear.wiki/index.php?title=Installation_instructions</a>
  - [https://drive.openeggbert.com/Speedy_Blupi/Screenshots/Android/speedy_blupi_on_android_via_exagear.webp](https://drive.openeggbert.com/Speedy_Blupi/Screenshots/Android/speedy_blupi_on_android_via_exagear.webp)
2. [Winlator](Article_does_not_yet_exist_or_link_is_broken/index.html)
3. [Limbo PC Emulator](Article_does_not_yet_exist_or_link_is_broken/index.html) with Windows 95 or later operating system installed

[Gamepad](Article_does_not_yet_exist_or_link_is_broken/index.html)

can be simulated by:

[GameKeyboard +](Article_does_not_yet_exist_or_link_is_broken/index.html)

<a class="ref" href="https://play.google.com/store/apps/details?id=com.locnet.gamekeyboard2">https://play.google.com/store/apps/details?id=com.locnet.gamekeyboard2</a>

### How to run on Raspberry Pi

Not yet tested: https://github.com/ryanfortner/exagear-rpi

<br>

Not yet tested: https://box86.org/

<a class="ref" href="https://www.youtube.com/watch?v=OT17OQNiGcA">https://www.youtube.com/watch?v=OT17OQNiGcA</a>

### How to run on ReactOS

[ReactOS](Article_does_not_yet_exist_or_link_is_broken/index.html)

is a

[free](Article_does_not_yet_exist_or_link_is_broken/index.html)

and

[open-source](Article_does_not_yet_exist_or_link_is_broken/index.html)

operating system for

[i586](Article_does_not_yet_exist_or_link_is_broken/index.html)

/

[amd64](Article_does_not_yet_exist_or_link_is_broken/index.html)

personal computers intended to be binary-compatible with computer programs and device drivers developed for Windows Server 2003 and later versions of

[Microsoft](Article_does_not_yet_exist_or_link_is_broken/index.html)

[Windows](Technologies/Platforms/Windows/index.html)

.

<a class="ref" href="https://reactos.org/">https://reactos.org/</a>

<br>

Speedy Blupi/Eggbert runs on React OS in "Limbo PC Emulator" on Android

**without issues**

<br>

Speedy Blupi/Eggbert runs on React OS in

[VirtualBox](Article_does_not_yet_exist_or_link_is_broken/index.html)

**with issues:**

Blupi/Eggbert is moving left or right even in case, no key is pressed, until the top arrow key is pressed. But gameplay is possible, if you consider this issue.

### How to run in browser

**Warning:**

Speedy Eggbert (Blupi maybe too) can be run via

[Boxed Wine](Article_does_not_yet_exist_or_link_is_broken/index.html)

, but it is buggy, slow, with blue boxes around, sound is working, but is jerky, the game crashes very soon. How to fix this issues, was not yet investigated.

<br>

**Steps:**

1. Download BoxedWine for web (build-?.zip files):http://208.113.165.28:8080/job/Boxedwine/job/master/
2. Unzip the zip file, go to Web directory.
3. Download: https://sourceforge.net/projects/boxedwine/files/FileSystems/Full/v5/Debian10-Wine-5.0.zip/download
4. Delete boxedwine.zip in the Web directory
5. Rename file Debian10-Wine-5.0.zip to boxedwine.zip
6. Copy DirectX files from Speedy Eggbert 1 or 2 installation CD-Rom to the Speedy Eggbert 1 or 2 directory.
7. Zip Speedy Eggbert 1 or 2 directory
8. Modify test.html, replace ski32 by speedy eggbert 1 or 2.
9. Serve the directory locally: (Python3 or another tool) `python3 -m http.server 8000`

### How to run on Steam Deck

1. Open the file /DATA/Config.def with a text editor. Change line like `CD-Rom=V:\US` to `CD-Rom=-nocd`
2. Copy the installation directory on the Deck.
3. Create a "non-steam" shortcut on the deck and point it to BLUPI.EXE
4. Select the compatibility tab, check "Force compatibility layer" and select "Proton 7.0"
5. Add the following to "Launch options" on the shortcut: `PROTON_USE_WINED3D=1 PROTON_NO_ESYNC=1 PROTON_NO_FSYNC=1 %command% -nocd`
6. Switch back to gaming mode (if you were on desktop mode), make sure the controller profile is set to Keyboard + Mouse, launch it

Background music is not working. You can fix it by installing Qsynth and sound fonts.

<br>

<a class="ref" href="https://www.reddit.com/r/speedyeggbert/comments/ucddzf/peak_gaming_performance/">https://www.reddit.com/r/speedyeggbert/comments/ucddzf/peak_gaming_performance/</a>

<a class="ref" href="https://web.archive.org/web/20240709191020/https://www.reddit.com/r/speedyeggbert/comments/ucddzf/peak_gaming_performance/">https://web.archive.org/web/20240709191020/https://www.reddit.com/r/speedyeggbert/comments/ucddzf/peak_gaming_performance/</a>

<br>

https://drive.openeggbert.com/Speedy_Blupi/Screenshots/Steam_Deck/peak-gaming-performance-v0-apj3kg8qrvv81.png

## All operating systems

### Speedy Blupi game requires CD-ROM

''Note: Speedy Eggbert does not have these CD-ROM checks.''

        There are 3 possible ways to fix it:

1. Open the file{install dir}/DATA/Config.def with a text editor (like notepad, for example).
        #* Change line like **CD-Rom=V:\US** to **CD-Rom=-nocd**
2. Run the Blupi EXE file with the argument **-nocd**
3. Change offset **4f6**(for SB1) or **506** (for SB2) from **75** to **eb**

### Cannot change to 16 bit color depth in the Settings screen

Game considers your computer to be slow.

<br>

Solution: Edit the file data/config.def and set Benchmark=9999.

### Dummy DirectPlay - make the EXE files run without DirectX installed

https://github.com/CnCNet/dummy-dplayx

<br>

This was not yet tested. Investigation is needed.

<br>

This program behaves as a ''stub'' to DirectPlay, but that just stops errors and nothing else.

### How to upgrade the EXE files to DirectX 11/12

https://github.com/dege-diosg/dgVoodoo2/

### winevdm - to be investigated

https://github.com/otya128/winevdm

### Fix some compatibility and performance issues on modern DirectX versions, if exist

https://github.com/narzoul/DDrawCompat

### How the 3D models of Eggbert were created

This software was used:

**Ray Dream Studio**

<br>

http://www.win3x.org/win3board/viewtopic.php?t=13786\

### How to show keyboard and mouse presses in the realtime

Maybe this will work: https://github.com/Jax-Core/Keystrokes

### How to play multiplayer over Internet

Use Hamachi. Maybe an alternative exists

### How to enable the cheat-player

### How to create a replay

Conditions: cheat-player must be enabled

1. Open the player and take world 300 to 320 <a class="ref" href="https://www.youtube.com/watch?v=CclakPC0rxE">https://www.youtube.com/watch?v=CclakPC0rxE</a>
2. Delete the old level and create a new level or load another level
3. Play the level.
  - If you loose a life, the replay can have a mistake. This maybe impacts only version 2, because
                        there the death animation is not deterministic (2 Eggbert death animations exist) (Missing
                        reference, it needs to be added)

This is stub, extend this section (https://www.youtube.com/watch?v=CclakPC0rxE)
