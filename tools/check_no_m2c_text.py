#!/usr/bin/env python3
"""Fail when C bound for the port carries m2c macro text.

include/m2c_macros.h is derived from m2c's GPL header. It is an allowed
input for drafting, but its text must not reach code that release builds
compile or that clean-room merge-back brings in. With no arguments this
checks every source behind config/lane_own_code_allow.txt (what
-DMUSASHI_LANE_OWN_CODE_ONLY=ON compiles); with arguments it checks those
files instead (use it on each merge-back batch before copying)."""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PATTERN = re.compile(r"m2c_macros|\bM2C_[A-Z0-9_]+")


def allow_list_sources():
    files = []
    for line in (ROOT / "config/lane_own_code_allow.txt").read_text().splitlines():
        pc = line.strip().lower()
        if not pc or pc.startswith("#"):
            continue
        found = sorted(ROOT.glob(f"src/main/{pc}.c")) + sorted(ROOT.glob(f"src/overlays/*/{pc}.c"))
        if not found:
            print(f"m2c check: allow-list entry {pc} has no source", file=sys.stderr)
        files += found
    return files


def main():
    files = [Path(a) for a in sys.argv[1:]] or allow_list_sources()
    bad = 0
    for path in files:
        for number, line in enumerate(path.read_text(errors="replace").splitlines(), 1):
            if PATTERN.search(line):
                print(f"{path}:{number}: m2c macro text: {line.strip()}")
                bad += 1
    print(f"m2c check: {len(files)} files, {bad} lines with m2c macro text")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
