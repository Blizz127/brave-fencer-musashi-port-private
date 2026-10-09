#!/usr/bin/env python3
"""Twin port (B28 inc 104): usage twin_port.py <target member> <twins.json> <outdir>.
For overlay functions whose target-member retail words equal a sibling
member's registry function except in instruction immediates (global
addresses), derive the sibling->target address map from the hi/lo pairs of
both word streams, rename the D_<addr> symbols of the sibling's C, compile
each candidate with gcc-2.7.2 (tools/build_candidate.py) and keep only those
byte-identical to the target's retail words. twins.json maps "0x<vram>" to
[kind, sibling, size, ndiff, recovery]; only kind "imm" is ported. Writes
candidates and result.json (ok/bad) to outdir; installing them is separate."""
import sys,json,re,subprocess,struct,os
R=os.path.dirname(os.path.dirname(os.path.abspath(__file__))); sys.path.insert(0,R+'/tools'); os.chdir(R)
import native_lane_gen as g
TGT=sys.argv[1]; twins=json.load(open(sys.argv[2])); out=sys.argv[3]
reg=json.load(open('provenance/matches.json'))['matches']
rows={(m['region'],m['vram']):m for m in reg}
tinfo=g.member_info(TGT)
def sx(v): return v-0x10000 if v&0x8000 else v
def addrs(w):
    hi={}; res=[]
    for i,x in enumerate(w):
        op=x>>26; rs=(x>>21)&31; rt=(x>>16)&31; imm=x&0xFFFF
        if op==0x0F: hi[rt]=imm<<16; res.append((i,None)); continue
        if op in (0x09,0x0D,0x20,0x21,0x23,0x24,0x25,0x28,0x29,0x2B,0x22,0x26,0x2A,0x2E,0x32,0x3A) and rs in hi:
            a=(hi[rs]+(imm if op==0x0D else sx(imm)))&0xFFFFFFFF; res.append((i,a))
        else: res.append((i,None))
        if op in (0x09,0x0D,0x0F,0x20,0x21,0x23,0x24,0x25) and rt in hi and rt!=rs: hi.pop(rt,None)
        elif op in (0x09,0x0D,0x20,0x21,0x23,0x24,0x25) and rt==rs: hi.pop(rt,None)
    return res
ok=[];bad=[]
for v,(k,src,size,nd,rec) in sorted(twins.items()):
    if k!='imm': continue
    V=int(v,16); m=rows[(src,V)]
    a=g.retail_words(V,size,tinfo); b=g.retail_words(V,size,g.member_info(src))
    pa=dict(addrs(a)); pb=dict(addrs(b))
    mp={}
    for i in pa:
        if pa[i] is not None and pb.get(i) is not None and pa[i]!=pb[i]: mp[pb[i]]=pa[i]
    text=open(m['source']).read()
    def rep(mo):
        X=int(mo.group(1),16)
        ds={t-s for s,t in mp.items() if X<=s<X+0x2000}
        if len(ds)==1: return 'D_%08X'%((X+ds.pop())&0xFFFFFFFF)
        return mo.group(0)
    new=re.sub(r'\bD_([0-9A-Fa-f]{8})\b',rep,text)
    fn='%s/%08x.c'%(out,V)
    open(fn,'w').write(new)
    binf=fn+'.bin'
    r=subprocess.run(['python3','tools/build_candidate.py','--symbol','func_%08X'%V,'--toolchain','gcc-2.7.2-psx','--optimization='+m.get('optimization','-O2'),'--include','include','--include','src/overlays/'+TGT,'--include','src/overlays/'+src,'--link-base','0x%08X'%V,'--output',binf,fn],capture_output=True,text=True)
    good=r.returncode==0 and os.path.exists(binf) and open(binf,'rb').read()==struct.pack('<%dI'%len(a),*a)
    (ok if good else bad).append((v,src))
print('OK',len(ok),'BAD',len(bad)); json.dump({'ok':ok,'bad':bad},open(out+'/result.json','w'))
