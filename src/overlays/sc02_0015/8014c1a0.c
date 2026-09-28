/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C1A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014C1C8(s32 arg0, s32 arg1, void *arg2);
extern u8 D_8017FE84[];

void func_8014C1A0(s32 arg0, s32 arg1) {
    func_8014C1C8(arg0, arg1, D_8017FE84);
}
