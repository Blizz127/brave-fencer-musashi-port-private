# Known divergences from retail

This is the public list of every known place where the PC port is not yet
1:1 with the retail North American PlayStation release. The standard is in
[ARCHITECTURE-PORT.md, "Purpose: preservation"](ARCHITECTURE-PORT.md#purpose-preservation).

Rules for this file:
- An entry stays until objective evidence closes it: a byte-matched C path,
  an emulator or video differential with identical output, or measured
  numbers. Evidence gets linked in the entry, and a closed entry moves to
  "Closed" with that link.
- Anything nobody has compared is **untested**, not "matches".
- Opt-in mods, cheats and debug switches that are off by default are
  listed under "Opt-in (off by default)". Everything else is a defect to fix.

Status values: **open** (differs, or is known to differ), **untested** (no
comparison yet), **opt-in** (off by default).

Seeded 2026-09-28 by reading the code on `port/platform-layer` (merged
`port/native-lane` 24d270872 and `main` f0299da37). Run the measurement
with `tools/port_matched_ratio.py`.

## Measured share (2026-09-28)

`tools/port_matched_ratio.py` was run on a headless boot to the title
screen:
- The build was lane-ON; the trace was taken with the lane off (so it is
  complete), on the guest clock, with exact per-PC counts from
  `tools/patches/trace-insns.patch`.
- It stopped at the naturally rendered Press Start prompt
  (`MUSASHI_PAUSE_AT_START_SCREEN`): 1109 frames, about 3500 s wall.
- 455 distinct guest functions ran, for 295.4 M interpreted instructions.
  195.0 M of those are the VSync wait loop (func_800424E4). Shares are
  given with that idle loop excluded (100.3 M instructions).

The shares:
- **Byte-matched C (native lane): 0.5%** of instructions, 62 functions.
- **Hand-written port code: 0.2%**, 42 functions: 9 PsyQ HLE, 4
  PsyCross, and 29 guest functions the host skips or intercepts.
- **Interpreted retail: 99.3%**, 351 functions. 212 of them have matched C
  that isn't run natively:
  - 86 are in PsyQ library ranges, which the lane policy keeps out even
    when matched;
  - 47 fail the lane's hooks rule;
  - 46 are PsyQ stub entries;
  - the rest fail other lane rules.
By domain, excluding idle, classified against the B1 lane table
(29477eed8). Overlay code is attributed to the resident MAIN.CD member
(73b802be3). That attribution is inferred from traced entries, and only
45 K instructions needed the global tie-break. The next run records exact
residency (tools/patches/trace-resident.patch).
- **Game code** (17.3 M instructions, 186 functions):
  - byte-matched C *runs* for **4.7%** (71 functions), up from 1.2% before
    B1;
  - byte-matched C *exists* for **99.85%**;
  - the gap is main_0003's matched C, interpreted because the lane has
    no overlay support yet, plus the lane-refused main-EXE functions
    (hooks and other rules).
- **PsyQ/SDK** (82.6 M, 268 functions):
  - shims run 0.2%;
  - the rest is interpreted retail: unregistered libcd (46 M, including
    the 43 M sector-copy loop at 80046C38), libpress in main_0003
    (21.4 M, D-023), libpad (6.4 M) and libetc (2.2 M).
  - Under the owner's rule, PsyQ/SDK stays platform code. The target is
    shims proven faithful, not matched C.

Shadowing:
- 31 active PsyQ shims shadow a registered matched-C function. 9 of
  them ran: memcpy, ClearOTagR, CdIntToPos, CdPosToInt, CatPrim, memset,
  SetDefDispEnv, GsInitCoordinate2 and GsSetLightMode.
- A further 15 guest functions with matched C are skipped by the host,
  for example 80016714 (startup environment clear, 3008 calls) and
  8005C388 (console putchar).

## Game logic and state

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-001 | Guest RAM was forced by default once the game was in play: player `unk4D` 2 → 1, the mode word 0x800B99F0 = 9, and every frame player `+0xA9 = 0x41` (pad type) and `+0x4D = 1`. **Fixed on `port/native-lane` in b3b33befd.** Nothing is forced by default now. The same pokes run only with `MUSASHI_DEBUG_FORCE=1` (see D-005), and `MUSASHI_NO_FORCE` is removed. | `pc_port/native_boot.c` | Workaround from before the boot path was complete. | fixed on port/native-lane (merge into this branch pending) |
| D-002 | The auto-start and auto-dismiss paths (`MUSASHI_BOOT_AUTO_START`, `MUSASHI_AUTO_DISMISS`, set by `--headless` and `--frames`) inject Start and dismiss presses. That is input only, like a player pressing buttons. Their `unk4D` RAM write is now behind `MUSASHI_DEBUG_FORCE` (b3b33befd). | `native_boot.c` | For headless tests. | opt-in (input only) |
| D-003 | The interpreter replaced the retail pad-record getter at 0x8005F704 with host code. **Fixed on `port/native-lane` in 57199ef9c**: the retail getter runs. The retail code returns 0x80078A48 (addiu sign-extends) and adds 0xF0 whenever a0 & 0xF0 is nonzero, so the override differed only for port 2 (+0x10 where retail gives +0xF0). | `pc_port/mips_formatter.c` | Boot-path workaround. | fixed on port/native-lane (merge pending) |
| D-004 | The serial card interface remains disconnected. The r31 candidate supplies the BIOS `bu00:` file device over a port-owned card image; in-game save and title Continue are not yet verified. | `pc_port/sio_controller.c`, `pc_port/bios_memcard.c` | Candidate and evidence: [memory-card verification](MEMORY-CARD-2026-09-30.md). `MUSASHI_MEMCARD=0` keeps the no-card path. | open |
| D-005 | `MUSASHI_DEBUG_FORCE=1` (debug switch) pokes guest RAM after SCENE1_REACHED: player+0x4D 2 → 1 (control unlock), 0x800B99F0 = 9 (game mode), player+0xA9 = 0x41 (pad type). It prints a DIVERGENCE line at startup and once per poke. | `native_boot.c` (b3b33befd) | Debugging only. | opt-in (off by default) |
| D-006 | `MUSASHI_GAMEPLAY_ACTION` (scripted test driver) writes pad words straight into guest RAM in gameplay (player +0xAA/+0xAC/+0xAE, 0x80078DCA, 0x80078DD2) and writes 0x800AE658. It prints a DIVERGENCE line when set (a6e3766f9). | `native_boot.c` | Automated gameplay tests. | opt-in (off by default) |
| D-007 | **Unknown cause:** why the player's pad-type byte (+0xA9) needed forcing to 0x41 for control. The D-003 override returned the retail value for port 1, so it does not explain this by itself. Static trace (2026-09-28): `func_80174714` advances player state only when `func_800CF8CC()` is false; that matched helper returns true exactly while mode `0x800B99F0` is 10. Mode 10 dispatches through member0010's `D_800D3430` table; its slot 10 handler (`0x801281B8`) reaches `func_80128714`, which polls `func_800D19F0`. That helper waits for `func_8001BE30`, whose state machine checks the CD queue and current CD request sector. This makes an incomplete CD request a plausible reason the mode-10 path stays active, but does not establish a runtime stall or an XA voice-stream cause. The nine listed functions in `provenance/matches.json` were freshly re-verified byte-exact against retail (9/9); the slot mapping was read from the extracted member0010 bytes. | pad/SIO path | Not yet known; static trace only. | open (untested) |

## Timing

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-010 | On the default host clock, if the game waits in `VSync` (0x800424E4 polling 0x8006CBB8) and the tick hasn't advanced, the host latches VBlank in I_STAT. The VBlank then follows host pacing, not guest CPU cycles. `MUSASHI_GUEST_CLOCK=1` (the default for `--headless`) paces VBlank by guest cycles instead. | `native_boot.c` `vsync_wait_raise_tick` | Interactive runs are host-paced. Headless on the host clock, a boot refuses at irq-dispatch (pc 80018DF4) after about 21 s with all frames black (2026-09-28). | open (host clock); untested (guest clock vs hardware cycle counts) |
| D-011 | **Guest time differs from retail when the native lane is on.** A native-lane call charges a fixed cost: 2 × (size / 4) cycles for generated functions, 16 for PsyQ entries. The retail instructions it replaces would have cost their interpreted cycle count. So with the lane on, VBlank-relative timing, and anything else counted in guest cycles, drifts from the all-interpreted run. On top of that, the guest clock charges the interpreter's per-instruction cost and does not model the R3000A's cache, load delays or memory wait states. Fix direction: the lane should charge the interpreted cycle count (for example a per-function count measured on the interpreter, or the retail count from a cycle model), so lane-on timing is 1:1 with lane-off. | `mips_formatter.c` `lane_try` (`cost_cycles`); `tools/native_lane_gen.py` (`cost = 2 * (size // 4)`); `native_boot.c` guest clock | Not modelled yet. | open |
| D-012 | Retail runs at 30 fps game logic. `[video] frame_rate = 60` is accepted by the config but has no effect. | `bfm_plat_config.c` | Design note only. | opt-in (no effect) |

## PsyQ library code (hand-written, not byte-matched)

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-020 | PsyQ compat entries run hand-written C instead of the retail library instructions at their PCs. This is by design: the port's PsyQ layer is PsyCross or its own code, never decompiled PsyQ. By default (`MUSASHI_PSYQ_LANE=pure`) that means every non-stub entry except the device entries and those whose body holds a port-sequenced PC. Each shim must be proven faithful by `tests/psyq_shim_probe.c` (retail on the interpreter vs the shim, same inputs, comparing v0 and guest RAM). The proven ones are in the table below. Seven were fixed after the lane probe (7935600a2). The GTE functions RotMatrix, RotMatrixYXZ/X/Y/Z and ratan2 read the game's own tables (193b41e86). All other entries have no per-entry differential yet. | `pc_port/platform/psyq/bfm_psyq_compat.def`, `pc_port/native_lane_psyq.c` | Owner rule: no decompiled PsyQ in the port. | open for every entry not proven below |
| D-021 | Entries with the `PSYCROSS` status call PsyCross (MIT, a PsyQ reimplementation), whose GTE and libgpu semantics are not retail. | `pc_port/platform/psyq/psyq_psycross.c` | Same as D-020. | untested |
| D-022 | Shims set v0 (and write memory) exactly, but leave the other caller-saved registers (v1, a0-a3, t0-t9) as they were on entry, where the retail code clobbers them (StGetNext is the exception: it sets them as retail does). Under the o32 ABI no C caller can observe this; hand-written asm callers could. | `native_lane_psyq.c`, `mips_formatter.c` `lane_try` | Wrappers work on the live register file. | open (believed invisible; not measured) |
| D-023 | main_0003 (the intro movie player) contains Sony libpress DecDCTvlcSize/DecDCTvlc at 0x800D3204-0x800D3574: handwritten SDK assembly that can never be C. It runs as interpreted retail, unmatched. For the port it is platform territory: the faithful replacement is a PsyCross or port-own DecDCTvlc, proven by a differential against interpreted retail (same bitstream in, same RAM out). | `tools/port_matched_ratio.py` `SDK_OVERLAY_RANGES` | Planned. | open (interpreted retail today, so faithful by construction until replaced) |
| D-024 | Native `VSync(mode < 0)` (the release default since 2026-10-01, also `pure+vsync` or `all`; `MUSASHI_PSYQ_LANE=pure` opts out) differs from retail `8004239C` in three ways. (1) It no longer reads GPUSTAT (`*8006BA94`) and Timer1 hcount (`*8006BA98`); retail discards both on this path, so the only effects lost are the device-observation trace records (`MUSASHI_TRACE_DEVICE_OBS` hashes differ from the interpreted path by construction) and the lazy-epoch commit those two loads triggered (the wrapper runs `device_sync` first, which commits the same time). (2) It runs atomically: charged the interpreter's 64 cycles (26 instructions at 2 plus 12 memory accesses at +1) after the call. A vblank that falls inside those 64 cycles is delivered at the next checkpoint, so the returned tick can be one lower than retail would return, where retail could deliver the IRQ mid-routine. Estimated frequency about 64 / 564,000 per call, roughly 1e-4, so on the order of ten of the ~90,000 route calls; both orders are legal hardware timing. This is the same lane-wide race S1 StGetNext has with its ring-filling IRQ. (3) Latency the device layer might add for the two discarded loads is not charged. Modes 0, 1 and n > 1 are NOT native: they refuse before any write and the interpreter runs the retail words, including the `800424E4` wait loop and the `vsync_wait_raise_tick` hook. `800426D4` (a flag read) and `800426FC` (an I_MASK swap, a device access) are separate libcd/libgpu routines, not VSync internals, and stay interpreted. | `pc_port/platform/psyq/bfm_psyq_compat.c` `bfm_psyq_VSync`, `pc_port/native_lane_psyq.c`, `tools/native_lane_gen.py` `HLE_REPLACED_GATES` | Owner rule: native game and SDK code, no interpreter; the waiting modes need the guest clock and IRQ delivery. | open (release default after runner gate `20261001-191919-bfm-owncode-fdd04fc114`) |
| D-042 | S3a libpad leaves (`MUSASHI_PSYQ_LANE=pure+vsync+pad` or `all`; the release default `pure+vsync` keeps them retail). `8005FBA8`, `8005FBC8`, `8005E0AC`, `8005DCA0`, `8005DE78`, `8005E13C` and `8005F394` run as owner-written C inside the input BIOS callback frame instead of as interpreted retail words. They make the same guest loads and stores, in the same order, at the same addresses, and the frame charges each retail instruction they stand for exactly as its interpreter does: one unit of the frame's 16384-instruction budget, then 2 cycles (+1 for a load/store) through the frame clock before the access, with the device-observation PC set to the retail PC. So budget exhaustion, clock refusals, the SIO byte timing, ACK due cycles, Timer2 count/last_cycles, I_STAT edges and `MUSASHI_TRACE_DEVICE_OBS` records are the same as the interpreted words (G1 differential and the village DEVOBS/PAD_TRACE streams, below). Differences: (1) the frame does not fetch and admit each retail word; instead each call checks an FNV-1a 64 digest of the leaf's words (and of the leaves it calls) through the same code-word path and refuses on any mismatch; the leaves assume their own words are not overwritten during the call. (2) After a mid-leaf fault (budget, clock or access refusal) the caller-saved registers can differ from the interpreter's at the faulting instruction; the frame discards its CPU on a fault, so this is not observable. (3) The leaves refuse, before any side effect, when the SIO/I_STAT pointer slots `800729C0`/`800729BC` hold anything but `1F801040`/`1F801070`, on a pending LWL/LWR or MFC2 load, a non-sequential entry, or when the frame's 8-deep call stack would overflow; the retail words then run. (4) Function-trace counts: a leaf entry counts as native only when the leaf ran; nested calls inside a native leaf (`8005FBC8` from `8005DCA0`/`8005DE78`/`8005E0AC`, `8005FBA8` from `8005DE78`) are recorded as native entries. The handler `8005D734`, `8005DBD8`, the step bodies, the TAP/config code and `8005F830`/`8005FA94` stay interpreted. | `pc_port/platform/psyq/bfm_psyq_libpad.c`, `pc_port/mips_formatter.c` (`input_pad_leaf`), `pc_port/native_lane_psyq.c`, `pc_port/native_boot.c` | Owner rule: native SDK code; the pad driver's busy-waits were the largest interpreted SDK block left. | opt-in; release default flip pending the integrator's runner gate |

### PsyQ shim differential status (`tests/psyq_shim_probe.c`, 96 inputs each)

| Shim | PC | Result | Evidence |
|------|----|--------|----------|
| memcpy | 8005C324 | same on 96/96 after fixing overlapping forward copy, NULL dst and n <= 0 | f986ce7a8 |
| memset | 8005C358 | same on 96/96 after fixing NULL dst and the return of 0 for n <= 0 | f986ce7a8 |
| bzero | 8005C2C8 | same on 96/96 (v0 too) after the same fix | f986ce7a8 |
| CatPrim | 80058CE4 | same on 96/96 | 1a8944bb4 |
| CdIntToPos | 80043A18 | same on 96/96 (including negative and large values) | 1a8944bb4 |
| CdPosToInt | 80043B1C | same on 96/96 (valid and invalid BCD) | 1a8944bb4 |
| SetDefDispEnv | 80058B04 | same on 96/96 | 1a8944bb4 |
| GsInitCoordinate2 | 80052D90 | same on 96/96 (NULL and non-NULL super) | 1a8944bb4 |
| GsSetLightMode | 800538EC | same on 96/96 | 1a8944bb4 |
| StGetNext | 80046C38 | same on every case of `tests/psyq_stgetnext_probe.c` (CTest `psyq_stgetnext_differential`): named ring states (empty, one/several frames with the retail StFreeRing in between, wrap marker with and without an end frame, marker at slot 0, partial frame, the not-ready spin, odd statuses, 32-bit index wrap, KUSEG/KSEG1/scratchpad rings and outputs, aliased outputs, refusals) plus 400 random scripts; compares the whole register file and all of guest RAM and scratchpad after every call, interpreter vs lane vs direct. Unlike D-022 it also leaves at/v1/a0-a3/t0 as retail does. | see PSYQ-COMPAT.md |
| func_80049440 (LZC) | 80049440 | same on every case of `tests/psyq_lzc_probe.c` (CTest `psyq_lzc_differential`): the retail MTC2 LZCS / MFC2 LZCR run on the interpreter over a real `gte_owner` (test-only transfer adaptor) against `bfm_psyq_LZC` through the lease bridge; compares v0, all 32 data and 32 control GTE registers, the owner's data-write/data-read/command/control-write counters (the HLE credits exactly one write and one read, as the two interpreter transfers do) and all guest RAM and scratchpad. Cases: 0, 1, -1, INT_MIN, INT_MAX, every single bit and its complement, every leading-zero and leading-one run length 1..32 with random tails, 600 random values (mixed magnitudes), and refusals (no bridge, lease already held, counter overflow) which leave bank, counters and RAM untouched. Class: GTE-bank access under the owner lease; no device I/O and no guest RAM. Registers other than v0 are unchanged by the HLE; the interpreter's own register file is not exposed by the nested-call API, so that side is read from the asm (v0 is the only register the retail words write). | see PSYQ-COMPAT.md |
| VSync (mode < 0) | 8004239C | same on every case of `tests/psyq_vsync_probe.c` (CTest `psyq_vsync_differential`): the retail words on the interpreter (lane suspended) against the lane wrapper (device_sync, then HLE) through `lane_try`, and the wrapper called directly; compares completion, the whole register file after the call (v0 = tick, v1 = the 8006BA9C latch, s0/s1/ra restored) and every byte of guest RAM and scratchpad, including the three dead stack slots below sp that the retail prologue fills. Cases: modes -1, -2, INT_MIN, INT_MIN+1, seven sp placements (kseg0, kseg1, kuseg, near the RAM ends), tick 0 and 0xFFFFFFFF, latch 0, lazy-epoch cases with a deferred vblank the sync must commit before the tick read (oracle applies the commit first, as the retail GPUSTAT load would), 200 random states; the sync hook must be called exactly once per native call. Refusals (modes 0, 1, 2, 16, 3, 1000, 0x7FFFFFFF, each with and without a pending commit; a failing device_sync; unaligned, low and unmapped sp) return 0 with every register and all RAM byte-identical. Mode 1 runs through the lane against the oracle (the interpreter completes it). Class selector and table membership for unset/pure/pure+vsync/all/0 are checked, and the entry cost is 64 cycles. Not covered: modes 0 and n > 1 against retail (the oracle's wait spins without a vblank source); those are shown interpreted by the village trace counts. | see D-024 |
| libpad leaves (S3a) | 8005FBA8, 8005FBC8, 8005E0AC, 8005DCA0, 8005DE78, 8005E13C, 8005F394 | same on every case of `tests/input_pad_leaf_probe.c` (pytest `tests/test_input_pad_leaf.py`): two identical universes (guest RAM, scratchpad, callback frame, SIO0 and Timer2 models, I_STAT latch, clock), retail words vs native leaves; compared after every step: all RAM and scratchpad, the frame stack/busy/faulted, every SIO field (FIFO, status, cycle, ack_due, pad state, analog mode), Timer2 count/mode/target/last_cycles, I_STAT and ACK state, the per-byte tx/rx log with tx cycle and ACK due, button samples, clock-charge count and cycles, handler result and stop PCs; per leaf also the whole register file and the remaining budget. Frame level: cold TAP negotiation (96 VBlanks), 1000 VBlanks of random buttons and sticks, PadSetAct-style motor/config buffers, lost and late ACKs beyond the 3440/3200/480-cycle timeouts, /ACK held low (the E0AC wait), Timer2 mode bit 0x200 with a nonzero target, mutated reply bytes (multitap/config IDs), all at once, single-VBlank SIO pointer corruption (leaves refuse, retail runs), a frozen clock (host stop, budget exhaustion), and every budget and every clock-refusal point of whole handler calls (5,498 and 7,515 instructions, plus a perturbed call). Leaf level: 4,200 random states (records, buffers, pointers, step index, RC2 latches, SIO protocol states, ACK latch, Timer2 phase/mode/target, stack in KUSEG/KSEG0/KSEG1) with budget and clock-refusal sweeps. Zero-side-effect refusals: wrong code digest, pending LWL/LWR, non-sequential entry, call depth, both pointer slots. Trace honesty: refused calls stay interpreted. 53,743 cases, 0 different. Six deliberate breaks (RC2 shift, dropped I_STAT ack, baud 0x89, dropped CTRL bit 4, one extra cycle charge, select byte not sent) each report differences (9,445 to 26,806 cases). | see D-042 |
| ClearOTagR | 80059BFC | **untested**. Retail programs DMA6, which the device-less probe cannot run. The shim was corrected from the asm: retail relinks ot[0] to the terminator at 0x80072844, where the shim wrote 0x00FFFFFF, and it prints at debug level >= 2. It needs a device-backed differential. | f986ce7a8 |

"Same on N/N" is evidence for the inputs tried, not a proof for all
inputs.

## Video

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-030 | The default CPU rasteriser (`gpu_controller.c`) is an approximation. Line clipping and edge rules are not proven against hardware, and Gouraud lines use the start colour for the whole line. Its polygon edge rule is inclusive: a pixel whose integer position lies exactly on any edge is drawn, so an axis-aligned quad from x0 to x1 is x1-x0+1 pixels wide. The PS1 (psx-spx) and the `gl` renderer use the top-left rule and leave the right/bottom edge pixels undrawn; `tests/bfm_gl_ctl_probe.c` measures about 0.3-0.8% of random polygon pixels as such edge pixels. It also keeps the E1 texpage when a textured polygon carries its own (the hardware and the bridge make the polygon's texpage current for later rects and untextured blends), and ignores the texture window (E2). | `pc_port/gpu_controller.c` | Not yet hardware-accurate. Changing it changes the shipped Original picture, so it needs its own gate. | open (lines, edge rule, texpage state, E2) |
| D-031 | Semi-transparency, mask bit and STP were fixed against an 8-case repro (`tools/headless/gpu_semi_repro.c`, 056abd331). That repro is a unit comparison, not a hardware capture. | `gpu_controller.c` | | untested against hardware |
| D-032 | `video.gpu = bfm_plat` is opt-in. GL startup context ownership fixed; village 1010 reached on blizzpc. The gl renderer now samples at integer positions with the PS1 integer colour formulas, and against `gpu_controller.c` on a synthetic stream every opaque pixel off a polygon edge is bit-exact at 1x (`tests/bfm_gl_ctl_probe.c`). Scanout differs: the cpu presenter's draw-clip workaround shows the drawing area while the gl path shows the GP1 display page. Village picture parity after the change is being measured (see the graphics design doc). | `pc_port/platform/bfm_plat_gpu_bridge.c`, `backends/renderer_gl.c`; [graphics evidence](GRAPHICS-ENHANCEMENTS-DESIGN.md#integer-sample-points-and-controller-parity-handoff-9139aade) | New path; scanout semantics need an explicit contract. | opt-in; rasterisation matches the controller off edges, scanout and village parity open |
| D-033 | The `gl` renderer blends in 8-bit: modes 0 (B/2+F/2) and 3 (B+F/4) can differ by one 5-bit step from the PS1's truncation (modes 1 and 2 are exact). Dithering is off above 1x resolution. Above 1x, texture coordinates and colours are interpolated in float (about 0.004% of random textured pixels pick the neighbouring texel). | `pc_port/platform/backends/gl/` | GPU precision; the HD path keeps 8 bits. | opt-in (`renderer = gl`) |
| D-034 | The `psycross` renderer draws through PsyCross's GL path with PGXP; its fidelity to the PS1 GPU hasn't been compared. | `backends/renderer_psycross.c` | | opt-in; untested |
| D-035 | Widescreen (hor+ / anamorphic), HD texture replacement and texture restyle change the picture. | `bfm_plat_widescreen.c`, gl renderer, mods | Enhancements. | opt-in (off by default) |
| D-036 | The `gl` renderer draws textured mode-2 (B−F) prims in two passes per draw command: all texels without STP opaque, then all STP texels subtracted. Where prims of one draw overlap and the later prim's non-STP texel lands on an earlier prim's STP texel, the PS1 shows the opaque texel while the gl path subtracts the STP texel over it. Found with self-overlapping quads in `tests/bfm_gl_ctl_probe.c`; not observed in the game. | `pc_port/platform/backends/gl/bfm_gl_exec.c` | Dual-source blending cannot express reverse subtract. | opt-in (`renderer = gl`); open |

## Audio

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-040 | SPU and XA/CD-DA output come from the port's own SPU core. Neither sample accuracy nor timing has been compared with hardware or an emulator. Headless runs use `MUSASHI_AUDIO=null`, which produces no sound. | `pc_port/spu_*`, `native_boot.c` | | untested |
| D-041 | Pre-title audio is silent in the headless run. 1200 s runs (native lane, guest clock) reach the Squaresoft logo, about 25-28 s of guest time. The only KON writes are libspu SpuInit's two passes over all 24 voices, at volume 0 and ADSR 0, on the silent block 0x0200. The sink receives about 340k frames, all zero. Whether retail plays anything during the publisher and Squaresoft logos is **untested**, pending an emulator or video reference. | SPU path | | untested |

## Opt-in (off by default)

These change retail behaviour only when a user asks for them:
- Cheats (`pc_port/mods/examples/cheat_pack`) and mods (docs/MODDING.md).
- The Port Dev Menu (on by default through the package's `launch.sh`; `BFM_DEV_MENU=1` or `--dev-menu`, `pc_port/dev_menu.c`; docs/PC-PORT.md): cheats that write the game's own HP/BP/Drans/clock state in the field only, and warps through the game's own exit request, listed once verified. Off, it writes nothing, reads no input and draws nothing; enabled with every cheat off it writes zero guest bytes (`tests/dev_menu_probe.c`); while open, the game reads a neutral pad. `BFM_CHEATS=0` disables it completely.
- `MUSASHI_DEBUG_FORCE=1` (D-005) and `MUSASHI_GAMEPLAY_ACTION` (D-006): both write guest RAM and log DIVERGENCE.
- `MUSASHI_HOLD_R1`, `MUSASHI_DISMISS_KEY`, `MUSASHI_PAUSE_*`, and the trace and dump switches. The trace and dump switches only observe.
- Widescreen, the gl renderer, HD textures, fast-forward.

## Closed

(none yet)
