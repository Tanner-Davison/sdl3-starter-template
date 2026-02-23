# Contributing

Thanks for your interest in improving this template. Contributions are welcome — bug fixes, platform compatibility improvements, documentation updates, and structural enhancements are all fair game.

---

## What belongs here

This is a **starter template**, not a game engine or framework. Keep that scope in mind when proposing changes.

**Good contributions:**
- Fix build issues on Linux, macOS, or Windows
- Improve the CMake or vcpkg setup
- Improve documentation clarity
- Add missing platform-specific handling
- Fix bugs in the `SDLWindow` class

**Out of scope:**
- Game-specific logic or systems
- Additional SDL3 extension libraries beyond SDL3_image and SDL3_ttf
- Engine features (ECS, asset managers, audio systems, etc.)

---

## Getting started

1. Fork the repo and create a branch from `main`
2. Make your changes
3. Test your build on at least one platform
4. Open a pull request with a clear description of what changed and why

---

## Pull request guidelines

- Keep PRs focused — one fix or improvement per PR
- If you're fixing a build issue, mention which OS and compiler you tested on
- Update the README or DEVELOPMENT_GUIDE if your change affects setup or usage
- Don't introduce dependencies beyond what vcpkg already manages

---

## Reporting issues

Open a GitHub issue and include:
- Your OS and compiler version
- The exact error output
- Steps to reproduce

---

## Code style

This project uses `.clang-format`. Run it before submitting:

```bash
clang-format -i src/*.cpp src/*.hpp
```

Indentation is 4 spaces. Keep it consistent with the existing code.

---

## Questions

Open a discussion or issue — happy to help get your PR across the line.
