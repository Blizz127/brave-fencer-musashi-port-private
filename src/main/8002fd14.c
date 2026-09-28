/* Exact retail word export for [8002FD14,8002FDC8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002FD14 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s16 D_800A46CC;
extern u8  D_8006AEF4;

extern void  func_80037D74(void);
extern s32   func_8003C4F0(s32);
extern s32   func_8002FF0C(s32, s32);
extern void  func_8002D240(s32 a0);

int func_8002FD14(int buf, int len) {
    s32 result;
    s32 temp;

    if (D_800A46CC == 0) {
        func_80037D74();
        temp = func_8003C4F0(0);
        if (temp != 0) {
            D_8006AEF4 &= 0xFE;
            result = func_8002FF0C(buf, len);
        } else {
            result = 0;
        }
    } else {
        result = func_8002FF0C(buf, len);
    }

    if (result != 0) {
        if (buf == 0x1A) {
            func_8002D240(0x28);
        }
        return result;
    }

    return 0;
}
