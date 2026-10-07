# Native frame driver behind `boot_entry` (design note, B22, 2026-10-07)

Step 2 of the zero-fallback plan in `docs/STRICT-NATIVE-BUILD.md`. Today a strict
build aborts at `seam=boot_entry guest_pc=80010000`, because the whole game loop
is interpreted. This note covers three things: what `main`'s loop calls, what
each callee is today, and what a host-side driver needs in order to run that
loop without the interpreter.

Method: a static `jal` call graph built from the registry-MATCH bytes of every
per-frame callee (gcc-2.7.2 build of the registry source, disassembled).
Indirect calls (`jalr`) are counted but not followed. Classes come from the B22
registry, `config/lane_own_code_allow.txt`, `config/psyq_ranges.txt` and
`pc_port/platform/psyq/bfm_psyq_compat.def`. "Lane rules pass on box" means
`tools/native_lane_gen.py --own-code-only --only <pcs>` admitted the function on
the sandbox. That run has no retail words, so the `escape` frame proofs and the
cycle ledger are still pending, and none of these functions is on the allow
list yet.

## Why `main` cannot just become a lane function

`main` (80010178) is compiled at -O0, its origin is untagged, and it is listed
in `ALWAYS_HOOKED` in the generator. It also switches `sp` to the scratchpad
(0x1F8003FC) with inline MIPS around three calls. Every lane rule that applies
(`hooks`, `calls`/inline asm, own-code) refuses it. The driver therefore has to
be host C that performs main's sequence itself and calls the guest functions
through the lane table. That host C must be written clean room from main's
retail disassembly and this note, never from the vendor `main`.

## What `main` does

Init, once: `80043060(0)`, `D_80074778 = 0x3E0`, `800141F0` (STARTUP_ENTRY,
which `native_boot` already sequences), `8005FC68(0)`, `8005FCB8` (libmcrd),
`80018918`, `D_800A2B7C = 80043300()`, `8002C8F4`, `8001971C`.

Outer loop, once per session (title, game, back to title):
`80014238` (session reset), `80014390`, `800191A8`, `80010A98`. The inner
loop then runs while `*(u16 *)(p + 0xA3D4) == 0`, with `p = D_800AF630`.
When the inner loop exits, main calls `80042610(0)` (libetc STUB row) and goes
round the outer loop again.

Inner loop, once per frame:

1. Bookkeeping that main does inline (the driver must replicate it):
   - frame counter `D_800C7C70` (never 0) and buffer index
     `D_800C7C74 = !D_800C7C74`, stored to `p+0xA3D2`;
   - primitive pointer `D_800A5E60 = D_8007BA70 + idx*80000`;
   - the slot at `p + idx*12`: `{0x640, 0, D_800A4F48 + idx*1600}`.
2. `800189A8` (pad poll; this is the `frame_begin` hook), then `80015208`.
3. If `p[0xA3E3] == 0` (normal game frame):
   - main counters at `p+0xA3A8` and `p+0xA3AC`;
   - OT pointers for this buffer, then `ClearOTagR(ot, 0x1000)` and
     `ClearOTagR(ot2, 4)`;
   - `80010B40`;
   - `80015498` and `8001C00C`, each called **on the scratchpad stack**.
4. Otherwise: `ClearOTagR(ot2, 4)`, then `800D25FC` on the scratchpad stack.
   800D25FC is a 40-byte indirect-call wrapper in a resident overlay (see
   `docs/STARTUP-OVERLAY-LEADS.md`).
5. `800184F0` (the `frame_end` hook), `DrawSync(0)`, `VSync(p[0xA3E8])`.
6. Display/draw buffer swap through `p+0x188`/`p+0x18A`: `PutDispEnv`,
   `PutDrawEnv`, `CatPrim`, and `DrawOTag` twice.
7. `8003500C`, `8002D034`, `8001AF34`, `8001513C`.

## Per-frame callees today

Subtree columns count the distinct functions reachable by `jal`, including the
callee itself. native = on the release allow list. own = owner/clean-room C
that is not admitted yet. vendor = vendor-derived C, interpreted in release.
other = other game code. psyq = Sony library range.

| Callee | Name | Class (B22) | Subtree | native | own | vendor | other | psyq | jalr |
|---|---|---|---|---|---|---|---|---|---|
| `80014238` | session reset (outer) | own | 76 | 27 | 8 | 0 | 0 | 41 | 10 |
| `80014390` | (outer) | native | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| `800191A8` | (outer) | own, lane rules pass on box | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| `80010A98` | (outer) | native | 3 | 1 | 0 | 0 | 0 | 2 | 2 |
| `800189A8` | pad poll, `frame_begin` | native | 15 | 9 | 1 | 0 | 1 | 4 | 0 |
| `80015208` | | **vendor** | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
| `80059BFC` | ClearOTagR | PsyQ HLE | 1 | | | | | 1 | 2 |
| `80010B40` | | native | 1 | 1 | 0 | 0 | 0 | 0 | 1 |
| `80015498` | text/sprite requests (scratchpad sp) | own | 6 | 1 | 1 | 3 | 0 | 1 | 0 |
| `8001C00C` | object pools (scratchpad sp) | native | 5 | 3 | 1 | 1 | 0 | 0 | 2 |
| `800D25FC` | overlay wrapper (scratchpad sp) | overlay | | | | | | | 1 |
| `800184F0` | `frame_end` | **vendor** | 6 | 0 | 0 | 1 | 0 | 5 | 3 |
| `800596F4` | DrawSync | PsyQ HLE | 1 | | | | | 1 | 2 |
| `8004239C` | VSync | PsyQ HLE (lane: mode < 0 only) | 1 | | | | | 1 | 0 |
| `80059FC0` | PutDispEnv | PsyQ HLE | 1 | | | | | 1 | 0 |
| `80059D68` | PutDrawEnv | PsyQ HLE | 2 | | | | | 2 | 2 |
| `80058CE4` | CatPrim | PsyQ HLE | 1 | | | | | 1 | 0 |
| `80059CF4` | DrawOTag | PsyQ HLE | 1 | | | | | 1 | 2 |
| `8003500C` | | native | 1 | 1 | 0 | 0 | 0 | 0 | 3 |
| `8002D034` | sound driver tick | **vendor** | 106 | 62 | 15 | 14 | 0 | 15 | 6 |
| `8001AF34` | | native | 158 | 83 | 17 | 21 | 0 | 37 | 5 |
| `8001513C` | empty hook | own, lane rules pass on box | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| `80042610` | (inner-loop exit) | PsyQ **STUB** | 1 | | | | | 1 | 1 |

Union of all subtrees: 279 functions. 127 are native, 30 own (not admitted),
28 vendor, 1 other game function and 93 PsyQ.

- **Vendor, interpreted in release (28):**
  - direct callees: `80015208`, `800184F0` (clean room in B23), `8002D034`;
  - under 80015498: `80015608`, `80015760`, `80015908` (clean room in B23);
  - under 8001C00C: `8001F9F8`;
  - in the sound driver: `80019AF8`, `8001B0D4`, `8002FF0C`, `80030730`,
    `80030A14`, `80030D80`, `80030F80`, `800314DC`, `80032048`, `800322A8`,
    `800324A4`, `80032774`, `80032A74`, `800336A8`, `8003388C`, `80034DFC`,
    `800363CC`, `80036AF8`, `80037144`, `800383A4`, `80038698`.
- **Own, not admitted (30).** 22 pass the lane rules on the box, including
  `800147B8` (recovery `mixed` before B22, now plain C). The rest are refused:
  - `hooks` (the port references a PC inside the function): `80014238`,
    `80014444`, `800145EC`, `80014928`, `8002FC64`;
  - `escape`, retail frame proof pending on the runner: `8001D1C4`,
    `8002E5F8`, `80036D58`;
  - `deny`: `80015498`;
  - `ub`: `80018A20` (no return value on the unknown-state path, as in retail).
- **Other game code (1):** `80018E9C`, under the pad poll. Only an
  unverified m2c draft exists and there is no registry match, so the box has
  no retail bytes to work from.
- **PsyQ (93):**
  - 16 HLE and 6 PsyCross rows are served by `bfm_psyq_call`;
  - 27 have no compat row (internal to a library body);
  - 44 are **STUB** rows, and in a strict build they abort on `psyq_refused`.
    Among them: PadGetState, PadInfoMode, PadSetAct and PadSetActAlign under
    the pad poll; InitHeap, ResetGraph-like 80059234 and SetDefDrawEnv-like
    80058A4C under the session reset; CdMix and most of `snd*`/`libcd` under
    the sound driver; `80042610`; DrawSyncCallback under 80010A98.

## Driver design

1. **Entry.** A new TU (for example `pc_port/native_frame_driver.c`) replaces
   `musashi_boot_run_entry_with_devices` when the lane is mapped (guest RAM at
   0x80000000) and the build asks for it (`MUSASHI_NATIVE_DRIVER`, implied by
   `MUSASHI_STRICT_NATIVE`). `native_boot`'s startup sequencing of 800141F0
   (STARTUP_ENTRY) stays as it is. The driver runs main's other init calls and
   then the two loops above.
2. **Calls.** One helper, `driver_call(pc, args...)`, looks the PC up in the
   generated `native_lane_table.c`:
   - hit: call the native entry;
   - PsyQ PC: go through `bfm_psyq_call`;
   - miss in a strict build: `musashi_strict_abort("frame_driver", name, pc)`,
     a new seam id;
   - miss in a hybrid build: fall back to `musashi_native_guest_call`.
   Indirect calls inside native code already go through the lane thunks, so
   `jalr` targets need nothing extra here. A non-admitted target surfaces as
   `lane_guest_call`.
3. **Inline state.** The bookkeeping in step 1, the OT pointer setup and the
   buffer swap are written as host C over guest RAM (`memory.bytes`), using the
   same addresses as above.
4. **Scratchpad stack.** 80015498, 8001C00C and 800D25FC run with guest
   `sp = 0x1F8003FC`. Correction (B23): native code *can* reach the
   scratchpad. `musashi_native_lane_map_guest` maps a scratchpad alias at
   host 0x1F800000 next to the RAM window (native_boot logs
   `scratchpad alias at 1f800000 unavailable` when it cannot), and
   800184F0 already builds its upload rectangle there. The driver therefore
   enters those three calls with the guest sp at 0x1F8003FC, as main does;
   guest-frame locals (`place_guest_locals`, e.g. 8001D1C4) land in the
   aliased scratchpad. Without the alias, the first scratchpad access from
   native code ends the run with `HOST_FAULT ... lane_pc=...` (exit 139).
5. **Pacing.** `VSync(p[0xA3E8])` is a waiting mode, and the lane only
   completes `mode < 0`. The driver replaces this call with
   `bfm_plat_frame_end(fields)`, which already presents and paces through
   `bfm_plat_timing` at the `frame_end` hook (800184F0). Then it runs a
   VSync(-1)-style tick so the guest counters still advance.
   `bfm_plat_frame_begin()` runs at the 800189A8 hook point.
6. **Input.** The pad libraries are STUB rows, so the platform input layer has
   to fill the two 0x4C-byte pad records at `D_80078D98`. The alternative is a
   pad HLE row (PadGetState/PadInfoMode) before 800189A8's subtree can run
   strict.
7. **IRQs.** Native calls run without IRQ delivery. The driver delivers
   VBlank, CD and SPU callbacks through the existing `irq_scheduler` once per
   frame at the VSync point, plus around long calls. Those callbacks are their
   own seams (`cd_irq`, `bios_event`, `source_call`), and step 3 of the strict
   plan has to make them native too.
8. **Overlays.** The `p[0xA3E3] != 0` branch (800D25FC) and the overlay
   callees under 8001C00C/8003500C resolve through the existing overlay digest
   hooks and the `main_0003`/`main_0012` lane members. Any other member
   reports a `lane_guest_call` miss.

## Implementation status (B23, 2026-10-07)

Behind `MUSASHI_STRICT_NATIVE` (with `MUSASHI_NATIVE_LANE=ON`), nothing in a
hybrid build changes:

- `pc_port/native_frame_driver.c` (+ `pc_port/include/musashi_native_frame_driver.h`):
  host C for main, written clean room from main's retail disassembly. It covers
  `__main`'s run-once flag, the init list, the session (outer) loop with
  `80042610(0)` on exit, and the frame (inner) loop. The frame loop includes
  all of main's inline bookkeeping: frame counter, buffer index (reread from
  `p+0xA3D2` at every use, as main does), primitive cursor, packet slot,
  counters, both OT rows, the scratchpad-stack calls, the display/draw
  buffer swap, CatPrim and the two DrawOTag calls.
- **Dispatch.** Every call goes through `musashi_native_lane_invoke`
  (`mips_formatter.c`, strict only): a fresh CPU bound to the boot devices,
  entered through `lane_try`, with no `formatter_step` fallback. A miss stops
  the process with
  `STRICT_INTERPRETER_ENTRY seam=frame_driver routine=not_in_lane func_XXXXXXXX [psyq=<why held back>]`.
  Inside native code, `musashi_native_guest_call` now dispatches the callee
  through the lane table in strict builds. That table holds generated C, the
  installed PsyQ compat wrappers and the driver's own entries. Only a miss is
  `lane_guest_call` (`routine=not_in_lane`).
- **Pacing.** At main's `VSync(p[0xA3E8])` the driver handles the modes:
  - `mode < 0`: goes to the VSync lane HLE;
  - otherwise the wait becomes `bfm_plat_frame_end(fields)`, which emits
    FRAME_END, presents and paces through `bfm_plat_timing`. Then
    `fields x MUSASHI_GUEST_FRAME_CYCLES` of execution clock are charged.
    Fields are 1 for mode 0, 0 for mode 1 and n for n > 1.

  Without bfm_plat, only `bfm_plat_timing_vsync` paces (with
  `MUSASHI_TIMING=bfm_plat`). `bfm_plat_frame_wait()` (FRAME_BEGIN, input
  poll, pause) runs before 800189A8. `MUSASHI_DRIVER_FRAMES=n` stops after n
  frames.
- **Native replacements for STUB Sony rows** (driver lane entries, appended
  to the installed table in strict `native_boot`):

  | PC | Entry | Replacement |
  |---|---|---|
  | `8005CE18` | InitHeap | BIOS A0:39 through the boot heap device (`init_heap`) |
  | `8005CF08` / `8005CF18` | Enter/ExitCriticalSection (SYS1/SYS2 wrappers) | the CD device's `enter_critical_result` (v0 = previous state) and the callback device's `exit_critical_section`, as the interpreter's syscall path does |
  | `80043974` | CdMix | the same seven CD register writes as 80044A8C, through the four register pointers at `8006CF4C..58` and the CD register device; returns 1 |
  | `8005F0C8` | PadInitDirect | records the two receive buffers; the driver writes the host pad into them in wire form before 800189A8 each frame (`00 41 lo hi`, or `FF` with no pad) |
  | `8005D0F8` / `8005D118` | PadStartCom / PadStopCom | accepted (the driver exchanges at its frame boundary) |
  | `8005D184` | PadGetState | 2 (FindCTP1: a pad without extended functions) when the host pad answers, else 0 |
  | `8005D244` | PadInfoMode | term 1: the pad id's high nibble (4 for digital); 2, 3, 4: 0 |
  | `8005D4B8` / `8005D538` | PadSetActAlign / PadSetAct | accepted, v0 = 1 |

  The libpad entries are not in the registry, so they are written from the
  documented library behaviour and 80018A20's use of the results (states 0,
  1, 2 and 6, and PadInfoMode term 2), not from retail words.

**Still open:**
- **crt0 (80010000..8001009F).** Not in the registry. The driver assumes
  that the BSS clear is redundant on fresh zeroed guest RAM, and that the
  stack top is the PsyQ default 0x801FFFF0 (`MAIN_SP` = top - 56). Both must
  be checked against the retail words once a disc is on the box.
- **IRQ delivery.** Item 7 above. The clock charge at VSync can make IRQs
  deliverable, and their handlers are still the `cd_irq`, `bios_event` and
  `source_call` seams.
- **The libetc VBlank counter.** It only advances through the VBlank IRQ
  handler.
- **Lane admission.** Every callee still has to be admitted (allow list plus
  retail-proved frames). Until then a strict run stops at the first callee
  that is not admitted, by design.

## Work order this implies

1. Clean-room the 3 vendor direct callees (80015208, 800184F0, 8002D034) and
   the 4 vendor functions under 80015498/8001C00C. B22 near-misses:
   - 80015908: permuter score 95;
   - 80015208: score 500;
   - 8002D034: score 285;
   - 8001F9F8: score 310;
   - 80015608: score 1350.
2. Clean-room the sound-driver vendor set (21 functions) or keep it behind a
   documented seam.
3. HLE rows for the STUB PsyQ calls on the route (pads first, then InitHeap,
   ResetGraph, SetDefDrawEnv, CdMix, the libetc callback setters).
4. Admit the B21/B22 functions that pass the lane rules: run the generator
   with retail extracts, do the village+attract native-vs-deny route proof on
   the runner, then add them to the allow list.
5. Write the driver (above). Then run a strict boot to the title, which should
   abort with a `frame_driver` miss naming the next missing piece instead of
   `boot_entry`.
