# Windows addition to public r38: blocked, not published

Owner clarification at 2026-10-02 21:10:35 UTC, delivered in Devbox message
`23c4f77ef5a3979a`: the same public release must include Windows and Linux.
Linux r38 is live and qualified. Windows remains an outstanding part of this
request, not a completed platform or a second release request. Preserve the
existing Linux artifact and use the same release when Windows qualifies.

The owner is playing. No desktop/device access, remote runner job, update,
restart or game interaction was performed during this audit. Codex remains
the sole writer; two existing reviewers performed local read-only audits.

## Actual checks on release/r37 source 61c60516d

Evidence: `~/release-staging/bfm-r38-public/windows-audit/RESULT.json`, with
the compile/configure logs and their hashes beside it.

| Check | Result |
|---|---|
| Existing Zig 0.13.0, target `x86_64-windows-gnu` | Available; Clang 18.1.6 |
| `pc_port/platform/windows.c` compile | x86-64 COFF object produced; this function only returns the platform name |
| CMake C/C++ compiler ABI detection | Passed using isolated Windows target/sysroot configuration |
| Actual game configure | Failed at `find_package(SDL2)`; no Windows SDL2 development package found |
| Windows syntax check of `mips_formatter.c` | Fails on unconditional `sys/mman.h` |
| Windows syntax check of `x11_nograb.c` | Fails on unconditional `dlfcn.h` |
| Windows game link/package | Not reached; no Windows game artifact |
| Windows runtime/gameplay/save/Continue | Not performed; no safe Windows/Wine runtime identified |

No dependencies were installed. Zig has cached Windows headers/CRT. The
available SDL3 SDK is not the SDL2 dependency this build uses. No Windows
SDL2/OpenAL/OpenSSL development libraries, standalone MinGW compiler, Wine,
proven sibling workflow or existing BFM Windows package was found in the
inspected local locations. The coordinator was promptly sent the blockers
and asked to identify an authorized, unoccupied Windows verification route.

## Required implementation before Windows qualification

1. Provide pinned Windows SDL2, OpenAL, OpenSSL Crypto and zlib dependencies,
   with licenses/source obligations preserved. Keep target libraries separate
   from the Linux host libraries.
2. Parameterize `tools/native_lane_gen.py`'s hardcoded
   `x86_64-unknown-linux-gnu` target, including the empty-object path, and
   verify CMake's existing compiler/archive plumbing for the Windows target.
   Verify COFF/Win64 ABI and unchanged admission policy;
   a Windows CMake toolchain alone currently still generates Linux objects.
3. Implement shared Windows guest memory and scratchpad alias mapping in
   `musashi_native_lane_map_guest`, retaining the guard page and refusal
   semantics. Replace Linux `memfd_create`/`mmap` and native-boot
   `mprotect`/`sigaction` fault handling with validated Windows equivalents.
4. Make X11/glibc interposition Linux-only; select and validate Windows SDL
   entrypoint handling and necessary environment/path/filesystem wrappers. Preserve the existing
   Windows APPDATA storage intent. Fix Windows card replacement's current
   remove-then-rename sequence before qualifying save safety.
5. Build the complete game target, verify imports and package contents, and
   qualify native ABI/guard/unwind probes plus isolated forest, village,
   attract, save and cold Continue on an unoccupied supported test runtime.
   Distinguish Wine, actual Windows, compile and package evidence explicitly.

Disabling the native lane is not a solution: the formatter still requires
Linux headers, and it would discard the qualified gameplay coverage. Do not
publish a renamed Linux binary, the platform-name probe, or an untested game
binary as Windows support. Public notes must continue to disclose the hybrid
runtime and known refusal/coverage limits on either platform.

## Coordinator constraints and audit completion

The coordinator confirmed no known authorized Windows runner/toolchain on
2026-10-02. blizzpc is Linux without MinGW/Wine/Zig in PATH; the Alienware
is occupied and excluded. No new compiler, library, Wine or container may
be installed before the owner's decision. The devbox's existing Zig binary
was identified from its symlink; this follow-up reused saved probe logs and
read source only, without invoking a compiler or accessing a runner.

See [short portability report](WINDOWS-PORTABILITY-SUMMARY-2026-10-02.md) for
build requirements and possible runtime qualification after authorization.
The public r38 release was read back and still explicitly says Windows is
unavailable. This audit does not establish Windows gameplay compatibility.
