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

- **Only some config keys reach the live game (enhancements G1/G2).**
  `native_boot.c:enhancements_from_file` reads `config.ini` at startup:
  `[video] gpu = bfm_plat` with `[backends] renderer = gl` selects the gl
  bridge, and `internal_scale` and `dither` reach it. Three more keys act
  only when the file sets them:
  - `vsync = 0|1` (gl only) sets the swap interval. Absent, the interval is
    left as it is; see frame pacing in 3.2.
  - `fullscreen = 0|1` (both renderers, r50) decides the window mode in
    `host_window_apply_mode`: 1 borderless desktop fullscreen, 0 a window.
    Absent, the window is kept everywhere. Since r51 that includes Steam
    Game Mode, where Gamescope shows the window borderless and scaled. r50
    switched Game Mode to fullscreen automatically, but an emulated Game
    Mode capture (Xvfb, no window manager) showed the post-creation switch
    leaving a 1280x960 back buffer under a 1920x1080 SDL size, which
    clipped the picture. `BFM_FULLSCREEN` / `--fullscreen` /
    `--windowed` win over the file (docs/HANDHELD-AUDIT-r49e.md).
  - `aspect = 16:9|16:10` (gl only, G3) opens the gl renderer at that aspect:
    hor+ (more of the scene at the sides, the game's projection untouched).
    `4:3` or absent keeps 4:3. A typed key, so `save_file` keeps it.
  - `present = integer` (gl only) places the image at whole multiples of the display
    height (`bfm_plat_present_viewport`). This is a text key the typed
    parser keeps, so `bfm_plat_config_save_file` drops it.

  `MUSASHI_GPU` / `MUSASHI_RENDERER` still win over the file.
  `window_width/height`, `aspect`, `widescreen_mode` and `frame_rate` are
  parsed (`bfm_plat_config.c`) and saved but still do not reach the game:
  `gpu_bridge_attach` opens 640x480 at 4:3. D-012 records `frame_rate = 60`
  as accepted with no effect.
- **Enhancements page.** `dev_menu.c` has ROOT / WARP / FINISH AREA /
  CHEATS / OPTIONS / ENHANCEMENTS. Enhancements holds these rows; every row
  but RENDERER and DISPLAY is gl only:
  - RENDERER (ORIGINAL / GL);
  - RESOLUTION (NATIVE..4X);
  - DITHER (AUTO/OFF/ON);
  - VSYNC (DEFAULT/ON/OFF; DEFAULT is the absent key);
  - DISPLAY (WINDOW/FULLSCREEN; it shows the mode in effect, Game Mode's
    automatic fullscreen included);
  - PRESENT (FIT/INTEGER);
  - WIDESCREEN (OFF / 16:9 HOR+ / 16:10 HOR+; G3, gl only: writes `[video] aspect`).

  Each change is written to `config.ini` one key at a time
  (`bfm_plat_config_write_key`) and applies on the next launch.
  `tests/dev_menu_probe.c` is the parity model: the menu is browsed and
  changed with every cheat off, and zero guest bytes change over 1000
  VBlanks.
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
   Alienware results are below. These measurements do not establish
   per-frame GPU headroom or guarantee real-time performance at 4x.
2. **Software rasterising costs guest-thread time.** The psycross bridge
   is 9 points faster unthrottled than the cpu path (median 87 % vs 78 %)
   although its present is 4x longer: the cpu rasteriser's per-pixel
   `store_vram` runs on the emulation thread and is invisible in
   `present_ms`. Moving drawing to the GPU is itself a speed-up.
3. **Rendering headroom is large.** The low mean present cost of the window-sized
   PsyCross frame suggests headroom, but does not measure 4x scale or a
   post-process pass. Those need their own timings; isolated GL bench
   results cannot establish real-game performance.
4. **Capture overhead for before/after videos is 4 ms per field**
   (`present_ms` 4.1 to 4.5 in the showcase takes with `bfmcap.so`
   readback + x264), so before/after captures must be compared by picture,
   not by speed.

### Alienware baseline (completed 2026-10-01)

The previously dispatched job `20260930-184759-bfm-2175-gfx-baseline2-715342`
finished (wrapper rc=0). The same script ran on the Core Ultra 9 290HX with
RTX 5070 Ti Laptop GPU, NVIDIA 615.71.09, OpenGL 3.3. Raw log:
`~/release-staging/bfm-gfx-2175/baseline-alienware-20260930-184759-bfm-2175-gfx-baseline2-715342.log`.

| Run | PERF windows | Speed min / median / max | present_ms median (max) | median idle |
|---|---|---|---|---|
| cpu_unthrottled | 17 | 85 / 100 / 130 % | 0.11 (0.36) | 0 % |
| cpu_throttled | 16 | 82 / 96 / 109 % | 0.12 (0.40) | 0 % |
| psycross_unthr | 18 | 91 / 115 / 136 % | 0.48 (4.87) | 0 % |
| psycross_thr | 16 | 89 / 100 / 114 % | 0.51 (5.09) | 5 % |
| gl_unthr | 0 | refused before CRT, rc=2 | n/a | n/a |

Playable-path runs ended at the planned 170 s timeout (rc=124); this is a
bounded performance sample, not a clean-exit or regression acceptance test.
`PERF` reports means over 600 fields, not individual frame times or GPU
query timings. Both hosts still refuse the GL path before gameplay.

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

Also cheap and worth doing first: **frame pacing**. PsyCross sets the swap
interval only in `PsyX_BeginScene` (`g_cfg_swapInterval = 0`, so 0 every
frame). Only the bridge + psycross renderer calls it. The cpu path
(`gpu_psycross.c`, `SDL_GL_SwapWindow` direct) and bridge + gl never call
it, so their interval is whatever the driver gives a new context. The
Enhancements VSYNC row (G2, gl only) sets 0 or 1 explicitly; DEFAULT leaves
the driver's value.

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

**G3 status (2026-10-20, branch claude/gfx-ws).** The Enhancements page has a WIDESCREEN row: OFF, 16:9 HOR+ or 16:10 HOR+, gl only.
- It writes `[video] aspect`, and `gpu_bridge_attach` opens the gl renderer at that aspect.
- The existing scene-slot margins then carry the extra columns.
- Anamorphic is not offered, because it needs the GTE hook.
- Culling fixes are not done, so expect pop-in at the sides.
- Evidence: ~/release-staging/bfm-gfx-ws, holding the s16 identity leg and the 4:3 vs 16:9 screenshots.

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

**G4 status (2026-10-20, branch claude/gfx-msaa).** MSAA is built for the gl renderer, as the config key `[video] msaa = 0|2|4|8` (typed, so `save_file` keeps it). Absent or 0 is off, and off is the renderer as it was. The ENHANCEMENTS row is not wired yet.
- **Effective samples.**
  - The request is clamped to `GL_MAX_SAMPLES` and `GL_MAX_COLOR_TEXTURE_SAMPLES` (`bfm_gl_msaa_effective`), then halved until the VRAM target's multisample colour fits 256 MiB at the internal scale.
  - The driver may allocate more than it is asked for (llvmpipe turns 2 into 4), so the renderer reports what the framebuffer holds: `GL_MSAA requested=N effective=M`, once, whenever the key is present (0 included). A `GL_MSAA note:` line says what was clamped or why MSAA stayed off, and `GL_MSAA stats ...` at shutdown counts the resolves, snapshots, readbacks and stencil builds that ran.
  - A missing entry point, a shader that does not link or an allocation that fails leaves MSAA off, with the single-sample executor untouched.
- **Targets.**
  - Every scene slot and the VRAM target gets an RGBA8 multisample texture and an FBO that all draws render into. The window overlay stays single-sample.
  - A target's single-sample texture is its resolved image. SNAPSHOT, RESOLVE/readback, `finish` and present first resolve the rect they need into it (`glBlitFramebuffer`, identical rects), so they all see box-averaged samples.
  - The mask-check stencil is a multisample renderbuffer, built per sample: one pass per sample under `GL_SAMPLE_MASK` over the target's alpha. A mask-check draw over a mask-set polygon edge therefore keeps exactly the samples the polygon covered.
- **Draw program.** It is derived at run time from the single-sample shaders by nine text patches, each asserted to match exactly once, so the single-sample strings are never edited.
  - There is no half-pixel shift. The single-sample path shifts geometry by half a device pixel so that a pixel centre lands on the PS1's integer sample point. With samples spread over the pixel that would blur every sprite, glyph and tile border. Without it a pixel-aligned rect covers whole pixels and only polygon edges blend.
  - The varyings are `centroid`, and the 1x integer barycentric formulas run only for a pixel whose integer position is inside its triangle (the pixels the PS1 draws). Fringe pixels keep centroid values and never fetch the neighbouring atlas texel.
  - The derivative correction of the replacement coordinates goes, because it undid the shift.
- **Caveats.**
  - The resolve averages samples. A RESOLVE into the VRAM mirror (StoreImage, or a CLUT/paletted page fed by a render target) holds blended colours on polygon edges, and the mask bit there is the majority of the pixel's samples. Interior pixels, whose samples all agree, are exact.
  - At internal scale above 1 the sample point of a gradient or a texel moves by half a device pixel, so interior values change too, by one step. In the 2x probe that is 3565 interior pixels of the Gouraud scene and 1626 of the textured one, with a largest channel difference of 9 of 255. Flat colours and pixel-aligned geometry are unaffected at any scale. This is a real gap against "only polygon edges change", and the in-game gates run at 1x. MSAA is redundant above 3x anyway.
  - The 2x request holds 4 samples on llvmpipe.
- **Config path in the live game.**
  - `native_boot.c` copies only `internal_scale` and `dither` from its private read of config.ini into the config the renderer sees.
  - Until it also copies `msaa` (`cfg->msaa = file.msaa;` in `enhancements_from_file`), `renderer_gl.c` reads the key from the user's config.ini itself. That bridge is marked TEMPORARY in the code.
- **Tests.** `tests/bfm_gl_msaa_probe.c`, built and run by `tests/test_bfm_gl.py` on a real GL 3.3 core context made through SDL (a display, xvfb or offscreen EGL, no OSMesa).
  - At 1x (and for flat colours at 2x) polygon scenes differ from the single-sample image only within two pixels of a silhouette edge. At 2x the Gouraud and textured scenes also change interior pixels by at most one step (see Caveats).
  - Pixel-aligned shapes are identical over the whole image.
  - A texture with a magenta frame shows no magenta (no bleed).
  - The per-sample mask, the snapshot and readback of resolved data, present, `set_msaa(0)`, the GPU clamp and the memory fit are all checked.
  - With `BFM_GL_BASE_DIR` set to a checkout from before MSAA, msaa = 0 hashes equal to that tree's executor, scene by scene.
  - `tests/bfm_gl_sdl_smoke.c msaa N` covers the renderer glue: the config field, the log line and StoreImage.
  - The OSMesa exec level is unchanged and was not run (Mesa 26 has no OSMesa).
- Evidence: ~/release-staging/bfm-gfx-msaa.

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

## 7. Resumed implementation evidence (2026-10-01)

The GL startup refusal was traced to context identity, rather than GPU
capability: `gpu_dma_healthy` delegates to the original PsyCross backend,
whose `valid` requires its window and GL context to remain current. The
GL renderer now borrows an already-current SDL window/context and owns
a new pair only for standalone clients. Shutdown preserves borrowed
resources and balances its own SDL video reference.

Verification: `python3 -m pytest -q tests/test_bfm_gl.py`: **5 passed**,
including standalone and borrowed-context SDL rendering/VRAM/scale tests,
OSMesa executor comparisons, and core tests. Native boot built successfully.
A private headless, lane-OFF, 45-second run selected `renderer=gl`, passed
DMA2 initialization, loaded title assets and reached scene initialization
without a refusal. It ended by the planned SIGTERM timeout (rc=124),
reported `EXECUTION_BOUNDARY reason=HOST_STOP`, and completed GPU teardown
(`graphics_init=RETURNED blank_presented=1 gpu_removed=1`). Evidence:
`~/release-staging/bfm-gfx-2175/context-boot/run.log` and
`build-gl-context.log`. This proves the startup fix; it does **not** prove
playable rendering, picture fidelity, or all-off frame-hash parity.

The existing capture shim reads PsyCross's `vram[]`. That array is not the
GL backend's VRAM mirror, so comparing its hashes between CPU and GL would
be invalid. A GL parity fixture must read the active renderer's VRAM through
`bfm_plat_renderer_download_vram`, or compare presented pixels. The stage-0
fixture proposal above needs this correction before it is implemented.

### Real GPU comparison: startup passes, picture gate fails

New private blizzpc runner job (not a rerun of either baseline):
`20260930-192219-bfm-2175-context-compare-1991019`, wrapper rc=0, 151 s.
Candidate code: `263cead32f`, optimized native lane ON; binary SHA256:
`16ebc3f4553dee5517687b7f836014b377917b73bab96f7bee21b01b2e9d8618`.
CPU and GL ran sequentially for 75 s each with isolated XDG directories,
null audio, cards disabled, offscreen SDL, the same input script and the
village warp harness. Both native exits were the planned timeout rc=124;
both logged HOST_STOP and orderly GPU teardown. There were zero
RUN_REFUSED / CHECKPOINT_REFUSED / IRQ_DISPATCH_REFUSED markers. Native-lane
`overlay refused` counters are digest/class fallback counts (CPU 873,
GL 956), not execution acceptance; they are not described as zero.

Both routes entered 3005 at guest VBlank 1183, sent the warp at 1845 and
entered village 1010 at 2261. Same-swap-index PNGs 1800 and 2400 were
retrieved and compared; frame 2400 was inspected visually on both paths.
These are rendered-picture comparisons, not a guest-RAM or active-VRAM
parity fixture.

| Swap index | Different RGB pixels / 1,228,800 | Mean absolute channel error (0..255) |
|---|---|---|
| 1800 | 187,790 | 12.078 |
| 2400 (village) | 1,218,860 | 37.930 |

The GL village image shows a white strip at the top, different framing and
texture appearance. It therefore **fails** the proposed CPU/GL 1x picture
parity gate. The CPU presenter contains a draw-clip-page scanout workaround
(`gpu_psycross.c:blit_vram`) that can change its display origin and size;
the bridge derives its display from GP1 mode/origin and ignores range
commands 06/07. These are concrete paths to investigate, not a proven sole
cause and not a reason to silently copy a workaround into the GL renderer.

Capture-instrumented PERF window medians: CPU 2.190 ms, GL 4.295 ms
(maxima 2.26 and 5.21 ms; four 600-field averages each). Readback/PNG work
is included. These are not per-frame timings, a pure GPU comparison, or
an enhancement performance claim.

Additional gates: `ctest --test-dir build -R
'dev_menu_model|gpu_device|gpu_backend' --output-on-failure`: 2/2 passed
(dev_menu_model and gpu_device_boundary actually matched). Retail guard:
`python3 tools/check_port_retail.py build/lanes/legion-fast`: 7 files,
0 problems. Native build and optimized native-lane build succeeded.

Owner-local evidence: `~/release-staging/bfm-gfx-2175/context-compare/`
(run logs, frame counts, PNGs, pixel-comparison.json), the complete
`context-compare-evidence.tar.gz`, the job script and build/guard logs.
No jobs remain running for this comparison. No release, tag or push.

**Task remains unfinished.** Stage 0 now passes startup and a village run,
but its renderer-picture/parity work, active-renderer VRAM fixture,
per-frame measurements, config wiring and Enhancements page remain open.
No new menu options, FSR, 60 fps interpolation, HD packs, AA/AF or
widescreen-culling acceptance is claimed. The original CPU path is unchanged
by the context fix; full game/save/replay all-off parity has not been measured.


### Active-renderer diagnostics and native presentation filtering (handoff 51dd2f4e)

The exit display/full-VRAM dump now reads `bfm_plat_renderer_download_vram`
when the GPU bridge is active, flushing the bridge's pending primitives first.
The CPU route keeps its existing PsyCross readback. There is no diagnostic
fallback to PsyCross VRAM when a bridge read fails. `VRAM_SOURCE` records the
source, controller display rectangle, and inclusive drawing-area coordinates.
The pre-existing display-dump alternate-page heuristic remains: the display
PNG is an inspection aid, not a canonical scanout or parity hash. Full-VRAM
PNGs compare RGB555 color only; they do not retain the mask/STP bit.

A new sequential blizzpc job, `20260930-203335-bfm-2175-active-vram-2826574`,
used the diagnostic candidate (binary SHA256
`4c9744185c76144c5bb32f41f043ea40fb79e170ae4728e5a0504dedcf38011e`).
Both CPU and GL reached village 1010, stopped at `IN_GAME_TARGET` 1250,
reported 168789 GTE writes and matching logged camera RAM, and captured 2389
swaps. Both returned 143 for the intentional SIGTERM stop; wrapper rc=0.
Zero RUN_REFUSED / CHECKPOINT_REFUSED / IRQ_DISPATCH_REFUSED markers.
Native-lane overlay counters were verified=285, refused=685 on both routes;
this remains a hybrid runtime, with CPU fallback. Null audio, disconnected
cards, isolated XDG paths, and headless offscreen SDL were used. No owner
foreground input, settings, or saves were changed.

At this stop both controller displays were `(0,0,320,240)`, while both drawing
areas were `(0,250)..(319,469)`. The full-VRAM images show 320x220 game regions
at y=10 and y=250. For this nonoverlapping state the CPU presenter's existing
workaround selects `(0,250,320,220)` and stretches it to the window; GL selects
the GP1 page `(0,0,320,240)`, retaining its 10-line top/bottom border regions
and showing the other buffer. This establishes a concrete source for border,
framing and buffer-age differences. It does not establish that the CPU
workaround is accurate PS1 scanout. Any compatibility implementation needs an
explicit host scanout contract and tests, rather than altering guest GP1 state
or discarding GL scene targets by changing their dimensions during present.

Even matching the drawing rectangles does **not** produce color parity:

| RGB555 region | Different RGB pixels | Mean absolute RGB channel error |
|---|---|---|
| Full VRAM | 76698 / 524288 | 4.225 |
| Drawing region y=10 | 36780 / 70400 | 9.887 |
| Drawing region y=250 | 36718 / 70400 | 9.984 |

These are exit-state RGB comparisons, not per-frame hashes or full guest-RAM
parity. A further source-level mismatch to investigate is texture modulation:
`gpu_controller.c` truncates `(channel5 * color8) >> 7`, while the GL shader
normalizes by 31 and modulates in RGB8 before readback quantization. Existing
GL executor tests compare against that normalized reference; their success
does not prove agreement with the actual CPU controller's game rendering.

Separately, GL scene/VRAM presentation and packed movie-image presentation
now use nearest filtering, matching the reference presenter's texel-preserving
policy and preventing interpolation across native pixel/page boundaries.
HD replacement textures retain their existing filtering. Added OSMesa pixel
edge assertions fail against the previous executor (three failed assertions)
and pass against the change. `tests/test_bfm_gl.py`: 5 passed; native and
optimized native-lane builds passed; two focused CTests passed; optimized
retail guard checked 7 files with 0 problems. The village runner candidate
above predates this filtering change: no post-change village picture,
performance, or complete parity acceptance is inferred from these tests.

Evidence stays owner-local under `~/release-staging/bfm-gfx-2175/`:
`active-vram-local/`, `active-vram-remote/` (logs, PNGs, result, binary hash,
`active-vram-comparison.json`), `active-vram-job.sh`, build logs, and
`nearest-baseline-test.log`. Retrieved `active-vram-evidence.tar.gz` SHA256
`5ac0b9096b9dc9fcb1bf114bc884a953166a0506d488e1ad399d40eda5e2ffd7`
matched the runner's readback. No runner jobs remain for this diagnostic.

Stage 0 remains open on scanout compatibility, integer/raster/color agreement,
and a deterministic per-frame active-renderer fixture. The Enhancements menu
and later feature stages remain unimplemented. No release or publication is
appropriate while this renderer gate fails; native conversion stays deferred.

### Integer sample points and controller parity (handoff 9139aade)

The two active-VRAM dumps above explained the colour mismatch once compared
pixel by pixel (320x220 drawing region at y=250): 47.8% of the GL pixels
equal the CPU pixel at the same position, 18.7% equal the CPU pixel one to
the right, 13.4% the one below, 6.5% the one diagonally below-right, and
under 1% any neighbour in the other directions. GL evaluates coverage,
texture coordinates and colours at fragment centres (x+0.5, y+0.5); the PS1
and `gpu_controller.c` sample the integer position (x, y). With textures
near one texel per pixel the half-pixel offset selects the next texel about
half the time. The 4x4 dither position showed no correlation (the game does
not enable dithering; neither renderer dithered). Two smaller terms were the
float modulation `t/31 * c/255 * 255/128` (rounded; the controller computes
`(texel5 * colour8) >> 7`) and Gouraud colours rounded rather than truncated.

Commit `4156941003` changes the gl renderer only:

- geometry on render targets moves by half a target pixel
  (`u_half = 0.5 / scale`), so the first sub-pixel's centre of every native
  pixel is the integer sample point; coverage follows the PS1 top-left rule,
  readback takes that sub-pixel, the window overlay is unchanged;
- on a 1x target the fragment shader computes texture coordinates and
  colours with the controller's integer barycentric formula from flat
  per-triangle vertex data (vertex 32 -> 68 bytes), independent of GPU
  interpolation precision; scales above 1 interpolate with a 1/512 epsilon
  before floor;
- VRAM texels and vertex colours take the PS1 integer route (truncated 8-bit
  colour, `((t5 << 3) * c8) >> 7`, dither on that value, top five bits
  written as `c5/31`); HD replacement/snapshot texels keep 8 bits and sample
  where the unshifted geometry did.

`tests/bfm_gl_ctl_probe.c` (commit `38ebac7941`) is the fixture the stage-0
plan asked for, at primitive level: one synthetic GP0 stream (4/8/15-bit
pages, CLUTs, per scene 48 random prims of every kind over flat backdrops,
opaque and semi-transparent) through the real `gpu_controller.c` and through
bridge -> batch -> gl executor on OSMesa, read back through the renderer's
resolve path, every differing pixel classified. Twelve scenes, 2304 prims,
1,843,200 pixels, at 1x:

| | before `4156941003` (6 scenes) | after (12 scenes) |
|---|---|---|
| opaque pixels differing off polygon edges | 37,187 / 460,800 | **0 / 921,600** |
| semi-transparent: coverage, mask or >1 step | 39,420 | **0** |
| semi-transparent: one 5-bit step (8-bit blend, D-033) | 4,359 | 16,226 |
| edge-rule pixels (controller inclusive vs top-left, D-030) | 4,456 | 5,754 |

TILE and SPRT rows are bit-exact including the mask bit. At internal scale
3 the float path leaves 6 of 153,600 opaque pixels one texel off (D-033).
`tests/test_bfm_gl.py`: 8 passed (new `test_exec_vs_controller`);
`tests/test_bfm_gpu_bridge.py`: 2 passed; native and optimized native-lane
builds, retail guard (7 files, 0 problems) and the focused CTests pass.

Found on the way and recorded, not changed (they are Original-path
behaviour or need their own gate): the controller keeps the E1 texpage when
a textured polygon carries its own, while the hardware and the bridge make
the polygon's texpage current for later rects and untextured blends; the
controller ignores the texture window (E2); its inclusive edge rule draws a
quad from x0 to x1 one pixel wider than the PS1 (D-030). In the gl renderer,
the textured mode-2 two-pass split orders fragments by STP within a draw,
which differs from primitive order where mixed-STP prims of one draw overlap
(D-036; not seen in the game). The CPU rasteriser is unchanged; the all-off
picture is unchanged.

Fixing D-030 in `gpu_controller.c` (top-left rule, polygon texpage state,
E2) would make the two paths agree exactly and is a small change, but it
alters the shipped Original picture by those edge pixels, so it is proposed
for the owner as a separate fidelity fix with its own before/after gate
rather than done inside this enhancements task.


### Scene coherency checkpoint (handoff 85e92dce)

The integer-sampling candidate `38ebac7941` completed the village comparison
in job `20260930-214900-bfm-2175-exact-vram`. The existing evidence in
`~/release-staging/bfm-gfx-2175/exact-vram-remote/` measures 916 / 70400
RGB pixels different in the y=250 drawing region (1.301%, MAE8 0.2394),
down from 36718 / 70400 before integer sampling. Of those 916, 591 differ
by at most one 5-bit step. The remaining differences have not all been
attributed; this is not pixel parity. Page 0 additionally has 3200 pixels
with a maximum 31-step difference in its top border.

The pending scene-cache fix was recovered and completed as `060cc912c8`:
resolve dirty pixels before evicting a scene slot, seed newly claimed slots
from VRAM before partial drawing, and flush scene resolves before display
size/margin changes reallocate targets. This protects untouched border pixels
and preserves the mask bit. It does not change the CPU renderer or select a
new scanout policy.

New executor regressions exercise partial drawing, three-page slot eviction,
reclaim and display resize at 1x and 3x, comparing all 16 bits across a
960x240 VRAM region. They pass with the fix and fail four pixel-equality
assertions against the preceding core (with the new resize-resolve entry
point replaced by a no-op for the baseline build). Six GL tests, two GPU
bridge tests, two focused CTests and the default native build pass. The
optimized candidate had already built before handoff; its executable SHA256
remains `629dd3af031c4ae5811285247e0249da976ff5d7e91cd5f1dd7aeb3755eaea60`.
The optimized retail guard checked seven files with zero problems.

The pre-handoff archive `coh-38ebac7941-wip-candidate.tar.gz` contains that
production change (later edits add tests/docs only). Its SHA256
`e34e0744a34e3a06453568f7d546852a51e89fe6bd69a01db23f03fa8146e768`
was verified again by runner readback. Only one comparison job was submitted:
`20260930-221700-bfm-2175-coh-vram.sh`. At this checkpoint it is still queued
behind the runner memory floor (about 4.7 GB available versus a 5 GB gate),
with no BFM job running. Do not resubmit it. Expected output is
`~/devbox-runner/work/20260930-221700-bfm-2175-coh-vram/coh-vram-evidence.tar.gz`
on blizzpc. Retrieve and hash-verify that archive, then compare both active
VRAM regions and matched-stop logs before claiming a village improvement.

Job `20260930-221700-bfm-2175-coh-vram` later ran (runner start 22:38 CDT;
both legs reached `[WARP] arrived 1010.0 ... vblanks=416` and
`HOST_STOP source=IN_GAME_TARGET`; both exited 143 from the post-stop timeout,
as in the earlier jobs). The runner extracted candidate SHA256 `629dd3af...`,
the optimized build above. Evidence archive SHA256
`8ae762e38626c26d93d1b9ca912edee6490c8143dbc148d63e961f8a53a1b5e0`
matches on runner and owner box; it is unpacked in
`~/release-staging/bfm-gfx-2175/coh-vram-remote/` with
`exact-vram-comparison.json`. CPU vs gl active VRAM at the matched stop:

| region | before (`38ebac7941`) | after (`060cc912c8` production change) |
|---|---|---|
| whole VRAM 1024x512 | 5043 px (0.962%, MAE8 1.6205) | **1843 px (0.352%, MAE8 0.0641)** |
| page 0 (0,0) 320x240 | 4127 px (5.374%, MAE8 10.84) | **927 px (1.207%, MAE8 0.2184)** |
| page 1 (0,240) 320x240 | 916 px (1.193%) | 916 px (1.193%) |
| drawing y=10 320x220 | 927 px (1.317%) | 927 px (1.317%) |
| drawing y=250 320x220 | 916 px (1.301%) | 916 px (1.301%) |

The fix removed the 3200 page-0 border pixels (the up-to-31-step stale-scene
loss). Every remaining difference (927 + 916 = 1843) lies inside the two
drawing regions and is unchanged by this fix; 1192 of them are one 5-bit
step. This is the open rasterisation residual, not parity. Frame capture
indices differ by two between the legs after the warp (e.g. 691 vs 693);
the comparison is of the final active VRAM only, not per-frame parity.

Logs are owner-local in `~/release-staging/bfm-gfx-2175/coh-*-tests.log` and
`coh-build-default.log`. Real-game coherency validation, scanout compatibility,
per-frame parity, performance acceptance and the Enhancements menu remain
open. No private build was published at this checkpoint. Production execution
remains hybrid with original CPU interpretation; native conversion remains
tracked separately and deferred.


### Exact semi-transparency and 5-bit display (gfx-g3, 2026-10-20)

**Root cause of the one-step class.** The gl executor blended in normalised RGBA8 space:
- the front was written as `c5/31`;
- the back was read as stored;
- the factors were 0.5/0.5 (mode 0) and 0.25 (mode 3).

Modes 0 and 3 therefore kept the fraction that the PS1 truncates, `(B + F) >> 1` and `B + (F >> 2)`, so they could round up one 5-bit step (D-033). In the controller fixture (`tests/bfm_gl_ctl_probe.c`) these were the "semi-transparent: one 5-bit step" pixels:
- 7,924 at 1x with the test's 6 scenes;
- 16,226 with 12 scenes.

**The fix: commit `30be401ced`, gl renderer only.** A target byte `8b + r` (`r < 8`) holds the 5-bit back `b`, and readback is `>> 3`. The shader writes a 5-bit front `f` as a whole number of steps:

| mode | written |
|---|---|
| 1 | `8f + B` |
| 2 | `B - 8f` |
| 3 | `8(f >> 2) + B` |
| 0 | `4f + B · 127/255`, using the dual-source factor |

For mode 0, `4(b + f) + r/2 - (8b + r)/510` rounds into step `(b + f) >> 1` for every `r`. All four modes are therefore exact for any stored byte, including the low bits that earlier blends leave behind.
- The C model is `bfm_gl_blend_state`, `bfm_gl_blend_byte` and `bfm_gl_blend_emulate`.
- 8-bit fronts (HD replacement texels) keep the plain factors.
- Opaque writes are unchanged.

**5-bit display: commit `afb019abae`.** After an exact blend, a byte can keep low bits; mode 1 leaves `8f + B`, for example. The scene present therefore shows each byte as `(byte >> 3)/31`, which is `c5 · 255/31` on screen. That is exactly the colour the Original path displays for the same VRAM pixel.
- Opaque bytes are already that value, so nothing changes for them.
- Movie images, and any frame while an HD replacement is live, keep 8 bits.

**Results** (gcc 15.2; GL on steamrt4 OSMesa/llvmpipe; local devbox):

| check | before (`3e639e8352`) | after (`afb019abae`) |
|---|---|---|
| core model: modes 0-3 vs PS1, 1024 pairs each | 254 / 1024 / 1024 / 213 (worst 1) | **1024 each**; any stored byte 32768/32768 |
| exec probe (real GL): modes 0-3 vs PS1, of 992 | 228 / 992 / 992 / 183 (worst 1) | **992 each**. The C model now matches GL on every pixel; mode 0 was 911/992. |
| controller fixture 1x, 6 scenes: semi one-step | 7,924 | **0** |
| controller fixture 1x, 12 scenes: semi one-step | 16,226 | **0** |
| controller fixture 1x: opaque non-edge / semi >1-step | 0 / 0 | 0 / 0 |
| controller fixture 1x, 12 scenes: edge-rule pixels (D-030, the controller's inclusive edges) | 5,754 | 5,576 |
| controller fixture 3x: semi one-step | 7,924 | **0** |
| present: back 20,3,30 + mode-1 front 9,1,7 on screen | raw bytes 237,33,255 | 239,33,255 (= Original) |

**Village matched stop, run on this devbox.** This is the coherency job's recipe: test warp 1010:0, idle input, in-game frame 1250, then `MUSASHI_DUMP_VRAM_FULL`. The runs were headless (offscreen SDL plus EGL surfaceless, Mesa 26 llvmpipe) and used one binary per side:
- base `3e639e8352`, sha256 `b03fc1f3...`;
- after `afb019abae`, sha256 `9a6d34e4...`.

All three legs reached the same state:
- `[WARP] arrived 1010.0 ... vblanks=416`;
- identical native-lane counters;
- `VRAM_SOURCE display=0,0,320,240 clip=0,250,319,469`.

The cpu leg is the Original renderer from the base binary. This change does not touch the cpu path.

| cpu (Original) vs gl, RGB555 | before | after |
|---|---|---|
| whole VRAM 1024x512 | 2931 (0.559%) | **336 (0.064%)** |
| drawing area y=10, 320x220 | 1491 (2.118%) | **173 (0.246%)** |
| drawing area y=250, 320x220 | 1440 (2.045%) | **163 (0.232%)** |

- **Step histogram, 1 / 2 / 3 / >3 steps:** before 2540 / 106 / 22 / 263, after 22 / 24 / 30 / 260.
- **Brightness:** gl brighter than cpu on 2731 pixels before and 132 after. The truncated fraction is gone.
- **Base gl vs new gl:** 2661 pixels changed, all of them darker, by 1 or 2 steps.
- **The 336 that remain:**
  - 150 equal a neighbouring cpu pixel, mostly the right one (86) or the one below (39). That is the shape of the controller's inclusive edges (D-030).
  - 335 sit on a colour boundary of the cpu image; 1 is interior.
- **Other hosts:** these local numbers are not the blizzpc figures above (1843 pixels, older candidate `629dd3af`). Different binaries and hosts reach slightly different village frames.

**Still open:**
- The edge-rule pixels belong to the controller. Its inclusive edges draw one pixel wider than the PS1; that is D-030, together with the polygon texpage state and the E2 texture window. Fixing them changes the shipped Original picture, so it stays a separate owner decision with its own gate.
- At 3x, 20 opaque pixels and 5 semi pixels with more than one step remain in the 6-scene fixture, before and after. They come from the float path's texel rounding (D-033's float half), which this change does not touch.
