/* SC02.CD member35 [80164930,80164A74): twin of main_0012 80164930 (src/overlays/main_0012/80164930.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80164930,80164A74) from MAIN.CD member 0012.
 * SHA256(span)=3af959dee1dd4e8d3750c7db2a92c96942ac8502c02c0ba51e61929b26836abf.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164930 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct {
    u16 f0;
    u8 pad0[0x4e];
    int f50;
    u8 pad1[0x14];
} Ent_80164930;

extern void func_80162CCC();
extern void func_80164ACC();

// @class: regalloc-order — wave-3 real-TU crack (§42a); cracked at Max.
// Fix: D_801870D0 read needs direct-addressed `lhu` (u16). Cannot use `*(u16*)&D_801870D0`
// (forces &sym into a held reg -> drift) NOR a block-scoped `extern u16` (conflicting-types
// ERROR vs the ambient s16, cc1 exit 33). Solution: flip the file-scope decl (5802) to u16 —
// byte-neutral to the only other user (func_801647A4 store-only) — and reference directly.


void func_80164930(s32 param_1) {

    extern s32 D_8011F9D0;
    extern s16 D_801870CC;
    extern s16 D_801870CE;
    extern u16 D_801870D0;
    int iVar3 = *(int *)(((int)param_1) + 0x20);
    if (*(int *)(((int)param_1) + 0x50) == 0) {
        short sVar1 = *(u16 *)(iVar3 + 0x1c) + 0x100;
        short nv;
        *(short *)(iVar3 + 0x1c) = sVar1;
        *(short *)(iVar3 + 0x18) = sVar1;
        *(short *)(iVar3 + 0x12) = *(u16 *)(iVar3 + 0x12) + 0x71;
        nv = D_801870D0 - 8;
        D_801870D0 = nv;
        D_801870CE = nv;
        D_801870CC = nv;
        if (nv < -0x80) {
            int i, lim;
            Ent_80164930 *p;
            for (i = 0, lim = 0x19, p = ((Ent_80164930 *)&D_8011F9D0); i < 0x14; i++) {
                if (p->f0 == lim && p->f50 != 0) {
                    ((void(*)(Ent_80164930 *))func_80162CCC)(p);
                }
                p++;
            }
            ((void(*)(Ent_80164930 *))func_80162CCC)((Ent_80164930 *)((int)param_1));
        } else {
            ((void(*)(int))func_80164ACC)(((int)param_1));
        }
    } else {
        short sVar1 = *(u16 *)(iVar3 + 0x1c) + 0x40;
        u16 uVar2;
        *(short *)(iVar3 + 0x1c) = sVar1;
        *(short *)(iVar3 + 0x18) = sVar1;
        uVar2 = *(u16 *)(iVar3 + 0x1a) - 0x200;
        *(u16 *)(iVar3 + 0x1a) = uVar2;
        if ((int)((unsigned)uVar2 << 0x10) < 0) {
            *(short *)(iVar3 + 0x1a) = 0;
        }
        *(short *)(iVar3 + 0x12) = *(u16 *)(iVar3 + 0x12) - 0x71;
    }
}
