# SDL3 starter template from: Tanner Davison

A minimal SDL3 starter template to get a window with a hardware-accelerated renderer up and running quickly. Includes SDL3, SDL3_image, and SDL3_ttf — managed automatically via vcpkg.

## Features

- `SDLWindow` class wrapping SDL3 init, renderer creation, event handling, and cleanup
- Hardware-accelerated renderer
- Basic game loop with clear/render/present pattern
- Proper RAII — window and renderer are cleaned up automatically on destruction
- Dependencies managed via vcpkg manifest (`vcpkg.json`)

## Prerequisites

### All Platforms
- [CMake](https://cmake.org/) 3.15+
- [vcpkg](https://github.com/microsoft/vcpkg)
- A C++23 compatible compiler

### Linux
- GCC 13+ or Clang 16+
- Install build tools:
  ```bash
  sudo apt install build-essential git cmake autoconf autoconf-archive automake libtool
  ```
- Install vcpkg:
  ```bash
  git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
  cd ~/vcpkg
  ./bootstrap-vcpkg.sh
  ```
- Set the environment variable (add to your `~/.bashrc` or `~/.zshrc`):
  ```bash
  export VCPKG_ROOT=~/vcpkg
  export CMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
  ```

### macOS
- Xcode Command Line Tools:
  ```bash
  xcode-select --install
  ```
- Install vcpkg if you don't already have it (there is no standard install location — clone it wherever you prefer):
  ```bash
  git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
  cd ~/vcpkg
  ./bootstrap-vcpkg.sh
  ```
- Set `VCPKG_ROOT` to wherever you cloned vcpkg (add to your `~/.zshrc`):
  ```bash
  export VCPKG_ROOT=~/vcpkg  # update this to match your actual vcpkg location
  export CMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
  ```

### Windows
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with the "Desktop development with C++" workload
- Install vcpkg:
  ```powershell
  git clone https://github.com/microsoft/vcpkg.git C:\vcpkg
  cd C:\vcpkg
  .\bootstrap-vcpkg.bat
  ```
- Set the environment variable (System Environment Variables or PowerShell profile):
  ```powershell
  $env:VCPKG_ROOT = "C:\vcpkg"
  $env:CMAKE_TOOLCHAIN_FILE = "C:\vcpkg\scripts\buildsystems\vcpkg.cmake"
  ```

## Building

Once prerequisites are installed, vcpkg will automatically download and install SDL3, SDL3_image, and SDL3_ttf on first build.

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

## Running

### Linux & macOS
```bash
./sdl3-starter-template
```

### Windows
```powershell
.\Release\sdl3-starter-template.exe
```

## LSP Support (clangd / Neovim)

The build generates a `compile_commands.json` in the build directory. Symlink it to the project root for clangd to pick it up:

```bash
ln -s build/compile_commands.json compile_commands.json
```

## Project Structure

```
sdl3-starter-template/
├── src/
│   ├── main.cpp        # Entry point and game loop
│   ├── window.hpp      # SDLWindow class declaration
│   └── window.cpp      # SDLWindow class implementation
├── vcpkg.json          # vcpkg dependency manifest
├── CMakeLists.txt      # Build configuration
└── README.md
```

## Usage

Add your game logic inside the loop in `src/main.cpp`:

```cpp
while (!gameWindow.shouldClose()) {
    gameWindow.handleEvents();

    SDL_SetRenderDrawColor(gameWindow.getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(gameWindow.getRenderer());

    // Your rendering code here

    SDL_RenderPresent(gameWindow.getRenderer());
}
```

To add new source files, append them to the `SOURCES` list in `CMakeLists.txt`:

```cmake
set(SOURCES
    src/main.cpp
    src/window.cpp
    src/your_new_file.cpp
)
```
