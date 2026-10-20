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
| 3 Text entry | **No text field is reachable in the shipped package by default.** The developer console is not reachable (correction to the r47 audit, section 1). The only exposure is the `launch.sh` zenity/kdialog disc picker, and only when no disc is found. | Low for the game. Medium if the picker appears. | None coded (no consumer). OSK design in section 5.4. Tripwire tests keep the audited absence true. | Confirm the picker never appears and no text field shows. |

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
  nothing and raises the window when `MUSASHI_INTERACTIVE=1`. `hold_window` (5120-5139) calls it again when the run ends.
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

- A windowed 1280x960 window is expected to be scaled and letterboxed by Gamescope itself (unverified: **[D]**). The bars and any border
  colour would then be Gamescope's, not the game's; the game cannot produce a white border once it presents, because it clears to black
  and fills the drawable.
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
| 1 | Platform-layer developer console (typed commands) | `bfm_plat_console_ui.c`, toggle `bfm_plat.c:247-248`, text `backends/input_sdl.c:173-177` | **No** (section 1, item 1): input backend is `null`; needs `MUSASHI_INPUT=bfm_plat` and a FRAME_BEGIN hook | Only through input_sdl.c | Not exposed. Tripwire-tested. |
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
2. Otherwise `SDL_StartTextInput()` (Steam's keyboard when SDL supports it) plus `musashi_host_session_detect_env()` from this branch to
   decide whether to add the explicit URL. Mode 0 (one line, Enter closes) is right for single-line fields:
   `steam://open/keyboard?XPosition=0&YPosition=0&Width=0&Height=0&Mode=0`.

The tripwire tests (section 6) fail the day a new `SDL_StartTextInput` caller or a `MUSASHI_INPUT` default appears, which forces this audit to be redone.

## 6. Fixes in this branch

Commits on `claude/qol-h1` (base 3e639e8352), separable so the lead can take the safe parts alone:

| Commit | What | Touches | Takeable alone |
|---|---|---|---|
| `c327d9192b` | this audit | docs | yes |
| `50d4cd39c9` | tripwire tests for check 3 | `tests/test_handheld_gate_audit.py` | yes |
| `ebd932e2e0` | `musashi_host_session.h` (Gamescope detection, window decision, 4:3 fit) and its probe | new header, tests | yes, nothing calls it |
| `083631b6ec` | window mode wiring, present fit, session log, opt-in live present probe | `native_boot.c`, `gpu_psycross.c`, `CMakeLists.txt`, `musashi_host_session.h` (comment), `tests/gpu_present_fit_probe.c` | needs the device check (6.1) |

### 6.1 Borderless desktop fullscreen under Gamescope, 4:3 inside it (check 2)

What it does:

1. `host_window_apply_mode` (native_boot.c) runs once, right after `PsyX_Initialise` and before the first present. It asks
   `musashi_host_window_decide`: **`BFM_FULLSCREEN` (1/0; `--fullscreen` / `--windowed` set it) first, then an explicit config.ini
   `[video] fullscreen = 1|0`, then Gamescope, then windowed.** Only the Gamescope rung is new behaviour. If it decides fullscreen it
   calls `SDL_SetWindowFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP)`; a refusal is logged and the window stays windowed.
2. `musashi_gpu_psycross_present` keeps 4:3 inside the drawable with black bars **when the window is fullscreen** (decided from the live
   window flags on every present); a windowed or hand-resized window runs the identical stretch as before.
3. `host_window_inspect` no longer forces a fullscreen window back to 1280x960.
4. Two log lines go to `last-run.log`: `HOST_SESSION` at startup (Gamescope decision and which variable matched, `SteamDeck` and
   `SteamGamepadUI`, the SDL video driver, `SDL_HasScreenKeyboardSupport`, the window mode and reason) and `HOST_WINDOW` after about two
   seconds (real window and drawable size, fullscreen flag, the 4:3 fit rectangle). They are the artifact-bound evidence for the first
   device run and answer the open questions of section 5.3 without another build.

Why each choice:

- **Gamescope only.** The gate is about Game Mode, and desktop users keep today's decorated window. Detection is the launcher's own rule
  (`SteamGameMode.DetectGamescope`, device-exercised there since 0.9.271) so the two programs agree on what Game Mode is. `SteamDeck=1`
  alone is not a signal (the launcher's test expects false; it counts only together with `SteamGamepadUI=1`). Parity vectors are in
  `tests/host_session_probe.c`.
- **Desktop fullscreen, not exclusive.** `PsyX_Initialise`'s fullscreen argument maps to exclusive `SDL_WINDOW_FULLSCREEN` (PsyCross
  `PsyX_render.cpp:278-281`), which asks for a 1280x960 mode. Desktop fullscreen never changes the display mode and makes the window the
  output, so Gamescope has nothing to scale or letterbox.
- **After creation, before the first present.** The first present (`native_boot.c` near `present_frame(&boot)` after the GPU init) then
  clears the resized drawable to black; later presents happen only while the display is on, so an unpainted resized window could otherwise
  sit through boot.
- **Fit from the live window state.** No new global to keep in sync; the GL renderer path keeps its own fitting.
- **Precedence with kill switches.** If Game Mode misbehaves on the device: `BFM_FULLSCREEN=0` in the Steam launch options, `--windowed`, or
  the Enhancements DISPLAY row set to WINDOW (it writes an explicit `fullscreen = 0`, which beats Gamescope, and works from the pad).

Desktop behaviour: unchanged by default (decision `default`, same present path). Four other effects the lead should know:

1. `--fullscreen` now does what it says (it was silently ignored); `--windowed` is new.
2. An explicit `[video] fullscreen = 1` now also applies to the ORIGINAL renderer, not only gl: this extends the G2 contract. The gl output
   change now follows the effective mode, so `BFM_FULLSCREEN=0` also vetoes a config `fullscreen = 1` there.
3. The DISPLAY row is seeded from the mode in effect (native_boot.c only; `dev_menu.c` is untouched), so under Gamescope it shows FULLSCREEN
   and one press turns it off for the next launch.
4. `HOST_SESSION` / `HOST_WINDOW` are new log lines.

Tests: `tests/host_session_probe.c` (pure: the launcher's detection vectors, precedence, the fit rectangle swept over 160k sizes), the opt-in live probe
`tests/gpu_present_fit_probe.c` (section 7.4) and the existing live `musashi_gpu_psycross_probe` as a regression check of the windowed present.

Not changed: the mouse cursor stays visible (`host_window_inspect`), the guest is untouched, the X11 interposer is untouched.

Risks (all device-unverified): how Gamescope's XWayland (or the Wayland driver) answers the EWMH fullscreen request from this window; whether the
launcher window stays visible behind it (the launcher hides itself on PLAY since 0.9.271 [L]); the visible cursor; legibility of the dev menu at the
output's resolution (its scale follows the drawable height).

**Scaling quality is a preference this branch does not decide.** The image is still sampled with `GL_NEAREST`, as in a window. A window at 1280x960 is an exact
4x of a 320x240 display; a fullscreen fit at 1080p is 4.5x (1440x1080) and at 1280x800 is 3.33x (1067x800), so some pixel columns are one pixel wider than
their neighbours. Alternatives, each a few lines at the same site in `musashi_gpu_psycross_present`: whole-multiple (integer) scaling, which is crisp but leaves
larger bars (at 1080p it is 4x = 1280x960, at 800p it is 3x = 960x720); or linear filtering only when the scale is not a whole number. This is the same question as
`docs/GRAPHICS-ENHANCEMENTS-DESIGN.md:440-442` (gl already offers PRESENT FIT / INTEGER). Decide it after seeing the device.

### 6.2 Tripwires for check 3

`tests/test_handheld_gate_audit.py` (8 tests, mutation-checked on a scratch copy): launch.sh never mentions `MUSASHI_INPUT`; `SDL_StartTextInput`,
`SDL_StopTextInput`, `SDL_SetTextInputRect`, `SDL_TEXTINPUT` and `SDL_TEXTEDITING` appear only in `input_sdl.c`; `plat_start` forces the null input
backend; `plat_input_attach` is env-gated; the console toggle is reachable only through `bfm_plat.c` and the frame hook; nothing opens URLs or the Steam
keyboard; no password field exists. Each failure names this document.

### 6.3 Not coded, with reasons

- **Steam on-screen keyboard fallback** (section 5.4): no consumer, device-only, would look like a pass.
- **L3/R3 fast-forward gating and pad-dismissable error dialogs** (section 3.4): owner-visible dev-menu and fatal-error behaviour; the lead decides.
- **`launch.sh` disc picker in Game Mode**: the script is pinned (`tools/package_legion.sh` must not change). Proposal for the next package revision: when
  Gamescope is detected, skip the picker and show the existing message, relying on the launcher to pass `BFM_DISC`.
- **Hiding the cursor in fullscreen**: unverifiable here and Gamescope may already hide an idle cursor.

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

### 7.4 Live present geometry (opt-in probe, private Xvfb)

`tests/gpu_present_fit_probe.c` samples pixels from inside the present (the overlay callback runs after the blit and before the swap) on a real PsyCross GL
context with all-white VRAM (llvmpipe, Mesa 26.0.8). Run as `MUSASHI_PRESENT_FIT_PROBE=1 xvfb-run -a -s "-screen 0 WxHx24" musashi_gpu_present_fit_probe`.
Built by hand with the same compile flags and libraries as the CMake target (the CMake build of that one target was queued behind other helpers' heavy jobs;
CMake generated the target and the `gpu_present_fit_live` ctest entry, and the heavy-slot build of `musashi_native_boot` passed, section 7.5).

```
1280x800  : fullscreen 1280x800: image 1067x800 at 106,0, bars black   PRESENT FIT OBSERVED ... rc=0
1280x1024 : fullscreen 1280x1024: image 1280x960 at 0,32, bars black   PRESENT FIT OBSERVED ... rc=0
1920x1080 : fullscreen 1920x1080: image 1440x1080 at 240,0, bars black PRESENT FIT OBSERVED ... rc=0
1280x960  : 4:3 screen, only the windowed stretch was checked          rc=0
no opt-in : skipped: opt-in probe ...                                  rc=77
fit disabled in a scratch copy of gpu_psycross.c: FAIL black(0)&&black(1)&&black(2)&&black(3)   rc=1
```

Limits: Xvfb has no window manager, so SDL takes its legacy fullscreen path (an override-redirect window), not the EWMH path Gamescope uses. The window
starts at least screen-sized because under Xvfb the GL framebuffer does not grow when a window does (found while writing the probe: pixels beyond the original
1280x960 stayed unreadable after hundreds of presents). Nothing here is evidence about Gamescope.

### 7.5 Builds and tests on the branch head

- `heavy_slot.sh nice -n 10 cmake --build /tmp/bfm-qol-h1-build --target musashi_native_boot musashi_gpu_psycross_probe -j3` (RelWithDebInfo, gcc 15.2): rc 0, no
  warning from the changed code (the warnings present are the existing disc_media, bfm_psyq_libgte and OpenSSL SHA256 ones). `musashi_native_boot` was **built, not run**:
  `host_window_apply_mode` and the log lines have not executed in a real boot (that needs the disc), only their pure logic and the present geometry are exercised.
- Existing live probe `musashi_gpu_psycross_probe` under `xvfb-run -s "-screen 0 1280x1024x24"`: rc 0, `GPU BACKEND OBSERVED: ... display-on accepted`.
- `gcc -std=gnu99 -Wall -Wextra -Werror -I pc_port/include tests/dev_menu_probe.c pc_port/dev_menu.c`: prints `DEV_MENU_ENHANCE_PASS`, `DEV_MENU_BRIDGE_PASS`, `DEV_MENU_PASS` (3 PASS lines).
- `pytest tests/test_bfm_plat.py`: 37 passed, 1 skipped in 28.14 s (baseline before the change: 37 passed, 1 skipped in 41.57 s).
- `pytest tests/test_host_chord.py tests/test_host_session.py tests/test_handheld_gate_audit.py`: 10 passed in 1.47 s. `tests/host_session_probe.c` also builds and passes with clang 21.1.8 under `-std=c99 -pedantic -Werror`.
- Mutation checks on scratch copies: six tripwire mutations (launch.sh exports `MUSASHI_INPUT`, a text-input call in native_boot, `plat_start` no longer null, `plat_input_attach` un-gated, a
  `bfm_plat_frame_begin` call, a password mention) each fail exactly the intended test; eight helper mutations (SteamDeck alone, config over env, no horizontal fit, no vertical fit,
  no centring, round-down, override ignored, case-sensitive match) each fail the probe.

### 7.6 Merge check against the other lanes (read only, `git merge-tree`)

`git merge-tree $(git merge-base claude/r49-enh windows-r49-enh) claude/qol-h1 windows-r49-enh`: **no conflict markers**; `CMakeLists.txt`, `mips_formatter.c` and `native_boot.c` are changed on both
sides and auto-merge. The same check against `claude/r50-native-main0015` and `claude/enh-g2` is clean.

## 8. Device-only items and what the first device run should capture

Keep `~/.local/state/bfm-port/last-run.log` from the Game Mode session with the package sha256, plus screenshots. Record the device identity at test
time: the gate names the owner's Alienware/Bazzite, while the launcher's 0.9.278 note names Legion Go 2 as its acceptance target and says the exact
hardware, OS, Game Mode, Gamescope, controller and Steam Input identity is unverified.

**Check 1 (controller).** Pad drives the title, the game's menus and a room with no remap or keyboard: D-pad and stick, A/B/X/Y, shoulders, triggers,
Start, Select; the Port Dev Menu opens with Back+Start and moves with D-pad and A/B. Log lines to keep: `GameController attached/chosen`,
`HOST_INPUT_DEVICE`, `controller ignore list`. Watch for accidental fast-forward from a stick click and for the Start/Back arbitration feel (3.3).

**Check 2 (window).** `HOST_SESSION` should read `gamescope=1 because=<variable>` and `window=fullscreen_desktop reason=gamescope`; `HOST_WINDOW` should read
`fullscreen=1` with `window` and `drawable` equal to the output size and `bars=1` unless the output is 4:3. Look at the screen: no border, no white band, the
image 4:3 centred with black bars, no flash of a smaller window at start, the dev menu legible. If `gamescope=0` on the device, record `steamdeck`,
`steamgamepadui`, `video_driver` from the same line and the environment (`XDG_CURRENT_DESKTOP`, `GAMESCOPE_WAYLAND_DISPLAY`): the detection rule then needs
the variable that session really sets (`BFM_GAMESCOPE=1` forces it meanwhile). If the window misbehaves, retest with `BFM_FULLSCREEN=0`.

**Check 3 (text entry).** No text prompt anywhere in the game, the Port Dev Menu or its Enhancements page; the `launch.sh` disc picker never appears (the disc
is found without it); record `HOST_SESSION osk_support=` (1 only when SDL would open Steam's keyboard in that session: `SteamDeck=1` on the x11 driver).
A dialog from `say()` or `user_error` appearing at all is itself a finding.

**A stale config can veto Gamescope.** If the device's `~/.config/bfm-port/config.ini` already holds `[video] fullscreen = 0` (for example from toggling the
DISPLAY row in an earlier test build), the explicit config wins: `HOST_SESSION` then reads `reason=config video.fullscreen=0`, the window stays windowed, and that
is the precedence working, not a detection failure. `BFM_FULLSCREEN` beats the config too.

**Before shipping (lead's side).** `musashi_native_boot` was built but never run on this branch, so `host_window_apply_mode`, `HOST_SESSION` and `HOST_WINDOW` have not
executed in a real boot. On integration the first route or save leg's log should show `HOST_SESSION gamescope=0 ... window=windowed reason=default` with route and save
identity unchanged; confirm the gate log parsers ignore the two new lines; one Xvfb leg with `BFM_GAMESCOPE=1` would exercise the fullscreen path end to end for the cost of one leg.

## 9. Gate record skeleton (all NOT RUN until the device session)

| Check | Result | Evidence |
|---|---|---|
| 1 Controller out of the box (menus and gameplay) | NOT RUN | device session pending |
| 2 Borderless/fullscreen, no white border | NOT RUN | device session pending |
| 3 Automatic OSK for every exposed text field | NOT RUN (audited absence, section 5.2) | this document; device confirmation pending |
