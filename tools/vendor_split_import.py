#!/usr/bin/env python3
"""Vendor split import (B28 inc 106): vendor_split_import.py <member> <vendor TU .c>
<lo hex> <hi hex> <outdir>. Preprocesses one Druthulu/BFM-decomp TU with its own
include paths (BFM_VENDOR, default /workspace/druthulu-bfm), splits it into
top-level chunks (K&R definitions merged), and for each function in [lo,hi)
the member has no registry row for, writes a standalone file: the
declarations it transitively uses (earlier definitions as prototypes, vendor
symbol names renamed to their func_/D_ address form) plus the definition.
Each is compiled with gcc-2.7.2 -O2 and kept only if byte-identical to the
member's retail words (outdir/res.json). Installing them is separate."""
import sys,re,os,json,subprocess,struct
R=os.path.dirname(os.path.dirname(os.path.abspath(__file__))); V=os.environ.get('BFM_VENDOR','/workspace/druthulu-bfm')
sys.path.insert(0,R+'/tools'); import native_lane_gen as g
GTE_AS_MACROS='__asm__(\n    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\\n"\n    "    cop2 \\\\fake_op << 20 | \\\\gbg << 20 | \\\\sf << 19 | \\\\mx << 17 | \\\\v << 15 | \\\\cv << 13 | \\\\lm << 10 | \\\\op\\n"\n    ".endm\\n"\n    ".macro mvmva sf, mx, v, cv, lm\\n"\n    "    cop2op 0x04, 0x12, sf = \\\\sf, mx = \\\\mx, v = \\\\v, cv = \\\\cv, lm = \\\\lm\\n"\n    ".endm\\n"\n    ".macro op sf\\n"\n    "    cop2op 0x17, 0x0C, sf = \\\\sf\\n"\n    ".endm\\n"\n);\n'
TGT,tu,lo,hi,out=sys.argv[1],sys.argv[2],int(sys.argv[3],16),int(sys.argv[4],16),sys.argv[5]
os.makedirs(out,exist_ok=True)
pp=subprocess.run(['cpp','-P','-undef','-nostdinc','-I',V+'/include','-I',os.path.dirname(tu),'-Dmips','-D__GNUC__=2','-D__OPTIMIZE__','-Dpsx','-D_PSYQ','-D_MIPSEL','-D_LANGUAGE_C',tu],capture_output=True,text=True)
assert pp.returncode==0, pp.stderr[:2000]
src=pp.stdout
# split into top-level chunks
chunks=[];i=0;n=len(src);start=0;depth=0;par=0
while i<n:
    c=src[i]
    if c=='"' or c=="'":
        q=c;i+=1
        while i<n and src[i]!=q:
            if src[i]=='\\': i+=1
            i+=1
    elif c=='/' and src.startswith('/*',i):
        i=src.index('*/',i)+1
    elif c=='{': depth+=1
    elif c=='}':
        depth-=1
        if depth==0:
            j=i+1
            k=src.find(';',j); nl=src.find('\n',j)
            # struct/typedef ends with ; after }, function ends at }
            rest=src[j:j+200].lstrip()
            head=src[start:src.index('{',start)] if '{' in src[start:i] else ''
            aggregate=re.search(r'\b(typedef|struct|union|enum)\b|=',head) is not None
            # `} __attribute__((packed, aligned(1))) Name;` ends the typedef too
            if rest.startswith(';') or (aggregate and re.match(r'^(?:__attribute__\s*\(\(.*?\)\)\s*)?[\w\s\*,\[\]]*;',rest)):
                i=src.index(';',j)
            chunks.append(src[start:i+1]); start=i+1
    elif c==';' and depth==0:
        chunks.append(src[start:i+1]); start=i+1
    i+=1
chunks=[c for c in chunks if c.strip() and "labels.inc" not in c]
KR=re.compile(r'\bfunc_[0-9A-Fa-f]{8}\s*\(\s*[A-Za-z_][\w\s,]*\)\s*\n')
merged=[]
for c in chunks:
    if c.lstrip().startswith('{') and merged:
        k=len(merged)-1
        while k>=0 and not KR.search(merged[k]) and len(merged)-k<12: k-=1
        if k>=0 and KR.search(merged[k]):
            c=''.join(merged[k:])+c; del merged[k:]
    merged.append(c)
chunks=merged
FN=re.compile(r'^\s*(?:static\s+)?[\w\s\*]+?\b(func_[0-9A-Fa-f]{8}\w*)\s*\(([^;{]*)\)[^{]*\{',re.S)
ID=re.compile(r'\b[A-Za-z_]\w*\b')
info=[]
for c in chunks:
    m=FN.match(c)
    if m: info.append(('fn',m.group(1),c))
    else: info.append(('decl',None,c))
def declared(c):
    names=set()
    for m in re.finditer(r'\b(?:struct|union|enum)\s+(\w+)',c): names.add(m.group(1))
    t=re.sub(r'\{[^{}]*\}','{}',c)
    while re.search(r'\{[^{}]*\}',t) and '{}' not in t: t=re.sub(r'\{[^{}]*\}','{}',t)
    m=re.findall(r'(\w+)\s*(?:\[[^\]]*\])*\s*(?:\([^()]*\))?\s*(?:,|;|=)',t)
    names|=set(m)
    m=re.findall(r'\(\s*\*\s*(\w+)\s*(?:\[[^\]]*\]\s*)*\)',t); names|=set(m)
    for e in re.findall(r'\{([^{}]*)\}',c):
        if 'enum' in c: names|=set(re.findall(r'(\w+)\s*(?:=|,|$)',e))
    return names
decl_names=[declared(c) if k=='decl' else {name} for k,name,c in info]
reg=json.load(open(R+'/provenance/matches.json'))['matches']
SYMS={}
for line in open(V+'/config/symbols.us.txt'):
    m=re.match(r'^(\w+)\s*=\s*0x([0-9A-Fa-f]{8});(.*)$',line)
    if m and not re.match(r'^(func|D)_[0-9A-Fa-f]{8}$',m.group(1)) and len(m.group(1))>2:
        SYMS[m.group(1)]=(int(m.group(2),16),'func' in m.group(3))
have={m['vram'] for m in reg if m['region']==TGT}
# VIMPORT_REDO=<vram hex>,...: regenerate these even though they have rows
have-={int(x,16) for x in os.environ.get('VIMPORT_REDO','').split(',') if x}
tinfo=None if TGT=='main' else g.member_info(TGT)  # main: the executable's own words
res=[]; RODATA={}
for idx,(k,name,c) in enumerate(info):
    if k!='fn': continue
    if not re.fullmatch(r'func_[0-9A-Fa-f]{8}',name): continue
    v=int(name[5:],16)
    if not(lo<=v<hi) or v in have: continue
    need=set(ID.findall(c))-{name}
    keep=set(); changed=True
    while changed:
        changed=False
        for j in range(len(info)):
            if j==idx or j in keep or (info[j][0]=='decl' and j>idx): continue
            if decl_names[j]&need:
                keep.add(j); changed=True
                if info[j][0]=='decl': need|=set(ID.findall(info[j][2]))
                else:
                    hdr=info[j][2][:info[j][2].index('{')]
                    need|=set(ID.findall(hdr))
    # A D_ symbol the definition uses but no kept (earlier) chunk or the body
    # itself declares: take the first TU-scope decl of it, wherever it is.
    declared_here=set().union(*[decl_names[j] for j in keep]) if keep else set()
    body_decl=set(re.findall(r'\b(D_[0-9A-Fa-f]{8})\b[^;()]*;',c[c.index('{'):])) if '{' in c else set()
    for sym in sorted(set(re.findall(r'\bD_[0-9A-Fa-f]{8}\b',c))-declared_here):
        if re.search(r'extern[^;]*\b'+sym+r'\b',c): continue
        for j in range(len(info)):
            if info[j][0]=='decl' and sym in decl_names[j]:
                keep.add(j)
                more=set(ID.findall(info[j][2]))
                for k2 in range(min(j,idx)):
                    if info[k2][0]=='decl' and decl_names[k2]&more: keep.add(k2)
                break
    parts=[]
    for j in sorted(keep):
        kk,nm,cc=info[j]
        if kk=='fn':
            hdr=cc[:cc.index('{')].strip()
            if not re.search(r'\)\s*$',hdr):  # K&R: parameter declarations follow the list
                hdr=hdr[:hdr.index(nm)+len(nm)]+'()'
                hdr=re.sub(r'\s+',' ',hdr)
            parts.append(hdr+';')
        else: parts.append(cc.strip())
    body='/* %s: func_%s from Druthulu/BFM-decomp\n * src/%s/%s (preprocessed; only the declarations it uses),\n * byte-identical to the %s retail words (gcc-2.7.2 -O2). */\n'%(TGT,name[5:].upper(),os.path.basename(os.path.dirname(tu)),os.path.basename(tu),TGT)+'\n'.join(parts)+'\n\n'+c.strip()+'\n'
    if re.search(r'\bmvmva\b',c) and '.macro mvmva' not in body:
        body=body.replace('\n\n'+c.strip(), '\n'+GTE_AS_MACROS+'\n'+c.strip(),1)  # gte_macros.inc for GNU as
    for nm2,(a2,isf) in SYMS.items():
        if re.search(r'\b'+nm2+r'\b',body):
            body=re.sub(r'\b'+nm2+r'\b',('func_%08X' if isf else 'D_%08X')%a2,body)
    fn='%s/%08x.c'%(out,v); open(fn,'w').write(body)
    def build(link, rb):
        cmd=['python3',R+'/tools/build_candidate.py','--symbol',name,'--toolchain','gcc-2.7.2-psx','--optimization=-O2','--include',R+'/include','--link-base','0x%08X'%link,'--output',fn+'.bin']
        if rb is not None: cmd+=['--rodata-base','0x%08X'%rb]
        return subprocess.run(cmd+[fn],capture_output=True,text=True,cwd=R)
    def sx(x): return x-0x10000 if x&0x8000 else x
    def his(w):
        hi={}; out=[]
        for x in w:
            op=x>>26; rs=(x>>21)&31; rt=(x>>16)&31
            if op==0x0F: hi[rt]=(x&0xFFFF)<<16; out.append(None); continue
            out.append((hi[rs]+sx(x&0xFFFF))&0xFFFFFFFF if op in (0x09,0x23,0x21,0x25,0x24,0x20,0x2B) and rs in hi else None)
        return out
    link,rb=v,None; ok=False; r=None; tries=[]
    for attempt in range(4):
        r=build(link,rb)
        if r.returncode!=0 or not os.path.exists(fn+'.bin'): break
        b=open(fn+'.bin','rb').read(); cw=struct.unpack('<%dI'%(len(b)//4),b); w=g.retail_words(v,len(b),tinfo)
        if w is None: break
        if list(w)==list(cw): ok=True; break
        diff=[i for i,(x,y) in enumerate(zip(w,cw)) if x!=y]
        jd={((cw[i]&0x3FFFFFF)-(w[i]&0x3FFFFFF))*4 for i in diff if (w[i]>>26)==2 and (cw[i]>>26)==2}
        if jd and len(jd)==1 and all((w[i]>>26)==2 for i in diff) is not None and link==v:
            link=v-jd.pop(); tries.append('link'); continue
        hw,hc=his(w),his(cw)
        pairs={(hc[i],hw[i]) for i in range(len(w)) if hw[i] is not None and hc[i] is not None and hw[i]!=hc[i]}
        if pairs and rb is None:
            ca,ra=min(pairs)
            # candidate rodata starts at the first rodata address it references
            cstart=min(p[0] for p in pairs)
            rb=ra-(ca-cstart); tries.append('rodata'); continue
        break
    if ok and rb is not None: RODATA[v]=rb
    res.append((hex(v),ok,len(open(fn+'.bin','rb').read()) if os.path.exists(fn+'.bin') else 0, '' if r.returncode==0 else r.stderr[-300:], RODATA.get(v), link-v if ok else None))
json.dump(res,open(out+'/res.json','w'),indent=1)
print('ok',sum(1 for x in res if x[1]),'of',len(res))
