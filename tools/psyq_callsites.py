#!/usr/bin/env python3
"""Enumerate the Psy-Q library entry points that the game code calls.

Inputs (all local; nothing retail is written out):
  - vendor/bfm-decomp/config/splat.us.exe.yaml   Psy-Q segment ranges (snd*/lib*/apicard*)
  - vendor/bfm-decomp/config/symbols.us*.txt     names
  - vendor/bfm-decomp/src/<lib>.c                Psy-Q object labels (XXX_NN_OBJ_off)
  - this repo's game code: src/main/<vram>.c for 0x80010000..0x8003A444 and
    src/overlays/*/*.c. Call sites are the jal/j words in their committed
    MUSASHI_NATIVE_MIPS_WORD exports; files without an export contribute
    their C-level calls by name.

Outputs (facts only: addresses, names, counts):
  pc_port/platform/psyq/bfm_psyq_calls.json
  pc_port/platform/psyq/bfm_psyq_compat.def    X-macro table (with tools/psyq_compat_status.py)
  docs/PSYQ-COMPAT.md                           generated coverage report

  tools/psyq_callsites.py --vendor ../brave-fencer-musashi-decomp/vendor/bfm-decomp [--check]
--check regenerates in memory and fails if the committed outputs differ.
"""
from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import psyq_compat_status as status_table  # noqa: E402

GAME_MAIN_LO, GAME_MAIN_HI = 0x80010000, 0x8003A444
OUT_JSON = ROOT / "pc_port/platform/psyq/bfm_psyq_calls.json"
OUT_DEF = ROOT / "pc_port/platform/psyq/bfm_psyq_compat.def"
OUT_MD = ROOT / "docs/PSYQ-COMPAT.md"


def psyq_segments(vendor: Path):
    segs = []
    pat = re.compile(r"\s+- \[0x[0-9A-Fa-f]+, *\w+, *((?:snd|lib|apicard)\w*)\]\s*#.*?vram (0x[0-9A-Fa-f]+)-(0x[0-9A-Fa-f]+)")
    for line in (vendor / "config/splat.us.exe.yaml").read_text().splitlines():
        m = pat.match(line)
        if m:
            segs.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16)))
    return segs


def symbol_names(vendor: Path):
    names = {}
    for f in ("symbols.us.txt", "symbols.us.ram.txt"):
        p = vendor / "config" / f
        if not p.is_file():
            continue
        for line in p.read_text().splitlines():
            m = re.match(r"\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+);\s*//\s*func", line)
            if m:
                names.setdefault(int(m.group(2), 16), m.group(1))
    return names


def object_labels(vendor: Path, segs):
    """addr -> (object, offset) from the lib*.c INCLUDE_ASM / definition order."""
    out = {}
    for name, lo, hi in segs:
        p = vendor / "src" / f"{name}.c"
        if not p.is_file():
            continue
        entries = re.findall(r'(?:INCLUDE_ASM\("[^"]+", *(\w+)\)|^\w[\w\s\*]*?\b(\w+)\s*\([^;]*\)\s*\{)',
                             p.read_text(), re.M)
        seq = [a or b for a, b in entries]
        # anchor object labels: NAME_OBJ_off with a known object base once one func address is known
        for i, lab in enumerate(seq):
            m = re.match(r"(func_)([0-9A-Fa-f]{8})$", lab)
            if not m:
                continue
            addr = int(m.group(2), 16)
            for later in seq[i + 1:i + 6]:
                mm = re.match(r"(\w+?)_OBJ_([0-9A-Fa-f]+)$", later)
                if mm:
                    out[addr] = (mm.group(1) + ".o", None)
                    break
    return out


def gte_shape_names(words_by_addr):
    """Name libgte setters from their exact coprocessor-2 instruction shapes."""
    out = {}
    for addr, words in words_by_addr.items():
        ctc = [((w >> 16) & 31, (w >> 11) & 31) for w in words if (w >> 21) == 0x246]   # ctc2 rt, rd
        body = [w for w in words if w != 0]
        if not ctc:
            continue
        rds = [rd for _, rd in ctc]
        if rds == [26] and len(body) <= 3:
            out[addr] = "SetGeomScreen"
        elif rds == [24, 25] and len(body) <= 6:
            out[addr] = "SetGeomOffset"
    return out


def game_files():
    for f in sorted((ROOT / "src/main").glob("*.c")):
        try:
            a = int(f.stem[:8], 16)
        except ValueError:
            continue
        if GAME_MAIN_LO <= a < GAME_MAIN_HI:
            yield f, "main"
    for f in sorted((ROOT / "src/overlays").glob("*/*.c")):
        yield f, f.parent.name


def scan(vendor: Path):
    segs = psyq_segments(vendor)
    names = symbol_names(vendor)
    by_name = {v: k for k, v in names.items()}

    def seg_of(a):
        for n, lo, hi in segs:
            if lo <= a < hi:
                return n
        return None

    calls = collections.Counter()
    files_per = collections.defaultdict(set)
    binaries_per = collections.defaultdict(set)
    source_kind = collections.Counter()
    word_re = re.compile(r"MUSASHI_NATIVE_MIPS_WORD\((0x[0-9A-Fa-f]{8})\)")
    call_re = re.compile(r"\b(func_[0-9A-Fa-f]{8}|[A-Za-z_]\w*)\s*\(")
    nfiles = 0
    for f, binary in game_files():
        nfiles += 1
        text = f.read_text(errors="replace")
        words = [int(w, 16) for w in word_re.findall(text)]
        found = []
        if words:
            for w in words:
                if (w >> 26) in (2, 3):
                    found.append(0x80000000 | ((w & 0x3FFFFFF) << 2))
            kind = "word"
        else:
            body = text.split("#else", 1)[-1]
            for n in call_re.findall(body):
                if n.startswith("func_"):
                    found.append(int(n[5:], 16))
                elif n in by_name:
                    found.append(by_name[n])
            kind = "c"
        for t in found:
            if seg_of(t):
                calls[t] += 1
                files_per[t].add(str(f.relative_to(ROOT)))
                binaries_per[t].add(binary)
                source_kind[kind] += 1

    # instruction words for Psy-Q functions the repo exports (for shape naming)
    psyq_words = {}
    for f in sorted((ROOT / "src/main").glob("*.c")):
        try:
            a = int(f.stem[:8], 16)
        except ValueError:
            continue
        if seg_of(a):
            ws = [int(w, 16) for w in word_re.findall(f.read_text(errors="replace"))]
            if ws:
                psyq_words[a] = ws
    shapes = gte_shape_names(psyq_words)
    objects = object_labels(vendor, segs)

    entries = []
    for addr in sorted(calls):
        if addr in names and not names[addr].startswith("func_"):
            name, src = names[addr], "symbol"
        elif addr in shapes:
            name, src = shapes[addr], "shape"
        elif addr in status_table.INFERRED:
            name, src = status_table.INFERRED[addr][0], "inferred"
        else:
            name, src = "func_%08X" % addr, "unnamed"
        entries.append({
            "addr": "0x%08X" % addr,
            "name": name,
            "name_source": src,
            "evidence": status_table.INFERRED[addr][1] if src == "inferred" else None,
            "segment": seg_of(addr),
            "object": objects.get(addr, (None,))[0],
            "callsites": calls[addr],
            "files": len(files_per[addr]),
            "binaries": len(binaries_per[addr]),
        })
    meta = {"game_files": nfiles, "callsites": sum(calls.values()),
            "callsites_from_words": source_kind["word"], "callsites_from_c": source_kind["c"],
            "psyq_range": ["0x%08X" % min(s[1] for s in segs), "0x%08X" % max(s[2] for s in segs)]}
    return {"meta": meta, "entries": entries}


def render_def(data):
    lines = ["/* GENERATED by tools/psyq_callsites.py from vendor/bfm-decomp config + this repo's game code,",
             " * with statuses from tools/psyq_compat_status.py. Do not edit by hand.",
             " *",
             " * BFM_PSYQ(pc, name, status, argc, returns, wrapper)",
             " *   status  BFM_PSYQ_PSYCROSS | BFM_PSYQ_HLE | BFM_PSYQ_STUB (stub-TBD: the lane",
             " *           refuses and the interpreter runs the retail code from the disc)",
             " *   wrapper int wrapper(uint32_t *r) over the o32 register file; bfm_psyq_stub if none */", ""]
    for e in data["entries"]:
        st = status_table.lookup(e["name"], e["segment"])
        lines.append("BFM_PSYQ(%s, %s, BFM_PSYQ_%s, %d, %d, %s)" % (
            e["addr"], e["name"], st.status.upper().replace("-TBD", ""), st.argc, st.returns,
            st.wrapper or "bfm_psyq_stub"))
    return "\n".join(lines) + "\n"


def render_md(data):
    rows = []
    tally = collections.Counter()
    sites = collections.Counter()
    for e in data["entries"]:
        st = status_table.lookup(e["name"], e["segment"])
        tally[st.status] += 1
        sites[st.status] += e["callsites"]
        rows.append("| `%s` | %s | %s | %s | %d | %d | %s | %s |" % (
            e["addr"], e["name"] if e["name_source"] != "unnamed" else "*unnamed*",
            e["segment"], e["object"] or "", e["callsites"], e["binaries"], st.status, st.note))
    total, total_sites = len(data["entries"]), data["meta"]["callsites"]
    def pct(n, d):
        return "%.1f%%" % (100.0 * n / d) if d else "-"
    named = sum(1 for e in data["entries"] if e["name_source"] != "unnamed")
    inferred = sum(1 for e in data["entries"] if e["name_source"] == "inferred")
    out = ["# Psy-Q → PsyCross/HLE compatibility table (generated)", "",
           "Generated by `tools/psyq_callsites.py` (see `docs/ARCHITECTURE-PORT.md`,",
           "\"Psy-Q compatibility layer\"). Do not edit; edit `tools/psyq_compat_status.py`",
           "and regenerate.", "",
           "Game code scanned: %d files (`src/main` 0x80010000–0x8003A444 and every overlay);"
           % data["meta"]["game_files"],
           "%d call sites into the Psy-Q range %s–%s (%d from exported jal/j words, %d from C)." % (
               total_sites, data["meta"]["psyq_range"][0], data["meta"]["psyq_range"][1],
               data["meta"]["callsites_from_words"], data["meta"]["callsites_from_c"]), "",
           "| Status | Entry points | Call sites |", "|---|---|---|"]
    for s in ("psycross", "hle", "stub-TBD"):
        out.append("| %s | %d (%s) | %d (%s) |" % (s, tally[s], pct(tally[s], total), sites[s], pct(sites[s], total_sites)))
    covered = tally["psycross"] + tally["hle"]
    covered_sites = sites["psycross"] + sites["hle"]
    out += ["| **covered (psycross + hle)** | **%d / %d (%s)** | **%d / %d (%s)** |" % (
        covered, total, pct(covered, total), covered_sites, total_sites, pct(covered_sites, total_sites)),
            "", "Named: %d / %d entry points (vendor symbols, libgte instruction shape, or %d inferred"
            % (named, total, inferred),
            "from call context: see `INFERRED` in tools/psyq_compat_status.py). The rest are listed",
            "by address and Psy-Q object for later naming.", "",
            "| Address | Name | Segment | Object | Call sites | Binaries | Status | Notes |",
            "|---|---|---|---|---|---|---|---|"] + rows
    return "\n".join(out) + "\n"


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--vendor", type=Path,
                    default=ROOT.parent / "brave-fencer-musashi-decomp/vendor/bfm-decomp")
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv)
    if not (args.vendor / "config/splat.us.exe.yaml").is_file():
        print("psyq_callsites: vendor tree not found at %s" % args.vendor, file=sys.stderr)
        return 2
    data = scan(args.vendor)
    outputs = {OUT_JSON: json.dumps(data, indent=1) + "\n", OUT_DEF: render_def(data), OUT_MD: render_md(data)}
    if args.check:
        bad = [str(p.relative_to(ROOT)) for p, text in outputs.items()
               if not p.is_file() or p.read_text() != text]
        if bad:
            print("psyq_callsites: stale: " + ", ".join(bad), file=sys.stderr)
            return 1
        return 0
    for p, text in outputs.items():
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text)
    print("psyq_callsites: %d entry points, %d call sites" % (len(data["entries"]), data["meta"]["callsites"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
