---
title: Pentium 100
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

Processor using the [i586](Technologies/Programming_languages/Assembly_Language/I586/index.html) microprocessor launched on 22th March 1993 and discontinued on 15th July 1999.

## Comparison of Pentium 100 (i586) and Core i7 (2024)

### Pentium 100 (i586)

- It has relatively simple architectures with limited instruction set.
- Pipeline is less complex.
- Hyper threading is not available.
- There are no advanced optimizations for out-of-order execution.
- Simple memory model.
- Parallelism and thread processing: Pentium uses only one thread.
- Performance: Emulating Pentium 100 should be much more faster.

### Core i7 (2024)

- Instruction set is much more complex (including SIMD extensions like AVX, AVX2, AVX-512).
- Several pipelines with out-of-order execution of instructions.
- Branch prediction.
- Hyper threading.
- And other advanced optimizations.
- Complex memory model:
  - Several layers of cache (L1, L2, L3)
  - Cache prefetching
  - Speculative execution
  - TLB (Translation Lookaside Buffer) for virtual memory
- Parallelism and thread processing: Core i7 has several cores and supports hyper-threading.
- Performance of Core i7 is about 1000 times bigger than the performance of Pentium 100.
