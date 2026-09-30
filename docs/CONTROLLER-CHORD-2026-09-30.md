# Controller dev-menu chord follow-up

The owner requested Select/Back + Start on any controller, either order within
300 ms or held together, enabled in the package by default, with lone presses
still delivered to the game.

## r30 evidence

Read the Legion's existing `~/.local/state/bfm-port/last-run.log` over SSH;
no game was started or interrupted. It selected the x86-64-v3 binary and
opened a mapped Steam virtual `SteamOS Handheld Controller` (28de:12fb).
Log lines 32441–32445 contain Back down, joystick button 6 down, Start down,
joystick button 7 down, then `[DEV_MENU] open vblank=1307`. This demonstrates
that the held chord worked in that run.

Line 43249 has `[DEV_MENU] open vblank=2056`; line 45901 has
`[CHEATS] GOD MODE on`. Input diagnostics record only the first 64 events
individually. There are no individual input records around these later actions,
so the log cannot establish whether the second opening used F8 or the pad chord,
or which input selected God Mode. God Mode is not itself evidence of a chord.

## Changes for the next build

- Set `SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD=1` in the environment and
  SDL hints before initialization, along with background joystick events.
  The MM session's separate Legion experiment identified missing virtual-pad
  enumeration in launcher-started games; that experiment was not repeated here.
- Check every attached mapped controller and unmapped joystick by instance ID.
  Unmapped pads use Linux Xbox buttons 6/7 for Back/Start and hat 0 for navigation.
- Recognize both held, either press order, and the second press within 300 ms
  even after the first was released. Consume a chord once until both release.
- Delay lone presses for the chord window. Replay short taps for their measured
  frame count (minimum two); a lone held button reaches the game after the window.
  Replay advances at menu polling, not each guest pad sampling call.
- Log accepted chords with instance ID and mapped/raw source.

Package default and explicit menu-disable settings are unchanged.

## Verification and limits

`python3 -m pytest -q tests/test_host_chord.py tests/test_bios_memcard.py
 tests/test_input_controller_words.py tests/test_bios_input.py`: **4 passed**.
The headless SDL test uses a mapped virtual Xbox pad and an unmapped virtual
joystick. It checks the production button reader and chord arbiter, both orders,
released-first taps, sustained holds, the 300 ms boundary, lone tap replay,
lone held delivery, no retrigger, and SDL tick wraparound.

`build/musashi_dev_menu_probe`: **DEV_MENU_PASS**, including disabled parity.
`native_boot.c` compiled with the existing CMake flags; existing PsyCross,
OpenSSL-deprecation and path-truncation warnings remain. Compilation also exposed
and fixed a missing `bfm_plat_storage.h` include in the inherited memory-card edits.
`bash -n tools/package_legion.sh` and `git diff --check` passed.

This is source/probe verification, not an r31 package gate. No new game run,
Windows/XInput hardware test, release, tag, push, or new on-device binary test
was performed. The inherited memory-card edits remain separate and uncommitted;
their probe passes, but save-point/cold-title-load verification remains pending.
