/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB098 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C088(s32 a0, s32 a1);
extern s32 func_8014C168(s32 *arg0, s32 arg1);
extern s32 func_8014C088(s32 arg0, s32 arg1);

void func_800CB098(s32 a0) {
    s32 s0;
    s32 v1;

    s0 = func_8014C168((s32 *)a0, 0x15C);
    if (s0 != 0) {
        v1 = func_8014C088(a0, 1);
        if (v1 != 0 && *(u16 *)((s32)v1 + 2) != 0) {
            *(s32 *)((s32)s0 + 0xCC) = v1;
        } else {
            *(s32 *)((s32)s0 + 0xCC) = a0;
        }
    }
}
