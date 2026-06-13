---
title: SDL
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Libraries
  href: Technologies/Libraries/index.html
subpages:
- label: Go Up
  href: Technologies/Libraries/index.html
---

### How to install SDL 3 on Linux

```

        git clone https://github.com/libsdl-org/SDL.git
        cd SDL
        mkdir build && cd build
        cmake .. -DSDL3_BUILD_SHARED=ON
        make -j$(nproc)
        sudo make install

```
