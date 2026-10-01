# Own-code native lane: first runtime evidence (2026-10-01)

Build: port `ea18cf0ec1`, release configuration (`MUSASHI_NATIVE_LANE=ON`,
`MUSASHI_LANE_OWN_CODE_ONLY=ON`, RelWithDebInfo `-O2 -march=x86-64-v3`).
`native_lane_gen` admits 348/395 game functions (219/262 before the
2026-10-01 clean-room merge-backs). Retail guard: 7 files, 0 problems.
Executable SHA256 `e16ea066...9c06`; package `owncode-ea18cf0ec1.tar.gz`
SHA256 `d16aecb5...b37a`, matched by runner readback. Evidence is owner-local
in `~/release-staging/bfm-owncode-ea18cf0ec1/`.

Runner jobs (blizzpc): `20261001-124858-bfm-owncode-ea18cf0ec1` (evidence
SHA256 `f41a61ec...0810`) and `20261001-125846-bfm-owncode-bisect` (evidence
`378372b1...cf8c`). Both hashes match on runner and owner box.

| Route | Result |
|---|---|
| Village 1010 warp, lane on (plain and traced) | PASS: `NATIVE_LANE entries=409 psyq=61`, `[WARP] arrived 1010.0`, `HOST_STOP source=IN_GAME_TARGET`, display 70196/76800 non-black |
| Idle attract, lane on, untraced (4 legs) | Same end state as shipped r30 (`20260930-111232-bfm-r30gateP2` attract_idle): `STEP_REFUSED pc=800495ec`, then `NATIVE_LANE_ABORT pc=80011380 code=4` with identical registers. Not a regression. |
| Idle attract, lane on, `MUSASHI_TRACE_FUNCS` set | Different: `NATIVE_LANE_ABORT pc=80011380 code=5`, `STEP_REFUSED pc=ffffffff`. Open: the tracer changes this route's outcome. |
| Village, `MUSASHI_NATIVE_LANE=0` | Stops at boot (`startup=PARTIAL`, `EXECUTION_BOUNDARY reason=REFUSED`, black display), so there is no same-input lane-off parity yet. Not checked against an older build. |

The bisect legs with runtime deny lists (`MUSASHI_NATIVE_LANE_DENY`, all 133
new PCs or each half) ended identically to the undenied leg. The
`NATIVE_LANE entries=` line is printed before deny filtering, so these logs
don't show that the deny list took effect. The r30 comparison above is the
evidence that this end state is not a regression.

## Measured call share (village route, release configuration)

`trace_share.py` over `village_trace/trace.counts` (function entries, not
cycles):

| Region | Native calls | Interpreted calls | Native share |
|---|---|---|---|
| main executable | 51,541 | 208,072 | 19.9% |
| overlays | 0 | 150,245 | 0% |
| all regions incl. PsyQ | 92,266 | 3,463,403 | 2.6% |

Distinct main functions executed: 133 native, 208 interpreted; overlays 0
native, 793 interpreted. Top interpreted entries: `80046c38` (libcd2,
2,297,066 calls), pad polling `8005fbc8`/`8005fba8`/`8005e0ac`/`8005dbd8`
(libpad), VSync `8004239c` and its internals `800426d4`/`800426fc` (libetc),
main `8001d388` and `8001fb8c`, overlay `8012a988`. No pre-merge release
trace exists, so this is a single measurement, not a before/after.

The runtime is hybrid: boot enters through the interpreter
(`boot_entry`), overlays are interpreted, and 205 lane call stubs are thunks
back into the interpreter. Nothing here is a native-completion claim.

## Staged proposal: top 20 interpreted entries (village route)

Shares are of the 3,463,403 interpreted calls. "Reached from" is the first
traced caller: game code means a game (non-PsyQ) PC calls it directly, and
SDK-internal means only library code calls it. PsyQ code never enters the
port (`config/psyq_ranges.txt` policy), so the SDK route is owner-written
host HLE at the entry point the game calls. With that in place the library
internals stop executing. Each HLE needs a differential check against the
interpreted original on the same input (returned values plus the guest state
it touches), not call counts: polling loops legitimately change their
iteration count.

| Stage | PCs (calls) | What | Reached from | Route |
|---|---|---|---|---|
| S1 | `80046c38` StGetNext (2,297,066; 66.3%) | libcd2 stream ring: next sector or not-ready | game, `800d27c4` (main_0003 poll loop) | SDK HLE over the stream ring in guest RAM: `bfm_psyq_StGetNext`, class pure (no device access; the ring is filled by the interpreted stream interrupt), differential `psyq_stgetnext_differential`; done on `claude/s1-stgetnext` (see below) |
| S2 | `8004239c` VSync (89,573), internals `800426d4` (56,946), `800426fc` (34,234): 5.2% | libetc frame wait and callback dispatch | SDK-internal (`80044150`, `80044258`, `8005b81c`) | Revised after the S2 audit: `800426d4` (a libcd flag read) and `800426fc` (an I_MASK swap) are NOT VSync internals and stay interpreted. VSync itself: native for `mode < 0` only, behind `MUSASHI_PSYQ_LANE=pure+vsync` (see "S2" below) |
| S3 | libpad `8005fbc8` (200,361), `8005fba8` (45,336), `8005e0ac` (26,666), `8005dbd8` (18,670), `8005dca0` (18,666), `8005f394` (15,998), `8005de78` (10,668): 9.7% | pad SIO exchange and handshake waits | SDK-internal only (pad interrupt/VSync callback chain) | HLE the pad driver's interrupt handler and the pad entry points on `bfm_plat_input` and the existing SIO wire shim; device/IRQ seam, highest timing risk |
| S4 | libgte24 `80049440` (22,346; 0.6%) | GTE helper | game, `80012928` | HLE through the GTE bridge (`bfm_psyq_LZC`, `musashi_gte_owner_native_lzc`), done on `claude/s4-libgte24` (see below) |
| S5 | libgpu2 `8005ba90` (13,207), `8005c020` (11,145): 0.7% | packet/OT internals | SDK-internal | HLE at the libgpu entry points; partly bypassed already on `MUSASHI_GPU=bfm_plat` |
| game | main `8001d388` (50,944), `8001fb8c` (38,208), `80020da4` (12,653): 2.9% | game code | game | clean-room re-derivation, then allow list |
| game | overlay `8012a988` (19,104), `80134a28` (11,364), `8017869c` (8,652): 1.1% | overlay game code | game | clean-room re-derivation plus the digest-checked overlay own-code lane (0 overlay entries today) |

If S1-S3 were native on this route, about 81% of today's interpreted calls
would stop interpreting. Entry counts aren't cycles, and the overall share
would still be bounded by boot and overlays running in the interpreter.
Suggested order: S1, then S4 (small, game-called), S2, then S3.

## Re-run on the 427/496 lane (port `89bd42dc10`)

Job `20261001-160659-bfm-owncode-89bd42dc10` (evidence SHA256 `3a6bcc64...3618`,
matched by readback). Executable SHA256 `c6aa807c...23d9`; retail guard 7
files, 0 problems; lane `entries=488 psyq=61`.

| Route | Result |
|---|---|
| Village 1010, plain and traced | PASS: `[WARP] arrived 1010.0`, `HOST_STOP source=IN_GAME_TARGET`, display 70196/76800 non-black (same as the 348/395 run) |
| Idle attract, untraced | Same end state as shipped r30: `STEP_REFUSED pc=800495ec`, then `NATIVE_LANE_ABORT pc=80011380 code=4` with identical registers |

Village call share, before and after the later merge-backs:

| Region | 348/395 lane | 427/496 lane |
|---|---|---|
| main executable, calls | 19.9% native | 24.1% native (59,838 of 248,070) |
| main executable, distinct functions | 133 native / 208 interpreted | 148 native / 167 interpreted |
| overlays | 0% | 0% (793 interpreted) |
| all regions incl. PsyQ | 2.6% | 2.8% (100,562 of 3,544,966) |

The overall share barely moves because `StGetNext` (`80046c38`, 2,297,212
calls) dominates; that's stage S1 above.

## S1 StGetNext HLE: local check (branch `claude/s1-stgetnext`)

Devbox only, not a runner job: this Xeon (no AVX2) cannot execute the
`-march=x86-64-v3` release binaries, so the route ran on a lane build with
the release options minus `-march` (`build/lanes/owncode-s1-local`); the
release-flag tree builds and passes `check_port_retail.py` (7 files, 0
problems). Lane `entries=489 psyq=62` (was 488/61), gen 427/497.

| Leg (village 1010 warp script) | Result |
|---|---|
| HLE | `[WARP] arrived 1010.0`, `HOST_STOP source=IN_GAME_TARGET`, no `NATIVE_LANE_ABORT`, display 70196/76800 non-black |
| `MUSASHI_NATIVE_LANE_DENY=80046c38` (retail StGetNext interpreted), same binary | identical end state and display count |
| HLE, `MUSASHI_TRACE_FUNCS` | same end state; `80046c38` 4,430,154 calls, all native; all regions 4,530,716 native / 1,147,282 interpreted calls (79.8% native by calls) |

The poll loop at `800d27c4` now iterates more often per CD sector (it spins
faster), so its call count rose; call counts are not cycles. The rest of the
interpreted work is S2/S3 (VSync, libpad), overlays and boot.


## S1 landed: StGetNext HLE on the release binary (port `65ed2743d0`)

Job `20261001-170055-bfm-owncode-65ed2743d0` (evidence SHA256
`237e2e76...81ac5`, matched by readback). Executable SHA256 `bd95bfb0...403c`
(release `-march=x86-64-v3` build); retail guard 7 files, 0 problems; lane
`entries=489 psyq=62` (was 488/61).

| Route | Result |
|---|---|
| Village 1010, plain and traced | PASS: `[WARP] arrived 1010.0 ... vblanks=416`, `HOST_STOP source=IN_GAME_TARGET`, display 70196/76800 non-black, the same as before S1 |
| Idle attract, untraced | Same end state as shipped r30 (`STEP_REFUSED pc=800495ec`, then `NATIVE_LANE_ABORT pc=80011380 code=4` with identical registers) |

Village trace:

| Measure | Before S1 (`89bd42dc10`) | After S1 |
|---|---|---|
| interpreted calls, all regions | 3,444,404 | 1,147,282 (-67%) |
| StGetNext `80046c38` | 2,297,212 interpreted | 4,430,154 native, 0 interpreted |
| libcd2 interpreted | 2,299,733 | 2,521 |
| native share of calls, all regions | 2.8% | 79.8% |
| main executable / overlays | 24.1% / 0% | 24.1% / 0% |

The polling loop at `0x800D27C4` calls StGetNext about twice as often once
each poll is native (4.43M native calls against 2.30M interpreted before) on
the same route, with the same warp vblank count and the same picture. That
inflates the "share of calls" figure, so the interpreted-call count is the
better progress measure. Next by interpreted calls: pad polling (S3), VSync
and its internals (S2), main `8001d388`/`8001fb8c`, libgte24 `80049440` (S4),
overlay `8012a988`.


## S4 LZC HLE (`80049440`, branch `claude/s4-libgte24`)

`func_80049440` is `mtc2 a0,$30; mfc2 v0,$31`: it moves a0 into GTE LZCS and
returns LZCR (the number of leading bits equal to the sign bit, 1..32),
leaving LZCS/LZCR in the shared cop2 data bank. No RAM, no other register.
Class: GTE-bank access under the `gte_owner` lease (installed with the
release default, like the PsyCross GTE wrappers); no device I/O, no guest RAM.

New code, all native C: `bfm_psyq_LZC` (`bfm_psyq_libgte.c`), an optional
`lzc` hook on `BfmPsyqGteBridge` with `bfm_psyq_gte_lzc`, and
`musashi_gte_owner_native_lzc`, which reuses the owner's one LZCS commit
(`gte_commit_lzcs`, factored out of the interpreter's MTC2 path unchanged) and
credits one data write and one data read as the interpreter's MTC2 + MFC2 do.
Differential: `tests/psyq_lzc_probe.c` (CTest `psyq_lzc_differential`), see
KNOWN-DIVERGENCES.md.

Generator exemption: `tools/native_lane_gen.py` treats every PC that
`mips_formatter.c` compares against as port-hooked and keeps it out of the
lane. The only references to `0x80049440` and `0x8004944C` there are
`formatter_step`'s COP2 leaf admission for the two transfer instructions,
which only matters when the retail routine runs interpreted, and sequences
nothing. `HLE_REPLACED_GATES` removes exactly those two PCs from the hooked
set so the HLE entry is admitted. Interpreted retail code still goes through
the same admission. Any future entry added there needs the same argument.

Evidence (worker, devbox): 741 cases, 0 different in the default and lane
builds; deliberate breaks: count+1 for every input 741/741, off-by-one at one
value 1, read credit skipped 738, LZCS written without LZCR 678. CTest 32/32
(default) and 33/33 (lane). The `gte_*` pytest suite fails the same 10 tests
on the base `8d7a3923dd` (cc -Werror mutants and one export test), so they
are pre-existing. Release-flag build: 427/497 admitted, retail guard 7/0.
Local no-march lane binary: `NATIVE_LANE entries=490 psyq=63`, village warp
`[WARP] arrived 1010.0` and `HOST_STOP source=IN_GAME_TARGET`, with no
`NATIVE_LANE_ABORT`.

### S4 on the release binary (port `fbeab8c4e8`)

Job `20261001-175927-bfm-owncode-fbeab8c4e8` (evidence SHA256 `41024ca1...b915`,
matched by readback; executable `bbf37566...4461`, x86-64-v3; retail guard
7/0; `entries=490 psyq=63`). Village plain and traced PASS (warp vblanks
416, `HOST_STOP source=IN_GAME_TARGET`); attract ends as shipped r30.
`80049440`: 22,346 native calls, 0 interpreted. Village interpreted calls
1,147,282 (after S1) -> 1,124,936. Main executable 24.1%, overlays 0%.

## S2 VSync(-1) native path (branch `claude/s2-vsync`)

Opt-in class `MUSASHI_PSYQ_LANE=pure+vsync` (also part of `all`); the release
default is unchanged (`pure`). Only `VSync(mode < 0)` is native: it returns the
guest tick `8006CBB8` after `device_sync`, sets v1 to the `8006BA9C` latch and
fills the three dead stack slots the retail prologue writes, and is charged the
interpreter's cost for that path (64 cycles). Modes 0, 1 and n > 1 refuse before
any write; the interpreter runs the retail words, including the `800424E4` wait.
`800426D4` and `800426FC` are libcd/libgpu routines, not VSync internals, and
are unchanged. Retail words skipped natively and the effects of skipping are
listed in KNOWN-DIVERGENCES D-024.

Generator: `0x8004239C` and `0x800424CC` (VSync's own shared epilogue, inside
its body because it has no registry size) are exempted like the LZC gates.
Every action keyed to those PCs is an admission or whitelist for interpreted
execution (the CD IRQ frame word table and call edges, which run with the lane
suspended; `formatter_admitted`'s range table; prefix runners nothing in the
production boot calls). Nothing there advances guest time, delivers an IRQ or
counts. `800424E4`, `800426D4` and `800426FC` stay hooked.

### Local evidence (no-march lane build, `NATIVE_LANE entries=491 psyq=64`, was 490/63)

Same-input differential `tests/psyq_vsync_probe.c` (CTest
`psyq_vsync_differential`): 236 cases, 216 native completions, 19 clean
refusals, 0 different (retail oracle vs lane vs direct; return registers, whole
register file, all RAM and scratchpad). Deliberate breaks, each failing then
restored to 0 different: stale tick (216 different), `device_sync` skipped (218),
dead stack slots not filled (216).

Village 1010 warp (`MUSASHI_GUEST_CLOCK=1`, unthrottled, `MUSASHI_TRACE_DEVICE_OBS=1`):

| Config | Warp vblanks | Final vblank / cycle | `8006CBB8` / `8006BA9C` / `8006BAA0` at stop | Stop | DEVOBS events / hash |
|---|---|---|---|---|---|
| pure, `EPOCH_LAZY=1` | 416 | 2784 / 1571848430 | 2784 / `00002918` / 2782 | `IN_GAME_TARGET` | 2,566,399 / `11f6b07a2e147a36` |
| pure, `EPOCH_LAZY=0` | 416 | 2784 / 1571848430 | 2784 / `00002918` / 2782 | `IN_GAME_TARGET` | 2,566,399 / `11f6b07a2e147a36` |
| pure+vsync, `EPOCH_LAZY=1` | 416 | 2784 / 1571848430 | 2784 / `00002918` / 2782 | `IN_GAME_TARGET` | 2,412,193 / `8dcbfa55a61f3ddc` |
| pure+vsync, `EPOCH_LAZY=0` | 416 | 2784 / 1571848430 | 2784 / `00002918` / 2782 | `IN_GAME_TARGET` | 2,412,193 / `8dcbfa55a61f3ddc` |

Every per-vblank DEVOBS line is identical between lazy 0 and 1 within each
configuration. The hash differs between configurations by construction: the
native path performs no GPUSTAT/Timer1 reads (154,206 fewer device events, two
per native call, about 77,100 calls) while the guest cycle count, tick, latch,
GTE write count (168,789) and stop are identical. `trace.counts`: `8004239c`
89,779 entries in both; `800424e4` 3,120 interpreted entries in both (two per
waiting VSync, so 1,560 waiting calls stay interpreted).

Mode mix (`MUSASHI_TRACE_PCS=8004239c`, 86,085 entries seen at interpreter
stepping; 3,694 of the 89,779 counted entries reach the PC without passing that
hook, split not measured): `a0 = -1` 80,624 (93.7%), `1` 3,901 (4.5%), `2` 935
(1.1%), `0` 625 (0.7%). Interpreted by design: 1,560 waiting calls + 3,901
mode-1 calls. Calls inside the CD IRQ frame and IRQ callbacks also stay
interpreted (the lane is suspended there).

Tests (lane build): CTest 34/34 (was 33; the new test is
`psyq_vsync_differential`), retail guard 7 files, 0 problems,
`tests/test_native_lane*.py` + `test_psyq_exclusion.py` 15 passed / 1 skipped,
`tests/test_bfm_plat.py` 37 passed / 1 skipped. The `-k gte` pytest group
fails the same 27 tests with and without this change.

### S2 runner gate on the release binary (port `fdd04fc114`)

Job `20261001-191919-bfm-owncode-fdd04fc114` (evidence SHA256
`ade91c6e...1172`, matched by readback; executable `1bba469d...f2fe8`,
x86-64-v3; retail guard 7/0).

| Leg | Result |
|---|---|
| village, `MUSASHI_PSYQ_LANE` unset (pure at the time) | `[WARP] arrived 1010.0 ... vblanks=416`, `HOST_STOP source=IN_GAME_TARGET`, display 70196/76800 |
| village, `pure+vsync` | identical: warp vblanks 416, stop tick `00000ae0` (2784), IRQ deliveries 11234, vblank slots, card call counts and display all equal to the pure leg |
| village, `pure+vsync`, traced | PASS; `8004239c` 89,779 entries classed native, `800424e4` (wait loop) 3,120 interpreted, `800426d4`/`800426fc` interpreted as expected |
| attract, `pure+vsync` | same end state as shipped r30 |

The tracer classes an entry by lane-table membership, so the refused VSync
calls (modes 0, 1 and n > 1, about 6% of entries by the worker's measured mode
mix) count as "native" there even though the interpreter runs them; about
80,600 calls actually run natively. Village interpreted calls by the tracer's
count: 1,124,936 -> 1,035,157 (the true reduction is about 80,600).

Following this gate the release default became `pure+vsync`
(`musashi_native_lane_psyq_classes`), and `MUSASHI_PSYQ_LANE=pure` opts out.

Default flip verified: job `20261001-192821-bfm-owncode-b41faa01d5` (evidence
`93c37bbf...0c4150`, matched by readback; executable `decf51c2...64b0`). Unset
`MUSASHI_PSYQ_LANE` logs `entries=491 psyq=64 classes=pure+vsync`, and
`MUSASHI_PSYQ_LANE=pure` logs `entries=490 psyq=63 classes=pure`. Both reach
the village with warp vblanks 416, stop tick `00000ae0` and display
70196/76800. `musashi_psyq_vsync_probe` on the runner against the user's
SLUS_007.26: 236 cases, 216 native completions, 19 refusals, 0 different.

## S3a libpad leaves (branch `claude/s3-pad`)

Opt-in class `MUSASHI_PSYQ_LANE=pure+vsync+pad` (also part of `all`); the
release default is unchanged (`pure+vsync`), and `pure` or `0` keeps every
leaf retail. Not lane entries: the pad driver's VBlank handler `8005D734`
runs in the input BIOS callback frame (`musashi_boot_execute_input_bios_callback`),
an admitted-word interpreter that never consults the lane, so the frame
itself dispatches the leaves, at the point where `input_callback_call` has
accepted the exact `jal`/`jalr` edge (and the live slot, for `8005F394`
through `80072964`) and the delay slot has run; the leaf returns to
`call + 8` and passes the frame's return check.

| PC | What it does (from the disassembly) |
|---|---|
| `8005FBA8` | RC2 wait start: latch Timer2 count to `80078F24`, wait length a0 to `800C5320` |
| `8005FBC8` | RC2 wait check: elapsed Timer2 ticks (wrap by target or 0x10000, `>> 3` unless mode bit 0x200) >= wait |
| `8005E0AC` | I_STAT = ~0x80, wait for /ACK release (STAT bit 7) under the RC2 wait, CTRL \|= 0x10 |
| `8005DCA0` | one pipelined SIO byte: select byte (a1 < 0) after the select delay, else RX, baud, ACK latch or RC2 timeout (-0x14), send, store the reply |
| `8005DE78` | the same with the inline Timer2 timeout (-2) and the step-2 0x3C delay |
| `8005E13C` | wait for RX ready |
| `8005F394` | next transmit byte from the record's actuator/config buffers |

New code, all native C, owner-written from the asm:
`pc_port/platform/psyq/bfm_psyq_libpad.c` (the leaves, which walk the retail
control flow and report every retail instruction they stand for) and the
adapter `input_pad_leaf` in `pc_port/mips_formatter.c`, which charges each
one as the frame's interpreter does (one budget unit, then 2 cycles, +1 for a
load/store, before the access, with the device-observation PC set to the
retail PC) and performs the access through the same memory/device path. The
handler, `8005DBD8`, the five step bodies, the TAP/config code and
`8005F830`/`8005FA94` stay interpreted. Divergences: KNOWN-DIVERGENCES D-042.

### G1 differential (`tests/input_pad_leaf_probe.c`, pytest `tests/test_input_pad_leaf.py`)

53,743 cases, 0 different (devbox, 1 m 57 s). Retail words vs native leaves
on two identical universes; compared after every step: all guest RAM and
scratchpad, the callback frame, every SIO field, Timer2, I_STAT/ACK state,
the per-byte tx/rx log with tx cycle and ACK due, button samples, clock
charges and cycles, results and stop PCs; per leaf also the register file and
budget. Frame-level scenarios: cold TAP (96 VBlanks), 1000 VBlanks of random
buttons and sticks, motor/config buffers, lost/late ACK past every timeout,
/ACK held low, Timer2 mode 0x200 and a nonzero target, mutated reply bytes,
all at once, SIO pointer corruption, frozen clock; every budget and every
clock-refusal point of whole handler calls (5,498 and 7,515 instructions).
Leaf level: 4,200 random states with budget/clock sweeps. Refusals leave CPU,
budget, clock, devices and RAM untouched. Deliberate breaks, each failing,
restored by the default build: RC2 shift (26,806 different), dropped I_STAT
ack (26,718), baud 0x89 (20,615), dropped CTRL bit 4 (9,445), one extra cycle
charge (20,237), select byte not sent (26,485).

### G2 local village 1010 warp (no-march lane build, `MUSASHI_GUEST_CLOCK=1`, unthrottled, `MUSASHI_TRACE_DEVICE_OBS=1`, `MUSASHI_TRACE_PAD=1`)

`MUSASHI_TRACE_PAD=1` prints, after every handler call, an FNV-1a 64 hash of
the driver's guest state (globals, records, receive and game buffers, RC2
latches, callback stack) and the SIO/Timer2/I_STAT model state, and the
poll-site counters at exit.

| Leg (~345 s each, 2 in parallel) | Warp vblanks | Final DEVOBS vblank / cycle / events / hash | Stop tick | PAD_TRACE lines |
|---|---|---|---|---|
| `pure+vsync`, `EPOCH_LAZY=1` | 416 | 2784 / 1571848430 / 2,412,193 / `8dcbfa55a61f3ddc` | `0ae0` | 2,668 |
| `pure+vsync+pad`, `EPOCH_LAZY=1` | 416 | identical (all 2,784 DEVOBS lines) | `0ae0` | 2,668, identical |

The DEVOBS stream matches S2's `pure+vsync` figures exactly: the leaves make
the same device accesses at the same PCs and cycles. `EPOCH_LAZY=0` legs did
not finish within the local 900 s cap (the eager epoch is slower under load);
over their common prefix they are identical, pad off vs on (1,777 DEVOBS and
1,748 PAD_TRACE lines) and lazy 0 vs 1. Completion of the lazy=0 legs is part
of the integrator's runner gate.

Poll sites per route (identical pad off and on; 2,667 completed handler
calls): `8005FBC8` call sites `8005DD1C` 56,481 (select delay, 21.2 per
VBlank), `8005DDF0` 119,890 (ACK wait, 45.0), `8005E030` 23,992 (step-2
delay, 9.0), `8005E0E0` 0 (the SIO model never holds /ACK low); their sum
200,363 is the whole `8005FBC8` count. Inline DE78 ACK loop `8005DF84`
305,653 (114.6 per VBlank, mostly port 2's 3,200-cycle timeout); RX waits
`8005DED8` 10,668 and `8005E148` 2,667 (one pass each: the model's RX is
ready at once); TX `8005DD08` and RX `8005DDB0` 0.

Traced pad-on leg (`MUSASHI_TRACE_FUNCS`, local): same warp, stop tick
`0ae0`; `8005FBC8` 200,363, `8005FBA8` 45,336, `8005E0AC` 26,666,
`8005DCA0` 18,666, `8005F394` 15,998, `8005DE78` 10,668, `8005E13C` 2,667,
all native and 0 interpreted (the tracer now counts an S3a leaf entry as
native only when the leaf ran). Interpreted calls, all regions: 1,035,157
(S2 runner trace `fdd04fc114`) -> 714,793; the difference, 320,364, is
exactly the seven leaves. `8005DBD8` (18,670) and the handler `8005D734`
(2,668) stay interpreted.

Tests (lane build, no-march): CTest 34/34; retail guard 7 files, 0 problems;
`tests/test_native_lane*.py`, `test_psyq_exclusion.py`, `test_input_*.py`:
all pass except `test_input_digital_irq.py`, which fails identically on the
base `c593163a01` (its round-1 expectation predates the DualShock SIO model:
see the commit message); `test_host_chord.py`, `test_bios_memcard.py`,
`test_input_controller_words.py`, `test_bios_input.py`,
`test_sio_controller.py` 5/5; `musashi_dev_menu_probe` DEV_MENU_PASS.

### S3a runner gate on the release binary (port `a4a988643c`)

Job `20261001-210505-bfm-owncode-a4a988643c` (evidence SHA256
`54d93009...c746`, matched by readback; executable `e046522c...cc82`, x86-64-v3;
retail guard 7/0; `entries=491 psyq=64`).

| Leg | Result |
|---|---|
| village `pure+vsync` vs `pure+vsync+pad`, `MUSASHI_EPOCH_LAZY=1` | identical: route enters at vblanks 1545/2207/2623, warp vblanks 416, stop tick `00000ae0`, 11,234 IRQ deliveries, display 70196/76800; `MUSASHI_TRACE_DEVICE_OBS_FILE` streams byte-identical (2,413,274 records); `PAD_TRACE` streams byte-identical (2,668 handler hashes) |
| the same with `MUSASHI_EPOCH_LAZY=0` | identical as above; also byte-identical to the lazy=1 streams within each configuration |
| village `pure+vsync+pad`, traced | the seven leaves all native, 0 interpreted (`8005fbc8` 200,363, `8005fba8` 45,336, `8005e0ac` 26,666, `8005dca0` 18,666, `8005f394` 15,998, `8005de78` 10,668, `8005e13c` 2,667); `8005dbd8` 18,670 interpreted as designed; village interpreted calls 714,793 (1,035,157 before S3a) |
| attract `pure+vsync+pad` | same end state as shipped r30 (`STEP_REFUSED pc=800495ec`, `NATIVE_LANE_ABORT pc=80011380 code=4`, same registers) |
| cold Continue from the r31 saved card, both configs | both enter `3001` at progress 10, vblank 2028, same flags; card SHA256 `bc137407...9506` unchanged. These legs stopped on a 240 s wall-clock timeout at different guest times, so their RAM was not comparable |

Matched-stop cold Continue, job `20261001-211756-bfm-owncode-a4a988643c-cold`
(evidence `97ef53e8...6477`): `MUSASHI_IN_GAME_FRAMES=600`, both configurations
stop at tick `00000a42` with 10,436 IRQ deliveries and display 58903/76800.
The 2 MiB guest RAM dumps are byte-identical, and the card is unchanged.

Following this gate the release default became `pure+vsync+pad`;
`MUSASHI_PSYQ_LANE=pure+vsync` or `pure` opts out.

S3a default flip verified: job `20261001-212109-bfm-owncode-a86577db04`
(evidence `5ad0758d...caf2ca1`, matched by readback; executable
`b28b3c05...4019e`). Unset `MUSASHI_PSYQ_LANE` logs
`classes=pure+vsync+pad`, and `pure+vsync` logs `classes=pure+vsync`. Both
reach the village with warp vblanks 416, stop tick `00000ae0` and display
70196/76800. `musashi_psyq_vsync_probe` on the runner: 236 cases, 0 different.

## Layout rewrite on the release binary

Pointer-typed struct members and array elements in 29 matched functions became
u32 guest addresses cast at each use (22 clean-room: bfm-rederive `cb44d24`,
port `c32016645c`; 7 owner-authored: port `258e0dcb2b`). All still
verify_registry MATCH with 0 retail data. 28 are now admitted. `8001C1E4` is
still rejected, now for `escape` (it passes a host stack array to
`func_80054514`). Own-code lane 427/497 -> 455/497.

| Job | Lane | Village plain/traced | Attract |
|---|---|---|---|
| `20261001-212907-bfm-owncode-c32016645c` (evidence `a4a902d2...4490`) | 449/497, `entries=513` | PASS (warp vblanks 416, `HOST_STOP source=IN_GAME_TARGET`, display 70196/76800) | as r30 |
| `20261001-213327-bfm-owncode-258e0dcb2b` (evidence `703c163f...a8fa`, exe `d8b4509b...1c53`) | 455/497, `entries=519` | PASS, same | same terminal refusal (`STEP_REFUSED pc=800495ec`, `EXECUTION_BOUNDARY reason=REFUSED`, tick `00003aca`, the same a0-a3). The `func_80011380` abort now unwinds through `func_80010B40` (its caller, return address `80010b94`), which is native since this change, so the log shows a second `NATIVE_LANE_ABORT pc=80010b40` |

The attract IRQ delivery count varies between runs of the same configuration
(49,609 / 49,614 / 49,621 across today's jobs), so it isn't a regression signal.

Village trace on the 455/497 lane: main executable 25.5% of calls native
(163 native vs 150 interpreted distinct functions; 24.1% and 148/167 before the
rewrite); overlays 0%; interpreted calls 712,841. The rewritten functions are
mostly cold on this route (sequencer/channel code), so the gain shows in
distinct-function coverage more than in calls.

## O1: overlay own-code lane plumbing (branch `claude/ovl-o1`)

Implements docs/OVERLAY-LANE-DESIGN.md section 3 A-F with slice O1, main_0003's
24 clean-room functions (`config/lane_own_code_allow_overlay.txt`). Devbox only,
not a runner job: this Xeon has no AVX2, so the release-flag tree
(`-O2 -march=x86-64-v3`, `build/o1-release`) is built for the generator report
and the retail guard, and the routes ran on an otherwise identical build
without `-march` (`build/o1-local`). Still hybrid; not a native-completion claim.

**Generator (release flags).** 480/524 admitted: 458 main (the same set as the
base `1f68a9cc18`, 458/500) and 22/24 overlay. `800D1D14` is refused by
`layout` (array of pointers) and `800D2A24` by `deny` (below). Each overlay row
in `report.json` carries its digest, covers (`main_0003`) and rule. Retail guard:
7 files, 0 problems. Executable SHA256 `7626a2d3...0763` (x86-64-v3, not run here).
Reading `bfm_plat_hook_sites.c` (B6) rejects no main function. It moves one
direct native call to the thunk: `80011B7C` (ROOM_EXIT hook site), which the
native `80011380`, `80010BB4` and `80011220` had called directly, so that event
never fired from native callers. The thunk did not arm entry hooks at all before;
it now does, as a jal does.

**Two defects found by the local route and fixed on the branch.**
1. B6 at first also blocked the PsyQ HLE entries SetGeomScreen/SetGeomOffset
   (`8004923C`/`8004921C`, whose own entry PCs are PROJECTION hook sites). Their
   retail words then ran under a native caller (thunk, `ra=ffffffff`) and failed the
   COP2 caller whitelist (`STEP_REFUSED pc=80049224`): the village route stopped
   after the warp request with `NATIVE_LANE_ABORT 8001125C/80010B40 code=4`, with
   and without overlay entries. An entry-kind site at the entry PC itself no longer
   blocks (`psyq_hooked` is the base list again, 52 entries).
2. With the overlay entries on, the intro FMV stopped after 4 MDEC transfers
   instead of 1852, and the warp request came at vblank 1845 instead of 2207 (the
   deny-all-overlay leg and the runner baseline). DENY bisection (exact once the
   overlay guard also honours DENY): `800D2454`, `800D2394`, `800D2AA0` and
   `800D2A24` each native alone match the baseline, and `800D2454` native calling
   `800D2A24` natively reproduces the cut. All four match their retail instructions
   (objdump of the user's member file). `800D2A24` retries CdControl(Setloc) and
   then the streaming read start (`8004657C`: CdControl `0x0E`, then `0x1B`), so its
   result depends on the guest time between its guest calls, and natively none
   passes. It is held out (`OVERLAY_DENY`); KNOWN-DIVERGENCES D-013 (6).

**Unit and probe tests.** `tests/test_native_lane_overlay_gen.py` 13/13: allow-file
parsing (malformed, duplicate, unaligned), the tracked list equals the registry's 24
clean-room rows, SHA-1 mismatch, missing sha1/config/file, untagged and
third-party origins, missing registry row, size and overlap, dedup with covers
(clean-room preferred), the jump-table rule, the hook sites and PsyQ list, and an
end-to-end release run (`800D2A24` deny; the `80011B7C` call is a thunk).
CTest `native_lane_overlay_runtime` (`tests/native_lane_overlay_runtime_probe.c`,
PASS): DENY keeps 1 of 2 overlay entries and the denied body does not run; RANGE
keeps 1 and the guard refuses the filtered function from a native caller although
its bytes match; entry verified/refused, guard verified/refused and recheck counters
move separately; a caller whose own bytes change under its guest call aborts
(`NATIVE_LANE_OVERLAY_RECHECK_FAILED`, code 7), and so does a directly called
overlay frame. With the bytes restored, both run again. The thunk fires the entry
hook. The trace counts the entry 5 native and 1 interp, as the counters do.

**Differential (`musashi_native_lane_overlay_probe`, main_0003 payload).** 22
entries: 10 cases same, 0 different, 0 not native, 56 not comparable, 22/22
negative cases (one flipped byte) refused, 0 bad. Only four functions have a
comparable positive case (`800CF078`, `800CF104`, `800D2394`, `800D2AA0`): the
interpreter oracle admits main_0003 words only inside `kFormatterRanges4`, which
covers 9 of the 22 entries, and the synthetic arguments miss the others' paths.
The other 13 cannot run interpreted at all (a call to them would refuse the step),
so the differential cannot reach them. That is a coverage limit, not a pass.
Foreign payloads (`OVERLAY_PROBE_FOREIGN=1`, main_0001/0008/0010 loaded in
main_0003's window): 88/88 cases each refused, 0 ran native.

**CTest and pytest.** Lane build 35/35 (34 at base, plus the new runtime probe),
default build 34/34 (same); `tests/test_bfm_plat.py`, `test_native_lane*.py`,
`test_port_matched_ratio.py` and `test_psyq_exclusion.py`: 71 passed, 1 skipped (Lua
not fetched).

**Local village 1010 warp** (no-march lane build, guest clock, unthrottled, the
runner job's environment and input script; three legs in parallel):

| Leg | Overlay | Warp request / arrival | Stop | Display | IRQ deliveries | MDEC transfers |
|---|---|---|---|---|---|---|
| plain | `entries=22 of 22`; `entry_verified=215 entry_refused=584 guard_verified=1 guard_refused=0 recheck_ok=348 recheck_failed=0` | vblank 2207 / 416 | `IN_GAME_TARGET`, tick `0ae0` | 70196/76800 | 11,235 | 1852 |
| traced (`MUSASHI_TRACE_FUNCS`, `MUSASHI_TRACE_RESIDENT`) | identical counters | same | same | same | 11,235 | 1852 |
| DENY all 24 | `entries=0 of 22`, all counters 0 | vblank 2207 / 416 | same | same | 11,238 | 1852 |

`NATIVE_LANE entries=522 psyq=64`; no `NATIVE_LANE_ABORT`, `HOST_FAULT` or recheck
failure. Lane-on vs deny-all differ in IRQ deliveries (3) and the final guest cycle
count (1), which is the cycle charge (D-011). DEVOBS streams were not compared
locally.

Trace: 215 overlay calls native, exactly `entry_verified`. The allow-listed functions
ran 215 native and 4 interp calls (`800D2A24` 2, held out; `800CF104` and
`800CF370` 1 each, refused at the boundary). Overlay space overall: 150,867
interpreted calls, so overlays are still 0.1% native on this route. O1 proves the
plumbing, not speed. All regions: 5,072,190 native and 618,360 interpreted calls.
`trace.resident` has 851 (target, digest) rows, 0 dropped.

Not done here: the runner gates on the x86-64-v3 binary (village plain/traced/
DENY-all, attract, DEVOBS parity), which the integrator submits. The attract route
was not run locally.
