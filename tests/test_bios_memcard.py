"""The BIOS memory-card file device over a 128 KiB image (host-owned HLE)."""
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]


def test_bios_memcard_file_device():
    with tempfile.TemporaryDirectory(prefix="musashi-bios-memcard-") as temp:
        probe = Path(temp) / "probe"
        subprocess.run([
            "cc", "-std=c99", "-Wall", "-Wextra", "-Werror",
            "-ffunction-sections", "-fdata-sections", "-Wl,--gc-sections",
            "-I", str(ROOT / "pc_port/include"),
            "-I", str(ROOT / "pc_port/platform"),
            str(ROOT / "tests/bios_memcard_probe.c"),
            str(ROOT / "pc_port/bios_memcard.c"),
            str(ROOT / "pc_port/bios_events.c"),
            str(ROOT / "pc_port/boot_memory.c"),
            str(ROOT / "pc_port/platform/bfm_plat_storage.c"),
            "-o", str(probe), "-lcrypto",
        ], check=True, timeout=60)
        out = subprocess.run([str(probe)], check=True, timeout=10,
                             capture_output=True, text=True).stdout
        assert "bios_memcard probe ok" in out
        for mode in ("write", "read"):
            subprocess.run([str(probe), temp, mode], check=True, timeout=10,
                           capture_output=True, text=True)
        card = Path(temp, "bfm_card0.mcd").read_bytes()
        assert len(card) == 131072
        assert card[128] == 0x51 and card[136:138] == b"\xff\xff"
        assert card[8192 + 0x480:8192 + 0x780] == bytes(i * 7 % 256 for i in range(0x300))
        assert not Path(temp, "bfm_card0.mcd.tmp").exists()
