/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164BDC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146578(void);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_80164DD0(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80164DB0(void);
extern u8 D_801B6510;
extern u8 D_801B6511;
extern u8 D_801B6512;
extern u8 D_801B6513;
extern u8 D_801B6514;
extern u8 D_801B6515;
extern u8 D_801B6516;
extern u8 D_801B6517;

void func_80164BDC(s32 param_1)
{
    register s32 p1   __asm__("$17");  /* $s1 */
    register s32 iVar1 __asm__("$16");  /* $s0 */
    register s32 base __asm__("$18");  /* $s2 */

    p1 = param_1;
    iVar1 = ((s32 (*)(void))func_80146578)();
    base = (s32)&D_801B6510;
    *(s32 *)(p1 + 0x20) = iVar1;
    if (iVar1 != 0) {
        func_8001CD50(iVar1, base);
        ((void (*)(s32, s32))func_800233CC)(base, 0x60);
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        D_801B6511 = 0xf0;
        *(u8 *)base = 0xf0;
        D_801B6512 = 0xc0;
        D_801B6516 = 0;
        D_801B6515 = 0;
        D_801B6514 = 0;
        D_801B6517 = 0;
        D_801B6513 = 0;
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
