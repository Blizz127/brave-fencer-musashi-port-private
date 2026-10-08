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

## Next

- Display path for the logo: compare the GPU packets the strict path submits
  with what the overlay's draw loop queues.
- Keep walking toward attract mode and the village (main_0012 is already in
  the overlay allow list through the release list; add more members to
  `config/lane_strict_overlay_allow.txt` as the boot loads them).
