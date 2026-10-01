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
| S1 | `80046c38` StGetNext (2,297,066; 66.3%) | libcd2 stream ring: next sector or not-ready | game, `800d27c4` (main_0003 poll loop) | SDK HLE over the CD streaming device; compat row is `BFM_PSYQ_STUB` today |
| S2 | `8004239c` VSync (89,573), internals `800426d4` (56,946), `800426fc` (34,234): 5.2% | libetc frame wait and callback dispatch | SDK-internal (`80044150`, `80044258`, `8005b81c`) | VSync HLE exists (`BFM_PSYQ_HLE`) but installs only with `MUSASHI_PSYQ_LANE=all`; promote the class behind its own gate |
| S3 | libpad `8005fbc8` (200,361), `8005fba8` (45,336), `8005e0ac` (26,666), `8005dbd8` (18,670), `8005dca0` (18,666), `8005f394` (15,998), `8005de78` (10,668): 9.7% | pad SIO exchange and handshake waits | SDK-internal only (pad interrupt/VSync callback chain) | HLE the pad driver's interrupt handler and the pad entry points on `bfm_plat_input` and the existing SIO wire shim; device/IRQ seam, highest timing risk |
| S4 | libgte24 `80049440` (22,346; 0.6%) | GTE helper | game, `80012928` | HLE through the existing GTE bridge; compat row is a stub |
| S5 | libgpu2 `8005ba90` (13,207), `8005c020` (11,145): 0.7% | packet/OT internals | SDK-internal | HLE at the libgpu entry points; partly bypassed already on `MUSASHI_GPU=bfm_plat` |
| game | main `8001d388` (50,944), `8001fb8c` (38,208), `80020da4` (12,653): 2.9% | game code | game | clean-room re-derivation, then allow list |
| game | overlay `8012a988` (19,104), `80134a28` (11,364), `8017869c` (8,652): 1.1% | overlay game code | game | clean-room re-derivation plus the digest-checked overlay own-code lane (0 overlay entries today) |

If S1-S3 were native on this route, about 81% of today's interpreted calls
would stop interpreting. Entry counts aren't cycles, and the overall share
would still be bounded by boot and overlays running in the interpreter.
Suggested order: S1, then S4 (small, game-called), S2, then S3.
