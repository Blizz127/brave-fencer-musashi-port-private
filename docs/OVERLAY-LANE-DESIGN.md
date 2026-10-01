# Overlay own-code lane: design (2026-10-01)

Design for task b3417aa6a518, part 2. It comes from a read-only analysis at port
`201548c6b4` (no builds, no vendor C bodies read). Its evidence is the release
village trace `~/release-staging/bfm-owncode-258e0dcb2b/ev/village_trace/trace.counts`
and the generator reports. Status: section 3 A-F and slice O1 are implemented on branch
`claude/ovl-o1` (evidence: NATIVE-LANE-RUNTIME-2026-10-01.md, "O1"); O2 is not started.

Overlay game code is 0% native in release builds: on the village route 150,805
interpreted calls across 793 distinct overlay functions (out of 712,841 interpreted
calls in all), and the release lane logs `NATIVE_LANE overlay entries=0`.

## 1. How overlay entries work today

- Members: CMake `MUSASHI_LANE_OVERLAY_MEMBERS` (default `main_0003`,
  `CMakeLists.txt:622`) is passed as `--overlay-members` (`:647`). `member_info`
  (`tools/native_lane_gen.py:186-207`) reads `config/overlay_<m>.yaml` (vram/start,
  code subsegments, extracted member file). A member whose config or file is missing
  silently stays interpreted (`:1320-1324`).
- Candidates: `overlay_candidates` (`:1283-1286`) takes registry rows with
  `region in members`, `recovery == "c"` and an existing source, filtered by
  `--only`, which is keyed by vram alone. Symbols are member-qualified
  (`lane_main_0003__func_...`, `:170-176`).
- Digest: `member_digest` (`:245-250`) is the FNV-1a 64 of the user's member file
  over the function's registry extent `[vram, vram+size)`, not the whole member. An
  extent outside the file is rejected as `overlay` (`:1037-1039`). Table rows carry
  `{entry, size, digest, member}` (`pc_port/include/musashi_native_lane.h:47-59`).
- Residency: `lane_try` (`pc_port/mips_formatter.c:13461-13474`) runs at a clean call
  boundary and calls `lane_find_overlay` (`:13309-13327`). That hashes guest RAM over
  each candidate's extent on every call (`lane_ram_digest`, `:13285`) and runs the
  entry whose digest matches. Otherwise `refused` is counted and the interpreter
  runs the resident words. Native-to-native calls inside a member are guarded by
  `musashi_native_lane_overlay_resident` (generated `native_lane_gen.py:1136-1150`,
  runtime `:13329-13336`), which falls back to the interpreter thunk on a mismatch.
  `install_overlay` (`:13260-13283`) rejects the whole table on a duplicate
  `(pc, digest)`. `MUSASHI_NATIVE_LANE_DENY`/`RANGE` apply to the main table only
  (`:13194-13222`).
- Why release has 0: `MUSASHI_LANE_OWN_CODE_ONLY` adds `--own-code-only --only
  config/lane_own_code_allow.txt` (`CMakeLists.txt:636-641`). That list holds main
  PCs only, so `overlay_candidates(..., only)` drops every overlay row. The release
  report shows `overlay: members [main_0003], candidates 0`. The member default
  isn't the cause: the dev lane with the same default admits 27 of 58 `main_0003`
  functions.

Latent defects the release design must fix:
1. The tracer labels a `trace.counts` row `native` only via `lane_find` (the main
   table, `mips_formatter.c:12944-12946`), so overlay calls always read `interp` and
   `trace_share.py` would report 0% even with a working overlay lane.
2. `--only` is vram-only. Listing `8012a988` would make that PC a candidate in every
   listed member.
3. `third_party_derived` (`native_lane_gen.py:1244-1252`) lets untagged C (no origin,
   clean header) through as own code. Only the hand-curated main allow list keeps it
   out today, so overlays need a positive origin check.
4. `hooked_pcs` reads only `pc_port/*.c` (`:328`). The platform entry-hook sites in
   `pc_port/platform/bfm_plat_hook_sites.c` (damage `8014BC80`, bp_use `8014BD60`,
   item `800D0F0C`/`800D128C`) are invisible to it. `room_enter 80128158` is still
   covered because `formatter_step` compares it (`mips_formatter.c:13539`).

## 2. Hot overlay code on the village route

The resident scene member is SC03 member 0001
(`extracted/overlays/sc03/0001.pac0.bin` at `0x80128158`). It explains 485 of the
550 traced scene-window call edges (136,964 of 147,339 calls); the other 65 edges
(10,375 calls) fit `sc01_0000/0001`, an earlier resident member. `sc03_0001` has no
registry entries and no config yaml. The hot shared-engine functions are
byte-identical over their registry extent in `sc03_0001`, `main_0012` and
`sc01_0000`. Because the digest is per extent, entries compiled from `main_0012`
would verify on the resident `sc03_0001` bytes.

All 793 overlay PCs (150,805 calls):

| Class | Functions | Calls |
|---|---|---|
| scene, byte-identical to an untagged `main_0012` entry | 246 | 60,615 (40%) |
| scene, registered but the sc03 bytes differ from every member | 121 | 34,265 |
| scene, unregistered | 212 | 22,084 |
| scene, byte-identical to a vendor-derived entry | 110 | 20,381 |
| `800CEDF8` window (`main_0001/3/8/10`) | 104 | 13,460 |

Registry origins: all SC-region overlay C is vendor-derived. `main_0012` is untagged
or vendor. The only clean-room overlay C is `main_0003`'s 24 functions.

Top hot functions:

| PC | Calls | Size | Origin and admissibility |
|---|---|---|---|
| `8012a988` | 19,104 | 292 | untagged `main_0012`, identical in sc03; yes after clean-room (its +0x90 pointer field as u32 or `layout` rejects it) |
| `80134a28` | 11,364 | 76 | untagged, identical; yes after clean-room (leaf dot3 + a2) |
| `8017869c` | 8,652 | 168 | vendor, identical; yes after clean-room (calls `80178744`) |
| `80134310` | 6,432 | 76 | untagged, identical; same body as `80134a28` |
| `80135480`, `80135a4c`, `80133cd4`, `801347a0`, `801449c8` | 6,144 / 6,144 / 4,180 / 4,028 / 2,352 | | registered, but the sc03 bytes differ (32/26/42/20/2 words); need a `sc03_0001` split |
| `80144a90` | 2,328 | 8 | untagged `jr ra; nop` reached through a pointer table; trivial, no speed gain |
| `8013435c`, `8013e298` | 2,153 / 1,794 | 104 / 44 | untagged, identical leaves; yes after clean-room |
| `8013e410` | 1,794 | 56 | untagged, identical bounded table walk; likely passes `irq` |
| `8013e448` | 1,794 | 108 | vendor, identical; uncertain (has a jalr) |
| `800d24d0` | 1,760 | | `main_0003` vendor; no: hooks `800d257c` and runs as a CD IRQ callback (lane suspended) |
| `800d2c88` | 1,760 | 32 | `main_0003` vendor; dev-admitted, needs clean-room for release |
| `800d2ef8`, `800d3020` | 1,760 each | | `main_0003` vendor; no: `memory` (device pointer / volatile) |
| `800cedfc` | 1,678 | | `main_0001/0008/0010` vendor; needs clean-room |
| `8017f258` | 1,552 | | unregistered |

## 3. Minimal release design

A. Allow list: a new `config/lane_own_code_allow_overlay.txt`, lines
`<member> <vram>`. No stored digest: the generator computes it from the member file
after checking the file's SHA-1 against the yaml `sha1` (a new check; the `main_0003`
and `main_0012` yamls already carry one). Different bytes give a different digest
and a separate entry; identical bytes give one entry valid wherever they are resident.

B. Generator (`tools/native_lane_gen.py`):
1. `--overlay-allow FILE`. Under `--own-code-only` the overlay candidates are exactly
   those pairs, and the main `--only` stops filtering overlays.
2. A positive origin check: a clean-room or owner origin is required, and untagged
   fails.
3. A hard build error on a missing member, an SHA-1 mismatch, a missing registry row
   or a size mismatch, so a release can never silently ship 0 entries.
4. Deduplicate `(vram, digest)`, preferring the clean-room source, and record which
   members each entry `covers`. Otherwise a duplicate makes `install_overlay` reject
   the whole table.
5. Reject guest jump tables (jr not to ra) until the digest also covers the
   referenced `.rodata`.
6. `hooked_pcs` also reads `pc_port/platform/bfm_plat_hook_sites.c` as `entry` kind,
   and direct calls into those sites go through the thunk.
7. `report.json` lists the overlay functions with digest, covers and rule.

C. CMake: `MUSASHI_LANE_OWN_CODE_ONLY` passes `--overlay-allow`; the members come
from the allow file instead of the `main_0003` default; DEPENDS gains the allow file
and the yamls.

D. Runtime (`pc_port/mips_formatter.c`):
- Keep the per-call full-extent digest (slice O2 hashes about 8.9 MB per route,
  roughly 10 ms).
- Apply `DENY`/`RANGE` to the overlay table and print the entry count after filtering.
- Split the counters into entry verified/refused and guard verified/refused.
- After every thunk or guest call inside a native overlay function, re-check the
  caller's own digest and abort (fail closed) on a mismatch.
- Optional: refuse to the interpreter when a pointer argument lies outside
  `80000000-80200000` (KUSEG/KSEG1/scratchpad).

E. Tracer: count an overlay row native only when `lane_find_overlay` verified it (as
S3a does for the pad leaves), and fold in `tools/patches/trace-resident.patch` (not
landed) for `(pc, digest)` residency.

F. Fallback and disclosure: a refusal means the interpreter runs the resident words.
A KNOWN-DIVERGENCES entry covers the cycle charge (2 × words per call), no IRQ
delivery inside a native call, the residency guard, and the KUSEG/scratchpad gap.
Every report prints the counters and the corrected share. Still hybrid; not a
native-completion claim.

## 4. Slices

**O1, plumbing, no new C**: allow-list `main_0003`'s 24 clean-room functions (all
dev-admitted, clean headers). Only about 219 village calls, but it proves A-F in a
release build with `verified > 0`.

**O2, first useful slice**: clean-room re-derive 9 `main_0012` functions that are
byte-identical in `sc03_0001`:

| Function | Size (bytes) |
|---|---|
| `8012a988` | 292 |
| `80134a28` | 76 |
| `80134310` | 76 |
| `8013435c` | 104 |
| `8013e298` | 44 |
| `8013e410` | 56 |
| `8012bd14` | 40 |
| `8016f1ac` | 24 |
| `8017869c` | 168 |

- Total: 880 bytes (220 words), 53,479 calls. That's 35.5% of interpreted overlay
  calls and 7.5% of all interpreted calls; 44,827 (29.7%) without the vendor-derived
  `8017869c`.
- Thunked callees: `8012ACE0`, `8012AAAC` (sc03 differs by 2 words; the guard/thunk
  handles it), `80013350` (escape-rejected in release) and `80178744`.
- Prerequisite: bfm-rederive gets the `main_0012` yaml, its symbols,
  `asm/nonmatchings/main_0012` for these 9 and a ledger batch, all inside its clean
  input set.

Gates, in order:
1. `register_match` MATCH per function, `check_no_retail_data` 0, no m2c macro text.
2. `verify_registry` MATCH after merge-back, with the clean-room origin recorded.
3. The generator admits 9/9 under `--own-code-only`, with `covers` including
   `main_0012` and `sc01_0000`; retail guard 7 files, 0 problems.
4. Pointer census: a0-a3 at the 9 PCs over the route (`MUSASHI_TRACE_PCS`); no KUSEG
   or scratchpad pointers.
5. Differential: `musashi_native_lane_overlay_probe` with the `main_0012` payload and
   a `sc03_0001` payload (positive), a member with different bytes (must refuse), and
   synthetic plus census arguments over a village `MUSASHI_DUMP_RAM` image: 0
   different, and deliberate-break mutants fail.
6. Runner village, plain and traced: warp vblanks 416, `IN_GAME_TARGET`, display
   70196/76800, stop tick `0ae0`, no abort or fault; overlay entries > 0 with the four
   counters. Attract as r30. A DENY-all-overlay leg for same-input parity (tick, IRQ
   count, DEVOBS).
7. Fixed tracer: the 9 PCs native with 0 interpreted; overlay interpreted calls
   150,805 -> about 97,300.

## 5. Risks and unknowns

- An overlay reload during a native call: the post-call self re-check aborts.
- Identical bytes don't prove identical jump tables, so jump tables are rejected
  until the digest covers them. Other data is read live, so it's equivalent.
- The digest cost grows with bigger, hotter functions. A cache would need write
  barriers for DMA, interpreted stores and native stores, which don't exist.
- KUSEG/scratchpad pointers fault the host and kill the process (the `80013f3c`
  precedent). `main_0012` has 73 `0x1F80` references, and `80134a28`'s a1 comes from
  `D_8017E914`. Only the census and the differential can settle it.
- Platform hook sites are invisible to the generator, and it's unverified whether
  thunked callees fire entry hooks.
- A fixed cycle charge against the interpreted cost: DEVOBS hashes may differ
  (vblanks held at 416 on earlier main admissions).
- Not determinable statically:
  - the resident member per call before the warp;
  - how many calls land at a clean boundary outside IRQ frames;
  - whether `8012a988` and `8013e410` pass every rule once rewritten;
  - whether every release build host has the member extracts (if one doesn't, the
    build must fail rather than ship 0 entries).
