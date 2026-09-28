/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E5624 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_80029178(s32);
extern s32 func_80029178(s32 arg);
extern void func_80029124(s32 a0, s32 a1);

s32 func_801E5624(void) {
    s32 v1 = func_80029504();
    s32 flag;

    if ((u32)(v1 - 0xC8) >= 0x64U) {
        if (v1 < 0x12C || (func_80029178(0xFA) & 0xFF) == 0) {
            flag = 1;
        } else {
            flag = 0;
        }
    } else {
        flag = 0;
    }

    if (flag != 0) {
        if ((func_80029178(0x114) & 0xFF) == 0) {
            func_80029124(0x114, 1);
            return 1;
        }
    }
    return 0;
}
