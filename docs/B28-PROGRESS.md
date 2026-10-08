# B28 progress note (restart point)

Branch `cursor/native-cleanroom-b28`, stacked on b27 `79fa85ee`. This note is
updated with every pushed increment.

## Run and gates

Strict run (box):

    FR=600 TO=400 bash /tmp/srun.sh

This builds `build/b23-strict` with -j5 and runs the driver. The stop line is
`STRICT_INTERPRETER_ENTRY`.

Gates before each commit:

1. Build `build/b23-hybrid`, then `cmp` its `generated/native_lane/native_lane_table.c`
   with the pre-B28 copy (it must be identical).
2. Hybrid ctest: 37/37.
3. `tools/check_no_m2c_text.py`.
4. `tools/check_no_retail_data.py --region main`: only the 2 known jtbl build
   failures (800626C8/800626DC) are allowed.
5. try.py MATCH for every new or changed source.

## State

Increment 1:
- Strict boot runs 2400 driver frames with no strict stop.
- The SQUARESOFT / "Published by Square Electronic Arts" logo textures are
  in VRAM.
- The displayed buffer (0,0 256x240) is still black. Next step: find why no
  draw reaches the display area (OT draw / DrawOTag path, fade, or display
  origin).

Increment 2:
- DMA4 completion IRQ (strict), sliced guest time, and libsnd/libspu VAB HLE
  (see the NATIVE-FRAME-DRIVER.md B28 increment 2 section).
- The logo overlay main_0001 finishes. State 6 draws 32 prims around frame 500.
- main_0004 loads about 50 frames later. First stop:
  `guest_pc=800ceec8`, the main_0004 state dispatcher (table 800D3598 on
  u16 800B99E4). It is called every frame from 80010F80.
- main_0004 has no C in the repo (only word exports) and nothing upstream.
  Its functions need clean-room C under `src/overlays/main_0004/` and a
  `main_0004` line in `config/lane_strict_overlay_allow.txt`.
- Disassemble overlays with `/tmp/cr/disov.py VRAM LEN extracted/overlays/main/0004.bin 800ce5f8`.
  This is dis2.py with a member file and base argument; rebuild it from
  dis2.py if /tmp is gone.

Increment 3:
- Added `config/overlay_main_0004.yaml` (sha1 checked; the 0x800 header means
  file offset 0 maps to 800CE5F8) and a `main_0004 all` line in the strict
  overlay allow list.
- Clean-room, byte-matched C in `src/overlays/main_0004/`: 800CEEC8
  (dispatcher), 800CEF04 (state 0), 800D1E18 (CdSearchFile of the movie),
  800CFB3C (record walk, LoadImage). Check them with
  `SIZE=0x.. python3 /tmp/cr/tryov.py VRAM SRC`, which compares against
  extracted/overlays/main/0004.bin at vram-800CE5F8. Add registry rows with
  `/tmp/cr/addrowov.py VRAM SIZE`.
- libsnd HLE: SsSetSerialAttr 8003D650, SsSetSerialVol 8003EDE8.
- First stop: `guest_pc=800cf010`, main_0004 state 2. State 0 advances the
  state twice, so state 1 is skipped.

Increment 4:
- More clean-room, byte-matched C for main_0004: 800CF010 (state 2),
  800CF078 (state 3), 800D1E58, and 800D1E9C (the blocking movie play loop,
  0x4F8 bytes).
- Strict generator (`escape` rule): when the compiler cross-jumped identical
  call tails, the retail words hold fewer `jal` sites than the C has calls.
  `merged_call_bases` now finds the one frame-offset assignment that maps
  every C call onto a retail site and covers every site. A tie is broken by
  the locals' definition order. This admits 800D1E9C.
- First stop: `guest_pc=800d2d68` (libpress MDEC reset, linked into the
  overlay), reached through main_0003's 800D2AA0. main_0003 is the sibling
  movie overlay: same code at the same addresses, vendor C, digest-identical,
  so its C runs for main_0004.
- Next: add `main_0003 all` to the strict overlay allow list. Its vendor C
  covers most of the movie player and libpress. Then HLE or C for whatever
  the lane still refuses (MDEC hardware access).

Increment 5:
- Added `main_0003 all` to the strict overlay allow list. Its vendor C
  (Druthulu) covers the movie player and libpress wherever main_0004's bytes
  are identical (digest-matched per call). Overlay lane: 291/319.
- Generator fix (strict): an empty asm whose output is tied to a different
  input (`"=r"(s1) : "0"(arg0)`) becomes `s1 = (arg0);`. Before this fix,
  strict treated a pinned output as an identity, which left s1 uninitialised
  (host fault in main_0003 800CFB3C).
- libpress MDEC low level (800D2D68 reset, 800D2E64 in, 800D2EF8 out,
  800D2F88/800D3020 syncs, 800D30B8 status, 800D30D0 timeout) as driver HLE
  through the gpu_io device (MDEC + DMA0/1). It is guarded by an FNV-1a 64
  hash of the resident bytes, since overlays share addresses.
- libcd streaming: StSetRing 80043088, StClearRing 8004689C, 80046BFC.
- First stop: `guest_pc=80046abc` (libcd streaming). Next: the remaining St*
  functions (StSetStream, StGetNext, StFreeRing, StUnSetRing 800468FC and the
  ring-filling ready callback), then the MDEC decode path.

Increment 6:
- libcd streaming and CD read HLE: StSetStream 80046ABC, 80046CFC,
  CdRead2 8004657C (installs the stream callbacks 800469CC/80046610),
  StUnSetRing 800468FC.
- GsSetRefView2 80053F6C and its callees (80053B20, 80054340, SquareRoot0
  80047D3C) have been native driver code since increment 1.
- The movie call 800D1E9C returns, and the overlay reaches state 3. First
  stop: `guest_pc=800cfc1c` (main_0003 vendor C, refused under `escape`: a
  frame local is passed through a pointer variable). The movie most likely
  ends early. Check whether frames decode once the stream callbacks run.

Increment 7 (generator, strict only):
- `pointer_slot_sources`: a frame local copied through a pointer variable
  (`argp = buf; f(argp)`) is still mapped to its retail frame slot (`escape`).
  This admits main_0003 800CFC1C.
- `switch_tables_internal`: a gcc switch whose jump-table entries (read from
  the member file) all point inside the function is no longer refused under
  `jumptable`. The native switch never reads the guest table. This admits
  5 main_0010 functions.
- Strict boot: logo, then the intro movie overlay (states 0..5, about frames
  525..1125), then main_0010 (resident engine). First stop:
  `guest_pc=8001c0c8`, a main row with origin "vendor-referenced
  (Druthulu/BFM-decomp)", which the strict provenance allow list did not
  name yet (fixed in increment 8).

Increment 8:
- `vendor-referenced (Druthulu/BFM-decomp)` (6 main rows) is added to the
  strict provenance allow list. Same upstream class as vendor-derived.
- main_0010 800CFD68 is now clean-room C that returns the callee's value.
  The vendor version fell off the end of a non-void function (`ub`), while
  its callers test the result.
- Strict boot passes main_0010 set-up and stops at frame ~1200:
  `guest_pc=80128158` (main_0012, the game's main overlay, 2359 C rows; only
  a hand-picked subset is admitted). Next: `main_0012 all` in the strict
  overlay allow list.

Increment 9:
- Added `main_0012 all` to the strict overlay allow list. The overlay lane is
  now 2032/2577. The strict build takes ~4 min the first time, so run it
  detached: `setsid nohup bash /tmp/srun.sh ... &`.
- `'<member> all'` skips registry rows whose size runs into the next
  function. Two main_0012 rows (8012ACE0, 801457A4) have that registry
  inconsistency.
- New strict-only evidence switch: `MUSASHI_STRICT_STOP_RAM=/tmp/x.bin`
  dumps guest RAM at a not_in_lane stop. Compare it with each member's
  digest to find the resident overlay. Keep the dump in /tmp only (it is game
  data).
- First stop: `guest_pc=80128288`. The resident member is sc02_0031 (a scene
  overlay with vendor C), not main_0012. Next: `sc02_0031 all`.

Increment 10:
- Added `sc02_0031 all`. The overlay lane is now 2591/3269.
- First stop: `guest_pc=80145cec`, sc02_0031 (resident, digest-checked from
  the stop RAM), refused as `ub` (undef/poison operand).

Increment 11:
- New strict-only generator rule `void_result_returns`. A function whose
  every return is `ret iN undef` (it falls off the end without a value)
  returns 0 instead. The rule applies only when no other C file uses the
  result (every use is an extern, a prototype, a definition header or a bare
  call statement) and no aligned word in the member or the main EXE equals
  the function address (so it is never an indirect target). 80145CEC passes;
  800CFD68 (its callers test the result) is still refused.
- The overlay lane is now 2616/3269. First stop: `guest_pc=800553d8`
  (libgs6, GsLinkObject4). Next: a driver HLE for it.

Increment 12 (driver HLE, strict only):
- New HLEs from the retail disassembly: GsLinkObject5 (800553D8),
  GsSetRefView2L (80054DCC), csqrt (80047B3C, with its hyperbolic CORDIC
  helper 800479E8) and GsPresetObject (800553F4, the 16 TMD packet-template
  cases from the jump table at 80073C20).
- First stop: `guest_pc=80144b9c` at frame ~1200, refused as `layout`
  (aggregate copy/fill sized with host pointer width).

Increment 13 (generator, strict only):
- Struct assignment: an llvm.memcpy/memmove whose global or local end has one
  named pointer-bearing type, with a constant length equal to that type's
  host size, is resized to the guest-layout size (`llvm_type_layout`).
  80144B9C (`D_80078E50 = *ent`, 48 -> 36 bytes) is the first case.
- `strip_symbol_binding_asm` drops file-scope `.globl X` / `.set X, 0x...`
  asm that only bound gcc's memcpy library call to the retail address. Left
  in, it made host `memcpy` an absolute symbol and broke the link. Any other
  module asm, or a direct call to the bound symbol, is refused (`symbols`).
- The overlay lane is now 2617/3269. First stop: `guest_pc=801814e4`
  (sc02_0031), refused as `escape` (`(s32)&local` passed as an int).

## Next

- Display path for the logo: compare the GPU packets the strict path submits
  with what the overlay's draw loop queues.
- Keep walking toward attract mode and the village (main_0012 is already in
  the overlay allow list through the release list; add more members to
  `config/lane_strict_overlay_allow.txt` as the boot loads them).
