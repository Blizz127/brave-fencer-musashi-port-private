/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A99A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A90D8;
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern Mtx32_801A90D8 D_800AE620;
extern s32 D_801B0738;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_801A99A4(s32 a0)
{
    Mtx32_801A90D8 mtx;
    s16 i;

    for (i = 0; i < 0x1000; i += 0x200) {
        s32 *obj = (s32 *)func_8012C658(0x34, 0x100, a0);
        if (obj != NULL) {
            mtx = D_800AE620;
            func_8004A0DC(i, &mtx);
            func_800484EC((s32)&mtx, (s32)&D_801B0738, (s32)obj + 0x10);
            *(s32 *)((s32)obj + 4) += *(s32 *)((s32)obj + 0x10);
            *(s32 *)((s32)obj + 0xC) += *(s32 *)((s32)obj + 0x18);
        }
    }
}
