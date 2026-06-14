---
title: Bugs
breadcrumb:
- label: Blupi
  href: Blupi/index.html
- label: Games
  href: Blupi/Games/index.html
- label: Speedy Blupi (Windows)
  href: Blupi/Games/Speedy_Blupi_(Windows)/index.html
- label: Bugs
  href: Blupi/Games/Speedy_Blupi_(Windows)/Bugs/index.html
subpages:
- label: Go Up
  href: Blupi/Games/Speedy_Blupi_(Windows)/index.html
---

A glitch is an unintentional mistake caused by some type of malfunction. <br> A bug is a noticeable flaw in the software that can be consistently reproduced. <br> Lag refers to a delay in the transmission of information.

## More players play a single player missions together

**How to reproduce:**

1. Player 1 saves the game during a multiplayer game by pressing F3 and loads with F4
2. Players 2, 3 and 4 do the same (Players 1, 2, 3 and 4 have to save and load the same level)
3. Players 1, 2, 3 and 4 can play a single player missions together. Goal and chests will be still in the single player level.

Since players don't share items, most levels become impossible to complete.

## Entity animation overflow glitch

The **animation overflow glitch** is affecting all known versions of Speedy Blupi/Eggbert I/II/1/2. [https://speedy-blupi.fandom.com/wiki/Animation_overflow_glitch](https://speedy-blupi.fandom.com/wiki/Animation_overflow_glitch)

- The severity of the impact varies across the versions.

In Speedy Blupi I this glitch causes graphical corruption on many entities.

- This glitch was almost entirely fixed in Speedy Blupi II

This glitch happens when a level is played for an extended period of time.

### How to reproduce

Dynamic entities have an animation counter, this counter uses 16-bit signed integer.

- 16-bit signed integer has range of -32768 through +32767.

Many of these counters start at 0 and increment every frame.

- This means, that after passing 32768 frames an integer overflow happens

The default count of frames per second is 20, in this case it takes 27 minutes and 18.4 seconds of in-game time to reach overflow, or 13 minutes and 39.2 seconds when in double speed mode.

- When this overflow happens, then the animation counter gains a negative value (-32768).

This bug was mostly resolved in the sequel.

### Fix

This glitch was mostly fixed in Speedy Blupi 2.

- When the animation counters surpasses 32700, then the animation counter is set to 0.
- This causes a noticeable "stutter". Reason: entities suddenly jump back to their first frame of animation. However, this is only an one-time issue and not a lasting effect. This glitch is much less severe in Speedy Blupi 2.

### Example

**An example of the bug in Rocks 5 (Speedy Blupi):** <br> ![](https://drive.openeggbert.com/Blupi/Games/Speedy_Blupi_(Windows)/Bugs/SB1_Rocks_5_animation_overflow_bug.png)

## Blupi animation overflow glitch

This glitch is similar to "Entity animation overflow glitch". <br> This glitch impacts Blupi's animations. <br> Blupi's animation counter relies on a 32-bit signed integer, which ranges from -2,147,483,648 to +2,147,483,647. <br> Running at 20 frames per second, the counter takes about 3.4 years to overflow (or 1.7 years in double speed mode) if there is no player input during that period.

## Color bug

Both versions 1 and 2 are impacted. **How to reproduce:**

1. Player plays as a Blupi other than yellow in multiplayer mode
2. Player returns to a single player level without closing the game

**Effects:**

1. The color of player's personal bomb will still the same, as was the selected Blupi color in the multiplayer
2. The yellow bombs will explode, player can still collect the color bomb of color used in the multiplayer

## Invisible block immunity

Both the homing bombs and Blupi riding helicopter or hovercraft are affected by this bug. <br> The impact is, that Blupi or homing bombs can travel through invisible blocks (like there would be no invisible block)

## Fake walls

This is a glitch. Create a moving platform, but do not define the second position. Then such wall will be visually the same as the other walls, but Blupi/Eggbert can walk through. This can be used to create secret walls. [Level editor](Blupi/Games/Speedy_Blupi_(Windows)/Level_editor/index.html)

## Items and objects like moving platforms

Items (elements) and objects can act like moving platforms, even this was not intended by the developer of the game.

## Some inanimated objects can become animated

## Combining elements to create new, unintended types of obstacles

For example:

- Lollipop power-up: makes player run faster and jump higher
- Wind: makes one-way corridors.

**Effect:** The speed boost provided by the lollipops let the player push through the wind.
