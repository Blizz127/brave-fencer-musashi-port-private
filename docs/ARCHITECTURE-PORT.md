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
| input | `bfm_plat_input.h` | two pads as PS1 buttons (active-high) and analog, host bindings, port hotkeys (fast-forward, console, cheat menu, pause, screenshot, quit), PS1 SIO wire bytes for the pad shim | `null` (built-in "scripted": state is set by code, for tests and the route autopilot). An SDL keyboard/joystick backend comes with the SDL libs |
| disc/storage | `bfm_plat_storage.h` | sector reads (2048 / 2324 / 2340 / 2352), MSF↔LBA, ISO9660 file lookup, whole-file reads through the mods file hook, memory cards (128 KiB `.mcd` per slot, atomic save) | `image` (built-in: user `.cue`/`.bin` raw or `.iso`), `pinned` (`backends/disc_pinned.c` → `pc_port/disc_media.c`, verified retail cue/bin by SHA-256) |
| timing | `bfm_plat_timing.h` | `VSync(n)` pacing at the NTSC field rate (1001/60000 s), resync after stalls, fast-forward speed (0 = uncapped), injectable clock | built-in host monotonic clock (POSIX `clock_gettime` / Win32 QPC) |
| mods | `bfm_plat_mods.h`, `bfm_plugin.h` | folder loader, event hooks, C plugins, script-runtime seam, hash-keyed asset replacement, texture dump, guest-memory binding | built-in |
| console/cheats | `bfm_plat_console.h` | cheat registry (plugin callbacks, `cheats.ini` pokes), cheat-menu model, console commands | built-in |
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
`-DBFM_PLAT_WITH_SDL_AUDIO`, `-DBFM_PLAT_WITH_PINNED_DISC`. The default
dependency-free build registers none and runs on the built-ins.

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

Runtime events the native dispatch table emits where the game does them:
`bfm_plat_event_room_enter/exit(area, room)`, `bfm_plat_event_battle(start,
encounter, result)`, `bfm_plat_event_item_get(item, count)`. Which guest
functions correspond to these events is still to be settled with the
native-lane work (`port/native-lane`).

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
- **Lua later.** `BfmPlatScriptRuntime {name, extension, load, shutdown}`
  is the seam. A Lua runtime registers for `.lua` and receives the same
  `BfmPluginHost` table a C plugin gets. No runtime is built in yet, and a
  mod naming a script logs "no script runtime".
- **Asset replacement, hash-keyed, from mods only.** The key is 16 hex digits
  of FNV-1a 64 over the original data:
  - textures: `le16 width, le16 height, width*height le16 pixels` of each
    VRAM upload → `assets/textures/<hash>.<ext>`. The built-in decoder is
    `.bfmi` ("BFMI", le16 w, le16 h, RGBA8888), and PNG etc. plug in through
    `bfm_plat_mods_register_decoder`. A replacement may be the same size
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
  `mods`, `ff [SPEED]`, plus any a plugin registers. The console's text
  front end (key capture, rendering) arrives with the SDL input backend.
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
- `psycross`, `sdl` (audio) and `pinned` (disc) backends, compile-checked
  only against their headers.

Stubbed / next:
- The `psycross`, `sdl` and `pinned` backends have never run. They need the
  SDL2/OpenAL/GL dev libs, and their CMake wiring is not added yet (the
  top-level `CMakeLists.txt` belongs to the native-lane work).
- The `psycross` renderer has no HD `upload_replacement` path, and
  `set_output` is a no-op. PsyCross owns window size.
- No SDL input backend yet (keyboard/joystick, bindings from config), and
  no console text front end.
- No Lua runtime (seam only). No PNG texture decoder (seam only).
- Game-event emission (room/battle/item) from the native dispatch table.
  Widescreen projection and 60 fps interpolation.
- Routing the game's Psy-Q-shaped call sites (libgpu/libcd/libetc shims in
  the native lane) through `bfm_plat_*`.

## Migration order (does not stall current work)

1. Interfaces and built-in backends land (this branch). The native lane
   keeps running on its `musashi_*` device owners.
2. The native lane's Psy-Q-shaped shims call `bfm_plat_*`: VSync →
   `bfm_plat_timing_vsync`, CdRead/CdSearchFile → `bfm_plat_disc_*`, pad →
   `bfm_plat_input_*`, LoadImage/DrawOTag → renderer. It binds guest RAM
   with `bfm_plat_guest_memory_bind`.
3. SDL libs arrive: build and run the `psycross`/`sdl`/`pinned` backends,
   add the SDL input backend and the console front end.
4. Room-enter and frame-tick events from dispatch, then asset replacement
   on real uploads, then the cheat console on the real game.
5. A modern renderer backend comes later and only needs the renderer
   interface (`upload_replacement` for HD textures, `set_output` for scale
   and aspect).
