/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151780 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8011DB1A;
extern s32 D_80127518;
extern s32 D_801151FC;
extern s32 func_801725CC(u8 *a0);
extern s32 func_80029D3C(void);
extern void func_80151878(void);
extern void func_80153B58(s32 *a0);

void func_80151780(s32 a0) {
    u8 idx;
    s32 *tbl;
    s32 fp;
    idx = *(u8 *)(a0 + 0xDD);
    tbl = *(s32 **)(a0 + 0x1F0);
    if (idx != 0 && idx < 0x21) {
        fp = tbl[idx - 1];
        if (fp != 0) {
            ((s32 (*)(s32))func_801725CC)(a0);
            {
                register s32 cur __asm__("$4");
                cur = D_8011DB1A;
                if (cur != 1000) {
                    D_8011DB1A = func_80029D3C();
                }
            }
            (*(void (**)(s32))((s32)tbl + (s32)(*(u8 *)(a0 + 0xDD)) * 4 - 4))(a0);
            D_801151FC = D_80127518;
        } else {
            ((void (*)(s32))func_80151878)(a0);
        }
    } else {
        (*(void (**)(s32))((s32)tbl + 8))(a0);
    }
    if ((*(u16 *)(a0 + 0xF0) & 0x200) != 0) {
        ((void (*)(s32))func_80153B58)(a0);
    }
    return;
}
