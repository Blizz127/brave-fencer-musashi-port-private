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
- **crt0 (80010000..8001009F)** was checked against the retail words once
  the disc was on the box, and the driver's `crt0()` now does what it does.
  The PSX-EXE header gives pc0 80010000, t_addr 80010000, t_size 0x64800, no
  b_addr/b_size, and s_addr 801FFFF0. crt0 ignores s_addr:
  - It clears 80074750..800C7F08. The start is gp, and it overlaps the last
    0xB0 bytes of the loaded image; those bytes are zero in retail, but the
    clear is still done.
  - It sets sp = (*800629BC - 8) | 0x80000000 = 801FFFF8. The retail
    _ramsize is 0x200000 and _stacksize is 0xC00.
  - It stores heap base 800C7F08 at 8006299C, and heap size
    `ramsize - 8 - stacksize - 0xC7F08` (0x1374F0) at 800629A0.
  - It saves ra at gp[0] and calls main.

  So main runs at sp 801FFFF8 - 56 = 801FFFC0, not the provisional 801FFFB8.
- **IRQ delivery.** Item 7 above. The clock charge at VSync can make IRQs
  deliverable, and their handlers are still the `cd_irq`, `bios_event` and
  `source_call` seams.
- **The libetc VBlank counter.** It only advances through the VBlank IRQ
  handler.
- **Lane admission.** Every callee still has to be admitted (allow list plus
  retail-proved frames). Until then a strict run stops at the first callee
  that is not admitted, by design.

## First strict run against the retail disc (B24, 2026-10-07)

The command was:
`MUSASHI_DRIVER_FRAMES=600 MUSASHI_PSYQ_LANE=all MUSASHI_GPU=bfm_plat MUSASHI_GUEST_CLOCK=1`.
It still stops inside `main_init`, so no frame has run yet. The stops,
in order, and what fixed each one:

1. **80043060.** Port-sequenced PsyQ. Fixed by `hle_exchange_cbe8`, which
   uses the same decomp-owned exchange the interpreter uses.
2. **800141F0.** Vendor-derived, and the non-strict generator always hooks
   it. Fixed by a clean room, plus the generator's `--strict` mode.
3. **80059234 (ResetGraph).** This is the current stop (`seam=lane_guest_call
   routine=not_in_lane`). ResetGraph calls ResetCallback (80042580), which
   reaches libetc's callback initializer 80042718. The port runs that
   initializer only on the interpreter:
   - `musashi_boot_run_callback_init_prefix` steps the retail words;
   - B0:19 HookEntryInt is a device hook;
   - the 80042C90 and 80042DB8 installers run through the decomp-owned
     800429DC registration.

   The next step is a native libetc core:
   - ResetCallback state;
   - InterruptCallback and DMACallback registration in the guest slot table;
   - a host IRQ dispatcher that the driver calls at VBlank, which runs the
     registered callbacks through the lane.

   This is the "native interrupt handlers" item.

Static walk of main's call graph from the driver's call list (jal only;
indirect calls are not followed): 179 functions are reachable, and 128 of them
are not yet in the lane. Of those:
- 17 are game code. The ones that still need a clean room are 80015208,
  8002D034, 80015608 and 80015760. 80015310 and 80018FC8 are refused for
  volatile device-register access.
- The rest are PsyQ library code:
  - libgpu: ResetGraph, SetGraphDebug;
  - libetc callbacks;
  - libcard: InitCARD/StartCARD (8005FC68/8005FCB8). They map 1:1 onto the CD
    and event devices: B0:5B/4A/4B, A0:70, eight OpenEvent/EnableEvent/TestEvent
    calls whose handlers 800617CC..80061858 `musashi_boot_execute_bios_event`
    already runs, and InterruptCallback(7, 800616D0);
  - libcd: CdInit 80043300, CdGetToc, the CdSearchFile internals;
  - libspu/libsnd: SpuInit, SsInit, SpuSetCommonAttr, the transfer and key
    setup that 8002C8F4 calls.

  Each of these needs a native HLE against the port's device owners.

## Native libetc core and interrupt delivery (B25, 2026-10-07)

Strict builds now own interrupts in the driver (`pc_port/native_frame_driver.c`,
written from the retail disassembly of 80042580..80043060, 80059234, 800594CC,
8005FC68 and 8005FCB8):

- **libetc** lane entries: ResetCallback 80042580 / init 80042718 (same RAM
  state as retail: I_MASK/I_STAT/DPCR writes, 1050-word clear of 8006BAFC,
  setjmp context ra 80042780 / sp 8006CB14, root-counter 1 mode 0x107, VBlank
  tick and slots, IRQ0 = 80042CE8, IRQ3 = 80042E08, service-table slots [1]
  and [5], A0:72, ExitCriticalSection); InterruptCallback 800425B0/800429DC and
  DMACallback 800425E0/80042F8C (decomp-owned bodies); VSyncCallback 80042610,
  VSyncCallbacks 80042644/80042D60; CheckCallback, GetIntrMask, SetIntrMask.
  B0:19 HookEntryInt is **not** issued: no interpreter scheduler is armed.
- **Interrupt point** (`driver_irq_poll`): after every top-level driver call
  and every VSync point, with interrupts enabled and `I_STAT & I_MASK` set,
  the BIOS kernel's priority chains run first (`ops->bios_irq`, the native
  entry `musashi_bios_kernel_dispatch_native_entry`: card/SIO and CD nodes),
  then libetc's custom exit, the decomp-owned dispatcher 800427F4, on the IRQ
  stack 8006CB14. Handlers 80042CE8 (VBlank: tick 8006CBB8 + 8 slots),
  80042E08 (DMA) and 800616D0 (card VBlank) run natively; other targets are
  lane calls. `musashi_frame_driver_irq_point()` lets host BIOS waits
  (`_bu_init`) deliver interrupts too.
- **Critical sections** (8005CF08/8005CF18 and the libcard/event helpers) are
  the driver's own interrupt-enable flag; the BIOS model's internal SYS1/SYS2
  pairs are no-ops without an interpreter continuation.
- The guest-clock VBlank source is live from the driver's start
  (`g_driver_irq_source`), so the game's VBlank counter advances natively
  (5 fields during the 2.8M-cycle `_bu_init` wait on the first run).
- **libgpu/libcard**: ResetGraph 80059234 (modes 0/3/5 native, others call
  jtb[13](1)), SetGraphDebug 800594CC, InitCARD 8005FC68, StartCARD 8005FCB8.

Strict boot now runs main through ResetCallback, 800141F0 (ResetGraph,
SetGraphDebug, PadInitDirect...), InitCARD (`_bu_init` completes:
result 0, cards disconnected), StartCARD and 80018918, and stops at **CdInit
80043300** (libcd, `not_in_lane`), still 0 frames. Everything after it in
main's startup (8002C8F4, 8001971C) is in the lane except libcd; the frame
loop needs the file loader, which drives libcd (CdControl 800435CC, CdSync
800434BC, CdReady 8004355C, CdReadyCallback 800435B4, CdGetSector 80043994,
CdControlB 80043830, CdControlF 80043704, CdRead 80046630, CdReadSync
8004674C, CdGetToc 800430B8 and the CdInit/CdReset chain 80043300/80043450/
80044D38/80044670/80044124/80043B9C). That HLE libcd (against the CD
register device and IRQ 2 through the driver's interrupt point) is the next
wall.

## Native libcd, libspu/libsnd startup and BIOS events (B26, 2026-10-07)

Strict builds now own the CD library, the sound start-up chain and the BIOS
event services as driver lane entries (`k_driver_entries`, strict only; each
replaces the compat row for its PC). All of it was written from the retail
disassembly and runs on the existing devices:

- libcd core (80043060..80046980): CdInit and the reset chain (80043300,
  80043450, 80044D38, 80044670 CD_cw, 80044124 CdSync, 800443A4 CdReady,
  80044B14 flush, 80044BF4 initvol, 80044CE8), the CD interrupt handler
  80045290 and getintr 80043B9C, CdControl/F/B, CdGetSector/2, CdDataSync,
  CdDataCallback, the callback exchanges, CdGetToc (800430B8/800430DC),
  CdDiskReady 80046630, CdGetDiskType 8004674C, the CdRead machinery
  (8004637C CdRead, 80046480 CdReadSync, 800460CC restart, 80045D00 sector
  callback, 80045FD0 DMA form, 800462E0 CdReadBreak, 80045C94) and
  CdSearchFile 80045374 (ISO 9660 path table and directory read through the
  native CdRead into the library buffer 80078000; the compat row needed the
  bfm_plat disc, which strict never opens). Registers go through the pointer
  cells 8006CF4C..8006CF90 to `MusashiCdRegisterDevice`.
- CD interrupts arrive through the B25 interrupt point: the libetc dispatcher
  calls 80045290, which runs natively and calls the ready/sync callbacks.
- Every native wait (CdSync, CdReady, CD_cw, CdReadSync, CdDataSync, the
  FIFO/DMA polls, WaitEvent, VSync(n)) spends guest time with
  `ops->spend` (`execution_clock.advance`) and then takes the interrupt
  point. Lane code gets the same: `boot->callback.checkpoint` is a strict
  checkpoint that calls `musashi_frame_driver_irq_point()`, and
  `lane_deadline` returns 0 when an enabled IRQ is pending and the driver
  would deliver it, so a lane busy-wait on an IRQ-set flag sees it.
- VSync 8004239C: mode < 0 keeps the compat form; n >= 0 waits fields of
  guest time with interrupts delivered.
- libspu/libsnd start-up (8003A424 SpuInit, 8003A444, 8003A5B8, 8003A53C,
  8003A84C, 8003AA18 DMA4 handler, 8003AB84 _spu_t, 8003B1EC SpuSetEnv,
  8003B280 SpuSetReverb, 8003B3D0, 8003B45C SpuSetReverbModeParam, 8003B954,
  8003BE24, 8003BE74, 8003BE98, 8003C0A0, 8003C598 SpuSetCommonAttr,
  8003D518 SsInit, 8003D548, 8003FA64 SpuVmFlush, 8003FE18, 8003FE3C,
  8004014C SpuInitMalloc, 800401A0, 80040868) over `MusashiCdSpuDevice`
  and the DMA4 registers.
- BIOS B0 events 8005CE68..8005CEC8 (Deliver/Open/Close/Wait/Test/Enable/
  Disable) through `ops->bios_event` onto `musashi_bios_events_*`; WaitEvent
  is a TestEvent loop with the interrupt point.
- New ops: `spend`, `deliver_event`, `bios_event`.

Result: strict boot passes CdInit, sound start-up and the CD file table
(CdSearchFile for LIST.CD/MAIN.CD and the other 21 names, through native
CdRead), 0 frames. The first remaining stop is `not_in_lane func_80019AF8`,
the file-loader state machine called from 80019A24. Its registry C is
vendor-derived (Druthulu), so the own-code strict lane leaves it out. It
needs a clean-room re-derivation (the bfm-rederive pipeline), like the other
25 vendor-derived main functions on main's static call graph (80015208,
80015608, 80015760, 8001B0D4, 8001F9F8, 8002D034, 8002FF0C, 80030730,
80030A14, 80030D80, 80030F80, 800314DC, 80032048, 800322A8, 800324A4,
80032774, 80032A74, 800336A8, 8003388C, 80034DFC, 800363CC, 80036AF8,
80037144, 800383A4, 80038698). Nearly all overlay code (village and
attract scenes) is vendor-derived too. The per-frame sound library (SsStart
8003D650, the tempo/sequencer 8003EDE8.., SsUtKeyOn/Off, SpuWrite/transfer
8003C438..8003C4F0) and the libcd2 stream library (StSetRing 80043088,
800469CC, 80046BFC) are the next PsyQ blocks; nothing on the boot path
reaches them yet.

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

## B27: ResetGraph(1), libgs start-up and the GTE lease (2026-10-07)

- ResetGraph modes other than 0/3/5 whose jump-table reset entry is 8005BD7C
  call the port-owned 8005BD7C HLE instead of the guest entry.
- New driver entries, written from the retail disassembly: GsInitGraph
  (800525DC, with its helpers 80052654, 80053CF8, 8005283C, 80052D00,
  80052BEC inlined), GsInitGraph2 (800527C4), GsDefDispBuff (80053178),
  GsDefDispBuff2 (80053EEC), the libgs 3D init 80053218, SetDefDrawEnv
  (80058A4C) and ClearImage (80059888, a renderer fill with the GPU's
  16-pixel granularity; compat function `bfm_psyq_ClearImage`, not a row).
- InitGeom/SetFarColor/SetGeomOffset run through the compat module's
  PsyCross wrappers. That needs the cop2 lease: strict boot now initialises
  the GTE owner before the driver starts (interpreter builds still take it
  at the first checkpoint), and a new driver op `cop2_enable`
  (`musashi_cpu_status_enable_cop2`) sets Status CU2 as retail InitGeom's
  mtc0 does. `_patch_gte` (8004D16C) only rewrites the BIOS RAM exception
  handler, which the native exception path never runs, so it is not
  reproduced.
- Strict boot (600-frame budget) now gets through GsInitGraph and the
  display-buffer set-up, still at frames=0. First remaining stop:
  `STRICT_INTERPRETER_ENTRY seam=lane_guest_call routine=not_in_lane
  guest_pc=80053f6c` (libgs GsSetRefView2, a GTE matrix routine with
  callees 80053B20, 80054340, 80047D3C). The static worklist of not-yet-native
  guest-call targets from admitted code is about 180 entries: lane-rule
  rejections of registry C (layout, deny, calls, escape, inttoptr), STUB
  PsyQ rows (libgs/libgte/libsnd/libspu) and overlay entry points.

## B28: GsSetRefView2, flat light, pad poll and libspu transfer (2026-10-07)

All rows below were written from the retail disassembly:

- **GsSetRefView2 (80053F6C) and its callees:**
  - 80053E28 rotation axis, 80053B20 RotZ by angle/360, 80054340 scale view,
    80052FCC CompMatrix.
  - Math: rcos 80047948, rsin 8004787C, SquareRoot0 80047D3C,
    TransposeMatrix 8004974C.
- **Lighting:**
  - GsSetFlatLight 80053328 and GsSetLightMatrix-style 80053804/800538BC.
  - SetColorMatrix through the PsyCross compat path.
- **DrawSyncCallback 800595FC:** swaps the callback word 80072794. Nothing
  invokes the callback, because the native GPU path completes synchronously.
- **Pad poll seam 80018A20:** the lane refuses it (`ub`: no return value on the
  unknown-state path, as in retail), so it is reproduced exactly in host C.
  Its callee 80018E9C is now matched clean-room C.
- **libspu:**
  - SpuGetAllKeysStatus 8003D25C, _spu_write 8003AE14, _spu_FsetRXX 8003AF4C,
    SpuWrite 8003C438, SpuSetTransferStartAddr 8003C498.
  - SpuIsTransferCompleted 8003C4F0: with flag 1 it waits through
    `bios_wait_event`, which is an interrupt point.

### B28 increment 2: logo load completes (2026-10-07)

- **DMA4 completion (strict only):** the SPU DMA CHCR write in
  `native_boot.c` now raises the DMA4 completion interrupt after clearing the
  busy bit. Before this, the loader callback 8002FC64 saw
  `SpuIsTransferCompleted(0)` fail, aborted the read and restarted it, so the
  logo overlay looped at state 5.
- **Guest time slicing:** when the clock provides `spend`, `vsync_point` now
  advances guest time in 16-line slices (2146 cycles per line, 263 lines per
  field) and polls IRQs after each slice. Without `spend` it falls back to the
  old `vblank` path.
- **libsnd/libspu VAB HLE (from disassembly):**
  - Memory: _spu_gcSPU 800416A8, SpuMalloc 80041E8C, SpuFree 8004162C.
  - VAB open and close: SsVabOpenHead 80041A20 (core 80041AB0), the sticky
    variants 80041A50/80041A80, SsVabClose 800415A8, and 800419B0.
  - VAB transfer: SsVabTransBodyPartly 80042154, SpuSetTransferMode 800422B4,
    SpuWritePartly 800422E8, SsVabTransCompleted 80042374.
  - Queries: _SsVmSetVab 800414E4, SsUtGetVagAtr 8003F144, SsUtGetVagAddr
    8003F380.
- **Traces:**
  - `MUSASHI_DRIVER_TRACE=N` prints a FRAME_TRACE line every N frames
    (overlay state, prims, loader and CD stream state).
  - `MUSASHI_CD_SECTOR_TRACE=1` logs each sector read.
- **Result:** the logo overlay reaches state 6 (32 prims) around frame 500. The
  next member, main_0004, is loaded about 50 frames later. Strict then stops at
  its dispatcher 800CEEC8, which has no C yet (the repo holds a word export
  only).
