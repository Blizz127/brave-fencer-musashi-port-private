# Strict native build (`MUSASHI_STRICT_NATIVE`)

The owner's endpoint is a useful playable slice executed with the CPU
interpreter disabled or absent, zero fallback, with semantic/visual/audio/
timing/save evidence. This build option is the enforcement half of that
standard: it turns "some retail word was interpreted" from something a trace
has to be read for into a process abort with the seam named.

```sh
cmake -S . -B build/strict -DMUSASHI_NATIVE_LANE=ON -DMUSASHI_LANE_OWN_CODE_ONLY=ON \
      -DMUSASHI_WITH_PSYCROSS=ON -DMUSASHI_LANE_OVERLAY_MEMBERS=main_0003,main_0012 \
      -DMUSASHI_STRICT_NATIVE=ON
```

The option is scoped to the two translation units that hold the seams
(`pc_port/mips_formatter.c`, `pc_port/platform/psyq/bfm_psyq_compat.c`), so
toggling it in an existing build directory recompiles only those and relinks.
`pc_port/mips_formatter_strict.c` (the reporter) is compiled into every build;
nothing calls it unless the option is on.

## What a strict binary does

Every production entry into the interpreter calls
`musashi_strict_abort(seam, routine, guest_pc)` before its first
`formatter_step`. It prints

```
native_boot: STRICT_INTERPRETER_ENTRY seam=<seam> routine=<routine> guest_pc=<pc>
native_boot: host call chain:
<backtrace>
```

and `abort()`s. The interpreter still compiles and links as dead code: moving
its support symbols (`musashi_native_lane_*`, the tracer, the overlay hooks,
`musashi_boot_cpu_context`, the overlay word selectors) out of
`mips_formatter.c` is the follow-up that lets a strict build drop the
interpreter TU from the link, at which point a lane miss becomes a link error.

## Seam catalog

| Seam id | Entry | Reached in the hybrid build from |
|---|---|---|
| `boot_entry` | `musashi_boot_run_entry_with_devices` | `main()`'s boot call at pc 80010000: the whole startup/game loop | In a strict `musashi_native_boot` with the lane, `main()` calls the frame driver instead (B23), so this seam now fires only in probes and lane-less strict builds. |
| `frame_driver` | `musashi_frame_driver_run` (`pc_port/native_frame_driver.c`) | strict only: a callee of main that the lane table cannot run (`routine=not_in_lane func_XXXXXXXX [psyq=...]`), a lane abort, or a refused device/guest access |
| `cd_irq` | `musashi_boot_execute_cd_irq_with_services` | `runtime_irq_callback` (irq_scheduler.c): overlay disc streaming, XA setup, the CD driver |
| `bios_event` | `musashi_boot_execute_bios_event` | `musashi_bios_events_deliver`: card/CD event callbacks |
| `input_bios_callback` | `musashi_boot_execute_input_bios_callback` | the pad BIOS card/input callbacks (native_boot.c `input_execute`) |
| `source_call` | `musashi_boot_execute_source_call` (and `..._source_function` through it) | `source_irq_execute`: non-special IRQ callbacks; the memory-card request handlers |
| `lane_guest_call` | `musashi_native_guest_call` | generated lane thunks calling a callee that is not in the lane. Since B23 the strict build first dispatches the callee through the lane table (generated C, PsyQ compat wrappers, frame-driver replacements) and stops only on a miss (`routine=not_in_lane`) |
| `psyq_refused` | `bfm_psyq_call` when a wrapper refuses | STUB rows, held-back wrappers, PsyCross classes compiled out |

The `musashi_boot_run_8xxxxxxx_prefix` routers in `mips_formatter.c` are
test-probe-only and are not guarded.

## Status (2026-10-03)

Adopted from the GLM lane draft (task 52098a9467c4,
`~/release-staging/glm-lanes/bfm/strict-build/STRICT_BUILD_DRAFT.md`), ported
onto `port/native-lane` after B18. Verified in `build/lanes/own12`
(main_0003+main_0012 lane, RelWithDebInfo):

- default build unchanged in behaviour (the seam TUs compile the same code
  without the define; one new TU); a headless boot runs through ResetGraph and
  CD_init with no `STRICT_INTERPRETER_ENTRY` line;
- strict build: `musashi_native_boot --disc ...` prints
  `STRICT_INTERPRETER_ENTRY seam=boot_entry routine=musashi_boot_run_entry_with_devices guest_pc=80010000`
  with the host call chain and exits 134; no PERF/ROUTE line is produced, i.e.
  not one interpreted instruction ran. Evidence:
  `~/release-staging/bfm-strict-native/run/strict-run.log`.

This is the expected result today: the game loop itself is interpreted. The
strict build is not a playable configuration and must not enter a release
candidate. What the zero-fallback slice still needs, in order:

1. the support-symbol split above, so strict can link without the interpreter;
2. a native frame driver behind the `boot_entry` seam (frame loop over lane
   entries, VSync-paced through `bfm_plat_timing`, overlay selection through
   the existing digest hooks; design and per-frame callee status in
   `docs/NATIVE-FRAME-DRIVER.md`). **Started in B23**: `pc_port/native_frame_driver.c`
   runs main's init, session and frame loops through the lane table with the
   `frame_driver` stop; see "Implementation status" in that note;
3. the slice lane itself: boot -> title -> village -> inn save -> Continue
   with every function on the route admitted (the measured release-trace
   ranking in the draft's §2-3 is the work order);
4. acceptance: a strict run of the slice that completes with zero
   `STRICT_INTERPRETER_ENTRY` lines, alongside the differential, pixel, PCM,
   timing and save artifacts the owner standard names.

Until then every useful build stays hybrid and is disclosed as such.

## Generator strict mode and scratchpad constants (B24, 2026-10-07)

- **`--strict`.** A `MUSASHI_STRICT_NATIVE` configure passes `--strict` to
  `tools/native_lane_gen.py`. With no interpreter, nothing observes a guest
  PC, so three interpreter-only rules are dropped:
  - the `hooks` rule (port-referenced PCs inside a body, `ALWAYS_HOOKED`);
  - the caller-pinned GTE rule;
  - the PsyQ hooked hold-back (`musashi_native_lane_hooked_psyq` is emitted
    empty).

  Non-strict builds are unchanged.
- **Scratchpad constants.** Constant addresses in 1F800000..1F8003FF now pass
  the `inttoptr` rule. `musashi_native_lane_map_guest` maps the scratchpad page
  at host 1F800000 from the same memfd as `MusashiBootMemory.scratchpad`.
  - Bodies that use such constants are listed in
    `musashi_native_lane_scratchpad_pcs[]`; today that is 800184F0.
  - When the alias cannot be mapped, native_boot leaves those bodies to the
    interpreter. A strict build aborts instead (`seam=native_lane
    routine=scratchpad_alias`).
- **ctest in a strict build.** Tests that drive the interpreter (for example
  entry_cpu_boundary, nested_source_call_cpu, native_startup_boundary and the
  lane differentials) abort at their first `STRICT_INTERPRETER_ENTRY`, by
  design. The hybrid build of the same tree passes all 37 tests against the
  retail extracts.


## Strict-only allow list and RAM volatile (B25, 2026-10-07)

- `config/lane_strict_allow.txt` is passed as a second `--only` (the
  generator takes the union) only when `MUSASHI_STRICT_NATIVE`: 800147B8,
  80015908, 8001D1C4, 8003324C. Their fixed cycle charges are approximate, so
  the normal build keeps them interpreted and its lane table is unchanged
  (regenerated hybrid `native_lane_table.c` byte-identical; route proof
  unaffected).
- With `--strict`, the memory rule admits a volatile load/store whose address
  provably derives from a constant guest RAM/scratchpad address (inttoptr
  bases through getelementptr/phi/select/bitcast, greatest fixpoint for loop
  phis) or is a local alloca. Matched C uses volatile to pin gcc 2.7.2 store
  order or pad frames (80018FC8, 80015310); device registers and pointer
  cells stay refused. Strict admits 647 functions.
