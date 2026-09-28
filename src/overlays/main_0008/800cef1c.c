/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEF1C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800167F0(s32 a0);
extern void func_80011818(s32 arg0);

void func_800CEF1C(void) {
    if (func_800167F0(4) & 0xFFFF) {
        func_80011818(12);
    }
}
