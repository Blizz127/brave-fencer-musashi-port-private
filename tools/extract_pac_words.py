#!/usr/bin/env python3
"""Emit SC01 member 0's decoded PAC code stream as a C word initializer.

`pc_port/mips_formatter.c` includes `sc01_pac0_words.inc` to build
`kOverlaySc01_CodeWords`, the resident SC01 overlay image the formatter
compares live guest RAM against. The include has no checked-in source: unlike
the `extract_asm_words.py` seams, the words are not transcribed into a decomp
C file, they are the retail payload itself, so the only honest input is the
pinned disc archive.

The decode is `tools/decode_title_pac.py`, which pins SC01.CD by SHA-256 and
refuses an unexpected member extent or PAC header. The decoded payload runs
513935 bytes, three past the last whole instruction word, so those trailing
bytes are dropped rather than zero-padded into a fourth: padding would hand the
formatter an instruction retail never had, and the formatter only ever indexes
below `sizeof(kOverlaySc01_CodeWords)`. Only a sub-word remainder is tolerated;
`--expected-words` still fails the configure step on any other drift.

This is extraction evidence, not a substitute for guest execution.
"""
from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from decode_title_pac import title_code  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("archive", type=Path, help="pinned retail SC01.CD")
    parser.add_argument("output", type=Path)
    parser.add_argument("--expected-words", type=int, required=True)
    args = parser.parse_args()

    code = title_code(args.archive)
    whole = len(code) // 4
    words = struct.unpack(f"<{whole}I", code[:whole * 4])
    if len(words) != args.expected_words:
        raise SystemExit(
            f"{args.archive}: decoded {len(words)} words, expected "
            f"{args.expected_words}")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("".join(f"0x{word:08x}u,\n" for word in words))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
