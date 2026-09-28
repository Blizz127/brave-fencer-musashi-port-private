/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150820 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_8014ACE8(void *a0, s32 a1, s32 a2);
extern void func_8014BD24(s32 a0, s32 a1);
void func_8014BD24(s32 a0, s32 a1);
extern void func_8014ACE8(void *a0, s32 a1, s32 a2);

void func_80150820(s32 a0, s32 a1) {
    if (a1 != 0) {
        func_8014BD24(a0, a1);
        func_8014ACE8((void *)a0, 4, a1);
    }
}
