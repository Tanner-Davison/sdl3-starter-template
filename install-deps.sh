#!/bin/bash

set -e

SDL3_VERSION="release-3.2.14"
SDL3_IMAGE_VERSION="release-3.2.4"
SDL3_TTF_VERSION="release-3.2.2"

TMP_DIR="$HOME/.sdl3-build"
mkdir -p "$TMP_DIR"

install_from_source() {
    local name=$1
    local repo=$2
    local version=$3
    local dir="$TMP_DIR/$name"

    echo ""
    echo ">>> Installing $name..."

    if [ -d "$dir" ]; then
        echo "Source already cloned, pulling latest..."
        git -C "$dir" fetch --tags
    else
        git clone --branch "$version" --depth 1 "https://github.com/libsdl-org/$repo.git" "$dir"
    fi

    mkdir -p "$dir/build"
    cmake -S "$dir" -B "$dir/build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=""
    cmake --build "$dir/build" -j$(nproc)
    sudo cmake --install "$dir/build"

    echo ">>> $name installed successfully."
}

echo "Installing SDL3 dependencies from source..."

install_from_source "SDL3"       "SDL"       "$SDL3_VERSION"
install_from_source "SDL3_image" "SDL_image" "$SDL3_IMAGE_VERSION"
install_from_source "SDL3_ttf"   "SDL_ttf"   "$SDL3_TTF_VERSION"

echo ""
echo "All dependencies installed. You can now build the project:"
echo "  mkdir build && cd build"
echo "  cmake .."
echo "  make"
