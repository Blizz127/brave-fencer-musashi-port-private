"""Focused source-level LWL/LWR/SWL/SWR fixture for the PVD reader."""
from pathlib import Path
import subprocess
import sys
import tempfile
import pytest

sys.path.insert(0, str(Path(__file__).parent))
from test_bios_event_callbacks import _generate_formatter_includes, _materialize_overlays, _sync_code_image

ROOT = Path(__file__).resolve().parents[1]


def _compile_probe(root, generated, probe_source):
    probe = root / "probe"
    subprocess.run([
        "cc", "-std=c99", "-Wall", "-Wextra", "-Werror",
        "-O2", "-Wno-parentheses",
        "-ffunction-sections", "-fdata-sections",
        "-Wl,--gc-sections",
        "-I", str(ROOT / "include"),
        "-I", str(ROOT / "pc_port/include"),
        "-I", str(ROOT / "pc_port"),
        "-I", str(generated),
        str(probe_source),
        str(ROOT / "pc_port/boot_memory.c"),
        "-lcrypto",
        "-o", str(probe),
    ], check=True, timeout=60)
    return probe


def test_pvd_merge_source_pairs_and_checked_memory():
    with tempfile.TemporaryDirectory(prefix="musashi-pvd-merge-") as temp:
        probe = Path(temp) / "probe"
        generated = Path(temp) / "generated"
        generated.mkdir()
        _generate_formatter_includes(generated)
        _materialize_overlays(generated)
        _compile_probe(Path(temp), generated, ROOT / "tests/pvd_merge_probe.c")
        _sync_code_image(generated)
        subprocess.run([str(probe)], check=True, timeout=10)


def test_pvd_merge_mutants_are_rejected_by_independent_oracle():
    formatter = (ROOT / "pc_port/mips_formatter.c").read_text()
    mutations = [
        (
            "bad LWL preserve mask",
            "0x00ffffffu, 0x0000ffffu",
            "0x00000000u, 0x0000ffffu",
        ),
        (
            "SWL no-op store",
            "!cpu_write32(memory, cpu, address & ~3u,\n                         merge_swl_value(memory_value, cpu->r[rt], address & 3u))",
            "!((merge_swl_value(memory_value, cpu->r[rt], address & 3u), 1))",
        ),
    ]
    for label, needle, replacement in mutations:
        assert formatter.count(needle) == 1, f"mutation needle drifted: {label}"
        with tempfile.TemporaryDirectory(prefix="musashi-pvd-merge-mutant-") as temp:
            root = Path(temp)
            generated = root / "generated"
            generated.mkdir()
            _generate_formatter_includes(generated)
            _materialize_overlays(generated)
            (root / "pc_port").mkdir()
            (root / "tests").mkdir()
            (root / "pc_port/mips_formatter.c").write_text(
                formatter.replace(needle, replacement)
            )
            (root / "tests/probe_code_words.h").write_text(
                (ROOT / "tests/probe_code_words.h").read_text())
            probe_source = root / "tests/pvd_merge_probe.c"
            probe_source.write_text(
                (ROOT / "tests/pvd_merge_probe.c").read_text()
                .replace('#include "../pc_port/mips_formatter.c"',
                         '#include "../pc_port/mips_formatter.c"', 1)
            )
            probe = _compile_probe(root, generated, probe_source)
            _sync_code_image(generated)
            result = subprocess.run([str(probe)], timeout=10,
                                    stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            assert result.returncode != 0, f"mutant survived: {label}"


@pytest.mark.parametrize("variant", ["baseline", "admission_mutant", "retire_mutant", "store_mutant"])
def test_packed_coordinate_source_copy(variant):
    formatter = (ROOT / "pc_port/mips_formatter.c").read_text()
    mutations = {
        "admission_mutant": ("{0x80021d88u,216u,MERGE_LWL}", "{0x80021d84u,216u,MERGE_LWL}"),
        "retire_mutant": ("{0x80021d90u, 216u, 2u}", "{0x80021d90u, 216u, 3u}"),
        "store_mutant": ("!cpu_write32(memory, cpu, address & ~3u,\n                         merge_swl_value(memory_value, cpu->r[rt], address & 3u))", "!((merge_swl_value(memory_value, cpu->r[rt], address & 3u), 1))"),
    }
    if variant in mutations:
        needle, replacement = mutations[variant]
        assert formatter.count(needle) == 1
        formatter = formatter.replace(needle, replacement)
    with tempfile.TemporaryDirectory(prefix="musashi-packed-coordinate-") as temp:
        root = Path(temp)
        generated = root / "generated"
        generated.mkdir()
        _generate_formatter_includes(generated)
        _materialize_overlays(generated)
        (root / "pc_port").mkdir()
        (root / "tests").mkdir()
        (root / "pc_port/mips_formatter.c").write_text(formatter)
        for name in ["probe_code_words.h", "pvd_merge_probe.c"]:
            (root / "tests" / name).write_text((ROOT / "tests" / name).read_text())
        probe = _compile_probe(root, generated, root / "tests/pvd_merge_probe.c")
        _sync_code_image(generated)
        result = subprocess.run([str(probe), "--packed-coordinate"], timeout=10,
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if variant == "baseline":
            assert result.returncode == 0, result.stderr.decode(errors="replace")
            assert b"Packed coordinates:" in result.stdout
        else:
            assert result.returncode != 0, f"mutant survived: {variant}"
