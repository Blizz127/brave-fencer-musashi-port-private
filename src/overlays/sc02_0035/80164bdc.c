/* SC02.CD member35 [80164BDC,80164CD4): twin of main_0012 80164BDC (src/overlays/main_0012/80164bdc.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80164BDC,80164CD4) from MAIN.CD member 0012.
 * SHA256(span)=eaf60335c17114f4d664c4049c15e71afbfbaca8b1a5309c594c64e3d245ef61.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164BDC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800233CC(void *, unsigned short);
extern void func_80146578(void);
extern void func_80146CA0(void *a0);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_80164DD0(s32 a0);
extern void func_80164DB0(s32);

void func_80164BDC(s32 param_1)
{

    extern u8 D_801BD840;
    extern u8 D_801BD841;
    extern u8 D_801BD842;
    extern u8 D_801BD843;
    extern u8 D_801BD844;
    extern u8 D_801BD845;
    extern u8 D_801BD846;
    extern u8 D_801BD847;
    register s32 p1   __asm__("$17");   
    register s32 iVar1 __asm__("$16");   
    register s32 base __asm__("$18");   

    p1 = param_1;
    iVar1 = ((s32 (*)(void))func_80146578)();
    base = (s32)&D_801BD840;
    *(s32 *)(p1 + 0x20) = iVar1;
    if (iVar1 != 0) {
        func_8001CD50(iVar1, base);
        ((void (*)(s32, s32))func_800233CC)(base, 0x60);
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        D_801BD841 = 0xf0;
        *(u8 *)base = 0xf0;
        D_801BD842 = 0xc0;
        D_801BD846 = 0;
        D_801BD845 = 0;
        D_801BD844 = 0;
        D_801BD847 = 0;
        D_801BD843 = 0;
        *(s16 *)(iVar1 + 0x1e) = 0xccc;
        *(s16 *)(iVar1 + 0x10) = 0x400;
        *(s16 *)(p1 + 0x60) = 0x700;
        *(s16 *)(p1 + 0x62) = -0x60;
        func_80164DD0(p1);
        ((void (*)(s32))func_80146CA0)(p1);
    } else {
        ((void (*)(s32))func_80164DB0)(p1);
    }
}
