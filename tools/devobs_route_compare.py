#!/usr/bin/env python3
"""Native-vs-deny route proof: compare two DEVOBS record streams.

MUSASHI_TRACE_DEVICE_OBS_FILE writes one record per device access, I_STAT
change and IRQ delivery: `KIND CYCLE PC A B C`. A batch of native functions
passes its route proof when the native leg and the leg that denies the batch
produce the same stream (and the same RAM and PAD trace, compared elsewhere).

One difference is explained, not waived (B18, docs/B18-TIMING-2026-10-03.md):
the thunk-return IRQ hold. When native code calls an interpreted function
through a thunk, that callee's `jr ra` delay slot has npc = the lane's return
sentinel, and pc_port/irq_scheduler.c holds an IRQ there until the call has
returned; it is delivered at the caller's resume pc, one slot later. Denying
a function turns a direct native-to-native call into such a thunk, so the
DENY leg delivers late; the native leg (and a fully interpreted run) delivers
in the slot. A hunk is accepted as this hold only if:

  - both sides have the same number of records, pairwise the same kind and
    the same A/B/C fields, and the same pc except on 'D' (delivery) records;
  - every 'D' pair has native pc S, deny pc R, where the retail word at S-4
    is `jr ra` and the word at R-8 is a `jal` (R is a call's resume pc);
  - every deny cycle is the native cycle plus the same shift d, and d is the
    interpreter cost of the retail instruction at S (tools/lane_cycles.py);
  - the streams are equal again after the hunk.

Anything else is DIFFER. Exit 0 for IDENTICAL or EXPLAINED, 1 for DIFFER,
2 for bad input. Retail words come from the user's own files (--exe for the
main EXE, --member NAME=FILE:VRAM:START for an overlay member).
"""
import argparse
import gzip
import itertools
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lane_cycles  # noqa: E402

JR_RA = 0x03E00008


class Code:
    """Retail words by guest address from the EXE and overlay members."""

    def __init__(self):
        self.spans = []   # (vram_lo, vram_hi, bytes, file_offset_of_vram_lo)

    def add_exe(self, data):
        t_addr, t_size = struct.unpack_from("<II", data, 0x18)
        self.spans.append((t_addr, t_addr + t_size, data, 0x800))

    def add_member(self, data, vram, start):
        self.spans.append((vram, vram + len(data) - start, data, start))

    def word(self, addr):
        for lo, hi, data, off in self.spans:
            if lo <= addr and addr + 4 <= hi:
                return struct.unpack_from("<I", data, off + addr - lo)[0]
        return None


def records(path):
    opener = gzip.open if str(path).endswith(".gz") else open
    with opener(path, "rt") as f:
        for line in f:
            yield line.split()


def classify_hunk(nat, deny, code):
    """None if the hunk is the thunk-return hold, else the reason."""
    shift = None
    deliveries = 0
    for a, b in zip(nat, deny):
        if len(a) != 6 or len(b) != 6 or a[0] != b[0] or a[3:] != b[3:]:
            return "records differ in kind or fields"
        d = int(b[1]) - int(a[1])
        if shift is None:
            shift = d
        elif d != shift:
            return "cycle shift not constant"
        if a[0] == "D":
            deliveries += 1
            s, r = int(a[2], 16), int(b[2], 16)
            jr, jal, slot = code.word(s - 4), code.word(r - 8), code.word(s)
            if jr != JR_RA:
                return f"native delivery pc {s:08x} is not a jr ra slot"
            if jal is None or jal >> 26 != 3:
                return f"deny delivery pc {r:08x} is not a call's resume pc"
            if shift != lane_cycles.insn_cost(slot):
                return f"shift {shift} is not the slot's cost {lane_cycles.insn_cost(slot)}"
        elif a[2] != b[2]:
            return "pc differs on a non-delivery record"
    if not deliveries:
        return "no delivery record in the hunk"
    if shift is None or shift <= 0:
        return "deny leg not later"
    return None


def compare(nat_records, deny_records, code, max_hunk=4096):
    """('IDENTICAL'|'EXPLAINED'|'DIFFER', hunks, detail)."""
    hunks, cur_n, cur_d, line = [], [], [], 0
    for a, b in itertools.zip_longest(nat_records, deny_records):
        line += 1
        if a is None or b is None:
            return "DIFFER", hunks, f"streams differ in length at record {line}"
        if a == b:
            if cur_n:
                why = classify_hunk(cur_n, cur_d, code)
                if why:
                    return "DIFFER", hunks, f"hunk ending at record {line - 1}: {why}"
                hunks.append((line - len(cur_n), len(cur_n), cur_n[-1][2], cur_d[-1][2]))
                cur_n, cur_d = [], []
            continue
        cur_n.append(a)
        cur_d.append(b)
        if len(cur_n) > max_hunk:
            return "DIFFER", hunks, f"hunk at record {line - len(cur_n) + 1} does not re-converge"
    if cur_n:
        return "DIFFER", hunks, "streams differ at the end"
    return ("EXPLAINED" if hunks else "IDENTICAL"), hunks, ""


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("native")
    ap.add_argument("deny")
    ap.add_argument("--exe", type=Path)
    ap.add_argument("--member", action="append", default=[], metavar="NAME=FILE:VRAM:START")
    args = ap.parse_args(argv)
    code = Code()
    try:
        if args.exe:
            code.add_exe(args.exe.read_bytes())
        for spec in args.member:
            _, rest = spec.split("=", 1)
            path, vram, start = rest.rsplit(":", 2)
            code.add_member(Path(path).read_bytes(), int(vram, 16), int(start, 16))
    except (OSError, ValueError) as e:
        print(f"devobs_route_compare: {e}", file=sys.stderr)
        return 2
    verdict, hunks, detail = compare(records(args.native), records(args.deny), code)
    for start, n, s, r in hunks:
        print(f"thunk-return hold: records {start}-{start + n - 1}, native delivery {s}, deny {r}")
    print(f"devobs_route_compare: {verdict} hunks={len(hunks)}" + (f" ({detail})" if detail else ""))
    return 0 if verdict in ("IDENTICAL", "EXPLAINED") else 1


if __name__ == "__main__":
    sys.exit(main())
