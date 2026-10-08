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

## Next

- Display path for the logo: compare the GPU packets the strict path submits
  with what the overlay's draw loop queues.
- Keep walking toward attract mode and the village (main_0012 is already in
  the overlay allow list through the release list; add more members to
  `config/lane_strict_overlay_allow.txt` as the boot loads them).
