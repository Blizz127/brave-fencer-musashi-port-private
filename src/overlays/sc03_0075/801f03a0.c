/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F03A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80029124(s32, s32);
extern void func_80029124(s32 arg0, s32 arg1);

void func_801F03A0(void) {
        func_80029124(0xF5, 1);
        func_80029124(0xFB, 1);
    }
