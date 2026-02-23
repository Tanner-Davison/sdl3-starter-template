# Security Policy

## Supported Versions

This is a starter template, not a versioned library. Security fixes are applied to the `main` branch only.

| Branch | Supported |
|--------|-----------|
| main   | ✅        |
| older forks/tags | ❌ |

---

## Reporting a Vulnerability

This project is a C++ build template with no network code, authentication, or user data handling. The attack surface is minimal by design.

That said, if you find something worth reporting — such as a supply chain issue with a vendored dependency or a CMake configuration that could lead to code execution during build — please report it privately rather than opening a public issue.

**Contact:** tanner.davison95@gmail.com

Include:
- A description of the vulnerability
- Steps to reproduce
- Potential impact

I'll respond within a few days and work with you on a fix before any public disclosure.

---

## Dependencies

SDL3, SDL3_image, and SDL3_ttf are managed via vcpkg. If a vulnerability is discovered in one of those upstream libraries, update your vcpkg baseline and rebuild. See the [vcpkg security advisories](https://github.com/microsoft/vcpkg/security/advisories) for upstream issues.
