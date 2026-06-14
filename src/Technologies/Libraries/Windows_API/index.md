---
title: Windows API
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Libraries
  href: Technologies/Libraries/index.html
- label: Windows API
  href: Technologies/Libraries/Windows_API/index.html
subpages:
- label: Go Up
  href: Technologies/Libraries/index.html
---

## WinMain function

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

- hInstance - application handle
- hPrevInstance - obsolete parameter, which is always null
- lpCmdLine - command line, which started the application, similar to the args parameter to main in C
- nCmdShow - specifies the starting mode of the application (minimized, maximized or normal)
