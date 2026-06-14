---
title: DirectX
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Libraries
  href: Technologies/Libraries/index.html
- label: DirectX
  href: Technologies/Libraries/DirectX/index.html
subpages:
- label: Go Up
  href: Technologies/Libraries/index.html
---

DirectX is a collection of application programming interfaces (APIs) developed by Microsoft. It is designed to handle tasks related to multimedia, especially game programming and video, on Microsoft platforms. DirectX enables software developers to create high-performance applications, such as video games, that can utilize advanced graphics and sound capabilities.

## Introduction

### History

DirectX was originally called Game SDK and was later renamed to DirectX, because Microsoft was naming their technologies with an X at the end. <br> DirectX was introduced by Microsoft in the Fall of 1995.

### DirectX 3 components

DirectDraw, DirectSound, DirectPlay, DirectInput, Direct3D and DirectSetup.

### DirectDraw

Provides ultra-fast access to video hardware. <br> Used for rendering 2D graphics. <br> Now largely replaced by Direct3D.

### DirectSound

Provides tools for playing and manipulating sound effects and music.

### DirectPlay

Direct Play is a deprecated component of DirectX used for the multiplayer modes of games. It provides the possibilities of communication like over the Internet or the local network. <br> Multi-player games over a network or the Internet. <br> Offers networking capabilities for multiplayer games (over the Internet or local network). It is now deprecated.

### DirectInput

Handles input devices like keyboards, mice, joysticks and game controllers.

### Direct3D

Handles 3D graphics rendering. <br> A core part of modern game development for rendering complex scenes and visual effects.

### DirectSetup

Automatic installing the DirectX components on the user's system.

### Other possibilities for games writtten in Direct X

- Windows built-in user interface
- Windows API

## Importance of DirectX

- **Performance**: It provides low-level access to hardware, allowing developers to optimize their applications for better performance.
- **Hardware Compatibility**: DirectX acts as a bridge between software and hardware, ensuring compatibility across different graphics cards, sound cards, and other hardware components.
- **Graphics and Gaming**: DirectX has been instrumental in the growth of PC gaming, enabling realistic visuals, advanced effects, and immersive environments.

## Comparison of DirectX 3 and DirectX 5

DirectX 3 and DirectX 5 represent two different versions of Microsoft's DirectX API, used for multimedia and game development. Here's a breakdown of the differences between them:

### Release Date:

**DirectX 3:** Released in 1996. <br> **DirectX 5:** Released in 1997.

### Feature Enhancements:

#### DirectX 3:

Introduced basic 3D graphics rendering capabilities. <br> Supported DirectDraw, DirectSound, and DirectInput for handling 2D graphics, sound, and input devices. <br> Limited hardware acceleration for 3D rendering, as most early 3D graphics cards were still emerging.

#### DirectX 5:

Improved 3D acceleration support compared to DirectX 3. <br> Introduced better support for more advanced 3D rendering techniques such as texture mapping, alpha blending, and more efficient handling of 3D polygons. <br> Enhanced Direct3D with new features like fog effects, specular lighting, and z-buffering. <br> Improved support for multiple input devices and sound.

### DirectSound:

#### DirectX 3:

DirectSound provided basic audio capabilities, including simple playback of audio files and the ability to manage multiple sound buffers.

#### DirectX 5:

Improved audio management, allowing for more sophisticated mixing of sounds. <br> Added better support for environmental audio effects (like echo and reverb) and positional audio, which could improve immersion for games or multimedia applications using stereo or multi-channel sound setups.

### DirectDraw (2D Graphics):

#### DirectX 3:

DirectDraw allowed developers to directly manipulate video memory for 2D rendering. It supported basic 2D operations such as blitting (bit block transfer), page flipping, and surface creation.

#### DirectX 5:

Enhanced performance for 2D operations and better management of video memory. <br> Added improved support for hardware-accelerated blitting and stretching, which could boost the performance of 2D games or multimedia applications. <br> Improved support for higher resolutions and color depths, benefiting 2D graphics.

### DirectInput:

#### DirectX 3:

Provided basic support for handling input devices like keyboards, mice, and joysticks. The input system was straightforward but lacked advanced features for more complex control schemes.

#### DirectX 5:

Expanded support for additional input devices and improved responsiveness. <br> Added support for more complex input configurations, allowing developers to manage multiple input devices simultaneously or use more advanced control schemes (e.g., force feedback for joysticks).

### Performance and Stability:

#### DirectX 3:

While functional, the APIs were not as optimized, and performance could be limited, especially on lower-end systems.

#### DirectX 5:

More optimizations across the API, leading to better performance in handling sound, input, and 2D graphics. <br> Improved stability, with bug fixes and enhancements that made it a more reliable API for developers to work with.

### Developer Tools and Documentation:

#### DirectX 3:

Basic tools and documentation, but there were fewer resources for developers.

#### DirectX 5:

Improved developer tools, including better debugging and profiling capabilities. <br> More comprehensive documentation, making it easier for developers to adopt DirectX and improve the quality of their multimedia applications.

### Direct3D (3D Rendering):

#### DirectX 3:

Direct3D was still quite primitive, with limited support for complex rendering techniques. It was mainly used in early 3D games and simulations, and developers had to work around its limitations.

#### DirectX 5:

Direct3D saw significant improvements, with more robust support for real-time 3D rendering, making it more suitable for 3D gaming. It began to take advantage of new hardware features, which was crucial for better performance and visual effects in games.

### Compatibility and Hardware Support:

#### DirectX 3:

Compatible with early 3D hardware but didn’t fully utilize the capabilities of more advanced graphics cards.

#### DirectX 5:

Provided better hardware support and could tap into the growing market of more powerful GPUs like the 3dfx Voodoo series, ATI Rage, and NVIDIA Riva cards, allowing developers to take advantage of better graphics performance.

### Adoption and Impact:

In summary, **DirectX 5** brought substantial improvements over **DirectX 3**, particularly in 3D graphics rendering and hardware acceleration, which made it much more suitable for the growing demands of the gaming industry at the time.

#### DirectX 3:

Was foundational in establishing DirectX as a standard for game development on Windows, but it was still limited in terms of features and performance.

#### DirectX 5:

Became more widely adopted, with many games developed specifically for this version. It marked the beginning of more visually impressive PC games due to improved 3D support and hardware acceleration.

### Summary:

The differences between **DirectX 3** and **DirectX 5** (without 3D focus) include improvements in sound (DirectSound), better performance for 2D graphics (DirectDraw), enhanced input device handling (DirectInput), and overall optimizations that resulted in better performance, stability, and developer support.

## Basics

### Pixel

The graphics shown by the monitor consists of pixels. <br> Pixel is the smallest are on the screen, that can be set to a specific color. <br> So, monitor consists of grids, where each cell is the pixel. <br> One pixel is obviously stored in the computer as one, two, three or four bytes of memory.

## Books

### DirectX Complete

Root, Michael D 1998

### Win32 Game Developers Guide With Directx 3

https://archive.org/details/win32gamedevelop0000kolb <br> https://www.worldofbooks.com/en-gb/products/directx-3-developer-s-guide-book-keith-weiner-9781571690302 <br> https://books.google.pl/books/about/Win32_Game_Developer_s_Guide_with_Direct.html?id=ZHEMAAAACAAJ&redir_esc=y <br> https://www.abebooks.com/9781571690302/Win32-Game-Developers-Guide-Directx-1571690301/plp <br> https://www.amazon.com/Win32-Game-Developers-Guide-Directx/dp/1571690301

### Inside DirectX

Author: Brett R. Moffett <br> https://archive.org/details/insidedirectx0000barg/page/n583/mode/2up <br> https://www.abebooks.com/servlet/BookDetailsPL?bi=31432713024&cm_sp=SEARCHREC-_-WIDGET-L-_-BDP-R&searchurl=ds%3D30%26rollup%3Don%26sortby%3D17%26tn%3Ddirectx <br> https://www.ebay.co.uk/itm/304264612255 <br> https://www.amazon.com/Inside-DirectX-Microsoft-Programming-Bradley/dp/1572316969/

### Tricks of the Windows Game Programming Gurus

Author: André LaMothe <br> https://theswissbay.ch/pdf/Gentoomen%20Library/Game%20Development/Programming/Tricks%20of%20the%20Windows%20Game%20Programming%20Gurus%20-%20Fundamentals%20of%202D%20and%203D%20Game%20Programming.pdf <br> https://archive.org/details/tricksofwindowsg00lamo <br> https://www.amazon.com/Tricks-Windows-Game-Programming-Gurus/dp/0672313618

### Windows Game Programming for Dummies

Author: André LaMothe <br> https://archive.org/details/windowsgameprog000lamo

### The Zen of Direct3D Game Programming

This book target DirectX7, but it also covers the DirectX basics, which are useful also understand the later versions <br> Author: Peter Walsh

### High perfomance Windows graphics programming : create fast graphics with DirectDraw

Author: Trujillo, Stan <br> https://archive.org/details/highperfomancewi0000truj

### DirectDraw Programming (1996)

https://archive.org/details/direct-draw-programming-1996

## External links

http://www.directxtutorial.com/ <br> https://library.thedatadungeon.com/ <br> https://web.archive.org/web/20050212092634/http://www.geocities.com/SiliconValley/Way/3390/
