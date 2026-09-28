/* Exact retail overlay 0010 export [800D2650,800D27DC), offset 0x23858. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2650 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u32 *ot;            /* 0x00 */
    u32 pad[4];         /* 0x04..0x13 */
} Env_800D2650;
typedef struct {
    u32 addr : 24;      /* 0x00 tag */
    u32 len  : 8;
} PTag_800D2650;
#define OT_800D2650             (D_800AE7BC[*(volatile u16 *)&D_800B9A02].ot)
#define getaddr_800D2650(t)     (((PTag_800D2650 *)(t))->addr)
#define setaddr_800D2650(t, v)  (((PTag_800D2650 *)(t))->addr = (u32)(v))
#define addPrim_800D2650(ot, p) (setaddr_800D2650(p, getaddr_800D2650(ot)), \
                                 setaddr_800D2650(ot, p))

u32 *func_800D2650(u32 *param_1, u8 *param_2, short param_3, short param_4, int a5, u32 a6)
{
    extern Env_800D2650 D_800AE7BC[];
    extern short D_800B9A02;

    register int cw __asm__("$2");
    register u32 s_a6 __asm__("$8") = a6;
    register u32 code __asm__("$14");
    register int clut __asm__("$13");
    register u8 bVar1 __asm__("$3");
    short sVar2;

    if (*param_2 < 0x80) {
        cw = 0x64000000;
        code = s_a6 | cw;
        cw = a5 + 0x100;
        clut = (cw << 6) | 0x16;
        do {
            sVar2 = *(short *)param_2;
            switch (sVar2) {
            case 0x1850:
            case 0x1858:
                *(short *)((u8 *)param_1 + 8) = param_3 + 4;
                *(short *)((u8 *)param_1 + 0xA) = param_4 - 7;
                break;
            case 0x3870:
                param_3 = param_3 + 7;
                param_2 = param_2 + 2;
                continue;
            case 0x3871:
                param_3 = param_3 + 4;
                param_2 = param_2 + 2;
                continue;
            case 0x3872:
                param_3 = param_3 + 2;
                param_2 = param_2 + 2;
                continue;
            default:
                *(short *)((u8 *)param_1 + 8) = param_3;
                *(short *)((u8 *)param_1 + 0xA) = param_4;
                param_3 = param_3 + 7;
                break;
            }
            *param_1 = 0x04000000;
            *(u32 *)((u8 *)param_1 + 4) = code;
            ((u8 *)param_1)[0xC] = *param_2;
            param_2 = param_2 + 1;
            sVar2 = 8;
            bVar1 = *param_2;
            param_2 = param_2 + 1;
            *(short *)((u8 *)param_1 + 0xE) = clut;
            ((u8 *)param_1)[0xD] = bVar1;
            *(short *)((u8 *)param_1 + 0x10) = sVar2;
            *(short *)((u8 *)param_1 + 0x12) = sVar2;
            addPrim_800D2650(&OT_800D2650[2], param_1);
            param_1 = param_1 + 5;
        } while (*param_2 < 0x80);
    }
    return param_1;
}
