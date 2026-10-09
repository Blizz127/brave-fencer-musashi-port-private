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
            if rest.startswith(';') or re.match(r'^[\w\s\*,\[\]]+;',rest):
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
FN=re.compile(r'^\s*(?:static\s+)?[\w\s\*]+?\b(func_[0-9A-Fa-f]{8})\s*\(([^;{]*)\)[^{]*\{',re.S)
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
tinfo=g.member_info(TGT)
res=[]
for idx,(k,name,c) in enumerate(info):
    if k!='fn': continue
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
    body='/* SC02.CD member35: func_%s from Druthulu/BFM-decomp\n * src/ov_SC02_035/%s (preprocessed; only the declarations it uses),\n * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */\n'%(name[5:].upper(),os.path.basename(tu))+'\n'.join(parts)+'\n\n'+c.strip()+'\n'
    for nm2,(a2,isf) in SYMS.items():
        if re.search(r'\b'+nm2+r'\b',body):
            body=re.sub(r'\b'+nm2+r'\b',('func_%08X' if isf else 'D_%08X')%a2,body)
    fn='%s/%08x.c'%(out,v); open(fn,'w').write(body)
    r=subprocess.run(['python3',R+'/tools/build_candidate.py','--symbol',name,'--toolchain','gcc-2.7.2-psx','--optimization=-O2','--include',R+'/include','--link-base','0x%08X'%v,'--output',fn+'.bin',fn],capture_output=True,text=True,cwd=R)
    ok=False
    if r.returncode==0 and os.path.exists(fn+'.bin'):
        b=open(fn+'.bin','rb').read(); w=g.retail_words(v,len(b),tinfo)
        ok= w is not None and struct.pack('<%dI'%len(w),*w)==b
    res.append((hex(v),ok,len(open(fn+'.bin','rb').read()) if os.path.exists(fn+'.bin') else 0, '' if r.returncode==0 else r.stderr[-300:]))
json.dump(res,open(out+'/res.json','w'),indent=1)
print('ok',sum(1 for x in res if x[1]),'of',len(res))
