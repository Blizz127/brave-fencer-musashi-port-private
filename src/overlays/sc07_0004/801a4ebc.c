/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4EBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A90D8;
typedef struct { s32 w0, w4, w8, wC; s16 h10, hpad; s32 t0, t1, t2; } Mat32_801A4EBC;
extern s32 D_801F888C;
extern Mtx32_801A90D8 D_800AE620;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_801A4FDC(void);
extern void func_801A5094(void);

void func_801A4EBC(u8 *a0)
{
    u8 *s1;
    Mat32_801A4EBC m;
    void *mp;
    s32 v0;
    s32 *p;

    s1 = a0;
    p = &D_801F888C;
    v0 = *(u16 *)p;
    if ((u32)(v0 - 2) < 3) {
        if (*p == 2) {
            func_8002D4C8(0xABE, 0);
        }

        m = *(Mat32_801A4EBC *)&D_800AE620;
        mp = &m;

        func_8004A0DC(*(s16 *)(*(s32 *)(*(s32 *)(s1 + 0x64) + 0x20) + 0x12), mp);

        m.t0 = *(s16 *)(*(s32 *)(s1 + 0x64) + 0x6);
        m.t1 = *(s16 *)(*(s32 *)(s1 + 0x64) + 0xA);
        m.t2 = *(s16 *)(*(s32 *)(s1 + 0x64) + 0xE);

        func_8004914C(mp);
        func_800491AC(mp);
        func_801A4FDC();
        func_801A5094();
    }
}
