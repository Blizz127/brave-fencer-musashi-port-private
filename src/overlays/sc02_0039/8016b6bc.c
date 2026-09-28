/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016B6BC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    int m0;
    int m1;
} M8_8016B6BC;
typedef struct {
    short x;
    short y;
} DVec_8016B6BC;
typedef struct {
    short x;    
    short y;    
    short c;    
    short pad;  
} Vtx_8016B6BC;
typedef struct {
    Vtx_8016B6BC v[3];        
    unsigned long combined;   
    unsigned long z1c;        
    unsigned long z20;        
    unsigned long color;      
} Prim_8016B6BC;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80013CFC(s32 a0, s32 a1, void *a2);
extern void func_8001739C(void *a0);

void func_8016B6BC(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {

    extern int D_801822C0;
    int iVar1;
    M8_8016B6BC *q;
    Prim_8016B6BC prim;
    Prim_8016B6BC *p = &prim;
    DVec_8016B6BC off;
    unsigned int v;
    unsigned int c;

    q = (M8_8016B6BC *)*(int *)((int)&D_801822C0 + ((param_4 << 0x10) >> 0xe));
    p->color = 0x50000000;
    c = (unsigned int)param_2;
    v = 0x20;
    if (c < 0x20) {
        v = c;
    }
    if (*(int *)(param_1 + 0x2c) == 0) {
        c = c | (v << 0x10 | v << 8);
    } else {
        c = c << 8 | v << 0x10 | v;
    }
    p->combined = c;
    iVar1 = (int)(short)param_3;
    p->z1c = 0;
    p->z20 = 0;
    func_80013CFC(iVar1, (int)q++, &p->v[0]);
    func_80013CFC(iVar1, (int)q++, &p->v[1]);
    func_80013CFC(iVar1, (int)q, &p->v[2]);
    func_80015978(param_1 + 4, (s32 *)&off);
    p->v[0].x += off.x;
    p->v[0].y += off.y;
    p->v[1].x += off.x;
    p->v[1].y += off.y;
    p->v[2].x += off.x;
    p->v[2].y += off.y;
    p->v[0].c = 3;
    func_8001739C(p);
}
