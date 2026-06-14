---
title: Sharp Runtime
breadcrumb:
- label: Projects
  href: Projects/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">Sharp Runtime</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://sharpruntime.openeggbert.com" target="_blank">https://sharpruntime.openeggbert.com</a></td>
</tr>
<tr>
<th>Programming language</th>
<td>C++</td>
</tr>
<tr>
<th>C++ standard</th>
<td>C++23</td>
</tr>
<tr>
<th>Licence</th>
<td>MIT</td>
</tr>
<tr>
<th>Based on</th>
<td>Partly derived from <a href="https://github.com/dotnet/runtime" target="_blank">.NET Runtime</a> (MIT, © .NET Foundation)</td>
</tr>
<tr>
<th>Used by</th>
<td><a href="Projects/CNA/index.html">CNA</a></td>
</tr>
</table>

**Sharp Runtime** is a C++ reimplementation of a small C#/.NET runtime subset, mainly used by [CNA](Projects/CNA/index.html) and game ports.

The goal is to provide a lightweight, .NET-inspired foundation layer for C++ projects, with a focus on familiar API design (`System::*`-like namespaces), clean and modern C++ implementation, and compatibility with higher-level frameworks like CNA.

> Sharp Runtime is **not** a full .NET runtime or CLR implementation. It is a pragmatic subset designed for use in native C++ applications.

## Role in the stack

```
Sharp Runtime  (System::* types, exceptions, events, delegates)
      └── CNA  (XNA-like API)
            └── Mobile Eggbert (C++), Galaxy Eggbert, MeshCraft, ...
```

## Goals

- Recreate useful parts of the .NET API in idiomatic C++
- Provide building blocks: exceptions, events/delegates, basic system types
- Serve as a foundation for [CNA](Projects/CNA/index.html)
- Keep the codebase simple, readable, and well-documented

## Attribution

Sharp Runtime is partly derived from the .NET runtime ([dotnet/runtime](https://github.com/dotnet/runtime), MIT License, © .NET Foundation and Contributors). The public API design of `System::*` types — class names, method signatures, namespace structure, and enum values — is based on the .NET standard library. Some algorithmic implementations (number formatting, date/time arithmetic, Unicode handling) are informed by or translated from the dotnet/runtime source code. The C++ implementation is original work by Robert Vokac and contributors.

## Implementation status

Each class or function is annotated with one of these statuses in Doxygen comments:

| Status | Meaning |
| --- | --- |
| Todo | Not implemented yet |
| Stub | Skeleton only, returns placeholder or fails |
| Partial | Partially implemented, may be incomplete |
| Implemented | Functionally complete |
| Verified | Validated against expected .NET behavior |

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Scope

Sharp Runtime intentionally does **not** aim to implement: the CLR (Common Language Runtime), JIT compilation, or full .NET standard compatibility. It focuses on a practical subset useful for native development.
