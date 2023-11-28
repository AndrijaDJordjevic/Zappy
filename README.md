# ZAPPY END OF YEAR PROJECT
# SERVER
# GUI

## Building raylib library

### INSTALL REQUIREMENTS ON UBUNTU / FEDORA

```bash
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```

```bash
sudo dnf install alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel libatomic
```

### Clone the raylib repository

```bash
cd external/
```

```bash
git clone https://github.com/raysan5/raylib.git
```

### INSTALL THE LIBRARIES TO THE STANDARD DIRECTORIES

```bash
cd external/raylib/src/
```
```bash
make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED # To make the dynamic shared version.
```
```bash
sudo make install RAYLIB_LIBTYPE=SHARED # Dynamic shared version.
```


# AI
