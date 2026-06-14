---
title: MeshCraft
breadcrumb:
- label: Projects
  href: Projects/index.html
- label: MeshCraft
  href: Projects/MeshCraft/index.html
subpages:
- label: Go Up
  href: Projects/index.html
---

<table class="infobox">
<tr>
<th colspan="2">MeshCraft</th>
</tr>
<tr>
<th>Website</th>
<td><a href="https://meshcraft.openeggbert.com" target="_blank">https://meshcraft.openeggbert.com</a></td>
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
<th>Development status</th>
<td>Early prototype</td>
</tr>
<tr>
<th>Inspired by</th>
<td>Ray Dream Studio, Google SketchUp</td>
</tr>
<tr>
<th>Dependencies</th>
<td><a href="Projects/CNA/index.html">CNA</a>, <a href="Projects/Sharp_Runtime/index.html">Sharp Runtime</a></td>
</tr>
</table>

**MeshCraft** is a C++23 application for building and editing 3D models from primitive shapes, groups, materials, and constructive solid geometry (CSG). Models are stored in the `.mc3` format — a human-readable YAML-based source format that can be compiled to glTF/GLB for use in games and real-time applications.

MeshCraft is inspired by Ray Dream Studio and Google SketchUp.

## The MC3 Format

MC3 (Mesh Craft 3D) is the native source format used by MeshCraft. It describes models as editable constructive objects rather than raw triangle meshes.

Key capabilities:
- Primitive shapes: box, sphere, cylinder, cone, plane
- Hierarchical groups and transforms
- Materials and textures (PBR-style)
- CSG operations: union, difference, intersection
- Reusable definitions (prefabs)
- Object actions and states for interactive/animated models
- Export target: glTF/GLB

## Planned features

- Primitive creation tools (box, sphere, cylinder, plane, cone)
- Transforms: position, rotation (XYZ extrinsic Euler), scale, pivot
- Materials and textures (PBR)
- CSG operations: union, difference, intersection
- Object hierarchy and grouping
- Object actions and animations (opening doors, moving objects, etc.)
- Export to glTF/GLB
- 3D editor UI: main viewport, object hierarchy panel, properties panel, tool palette, transform gizmo

## Build

```bash
cmake -S . -B build
cmake --build build
./build/MeshCraft
```
