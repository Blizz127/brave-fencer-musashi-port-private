"""Host session helper for the owner handheld gate (pure logic, no display)."""
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]


def test_host_session_probe():
    with tempfile.TemporaryDirectory(prefix="bfm-host-session-") as tmp:
        probe = Path(tmp) / "probe"
        # -std=c99 -pedantic: the helper is shared with the Windows lane, so it stays portable C99.
        subprocess.run(["cc", "-std=c99", "-Wall", "-Wextra", "-Werror", "-pedantic",
                        "-I", str(ROOT / "pc_port/include"),
                        str(ROOT / "tests/host_session_probe.c"), "-o", str(probe)],
                       check=True, timeout=60)
        result = subprocess.run([str(probe)], check=True, timeout=30,
                                capture_output=True, text=True)
        assert "host session probe ok" in result.stdout
