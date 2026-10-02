# BFM Windows portability audit — 2026-10-02

**No qualified Windows game build or authorized Windows runtime exists.**
Public r38 remains Linux-only; its release notes still say Windows is unavailable.
Audit target: qualified runtime source `61c60516d18bf6402e6dbd937d8c8d18ebd1af4b`.

The devbox already has Zig 0.13.0. Saved checks produced a Windows COFF
platform-name adapter and passed CMake compiler detection; the actual game
configuration failed at missing Windows SDL2. Formatter/X11 syntax checks
failed on Linux headers. No game link or Windows gameplay test passed.
This follow-up read source and saved results only; it ran no compiler,
downloads, installs, containers or runner jobs.

A Windows build needs:

- **Toolchain:** an owner-approved Windows x64 C/C++ compile/link setup with
  target headers, CRT and import libraries. Existing Zig is a candidate for
  cross-compilation, not a proven complete BFM build workflow.
- **Libraries:** matching Windows SDL2, OpenAL Soft and OpenSSL Crypto
  development/runtime libraries, OpenGL headers/import support and a working
  runtime driver. Include zlib to preserve the current package's optional PNG
  features. Retain dependency notices/source obligations.
- **Code generation:** parameterize the Linux target in `tools/native_lane_gen.py`
  (including its empty-object path); validate existing CMake compiler/archive
  wiring, COFF output and the Win64 ABI without relaxing admission guards.
- **Host code:** implement shared fixed-address guest/scratchpad mappings,
  guard-page protection and fault handling; condition Linux X11/glibc hooks;
  resolve SDL entrypoint handling and environment/directory/time wrappers.
- **Packaging and saves:** provide a Windows launcher and DLL layout; preserve
  APPDATA conventions and replace cards without deleting the old card before
  a replacement succeeds. Then verify imports, package contents and retail scan.

**Runtime testing without the owner's desktop:** after an owner decision,
use a separate Windows x64 runner or VM with its own graphical session,
lawful locally held game data and isolated test cards. Run ABI/guard/unwind
probes, forest/village/attract routes, save and cold Continue; qualify graphics,
audio and controller behavior separately. A headless/null-audio pass cannot
establish those device behaviors. Compile-only checks or future Wine tests
must be reported separately from actual Windows execution.

No such runner is currently authorized. blizzpc is Linux; the occupied
Alienware is excluded. Do not install a toolchain, dependencies, Wine or
containers, or create a VM, while the coordinator awaits the owner's decision.

Detailed source findings and saved evidence:
[Windows release audit](WINDOWS-RELEASE-2026-10-02.md).
