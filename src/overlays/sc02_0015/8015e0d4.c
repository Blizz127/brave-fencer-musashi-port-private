/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015E0D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_8014C1A0(s32 arg0, s32 arg1);

int func_8015E0D4(int a0)
{
    s16 sp18[4];
    s32 s0;
    s0 = *(s32 *)(a0 + 0x178);
    if (s0 != 0) {
        func_8014C1A0(a0, s0);
        func_80015978(s0 + 4, (s32 *)sp18);
        sp18[3] = 0;
        func_8014C4AC(s0, 0x11, func_80029AAC(), sp18,
                      *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12));
        *(s32 *)(a0 + 0x178) = 0;
    }
}
