/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFC30 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern s32 func_80029504(void);
extern void func_80029124(s32, s32);

s32 func_801EFC30() {
    if ((func_80029178(0xF5) & 0xFF) != 0) {
        return 0;
    }
    if ((u32)(func_80029504() - 0xC8) < 0x190) {
        func_80029124(0xF5, 1);
        func_80029124(0x10F, 1);
        return 1;
    }
    return 0;
}
