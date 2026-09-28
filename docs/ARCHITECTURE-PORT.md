# Port architecture standard (Brave Fencer Musashi)

This follows the owner's port standard of 2026-09-28, as written up in
`~/dev/Parasite-Eve-Decompilation/docs/ARCHITECTURE-PORT.md`: all ports on
this dev box share one pattern. The goal is a port people can customize,
with better graphics, mods and cheats.

## Layers

```
 game C (matched decomp TUs under src/, native lane / hand ports in pc_port/)
   │  calls ONLY the bfm_plat_* interfaces below (no PsyCross, no host APIs)
 ┌─┴──────────────────────────────────────────────────────────────────────┐
 │ platform interfaces (pc_port/platform/bfm_plat*.h; umbrella bfm_plat.h)│
 │  renderer · audio · input · disc/storage · timing · mods · config      │
 └─┬──────────────────────────────────────────────────────────────────────┘
   │  one or more backends per interface, picked by name from the config
 backends: PsyCross (MIT, fetched, not committed) · in-house HLE (musashi_*
           device owners in pc_port/, null/image/scripted built-ins)
           · later: OpenGL/Vulkan renderer, other audio devices
```

Rules:
1. Game code never includes a PsyCross header, a host/OS header or a Sony
   Psy-Q header. Where the retail code called a Psy-Q library function
   (`LoadImage`, `PutDrawEnv`, `DrawOTag`, `CdRead`, `CdSearchFile`, `VSync`,
   `PadRead`, …), the port calls a `bfm_plat_*` function with the same
   meaning, and a backend implements it. `tests/test_bfm_plat.py` checks
   that the core `bfm_plat*` sources include no SDL/GL/AL/PsyCross header.
   Only `pc_port/platform/backends/` may include them.
2. Interfaces are defined by **meaning, not by PS1 registers**. The renderer
   takes draw/display environments, semantic primitives
   (`BfmPlatPrim`: flat/gouraud/textured tris and quads, lines, tiles,
   sprites, fills) and VRAM uploads, not GP0 words. That lets a modern
   renderer upscale, replace textures, widen the view or interpolate
   frames. The PS1-accurate path is one backend among several.
3. No Sony Psy-Q code or tables in any backend. Game data is never committed
   or shipped. It is read from the user's disc image at runtime.
4. Backends can be swapped without touching game code. Selecting an unknown
   renderer, audio or input backend falls back to the built-in `null`
   backend, so headless runs and tests always work. A disc backend has no
   fallback: a missing disc is a user-visible error.

Return convention: `BFM_PLAT_OK` (0), or a negative `BfmPlatResult`. The
older `musashi_*` device owners return 1 for success, and the backends
that wrap them translate.

## Interfaces

| Interface | Header | Covers | Backends now |
|---|---|---|---|
| renderer | `bfm_plat_renderer.h` | draw env / disp env, primitive lists, VRAM upload/download, present, output (window, internal scale, aspect, frame rate), overlay text | `null` (built-in: real 1024x512 VRAM, FILL, upload/download), `psycross` (`backends/renderer_psycross.c` → PsyCross libgpu) |
| audio | `bfm_plat_audio.h` | 44.1 kHz s16 stereo MAIN (SPU mix) and CD (XA/CD-DA) streams, volume, pause, status; drops PCM during fast-forward | `null` (built-in, counts frames), `sdl` (`backends/audio_sdl.c` → `pc_port/audio_sdl.c`) |
| input | `bfm_plat_input.h` | two pads as PS1 buttons (active-high) and analog, `[input]` bindings from config, port hotkeys (fast-forward, console, cheat menu, pause, screenshot, quit), console text/key queue, PS1 SIO wire bytes for the pad shim | `null` (built-in "scripted": state is set by code, for tests and the route autopilot), `sdl` (`backends/input_sdl.c`: keyboard + SDL GameController) |
| disc/storage | `bfm_plat_storage.h` | sector reads (2048 / 2324 / 2340 / 2352), MSF↔LBA, ISO9660 file lookup, whole-file reads through the mods file hook, memory cards (128 KiB `.mcd` per slot, atomic save) | `image` (built-in: user `.cue`/`.bin` raw or `.iso`), `pinned` (`backends/disc_pinned.c` → `pc_port/disc_media.c`, verified retail cue/bin by SHA-256) |
| timing | `bfm_plat_timing.h` | `VSync(n)` pacing at the NTSC field rate (1001/60000 s), resync after stalls, fast-forward speed (0 = uncapped), injectable clock | built-in host monotonic clock (POSIX `clock_gettime` / Win32 QPC) |
| mods | `bfm_plat_mods.h`, `bfm_plugin.h` | folder loader, event hooks, C plugins, script-runtime seam, hash-keyed asset replacement, texture decoders, texture dump, guest-memory binding | built-in (`.bfmi` decoder); `backends/texture_png.c` (`.png`, in-house on zlib) |
| console/cheats | `bfm_plat_console.h`, `bfm_plat_console_ui.h` | cheat registry (plugin callbacks, `cheats.ini` pokes), cheat-menu model, console commands, console text front end (scrollback, edit line, history, Tab completion) drawn via renderer `overlay_text` | built-in |
| game events | `bfm_plat_events.h` (events themselves in `bfm_plugin.h`) | event name catalog, guest-PC hook-site table for the native lane, `events` console command | built-in |
| config | `bfm_plat_config.h`, `bfm_plat_ini.h` | user INI file, CLI overrides, save-back, per-plugin sections | built-in |

The existing `pc_port/` device owners (`gpu_psycross.c`, `audio_sdl.c`,
`bios_input.c`, `disc_media.c`, `source_clock.c`, …) remain the
register-level HLE the native lane runs on. `bfm_plat` sits above them:
`audio_sdl.c` and `disc_media.c` are wrapped directly as backends. The
guest's own pad polling (`bios_input.c`, SIO) should read
`bfm_plat_input_pad()` + `bfm_plat_pad_to_wire()`. `source_clock.c` is a
modeled cycle count, not wall time, and stays separate from
`bfm_plat_timing`, which only paces presentation.

`bfm_plat_register_builtin_backends()` (`bfm_plat_backends.c`) registers
the backends compiled into a build: `-DBFM_PLAT_WITH_PSYCROSS`,
`-DBFM_PLAT_WITH_SDL_AUDIO`, `-DBFM_PLAT_WITH_SDL_INPUT`,
`-DBFM_PLAT_WITH_PINNED_DISC`. `-DBFM_PLAT_WITH_PNG` registers the PNG
texture decoder in `bfm_plat_init`. The default dependency-free build
registers none and runs on the built-ins.

### Input bindings

Bindings come from `[input]`. Each key names a target and lists host
inputs, comma-separated. A target with no key uses its default, and an
empty value unbinds it.

```ini
[input]
analog = 1                       ; report DualShock analog mode (sdl backend)
p1.cross = key:z, pad:a          ; defaults: p1 keyboard + pad 1, p2 pad 2 only
p1.l2 = key:q, pad:lefttrigger   ; axes: pad:lefttrigger, pad:-leftx, pad:+lefty
p2.start = pad:start
hotkey.fast_forward = key:tab    ; also console (`), cheat_menu (f1), pause,
hotkey.quit =                    ; screenshot (f12), quit (unbound)
```

Targets are `p1.`/`p2.` plus `select l3 r3 start up right down left l2 r2
l1 r1 triangle circle cross square`, and `hotkey.` plus `fast_forward
console cheat_menu pause screenshot quit`. The core parses these
(`bfm_plat_input_bindings_from_config`). A backend supplies only a resolver
from `key:NAME` / `pad:NAME` to its host codes, so a future non-SDL backend
gets the same config format. The `sdl` backend reads keyboard and
controller *state* after `SDL_PumpEvents`, and gets typed text and
controller hotplug through `SDL_AddEventWatch`. It never takes events off
the queue that PsyCross pumps. While the console is open, letter-key
bindings are ignored and pads report neutral to the game.

### Console front end

`bfm_plat_console_ui` is the text UI over `bfm_plat_console_exec`. The
console hotkey toggles it when `[debug] console = 1`. Text typed before it
opens is dropped. Input backends push text and editing keys
(`bfm_plat_input_push_text/_key`), and the frame loop drains them while
the console is open. It draws 12 scrollback lines plus the prompt through
`bfm_plat_renderer_overlay_text`, so any renderer that implements
`overlay_text` shows it. Keys: Enter, Backspace, Left/Right, Up/Down
(history), PageUp/PageDown, Tab (command completion), Esc.

### Lifecycle and the frame loop

```c
BfmPlatConfig cfg;
bfm_plat_config_defaults(&cfg);
char path[512];
if (bfm_plat_config_default_path(path, sizeof path) == BFM_PLAT_OK)
    bfm_plat_config_load_file(&cfg, path);          /* missing file is fine */
bfm_plat_config_apply_args(&cfg, argc, argv, used);
bfm_plat_init(&cfg);                  /* backends, disc, console, mods, BOOT */
bfm_plat_guest_memory_bind(&ram);     /* once guest RAM exists */
for (;;) {
    bfm_plat_frame_begin();           /* input poll + INPUT hook, hotkeys, FRAME_BEGIN */
    /* ... game frame: renderer / audio / disc calls ... */
    bfm_plat_frame_end(fields);       /* FRAME_END (cheats), cheat menu, present, VSync pacing */
}
bfm_plat_shutdown();
```

### Game-event hook points

These are named events the native lane fires when the game does them.
Payload structs are in `bfm_plugin.h`, names in `bfm_plat_events.c`, and
the retail sites in `bfm_plat_hook_sites.c` (`bfm_plat_known_sites`,
`bfm_plat_hooks_register_known`). Evidence paths are in
`vendor/bfm-decomp` (Druthulu's cleaned decomp of the same SLUS-00726
build, fetched separately) unless marked "repo".

| Event | Guest site | Symbol | Evidence | Payload fill | Confidence |
|---|---|---|---|---|---|
| `frame_begin` | `0x800189A8` | `func_800189A8` (per-frame pad poll: 2 pads, 0x4C records at `D_80078D98`) | first call in `main`'s inner loop, `src/boot.c:310` (`main` 0x80010178, `src/boot.c:277`); body `src/800.c:6042`, `PadGetState` at `src/800.c:6094`; also once per frame in the resident modal loop `src/md_MAIN_003/md_MAIN_003_jr_800D1E18.c:236` | none (action: `bfm_plat_frame_wait`) | high. The modal loop gets FRAME_BEGIN without FRAME_END |
| `frame_end` | `0x800184F0` | `func_800184F0` | called right before `VSync(*(s32 *)(p + 0xA3E8))`, `src/boot.c:372`/`:374`; body `src/800.c:5761`; no other caller | none (action: `bfm_plat_frame_hook_end`) | high |
| `room_enter` | `0x80128158` in any `SC*` overlay | `func_80128158` (location-overlay export stub 0 → `func_80128288`, a phase dispatch `D_8017E618[D_800B99F6]`, repo `src/overlays/main_0012/80128288.c`) | called every scene-loop frame by resident `func_800CF238`, `src/resident/resident.c:255`; phase 0 reached SC02/31's init `80128420` (repo `docs/MENU-BOOT-CONTINUATION.md`, "SC02 initialization routine") | fires on the edge into scene phase 0 (u16 `0x800B99F6` = state base+0xA3C6) or on an overlay change. area/room are parsed from the overlay name the native lane reports ("SC02_031" → 2/31) | medium. Phase 0 = init is observed for SC02/31 only |
| `room_exit` | `0x80011B7C` | `func_80011B7C(mode)` (set major mode base+0xA3C0, clear phase) | the scene loop leaves with `func_80011B7C(8)`, `src/resident/resident.c:261`; body `src/boot.c:950` | fires when `$a0 == 8` while an `SC*` overlay is selected | low. ~400 call sites, and mode 8 is not proven unique to scene exit |
| `save` | `0x8002B0B4` | `func_8002B0B4` (memory-card state machine; splat's `SaveLoadRoutine` is its case 0) | state 13 writes the slot's 0x300-byte game-state block, `src/800_b.c:301`, `:318`, then advances `D_800760AC` | fires on the edge into state 13 (s32 `0x800760AC`); slot = `$a1` | medium. A retried write could fire twice |
| `load` | `0x8002B0B4` | same | states 17/32 read that block, `src/800_b.c:486-488` | fires on the edge into state 17 or 32; slot = `$a1` | medium |
| `projection` | `0x8004923C` | `func_8004923C` = libgte `SetGeomScreen` (`ctc2 $a0, $26`, repo `src/main/8004923c.c`) | game init `func_80014444` runs InitGeom (`func_80047CB4`), then `func_8004923C(0x3E8)`, storing 0x3E8 in `D_80126950` (`src/800.c:1787`) | h = `$a0 & 0xFFFF` | high (exact instruction shape) |
| `projection` | `0x8004921C` | `func_8004921C` = libgte `SetGeomOffset` (`sll 16; ctc2 $24/$25`, repo `src/main/8004921c.c`) | called per draw buffer by the libgs offset routine `func_80052BEC` (repo) and by overlay camera code (`src/shared/ov/func_8017C530.h:14`) | ofx/ofy = `(int16)$a0/$a1` | high |
| `battle_start` / `battle_end` / `item_get` | TBD | none | see "Unsited events" below | none | needs runtime tracing |

**Unsited events: what was searched (2026-09-28).** There is no symbol,
comment or runtime note for battles or items in `vendor/bfm-decomp`
(ov_MAIN_012, resident/, shared/ov, md_*, the main-exe TUs) or in this
repository's docs. Candidates looked at and rejected:
- `func_8017CF3C` (ov_MAIN_012) formats the save-slot display. It gives the
  slot record layout: play time, time of day, HP and BP cur/max capped at
  999, money at +0x14 capped at 99999. It is a layout, not an event.
- `func_80029ED4` is a monotonic counter (`D_80078F08`, capped at
  9,999,999, which calls `func_8002A2D4` every 10 steps), not an
  acquisition.
- `D_80075CC0` is only the save staging copy (`func_8002AF70` /
  `func_8002B00C` copy 0x2DC bytes in and out). The live state's address
  comes from the save-menu modules' callers and wasn't traced.
- Every location overlay's phase-2 exit chooses `func_80011B7C(0x13)` or
  `func_80011B7C(4)` (e.g. `ov_SC02_000.c:374-376`). The meaning of the two
  modes (continue vs game over?) isn't established.

The next step is runtime tracing: watch the HP fields of the live state and
the money word for writes, then attribute the writer PCs. Low-confidence
guesses were not registered, because a wrong site fires wrong events for
every mod.

`tests/test_bfm_plat.py` pins these sites to their symbols, events and
confidence. When the vendor tree is present, it also checks that every
cited line still contains the cited code.

How the native lane uses them:
- `bfm_plat_guest_memory_bind` (RAM) and `bfm_plat_guest_regs_bind`
  (registers, for `$a0`/`$a1`). Then `bfm_plat_hooks_register_known()`.
- On overlay selection: `bfm_plat_hooks_set_overlay("SC02_031")`, or NULL
  for none. Sites at or above `0x80128158` (the location-overlay window)
  must name an overlay pattern (`"SC*"` or an exact name), because the same
  address is different code in each overlay. Registration refuses them
  otherwise.
- On entry to a guest function: `if (bfm_plat_hooks_has(pc))
  bfm_plat_hooks_at(pc);`.
- Frame sites are actions. The FRAME_BEGIN site calls `bfm_plat_frame_wait()`
  (input poll, hotkeys, and blocking while paused). The FRAME_END site calls
  `bfm_plat_frame_hook_end()` (pending screenshot, cheats, overlays). The
  game's own VSync → `bfm_plat_timing_vsync` does the pacing, and its own
  DrawOTag/present does the presenting.
- Direct emitters for hand-ported code: `bfm_plat_event_room_enter/exit`,
  `bfm_plat_event_battle`, `bfm_plat_event_item_get`, `bfm_plat_event_save`.

The `events` console command lists each event with its count and every
registered site with its overlay and hits.

### Widescreen

Config: `[video] aspect = 4:3 | 16:9 | 16:10` and `widescreen_mode = hor+ |
anamorphic` (`--aspect`; `widescreen = 1` / `--widescreen` mean 16:9).
The maths is in `bfm_plat_widescreen.c`, in 16.16 fixed point so every
backend rounds the same way. The PS1 display is always shown at 4:3,
whatever its pixel width.

- **hor+**: projection unchanged. The renderer shows a wider window with
  unstretched pixels. Visible width in display pixels is
  `disp_w * A / (4/3)`, centred: 428 wide starting at x = -54 for a
  320-wide display at 16:9, and 384 starting at -32 at 16:10. The
  PsyCross backend does this: with PGXP it maps the display unstretched
  into a window of any aspect, so the backend sizes its window to the
  aspect (`bfm_plat_widescreen_window`: 1280x720 at 16:9). Geometry the
  GTE projects past the 4:3 edges then becomes visible. Objects the game
  culls at those edges will pop at the sides; that is the known cost.
- **anamorphic**: after perspective division, screen X is squeezed around
  OFX by `k = (4/3)/A` (0.75 at 16:9, 0.8333 at 16:10), and the output is
  stretched to A. The game's culling stays correct, but 2D HUD elements
  are stretched. A GTE backend applies it with
  `bfm_plat_widescreen_sx_current(sx)` on every projected SX (RTPS/RTPT).
  The renderer must stretch. PsyCross can't, so `set_output` refuses
  anamorphic there and `bfm_plat_init` falls back to hor+ with a log line.
- The game's projection is known to the platform: hook sites at libgte
  `SetGeomScreen`/`SetGeomOffset` (table above) record H/OFX/OFY
  (`bfm_plat_projection_get`) and emit `BFM_EVENT_PROJECTION`. Retail sets
  H = 1000 once at init (horizontal FOV 18.2° across 320 px; hor+ 16:9 shows
  24.2°). `bfm_plat_projection_hfov_mdeg` computes these.
- Tests: `test_widescreen_projection_maths` checks every aspect, display
  width (256-640) and a range of SX values against exact fractions, plus
  the config keys and the projection hook sites.

### Pause, screenshot, quit

- **Pause** (hotkey, `pause` command, `bfm_plat_pause`): `bfm_plat_frame_begin`
  returns `BFM_PLAT_PAUSED`. The caller skips its game logic and still calls
  `bfm_plat_frame_end`, which presents, draws "PAUSED" and paces but emits no
  FRAME_BEGIN/FRAME_END, so cheats and plugins don't tick. Audio is paused.
  The hook-site path blocks in `bfm_plat_frame_wait` instead, so the guest
  frame loop doesn't advance.
- **Screenshot** (hotkey, `screenshot [PATH.png]`): reads the current
  display area (last `set_disp_env`, 15- or 24-bit) back through
  `download_vram` and writes a PNG with the dependency-free encoder in
  `bfm_plat_image.c` (stored deflate, so zlib isn't needed). The shot is
  taken before overlays are drawn. Files go to `[video] screenshot_dir`
  (default `screenshots`) as `bfm_NNNNN.png`, at the native display
  resolution.
- **Quit** (hotkey, `quit`): sets `bfm_plat_quit_requested()` for the main
  loop.

## Mod hooks

- **Folders.** Every directory in `[mods] dirs` (';'-separated, default
  `mods` next to the binary) is scanned at startup. A mod is a folder with
  `mod.ini`:
  ```ini
  [mod]
  name = hello
  version = 1.0.0
  priority = 100        ; load order: ascending priority, then folder name
  enabled = 1
  plugin = hello_plugin ; <mod>/hello_plugin.so | .dll | .dylib
  script = main.lua     ; handed to a registered script runtime
  ```
  Folders without a manifest are skipped, and duplicate mod names are
  ignored. Plugin and script names must be plain file names inside the mod
  folder.
- **Event hooks.** `BfmEvent` (numbering is ABI): `BOOT`, `SHUTDOWN`,
  `FRAME_BEGIN`, `FRAME_END` (frame tick), `VSYNC`, `INPUT` (editable pads
  and hotkeys), `BEFORE_PRESENT`/`AFTER_PRESENT`, `ROOM_ENTER`/`ROOM_EXIT`,
  `BATTLE_START`/`BATTLE_END`, `ITEM_GET`, `SAVE`/`LOAD`. Hooks run in
  subscription order, which follows load order. Hooks made by mods are
  dropped at mods shutdown, so an unloaded plugin never stays subscribed.
- **C plugins** (`bfm_plugin.h`, ABI version 1). A plugin exports
  `bfm_plugin_init(const BfmPluginHost *, BfmPluginInfo *)` and optionally
  `bfm_plugin_shutdown()`. The host table offers log, subscribe/unsubscribe,
  `guest_read`/`guest_write`, `register_cheat`/`set_cheat`,
  `register_command` and `config_get`. `BfmPluginHost` only ever grows at
  the end, so plugins check `abi_version`/`size`. Plugins can also be linked
  into the binary and registered with
  `bfm_plat_mods_register_static_plugin` (for platforms without dlopen, and
  for tests). Sample: `pc_port/mods/examples/hello`.
- **Lua** (optional, `-DBFM_PLAT_WITH_LUA`, `backends/script_lua.c`).
  `tools/fetch_lua.sh` fetches Lua 5.4.9 into the ignored
  `tools/third_party/lua`, verified against lua.org's published SHA-256.
  Each mod whose manifest names a `.lua` script gets its own `lua_State`.
  - Sandbox: base (no dofile/loadfile/load/require), table, string, math,
    utf8 and coroutine. No io, os, package or debug. Text chunks only.
  - Every load and callback runs under a 5M-instruction budget, so a
    runaway script errors out instead of hanging the game.
  - The global `bfm` table offers the same services as `BfmPluginHost`:
    `bfm.on(event, fn)` / `bfm.off(id)` with payload tables (input is
    editable: `pads[i].buttons`, sticks, `hotkeys`); `bfm.read8/16/32`,
    `write8/16/32`, `read/write(addr, n|s)`; `bfm.cheat{...}` (poke or
    `apply`/`on_toggle`); `bfm.set_cheat`; `bfm.command(name, help, fn)`;
    `bfm.config`, `bfm.log`; `bfm.PAD_*` / `bfm.HOTKEY_*`.
  - Cheats and commands can be registered only while the main chunk runs.
    They belong to the mod and are dropped with it. Hooks made later are
    dropped at mods shutdown too.
  - Sample: `pc_port/mods/examples/lua_hello`.
  - Without the define, a mod naming a script logs "no script runtime".
  The same `BfmPlatScriptRuntime` seam takes other languages.
- **Asset replacement, hash-keyed, from mods only.** The key is 16 hex digits
  of FNV-1a 64 over the original data:
  - textures: `le16 width, le16 height, width*height le16 pixels` of each
    VRAM upload → `assets/textures/<hash>.<ext>`. The built-in decoder is
    `.bfmi` ("BFMI", le16 w, le16 h, RGBA8888). `.png` comes from
    `backends/texture_png.c` (in-house, on zlib's inflate: non-interlaced
    grey, RGB, palette 1-8 bit with tRNS, grey+alpha and RGBA, 8/16-bit,
    all filters, CRC-checked; Adam7 is refused). Other formats plug in
    through `bfm_plat_mods_register_decoder`. A replacement may be the same size
    or an integer multiple of it (HD). Backends with `upload_replacement`
    get the HD image. Otherwise a same-size image is folded back to 15-bit
    VRAM (opaque black keeps the STP bit), and anything else keeps the
    original.
  - disc files (`bfm_plat_disc_read_file`): whole-file hash →
    `assets/files/<hash>.<ext>`.
  - When two mods replace the same asset, the later one in load order wins.
    Mods contain only modder-made files. The port never ships disc data,
    and `[mods] dump_textures = 1` writes the user's own uploads to
    `dump_dir` on their machine only, so modders can find hashes. Those
    dumps must not be redistributed.
- **Cheat menu and console** (`bfm_plat_console.h`). Cheats come from
  plugins (callback) or from a mod's `cheats.ini` (poke: `address`,
  `value`, `width` 1/2/4, `enabled`). Enabled cheats run on every
  `FRAME_END`. The cheat menu is a model toggled by the cheat-menu hotkey
  and drawn through the renderer overlay. Console commands: `help`,
  `cheats`, `cheat NAME on|off|toggle`, `peek`, `poke`, `get`, `set`,
  `mods`, `ff [SPEED]`, `events`, plus any a plugin registers. The text
  front end is `bfm_plat_console_ui` (above).
- **Config file + command line** (`bfm_plat_config.h`). The path is
  `$BFM_PORT_CONFIG`, else `$XDG_CONFIG_HOME/bfm-port/config.ini`, else
  `~/.config/bfm-port/config.ini` (`%APPDATA%\bfm-port\config.ini` on
  Windows).
  ```ini
  [video]    widescreen, internal_scale (1-8), window_width, window_height,
             fullscreen, frame_rate (30|60), vsync
  [timing]   fast_forward_speed (0-64, 0 = uncapped), fast_forward_toggle
  [backends] renderer, audio, input, storage
  [disc]     path          ; the user's own image
  [storage]  save_dir
  [mods]     enabled, dirs, dump_textures, dump_dir
  [debug]    console, log_level
  [mod.<name>] ...         ; free-form, read by plugins via config_get
  ```
  CLI: `--config PATH` (applied first), `--set section.key=value`,
  `--widescreen`, `--fps N`, `--scale N`, `--renderer NAME`,
  `--audio NAME`, `--disc PATH`, `--no-mods`, `--fullscreen`. Out-of-range
  values are rejected, the previous value stays and `rejected_values`
  counts them. `bfm_plat_config_save_file` writes everything back,
  including plugin sections.
- **Test/harness aids** (route autopilot through the scripted input backend,
  injected clock) stay behind test code and are not part of the default mod
  state.

Widescreen and 60 fps need both halves. The config and renderer carry the
aspect and frame-rate target (`BfmPlatOutput`). The game-side projection
change (GTE H / screen-width constants) and frame interpolation are game
and renderer work still to be done; the flags alone only change the output
aspect.

## Backends and licenses

| Component | Where | License | Notes |
|---|---|---|---|
| bfm_plat core, built-in backends, mods loader, sample plugin | `pc_port/platform/`, `pc_port/mods/` | this repository's code (see `LICENSE-NOTES.md`) | original work, no Psy-Q material |
| PsyCross | `tools/third_party/psycross`, fetched by `tools/fetch_toolchains.sh` at `e56e4cde1c2b8a15e0d4e38b26cdd9202e0d17e6` from `github.com/OpenDriver2/PsyCross`; ignored by git | MIT, © 2020 REDRIVER2 Project | a reimplementation of the Psy-Q library API on SDL2/OpenAL/OpenGL. It is not Sony code. Bundles a glad-generated GL loader (`src/render/glad.c`; generated code under glad's permissive terms, Khronos GL registry Apache-2.0) |
| in-house HLE device owners | `pc_port/*.c` (`gpu_psycross.c`, `audio_sdl.c`, `disc_media.c`, `bios_*.c`, …) | this repository | the `sdl` and `pinned` backends wrap these |
| SDL2 (runtime dependency) | system / host-port-deps | zlib | not vendored |
| OpenAL Soft (via PsyCross) | system | LGPL-2.1, dynamically linked | not vendored |
| OpenSSL libcrypto (`disc_media.c` SHA-256) | system | Apache-2.0 | `pinned` backend only |
| built-in 5x7 debug font (`bfm_plat_font.c`) | `pc_port/platform/` | this repository | original glyphs drawn for this port, not derived from PsyCross's `dbugfont` |
| Lua 5.4.9 | `tools/third_party/lua`, fetched by `tools/fetch_lua.sh` (sha256 `2335b6c5…6fb8e6`); ignored by git | MIT, © 1994–2026 Lua.org, PUC-Rio | optional script runtime (`BFM_PLAT_WITH_LUA`) |
| zlib (`texture_png.c` inflate) | system libz | zlib | PNG decoder only; the decoder itself is in-house, and no third-party PNG code is vendored |
| Game data | the user's own disc image | © the rights holders | never committed or shipped |

## Status

Done (`port/platform-layer`, tested without SDL: `tests/test_bfm_plat.py`,
also clean under ASan/UBSan):
- All interface headers, dispatchers, and the built-in `null` / `image` /
  scripted-input / host-clock backends.
- Config file, CLI and save-back. Mods loader with dlopen and static
  plugins, the script seam, texture and file replacement, texture dump.
  Cheats (callback and poke), cheat-menu model, console. Frame loop with
  hotkeys and fast-forward.
- `psycross`, `sdl` (audio), `sdl` (input) and `pinned` (disc) backends,
  compile-checked only against their headers. The PNG decoder is fully
  tested (zlib is present).
- Config-driven input bindings, the console text front end, the
  event catalog and the guest-PC hook-site table.

Stubbed / next:
- The `psycross`, `sdl` and `pinned` backends have never run. They need the
  SDL2/OpenAL/GL dev libs, and their CMake wiring is not added yet (the
  top-level `CMakeLists.txt` belongs to the native-lane work).
- The `psycross` renderer has no HD `upload_replacement` path, and
  `set_output` is a no-op. PsyCross owns window size.
- The SDL input backend's rebinding at runtime (`set_bindings`) has no UI.
- Overlay text on `psycross` is compile-checked only. It draws the
  built-in 5x7 font (`bfm_plat_font.c`, original to this repo) as TILE runs
  over a semi-transparent backing, in the current draw environment's
  coordinates. It uses no VRAM texture, because PsyCross's `FntLoad` would
  overwrite game VRAM.
- Guest sites for battle start/end and item get (no evidence yet). Room
  exit is low-confidence. Registering the known sites and reporting the
  selected overlay from the native lane.
- Anamorphic widescreen needs the GTE backend to call
  `bfm_plat_widescreen_sx_current` and a stretching renderer. On PsyCross
  it falls back to hor+. The hor+ edge culling is not patched.
- 60 fps interpolation.
- Routing the game's Psy-Q-shaped call sites (libgpu/libcd/libetc shims in
  the native lane) through `bfm_plat_*`.

## CMake wiring (note for port/native-lane)

This branch doesn't touch `CMakeLists.txt`. To wire it into the build:

```cmake
# Core: C99, no dependencies. dlopen for native plugins.
add_library(bfm_plat STATIC
    pc_port/platform/bfm_plat.c          pc_port/platform/bfm_plat_backends.c
    pc_port/platform/bfm_plat_ini.c      pc_port/platform/bfm_plat_config.c
    pc_port/platform/bfm_plat_renderer.c pc_port/platform/bfm_plat_audio.c
    pc_port/platform/bfm_plat_input.c    pc_port/platform/bfm_plat_storage.c
    pc_port/platform/bfm_plat_timing.c   pc_port/platform/bfm_plat_mods.c
    pc_port/platform/bfm_plat_console.c  pc_port/platform/bfm_plat_console_ui.c
    pc_port/platform/bfm_plat_events.c   pc_port/platform/bfm_plat_hook_sites.c
    pc_port/platform/bfm_plat_image.c    pc_port/platform/bfm_plat_font.c
    pc_port/platform/bfm_plat_widescreen.c)
target_include_directories(bfm_plat PUBLIC pc_port/platform)
target_link_libraries(bfm_plat PUBLIC ${CMAKE_DL_LIBS} m)

if(MUSASHI_WITH_PSYCROSS)   # SDL2 / OpenAL / GL already found above
    target_sources(bfm_plat PRIVATE
        pc_port/platform/backends/renderer_psycross.c
        pc_port/platform/backends/audio_sdl.c
        pc_port/platform/backends/input_sdl.c)
    # renderer_psycross.c needs C11 (PsyCross headers use static_assert)
    set_source_files_properties(pc_port/platform/backends/renderer_psycross.c
        PROPERTIES COMPILE_OPTIONS "-std=gnu11;-include;assert.h")
    target_include_directories(bfm_plat PRIVATE
        ${MUSASHI_PSYCROSS_DIR}/include pc_port/include)
    target_compile_definitions(bfm_plat PRIVATE BFM_PLAT_WITH_PSYCROSS
        BFM_PLAT_WITH_SDL_AUDIO BFM_PLAT_WITH_SDL_INPUT)
    target_link_libraries(bfm_plat PRIVATE SDL2::SDL2 musashi_pc_port)
endif()

find_package(ZLIB)          # optional: .png texture replacements
if(ZLIB_FOUND)
    target_sources(bfm_plat PRIVATE pc_port/platform/backends/texture_png.c)
    target_compile_definitions(bfm_plat PRIVATE BFM_PLAT_WITH_PNG)
    target_link_libraries(bfm_plat PRIVATE ZLIB::ZLIB)
endif()
# Optional Lua (after tools/fetch_lua.sh): all of tools/third_party/lua/src/*.c
# except lua.c and luac.c, as a separate C target without -Werror.
set(BFM_LUA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tools/third_party/lua/src)
if(EXISTS ${BFM_LUA_DIR}/lua.h)
    file(GLOB BFM_LUA_SOURCES ${BFM_LUA_DIR}/*.c)
    list(FILTER BFM_LUA_SOURCES EXCLUDE REGEX "/(lua|luac)\\.c$")
    add_library(bfm_lua STATIC ${BFM_LUA_SOURCES})
    target_include_directories(bfm_lua PUBLIC ${BFM_LUA_DIR})
    target_sources(bfm_plat PRIVATE pc_port/platform/backends/script_lua.c)
    target_compile_definitions(bfm_plat PRIVATE BFM_PLAT_WITH_LUA)
    target_link_libraries(bfm_plat PRIVATE bfm_lua)
endif()
# Optional: pc_port/platform/backends/disc_pinned.c + BFM_PLAT_WITH_PINNED_DISC
# (links disc_media.c / OpenSSL::Crypto, already in musashi_pc_port).
```

Notes:
- `bfm_plat.c` must be compiled with the same `BFM_PLAT_WITH_PNG` define as
  `texture_png.c`. Keep the definitions on the target, not per source.
- `musashi_audio_sdl_*` comes from `pc_port/audio_sdl.c`. Link whichever
  target builds it (shown here as `musashi_pc_port`).
- Tests: `python3 -m pytest tests/test_bfm_plat.py`. It builds its own
  probes and doesn't need CMake.
- For the sample plugin to find nothing but the plugin SDK, export nothing
  from the executable. Plugins use only the `BfmPluginHost` table.

## Migration order (does not stall current work)

1. Interfaces and built-in backends land (this branch). The native lane
   keeps running on its `musashi_*` device owners.
2. The native lane's Psy-Q-shaped shims call `bfm_plat_*`: VSync →
   `bfm_plat_timing_vsync`, CdRead/CdSearchFile → `bfm_plat_disc_*`, pad →
   `bfm_plat_input_*`, LoadImage/DrawOTag → renderer. It binds guest RAM
   with `bfm_plat_guest_memory_bind`.
3. SDL libs arrive: build and run the `psycross`/`sdl`/`pinned` backends
   (SDL input and the console front end are already written). Add
   `overlay_text` to the `psycross` renderer.
4. Room-enter and frame-tick events from dispatch, then asset replacement
   on real uploads, then the cheat console on the real game.
5. A modern renderer backend comes later and only needs the renderer
   interface (`upload_replacement` for HD textures, `set_output` for scale
   and aspect).
