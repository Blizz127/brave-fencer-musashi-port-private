/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801650C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80162CCC(void);
extern void func_80162CCC();
extern void func_80165124(void *a0);
extern void func_801651B8(void *a0);

void func_801650C4(s32 *a0) {
    s16 v = *(u16 *)((s32)a0 + 0x62) - 0x10;
    *(u16 *)((s32)a0 + 0x62) = v;
    if (v < 0) {
        func_80162CCC();
    } else {
        func_80165124(a0);
        func_801651B8(a0);
    }
}
