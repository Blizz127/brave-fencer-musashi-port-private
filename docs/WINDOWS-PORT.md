# Windows host-port plan

**Status, 2026-10-02: deferred to a separate, owner-scheduled task.**
The Linux r38 release is complete. Stop waiting for a Windows runner; no
Windows implementation, toolchain/library installation or runner provisioning
is authorized by this plan. Preserve the owner's occupied Alienware.

## Evidence already recorded

Baseline examined: `61c60516d18bf6402e6dbd937d8c8d18ebd1af4b` (r37/r38 runtime).
Existing devbox Zig 0.13.0 produced a COFF platform-name adapter and passed
CMake C/C++ compiler detection. The game configure failed at Windows SDL2;
syntax checks failed on `sys/mman.h` and `dlfcn.h`. No Windows game linked,
ran, passed its retail scan or qualified for publication.

Saved commands, logs and SHA-256s:
`~/release-staging/bfm-r38-public/windows-audit/RESULT.json` and adjacent
`toolchain.cmake`, `configure.log`, `formatter-compile.log`, `x11-compile.log`.
See [detailed audit](WINDOWS-RELEASE-2026-10-02.md) and
[short findings](WINDOWS-PORTABILITY-SUMMARY-2026-10-02.md).

## Work items and rough size

Planning estimate: **roughly 2–4 engineer-weeks after dependencies and a
separate test runtime are approved and available**. This is a low-confidence
scope estimate, not a delivery commitment; Windows mapping/ABI and graphics
issues can increase it. Approval/provisioning wait time is excluded.

| Work item | Scope | Rough effort |
|---|---|---|
| Toolchain and dependencies | Establish Windows x64 compiler/linker/CRT/import libraries; pinned SDL2, OpenAL Soft, OpenSSL Crypto, OpenGL support and zlib for current PNG features. Verify licenses and DLL dependencies. Existing Zig is only a candidate. | 1–2 days |
| Native generator and ABI | Parameterize Linux target and empty-object path in `tools/native_lane_gen.py`; validate existing CMake compiler/archive plumbing, COFF output, Win64 calls/returns and unwind behavior. Preserve admission/digest guards. | 2–4 days |
| Guest mappings and faults | Replace `memfd`/`mmap` shared fixed-address guest/scratchpad aliases, guard protection and POSIX signal handling with Windows equivalents preserving guest alias/refusal semantics. | 3–5 days |
| Host integration and saves | Condition X11/glibc hooks; resolve SDL entrypoint, environment/path/time wrappers and Windows launcher/DLL layout. Preserve APPDATA and replace cards without losing the previous file on failure. | 1–3 days |
| Qualification and packaging | Run Windows probes/routes/save tests, check device behavior and retail/data guards, then package/read back a separately identified candidate. | 3–5 days |

Use a qualified Linux baseline chosen when the task is scheduled. Do not
disable the native lane merely to obtain a build or claim native completion;
the current playable runtime is hybrid. Keep Linux behavior and existing
saves intact. Windows publication requires its own qualification and release
decision; no Windows artifact is promised for r38.

## Test route without the owner's desktop

After explicit owner scheduling and provisioning approval, use a dedicated
Windows x64 runner or VM with a separate graphical session, lawful locally
held disc data and isolated test cards. No such runner is currently authorized.
blizzpc is Linux; the occupied Alienware is excluded.

1. Compile/link all game targets, inspect PE imports/DLLs, and run ABI,
   alias/guard/refusal and unwind probes on actual Windows.
2. Run isolated forest, village and attract routes against the chosen Linux
   baseline, preserving known refusal and timing disclosures.
3. Save, quit and cold Continue; inject card-write/replace failures and verify
   the previous card survives. Never use the owner's live card.
4. Check graphics, audio, input and timing in the runner's own session.
   Headless/null-audio results do not establish hardware fidelity; Wine
   results, if separately authorized, remain distinct from Windows results.
5. Run rights/retail-data checks on the exact package; verify artifact hashes,
   launch contract and update detection before any separately authorized release.
