---
title: Registers
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Programming languages
  href: Technologies/Programming_languages/index.html
- label: Assembly Language
  href: Technologies/Programming_languages/Assembly_Language/index.html
- label: I586
  href: Technologies/Programming_languages/Assembly_Language/I586/index.html
subpages:
- label: Go Up
  href: Technologies/Programming_languages/Assembly_Language/I586/index.html
---

Only some registers can be modified via the instruction in the executable file.

<br>

The other are modified by the internal state of the processor, for example in the case, an overflow happened.

## Types of registers based on the data length

64-bit registers - These do not exist in the i586 instruction set. They exist only in the 64-bit processors.
        Their names start with the R character.

<br>

32-bit registers - Their names start with the E character.

<br>

16-bit registers

<br>

8-bit registers

## Categories of registers

- General registers
- Control registers
- Segment registers

## Categories of general registers

- Data registers
- Pointer registers
- Index registers

## Data registers

There are four data 32-bit data registers: EAX, EBX, ECX, EDX

- Lower halves of the 32-bit registers can be used as four 16-bit data registers: AX, BX, CX and DX.
- Lower and higher halves of the above-mentioned four 16-bit registers can be used as eight 8-bit data
                registers: AH, AL, BH, BL, CH, CL, DH, and DL.

Regarding the 64-bit processors: There are also four data 64-bit data registers: RAX, RBX, RCX, RDX

## Pointer registers

There are three data 32-bit pointer registers: EIP, ESP, EBP

<br>

Their 16-bit equivalent are IP, SP, BP

### Instruction Pointer (EIP)

The 32-bit

**EIP**

register holds the address of the next instruction to be executed. When combined with the

**CS**

register (as

**CS:EIP**

), it provides the full address of the current instruction within the code
        segment.

- The **CS:EIP** pair gives the logical address pointing to the instruction that the processor will
                execute next.

### Stack Pointer (ESP)

The 32-bit

**ESP**

register holds the offset within the stack. When used with the

**SS**

register (

**SS:ESP**

),
        it refers to the current location in the stack.

- The **SS:ESP** pair provides the complete address within the stack segment.

### Base Pointer (EBP)

The 32-bit

**EBP**

register helps in referencing the parameters passed to a subroutine. The address from the

**SS**

register is combined with the offset in

**EBP**

to locate the function parameters.

**EBP**

can also be
        used with

**ESI**

and

**EDI**

for special addressing.

- The **SS:EBP** pair points to the base of the current stack frame, facilitating access to function arguments
                and local variables.

## Index registers

There are two data 32-bit pointer registers: ESI, EDI

<br>

Their 16-bit equivalent are SI, DI

### Source Index (SI)

It is used as source index for string operations.

### Destination Index (DI)

It is used as destination index for string operations.

## Control registers

Many instructions involve comparisons and mathematical calculations and change the status of the flags and some
        other conditional instructions test the value of these status flags to take the control flow to other location.

## Segment registers

Segments are specific areas defined in a program for containing data, code and stack.

## External links

[https://wiki.osdev.org/CPU_Registers_x86](https://wiki.osdev.org/CPU_Registers_x86)
