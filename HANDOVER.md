# BFM handover to Claude Opus 5.5 (2026-10-03)

## Current handoff checkpoint — supersedes historical ownership below

Owner/coordinator routing change: transfer this project from Codex to Claude
Opus 5.5. Claude starts only after the coordinator receives `HANDED OVER`.
Codex stops all project writes after that report. Do not start competing workers.
Authoritative Linux worktree: `/home/blizz/dev/bfm-port-integration`, branch
`port/native-lane`. Last code checkpoint is `d52d99922a` (standalone BIOS scratch
pointer UB fix); last recorded checkpoint before this handover is `3a1f5e61d2`.
The handover commit is the latest local commit touching this file. No push.

Original matching-source worktree `/home/blizz/dev/brave-fencer-musashi-decomp`
on `main` was `a4b343946b`; its root HANDOVER is a pointer to this authoritative
handover, not a request to merge private runtime source into public main.
Qualified Linux release worktree `/home/blizz/dev/bfm-r36` is branch
`release/r37`, source `61c60516d18bf6402e6dbd937d8c8d18ebd1af4b` (directory
name is historical). Preserve it and qualified packages. Windows source remains
separate task `ce62b0f3dc66`, `/home/blizz/dev/bfm-windows`, `windows-port`;
coordinate shared-file integration through the coordinator. This routing change
does not authorize another Windows writer or a new toolchain installation.

Tracked changes are committed. Pre-existing untracked integration control files
`AGENTS.md`, `CLAUDE.md` are preserved. Original source worktree also has existing
untracked `-`, `AGENTS.md`, `CLAUDE.md`, `tools/patches/psycross-local.patch`.
These were not deleted, moved, hidden or included in the handover commit.
There is no unfinished Codex runtime edit or uncommitted publisher edit.

## Latest private/public publication state

- Linux private is **r41** (2026-10-03 06:20Z), build `bfm-r41-3634893fe`,
  source `release/r41` 3634893fe1 (= r37 + B18 main_0012 native admissions,
  D-011 overlay deadline guard, D-043 route-proof rule, pass-through prototype
  fixes, BIOS UB fix), 8,300,787 bytes,
  SHA `90fc5307023cb9ce19583980e9dade79f6988be8a98a67e3bfb38c4174ed4c25`.
  Receipt `/home/blizz/release-staging/bfm-r41/RECEIPT.txt`: full combined gate
  (67/67 checks), eager-epoch route proof, interleaved speed vs r37, launcher
  detection r37->r41. r37 (`bfm-r37-61c60516d`, receipt
  `/home/blizz/release-staging/bfm-r37/RECEIPT.txt`) stays as rollback.
- Windows owner-test is **r42** (2026-10-03 05:16Z), `bfm-r42-d0ac23d9c-windows-x64`
  (windows-port d0ac23d9ce: cue FILE entries resolved against the cue folder for
  backslash/drive paths; fixes r40's "disc.bin is missing" from the launcher),
  3,998,185 bytes, SHA `007378926fbb266c53179118cf060bb2e7b5c268b948ffe094eb4dfca1aee205`,
  receipt `/home/blizz/release-staging/bfm-r42-windows/PUBLISH-RECEIPT.json`.
  Package = live r40 with only the EXE/README/THIRD-PARTY/manifest changed;
  `tools/package_windows.sh` on windows-port (26380e9408) now emits that
  contract. The Linux publisher keeps the Windows leaf
  (`claude/private-port-builds` 391ca9b). Still UNVERIFIED on real Windows.
- Earlier state (superseded): Linux private r37 since 2026-10-02; qualified forest,
  village/attract, inn save and isolated cold Continue gates banked there.
- Windows owner-test **r40 is LIVE** in the same owner-only bucket channel,
  build `bfm-r40-b33bdee18-windows-x64`, source
  `b33bdee18e852d255e86fbf862bd74572c8d243b` plus staged packaging/script updates.
  ZIP **3,997,835 bytes**, SHA
  `b10d2870a4dc0862e858bba567e935de1ff984467ec615fd23f8fc24014b05e2`.
  Key `brave-fencer-musashi/builds/bfm-r40-b33bdee18-windows-x64/bfm-r40-b33bdee18-windows-x64.zip`.
  **UNVERIFIED on real Windows**, owner waived that gate for private testing
  only, not licence gates. No GitHub Windows release/tag was created.
- Channel `brave-fencer-musashi/channel.json` stays schemaVersion 2. ALL
  top-level Linux fields are unchanged. Only optional `artifacts.windows-x64`
  was added: `version`, `packageKey`, `sha256`, `packageSize`, `archiveFormat:zip`.
  No `platforms`, commands, URLs or credentials; optional Windows publishedAt
  omitted. Signed full ZIP and channel GET readback passed; unsigned object
  request denied with Authorization error. Actual gated selector source with
  live JSON selects Windows r40/Linux r37, no Windows fallback, x64 enforced.
- Launcher **0.9.240+ required** for Windows, gated source `8b0edc99d4957ed3399749ec95ee421a8bca75aa`.
  Gate `/home/blizz/scratch/bfm240-final/receipt.json`: build 0 warnings/errors,
  2199 passed, 16 pre-existing failures, none new; old 238 parser ignores extension.
  This is a gated source/framework build, not a claim the owner has the packaged
  launcher installed. Launcher packaged delivery remains its integrator's job.
- Final Windows evidence `/home/blizz/release-staging/bfm-windows-owner-test-b33bdee18/`:
  `PUBLISH-RECEIPT.{json,txt}`, `signed-readback.json`, `channel-live-readback.json`,
  `live-selection-proof.json`, `LAUNCHER-CONTRACT.json`, `R40-RECEIPT.txt`.
  Rollback remote `brave-fencer-musashi/channel.json.bak-20261003T013219Z`, local
  `brave-fencer-musashi-channel-before-20261003T013219Z.json` there; exact old
  bytes verified. Older r0/r39 and rejected intermediate ZIPs retained as evidence.
  Keep Linux r30–r34 rollback; do not delete existing packages.
- r40 EXE/SDL2/OpenAL DLLs are unchanged from side-lane test build; complete
  matching OpenAL Soft 1.25.1 upstream source, PFFFT/fmt/GSL notices, SDL2 notice
  and Zig/mingw/LLVM/musl runtime notices added. Final retail guard 27 files/0.
  Script now honours BFM_DISC or BFM_DISC_DIR/disc.cue, returns66/no picker for
  missing explicit env inputs, and safely remembers paths with spaces/&/!.
  Five isolated headless Wine cmd tests use a stub child, not a game runtime.
- Existing owner-only data pack `brave-fencer-musashi/data/manifest.json` is
  already uploaded; no new data upload occurred. Launcher restores game-root
  `disc/disc.cue` plus adjacent `disc.bin`, `disc/files/SLUS_007.26`; cue FILE is
  exactly `disc.bin`. ZIP has one enclosing build-name directory, entry
  `launch.cmd`, binary `musashi_native_boot.exe`. Launcher passes absolute
  BFM_DISC/BFM_DISC_DIR and no custom Windows args. Saves/config/logs default
  `%APPDATA%/bfm-port`, card `bfm_card0.mcd`; launcher does not relocate them.
- Private publisher worktree `/home/blizz/dev/banshee-realm-client-private-builds`
  on `claude/private-port-builds`, local commit
  `fd0716cc27e8049c33e023593c8e99ab419dc16a`: script
  `scripts/publish-owner-port-package.py --windows-zip ZIP --port musashi
  --build-id ID --commit COMMIT --sha256 SHA [--dry-run]` adds only the leaf,
  validates manifest/hash, protects immutable objects, keeps rollback, checks
  full upload size/SHA and channel concurrency/readback. 14 publisher +7
  existing private-release tests pass. Do not use the older tar-only mirror
  to replace this channel and accidentally drop the Windows extension.
- Public **r38 stays Linux-only**, exact qualified r37 runtime; tar 9,647,813
  bytes, SHA `6b2f95732a2da966bfd876d478bf1b7a4464258a236b75be4990739d7a0a831a`.
  Receipt `/home/blizz/release-staging/bfm-r38-public/RECEIPT.txt`. Public docs
  main `7da1b3c55860513c7a612311675396dae29ba969`; wiki
  `e2b2f10e0fa1fb519cc3c7f4db6eabc62617742a`. No private source/history push.

## Milestone, owner goal and blockers

Owner endpoint is native gameplay/engine executed as compiled host code, with a
useful playable slice demonstrated with the CPU interpreter disabled/absent,
zero fallback and semantic/visual/audio/timing/save evidence, then broader coverage.
**Not achieved.** Current useful builds are HYBRID. Retail/vendor-derived routines
not admitted for rights or semantic reasons remain interpreted; native BIOS/HLE
services do not make the whole game native. Unsupported/stubbed paths and known
800495ec attract refusal remain disclosed. Null/KUSEG gap, 48 approximate cycle
charges and full hardware audio/visual fidelity remain open. No measured share
of production executed guest instructions/frames/time native vs interpreted.
Release candidate census is 562/593 functions (94.77%), 17022/18556 words (91.73%)
within the selected lane candidate set; these are NOT whole-retail coverage or
executed workload shares. No useful interpreter-disabled zero-fallback slice yet.

B18 is resolved (3634893fe1, `docs/B18-TIMING-2026-10-03.md`: the attract
DEVOBS differences were the deny leg's thunk-return IRQ hold, D-043) and shipped
in r41. The strict interpreter-free build option (`MUSASHI_STRICT_NATIVE`,
`docs/STRICT-NATIVE-BUILD.md`) is the acceptance tool for the zero-fallback
slice; a release-configuration executed-share trace of r41 follows.
Historical text of the B18 milestone: deferred **B18 timing mismatch** at
`main_0012:8014C99C`: village equal; attract72 DEVOBS differences, RAM/PAD equal.
Local old route archive lacks full DEVOBS streams; do not pretend the historical
3-IRQ/2-cycle explanation was independently reconstructed. Add focused overlay
deadline regression: existing native_lane_guard_probe covers main only, overlay
probe compares call/return timing. Keep B18 out of releases pending fresh eager
epoch village/attract evidence. Integration contains B18 admission/B19 source;
integration build is not automatically the qualified r37 release.

Shared Windows patches0001–0005 remain UNAPPLIED pending refreshed test linkage
and docs collision fixes. Only standalone UB patch accepted as d52d99922a.
See `docs/WINDOWS-PATCH-REVIEW-2026-10-03.md`: SHA replacement breaks direct-link
Python harnesses (undefined bfm_plat_sha256_final;47 files mention -lcrypto),
and patch0005 creates existing docs/WINDOWS-PORT.md. Require complete Linux review,
probes/routes/release gates before shipping. Packaging libcrypto cleanup must
follow actual dependency audit. Windows lane should incorporate staged
`launch-disc-env.patch` into its generator when resumed; current live ZIP script
is an intentional packaging-only update, not a Windows source-branch commit.

## Build, test, run and runner collection

No new job was started for handover. No Codex BFM local child or runner job is
in flight. Read-only check of blizzpc running/queue found no BFM job; relevant
process listing likewise empty. Do not stop other projects' jobs or owner game.
The completed r37 gate is `20261002-154305-bfm-r37-gate-61c60516d-1141388`;
local job/script/evidence are `/home/blizz/release-staging/bfm-r37/{job.txt,gate.sh,gate-evidence.tar.gz}`.

Linux integration cached development build (main_0003 overlay only):

```sh
cd /home/blizz/dev/bfm-port-integration
cmake -S . -B build/lanes/owncode -DCMAKE_BUILD_TYPE=RelWithDebInfo -DMUSASHI_NATIVE_LANE=ON -DMUSASHI_LANE_OWN_CODE_ONLY=ON -DMUSASHI_WITH_PSYCROSS=ON -DMUSASHI_LANE_OVERLAY_MEMBERS=main_0003
cmake --build build/lanes/owncode -j2
ctest --test-dir build/lanes/owncode --output-on-failure
python3 -m pytest -q tests/test_input_bios_callback.py
```

Offload heavy builds/gates rather than run large local jobs. Existing callback
probe passes GCC and Clang UBSan/bounds with unrelated pre-existing warning
errors downgraded diagnostically; unmodified pytest currently fails GCC
Wclobbered at lane_try. Clang also needs its unrelated unused declaration
warning downgraded. No source/test harness change concealed those warnings.
Native lane configuration is release-specific; r37 uses own-code-only
main_0003+main_0012 (93 selected overlay pairs), baseline and x86-64-v3.
Use banked release job/script as the exact recipe; do not broaden the integration
allowlist into a release accidentally. package_legion.sh takes --binary,
--binary-v3, --run, --out, --status plus retail --exe/--extracted references;
BFM_PKG_COMMIT/BFM_PKG_BRANCH must match exported source.

Authorized headless host `blizz@100.87.173.93` (blizzpc). Use one BFM slot;
chain work under existing runner. Current runner.conf read at handoff:
CPU_QUOTA450%, MEM_MAX3G, timeout default6h, nice19/idle IO, thermal start<90C,
gaming max1 aggregate slot, disk free floor30GiB and runner30GiB cap; memory
headroom2GiB above slot cap. Runner README contains older limits; config and
guards take precedence. Do not loosen caps or use occupied Alienware/desktop.

```sh
ssh blizz@100.87.173.93 '~/devbox-runner/bin/submit bfm-NAME' < job.sh
ssh blizz@100.87.173.93 'ls ~/devbox-runner/jobs/running ~/devbox-runner/jobs/queue'
ssh blizz@100.87.173.93 'cat ~/devbox-runner/logs/JOB.exit; tail -80 ~/devbox-runner/logs/JOB.log'
scp blizz@100.87.173.93:devbox-runner/work/JOB/evidence.tar.gz ./
```

Assert package SHA inside every job. Existing disc on runner at
`~/devbox-runner/gamedata/bfm/disc.cue`; use in place, no new transfer. Run with
DISPLAY/WAYLAND_DISPLAY/XAUTHORITY unset, SDL_VIDEODRIVER=offscreen,
EGL_PLATFORM=surfaceless, MUSASHI_AUDIO=null, MUSASHI_INTERACTIVE=0;
isolate HOME/XDG state/config/cache and cards inside job work dir. Gating includes
forest captures, native-vs-denied village/attract DEVOBS/RAM/PAD, inn save and
separate cold Continue. Ordinary host-stop exit/abort must be distinguished from
runtime refusal/fault; see completed gate summaries. No physical audio/pad fidelity
claim from null/headless tests. Let any later owner-authorized jobs finish and
collect via logs/work above; never cancel another lane's jobs.

Everything below is retained historical context, with ownership, live releases,
Windows availability and caps superseded by this checkpoint.

## Windows patch handoff review, 2026-10-03

Standalone BIOS callback scratch-pointer UB fix accepted as `d52d99922a`.
Existing callback probe passes GCC and Clang UBSan/bounds with unrelated
pre-existing warning errors downgraded for those diagnostic runs. Series
0001–0005 is held for missing in-tree SHA linkage in Python probe harnesses
(boot-memory setup reproduced an undefined SHA symbol) and an existing
`docs/WINDOWS-PORT.md` path collision. Details and required follow-up:
[shared patch review](docs/WINDOWS-PATCH-REVIEW-2026-10-03.md).
No route/release gates or publication were performed for this handoff.

## Current ownership, 2026-10-03

Codex is the sole **Linux writer/integrator**. Windows implementation is owned
by separate task `ce62b0f3dc66`, the BFM Claude lane in `~/dev/bfm-windows`,
branch `windows-port`. Stop Windows work in this lane. Shared-file changes
from Windows must arrive as proposed patches through the coordinator before
Linux integration. The coordinator reports SDL2/OpenAL dependencies and
wine64 are already present in that side worktree; this lane made no installs.
Resume Linux/native work under efficient routing. The earlier Windows audit
and planning documents are historical findings, not an active Codex task.

## Public documentation published, 2026-10-02

The coordinator resolved the documentation-only public exception and explicitly
permitted Linux publication when no qualified Windows artifact exists. Public r38
README/setup and wiki are now **LIVE and verified**:

- README: https://github.com/Blizz127/brave-fencer-musashi-decomp-port/blob/main/README.md
- Setup: https://github.com/Blizz127/brave-fencer-musashi-decomp-port/blob/main/docs/SETUP.md
- Dev menu: https://github.com/Blizz127/brave-fencer-musashi-decomp-port/wiki/Dev-Menu
- Milestones: https://github.com/Blizz127/brave-fencer-musashi-decomp-port/wiki/Milestones

Public docs main `831e5e889827693be9a1bea6a1145b3e0ef04cfc` changes only README and setup Markdown;
wiki master `e2b2f10e0fa1fb519cc3c7f4db6eabc62617742a` changes only Home, Dev-Menu and Milestones.
No private source/history was pushed. Release notes explicitly say Linux-only,
name the outstanding Windows implementation/dependency/runtime work and link the
guides. Runtime source, release tag target and both assets are unchanged.

Five raw files matched local hashes, five rendered URLs returned200, remote heads
matched, and fresh anonymous release asset downloads matched the existing size/SHA.
Source/package reviews, local links and all29 warp labels passed. No runtime gates
were duplicated; no owner game/desktop actions. Receipt:
`~/release-staging/bfm-r38-public/public-docs/RECEIPT.txt`.
Windows is now deferred to a separate owner-scheduled host-port project.
No Windows route is awaited and r38 release work is complete. Return to normal
BFM work with the same sole writer and efficient routing. Native conversion stays open.

Normal BFM work resumes with the deferred B18 timing mismatch at overlay
`main_0012:8014C99C`. The recorded route summary confirms village equality
and 72 attract DEVOBS differences with equal RAM/PAD; the local archive does
not contain the full DEVOBS streams. The next focused step is an overlay
deadline regression: `native_lane_guard_probe` currently covers main entries
only, while `native_lane_overlay_probe` compares call/return timing. Keep B18
out of release builds until eager-epoch village and attract proofs pass.

The follow-up read-only Windows audit is complete; the short report is
[Windows portability summary](docs/WINDOWS-PORTABILITY-SUMMARY-2026-10-02.md).
No new compiler invocation, download, install or runner access was used.
No Windows runner is authorized, the occupied Alienware is excluded, and the
future Windows task must explicitly authorize any toolchain/dependency
installation. Public r38 says Windows is unavailable. Work items, rough effort
and a test route avoiding the owner desktop are in [WINDOWS-PORT.md](docs/WINDOWS-PORT.md).

## Codex continuation, 2026-10-02 20:00 UTC

Codex acknowledged task `df2840be6532` and is the sole writer. The forest
fault is now isolated and fixed: two interpreted SWC2 instructions read the
lighting control bank instead of data IR3, corrupting the final element of
camera/object matrices. Ten GTE regression tests pass, including a mutant
that restores the fault. Matched diagnostic forest runs now have **0/647 dark
presents**, versus 22/647 before (mash) and 10/647 before (idle). Captured
formerly dark frames show the forest and player. Evidence, limits and corrections
to the initial hypotheses below: [forest investigation](docs/FOREST-SWC2-2026-10-02.md).

**r37 is now LIVE owner-only**, published 2026-10-02T21:05:59.548006+00:00: `bfm-r37-61c60516d`,
source `61c60516d18bf6402e6dbd937d8c8d18ebd1af4b`. It includes the narrow
packed-coordinate admission and passed the complete packaged gate. Artifact
8,244,817 bytes, SHA `4bb186e5010e1a04f2c739ac9e7a86d6ab33031616bfdf145934fcd11698a87e`.
GitHub/bucket/channel readback and launcher Private upgrade detection passed.
Receipt: `~/release-staging/bfm-r37/RECEIPT.txt`. r34 is rollback; r35/r36 remain
held and unpublished. B18 stays deferred; the native-only milestone remains open.

**Public r38 is now LIVE**, published 2026-10-02T21:35:28Z on the owner's
explicit public-release instruction (Devbox message `ca58a91adbc1c261`):
https://github.com/Blizz127/brave-fencer-musashi-decomp-port/releases/tag/bfm-r38-61c60516d
It promotes the exact qualified r37 runtime: both executables, all libraries
and `launch.sh` are unchanged. Only package identity/docs and dependency
license/source material changed. Public tarball is 9,647,813 bytes, SHA
`6b2f95732a2da966bfd876d478bf1b7a4464258a236b75be4990739d7a0a831a`.
Both assets passed anonymous readback; GitHub Latest and launcher Public
upgrade selection passed. Receipt: `~/release-staging/bfm-r38-public/RECEIPT.txt`.
Private remains r37; all rollback builds remain available. The public tag
targets the existing sanitized snapshot `ec620c78dd5f68a166f6565f7c2d8539e9c378a0`,
while the runtime source is `61c60516d18bf6402e6dbd937d8c8d18ebd1af4b`;
this source-snapshot limitation is explicit in the public notes. Never push
the private development tree/history to that public repository.

Public packaging requires the full Apache and GPL3 texts plus corresponding
OpenAL source and Debian patches (r38 includes them under `licenses/`). The
32-byte public content scan checked 788 references: 54 short matches were
retained and classified as generic sequences, address metadata or licensed
PsyCross diagnostics; zero unresolved. Private RAM/card/capture evidence is
excluded. The completed r37 inn save/cold Continue gate supersedes the earlier
pending report; no runtime gates were duplicated for this unchanged runtime.

**Windows is deferred to a separate owner-scheduled project.** The owner's
earlier Windows+Linux clarification arrived in Devbox message `23c4f77ef5a3979a`;
the coordinator subsequently closed r38 with Linux only.
The cached Zig compiler passed a tiny Windows COFF adapter compile and CMake
compiler detection, but the game configure fails for missing Windows SDL2,
and production code requires Linux memory mapping/X11 APIs and Linux-target
native-lane objects. No Windows game binary or runtime test exists yet.
See [Windows release blockers and evidence](docs/WINDOWS-RELEASE-2026-10-02.md).
Preserve the running owner game/desktop and existing Linux release. Do not
start Windows work or wait for a route under the completed r38 request.

The established publisher worktree is restored at
`~/dev/banshee-realm-client-private-builds`, branch `claude/private-port-builds`,
commit `75c5f42bb22895bbd2abaed54b628379f1482423`. Both publisher scripts and
`ports.json` were verified byte-for-byte against the unchanged export used for
r37, retained at `~/release-staging/bfm-r37/publisher/`. The coordinator's delayed
r36 publication request is superseded by r37: r36 failed the attract gate, and
r37 fixes that earlier stop. r30-r34 remain available for rollback.
Codex remains the sole writer.
The historical handover below describes the state before this investigation.

Owner decision (relayed by the Devbox Coordinator): the BFM port, decompilation and builds
move to Codex, effective 2026-10-02. Codex is the single writer from here. Coordinator
task: **df2840be6532**. Nothing below has been pushed publicly; private pushes went only
to `Blizz127/brave-fencer-musashi-port-private` (remote `port-private`).

## 1. Published private builds (owner-only channel)

| Build | Source | Status |
|---|---|---|
| **r37** `bfm-r37-61c60516d` | `release/r37` 61c60516d18b = r35 + matrix/SWC2 + packed-copy fixes | **LIVE** owner-only |
| r34 `bfm-r34-5e0952520` | `release/r34` 5e0952520629 = r33 + pass-through call routing | rollback |
| r33 `bfm-r33-70f6117f9` | `70f6117f94` | rollback; diverges from retail (8014BDE8 pass-through bug, see 3.2) |
| r32 `bfm-r32-48abdba08` | `48abdba08c` | rollback; same 8014BDE8 bug |
| r31 `bfm-r31-3eddf31ad` | `3eddf31ad0` | rollback; ra-pin hazard (8002C410) |
| r30 `bfm-r30-e564658c0` | `e564658c0` | rollback |

- Receipts: `~/release-staging/bfm-r3{1,2,3,4}/RECEIPT.txt`; channel snapshots
  `brave-fencer-musashi-channel-before-*.json` and `-bfm-rNN-*.json` next to them.
- Publish recipe: `~/dev/banshee-realm-client-private-builds/scripts/publish-private-port-build.py
  musashi <tarball> <build-id> --commit <FULL sha, pushed to port-private> --sha256 <sha>
  --notes NOTES.md --known-issue ...` (dry-run first). Verify: upload sha, channel
  readback, launcher `PortUpdatePolicy` revision upgrade (rN -> rN+1).
- Rules in force: owner-only private channel only; never reuse a label; no public push;
  no forced update; keep previous builds for rollback; no launchModes declared (Original
  only); disclose hybrid status in the notes.
- r31/r32 release BODIES were corrected in place on 2026-10-02 (count correction, see 6);
  their channel knownIssues were left as published (coordinator decision).

## 2. Held candidate: r35 (NOT published)

`release/r35` 87c7b972e8 = r34 + two hardware-correct GPU fixes:
- `7a96796577`: the triangle size cull (no triangle 1024+ wide / 512+ tall, psx-spx) plus
  signed 11-bit vertex decode (main line `4c94e5e151`).
- `87c7b972e8`: the cpu presenter scans out the GP1 display area instead of the draw/clip
  page (main line `1c2b33b5ea`; r34 trace showed the clip page on 2,377/3,296 presents).

Package `~/release-staging/bfm-r35/bfm-r35-87c7b972e.tar.gz` (sha 2254dd8e...66a0, retail
guard 0). **Held** because neither fix removes the owner-visible forest flicker (section
3.1). A/B of r34 vs the first r35 (cull only) was byte-identical on every captured frame.
Not gated beyond that.

## 3. Open problems

### 3.1 Forest flicker / "black boxes" (owner report, Original mode, r34 on Legion Go)

- Owner's live log (copied read-only): `~/release-staging/bfm-r34/legion/last-run-live.log`.
  Zero refusals; he was in 3005/3008 (intro + forest).
- Symptom on blizzpc (deterministic, same frames every run, also r30/r34/r35): in the forest
  (room 3008, New Game + mash) one game frame in every ~5 goes dark (displayed for 2
  vblanks): presents 2716/17, 2726/27, 2776/77, ... plus a run 2682-2691.
- VRAM at a dark frame (`~/release-staging/bfm-r35/dark/ev2/run/cap/`): the displayed
  buffer has the HUD + faint far clouds and **no floor**; the other buffer is normal.
- Per-present GP0 counts (diag build, branch `diag/gp0-counts` in `~/dev/bfm-r34`, env
  `MUSASHI_TRACE_GP0=1`): the frames that later display dark submitted **11-18 polygons**
  (24k pixels) vs 280-390 normally. The size cull dropped 0. **The game does not submit the
  floor in those frames**; the GPU/presenter is not the cause.
- Inconclusive: a half-instruction-cost knob (`MUSASHI_DIAG_HALF_COST`) changed nothing at
  all, so it probably does not drive the guest clock; the lane-off control cannot reach the
  forest (the interpreter refuses at 3005).
- Hypotheses: (A) guest timing / frame budget, (B) GTE results vs hardware in the game's
  visibility test, (C) OT/packet buffer handling, (D) a native-lane semantic difference.
- An Opus worker started on it (branch `claude/forest-flicker` in `~/dev/bfm-flicker`);
  see section 8 for its state at handover.
- Capture tooling: `tools/headless/bfm_swap_capture.c` (now with
  `BFM_CAPTURE_PNG_IN_WINDOWS`), `bfm_swap_capture2.so` in blizzpc packages.

### 3.2 Pass-through ABI class (fixed)

C that under-declares arguments its retail words pass straight through (e.g.
`s32 func_80013328(void)`) broke when reached by a direct native call. Fixed by the
generator detector + routing (`ab7fbcd81a`) and 7 prototype fixes (`d3231544d6`, also in
decomp `a4b343946b` and rederive `b84dbbd`). r34 carries only the routing. Confirm job
`20261002-150518-bfm-r33-bde8` proved r33 diverged; r34's eager route proof was byte-identical.

### 3.3 B18 (cold tail batch 1) deferred, not in any build

- 30/30 matched clean-room (B18 26 + tail3 4), merged as source; 23 admitted on the main line.
- Held out: `8012B608` (ambiguous cycle map, fixed charge) and `8012DEB8` (null guest pointer
  on attract, host fault: the KUSEG gap, D-013 (4)); both in `OVERLAY_DENY`
  (`tools/native_lane_gen.py`). `80128ED8` is refused (layout).
- Route proof 3 (`20261002-173201-bfm-b18route3-d9266619f3`): village byte-identical; attract
  RAM/PAD identical but 72 DEVOBS lines differ: 3 IRQs delivered 2 cycles early at a D-011
  deadline checkpoint inside native `8014C99C`. Fix the checkpoint position mapping or hold
  8014C99C out before any release with B18.
- Policy learned: no batch ships without a route-level native-vs-deny proof under
  `MUSASHI_EPOCH_LAZY=0` on village AND attract (DEVOBS/RAM/PAD byte-identical).

### 3.4 B19 (cold tail batch 2): source only

25/30 matched (rederive `0519d90`; decomp `2332d3e14b`, port `f370848018`), NOT in the overlay
allow list. 5 failed (80149B54, 8014FE60, 8014EA4C, 8015126C, 80128678 = scratchpad stack switch,
needs inline asm). Next batches: `scratchpad/rederive_setup_batch.py` (ranked by r33 village+
attract interpreted calls; 1,711 candidates, 452 called).

### 3.5 Null/KUSEG guest-pointer lane fix: design approved, not started

Native code that reads through a null/low guest pointer faults the host where retail reads
the low-RAM mirror (D-013 (4)). Costs functions (8012DEB8) and is the r30 NormalClip crash
class. Design first (e.g. normalise pointer arguments at lane thunks, or map/mirror low
addresses).

### 3.6 Other

- Lazy-epoch SPU voice-volume readbacks are nondeterministic run to run (RAM unaffected);
  disclosed in r33/r34 notes.
- D-030 E2 texture window / texpage handling in the cpu rasteriser: not implicated so far.
- Intermittent "pinned retail EXE rejected" at startup on blizzpc when its runner area was
  near the 30 GiB cap.

## 4. Repos and branches

| Repo | Branch / HEAD | Notes |
|---|---|---|
| port `~/dev/bfm-port-integration` | `port/native-lane` (this file's commit) | main line; contains B18 allow list + B19 source + GPU fixes + pass-through |
| port worktree `~/dev/bfm-r34` | `release/r34`, `release/r35`, `diag/present-trace`, `diag/gp0-counts` | release branches; diag branches are diagnostics only, never release |
| decomp `~/dev/brave-fencer-musashi-decomp` | `main` a4b343946b | matching C, merge-backs |
| rederive `~/dev/bfm-rederive` | `main` 0db31c3 / b84dbbd | clean-room workspace (LEDGER.tsv, provenance); README clean-input rules updated |
| other worktrees | `claude/*` in `~/dev/bfm-*`, `~/dev/bfm-rederive-wt/*` | all merged or recorded; committed |

Gates for matched C: `tools/register_match.py`, `tools/verify_registry.py` MATCH,
`tools/check_no_retail_data.py` 0, `tools/check_no_m2c_text.py` 0. Clean-room rules:
`~/dev/bfm-rederive/docs/rederive/README.md`.

## 5. Runner (blizzpc 100.87.173.93) jobs and artifacts

No BFM job running or queued at handover. Recent evidence (copied locally):
- r34 gate: `20261002-154157-bfm-r34-gate-5e0952520` -> `~/release-staging/bfm-r34/gate-evidence.tar.gz`
- r35 A/B: `20261002-175156-bfm-r35-ab`, `20261002-181512-bfm-r35-ab2b` -> `~/release-staging/bfm-r35/ab*/`
- dark frames: `20261002-182305-bfm-r35-dark2`, `20261002-182943-bfm-r35-gp0`,
  `20261002-183657-bfm-r35-gp0c` -> `~/release-staging/bfm-r35/dark/`
- B18 route proofs 1-3 -> `~/release-staging/bfm-b18route/`
- pruned-dir receipts: `~/release-staging/bfm-runner-receipts/`, list on blizzpc
  `~/devbox-runner/bfm-pruned-20261002.txt`
Runner packages kept: bfm-r30..r35, probes-*, bfm_swap_capture{,2}.so, diag-*.tar.gz.
Fair share: BFM uses one runner slot; chain gate/route/speed in one job; assert the
package sha256 inside every gate job (template `~/release-staging/bfm-r34/combined.sh`).

## 6. Native status (disclose honestly)

- Release lane (r34/r37): main 474/500 + overlay 88/93 = 562/593 (count from report.json split by
  member; the generator's "N/M game functions" line counts both together). r31/r32 notes
  originally double-counted; corrected.
- Still HYBRID: most overlay/scene code and non-HLE PsyQ run in the interpreter; 48 native
  functions keep the fixed (approximate) cycle charge; the null/KUSEG gap remains.
- Never claim native completion from counts; route proofs and gates are the evidence.

## 7. Docs to read first

`docs/NATIVE-LANE-RUNTIME-2026-10-01.md` (evidence log), `docs/KNOWN-DIVERGENCES.md`
(D-011, D-013, D-024, D-030..D-036), `docs/OVERLAY-LANE-DESIGN.md`,
`docs/MEMORY-CARD-2026-09-30.md`, `docs/GRAPHICS-ENHANCEMENTS-DESIGN.md`.

## 8. Forest-flicker worker state at handover

At handover (2026-10-02 ~18:45 UTC) the worker had made no commits and no code changes on
`claude/forest-flicker` (branch == port/native-lane `1c2b33b5ea`). It was told to stop; any report it
sends will be relayed to the coordinator. Restart the investigation from section 3.1.
