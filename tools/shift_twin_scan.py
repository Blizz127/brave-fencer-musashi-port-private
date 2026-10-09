#!/usr/bin/env python3
"""Shifted-twin scan (B28 inc 105): usage shift_twin_scan.py <vram hex> <size hex>.
Finds sibling-member code with the same instruction shape as sc02_0035 at
<vram> (opcode/registers equal; immediates and jal targets masked) at any
address, and whether a registry row of that size starts there."""
import sys,json,glob,struct;sys.path.insert(0,'tools');import native_lane_gen as g
reg=json.load(open('provenance/matches.json'))['matches']
def mask(w):
    op=w>>26
    if op in (2,3): return op<<26
    if op==0: return w
    return w&0xFFFF0000
def run(V,size,tgt='sc02_0035'):
    a=[mask(x) for x in g.retail_words(V,size,g.member_info(tgt))]
    n=len(a); hits=[]
    starts={}
    for m in reg: starts.setdefault(m['region'],{})[m['vram']]=m
    for c in sorted(glob.glob('config/overlay_*.yaml')):
        mem=c.split('overlay_')[1][:-5]
        if mem==tgt: continue
        info=g.member_info(mem)
        if not info: continue
        for (lo,hi) in info['code']:
            w=g.retail_words(lo,hi-lo,info)
            mw=[mask(x) for x in w]
            for i in range(len(mw)-n+1):
                if mw[i]==a[0] and mw[i:i+n]==a:
                    addr=lo+4*i; row=starts.get(mem,{}).get(addr)
                    hits.append((mem,hex(addr),bool(row) and row['size']==size, row and row['recovery']))
    return hits
if __name__=='__main__':
    print(run(int(sys.argv[1],16),int(sys.argv[2],16)))
