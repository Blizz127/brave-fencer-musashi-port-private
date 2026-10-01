# Graphics enhancements: feasibility and plan (task 2175d2b7b66b)

Owner request (2026-09-30): "better graphics options like 60 fps, DLSS, AMD
(FSR), higher resolutions, better models etc ... standard recomp port stuff
under Enhancements". Every option is OFF by default, lives in the Port Dev
Menu under a new **Enhancements** page, is persisted, and leaves the retail
picture and timing untouched when off (ARCHITECTURE-PORT.md rules 1 to 4;
D-035 in KNOWN-DIVERGENCES.md covers the opt-in divergence).

This document is stage 1 of the task: what the renderer does today, what each
feature needs, what is blocked and why, the order of work, and the measured
baseline. Nothing in it is implemented yet unless the text says so. The
existing design notes it builds on are ARCHITECTURE-PORT.md "60 fps (design
note, not implemented)", "Widescreen" and "gl renderer (HD / restyle)".

## 1. The renderer today (r30, e564658c0)

Two render paths exist, selected by the environment, not by config.ini:

| Path | Selection | What draws | Resolution | Status |
|---|---|---|---|---|
| **cpu** (default, shipped) | `MUSASHI_GPU=cpu` or unset | `pc_port/gpu_controller.c` software rasteriser into PsyCross's CPU `vram[]` at native 1x; `gpu_psycross.c:blit_vram` stretches the GP1 display rect to the window with `GL_NEAREST` | 320x240-class, stretched to a fixed 1280x960 window (`native_boot.c:4874`, `:5390`); no aspect handling, ultrawide would stretch | the only path verified through gameplay |
| **bridge + psycross** | `MUSASHI_GPU=bfm_plat`, `MUSASHI_RENDERER=psycross` | GP0/GP1 decoded to `BfmPlatPrim` lists (`bfm_plat_gpu_bridge.c`), drawn by PsyCross's GL 3.3 primitive renderer into the window backbuffer | window resolution, integer vertices (`USE_PGXP=0`), OT-order painter's depth | runs the village scene headless (measured below); fidelity to the PS1 GPU untested (D-034) |
| **bridge + gl** | `MUSASHI_GPU=bfm_plat`, `MUSASHI_RENDERER=gl` | `backends/renderer_gl.c` + `backends/gl/*`: own GL 3.3 core context, VRAM `R16UI` texture, RGBA8 targets at internal scale 1..8, dual-source PS1 blending, dither at native granularity, hor+/anamorphic, hash-keyed HD texture replacement | `video.internal_scale` 1..8, window of any size | **refuses before the game starts** in r30: `GPU DMA2 owner initialization refused before CRT`, rc=2 (measured 2026-09-30, job 20260930-184759-...-1440190). Never run against the real game (ARCHITECTURE-PORT.md status list, D-032) |

Facts that shape every feature below:

- **Config keys exist but do not reach the live game.** `[video]`
  `internal_scale`, `window_width/height`, `fullscreen`, `vsync`, `aspect`,
  `widescreen_mode`, `frame_rate`, `dither`, `gpu` are parsed
  (`bfm_plat_config.c:130-166`) and saved, but `native_boot.c:plat_start`
  builds its config from defaults and the environment only
  (`native_boot.c:5094-5125`), and `gpu_bridge_attach` hardcodes
  640x480, scale 1, 4:3 (`native_boot.c:5160-5165`). D-012 records
  `frame_rate = 60` as accepted with no effect.
- **No Enhancements page, no persistence.** `dev_menu.c` has ROOT / WARP /
  FINISH AREA / CHEATS / OPTIONS; state is in memory only. Options holds
  FAST-FORWARD, FAST-FORWARD SPEED, SCREENSHOT. `tests/dev_menu_probe.c`
  is the parity model (menu browsed, every cheat off, zero guest bytes
  change over 1000 VBlanks); any Enhancements page must keep it green.
- **Retail logic is 30 Hz; the host presents 60 fields.** `main` waits
  `VSync(*(s32 *)(p + 0xA3E8))` = 2 fields. `epoch_video_edge`
  (`native_boot.c:2760-2830`) presents once per 60 Hz field, so every
  frame is shown twice already. `PERF` lines (`native_boot.c:2708`) give a
  10 s average of speed, idle share and present time; there is no
  per-frame time log yet.
- **Depth is draw order, not a Z buffer.** PsyCross and the gl backend both
  reproduce the PS1 painter's algorithm (ARCHITECTURE-PORT.md "GPU seam
  decisions"). There is no depth buffer, no motion vector, no jitter, and
  no per-primitive identity across frames (`BfmPlatPrim` has no owner tag).
- **GTE results are committed as integer SXY.** The GTE is PsyCross's bank
  behind `gte_owner.c`; `USE_PGXP=0` is forced in `CMakeLists.txt`. No
  sub-pixel capture hook exists.
- **Texture replacement exists on the gl path only**, keyed by FNV-1a 64 of
  the raw VRAM upload rect (`bfm_plat_mods.c:503`, `[mods] dump_textures`,
  docs/MODDING.md section 4). It ignores texture window and CLUT, so one
  replacement serves every palette swap of a texture. The cpu path has
  only the evidence dump `MUSASHI_DUMP_UPLOADS`.
- **Widescreen maths and projection hooks exist** (`bfm_plat_widescreen.c`,
  `SetGeomScreen`/`SetGeomOffset` sites). Missing: the GTE backend never
  calls `bfm_plat_widescreen_sx_current`, hor+ edge culling is unpatched,
  and the cpu path's present cannot show a wider image.
- **Parity fixtures.** There is no frame-hash or VRAM-hash golden test.
  The closest tools: `test_bfm_gpu_bridge.py::test_bridge_matches_controller`
  (bridge rasteriser vs CPU controller, skipped without
  `BFM_GPU_CONTROLLER_DIR`), `tools/headless/bfm_swap_capture.c`
  (LD_PRELOAD: PNG + VRAM dump per swap), `bfm_ot_replay.c` (replays
  captured lists through both rasterisers), `tools/vram_pixel.py`.

## 2. Measured baseline (2026-09-30)

Method: packaged r30 `musashi_native_boot.x86-64-v3` (sha256
`59299783fdab...57edd`), headless on the blizzpc runner (SDL offscreen,
EGL surfaceless, `MUSASHI_AUDIO=null`, no capture shim), dev-menu warp
test harness to Grillin' Village 1010 then idle, so the camera is the same
in every run; one run at a time; 170 s wall each; `PERF` windows after the
warp. Job `20260930-184759-bfm-2175-gfx-baseline2-1440190`, script
`baseline-job2.sh`, raw log and stats in
`~/release-staging/bfm-gfx-2175/` (owner-local).

Host: AMD Ryzen 7 5800XT, Radeon RX 6900 XT (radeonsi, Mesa 26.2.1, GL 4.6
core), runner-niced, host load about 1 to 2.

| Run | Path | Throttle | Speed min / median / max | present_ms median (max) | idle |
|---|---|---|---|---|---|
| cpu_unthrottled | cpu | unthrottled | 66 / **78** / 94 % | 0.21 (0.55) | 0 % |
| cpu_throttled | cpu | guest clock | 62 / **72** / 95 % | 0.32 (0.51) | 0 % |
| psycross_unthr | bridge + psycross | unthrottled | 71 / **87** / 99 % | 0.83 (1.26) | 0 % |
| psycross_thr | bridge + psycross | guest clock | 58 / **68** / 99 % | 0.96 (1.29) | 0 % |
| gl_unthr | bridge + gl | unthrottled | refused before gameplay (rc=2) | n/a | n/a |

What the numbers say:

1. **The village scene does not hold real time on this host, and the GPU
   is not why.** Speed is 60 to 95 % with idle at 0 % while present costs
   0.2 to 1.3 ms of a 16.7 ms field. The emulated guest CPU (interpreter
   plus native lane) is the ceiling. Any "60 fps" option is cosmetic until
   the game runs at 100 % in its heaviest rooms. Caveat: the runner nices
   its jobs and other work was on the box; a foreground measurement on the
   owner's machines is needed before treating these as absolute. The
   Alienware (Core Ultra 9 290HX, RTX 5070 Ti) run is queued as job
   `20260930-184759-bfm-2175-gfx-baseline2-715342`; the runner held its
   slots on the memory cap (MemAvailable 12 GB < 14 GB) and the machine was
   on battery, so there are no Alienware numbers yet.
2. **Software rasterising costs guest-thread time.** The psycross bridge
   is 9 points faster unthrottled than the cpu path (median 87 % vs 78 %)
   although its present is 4x longer: the cpu rasteriser's per-pixel
   `store_vram` runs on the emulation thread and is invisible in
   `present_ms`. Moving drawing to the GPU is itself a speed-up.
3. **Rendering headroom is large.** At 1 ms per field for a window-sized
   PsyCross frame, 4x internal scale and a post-process pass will fit in a
   16.7 ms field on either host. The gl bench (ARCHITECTURE-PORT.md) agrees:
   a desktop GPU draws these frames in well under a millisecond.
4. **Capture overhead for before/after videos is 4 ms per field**
   (`present_ms` 4.1 to 4.5 in the showcase takes with `bfmcap.so`
   readback + x264), so before/after captures must be compared by picture,
   not by speed.

## 3. Feature by feature

Legend: **ready** = infrastructure exists, needs wiring and tests;
**build** = new code on existing hooks; **blocked** = needs a prerequisite
that does not exist, with the reason.

### 3.0 Prerequisite: an enhancement renderer that runs the game (stage 0)

Every option below except the 60 fps logic question needs a GPU-side
renderer with an internal render target. The only candidate with scale,
widescreen, HD textures and a post-process seam is the **gl backend**, and
it refuses at start. Stage 0 is therefore:

- Make `MUSASHI_GPU=bfm_plat MUSASHI_RENDERER=gl` boot and play. The
  refusal is `GPU DMA2 owner initialization refused before CRT`
  (`gpu_dma2.c` owner handshake while the gl backend owns its own SDL
  window/context next to the PsyCross one `native_boot` already created;
  `renderer_gl.c:109` calls `SDL_CreateWindow`). Likely fix: let the gl
  backend adopt the existing PsyCross window/context (the executor already
  runs on "any current GL 3.3 context") instead of creating a second one.
- Route config to the live game: `plat_start` loads
  `$XDG_CONFIG_HOME/bfm-port/config.ini` and `--set`, and
  `gpu_bridge_attach` passes `internal_scale`, window size, aspect, vsync
  from it instead of the 640x480 constants.
- **Parity gate at 1x, everything off:** record one deterministic run
  (cold boot, warp to 1010, N fields) on the cpu path with
  `bfm_swap_capture.c` (PNG + VRAM per swap), then the same on gl at 1x,
  and compare per-frame VRAM hashes. Target: identical 15-bit VRAM for
  every frame except where D-033 allows ±1 in modes 0 and 3 (report the
  count). This becomes the "all enhancements off" fixture the task asks
  for; the project has no 900-hash style fixture today, so this creates
  the equivalent (frame hashes over a fixed route).
- Add the **Enhancements** page to the dev menu with persistence through
  `bfm_plat_config_set` / `bfm_plat_config_save_file`, and extend
  `tests/dev_menu_probe.c` so browsing the page with everything off still
  changes zero guest bytes.

Estimate: 1 to 2 days. Risk: medium (window/context ownership, and the gl
backend's first contact with real display lists; expect primitive-decode
bugs to surface in the parity gate).

### 3.1 Internal resolution scaling and output resolution

- **Status: ready** on gl (`video.internal_scale` 1..8, RGBA8 targets at
  `1024S x 512S`, scene slots at `(disp_w+2m)S x disp_h S`, present fitted
  to the window with black bars). Window and fullscreen resolution are
  already independent of the internal scale on gl. On cpu: nothing; the
  window is a 1280x960 constant.
- **Needs:** stage 0; menu rows `RENDER SCALE: NATIVE / 2x / 3x / 4x` and
  `OUTPUT: WINDOW / FULLSCREEN` (`SDL_SetWindowFullscreen` desktop mode,
  present keeps 4:3 with bars); scale changes at runtime require
  re-creating the gl targets (`bfm_gl_exec_create` takes the scale at
  creation).
- **UI/2D correctness and bleeding.** Texels are sampled nearest at native
  texel size (not magnified), 2D tiles/sprites are drawn as scaled quads
  with the same integer texel sampling, and the draw-env clip is a scissor
  in scaled pixels, so there is no texture bleeding by construction. What
  changes with scale is edge placement only. Test: at 2x/4x, downsample the
  frame by box filter to 1x and compare with the 1x frame of the same
  field; expect differences only on primitive edges (count and report).
- **Dither:** `video.dither = auto` turns the PS1 dither off above 1x
  (D-033). Expose as `DITHER: AUTO / ON / OFF` on the same page.
- Estimate: 0.5 day after stage 0.

### 3.2 Frame rate: 60 fps

The honest labels first, as the task asks:

- **Native game logic is 30 Hz** and stays 30 Hz. A doubled logic tick
  (ARCHITECTURE-PORT.md option 2) changes gameplay timing (play-time
  counter `func_80029444`, RNG cadence, scripted timing, day/night clock)
  and is **not planned**.
- **"60 fps" in this port means interpolated presentation** (option 1):
  logic at 30, picture at 60 with the camera and object transforms
  interpolated between ticks. The menu row must say
  `60 FPS (INTERPOLATED CAMERA)` and the README must say logic stays 30 Hz.
- **Fallback is automatic and per frame:** a large transform delta (cuts,
  warps, room changes, MDEC movies, 2D-only frames) presents the last
  tick twice, which is exactly retail pacing.

Feasibility and prerequisites, in order:

1. The game must first hold 100 % speed in its heavy rooms (section 2);
   otherwise the second presented frame only slows the game further.
   Interpolation is therefore ordered **last** among the renderer options.
2. **Per-primitive identity across ticks.** `BfmPlatPrim` needs an owner
   tag (the guest primitive address or the OT entry it came from). Retail
   builds its OTs from fixed per-object primitive buffers, so the packet
   address is a stable identity for models and most sprites; particles
   and rebuilt primitives will not match and draw uninterpolated.
3. **Camera and object matrices.** Hook the libgte rotation/translation
   setters (`SetRotMatrix`/`SetTransMatrix` equivalents) as projection-like
   hook sites next to the existing `SetGeomScreen`/`SetGeomOffset` ones,
   recording per tick. With sub-pixel vertex capture (3.4) the simpler
   route is to interpolate **screen-space vertices per matched primitive**
   between ticks N-1 and N; that needs no matrix semantics and handles
   camera and objects alike, at the cost of straight-line motion over one
   tick (acceptable at 33 ms).
4. `present_interpolated(alpha)` in the gl backend: draw the matched
   primitive list with vertices lerped at alpha = 0.5 on the odd field.
   Doubled GPU work is affordable (section 2).
5. **Tests:** off = frame hashes identical to the stage 0 fixture; on =
   the even fields are identical to the off fixture and only odd fields
   differ; a camera pan test (scripted stick hold in 1010) shows the odd
   field's camera-relative vertex positions at the midpoint ±1 px.
6. Movies, 24-bit display and menus stay at their native cadence.

Estimate: 3 to 5 days after stage 0 and 3.4. Risk: high (identity misses
show as judder on particles; must be visibly acceptable).

Also cheap and worth doing first: **frame pacing**. The host presents
every field without a swap interval (`g_cfg_swapInterval = 0`,
`SDL_GL_SwapWindow` direct); `video.vsync` is only honoured by the gl
backend. Expose `VSYNC: ON/OFF` on the page once gl is the renderer.

### 3.3 Upscalers: FSR 1, FSR 2/3, DLSS

- **AMD FSR 1 (spatial EASU + RCAS): build, feasible.** FidelityFX FSR 1.0
  is MIT-licensed single-file GLSL (`ffx_a.h`, `ffx_fsr1.h`); it needs only
  the finished colour frame. It fits as a post pass in the gl present:
  render at internal scale S, EASU to the window size, RCAS sharpen, then
  the overlay. It is GPU-vendor neutral (works on the RTX machine too).
  Menu: `UPSCALER: OFF / FSR 1 (QUALITY, BALANCED, PERFORMANCE)` and
  `FSR SHARPNESS`. Note for the owner: at 320x240 source FSR 1 mostly
  smooths pixel art; its real value is upscaling a 2x/3x internal render to
  a 4K window cheaply. Test: present-time delta from `PERF` (expect < 1 ms
  at 1440p on either GPU) and a before/after capture at matched camera.
  Estimate: 1 day after stage 0. Licence: MIT, vendored with its notice
  (`docs/PC-PORT.md` third-party table).
- **FSR 2 / FSR 3 (temporal): blocked.** They require a depth buffer,
  per-pixel motion vectors, sub-pixel camera jitter and a reactive mask.
  The renderer has none: depth is OT order (no Z), motion vectors need the
  per-primitive identity and previous-tick vertices of 3.2, and camera
  jitter requires PGXP-style perspective projection (3.4) with the game's
  projection matrix under host control. Prerequisites: 3.2 and 3.4
  complete, then synthesise depth from PGXP Z and motion vectors from the
  lerp deltas. FSR 3 frame generation is a Vulkan/DX12 SDK on top; the GL
  renderer would need a Vulkan interop or a renderer port. **Not planned
  in this task**; revisit after 3.2 and 3.4 ship. The menu must not list
  it until it runs.
- **NVIDIA DLSS: blocked.** Same inputs as FSR 2 plus the NGX SDK (Vulkan
  or DX, not OpenGL; redistribution under NVIDIA's SDK licence), an NVIDIA
  GPU at runtime (`libnvidia-ngx.so` present on the Alienware, absent on
  the AMD blizzpc), and a signed-SDK integration the project cannot test
  on its AMD runner. If ever done it is gated at runtime on
  `GL_RENDERER`/Vulkan device vendor = NVIDIA and hidden otherwise. **Not
  planned in this task**; the menu must not show a DLSS row. The owner's
  question "DLSS?" gets a plain answer in the release notes: not in this
  renderer; FSR 1 is the vendor-neutral upscaler, and a temporal upscaler
  needs the depth/motion-vector pipeline first.

### 3.4 Better assets and geometry

- **Texture packs (AI-upscaled from the owner's own dumps): build, ready
  on gl.** The hook (`bfm_plat_mods_replace_texture` → `upload_replacement`,
  bilinear sampling of an RGBA8 image normalised to the rect, alpha < 0.5
  transparent, vertex colour still modulates) exists and is tested in
  isolation. Pipeline: a dump run with `[mods] dump_textures = 1` over the
  36-room sweep route (owner-local output, never redistributed), an
  upscale pass (the PE background recipe, 4x, with alpha preserved for STP
  texels), pack as `assets/textures/<hash16>.png` in a mod folder, enable
  via the Enhancements row `HD TEXTURES: OFF / <pack name>` (which sets
  `[mod.<name>] enabled`). Known limits to document: palette swaps share
  one replacement (the key is the raw upload rect, not the CLUT), texture
  windows are ignored, render-feedback (GPU-drawn textures) keeps the
  native look. Test: a frame with the pack has every replaced rect's draw
  sampling the replacement (count from a `BFM_GL_LOG_REPLACEMENTS`-style
  counter), and the pack off equals the fixture.
  Estimate: 1 day of port work plus the dump/upscale run (runner time).
- **Texture filtering: build, small.** The gl shader samples nearest.
  Offer `TEXTURE FILTER: NEAREST / BILINEAR` for 15-bit pages and HD
  replacements only (CLUT pages cannot be filtered before palette lookup
  without a decoded texture cache, which is a later step). Estimate: 0.5
  day.
- **PS1 wobble and affine warping (PGXP-style precision): build, medium.**
  Two parts. (a) Sub-pixel vertices: capture the GTE's unrounded SX/SY
  (and SZ) in `gte_owner.c` at RTPS/RTPT and attach them to the primitive
  that later reads the packet (PsyCross's PGXP cache does exactly this
  lookup-by-address; the port forces it off because the GTE used to be
  stubbed). (b) Perspective-correct texturing: pass 1/W into the gl
  shader and drop `noperspective`. The gl backend already has
  `USE_PGXP`-shaped seams in PsyCross to copy the design from, but the
  work must respect the "integer commit, depth is OT order" decision in
  PC-PORT.md: PGXP Z is used for perspective only, never for depth
  testing, until a z-vs-OT policy is written. Menu rows
  `GEOMETRY PRECISION: OFF / SUBPIXEL` and `PERSPECTIVE TEXTURES: OFF /
  ON`. Test: a scripted slow camera pan in 1010 at 4x; count per-frame
  vertex snaps > 0.5 px on matched primitives, expect 0 with SUBPIXEL on;
  off equals the fixture. Estimate: 2 to 3 days. This is also the
  prerequisite for 3.2 and any temporal upscaler.
- **Higher-poly or smoothed models, vertex-normal smoothing, per-pixel
  lighting: blocked for this task.** PS1 lighting is computed by the GTE
  (NCS/NCT) into vertex colours before the GPU sees a flat/gouraud
  primitive; normals never reach the renderer. Doing this properly means a
  TMD-aware path: identify the model (TMD on disc, `tools/extract_tmd.py`)
  behind each primitive, re-light it on the host with the game's light
  matrices (hook the `SetLightMatrix`/`SetColorMatrix` sites), and
  optionally substitute a higher-poly mesh. That is a model-replacement
  system, not a toggle; it needs the identity work of 3.2 and the matrix
  hooks of 3.4 first. Smoothed normals on the existing low-poly meshes
  would only be a per-pixel-lighting variant of the same system. Deferred;
  listed in the menu as nothing until it exists.
- **Widescreen (hor+, anamorphic) with culling fixes: build, medium.**
  Maths and the gl margins exist. Missing: hor+ edge culling. Retail culls
  objects against the 320-wide screen before drawing, so hor+ shows
  pop-in at the sides; the fix is per culling site (the GTE-side screen
  width test or `SetGeomScreen`-dependent compares) and must be found in
  the matched decomp per room class. First deliverable: hor+ 16:9/16:10 on
  gl with the pop-in documented (`ASPECT: 4:3 / 16:9 HOR+ / 16:10 HOR+ /
  16:9 ANAMORPHIC`), then the culling patches as evidence is gathered
  with a scripted edge-of-screen test in 1010 and 3008. Anamorphic also
  needs `bfm_plat_widescreen_sx_current` called from the GTE backend.
  Estimate: 1 day for hor+ on gl, culling fixes open-ended.

### 3.5 Anti-aliasing and anisotropic filtering

- **MSAA: build, small.** Make the gl scene-slot and VRAM targets
  multisampled (`glRenderbufferStorageMultisample` / multisample textures,
  resolve before readback and present). Caveats: the mask-bit stencil and
  the render-feedback SNAPSHOT/RESOLVE paths read the targets, so the
  resolve must happen before any readback, and dual-source blending with
  per-sample STP is fine in GL 3.3 core. Only polygon edges change; at
  320x240-class geometry 4x MSAA is the visible win, and it is redundant
  above 3x internal scale. Menu: `ANTI-ALIASING: OFF / MSAA 2x / 4x / 8x`
  (capped by `GL_MAX_SAMPLES`). Test: off equals fixture; on, differences
  only on edge pixels. Estimate: 1 day.
- **Anisotropic filtering: not meaningful here; offered only with
  perspective textures and HD packs.** PS1 textures are affine, unmipped
  and sampled nearest; AF needs mipmaps and perspective-correct derivatives
  to do anything. With 3.4 perspective texturing plus HD replacements
  (which are real RGBA8 textures) AF becomes a one-line sampler parameter
  (`GL_TEXTURE_MAX_ANISOTROPY_EXT`, present on both hosts' drivers) and
  mip generation for replacements. Menu: `ANISOTROPIC: OFF / 2x..16x`,
  greyed until perspective textures are on. Estimate: 0.5 day after 3.4.

## 4. Order of implementation

Each stage: one commit series on `port/native-lane`, a test per option, a
before/after capture at the matched camera (warp harness to 1010, same
field index), everything-off frame hashes equal to the stage 0 fixture,
plain-words release notes. No release, tag, push or publication in this
task.

| # | Stage | Depends on | Estimate | Risk |
|---|---|---|---|---|
| 0 | gl renderer runs the game; config reaches the game; 1x frame-hash parity fixture; Enhancements page + persistence | – | 1–2 d | medium |
| 1 | Internal scale 2x/3x/4x, output window/fullscreen, dither mode, vsync | 0 | 0.5 d | low |
| 2 | FSR 1 (EASU + RCAS) post pass with sharpness | 0, 1 | 1 d | low |
| 3 | HD texture packs from the owner's dumps; texture filter nearest/bilinear | 0 | 1 d + runner time | low |
| 4 | MSAA 2x/4x/8x | 0, 1 | 1 d | low |
| 5 | Widescreen hor+ on gl (anamorphic after the GTE hook); culling fixes as found | 0 | 1 d + open | medium |
| 6 | Sub-pixel geometry + perspective textures; anisotropic for HD | 0 | 2–3 d | medium |
| 7 | 60 fps interpolated presentation (camera/object), with automatic native-rate fallback | 0, 6, and the game at 100 % speed in heavy rooms | 3–5 d | high |

Blocked, reported rather than built: FSR 2/3, DLSS (section 3.3);
higher-poly/smoothed models and per-pixel lighting (3.4); 60 Hz game logic
(3.2, by design). The speed ceiling in section 2 is a separate performance
task (emulation hot paths, more matched functions on the native lane), not
a graphics option, and it gates stage 7.

## 5. Verification plan common to every stage

- **Parity fixture (stage 0):** cold boot, warp 1010, 600 fields, cpu path
  vs gl 1x, per-frame VRAM hashes (`bfm_swap_capture.c`); the fixture hash
  list is checked into `tests/fixtures/` and every later stage runs it with
  all enhancements off. Plus the existing `dev_menu_probe` zero-guest-write
  gate with the new page browsed.
- **Measured effect:** `PERF` present_ms before/after per option on both
  runners (a per-frame frame-time log, `MUSASHI_PERF_FRAMES=<path>`, is
  added in stage 0 so stutter is visible, not just the 10 s mean).
- **Before/after captures:** the showcase capture pipeline
  (`release-staging/xeno-work/videos-20260930/r29`, `bfmcap.so`,
  `mkedit.py`) at the same warp and field index, side-by-side contact
  sheets; captures stay owner-local.
- **Saves, replays, fixtures identical with everything off:** no option
  touches guest RAM or timing; the dev-menu probe and the frame-hash
  fixture are the evidence. 60 fps interpolation reads primitive lists
  only and must show zero guest writes in the probe.

## 6. Open questions for the owner (not blocking stage 0)

1. Default window size and fullscreen behaviour on the Legion/Steam Game
   Mode (today a fixed 1280x960 window): keep 4:3 with bars at the
   display's native resolution when FULLSCREEN is on?
2. Which rooms to use for the HD-texture dump route: the 36-room sweep, or
   the Chapter 1 milestone route only?
3. Is "60 fps (interpolated camera)" acceptable wording, given logic stays
   30 Hz by design?
