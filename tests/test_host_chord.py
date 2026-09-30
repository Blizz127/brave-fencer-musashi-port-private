"""Headless SDL virtual controller coverage for the dev-menu chord."""
from pathlib import Path
import os
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]


def test_host_chord():
    flags = subprocess.check_output(["pkg-config", "--cflags", "--libs", "sdl2"], text=True).split()
    with tempfile.TemporaryDirectory(prefix="bfm-host-chord-") as tmp:
        probe = Path(tmp) / "probe"
        subprocess.run(["cc", "-std=c99", "-Wall", "-Wextra", "-Werror",
                        "-I", str(ROOT / "pc_port/include"),
                        str(ROOT / "tests/host_chord_probe.c"), "-o", str(probe), *flags],
                       check=True, timeout=60)
        result = subprocess.run([str(probe)], check=True, timeout=10,
                                env={**os.environ, "SDL_VIDEODRIVER": "dummy"},
                                capture_output=True, text=True)
        assert "host chord probe ok" in result.stdout
