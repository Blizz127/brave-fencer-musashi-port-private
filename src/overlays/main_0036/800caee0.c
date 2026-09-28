/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C088(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801655E4(s32 a0);
extern void func_80165958(void);

void func_800CAEE0(u8* a0)
{
    s32 v0 = func_8014C088((s32)a0, 0x22);

    if (v0 != 0) {
        func_801599A4(a0);
        func_80159B3C(a0);
    } else {
        func_801655E4((s32)a0);
        func_80165958();
        *((u8 *)a0 + 0x197) += 1;
    }
}
