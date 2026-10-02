# BFM handover to Codex (2026-10-02)

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
Windows remains outstanding/unqualified. Codex yields after this release completion
for efficient routing; no model switch is claimed. Native conversion stays open.

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

**Windows is still outstanding for the same public r38 request.** The owner's
Windows+Linux clarification arrived in Devbox message `23c4f77ef5a3979a`.
The cached Zig compiler passed a tiny Windows COFF adapter compile and CMake
compiler detection, but the game configure fails for missing Windows SDL2,
and production code requires Linux memory mapping/X11 APIs and Linux-target
native-lane objects. No Windows game binary or runtime test exists yet.
See [Windows release blockers and evidence](docs/WINDOWS-RELEASE-2026-10-02.md).
The coordinator was informed; preserve the running owner game/desktop and
the existing Linux release while completing this remaining platform work.

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
