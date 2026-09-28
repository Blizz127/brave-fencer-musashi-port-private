/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFC80 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32, s32);
extern void func_8014B2A8(void);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_801EFC80(void) {
    func_8014B2A8();
    ((s32 (*)(s32, s32))func_8002D4C8)(0x464, 0);
}
