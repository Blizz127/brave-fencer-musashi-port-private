#!/usr/bin/env python3
"""Register one or more functions in provenance/matches.json, gated by the oracle.

Each function is rebuilt from its source and compared against retail exactly
as tools/verify_registry.py would compare it. Only a byte-exact MATCH is
written to the registry; anything less is reported and leaves no trace. A
function that is already registered, or whose size cannot be read from the
splat disassembly, is refused.

    python3 tools/register_match.py main 0x8002F658 src/main/8002f658.c
    python3 tools/register_match.py main 0x8002F658 src/main/8002f658.c --optimization=-O0
"""

from __future__ import annotations

import argparse
import sys
import tempfile
from pathlib import Path

import batch_match
import build_candidate
import match_function
import verify_registry
from retail_common import RetailError, load_json, write_json_atomic

REPO = Path(__file__).resolve().parents[1]
ASM_BY_REGION = {
    "main": REPO / "asm/main.s",
    "main_0007": REPO / "asm/overlays/main_0007/main_0007.s",
    "main_0012": REPO / "asm/overlays/main_0012/main_0012.s",
}


def function_size(region: str, vram: int) -> tuple[str, int]:
    asm = ASM_BY_REGION.get(region)
    if asm is None or not asm.is_file():
        raise RetailError(f"no splat disassembly known for region {region!r}")
    for function in batch_match.enumerate_functions(asm.read_text()):
        if function.vram == vram:
            return function.name, function.size
    raise RetailError(f"no function at 0x{vram:08X} in {asm.relative_to(REPO)}")


def gate(entry: dict, targets: dict) -> tuple[bool, str]:
    with tempfile.TemporaryDirectory(prefix="register_match.") as scratch:
        candidate = Path(scratch) / "candidate.bin"
        build_argv, match_argv = verify_registry.plan(entry, targets, candidate)
        code, out = verify_registry._quiet(build_candidate.main, build_argv)
        if code != 0 or not candidate.is_file():
            return False, "BUILD FAILED\n" + out
        code, out = verify_registry._quiet(match_function.main, match_argv)
        return code == 0, out


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("region")
    parser.add_argument("vram", type=lambda value: int(value, 0))
    parser.add_argument("source", type=Path)
    parser.add_argument("--optimization", default="-O2")
    parser.add_argument("--size", type=lambda value: int(value, 0),
                        help="override the splat size when splat split one real function into several")
    parser.add_argument("--recovery", default="c", choices=("c", "assembly", "mixed", "unclassified"))
    parser.add_argument("--registry", type=Path, default=REPO / "provenance/matches.json")
    args = parser.parse_args(argv)

    try:
        data = load_json(args.registry)
        entries = data["matches"]
        if any(e["region"] == args.region and int(e["vram"]) == args.vram for e in entries):
            raise RetailError(f"0x{args.vram:08X} is already registered in {args.region}")
        name, size = function_size(args.region, args.vram)
        if args.size is not None:
            if args.size < size or args.size % 4:
                raise RetailError(f"--size 0x{args.size:X} must be word-aligned and cover the splat range 0x{size:X}")
            size = args.size
        source = args.source.resolve().relative_to(REPO)
        entry = {
            "name": name,
            "vram": args.vram,
            "size": size,
            "region": args.region,
            "source": str(source),
            "recovery": args.recovery,
            "extent": "function",
            "optimization": args.optimization,
        }
        ok, out = gate(entry, data.get("targets", {}))
        if not ok:
            print(f"REFUSED {name}: not a byte-exact match\n{out}")
            return 1
        entries.append(entry)
        write_json_atomic(args.registry, data)
        print(f"REGISTERED {name} size=0x{size:X} {source} {args.optimization}")
        return 0
    except RetailError as exc:
        print(f"register_match: ERROR: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
