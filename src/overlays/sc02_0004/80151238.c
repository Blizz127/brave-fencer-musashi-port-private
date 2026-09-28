/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80151238 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_8014ACE8(void *a0, s32 a1, s32 a2);
extern void func_8014ACE8(void *a0, s32 a1, s32 a2);

void func_80151238(void *a0) {
    s16 v0 = *(s16 *)((s32)a0 + 0xF2);
    if (v0 != 0) {
        func_8014ACE8(a0, 5, (s32)v0 & 0x7FFF);
    }
}
