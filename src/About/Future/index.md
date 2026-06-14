---
title: Future
breadcrumb:
- label: About
  href: About/index.html
subpages:
- label: Go Up
  href: About/index.html
---

As both the games [Speedy Blupi (Desktop)](Blupi/Games/Speedy_Blupi_(Windows)/index.html) and [Speedy Blupi (Phone)](Blupi/Games/Speedy_Blupi_(Windows_Phone)/index.html) are [closed-source](Article_does_not_yet_exist_or_link_is_broken/index.html) and with [proprietary](Article_does_not_yet_exist_or_link_is_broken/index.html) dependencies, the goal for the future should be to completely port these games to their [open-source](Article_does_not_yet_exist_or_link_is_broken/index.html) alternatives and at the best also to decompile these original games.

- Free and open source technologies should be used to keep these games running on the future operating systems.

Old versions of [Visual Studio](Article_does_not_yet_exist_or_link_is_broken/index.html), [DirectX](Technologies/Libraries/DirectX/index.html) 3, [Direct Play](Article_does_not_yet_exist_or_link_is_broken/index.html), [Windows Phone](Technologies/Platforms/Windows_Phone/index.html) emulators and others may not be supported on the future versions of the [Windows](Technologies/Platforms/Windows/index.html) operating systems.

Free replacements are: [SDL](Technologies/Libraries/SDL/index.html)

## Speedy Blupi (Desktop)

The support of future versions of [Windows](Technologies/Platforms/Windows/index.html) (maybe Windows 12, 13, 14, ...) to run [Speedy Blupi](Blupi/Games/Speedy_Blupi_(Windows)/index.html) I/II is uncertain.

It should be the key goal for us to constantly ensure, that:

- The latest version of [Wine](Technologies/Other/Wine/index.html) project will still support the run of Speedy Blupi I/II - at least until the moment, the complete specification of Speedy Blupi I/II will be completed. This complete specification is necessary to develop [Open Eggbert](About/index.html) - the free and open source recreation of Speedy Blupi I/II. There should be recorded as much as possible or gameplay videos for various situations in the game. It would be also good to record on the screen some visualization of the pressed keys.

[Wine](Technologies/Other/Wine/index.html) is developed in the [C](Article_does_not_yet_exist_or_link_is_broken/index.html) [programming language](Technologies/Programming_languages/index.html).

See: [https://www.winehq.org/](https://www.winehq.org/)

Fortunately, there is ongoing work on the [decompilation](Technologies/Other/Reverse_engineering/index.html) of *[Speedy Eggbert](Blupi/Games/Speedy_Eggbert/index.html) II*. This can later be used as the engine for all the desktop versions of the game. GitHub repository: [https://github.com/jummy0/sb2-decomp](https://github.com/jummy0/sb2-decomp)

Risk: [X86S](Article_does_not_yet_exist_or_link_is_broken/index.html) was the new x86-64 architecture, where the 16-bit and 32-bit support was removed. X86S was cancelled by Intel in December 2024.

## Speedy Blupi (Phone)

Regarding Speedy Blupi ([Windows Phone](Technologies/Platforms/Windows_Phone/index.html)), it is now not possible to run Windows Phone [XAP](Article_does_not_yet_exist_or_link_is_broken/index.html) executable files on [Linux](Technologies/Platforms/Linux/index.html).

- It seems, that no such support will exist in the future, as the Windows Phone is a discontinued platform.

It should be the goal for us to document new features and differences (to desktop version) of Speedy Blupi (Windows Phone), but also record videos of playing Speedy Blupi (Windows Phone) via "Project My Screen App for Windows Phone" [https://www.microsoft.com/en-us/download/details.aspx?id=42536](https://www.microsoft.com/en-us/download/details.aspx?id=42536)

## What programming languages and libraries to use for the next decades

Good candidates: Java, C#, C++

Bad candidates: Node.js.

The goal should be to make both Speedy Blupi for Windows and Windows Phone sustainable and easy to run (even in the future)

We should focus on technologies that have a large community and are open, with well-documented tools. Both options, C++ with SDL2 and Java with LibGDX, have their advantages, but here are a few factors that can help us decide.

As few dependencies on specific libraries as possible should be used.

Dependencies, that could become obsolete over time, should be minimized.
