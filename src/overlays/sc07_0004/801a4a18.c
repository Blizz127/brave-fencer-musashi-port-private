/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4A18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80132288(s32 *a0, s32 *a1, s32 a2);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 D_801F8888;
extern s32 D_801F8898;
extern s32 D_801B007C;
extern s32 D_801B00B4;
extern s32 D_801B75EC;
extern u8 D_801B80FC[];

void func_801A4A18(s32 a0)
{
    s16 cond;
    s32 mirror;

    cond = *(s16 *)(a0 + 0x70);
    mirror = *(s32 *)(a0 + 0xCC);

    if (cond == 0) {
        func_80132288(&D_801F8888, &D_801B007C, D_801B75EC);
        if (mirror != 0) {
            func_80132288(&D_801F8898, &D_801B00B4, (*(s32 *)D_801B80FC));
        }
    }

    *(s16 *)(a0 + 0x84) = 0;
    func_8012AD44((s32 *)a0, 2);
}
