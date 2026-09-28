/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80162120 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800291DC(s32);
extern void func_800291C8(s32, s32);
extern int func_800291DC(int);
extern s32 func_800D0D7C(s32, s32);

void func_80162120(void) {
    s32 v0;
    if ((s16)func_800291DC(8) == 0) {
        v0 = func_800D0D7C(0, 1);
        func_800291C8(8, (s16)(v0 | 0x8000));
    }
}
