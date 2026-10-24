#!/usr/bin/env python3
"""Classify LANE_RESUME_STALE pairs (dev-only counter output) by the call that stored the resume pc:
the jal at resume-8 names callee C. If C is an admitted native function WITHOUT a ledger (unmapped), the value
belongs to a direct call still on the native stack whose own guest call took it: the in-call class (kept by
design). If C is a mapped (ledger) native function, the value outlived its call: the leak class (must be 0).
Main-EXE words come from the EXE, overlay words from a RAM image taken on the same route.
  classify_stale.py RUN_LOG EXE RAM_BIN REPORT_JSON"""
import json
import re
import struct
import sys

log, exe, ram, report = sys.argv[1:5]
e = open(exe, 'rb').read()
r = open(ram, 'rb').read()
rep = json.load(open(report))
status = {}
for f in rep['functions']:
    if f.get('admitted'):
        status[(f['vram'])] = 'mapped' if f.get('ledger') else 'unmapped'


def word(a):
    if 0x80010000 <= a < 0x80010000 + len(e) - 0x800 and a < 0x80074800:
        return struct.unpack_from('<I', e, a - 0x80010000 + 0x800)[0]
    return struct.unpack_from('<I', r, a - 0x80000000)[0]


pat = re.compile(r'LANE_RESUME_STALE resume=([0-9a-f]{8}) target=([0-9a-f]{8}) calls=(\d+)')
tot = {}
rows = []
for line in open(log, errors='replace'):
    m = pat.search(line)
    if not m:
        continue
    res, tgt, n = int(m.group(1), 16), int(m.group(2), 16), int(m.group(3))
    w = word(res - 8)
    if (w >> 26) == 3:
        callee = ((res - 8) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
        cls = {'unmapped': 'in-call', 'mapped': 'LEAK'}.get(status.get(callee), 'other(%s)' % status.get(callee))
    else:
        callee, cls = None, 'not-a-jal(%08x)' % w
    tot[cls] = tot.get(cls, 0) + n
    rows.append((cls, n, res, tgt, callee))
for cls, n, res, tgt, callee in sorted(rows, key=lambda x: (x[0], -x[1])):
    print(f'{cls:10s} calls={n:6d} resume={res:08x} target={tgt:08x} stored-for={callee:08x}' if callee else
          f'{cls:10s} calls={n:6d} resume={res:08x} target={tgt:08x}')
print('TOTALS', json.dumps(tot, sort_keys=True))
