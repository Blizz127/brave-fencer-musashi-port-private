/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161D88 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800AE6B0;
extern void func_80029124(s32, s32);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern void func_80029124(s32 a0, s32 a1);
extern s32 func_80029178(s32);
extern s32 D_800AE6A8;
extern void func_800D1734(void *);
extern s32 D_80180818;

void func_80161D88(void) {
    if ((D_800AE6B0 & 0x80FFFFFF) == 0 && (D_800AE6A8 & 0x80FFFFFF) == 0 &&
        (func_80029178(0x141) & 0xFF) != 0) {
        func_80029124(0x141, 0);
        func_80029124(0x95, 1);
        func_800D1734(&D_80180818);
    }
}
