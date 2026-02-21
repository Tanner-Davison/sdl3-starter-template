# sdl3-starter-template

A minimal SDL3 project template. Clone it, build it, and start writing your game.

Includes SDL3, SDL3_image, and SDL3_ttf via vcpkg.

---

## Requirements

| Tool | Version |
|------|---------|
| CMake | 3.15+ |
| vcpkg | latest |
| GCC / Clang / MSVC | C++23 support |

---

## Setup

### 1. Install vcpkg

Skip this if you already have it. Clone it anywhere — there is no standard location.

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
cd ~/vcpkg
./bootstrap-vcpkg.sh   # macOS / Linux
.\bootstrap-vcpkg.bat  # Windows
```

Then add these to your shell profile (`~/.zshrc`, `~/.bashrc`, or PowerShell `$PROFILE`):

```bash
export VCPKG_ROOT=~/vcpkg   # update to your actual path
export CMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```

### 2. Linux — install build dependencies

```bash
sudo apt install build-essential git cmake autoconf autoconf-archive automake libtool
```

### 3. macOS — install Xcode tools

```bash
xcode-select --install
```

### 4. Windows — install Visual Studio

[Visual Studio 2022](https://visualstudio.microsoft.com/) with the **Desktop development with C++** workload.

---

## Building

### Linux & macOS

```bash
git clone https://github.com/yourusername/sdl3-starter-template.git
cd sdl3-starter-template
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Windows (Visual Studio)

```powershell
git clone https://github.com/yourusername/sdl3-starter-template.git
cd sdl3-starter-template
mkdir build && cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

### Windows (Ninja)

```powershell
cmake .. -G Ninja
cmake --build .
```

vcpkg will automatically download and build SDL3, SDL3_image, and SDL3_ttf on first run. This may take a few minutes.

---

## Running

```bash
# Linux & macOS
./sdl3-starter-template

# Windows
.\Release\sdl3-starter-template.exe
```

---

## Project Structure

```
sdl3-starter-template/
├── src/
│   ├── main.cpp        # entry point and game loop
│   ├── window.hpp      # SDLWindow class
│   └── window.cpp      # SDLWindow implementation
├── vcpkg.json          # dependency manifest
├── CMakeLists.txt
└── README.md
```

---

## Usage

Your game loop lives in `src/main.cpp`:

```cpp
while (!gameWindow.shouldClose()) {
    gameWindow.handleEvents();

    SDL_SetRenderDrawColor(gameWindow.getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(gameWindow.getRenderer());

    // render here

    SDL_RenderPresent(gameWindow.getRenderer());
}
```

To add source files, update `CMakeLists.txt`:

```cmake
set(SOURCES
    src/main.cpp
    src/window.cpp
    src/player.cpp   # add yours here
)
```

---

## LSP / clangd

Symlink the generated `compile_commands.json` to the project root:

```bash
ln -s build/compile_commands.json compile_commands.json
```

---

## License

MIT
