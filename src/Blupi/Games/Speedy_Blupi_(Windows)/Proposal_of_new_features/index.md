---
title: Proposal of new features
breadcrumb:
- label: Blupi
  href: Blupi/index.html
- label: Games
  href: Blupi/Games/index.html
- label: Speedy Blupi (Windows)
  href: Blupi/Games/Speedy_Blupi_(Windows)/index.html
- label: Proposal of new features
  href: Blupi/Games/Speedy_Blupi_(Windows)/Proposal_of_new_features/index.html
subpages:
- label: Go Up
  href: Blupi/Games/Speedy_Blupi_(Windows)/index.html
---

## Recreation of game graphics

The [3D](Article_does_not_yet_exist_or_link_is_broken/index.html) editor [Blender](Article_does_not_yet_exist_or_link_is_broken/index.html) may be used to create the 3D models again and to render the [game](Article_does_not_yet_exist_or_link_is_broken/index.html) graphics again. <br> New game graphics will be double the size. <br> [Gimp](Article_does_not_yet_exist_or_link_is_broken/index.html) or [Inkscape](Article_does_not_yet_exist_or_link_is_broken/index.html) may be used too

## New types of transport

### Ship

### Submarine

- Allows Blupi to explore underwater areas.
- Equipped with torpedoes to destroy underwater obstacles or enemies.
- Can only stay underwater for a limited time before needing to surface for air.

### Bike

### Line skates

### Hot Air Balloon

- Blupi can navigate above levels, but it moves slowly and is affected by wind currents and fans.
- Players must use burners sparingly to control altitude, balancing fuel.

### Glider

- Lets Blupi glide from high places, useful for exploring or avoiding hazards below.
- Can catch air currents for extended gliding.

## Level editor improvements

Features will be inspired by X-Edit, X-Edit-Mapper, BlupiEdit and tiled-blupi

## New directory IMAGE

24 bit graphics (BMP or PNG)

## Support for the following image file extensions: BLP, BMP, PNG

## Support for the following image music extensions: BLP, MIDI, OGG, MP3

## Support for the following image sound extensions: BLP, WAV, OGG, MP3

## Support for text mods (translations/alternative texts)

## Wide screen

## Graphics resolution

Now the size of the block is 64x64 px. <br> But the block size could in the future also 128x128, 256x256 or 512x512 px. <br> Now in 2025 there are even monitors with this resolution: 7680x4320 <br> There is always the monitor height like this: 7 and a half of the block, which is theoretical block size 576x576 for monitor with resolution 7680x4320 <br> **Risks:** APK Android executable file has limit 150 MB for Google Play. Possible solution: Expansion files <br> Naming convention:

- blupi__frame1__256x256__32bit.png
- blupi__frame2__256x256__32bit.png
- blupi__frame3__256x256__32bit.png
- blupi__frame1__128x128__32bit.png
- blupi__frame2__128x128__32bit.png
- blupi__frame3__128x128__32bit.png
- blupi__frame1__64x64__32bit.png
- blupi__frame2__64x64__32bit.png
- blupi__frame3__64x64__32bit.png

### Resolution

Window or fullscreen resolution is: <br> For SBD, SB1, SB2, SED, SE1, SE2 the resolution is always: 640*480 (VGA)<br> <br> OE3 supports also the resolution: 1280 × 960 (QuadVGA)

## FPS

**Now:** The FPS is always 20 frames per second <br> **Future:** The FPS could be also 60 or 120, this means more sprites to be rendered <br> **Trends in FPS in the last decades:**

- **1980s–1990s:** 20–30 FPS was the norm on most gaming devices. <li> <b>2000s:</b> 60 FPS became the target for console and PC games. <li> <b>2010s–2020s:</b> 60 FPS is the norm, while 120 FPS and above are common on gaming monitors and esports devices. <li> <b>Future:</b> 240 Hz and 360 Hz refresh rate monitors exist, but are not widely used outside of specific gaming segments. </li></li></li>

### Ideas

- **Frames for Different FPS:**
  - **20 FPS (low performance, mobile devices):** Original graphics for 20 FPS (each frame is displayed for 50 ms).
  - **60 FPS (medium performance, standard PCs and mobile devices):** 3x more frames than at 20 FPS, meaning you need a new or interpolated frame for each frame to ensure smoother animation.
  - **120 FPS (higher performance, modern monitors and gaming PCs):** 2x more frames than at 60 FPS, ensuring even smoother animation and readiness for monitors with higher refresh rates.
- **Graphics Quality:**
  - **Low Quality (64x64 px textures):**
    - **For mobile devices and older PCs:** Lower resolution textures (64x64 px) help save space and ensure smooth performance on weaker devices.
    - **Mobile game version:** Optimized smaller textures load and render faster.
  - **Medium Quality (128x128 px textures):**
    - **For standard PCs and mid-range mobile devices:** A balanced compromise between quality and performance.
    - **Medium performance:** This texture size is ideal for devices with sufficient power to maintain a reasonable frame rate while offering better detail than 64x64 px.
  - **High Quality (256x256 px textures):**
    - **For modern gaming PCs and high-resolution monitors (e.g., 1080p or higher):** For higher FPS (60 FPS and 120 FPS), this texture size makes sense on more powerful devices.
    - **For maximum graphical detail:** If players choose high FPS and high-quality graphics, this texture size provides a better visual experience.
- **Recommended Combinations for Different Configurations:**
  - **For mobile devices (e.g., Android):**
    - **FPS:** 20 FPS or 60 FPS (for better performance on weaker devices).
    - **Textures:** 64x64 px to reduce memory and graphics demands.
  - **For standard PCs:**
    - **FPS:** 20 FPS or 60 FPS.
    - **Textures:** 128x128 px or 256x256 px (depending on PC performance).
  - **For modern gaming PCs (high performance):**
    - **FPS:** 60 FPS or 120 FPS.
    - **Textures:** 256x256 px for maximum quality on modern monitors.
- **Approach to Supporting Different Versions:**
  - **Optimization for various devices:** It’s best to adjust graphics and FPS based on a device’s capabilities. If someone has an older phone or PC, they should use 64x64 px textures and 20 FPS. On powerful machines with modern monitors and graphics cards, 256x256 px textures and 120 FPS will be preferred.
  - **For the future:** If you plan to support 120 FPS, ensure that your animations and textures are detailed enough to provide the best experience at higher FPS.

## New cheats

The screen height is always 7 and a half blocks (when not zoomed in).

## Improved multiplayer mode. More than 4 Eggberts in the multiplayer. And others.

## Some bugs in Speedy Blupi/Eggbert 1/2/I/II won't exist (Unfortunately some new unwanted bugs will be introduced)

## Support for mods - external directories or compressed archives with:

- worlds in directory data (mandatory)
- alternative graphics in directories IMAGES08 or IMAGES16 or IMAGE24 OR IMAGES16X2 OR IMAGES24X2 (optional)
- alternative WAV sounds in directory SOUND
- alternative MIDI music in directory SOUND

## Using artificial intelligence (AI)

Playing other players in the multiplayer. <br> AI controls Blupi and play the single game. <br> AI generates new worlds.

## World generator (using computer algorithm or artificial intelligence)

## World size could be also: width=200 height=200

## Infinite worlds - provided by the world generator

## Limits will be changed: size and object limit in levels.

This requires new file format - maybe EGT file name extension.

## Dream blocks will be back

## Possibility to forbid cheats

## Some ideas and features from Speedy Blupi for Windows Phone should also appear in the Open Eggbert

## Respawnable objects

## Another/custom water colors

## liana, ladder

## different types of bombs

## multi-station lifts with circle and shuttle mode - lifts with more than two checkpoints

## editing levels on the fly (during the gameplay)

## ice blocks, sliding ice blocks

## Mouse, key and touch presses can be shown in real time on screen

inspired by

```

        https://github.com/Jax-Core/Keystrokes
        https://gitlab.com/screenkey/screenkey
        https://linux.die.net/man/1/xev
        https://kbd-project.org/manpages/man1/showkey.1.html
        https://www.omgubuntu.co.uk/screenkey-show-key-presses-screen-ubuntu

```

## Editing CONFIG.DEF will be possible via a new graphical interface in the game.

## Switching between fullscreen and window modes without the requiring to exit the game and then start again.

## It will be possible to switch between game spaces without exiting the game and starting again.

## New ways of control of the game:

- white transparent buttons (similar to the Windows Phone version) on the touch screen
- accelerometer (similar to the Windows Phone version) - available only on the Android version'
- onscreen keyboard

## New keyboard shortcuts:

- F7: Speed 4x
- F8: Speed 8x

## Language localization.

Language can be switched during the game is running - without start. New language localizations can be created.

## Improve the Tutorial level. Inspire by Speedy Blupi for Windows Phone

## Wall climbing

## Sprinting - to avoid death by an enemy

## Secret Worlds

Hidden portals in levels that lead to challenging bonus worlds with high rewards.

## Magnet Blocks

- Blocks that attract or repel Blupi depending on their charge.
- Can be used for puzzles or navigating tricky areas.

## Ghost Blocks

Blocks that appear solid but vanish when Blupi approaches.

## Timed Blocks

Blocks that are visible only for a set time after being activated

## Magical Compass

Points towards hidden treasures or the exit in complex levels.

## Time Rewind Potion

Temporarily rewind time to correct mistakes or retry challenges.

## Sticky Shoes

Allows Blupi to walk on walls or ceilings for a limited time.

## Interactive scripting in the level editor

## Replay System

Players can record and share their gameplay or use replays to analyze strategies.

## Boss Levels

Large, multi-stage enemies at the end of each hub world.

## Flying Saucer

- A UFO-like vehicle that hovers above the ground, allowing for exploration of elevated areas.
- Can temporarily abduct enemies or objects to move them.

## Spider Bot

- A small, legged vehicle that can climb walls and ceilings.
- Ideal for navigating vertical or inverted terrains.

## Damage Resistance

Some vehicles could absorb a hit instead of Blupi losing a life.

## Gravity Flip Zones

Areas where gravity is reversed or altered, letting Blupi walk on ceilings or navigate zero-gravity sections.

## Teleport Beacon

Lets Blupi place a marker and return to that spot later.

## Easter Eggs

Fun references or hidden areas rewarding exploration and curiosity.

## More detailed pause menu with an overview map

Similar to Planet Blupi, the map would gradually uncover as the player moves through the world. This feature would be especially useful for navigating more complex, maze-like levels.

<figure>
<img src="https://drive.openeggbert.com/Blupi/Games/Speedy_Blupi_(Windows)/Proposal_of_new_features/More-detailed-pause-menu.jpg"/>
<figcaption>This is a mockup Source: Discord server "Blupi Games Fans" Author: jummy</figcaption>
</figure>

## Sound menu improvement

Sound or music can be disabled by 2 new buttons instead of clicking Volumn down many times

## To use artificial intelligence - AI plays Blupi, and other ideas

## Proposal of modding system for Open Eggbert

Open Eggbert Store will be involved too. <br> Similarly to Maven building system, every mod will be described in a xml file, but it will be packaged to a ZIP file ending with the extension ".egm" (like Open Eggbert mod). <br> *To Do: Update text string modding and translations, potentially adding support for additional languages. This will enhance the ability to modify the game beyond what’s possible with the original version, although it is also possible to modify the string texts within the original EXE files.*

<textarea cols="100" readonly="" rows="20" style="font-size: 125%;">
<?xml version="1.0" encoding="UTF-8"?>
        <mod>
   <modelversion>1.0.0</modelversion>
   <parent>
       <groupid>epsitec</groupid>
       <modid>legacy-blupi-1</modid>
       <version>1.0.0</version>
   </parent>
   <groupid>john-doe</groupid>
   <modid>legacy-blupi-1-with-minecraft-graphics</modid>
   <version>0.0.0-SNAPSHOT</version>
   <packaging>egm</packaging>
   <type>full</type><!-- level, sound, music, image8, image16, image24, image24x2, full, partial -->
   <featurelevel>SPEEDY_BLUPI_I</featurelevel><!-- enum FeatureLevel -->
   <name>legacy-blupi-1-with-minecraft-graphics</name>
   <description>legacy-blupi-1-with-minecraft-graphics</description>
   <imports>
       <import>
       <groupid>john-doe</groupid>
       <modid>image24x2-minecraft</modid>
       <version>1.0.0</version>
       </import>
   </imports>

   <files>
      <file>IMAGE16/info.blp</file>
   </files>
   
   <stores>
       <store>
           <id>releases</id>
           <name>john-doe-releases-store</name>
           <url><nowiki>https://john-doe-store.com/releases</nowiki></url>
       </store>
       <store>
           <id>snapshots</id>
           <name>john-doe-snapshots-store</name>
           <url><nowiki>https://john-doe-store.com/snapshots</nowiki></url>
       </store>
   </stores>
</mod>

</textarea>

## Open Eggbert Editor

Future Desktop application (C++, Qt). **Goals:**

- creating mods
- editing and analysing sprites and sprite sheets

## Game Space Selection

This is Open Eggbert only screen. <br> This is main screen for Open Eggbert. <br> But if Open Eggbert is launched in a legacy Speedy Blupi/Eggbert directory, then, the main screen for Open Eggbert is Init Screen. <br> This screen is not present in Speedy Blupi/Eggbert games. <br> As the default, the following game spaces exist:

- Speedy Blupi Demo
- Speedy Blupi I
- Speedy Blupi II
- Speedy Eggbert Demo
- Speedy Eggbert 1
- Speedy Eggbert 2
- Open Eggbert

You can create new Game Space using legacy assets (1998, 2002) or using game mods.
