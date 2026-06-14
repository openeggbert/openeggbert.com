---
title: EXE
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Platforms
  href: Technologies/Platforms/index.html
- label: Windows
  href: Technologies/Platforms/Windows/index.html
- label: EXE
  href: Technologies/Platforms/Windows/EXE/index.html
subpages:
- label: Go Up
  href: Technologies/Platforms/Windows/index.html
---

EXE is the executable file format developed by the [Microsoft](Technologies/Other/Microsoft/index.html) company for the following [operating system](Article_does_not_yet_exist_or_link_is_broken/index.html)s: [Windows](Technologies/Platforms/Windows/index.html), [DOS](Article_does_not_yet_exist_or_link_is_broken/index.html), [OS/2](Article_does_not_yet_exist_or_link_is_broken/index.html).

The EXE file contains series of instructions for the processor to be executed.

Magic number of the EXE file format is: 0x4d 0x5a (which means, each EXE file starts with the [ASCII](Article_does_not_yet_exist_or_link_is_broken/index.html) string called "MZ".

## Formats of the EXE file

### DOS

- **16-bit DOS MZ Executable (MZ)**
  - The original DOS executable format, identifiable by the ASCII letters "MZ" at the start of the file.
  - Later formats retain an MZ DOS stub header for backward compatibility.
- **16-bit New Executable (NE)**
  - Introduced in multitasking MS-DOS 4.0.
  - Used in 16-bit OS/2 and Windows, identifiable by "NE" in ASCII.

### OS/2

- **32-bit Linear Executable (LX)**
  - Introduced in OS/2 2.0 and identifiable by "LX" in ASCII.
  - Runs only on OS/2 2.0 and higher.
- **Mixed 16/32-bit Linear Executable (LE)**
  - Introduced in OS/2 2.0, identifiable by "LE" in ASCII.
  - Used for VxD drivers on Windows 3.x, OS/2, and Windows 9x.

### Windows

- **32-bit Portable Executable (PE)**
  - Introduced with Windows NT, structured as "fat binaries" with a DOS-specific and Windows-specific section.
  - The DOS stub (a minimal DOS program) displays "This program cannot be run in DOS mode." Custom DOS stubs can be created.
  - The Windows part starts with "PE\0\0" (ASCII for "PE" with two null bytes).
The PE format is used by Windows 95 and higher.
- **64-bit Portable Executable (PE32+)**
  - Introduced with 64-bit Windows, an extended PE format with wider fields.
  - Often allows code to run in either 32-bit or 64-bit mode.
  - Includes a DOS stub for compatibility.

### Other Formats

- Additional EXE formats include W3 (used in **WIN386.EXE**), W4 (compressed LE files in **VMM32.VXD**), and others like DL, MP, P2, and P3 (used by Phar Lap extenders).

## Parts of the PE EXE file

EXE file consists of the following parts: headers, sections

### EXE headers

- MS-DOS Header
- PE Header

#### MS-DOS Header

Its length is 64 bytes and contains the relocation information. This header is intended for MS-DOS operating system.

Purpose of this header is to show an error message, if such an EXE file is started on the MS-DOS operating system, which is only for historical purposes.

Usual text of the message is: This program cannot be run in DOS mode

#### PE Header

The **PE (Portable Executable) header** is part of a Windows `.exe` file that the operating system reads when it runs the file. This header tells the OS where and how to load the program into memory. It begins with a unique 4-byte signature and includes essential details such as:

- The memory location where the executable should start
- The program's entry point address
- A checksum
- Supported processor types
- The executable's size
- A list of required libraries, functions, and resources

##### Section Table

The section table is an array of structures, where each entry represents a section of the executable. Each entry includes information about the section, such as:

- Its size in memory
- Location
- Specific characteristics

##### Data Directory

The data directory is an array that points to various tables with essential executable information, including:

- **Export Table**: Lists functions the executable makes available to other programs.
- **Import Table**: Lists functions it imports from other libraries.
- **Resource Table**: Contains embedded resources (e.g., images).
- **Import Address Table (IAT)**: Holds runtime addresses for imported functions, so they’re accessible when the program runs.

### Sections

These are key sections within a `.exe` file.

- **.text/.code/CODE/TEXT** — Holds the executable code, or machine instructions, that the CPU runs. This section is vital for disassembly.
- **.tests/TEXTBSS** — Included if incremental linking is enabled.
- **.rdata** — Stores constants and read-only data, such as string literals.
- **.data/DATA** — Typically has read and write access, containing initialized global and static variables that can be accessed from anywhere in the program.
- **.bss/BSS** — Holds uninitialized global and static variables.
- **.rsrc** — Contains embedded resources, like images and icons. Strings may also be stored here.
- **.debug** — Stores debugging information.
- **.idata** — Import data section, which includes details on imported functions.
- **.edata** — Export data section, holding information on exported functions.
- **.reloc** — Contains data necessary for relocating library files in memory.

## External links

- [Medium article on analyzing .exe files](https://eshagalawatta.medium.com/analyzing-structure-of-executable-programs-exe-files-821b2d531a4)
- [Wikipedia: .exe](https://en.wikipedia.org/wiki/.exe)
