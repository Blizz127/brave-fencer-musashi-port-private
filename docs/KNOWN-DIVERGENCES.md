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
- 93.1 M instructions (93% of the non-idle total) are in code with no
  registry entry:
  - libcd 46 M (a single sector-copy loop at 80046C38 alone is 43 M);
  - overlay code at 800CFxxx-800D3xxx, 37 M (the title/movie overlay,
    unregistered);
  - libpad 6.4 M, libetc 2.2 M, libgpu 1.2 M.

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
| D-001 | **Guest RAM is forced by default once the game is in play.** When scene 1 is reached (320x240 display, more than 800 GTE writes), the host writes the player object at 0x80126B58: `unk4D` goes 2 → 1 and the mode word 0x800B99F0 becomes 9 (gameplay). After that, every frame writes `+0xA9 = 0x41` (digital pad mode) and `+0x4D = 1`. Retail sets these itself. | `pc_port/native_boot.c`, "Control unlock", about lines 1606-1625 | It was a workaround to reach player control while the boot path was incomplete. It runs unless `MUSASHI_NO_FORCE` is set, so it is on by default. | open, and it must become opt-in or be removed |
| D-002 | The auto-start and auto-dismiss paths (`MUSASHI_BOOT_AUTO_START`, `MUSASHI_AUTO_DISMISS`, which `--headless` and `--frames` both set) inject pad presses at chosen phases and also force `unk4D` (the same write as D-001). | `native_boot.c` about lines 1164-1235, 3796-3810 | For headless tests. | opt-in, but `--headless` turns it on; the `unk4D` write is a RAM change, not input |
| D-003 | Host code shadows guest functions: at 0x8005F704 (the pad-record getter) the interpreter returns `0x80088A48 + (a0 & 0xF0)` or the live `D_80072990` record without running the retail instructions. | `pc_port/mips_formatter.c`, formatter_step | A boot-path workaround. | open; no differential |
| D-004 | Memory cards are always disconnected. Saving and loading are unavailable, and the game takes its no-card path. | `pc_port/sio_controller.c` (`disconnected_cards = 1`) | No card image backend yet. | open |

## Timing

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-010 | On the default host clock, if the game waits in `VSync` (0x800424E4 polling 0x8006CBB8) and the tick hasn't advanced, the host latches VBlank in I_STAT. The VBlank then follows host pacing, not guest CPU cycles. `MUSASHI_GUEST_CLOCK=1` (the default for `--headless`) paces VBlank by guest cycles instead. | `native_boot.c` `vsync_wait_raise_tick` | Interactive runs are host-paced. Headless on the host clock, a boot refuses at irq-dispatch (pc 80018DF4) after about 21 s with all frames black (2026-09-28). | open (host clock); untested (guest clock vs hardware cycle counts) |
| D-011 | The guest clock charges the interpreter's per-instruction cost and does not model the R3000A's cache, load delays or memory wait states. A native-lane call charges its entry's fixed `cost_cycles` (PsyQ entries: 16), not the retail instruction count. | `native_boot.c` guest-clock quantum; `mips_formatter.c` `lane_try` | Not modelled. | open; frame-timing differential not done |
| D-012 | Retail runs at 30 fps game logic. `[video] frame_rate = 60` is accepted by the config but has no effect. | `bfm_plat_config.c` | Design note only. | opt-in (no effect) |

## PsyQ library code (hand-written, not byte-matched)

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-020 | PsyQ compat entries run hand-written C instead of the retail library instructions at their PCs. This is by design: the port's PsyQ layer is PsyCross or its own code, never decompiled PsyQ. By default (`MUSASHI_PSYQ_LANE=pure`) that means every non-stub entry except the device entries and those whose body holds a port-sequenced PC. Each shim must be proven faithful by `tests/psyq_shim_probe.c` (retail on the interpreter vs the shim, same inputs, comparing v0 and guest RAM). The proven ones are in the table below. Seven were fixed after the lane probe (7935600a2). The GTE functions RotMatrix, RotMatrixYXZ/X/Y/Z and ratan2 read the game's own tables (193b41e86). All other entries have no per-entry differential yet. | `pc_port/platform/psyq/bfm_psyq_compat.def`, `pc_port/native_lane_psyq.c` | Owner rule: no decompiled PsyQ in the port. | open for every entry not proven below |
| D-021 | Entries with the `PSYCROSS` status call PsyCross (MIT, a PsyQ reimplementation), whose GTE and libgpu semantics are not retail. | `pc_port/platform/psyq/psyq_psycross.c` | Same as D-020. | untested |
| D-022 | Shims set v0 (and write memory) exactly, but leave the other caller-saved registers (v1, a0-a3, t0-t9) as they were on entry, where the retail code clobbers them. Under the o32 ABI no C caller can observe this; hand-written asm callers could. | `native_lane_psyq.c`, `mips_formatter.c` `lane_try` | Wrappers work on the live register file. | open (believed invisible; not measured) |

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
| ClearOTagR | 80059BFC | **untested**. Retail programs DMA6, which the device-less probe cannot run. The shim was corrected from the asm: retail relinks ot[0] to the terminator at 0x80072844, where the shim wrote 0x00FFFFFF, and it prints at debug level >= 2. It needs a device-backed differential. | f986ce7a8 |

"Same on N/N" is evidence for the inputs tried, not a proof for all
inputs.

## Video

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-030 | The default CPU rasteriser (`gpu_controller.c`) is an approximation. Line clipping and edge rules are not proven against hardware, and Gouraud lines use the start colour for the whole line. | `pc_port/gpu_controller.c` | Not yet hardware-accurate. | open (lines); untested (polygon edge and fill rules) |
| D-031 | Semi-transparency, mask bit and STP were fixed against an 8-case repro (`tools/headless/gpu_semi_repro.c`, 056abd331). That repro is a unit comparison, not a hardware capture. | `gpu_controller.c` | | untested against hardware |
| D-032 | `video.gpu = bfm_plat` (the GPU bridge to the bfm_plat renderer) is verified only through the splash and fade-in at 125 s. The title and gameplay haven't been compared. | `pc_port/platform/bfm_plat_gpu_bridge.c` | New path. | opt-in; untested beyond the splash |
| D-033 | The `gl` renderer blends in 8-bit float: modes 0 (B/2+F/2) and 3 (B+F/4) can differ by ±1 in a 5-bit channel. Dithering is off above 1x resolution. | `pc_port/platform/backends/gl/` | GPU precision. | opt-in (`renderer = gl`) |
| D-034 | The `psycross` renderer draws through PsyCross's GL path with PGXP; its fidelity to the PS1 GPU hasn't been compared. | `backends/renderer_psycross.c` | | opt-in; untested |
| D-035 | Widescreen (hor+ / anamorphic), HD texture replacement and texture restyle change the picture. | `bfm_plat_widescreen.c`, gl renderer, mods | Enhancements. | opt-in (off by default) |

## Audio

| ID | Divergence | Where | Why | Status |
|----|------------|-------|-----|--------|
| D-040 | SPU and XA/CD-DA output come from the port's own SPU core. Neither sample accuracy nor timing has been compared with hardware or an emulator. Headless runs use `MUSASHI_AUDIO=null`, which produces no sound. | `pc_port/spu_*`, `native_boot.c` | | untested |

## Opt-in (off by default)

These change retail behaviour only when a user asks for them:
- Cheats (`pc_port/mods/examples/cheat_pack`) and mods (docs/MODDING.md).
- `MUSASHI_GAMEPLAY_ACTION` (scripted RAM writes and input for tests).
- `MUSASHI_HOLD_R1`, `MUSASHI_DISMISS_KEY`, `MUSASHI_PAUSE_*`, and the trace and dump switches. The trace and dump switches only observe.
- Widescreen, the gl renderer, HD textures, fast-forward.

## Closed

(none yet)
