"""Tripwires for the owner handheld gate's check 3 (text entry), audited in
docs/HANDHELD-AUDIT-r49e.md.

The audited claim is: no text field is reachable in the shipped package by
default. These tests do not prove that on a device. They fail the day the
source stops supporting the claim, so the audit is redone (and, if a text
field really appears, the Steam on-screen keyboard or a built-in pad keyboard
is wired) instead of the claim quietly going stale.
"""
from functools import lru_cache
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
# Host-side code only: src/ is guest (decompiled) code and cannot call SDL.
CODE_DIRS = ("pc_port", "include")
CODE_SUFFIXES = {".c", ".cpp", ".h"}
AUDIT = "docs/HANDHELD-AUDIT-r49e.md"

INPUT_SDL = "pc_port/platform/backends/input_sdl.c"


@lru_cache(maxsize=1)
def code_files():
    out = {}
    for d in CODE_DIRS:
        base = ROOT / d
        if not base.is_dir():
            continue
        for p in sorted(base.rglob("*")):
            if p.is_file() and p.suffix in CODE_SUFFIXES:
                out[str(p.relative_to(ROOT))] = p.read_text(errors="replace")
    return out


def users_of(token):
    """Repo-relative paths of production sources that mention token."""
    return [rel for rel, text in code_files().items() if token in text]


def function_body(text, signature):
    m = re.search(signature + r"[^{;]*\{\n(.*?)\n\}\n", text, re.S)
    assert m, "function not found: " + signature
    return m.group(1)


def launch_sh():
    text = (ROOT / "tools/package_legion.sh").read_text()
    m = re.search(r"cat > \"\$stage/launch\.sh\" <<'SH'\n(.*?)\nSH\n", text, re.S)
    assert m, "launch.sh heredoc not found in tools/package_legion.sh"
    return m.group(1)


def test_launch_sh_never_enables_the_platform_input_backend():
    # The sdl input backend (the only SDL_StartTextInput caller) opens only under
    # MUSASHI_INPUT=bfm_plat; a launch.sh that exports it would expose the console.
    assert "MUSASHI_INPUT" not in launch_sh(), \
        "launch.sh now mentions MUSASHI_INPUT: check 3 must be re-audited (" + AUDIT + ")"


def test_text_input_is_started_only_by_the_console_backend():
    for token in ("SDL_StartTextInput", "SDL_StopTextInput", "SDL_SetTextInputRect",
                  "SDL_TEXTINPUT", "SDL_TEXTEDITING"):
        assert users_of(token) in ([], [INPUT_SDL]), \
            "%s appears outside input_sdl.c: a new text-entry path needs the OSK review in %s (got %s)" % (
                token, AUDIT, users_of(token))
    assert users_of("SDL_StartTextInput") == [INPUT_SDL]


def test_nothing_opens_urls_or_the_steam_keyboard_yet():
    # When a text field is introduced, the OSK decision belongs in the audit doc first.
    assert users_of("SDL_OpenURL") == [] and users_of("steam://") == [], \
        "a Steam/URL call appeared: update " + AUDIT


def test_native_boot_and_dev_menu_have_no_text_input_apis():
    for rel in ("pc_port/native_boot.c", "pc_port/dev_menu.c"):
        text = (ROOT / rel).read_text()
        for token in ("SDL_StartTextInput", "SDL_TEXTINPUT", "SDL_TEXTEDITING", "SDL_SetTextInputRect"):
            assert token not in text, "%s uses %s: re-audit check 3 (%s)" % (rel, token, AUDIT)


def test_plat_start_forces_the_null_input_backend():
    body = function_body((ROOT / "pc_port/native_boot.c").read_text(), r"static void plat_start\(MusashiBootMemory \*memory\)")
    assert re.search(r'snprintf\(cfg\.input, sizeof cfg\.input, "null"\)', body), \
        "plat_start no longer forces the null input backend: re-audit check 3 (%s)" % AUDIT


def test_plat_input_attach_needs_the_opt_in_environment():
    body = function_body((ROOT / "pc_port/native_boot.c").read_text(), r"static void plat_input_attach\(void\)")
    assert 'getenv("MUSASHI_INPUT")' in body
    assert re.search(r'if \(!want \|\| strcmp\(want, "bfm_plat"\) != 0\) return;', body), \
        "plat_input_attach is no longer env-gated: re-audit check 3 (%s)" % AUDIT


def test_console_toggle_is_reachable_only_through_the_frame_hook():
    assert sorted(users_of("bfm_plat_console_ui_toggle")) == [
        "pc_port/platform/bfm_plat.c", "pc_port/platform/bfm_plat_console_ui.c",
        "pc_port/platform/bfm_plat_console_ui.h"]
    # bfm_plat_frame_begin runs hotkeys; native_boot reaches it only via the FRAME_BEGIN hook site.
    assert "pc_port/native_boot.c" not in users_of("bfm_plat_frame_begin")
    assert "pc_port/native_boot.c" not in users_of("bfm_plat_frame_wait")
    assert "pc_port/native_boot.c" not in users_of("bfm_plat_console_ui_open")


def test_no_password_fields_exist():
    for rel, text in code_files().items():
        text = text.lower()
        assert "password" not in text and "passwd" not in text, \
            "%s mentions a password: the gate requires masking, see %s" % (rel, AUDIT)
    assert "password" not in launch_sh().lower()
