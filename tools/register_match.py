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


def splat_function(region: str, vram: int):
    asm = ASM_BY_REGION.get(region)
    if asm is None or not asm.is_file():
        raise RetailError(f"no splat disassembly known for region {region!r}")
    text = asm.read_text()
    for function in batch_match.enumerate_functions(text):
        if function.vram == vram:
            return text, function
    raise RetailError(f"no function at 0x{vram:08X} in {asm.relative_to(REPO)}")


def returns_at(text: str, function, size: int) -> bool:
    """True when the word two before ``size`` is `jr $ra`, i.e. a function ends there."""

    words = {addr: word for addr, word, _op in batch_match.instruction_words(text, function)}
    return words.get(function.vram + size - 8) == 0x03E00008


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
    parser.add_argument("--rodata-base", type=lambda value: int(value, 0),
                        help="retail address of the function's .rodata (switch tables)")
    parser.add_argument("--origin", help='provenance tag, e.g. "vendor-derived (Druthulu/BFM-decomp)"')
    parser.add_argument("--replace", action="store_true",
                        help="upgrade an existing non-C entry at this address (e.g. assembly) to the new source")
    parser.add_argument("--registry", type=Path, default=REPO / "provenance/matches.json")
    args = parser.parse_args(argv)

    try:
        data = load_json(args.registry)
        entries = data["matches"]
        existing = [i for i, e in enumerate(entries)
                    if e["region"] == args.region and int(e["vram"]) == args.vram]
        if existing and not args.replace:
            raise RetailError(f"0x{args.vram:08X} is already registered in {args.region}")
        if existing and entries[existing[0]].get("recovery") == "c":
            raise RetailError(f"0x{args.vram:08X} is already registered as C; --replace only upgrades non-C entries")
        if args.replace and not existing:
            raise RetailError(f"--replace given but 0x{args.vram:08X} is not registered in {args.region}")
        text, function = splat_function(args.region, args.vram)
        name, size = function.name, function.size
        if args.size is not None:
            if args.size <= 0 or args.size % 4:
                raise RetailError(f"--size 0x{args.size:X} must be positive and word-aligned")
            # splat sometimes folds a following function into this range; a
            # shorter size is accepted only where the retail code returns.
            if args.size < size and not returns_at(text, function, args.size):
                raise RetailError(f"--size 0x{args.size:X} is shorter than the splat range 0x{size:X} "
                                  "and does not end at a `jr $ra` + delay slot")
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
        if args.rodata_base is not None:
            entry["rodata_base"] = args.rodata_base
        if args.origin:
            entry["origin"] = args.origin
        ok, out = gate(entry, data.get("targets", {}))
        if not ok:
            print(f"REFUSED {name}: not a byte-exact match\n{out}")
            return 1
        if existing:
            previous = entries[existing[0]]
            if entry["size"] < int(previous["size"]):
                raise RetailError(f"replacement covers 0x{entry['size']:X} bytes, less than the existing 0x{int(previous['size']):X}")
            entries[existing[0]] = entry
        else:
            entries.append(entry)
        write_json_atomic(args.registry, data)
        print(f"REGISTERED {name} size=0x{size:X} {source} {args.optimization}")
        return 0
    except RetailError as exc:
        print(f"register_match: ERROR: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
