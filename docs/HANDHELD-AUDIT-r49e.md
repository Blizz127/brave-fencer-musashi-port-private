# Owner handheld gate: source audit of the r49e candidate

Audited 2026-10-20 by helper `qol-h1` (branch `claude/qol-h1`) on candidate `claude/r49-enh` **3e639e8352**.
Every `file:line` below is at that commit unless it says otherwise. This is a source audit plus devbox host
probes. **It is not a device result: all three checks stay NOT RUN until the owner's Alienware/Bazzite Game Mode
session runs the exact package** (gate text: project `CLAUDE.md`, "Owner release gate").

Evidence classes used below:

- **[S]** read in source at the audited commit.
- **[H]** observed on this devbox (command and output recorded in section 7).
- **[L]** prior art in the owner's launcher repo (`~/dev/banshee-launcher-merge-0.9.278`, read only).
- **[D]** can only be verified on the device.

## 0. Summary

| Check | Source finding | Risk under Gamescope | Fix in this branch | Device-only |
|---|---|---|---|---|
| 1 Controller | SDL GameController sampler with Steam-virtual-pad preference, hotplug, Legion/InputPlumber ignore-list repair and background-events hint. No defect found. | Low. Observed side effects of the shipped dev-menu defaults: L3 toggles fast-forward, R3 held fast-forwards, a lone Back/Start is arbitrated (section 3.3). Error dialogs cannot be dismissed with a pad. | None (no defect). Options listed for the lead. | Out-of-box behaviour under Steam Input in menus and gameplay. |
| 2 Window | Windowed 1280x960 `SDL_WINDOW_RESIZABLE`; nothing makes it fullscreen. The Right-Alt+Enter toggle cited by the r47 audit is dead code. Present stretches 4:3 over the whole drawable. | Medium. No evidence either way for Gamescope's own scaling; a fullscreen window at the output size would be the standard path. | Gamescope-only borderless desktop fullscreen plus 4:3 fit; kill switches. Section 6. | Whether it presents with no white border at the device's real size and aspect. |
| 3 Text entry | **No text field is reachable in the shipped package by default.** The developer console is not reachable (correction to the r47 audit, section 2). The only exposure is the `launch.sh` zenity/kdialog disc picker, and only when no disc is found. | Low for the game. Medium if the picker appears. | None coded (no consumer). OSK design in section 5.4. Tripwire tests keep the audited absence true. | Confirm the picker never appears and no text field shows. |

## 1. Corrections to the r47 audit (`~/release-staging/bfm-r47-release/handheld-gate/HANDHELD-GATE-AUDIT-r47.md`)

1. **"The developer console is on by default, opens with the backtick key and calls SDL_StartTextInput" is true of the
   platform layer's own defaults, not of the shipped game.** `bfm_plat` defaults `console = 1`
   (`pc_port/platform/bfm_plat_config.c:52`) and binds ``hotkey.console = key:` ``
   (`bfm_plat_input.c:181`), but in `musashi_native_boot`:
   - `plat_start` forces the platform layer's input backend to `"null"` (`native_boot.c:5420-5422`), so hotkeys are
     never read from the keyboard;
   - the `sdl` input backend, the only place that calls `SDL_StartTextInput` (`backends/input_sdl.c:173-177`), is
     opened only when the environment sets `MUSASHI_INPUT=bfm_plat` (`native_boot.c:5541-5547`, called at 5784;
     `docs/PC-PORT.md:660` documents it as opt-in);
   - the shipped `launch.sh` never sets `MUSASHI_INPUT` (checked in the r49e package, section 7.1).

   A second condition applies even with that variable: `handle_hotkeys` (`bfm_plat.c:236-252`) runs only from
   `bfm_plat_frame_begin`, which native_boot reaches only through the FRAME_BEGIN hook site 0x800189A8
   (`bfm_plat_events.c:178`, `bfm_plat_hook_sites.c:218`). Whether that site fires on the native lane is **not verified**
   here, so the doc does not claim the console is reachable under that variable either.
2. **"PsyCross toggles desktop fullscreen with Right-Alt+Enter" is dead in this build.** The toggle lives in
   `PsyX_Sys_DoPollEvent` (PsyCross `src/PsyX_main.cpp:737-748`). That function is called only from `PsyX_BeginScene`
   and `PsyX_UpdateInput` (lines 783, 958), which the native path does not call (`native_boot.c:5325`,
   `gpu_psycross.c:519`), and `tools/patches/psycross-local.patch` additionally makes it `return;` at entry. native_boot's
   own VBlank loop drains SDL events itself (`native_boot.c:2873-2880`) and handles only `SDL_QUIT`.

## 2. Method and what was not done

Source reading of the launch path (`tools/package_legion.sh` launch.sh, `native_boot.c`, `gpu_psycross.c`, the
platform layer, PsyCross at `tools/third_party/psycross` with the local patch applied), the shipped r49e package
(`~/release-staging/bfm-r49e-build/bfm-r49-3e639e835.tar.gz`, read only), the launcher's Game Mode code, and host probes
against the SDL library bundled in that package. No game run, no retail data, no device.

## 3. Check 1: controller

### 3.1 Current behaviour [S]

- Hints at the very start of `main`: `musashi_host_pad_hints()` (`native_boot.c:5583` ->
  `include/musashi_host_chord.h:67-71`) sets `SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD=1` (env and hint) and
  `SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS=1`; the latter is set again before the window exists
  (`native_boot.c:5726-5729`) because Gamescope can focus the window while SDL still thinks it has no focus.
- `sanitize_controller_ignore_list` (`native_boot.c:1618-1642`, called at 5584) drops the Legion/InputPlumber entries
  (28de:1205/1206/12f0-12ff, every 17ef) Steam passes in `SDL_GAMECONTROLLER_IGNORE_DEVICES`.
- The game pad sampler `sample_keyboard_pad` (`native_boot.c:1650`) reads keyboard state and SDL GameController state.
  `game_pad_select` (1548-1606) reconciles hotplug every 60 polls, flags a Steam virtual pad (Steam handle, 28de:11ff or
  a "Steam Virtual" name) and prefers an active virtual pad, then any active pad.
- Mapping (`native_boot.c:1717-1772`): D-pad and left stick (+-10000) = D-pad; A = Cross, B = Circle, X = Square,
  Y = Triangle; LB/RB = L1/R1; triggers above 16000 = L2/R2; Start/Back = Start/Select; sticks pass through as analog with
  a 3000 dead zone. L3/R3 are not sent to the game.
- The game's own menus use the same pad path. The Port Dev Menu is on by default (`launch.sh` sets `BFM_DEV_MENU=1`,
  `package_legion.sh:153-160`), opens with Back+Start or F8, and is navigated by D-pad or left stick with A/B
  (`native_boot.c:2419-2491`).
- A keyboard fallback exists (arrows/WASD, Z/X/C/V, Return, Space) but nothing requires it.

### 3.2 Risks under Steam Game Mode (reasoning, not device evidence)

1. Steam Input must hand the game a gamepad. The launcher keeps its single shortcut on the Gamepad template [L
   `docs/releases/0.9.207.md:13`], so a game started from it should inherit that; **[D]**.
2. A physical pad next to Steam's virtual pad is handled (`game_pad_select`), as is InputPlumber on Legion hardware.
3. SDL's bundled build is the Ubuntu 2.32.10 classic library (section 7.1); the package's `LD_LIBRARY_PATH` prefers it over
   the system one.

### 3.3 Observed side effects of the shipped dev-menu defaults (not defects; owner-visible, so recorded)

- **L3 toggles fast-forward and R3 held fast-forwards, always** (`include/musashi_dev_menu.h:59`,
  `native_boot.c:2469-2470`, `dev_menu.c:629`). `BFM_CHEATS=0` removes it. An accidental stick click on a handheld will
  speed the game up.
- **A lone Back or Start press is arbitrated** for 300 ms so the Back+Start chord can win
  (`musashi_host_chord_step`, `native_boot.c:1738`, `2487-2489`): a tap reaches the game when released, a hold after 300 ms.
- **Error dialogs need a mouse or keyboard**: `user_error` (`native_boot.c:4691-4696`, `SDL_ShowSimpleMessageBox` when
  `MUSASHI_INTERACTIVE=1`) and `say()` in `launch.sh:108-113` (zenity/kdialog `--error`). Neither has a text field. With
  only a pad they cannot be dismissed except by closing the game.

### 3.4 Proposed fixes (none coded)

No defect was found in the controller path, so nothing was changed. Options for the lead, in order of value:

1. Gate the L3/R3 fast-forward behind the dev menu being open (or off in Game Mode). It touches `dev_menu_probe` semantics
   ("FF always"), so it is the lead's call.
2. Let a pad button dismiss `user_error` (or time it out). Fatal-error path only.
3. Nothing for the Back/Start arbitration; it is the documented dev-menu behaviour.

### 3.5 Host evidence

`tests/test_host_chord.py` (virtual SDL joystick, dummy driver) covers the chord. It says nothing about Steam Input.

## 4. Check 2: window

### 4.1 Current behaviour [S]

- `PsyX_Initialise("Brave Fencer Musashi - native VRAM", 1280, 960, 0)` (`native_boot.c:5730`). PsyCross creates the window with
  `SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE` and no fullscreen flag for fullscreen = 0 (PsyCross `src/render/PsyX_render.cpp:275-287`).
  It is an ordinary decorated 1280x960 window.
- `host_window_inspect` (`native_boot.c:5070-5118`) forces the size back to 1280x960 (5083-5084), shows the cursor, grabs
  nothing and raises the window when `MUSASHI_INTERACTIVE=1`. `hold_window` (5120-5139, 3 s from `launch.sh`) calls it again.
- Hints (`native_boot.c:5719-5725`) include `SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS=0`, which a fullscreen window needs.
- Nothing in this build can make the default (ORIGINAL, PsyCross) path fullscreen: the Right-Alt+Enter toggle is dead (section 1),
  `--fullscreen` is silently ignored by `main`'s argument loop (`native_boot.c:5602-5636`), and `[video] fullscreen = 1` reaches only
  the experimental gl renderer through `gl_output` (`backends/renderer_gl.c:206-207`, `native_boot.c:5503-5513`). The Enhancements
  DISPLAY row writes that same key for the next launch.
- Present (`gpu_psycross.c:476-535`): clears the whole drawable black and stretches the GP1 display rect over the whole drawable
  (`SDL_GL_GetDrawableSize`, lines 494-518). There is no aspect preservation, so a window that is not 4:3 distorts the image
  and no region inside the window can stay unpainted once frames present. The first present is at `native_boot.c:5795`.
- The X11 interposer (`libmusashi_x11_nograb.so`, linked into the binary, `CMakeLists.txt:403-410`) overrides `dlsym`
  (`x11_nograb.c:240-272`) to neutralise raise/restack/grab and focus calls. It does **not** intercept `XSendEvent`, so the
  `_NET_WM_STATE` fullscreen request SDL sends passes through.
- `docs/GRAPHICS-ENHANCEMENTS-DESIGN.md:440-442` already asks the owner whether Game Mode should keep 4:3 with bars at the
  display's native resolution when fullscreen. Nothing answers it yet; section 6 implements the proposed answer.

### 4.2 Risk under Gamescope

- A windowed 1280x960 window is scaled and letterboxed by Gamescope itself. The bars and any border colour are Gamescope's,
  not the game's; the game cannot produce a white border once it presents, because it clears to black and fills the drawable.
- Where a white border could come from: another window of the same shortcut showing around a smaller game window (the launcher
  hides itself on PLAY in Game Mode since 0.9.271 [L `docs/releases/0.9.271.md:59-66`]), or a window the compositor does not treat as
  the app window. Neither can be decided from source. **[D]**
- Without a fix the first device run answers it only by looking.

### 4.3 Proposed and implemented fix

See section 6. In short: under Gamescope only (or when asked), request borderless desktop fullscreen once, and fit the 4:3 image
inside the real drawable with black bars. Desktop behaviour is unchanged.

## 5. Check 3: text-entry inventory

### 5.1 Flows (UI scope checked: everything the `musashi_native_boot` package can show or accept)

| # | Flow | Where [S] | Reachable in the shipped package by default? | Starts SDL text input? | Verdict |
|---|---|---|---|---|---|
| 1 | Platform-layer developer console (typed commands) | `bfm_plat_console_ui.c`, toggle `bfm_plat.c:247-248`, text `backends/input_sdl.c:173-177` | **No** (section 1.1): input backend is `null`; needs `MUSASHI_INPUT=bfm_plat` and a FRAME_BEGIN hook | Only through input_sdl.c | Not exposed. Tripwire-tested. |
| 2 | Cheat menu | `bfm_plat_console.c` (model), draw `bfm_plat.c:278` | No default hotkey (`bfm_plat_input.c:182` is empty) | No | No typing at all |
| 3 | Port Dev Menu (on by default) | `dev_menu.c`, glue `native_boot.c:2360-2640` | Yes | No | Pad/F-key only; no text field |
| 4 | Enhancements page | `dev_menu.c` rows, `native_boot.c:5369-5398` | Yes (inside the dev menu) | No | Cycles values; no typing |
| 5 | Disc picker | `package_legion.sh:133-141` (`zenity --file-selection` / `kdialog --getopenfilename`) | **Only when no disc is found** (BFM_DISC, remembered disc, `./disc`, `~/Games/...`) | n/a (separate GTK/Qt process) | **Only text-capable exposure** (location field). No automatic Steam OSK is arranged. |
| 6 | Modal error boxes | `say()` `package_legion.sh:108-113`, `user_error` `native_boot.c:4691-4696` | Only on error | No | No field; see 3.3 |
| 7 | SDL text events | `SDL_TEXTINPUT` handled only in `input_sdl.c:98`; PsyCross handles it only in the disabled `PsyX_Sys_DoPollEvent` | n/a | Never called outside input_sdl.c | No host-to-guest text path exists |
| 8 | The game's own menus (guest code) | retail UI | Yes | No | PSX pad-driven. This repo cannot prove the retail UI has no name entry; the port has no path that feeds host text to the guest. **[D]** confirm no keyboard/name prompt appears |
| 9 | Password fields | none | n/a | n/a | None anywhere (`grep -ri password pc_port tools/package_legion.sh`: no match) |

Mods: `mods_enabled` defaults on, but the Lua backend is not built (`tools/third_party/lua` absent; `CMakeLists.txt:582-590` is optional),
so no script can drive any UI. Plugins load only from a user's `mods/` directory.

### 5.2 Audited absence statement for the release note

"No text field is reachable in the shipped package by default; checked scope: the game, the Port Dev Menu and its Enhancements page,
the platform-layer console and cheat menu (unreachable by default), and the launch.sh dialogs. The only exposure is the disc picker
when no disc image is found." This does not replace a device PASS; it is the audited-absence record the gate asks for.

### 5.3 What SDL 2.32.10 does about the Steam keyboard [H]

With the SDL bundled in the r49e package (`lib/libSDL2-2.0.so.0` = `SDL-release-2.32.10-0-g5d2495703 (Ubuntu 2.32.10+dfsg-6)`),
x11 video driver:

- `SteamDeck` unset: `SDL_HasScreenKeyboardSupport()` = 0; `SDL_StartTextInput()` opens nothing.
- `SteamDeck=1`: `SDL_HasScreenKeyboardSupport()` = 1; `SDL_StartTextInput()` runs
  `xdg-open steam://open/keyboard?XPosition=0&YPosition=0&Width=0&Height=0&Mode=1` and `SDL_StopTextInput()` runs
  `xdg-open steam://close/keyboard` (probe in 7.2, with a fake `xdg-open` that logs its arguments).
- dummy driver: no support even with `SteamDeck=1`.

So the r47 audit's "opens NO Steam OSK" depends on the session: with `SteamDeck=1` and the x11 (XWayland) driver SDL opens Steam's keyboard
by itself. **Unknown until the device runs:** whether Bazzite's Game Mode puts `SteamDeck=1` into the game's environment, which video driver SDL
picks there, and whether `xdg-open` can reach Steam from the game process. The launcher treats `SteamDeck=1` + `SteamGamepadUI=1` together as a
Game Mode signal [L `SteamGameMode.cs:80-98`] but chose a built-in on-screen keyboard for its own sign-in and says it does not use Steam's
[L `docs/releases/0.9.225.md`], so the repo holds no device evidence for the Steam keyboard path.

### 5.4 Proposal for any future reachable text field (not coded: it has no consumer)

A fallback that calls `SDL_OpenURL("steam://open/keyboard?...")` when Gamescope is detected and `SDL_HasScreenKeyboardSupport()` is 0 would be dead
code today and a path nobody can test off the device. Prefer, in this order, when a field is first introduced:

1. A built-in pad-driven keyboard drawn through the dev-menu overlay (what the launcher did in 0.9.225): independent of `SteamDeck`, the video
   driver and Steam being reachable, and passwords can be masked by construction.
2. Otherwise `SDL_StartTextInput()` (Steam's keyboard when SDL supports it) plus the helper `musashi_host_session_gamescope()` from this branch to
   decide whether to add the explicit URL. Mode 0 (one line, Enter closes) is right for single-line fields:
   `steam://open/keyboard?XPosition=0&YPosition=0&Width=0&Height=0&Mode=0`.

The tripwire tests (section 6) fail the day a new `SDL_StartTextInput` caller or a `MUSASHI_INPUT` default appears, which forces this audit to be redone.

## 6. Fixes in this branch

(Filled in below as commits land; see section 8 for the final list.)

## 7. Host evidence recorded during the audit [H]

### 7.1 Package facts (`bfm-r49-3e639e835.tar.gz`, extracted to scratch, read only)

- `launch.sh` is the `package_legion.sh` heredoc plus one r49 line (`MUSASHI_VSYNC_WAIT`); it sets `MUSASHI_INTERACTIVE`, `MUSASHI_GUEST_CLOCK`,
  `MUSASHI_HOLD_WINDOW_MS`, `BFM_DEV_MENU`, `BFM_ROUTE_JOURNAL`, and never mentions `MUSASHI_INPUT`, `BFM_FULLSCREEN` or `debug.console`.
- Bundled SDL: `SDL-release-2.32.10-0-g5d2495703 (Ubuntu 2.32.10+dfsg-6)`, containing the strings `steam://open/keyboard...`,
  `steam://close/keyboard` and `SteamDeck`.

### 7.2 SDL on-screen-keyboard probe

Scratch programs `sdl_osk_probe.c` / `sdl_osk_start.c` (not in the repo), compiled against system SDL 2.32.10 headers and run with
`LD_LIBRARY_PATH` pointing at the package's `lib/`, under `xvfb-run` with `SDL_VIDEODRIVER=x11`:

```
SteamDeck unset : has_osk=0   (xdg-open never called)
SteamDeck=1     : has_osk=1   xdg-open steam://open/keyboard?XPosition=0&YPosition=0&Width=0&Height=0&Mode=1
                              xdg-open steam://close/keyboard
dummy driver, SteamDeck=1 : has_osk=0
```

### 7.3 Baseline before any change (candidate 3e639e8352)

- `gcc -std=gnu99 -Wall -Wextra -Werror -I pc_port/include tests/dev_menu_probe.c pc_port/dev_menu.c`: builds; prints
  `DEV_MENU_ENHANCE_PASS`, `DEV_MENU_BRIDGE_PASS`, `DEV_MENU_PASS` (3 PASS lines).
- `pytest tests/test_bfm_plat.py`: 37 passed, 1 skipped in 41.57 s.

## 8. Device-only items and what the first device run should capture

See section 9 once the HOST_SESSION line exists. Until then: record `~/.local/state/bfm-port/last-run.log` and screenshots from the Game Mode session.

## 9. Gate record skeleton (all NOT RUN until the device session)

| Check | Result | Evidence |
|---|---|---|
| 1 Controller out of the box (menus and gameplay) | NOT RUN | device session pending |
| 2 Borderless/fullscreen, no white border | NOT RUN | device session pending |
| 3 Automatic OSK for every exposed text field | NOT RUN (audited absence, section 5.2) | this document; device confirmation pending |
