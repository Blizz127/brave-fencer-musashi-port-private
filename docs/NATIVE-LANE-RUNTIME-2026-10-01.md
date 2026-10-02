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

### O1 on the release binary (port `a361ecccd0`)

Job `20261001-230856-bfm-owncode-a361ecccd0` (evidence SHA256 `39120b51...05ee`,
matched by readback; executable `a2d453f5...8a41`, x86-64-v3; retail guard 7/0).
Generator: 480/524 admitted = the same 458 main + 22/24 `main_0003` overlay
entries (`800d1d14` layout, `800d2a24` deny).

| Leg | Result |
|---|---|
| village, plain and traced | warp vblanks 416, `HOST_STOP source=IN_GAME_TARGET`, display 70196/76800, intro FMV `MDEC transfers=1852`; `NATIVE_LANE overlay verified=216 refused=584 entry_verified=215 guard_verified=1 recheck_ok=348 recheck_failed=0` |
| village, all 24 overlay PCs denied | the same outcome, with all overlay counters 0 (DENY applies to the overlay table) |
| attract | same terminal refusal (`STEP_REFUSED pc=800495ec`); overlay `entry_verified=2436 guard_verified=4 recheck_ok=4536 recheck_failed=0`; MDEC transfers 7408 |

This is the first release build that executes native overlay code. O1 is the
plumbing slice, so the village gain is small (main_0003 is barely resident there);
O2 targets the hot scene code.

### B14 targeted native differential (port `aa251b2123`)

`tests/native_lane_targeted_probe.c` (CTest `native_lane_targeted_differential`)
runs each of the three B14 functions through the interpreter (lane off) and the
native lane from identical seeded RAM and compares the full 2 MiB of guest RAM.
The functions are void, so there's no v0 to compare.

- `80020DA4`: 3,375 boundary angle combinations (0, 1, 2, 0x7FF, 0x800, 0xFFF,
  0x1000, values above 0xFFF to prove masking, 0xFFFF) plus random cases; output
  buffers at several addresses including overlapping the input; the retail
  sin/cos table and a test-built one.
- `8001D388` / `8001FB8C`: every guard branch (state <0/0/>0, enabled 0/non-zero,
  type ==/!= the target, subtype 0 / last valid / first invalid / large; for FB8C
  `*count` 0 and 0x7FFFFFFF, and aliasing the object's state word). The call path
  runs real retail handlers through the retail table or rotated table entries. The
  interpreter admits only whitelisted retail code, so hand-made guest stubs can't
  run on the reference side; the interpreter's entry hook confirms the handler
  call and that no call happens when the guard fails.

| Function | Cases | Same | Different | Not comparable |
|---|---|---|---|---|
| `8001D388` | 3,000 | 2,685 | 0 | 315 |
| `8001FB8C` | 3,000 | 2,626 | 0 | 374 |
| `80020DA4` | 4,500 | 4,500 | 0 | 0 |

"Not comparable" means the called retail handler made a call the interpreter
doesn't admit, so both sides refused. Deliberate breaks (temporary source edits,
reverted) were all detected:
- `subtype < 12` in D388: different=1, native_failed=29;
- a dropped `*count += 1` in FB8C: different=207, i.e. every call-path case;
- a sign error in `m[6]` in DA4: 3,012 of 4,500 different.

Release x86-64-v3 confirmation: job `20261002-010328-bfm-b14diff-aa251b2123`
(evidence `3363c01a...a672`). Identical counts, 0 different. The lane-wide probe
gives 440 functions verified, 0 different.

## D-011 phase 2a: retail cycle model and mapping, report only (branch `claude/d011-cycles`)

Goal of D-011: a native-lane call should charge the guest time the interpreted
retail words would, on the path actually run. Today it charges a fixed
`2 * words` at return. Phase 2a builds the cost model and the mapping and
**only reports**. Admission, the generated table (byte-identical to the base
build) and every runtime charge are unchanged.

- **G1** (`tools/lane_cycles.py`): decodes each function's retail words (from
  the user's own extract) into segments. A segment is a straight run, followed
  through unconditional jumps, that ends at a conditional branch, a call, the
  return or a trap. Its cost uses the interpreter's own rule (`formatter_step`:
  2 per instruction, +1 load/store, LWL/LWR 3, SWL/SWR 4, delay slots counted).
  gcc's divide checks (`bnez rt; break 7`, the `-1`/`0x80000000` overflow
  check) and the signed divide-by-power-of-two bias (`bgez x; addiu x,2^k-1`)
  are folded into their segment. Their data-dependent extra cost (+4 for a
  divisor of -1, +2 for a negative dividend) is recorded so that 2b can charge
  it at run time. Checks: VSync(mode < 0) is 64 cycles, the same as the S2 hand
  count. `800D2A24` costs 25 cycles to its first Setloc call and 21 per retry.
- **G2**: a product walk of the clang -O0 CFG (after symbol rewriting, before
  optimisation) against the retail CFG.
  - Calls (callee and order) and the return are anchors.
  - A clang branch pairs with the next retail branch, with the polarity taken
    from the two predicates (equality / signed / unsigned family, direction,
    strict constant). The definer is followed through single-predecessor
    blocks and the predecessor's delay slot.
  - A clang branch with no retail counterpart is transparent (gcc's
    branch-free set-on-compare idioms).
  - A loop header entered from outside may be folded: gcc dropped the first
    test, so the exit arm is dead on that first evaluation.
  - Undecidable pairings are searched with backtracking. All complete,
    consistent product graphs are enumerated and ranked by how much they lean
    on pairings the predicates do not support; the best-ranked ones must
    charge identical costs, else the function is refused as ambiguous.
  - Consistency means: every reachable retail branch and call is covered, and
    no product cycle is free of retail cost.

  This is a heuristic, not translation validation. The oracle (interpreter
  clock vs native ledger, at each thunk and at return) is the first item of
  phase 2b.

**Release own-code set** (`--own-code-only`, 480 admitted = 458 main + 22
`main_0003`):

| Retail shape | Mapped | Refused |
|---|---|---|
| straight-line | 122 | 0 |
| straight-line with calls | 133 | 0 |
| acyclic (37 without calls, 95 with) | 118 | 14 |
| loops (45 without calls, 40 with) | 66 | 19 |
| retail CFG refused (guest jump table `jr $2`) | 0 | 8 |
| **total** | **439** | **41** |

Refusal reasons (the admitted functions that a phase-2b rule `cycles` would
hold out):
- 21 `switch` (3 of them in `main_0003`: `800CF104`, `800D0268`, `800D0740`);
- 8 jump tables;
- 7 retail-only loops: gcc's inline struct-copy loops against clang's
  `memcpy`, `80029274` and kin;
- 2 ambiguous;
- 3 other (`80018F20`, `8002C3B0`, `80038FC4`).

Caveats on the mapped set:
- Of the 439, 20 rely on at least one pairing that the search decided rather
  than the predicates (`structural` > 0 in `report.json`).
- 268 have a clang block reached at more than one retail pc, which 2b
  node-splits.
- 8 carry a data-dependent division adjustment (6 `div_m1`, 2 `sdiv_pow2`).
- 251 of the 255 straight-line functions have an exact path cost different
  from today's `2 * words` charge. Example: `80020DA4` is 222, today 200.

**Gate functions.**

| Function | Status | Notes |
|---|---|---|
| `800D2A24` | mapped | Still `deny`; analysed anyway; 25/21 |
| `800D2454` | mapped | Calls cost 24, 4, 9, 15, 4; return 18; total 74 (today 62) |
| `8001D388` | mapped | 23 / 32 / 41 / 52 per failed guard; 56 + 9 through the jalr (today 58 on every path) |
| `8001FB8C` | mapped | |
| `80020DA4` | mapped | 222 |

**Hot route functions.** Top 20 generated-lane entries by native calls on the
O1 village traced leg; direct native-to-native calls are not counted. 18 are
mapped. `80031BE0` (2,750 calls, switch) and `8001AF34` (1,456, jump table) are
refused.

Tests: `tests/test_lane_cycles.py`, 13 cases.
- The cost rule.
- Call and return costs of a straight-line function.
- A folded bottom-tested loop is charged exactly (4 iterations: 52).
- Refusals: call order, retail-only branch, ambiguous polarity, switch and
  jump table.
- Predicate-decided polarity.
- The division folds.
- VSync = 64 and `800D2A24` 25/21, retail walk and product graph (extract
  needed).
- A generator run whose report carries the gate statuses with admission
  unchanged.

## D-011 phases 2b/2c: ledger, deadline guard, `800D2A24` native (branch `claude/d011-cycles`)

**What runs.** Each admitted function whose mapping succeeded (440 of 481: 420
main + 20 `main_0003`; the host intrinsics among them charge 0) is built from
an instrumented -O0 module:
- A per-function product state (select chains that -O2 folds wherever the state
  is static) adds the mapped retail cost of each segment to `musashi_lane_ledger`
  at every event, plus the division idioms' data-dependent extras.
- Every rule of the generator still runs on the uninstrumented module. The
  instrumented one must keep the same definitions and guest calls.
- `musashi_native_guest_call` flushes the ledger before the callee runs.
  `lane_try` flushes it at return and charges the fixed 2 × words only for
  unmapped bodies.
- Deadline guard: the clock's deadline query (`musashi_execution_clock_set_deadline`; native_boot `lane_deadline`:
  the lazy epoch's device deadline, available with the lazy epoch off too, or 0
  when an IRQ is deliverable) sets `musashi_lane_budget`. A charge that reaches
  it calls `musashi_native_lane_tick` with the function's segment table. The tick
  charges the clock up to the retail instruction where the deadline falls and runs
  the interpreter's checkpoint there: retail pc, delay-slot state, the same CPU
  identity, at most once per instruction.
- An IRQ left deliverable by a guest call's return is delivered at the call's
  retail resume pc (`musashi_lane_resume_pc`).
- Guest calls from native code run the callee at the retail stack pointer
  (`musashi_lane_sp_adj`, the native frames' retail sizes).

**Two findings on the way.**
1. **Host intrinsics charge 0 in the interpreter.** The interpreter answers the
   6 host-intrinsic PCs with host code that charges no guest time, so the lane-off
   baseline is 0 there, and their native bodies now charge 0.
2. **The `800D2A24` FMV cut was not a timing bug.** `800D2454`'s clean-room C was
   typed `void`, but its caller (800D1F68) branches on v0 after the jal, and the
   retail words leave `800D2A24`'s result there. Interpreted, `800D2A24` left that
   result in v0 through the thunk; natively, v0 held 8004657C's.
   - What ruled out timing: with the guard in strict mode (a checkpoint before
     every retail instruction) the FMV was still cut, and with the retail stack
     pointer fixed it still was.
   - Fix: `800D2454` now returns `func_800D2A24`'s result. The old and new C both
     match retail byte-exact (31/31 words, `build_candidate.py`).
   - New generator rule `abi`: a void-typed function whose retail caller reads
     v0/v1 after the jal, before writing it (`void_result_readers`: main EXE and
     configured overlay members; jalr callers not covered), is refused. It hits
     nothing in the current set. With the old C it hits 800D2454 (caller 800D1F68).

**Oracle (no-march local build).**

| Probe | Result |
|---|---|
| lane-wide RAM (unchanged) | 440 verified, 0 different |
| lane-wide cycles (interpreter clock vs ledger at every non-lane entry and at return; 5 argument patterns, 2 of them negative for the division paths) | 359 same, 0 different, 61 not comparable |
| ... `structural` mappings / division adjustments / node-split | 16 same, 4 not comparable / 7, 1 / 198, 55 |
| mutation: division extras zeroed | 6 functions different (80010A08, 80015AD0, 80029CD4 and three callers), so the paths are exercised |
| targeted B14 cycles | 8001D388 2685/0, 8001FB8C 2626/0, 80020DA4 4500/0 (same/different) |
| overlay `main_0003` cycles | 3 same, 0 different, 16 not comparable (interpreter admission covers 9 of 22) |
| guard (32 deadline schedules, an IRQ handler cost inside each checkpoint) | 356 same, 0 different, 64 not comparable; 117,922 mid-native checkpoints |
| lane-wide cycles with `MUSASHI_LANE_GUARD_STRICT=1` | 359 same, 0 different |

**Local village 1010 warp.** No-march RelWithDebInfo lane build, guest clock,
unthrottled, the O1 smoke's environment and input script; 12-thread devbox,
4 legs in parallel.

| Leg | MDEC transfers | Warp request / arrival | Stop tick | Display | Wall |
|---|---|---|---|---|---|
| `800D2A24` native | 1852 | vblank 2207 / 416 | `0ae0` | 70196/76800 | 348 s |
| `MUSASHI_NATIVE_LANE_DENY=800d2a24` | 1852 | 2207 / 416 | `0ae0` | 70196/76800 | 358 s |
| native + `MUSASHI_EPOCH_LAZY_CHECK=1` | 1852 | 2207 | `0ae0` | 70196/76800 | 444 s, no `LAZY_CHECK_FAILED` |
| native + `MUSASHI_EPOCH_LAZY=0` | 1852 | 2207 / 416 | `0ae0` | 70196/76800 | 1,264 s; IRQ deliveries 11,235; guard and ledger counters identical to the lazy legs |

The native leg logged: IRQ deliveries 11,235 (the O1 baseline's lane-on count),
`ledger lost=0`, guard ticks 12,277, mid-native checkpoints 11,185, deadline
unknown in 154,815 of 4,756,786 refreshes. Every unknown case is the CD drive/DMA state not being at the epoch's cycle
(the CD path owns that time; the lazy epoch counts the same states as unsettled).
Checkpointing every instruction there would be the test-only strict mode, so
those stretches run without mid-body checkpoints (D-011 residual 5).

Not run here: the runner gates (village/attract, B14 native vs DENY identity at
lazy 0/1, O1 overlay vs deny-all identity) on the x86-64-v3 release binary.

### D-011 runner gates on the release binary (port `d2ab318b7f`)

Job `20261002-052918-bfm-d011-d2ab318b7f` (evidence `36e97e67...c9e`, matched by
readback; executable `7cb2f8ec...c1a6`, x86-64-v3; retail guard 7/0; 481/524
admitted, the ledger on 440, overlay 23/24 with `800D2A24` native):

| Gate | Result |
|---|---|
| Intro FMV, `800D2A24` native | `MDEC transfers=1852` (identical with `DENY=800d2a24`); stop tick `0ae0`; display 70196/76800 |
| B14 native vs `DENY=8001d388,8001fb8c,80020da4`, `EPOCH_LAZY=1` | DEVOBS byte-identical, PAD_TRACE identical, full 2 MiB RAM at the stop identical |
| the same at `EPOCH_LAZY=0` | DEVOBS, PAD_TRACE and RAM identical |
| native lazy=1 vs lazy=0 | DEVOBS identical |
| overlay lane vs all 24 overlay PCs denied | differs (DEVOBS line 906,505) -> attributed below |
| attract | same terminal refusal (`STEP_REFUSED pc=800495ec`), MDEC 7408, overlay `recheck_failed=0`, ledger `lost=0` |

Before D-011 the same B14 comparison diverged at DEVOBS record 1,371,000, so
these gates show the ledger makes guest time 1:1 with the interpreter for the
mapped functions.

Attribution, job `20261002-054235-bfm-d011attr-d2ab318b7f` (evidence
`4a74e84c...bcf5`): denying only `800cf104` (main_0003, a `switch`, one of the
41 fixed-charge functions, run natively 57 times on the route) leaves 158 native
overlay calls, and the run is byte-identical to the all-overlay-denied run
(DEVOBS, PAD_TRACE, RAM). So every other overlay entry is timing-exact; the
overlay divergence is entirely the disclosed fixed-charge residual, and it
changes no gameplay result (FMV, village, attract).

## O2: main_0012 clean-room scene functions (port `bf958679df`..`ea46c584a2`)

68 clean-room main_0012 functions (rederive B15-B17, merge-back `bf958679df`,
allow list `b6aac50405`). The first runner gate (`b6aac50405`, 55 admitted)
found two problems:

- **void-ABI bugs** (the `800D2454` class): main `80013294`, `80013328`,
  `80013450` return `func_80047D3C`'s s32 result, `80015954`/`80015978` return
  `u16 arg0[2]`/`arg0[5]`; main_0012 scene code reads v0 after those jals.
  They were native in the shipped private r30 with v0 stale. Fixed in
  `183341fa55` (byte-exact either way). `1a8f25dcaa` holds the handler tables
  of `80162b1c`/`80165ca0`/`8017849c` as u32 guest words (layout rule).
  `f7442de48d` stops the abi rule counting an `lwl`/`lwr` pair as a v0 read.
  The 10 sources match in decomp (`b7d4d990e0`) and rederive (`a584b42`):
  verify_registry MATCH 10/10, check_no_retail_data 0.
- **`801463A0` "native body ran on modified bytes"**: a probe bug, not a
  guard bug. Any host fault in a negative case was reported as the native
  body running. With the byte flipped, `801463A0` ran interpreted; its
  unflipped native callee `80155150` read through `obj->model == 0` in the
  synthetic state (host address `0x24`, the KUSEG gap of D-013 (4)).
  `ea46c584a2` classifies faults as the main probe does (`mirror_fault`,
  `wrap_fault`, anything else fails the function) and judges a negative case
  by whether the entry under test ran.

Release lane at `ea46c584a2`: main 540/592, overlay 82/92 (main_0003 23/24,
main_0012 59/68; refused: `8012f14c` hooks, `801379fc` irq, `8014a59c` ub,
`801508f8` compile, `80147514`/`8014bde8`/`80154418`/`80154be4`/`80165e90`
escape, i.e. a host stack address passed to a thunked callee).

### O2 runner gate (job `20261002-061724-bfm-o2-ea46c584a2`)

Evidence `1dd6b7ea...c091` (matched by readback); package `e09e5c7e...5e8e`.

| Gate | Result |
|---|---|
| overlay probe main_0012 | 59 entries, same 102, different 0, negative_ok 59/59, mirror_fault 51, fault 0, functions_bad 0; cycles 40 functions same, 0 different |
| overlay probe main_0003 | 23 entries, same 10, different 0, negative_ok 23/23, mirror_fault 6, fault 0, functions_bad 0 |
| lane-wide probe | 440 verified, 0 bad; cycles 359 same, 0 different |
| targeted (B14) | 8001FB8C 2626 same, 80020DA4 4500 same, 0 different |
| village 1010 | warp at vblank 416, MDEC 1852, tick `0ae0`, display 70196/76800; overlay verified 68,147 (was 67,351), recheck_failed 0 |
| village traced | identical to the village leg |
| village, all 92 overlay PCs denied | identical outcome (MDEC 1852, tick `0ae0`, display) |
| attract, 480 s | timed out (SIGTERM) at tick `2765`, MDEC 5556, on a runner shared with 3 other jobs (the `b6aac50405` gate reached its terminal refusal at tick `3aca`, MDEC 7408). The `pc=8004255c` refusals are the SIGTERM teardown; re-run with 1500 s pending |
| attract, 1500 s (job `20261002-063321-bfm-o2attr-ea46c584a2`, evidence `ea63e7f0...bb21`) | terminal `STEP_REFUSED pc=800495ec`, tick `3aca`, MDEC 7408, display 70400/76800, the same as the `b6aac50405` gate; overlay verified 2,194,531, recheck_failed 0, ledger lost 0 |
| attract, all 92 overlay PCs denied, 1500 s | the same terminal state (tick `3aca`, MDEC 7408, display 70400/76800) |

### Entry-PC prefilter (port `b57ba35c2d`) and private build r31

The first r31 candidate ran about 17% slower than r30 (blizzpc, throttled,
interleaved: steady 67-69% against 82-84%). With `MUSASHI_NATIVE_LANE=0` it
ran as fast as r30; denying the overlay entries, `MUSASHI_PSYQ_LANE=pure` and
`MUSASHI_MEMCARD=0` did not help. A SIGPROF sample profile showed `lane_find`
6.2%, `lane_try` 2.3% and `lane_ovl_first` 1.2% of CPU: `lane_try` runs
before every interpreted instruction, and since O2 the overlay table spans
`800CF078`-`801787D4`, so nearly every overlay instruction paid two binary
searches. A 64 KiB bitmap of entry PCs answers misses in O(1); the probes are
unchanged. r31 (`bfm-r31-3eddf31ad`, private channel) then measured 82-84%
steady beside r30's 82-83% in the same job
(`20261002-075659-bfm-r31-gate-3eddf31ad`), which also passed smoke (v3 and
baseline), card-off, attract, inn save and cold Continue through `launch.sh`.

## Guest-frame locals: rule `escape` (branch `claude/escape-locals`)

Before this branch, 35 own-code functions (30 main, 5 `main_0012`) were
refused because they pass the address of a local to a callee. A native local
is a host stack slot, which an interpreted callee cannot see.

**Design.** Such a local now lives in guest RAM, at the address the retail
code uses. `place_guest_locals` (`tools/native_lane_gen.py`) runs on the -O0
IR before `narrow_pointer_cells`:

- An alloca is moved when its address reaches a `lane_call_*` argument
  through constant GEPs. Other allocas stay on the host.
- The offset comes from a forward dataflow over the retail words
  (`retail_call_args`). For each jal it gives the arguments proven to hold
  retail sp + k: a0-a3, callee-saved copies across calls, and stack argument
  words at sp+0x10.. stored from such a register.
- IR calls are paired with retail jals per callee, in order.
- It refuses (rule `escape`) on:
  - a different number of calls in the C and in the retail words;
  - an argument set that differs (a local in the C where retail has no sp
    address, or the reverse, including a retail jal the C does not make);
  - two offsets for one local;
  - a non-constant offset into a local;
  - a pointer-typed local;
  - a region that is misaligned, overlaps another local, overlaps a saved
    register slot (`sw s0-s7/fp/ra, off(sp)`), lies in the outgoing argument
    area, or extends past the frame;
  - control flow the dataflow cannot follow (`jr` to a register other than
    ra, `jalr`, branch-and-link, a transfer in a delay slot).
- The rewrite turns `%x = alloca T` into `inttoptr(entry_sp - sp_adj + off)`.
  - `musashi_lane_entry_sp` is new: the guest sp at the lane entry, set,
    saved and restored by `lane_try`.
  - `sp_adj` is the D-011 `musashi_lane_sp_adj`, after the body's own
    adjustment. That gives the same retail sp the guest-call thunk gives a
    callee. A nested native body gets its own retail sp the same way.
  - The host's `-ftrivial-auto-var-init=zero` memset of a moved local is
    dropped: retail leaves the slot as it was.
  - Pointer stores into a moved local become 32-bit guest stores
    (`narrow_pointer_cells` sees guest memory).
- The table gains `musashi_native_lane_guest_locals[]`
  (pc, frame, off, size, member). The main and overlay probes compare those
  bytes, even though they sit inside the frame band the probes otherwise skip.
- IRQ handlers run on their own stacks (BIOS callback stack, the CD ISR
  context stack), not at the game's sp, so a mid-native checkpoint does not
  reach a live guest-frame local.

**Found by the new GTE-backed targeted cases: caller-pinned GTE callees.**
Several GTE sites are admitted only for an audited jal return address
(`gte_49324_caller`: `ra == 0x80013274u ...`; `jal_caller_of(ra,
kGteEntry...)`). A native caller reaches the callee through the thunk with
the sentinel ra (`UINT_MAX`), so the callee refuses at its first COP2 site
and the lane call aborts. `hooked_pcs` missed `ra == 0x...` lines, so this
was also a latent bug in already-admitted code:
- `8002C410` calls Square0 (a STUB in the PsyQ table, so always interpreted).
- `80014148` calls ApplyMatrixLV and `8001F97C` calls `80020F34`. These are
  interpreted whenever the PsyQ lane is off or a wrapper refuses.

Two fixes, both in rule `hooks`:
- `hooked_pcs` now also reads `ra ==`/`ra !=` lines.
- A new check refuses any body whose stub calls a `jal_caller_of` entry
  (none today after the first fix).

**Admission (own-code set: `--own-code-only`, the main allow list and the
92-pair overlay allow list).** Base `682f8ed437`: 540/592. This branch:
561/592.
- 24 of the 35 escape functions are admitted:
  - main: 8001282C, 800128B4, 80012E0C, 80014774, 8001C1E4, 8001C214,
    8001C2C4, 8001C448, 8001C4A4, 8001C558, 8001C6E4, 8001C744, 8001C7B0,
    8001C810, 8001C8C4, 8001CA1C, 8001CA88, 80028620, 8002E5BC;
  - `main_0012`: 80147514, 8014BDE8, 80154418, 80154BE4, 80165E90.
  - All are ledger-mapped (exact D-011 charge).
- The other 11 stay refused:
  - `hooks` (caller pin): 80013228, 800132BC, 80013350, 800133E4 (Square0),
    800141AC (ApplyMatrixLV), 80017DF8, 80017E30 (80048EAC).
  - `abi`: 80016B60 (its locals are placed, but it calls func_8004958C,
    unprototyped, with 8 arguments).
  - `deny`:
    - 800128EC: the retail cycle mapping is ambiguous, so it would keep the
      fixed charge.
    - 80014168: no oracle; the interpreter refuses its own unaligned copy.
    - 80016D78: no oracle; its allocator callee returns NULL on probe state.
- Newly refused by the `hooks` fix: 80014148, 8001F97C, 8002C410
  (previously admitted).
- The four 0-argument wrappers 80013200, 80013294, 80013328 and 800133BC
  stay admitted. They would fail the arity rule only if their callees
  became native.

**Probes (no-march lane build, own-code).**

| Gate | Result |
|---|---|
| lane-wide probe | entries 536, same 1138, different 0, native_failed 0, functions_verified 453, functions_bad 0; cycles 372 functions same, 0 different |
| targeted, B14 families | 8001D388 2685, 8001FB8C 2626, 80020DA4 4500 same; 0 different; cycles 0 different |
| targeted, escape family | 400 seeded cases per function, GTE owner behind a CPU transfer device. The interpreter leg runs in a forked grandchild, so both legs start from the same GTE bank. Full comparisons (v0, RAM incl. guest locals, GTE banks, cycles): 400 same for each of 8001282C, 800128B4, 80012E0C, 8001C1E4, 8001C214, 8001C2C4, 8001C448, 8001C4A4, 8001C558, 8001C6E4, 8001C744, 8001C7B0, 8001C810, 8001C8C4, 8001CA1C, 8001CA88, 80028620; cycles 400 same each. 80014774 and 8002E5BC: 0 full cases, because their callee does GPU/CD I/O, which the device-less oracle refuses. Their first callee entry matched in 400 of 400 cases (sp, frame-pointing arguments and stack words, and the local's bytes). |
| overlay main_0012 | 64 entries, same 387, different 0, negative_ok 64/64, functions_bad 0; cycles 0 different. Guest-local entries run 64 extra seeded patterns: 80147514 66 same, 8014BDE8 34, 80154418 67, 80154BE4 51, 80165E90 67 |
| overlay main_0003 | 23 entries, same 10, different 0, negative_ok 23/23, functions_bad 0 |

**Limits.**
- The offset proof is a dataflow over the retail words plus an in-order
  pairing of calls per callee. It is not translation validation. The probes
  are the evidence for the cases they reach.
- 80014774 and 8002E5BC are compared only at their callee's entry.
- The guest frame's other slots (saved registers, host-only locals) are
  still not written, as in D-011 (4).
- No gameplay or runner result is claimed here.
