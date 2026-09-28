/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150BC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u8 func_8014BF6C(void);
extern u16 D_800B99DA;
extern s32 func_80151184(s32 a0, s32 a1, s32 a2);
extern s32 func_801619D0(void *a0);
extern u8 func_8014BF6C(void);

void func_80150BC8(s32 *a0) {
    if (func_801619D0(a0) != 0) {
        if (D_800B99DA & 0x7) {
            func_80146994(0x34, (s32)a0, 0, 0);
        }
    } else {
        if ((func_8014BF6C() & 0xFF) == 0) {
            func_80151184((s32)a0, 0xC003, 0x10);
        }
    }
}
