/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C99C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80029124(s32, s32);
extern s32 func_80029178(s32 arg);
extern s32 func_8016F1AC(void);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern void func_80029124(s32 a0, s32 a1);
extern void func_80139914(s32 a0);

void func_8014C99C(u8 *a0) {
    if ((func_80029178(0x119) & 0xFF) != 0) {
        if (func_8016F1AC() != 0) {
            func_80139914(*(s32 *)(a0 + 0x198));
            *(s32 *)(a0 + 0x198) = 0;
            func_80029124(0x119, 0);
        }
    }
}
