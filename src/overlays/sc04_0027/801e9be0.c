/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E9BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 *func_801E9BE0(s32 *out) {
    typedef struct { u32 addr : 24; u32 len : 8; } PTag_801E9BE0;
    typedef struct { u32 *ot; u32 pad[4]; } Env_801E9BE0;   /* 0x14 stride */
    typedef struct { u16 f0; u16 f2; } Prim4_801E9BE0;
    typedef struct {
        s16 f0;                     /* 0x00 */
        s16 f2;                     /* 0x02 */
        void *f4;                   /* 0x04 */
        void *f8;                   /* 0x08 */
        s16 fC;                     /* 0x0C */
        s16 fE;                     /* 0x0E */
        s16 f10;                    /* 0x10 */
        s16 f12;                    /* 0x12 */
        void *f14;                  /* 0x14 */
        Prim4_801E9BE0 *f18;        /* 0x18 */
        void *f1C;                  /* 0x1C */
    } Panel_801E9BE0;               /* 0x20 stride */

    extern Env_801E9BE0 D_800AE7BC[];
    extern u16 D_801EBB10[];
    extern u16 D_8011511A;
    extern s32 D_80115134;      /* fixed by this TU's file-scope decl */
    extern s16 D_8011512C;
    extern u16 D_80115116;
    extern s16 D_800B9A02;

    extern s32 func_8005A600(s32, s32, s32, s32, s32);

    Prim4_801E9BE0 *q;
    volatile u16 *pb;
    s32 n;
    s32 d;

    /* D_80115134 is an s32 table base here -- keep s32 arithmetic,
       fold +0x18 into the load displacement. */
    q = *(Prim4_801E9BE0 **)((*(s16 *)&D_8011511A << 5) + D_80115134 + 0x18);
    if (D_8011512C == 1) {
        n = D_801EBB10[D_80115116 & 7];
    } else {
        n = 0;
    }

    out[0] = 0x04000000;
    *((u8 *)out + 0xC) = 0x70;
    *((u8 *)out + 0xD) = 0x10;
    out[1] = 0x64808080;
    pb = (volatile u16 *)&D_800B9A02;
    *(u16 *)((u8 *)out + 0xE) = 0x4056;

    d = n - 0x60;                                   /* [L2] */
    *(s16 *)((u8 *)out + 0x8) = q->f0 + d;
    *(s16 *)((u8 *)out + 0xA) = q->f2 - 2;
    *(s16 *)((u8 *)out + 0x12) = 0x10;
    *(s16 *)((u8 *)out + 0x10) = 0x10;

    ((PTag_801E9BE0 *)out)->addr =
        ((PTag_801E9BE0 *)(D_800AE7BC[*pb].ot + 2))->addr;
    ((PTag_801E9BE0 *)(D_800AE7BC[*pb].ot + 2))->addr = (u32)out;

    out += 5;                                       /* [L1] */
    func_8005A600((s32)out, 0, 0, 0x15, 0);

    ((PTag_801E9BE0 *)out)->addr =
        ((PTag_801E9BE0 *)(D_800AE7BC[*pb].ot + 2))->addr;
    {
        u32 *op;
        register u32 v __asm__("$2");               /* [L3] */
        op = D_800AE7BC[*pb].ot;
        v = op[2];
        v = (v & 0xFF000000) | (((u32)out) & 0xFFFFFF);
        op[2] = v;
    }

    return out + 2;
}
