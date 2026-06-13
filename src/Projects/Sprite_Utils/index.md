---
title: Sprite Utils
breadcrumb:
- label: Projects
  href: Projects/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

Repository: [https://github.com/openeggbert/sprite-utils](https://github.com/openeggbert/sprite-utils)

## Description

Application used to work with sprite images - highlighting borders, adding more sprites in one image <br> Sprite Utils is a Java application used to manage sprite positions in images.

- Sprite positions are saved in spritesheet.csv

Syntax: `java -jar sprite-utils.jar command --option1 valueOfOption1 --option2 valueOfOption2 ... --optionN valueOfOptionN`

## Usage

A graphics editor like KolourPaint, MS Paint or an alternative is used. <br> It is repeatedly checked whether the positions of the sprites are rendered in the correct places.

## Options

| Option name | Mandatory | Default value | Command | Description |
| --- | --- | --- | --- | --- |
| **--dir** | Yes | N/A | draw | Absolute path to the directory with images, which includes sprites |
| **--rectangle-color** | No | 0,255,0 | draw | Border color of rectangles - comma separated list of RGB (bytes) |
| **--sprite-sheet-path** | Yes | N/A | draw | Absolute path to the CSV file with the sprite sheet positions |
| **--row** | No | All rows | draw | Number of the row in the images to be drawn (since row 1) |
| **--file-name** | No | All files in the sprite sheet | draw | Name of the image file to be drawn |
| **--draw-number** | No | Yes | draw | Draws the numbers of the sprites in the image |
| **--double-sized-number** | No | No | draw | Draws the number label in the doubled size |

## Commands

### Command: draw

Rectangles are drawn around the sprites and each sprite is labeled with its number. in the image <br> **Example:**

```

java -jar /rv/data/desktop/code/github.com/openeggbert/sprite-utils/target/sprite-utils-0.0.0-SNAPSHOT-jar-with-dependencies.jar \
draw \
--dir /rv/data/desktop/code/github.com/openeggbert/open-eggbert-legacy-assets/speedy_eggbert_1/IMAGE08  \
--rectangle-color 255,0,0  \
--sprite-sheet-path /rv/data/desktop/code/github.com/openeggbert/open-eggbert/assets/default-spritesheets/speedy_blupi_I.spritesheet.csv  \
--row 5 \
--file-name OBJECT.BLP \
--double-sized-number true

```

## Format of CSV file spritesheet.csv

**Note:** The file *spritesheet.csv.computed.csv is intended to be used in Open Eggbert - for image mods

### Columns

| Column name | Mandatory | Description |
| --- | --- | --- |
| **File** | Yes | Name of the image, where the sprite exists. |
| **Group** | Yes | Sprite group name. |
| **Number in Group** | Yes | Number in group. |
| **Row** | Yes | Row position of sprite in the image starting from 1. |
| **Column** | Yes | Column position of sprite in the row of the image starting from 1 |
| **X** | No | Start x position of the sprite starting from 0 and starting from the top-left corner. If the value is empty, then the X value is calculated automatically. |
| **Y** | Yes | Start y position of the sprite starting from 0 and starting from the top-left corner. The value cannot be empty. |
| **Width** | Yes | Width of the sprite. |
| **Height** | Yes for 1st column | Height of the sprite. If the number of column is larger than 1 and the height is greater, than the height of the previous column, than the height is interpreted as an addition to the height of the previous sprite. |
| **Notes** | No | Notes |
| **Tags** | No | Tags |
| **Number per file** | Yes | Number of sprite in the image file |

### Example

| File | Group | Number in Group | Row | Column | X | Y | Width | Height | Notes | Tags | Number per file |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| blupi000.blp | Yellow_Eggbert_Born | 1 | 1 | 1 |  | 0 | 28 | 20 |  | ok | 1 | blupi000.blp | Yellow_Eggbert_Born | 2 | 1 | 2 |  | 0 | 28 | 0 |  | ok | 2 | blupi000.blp | Yellow_Eggbert_Born | 3 | 1 | 3 |  | 0 | 28 | 3 |  | ok | 3 | blupi000.blp | Yellow_Eggbert_Born | 4 | 1 | 4 |  | 0 | 28 | 0 |  | ok | 4 | blupi000.blp | Yellow Bomb | 1 | 1 | 5 |  | 0 | 34 | 1 |  | ok | 5 | blupi000.blp | Yellow Bomb | 2 | 1 | 6 |  | 0 | 38 | 0 |  | ok | 6 | blupi000.blp | Yellow Bomb | 3 | 1 | 7 |  | 0 | 40 | 0 |  | ok | 7 | blupi000.blp | Yellow Bomb | 4 | 1 | 8 |  | 0 | 42 | 0 |  | ok | 8 | blupi000.blp | Yellow Bomb | 5 | 1 | 9 |  | 0 | 44 | 0 |  | ok | 9 | blupi000.blp | Yellow Bomb | 6 | 1 | 10 |  | 0 | 45 | 0 |  | ok | 10 | blupi000.blp | Yellow_Eggbert_Life | 1 | 1 | 11 |  | 0 | 17 | 1 |  | ok | 11 | blupi000.blp | Yellow_Eggbert_Born | 5 | 1 | 12 |  | 0 | 28 | 2 |  | ok | 12 | blupi000.blp | Yellow_Eggbert_Born | 6 | 1 | 13 |  | 0 | 28 | 2 |  | ok | 13 | blupi000.blp | Yellow_Eggbert_Born | 7 | 1 | 14 |  | 0 | 28 | 1 |  | ok | 14 | blupi000.blp | Yellow_Eggbert_Born | 8 | 1 | 15 |  | 0 | 28 | 1 |  | ok | 15 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 1 | 1 | 16 |  | 0 | 53 | 0 |  | ok | 16 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 1 | 1 | 17 |  | 0 | 60 | 0 |  | ok | 17 | blupi000.blp | Yellow_Eggbert_Born | 9 | 1 | 18 |  | 0 | 28 | 1 |  | ok | 18 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 2 | 1 | 19 |  | 0 | 46 | 0 |  | ok | 19 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 3 | 1 | 20 |  | 0 | 46 | 0 |  | ok | 20 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 2 | 1 | 21 |  | 0 | 47 | 0 |  | ok | 21 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 3 | 2 | 1 |  | 32 | 47 | 32 |  | ok | 22 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 4 | 2 | 2 |  | 32 | 47 | 0 |  | ok | 23 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 4 | 2 | 3 |  | 32 | 48 | 0 |  | ok | 24 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 5 | 2 | 4 |  | 32 | 48 | 0 |  | ok | 25 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 5 | 2 | 5 |  | 32 | 48 | 0 |  | ok | 26 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 6 | 2 | 6 |  | 32 | 48 | 0 |  | ok | 27 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 6 | 2 | 7 |  | 32 | 49 | 0 |  | ok | 28 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 7 | 2 | 8 |  | 32 | 49 | 0 |  | ok | 29 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 7 | 2 | 9 |  | 32 | 49 | 0 |  | ok | 30 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 8 | 2 | 10 |  | 32 | 49 | 0 |  | ok | 31 | blupi000.blp | Yellow_Eggbert_Swimming_Butt | 1 | 2 | 11 |  | 32 | 52 | 0 |  | ok | 32 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 8 | 2 | 12 |  | 32 | 54 | 0 |  | ok | 33 | blupi000.blp | Yellow_Eggbert_Swimming_Right | 9 | 2 | 13 |  | 32 | 57 | 0 |  | ok | 34 | blupi000.blp | Yellow_Eggbert_Swimming_Left | 9 | 2 | 14 |  | 32 | 58 | 0 |  | ok | 35 | blupi000.blp | Yellow_Eggbert_Crouching_Left | 1 | 2 | 15 |  | 32 | 37 | 7 |  | ok | 36 | blupi000.blp | Yellow_Eggbert_Crouching_Right | 1 | 2 | 16 |  | 32 | 37 | 0 |  | ok | 37 |
| blupi000.blp | Yellow_Eggbert_Born | 1 | 1 | 1 |  | 0 | 28 | 20 |  | ok | 1 |
| blupi000.blp | Yellow_Eggbert_Born | 2 | 1 | 2 |  | 0 | 28 | 0 |  | ok | 2 |
| blupi000.blp | Yellow_Eggbert_Born | 3 | 1 | 3 |  | 0 | 28 | 3 |  | ok | 3 |
| blupi000.blp | Yellow_Eggbert_Born | 4 | 1 | 4 |  | 0 | 28 | 0 |  | ok | 4 |
| blupi000.blp | Yellow Bomb | 1 | 1 | 5 |  | 0 | 34 | 1 |  | ok | 5 |
| blupi000.blp | Yellow Bomb | 2 | 1 | 6 |  | 0 | 38 | 0 |  | ok | 6 |
| blupi000.blp | Yellow Bomb | 3 | 1 | 7 |  | 0 | 40 | 0 |  | ok | 7 |
| blupi000.blp | Yellow Bomb | 4 | 1 | 8 |  | 0 | 42 | 0 |  | ok | 8 |
| blupi000.blp | Yellow Bomb | 5 | 1 | 9 |  | 0 | 44 | 0 |  | ok | 9 |
| blupi000.blp | Yellow Bomb | 6 | 1 | 10 |  | 0 | 45 | 0 |  | ok | 10 |
| blupi000.blp | Yellow_Eggbert_Life | 1 | 1 | 11 |  | 0 | 17 | 1 |  | ok | 11 |
| blupi000.blp | Yellow_Eggbert_Born | 5 | 1 | 12 |  | 0 | 28 | 2 |  | ok | 12 |
| blupi000.blp | Yellow_Eggbert_Born | 6 | 1 | 13 |  | 0 | 28 | 2 |  | ok | 13 |
| blupi000.blp | Yellow_Eggbert_Born | 7 | 1 | 14 |  | 0 | 28 | 1 |  | ok | 14 |
| blupi000.blp | Yellow_Eggbert_Born | 8 | 1 | 15 |  | 0 | 28 | 1 |  | ok | 15 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 1 | 1 | 16 |  | 0 | 53 | 0 |  | ok | 16 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 1 | 1 | 17 |  | 0 | 60 | 0 |  | ok | 17 |
| blupi000.blp | Yellow_Eggbert_Born | 9 | 1 | 18 |  | 0 | 28 | 1 |  | ok | 18 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 2 | 1 | 19 |  | 0 | 46 | 0 |  | ok | 19 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 3 | 1 | 20 |  | 0 | 46 | 0 |  | ok | 20 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 2 | 1 | 21 |  | 0 | 47 | 0 |  | ok | 21 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 3 | 2 | 1 |  | 32 | 47 | 32 |  | ok | 22 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 4 | 2 | 2 |  | 32 | 47 | 0 |  | ok | 23 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 4 | 2 | 3 |  | 32 | 48 | 0 |  | ok | 24 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 5 | 2 | 4 |  | 32 | 48 | 0 |  | ok | 25 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 5 | 2 | 5 |  | 32 | 48 | 0 |  | ok | 26 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 6 | 2 | 6 |  | 32 | 48 | 0 |  | ok | 27 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 6 | 2 | 7 |  | 32 | 49 | 0 |  | ok | 28 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 7 | 2 | 8 |  | 32 | 49 | 0 |  | ok | 29 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 7 | 2 | 9 |  | 32 | 49 | 0 |  | ok | 30 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 8 | 2 | 10 |  | 32 | 49 | 0 |  | ok | 31 |
| blupi000.blp | Yellow_Eggbert_Swimming_Butt | 1 | 2 | 11 |  | 32 | 52 | 0 |  | ok | 32 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 8 | 2 | 12 |  | 32 | 54 | 0 |  | ok | 33 |
| blupi000.blp | Yellow_Eggbert_Swimming_Right | 9 | 2 | 13 |  | 32 | 57 | 0 |  | ok | 34 |
| blupi000.blp | Yellow_Eggbert_Swimming_Left | 9 | 2 | 14 |  | 32 | 58 | 0 |  | ok | 35 |
| blupi000.blp | Yellow_Eggbert_Crouching_Left | 1 | 2 | 15 |  | 32 | 37 | 7 |  | ok | 36 |
| blupi000.blp | Yellow_Eggbert_Crouching_Right | 1 | 2 | 16 |  | 32 | 37 | 0 |  | ok | 37 |

## How to use

### Modify DATA/CONFIG.DEF:

```

        FullScreen=0

        TrueColor=8

        Timer=200ms

```

### How to create rectangles based on the sprite sheet CSV file (example)

java -jar /rv/data/desktop/code/code.nanoboot.org/nanoboot/sprite-utils/target/sprite-utils-0.0.0-SNAPSHOT-jar-with-dependencies.jar draw --dir /rv/data/desktop/code/code.nanoboot.org/nanoboot/open-eggbert-legacy-assets/speedy_eggbert_1/IMAGE08 --rectangle-color 0,255,0 --sprite-sheet-path /rv/data/desktop/code/code.nanoboot.org/nanoboot/open-eggbert/assets/default-spritesheets/speedy_blupi_I.spritesheet.csv --row 4 --file-name BLUPI000.BLP ;

### How to run Speedy Blupi/Eggbert in window mode on Linux without blue backgrounds

cd /rv/data/desktop/code/code.nanoboot.org/nanoboot/open-eggbert-legacy-assets/speedy_eggbert_1;Xephyr :1 -ac -screen 800x600x16 & DISPLAY=:1 xfwm4 & DISPLAY=:1 wine Eggbert1.exe
