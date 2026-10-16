# BFM Windows host port — design

Status, 2026-10-02: a side track on branch `windows-port` in the `~/dev/bfm-windows`
worktree. Linux stays the primary target. Its owner (the BFM Codex lane) is the only
writer of Linux release branches, and any shared-file change here reaches it as a
proposed patch.

This document builds on `docs/WINDOWS-RELEASE-2026-10-02.md` and on the
cross-compile audit in `release-staging/bfm-r38-public/windows-audit/RESULT.json`.

## Goal and non-goals

- **Goal:** `musashi_native_boot.exe` for x86-64 Windows 10+. It runs the same
  production path as Linux:
  - native-lane functions compiled to host code;
  - the existing interpreter for code the lane does not yet cover (interim, disclosed);
  - the PsyCross/SDL2/OpenAL/GL presenter.
- **Same disclosures as Linux.** The Windows build is hybrid exactly where Linux is.
  No Windows-only claim of native coverage. Lane coverage, refusals and fallback
  counts are reported per build.
- **Not in scope:**
  - X11 grab interposition (Linux-only by nature);
  - the dlopen mods ABI on Windows (phase 2, `LoadLibraryW`);
  - code signing;
  - a public release.

## Linux-specific surface, measured

Measured on 402cf86301.

| Area | Where | Linux mechanism | Windows mechanism |
|---|---|---|---|
| Guest RAM at fixed VA | `mips_formatter.c` `musashi_native_lane_map_guest` | `memfd_create`+`ftruncate`+`mmap(MAP_FIXED_NOREPLACE)` at 0x80000000; same page mapped again at 0x1F800000 (scratchpad alias) | `CreateFileMappingW(INVALID_HANDLE_VALUE)` sized RAM+64 KiB; `MapViewOfFileEx` at 0x80000000 (RAM) and at 0x1F800000 (offset 2 MiB, 64 KiB view). Both bases are 64 KiB-aligned (allocation granularity). If a view does not land at the requested address, refuse, exactly like `MAP_FIXED_NOREPLACE` failing |
| Guard page | `native_boot.c` `native_boot_owner` | `mprotect(ram_mirror_guard, PROT_NONE)` | `VirtualProtect(PAGE_NOACCESS)`. The guard must sit in a private `VirtualAlloc` region, not inside the section view: protections on section views need care |
| Host fault report | `native_boot.c` `lane_fault` | `sigaction(SIGSEGV/SIGBUS, SA_SIGINFO)` → `HOST_FAULT addr= lane_pc=` → re-raise, exit 139 | `AddVectoredExceptionHandler(1, …)` on `EXCEPTION_ACCESS_VIOLATION` (fault address = `ExceptionInformation[1]`) → same line → `TerminateProcess(…, 139)`, so the gate scripts see the same code |
| Host stop | `native_boot.c` `request_host_stop` | `signal(SIGTERM/SIGINT)` sets a flag | Already flag-only, so it ports. Add `SetConsoleCtrlHandler`, which sets the same flag (it runs on another thread; flag only, no longjmp) |
| Lane abort | `mips_formatter.c` `longjmp(active->abort, n)` | glibc setjmp | Win64 `longjmp` unwinds via SEH and needs `.pdata` for every frame. Clang emits it for all lane objects and host code by default; add a check that every lane `.o` carries `.pdata` |
| SDL window properties | `native_boot.c` ~5011 `dlsym(RTLD_DEFAULT, "SDL_SetWindowFocusable"…)` | dlfcn | Optional SDL3-era symbols; on Windows `GetProcAddress(GetModuleHandleW(L"SDL2.dll"))` or compile-out |
| X11 grab shim | `x11_nograb.c` (395 lines, shared lib) | `dlsym(RTLD_NEXT)` X11 interposer | Linux-only target; CMake skips it under `WIN32` |
| Plugins | `bfm_plat_mods.c` | `dlopen` + `dirent` | Already has `_WIN32` pieces. Phase 2: `LoadLibraryW` + `FindFirstFileW`. Phase 1 builds with plugins disabled and reports it |
| Paths | `bfm_plat_config.c`, `native_boot.c` | `XDG_*`/`HOME` | `SHGetKnownFolderPath(FOLDERID_RoamingAppData)` → `%APPDATA%\bfm-port\…`. Same relative layout (`state/bfm-port/bfm_card0.mcd`) |
| Card replace | `bfm_plat_storage.c:382` | `rename(tmp, path)` (atomic) | The current `_WIN32` branch removes the old card *then* renames, which loses the save if a crash lands in between. Use `MoveFileExW(tmp, path, MOVEFILE_REPLACE_EXISTING \| MOVEFILE_WRITE_THROUGH)` |
| Timing | `bfm_plat_timing.c` | `clock_gettime(CLOCK_MONOTONIC)`, `nanosleep` | `_WIN32` branch exists. Verify it uses QPC and a high-resolution waitable timer, not 15.6 ms `Sleep` granularity (this is a frame-pacing risk) |
| SHA-256 | `boot_memory.c`, `bios_exception.c`, `native_boot.c` | OpenSSL `EVP_Digest`/`SHA256` | Switch to the in-tree `bfm_plat_sha256.c`, which removes OpenSSL from both targets. Linux digests must be byte-identical (unit test against the OpenSSL output) |
| `long` width | 70 sites in `pc_port` | LP64 (64-bit) | LLP64 (32-bit). Host code: audit any `long` holding a pointer or size. Lane code: moot, `host_long` already rewrites decomp `long` to `int` |
| Native-lane target | `tools/native_lane_gen.py` `HOST_TARGET`, `-fPIE` | x86_64-unknown-linux-gnu ELF | `--host-target x86_64-windows-gnu` sets only the **object** triple (see "Native lane on Win64" below); GNU `nm`/`ar` read COFF |

## Native lane on Win64 (implemented, W3)

Every admission check still runs on the x86-64 SysV IR. Only the final
object compile targets Win64. The reason is that Win64 IR has no
`signext`/`zeroext` attributes, while the generator reads the C signedness of
narrow arguments and returns from them. That signedness feeds the dispatch
table's prototypes, `to_guest()` (sign-extension into v0) and the call-stub
names.

When the first attempt compiled the IR for Win64 directly, decisions matched
but 201 table prototypes lost their signedness (`int16_t` → `uint16_t`). A
signed short return would then have been zero-extended into v0.

`object_ir()` drops the SysV extension promises and the triple/layout before
`clang -c --target=x86_64-windows-gnu`. This is sound for lane code because:
- lane signatures are ints and pointers only (`abi_type`);
- `long` is already `int`;
- a Win64 callee must not rely on its caller extending narrow values.

COFF objects add `-fasynchronous-unwind-tables`. `-ffreestanding` drops the
Win64 `uwtable` default, and without it a lane function gets no `.pdata`, so
the lane abort's `longjmp` (SEH unwind on Win64) could not pass through it. A
function without `uwtable` is now refused.

Result on 402cf86301 + this branch (`--overlay-members main_0003`):
- 655/785 game functions plus 30/58 overlay functions admitted, the same as Linux;
- per-function decisions, cycle ledger, pass-through and call stubs identical;
- `native_lane_table.c` byte-identical to the Linux one;
- all objects are x86-64 COFF.

The default (Linux) generator output is byte-identical to the baseline
(`libmusashi_native_lane.a`, `native_lane_table.c`).

## Work items

Each step lands with the Linux gates green before the next one starts.

| # | Item | Size | Linux effect |
|---|---|---|---|
| W1 | `pc_port/host/` seam: `bfm_host_map_guest`, `bfm_host_guard_page`, `bfm_host_install_fault_report`, `bfm_host_on_stop`, `bfm_host_lib_sym`. Linux implementation = today's code, moved | ~250 lines | none; pinned hashes unchanged |
| W2 | In-tree SHA-256 replaces OpenSSL (three call sites) | ~40 lines + test | drops the OpenSSL link; digests identical |
| W3 | `native_lane_gen.py --host-target`; tool selection (`nm`/`ar`), `-fPIE` only for ELF; `.pdata` check for COFF | ~60 lines | default stays Linux; generator output byte-identical |
| W4 | Windows host implementation (`host/win32.c`): section mapping, VEH, console ctrl, `GetProcAddress` | ~250 lines | none |
| W5 | Paths/APPDATA, `MoveFileExW` card replace, timing check, `long` audit | ~150 lines | none (`#ifdef _WIN32`) |
| W6 | CMake toolchain file `cmake/zig-windows.cmake` (`zig cc -target x86_64-windows-gnu`), `WIN32` target split | ~80 lines | none |
| W7 | Cross-build `musashi_native_boot.exe` with the lane; import audit; package (exe + SDL2.dll + OpenAL32.dll + licences) | build | none |
| W8 | Runtime qualification: Windows lane probes, host_stop probe, village + attract routes, native vs deny | runtime | needs Wine or a Windows host (see "Test route") |

W1–W3 and W5–W6 need nothing new. W7 needs the SDL2/OpenAL Windows dev
packages. W8 needs a Windows runtime.

## Test route that needs no owner desktop

1. **Compile/link (available now):** zig 0.13 at `~/.local/bin/zig` cross-compiles
   to PE32+ (UCRT). Checked 2026-10-02 with a probe that uses
   `CreateFileMappingW`/`MapViewOfFileEx` at 0x80000000 and 0x1F800000 plus
   `AddVectoredExceptionHandler`. It links, and `objdump -p` lists only
   `KERNEL32.dll` and `api-ms-win-crt-*` imports.
2. **Static gates (available now):**
   - `objdump -p` import allow-list: KERNEL32, USER32, GDI32, SHELL32, OLE32, OPENGL32, WINMM, IMM32, SETUPAPI, VERSION, ucrt api-sets, SDL2.dll, OpenAL32.dll;
   - no undefined lane symbols;
   - `.pdata` present in every lane object;
   - lane counts reported.
3. **Linux regression (blizzpc runner, only when Linux gates are idle):**
   - the W1–W3 refactor must give byte-identical `musashi_native_boot` hashes where the code is unchanged, or else identical DEVOBS/RAM/PAD on the village and attract routes;
   - lane_all/overlay/host_stop probes unchanged.
4. **Runtime:**
   - (a) Wine on this dev box (owner-installed wine-10.0, prefix `.wineprefix` in this worktree), with a private `xvfb-run -a` X server and Mesa GL. It never touches a desktop. The probes (lane_all, overlay, host_stop) are console programs; routes run with the SDL dummy video driver and the existing capture shim. Wine is not a Windows qualification. It finds gross breakage only, and its results are reported as "Wine".
   - (b) The real gate is a Windows VM or test machine (not the owner's desktop) for routes, plus one owner-visible smoke run when the owner wants it.

## Dependencies needing approval (not downloaded)

| Item | Exact source | Size | Why |
|---|---|---|---|
| SDL2 2.32.10 MinGW dev | `https://github.com/libsdl-org/SDL/releases/download/release-2.32.10/SDL2-devel-2.32.10-mingw.tar.gz` | ≈ 15 MB | headers + import lib + `SDL2.dll`; same version as the Linux build |
| OpenAL Soft 1.25.1 binaries | `https://openal-soft.org/openal-binaries/openal-soft-1.25.1-bin.zip` | ≈ 5 MB | `OpenAL32.dll` + import lib; same version as Linux |
| Wine (runtime smoke only) | Ubuntu 26.04 `apt install --no-install-recommends wine64` (10.0~repack-12ubuntu1) | 68 packages, ≈ 1.2 GiB installed | headless smoke of the cross-built exe; needs sudo, so the owner must approve |

zlib stays optional (PNG texture replacement), so it is left out of phase 1.
OpenSSL is not needed after W2.

## Status (2026-10-02)

| # | State |
|---|---|
| W1 host seam | done; Linux code moved unchanged |
| W2 SHA-256 | done; OpenSSL no longer linked |
| W3 lane target | done; Windows decisions and table equal Linux, objects COFF |
| W4 Windows adapter | done (section views, VEH + unhandled filter, GetProcAddress) |
| W5 paths/card/timing | card replace atomic. Cache in `%LOCALAPPDATA%\bfm-port`, screenshots in `%USERPROFILE%\Pictures`, card dirs accept `\` and drive prefixes. Timing uses `Sleep()` at ms granularity. SDL2 raises the system timer to 1 ms (`SDL_HINT_TIMER_RESOLUTION`); frame pacing still has to be measured on real Windows |
| W6 CMake/zig | done; `-s` link (see retail note) |
| W7 package | `tools/package_windows.sh`: zip with allow-listed imports, licences, manifest, retail_guard. Since 2026-10-03 it emits the r40 owner-test contract: launch.cmd honours launcher-managed `BFM_DISC`/`BFM_DISC_DIR` (exit 66, no picker, when they point nowhere), the full runtime notice set plus the complete OpenAL Soft source (`deps/openal/openal-soft-1.25.1.tar.bz2`, `tools/windows/licenses-reference/`), manifest `contains_game_data`/`distribution`, and a `--status` that must say "UNVERIFIED on real Windows" (publisher requirement). Regenerating r42 from the same exe reproduced the published package in 24/27 files; README/THIRD-PARTY/manifest differ in wording only |
| W8 runtime | Wine smoke only (not qualification); a real Windows machine is pending owner access |

Findings on the way:
- **Real UB, Linux too.** `cpu_ram_span` formed a BIOS-frame pointer 0x84d8 bytes past its array before subtracting. clang UBSan (zig's Debug default) trapped on it; gcc UBSan does not check pointer arithmetic. It is fixed and the fix is proposed to the Linux writer.
- **Retail bytes in the exe.** zig links with `/DEBUG`, so lld-link keeps unreferenced COMDATs, among them LIBGTE's rcossin table (equal to the game's). A stripped link gets `/OPT:REF`; `package_windows.sh` refuses unstripped input.
- **Wine attract, interpreter-only:** equal to Linux over all 46,105 guest-trace lines, to the same refusal stop.

## Risks

- **Fixed VA collision.** ASLR or high-entropy DLL placement could take 0x80000000
  or 0x1F800000. Mitigation: map first thing in `main`, before SDL/GL load; refuse
  cleanly if either view misses; set `/DYNAMICBASE` so the image itself stays
  away from both bases.
- **SEH unwinding through lane frames on longjmp.** Mitigation: the `.pdata`
  check, plus a probe that aborts from depth.
- **LLP64 changes the lane IR, so lane coverage differs.** Mitigation: report the
  Windows lane counts on their own; parity is proven on Windows output only.
- **Frame pacing with a coarse Windows timer.** Mitigation: a waitable
  high-resolution timer, then measure speed% the same way as Linux.
