"""S3a: native libpad leaves vs the interpreted retail words (G1 differential).

tests/input_pad_leaf_probe.c runs the same script on two identical universes,
retail words vs native leaves, and compares guest RAM, the callback frame,
SIO/Timer2/I_STAT state, the per-byte SIO log, the clock and (per leaf) the
register file and budget. Each deliberate break in bfm_psyq_libpad.c must
make it report a difference."""
from pathlib import Path
import subprocess
import sys
import tempfile

import pytest

ROOT = Path(__file__).resolve().parents[1]
EXE = ROOT / "extracted/disc/files/SLUS_007.26"
sys.path.insert(0, str(Path(__file__).parent))
from test_bios_event_callbacks import _generate_formatter_includes, _sync_code_image

BREAKS = {1: "RC2 elapsed shifted by 2", 2: "E0AC I_STAT ack dropped",
          3: "DCA0 baud 0x89", 4: "E0AC CTRL |= 0x10 dropped",
          5: "E13C one extra cycle charge", 6: "DCA0 select byte not sent"}


def _build(root):
    generated = root / "generated"
    generated.mkdir()
    _generate_formatter_includes(generated)
    probe = root / "probe"
    subprocess.run([
        "cc", "-std=c99", "-Wall", "-Wextra", "-Werror",
        "-O2", "-Wno-parentheses", "-ffunction-sections", "-fdata-sections",
        "-Wl,--gc-sections", "-I", str(ROOT / "include"),
        "-I", str(ROOT / "pc_port/include"), "-I", str(generated),
        str(ROOT / "tests/input_pad_leaf_probe.c"),
        str(ROOT / "pc_port/boot_memory.c"),
        str(ROOT / "pc_port/sio_controller.c"),
        str(ROOT / "pc_port/timer2.c"), "-lcrypto", "-o", str(probe),
    ], check=True, timeout=120)
    _sync_code_image(generated)
    return probe


@pytest.mark.skipif(not EXE.is_file(), reason="no local disc extract")
def test_input_pad_leaf_differential_and_breaks():
    with tempfile.TemporaryDirectory(prefix="musashi-input-pad-leaf-") as temp:
        probe = _build(Path(temp))
        run = subprocess.run([str(probe), str(EXE)], capture_output=True, text=True, timeout=1800)
        sys.stderr.write(run.stderr[-6000:])
        assert run.returncode == 0, run.stderr[-3000:]
        assert "different=0" in run.stderr
        for n, name in BREAKS.items():
            broken = subprocess.run([str(probe), str(EXE), "--break", str(n)],
                                    capture_output=True, text=True, timeout=1800)
            assert broken.returncode == 0, f"break {n} ({name}) not detected"
