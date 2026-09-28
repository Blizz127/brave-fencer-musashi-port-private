/* Exact retail word export for [8001FB8C,8001FC08); EXE and assembly verified. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8001FB8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern void (*D_80063500[])();

void func_8001FB8C(s32 *obj, s32 *count) {
    if (obj[1] < 0) return;
    if (*(u16 *)obj != 1) return;
    if (*(u16 *)((u8 *)obj + 2) < 9) {
        D_80063500[*(u16 *)((u8 *)obj + 2)](obj);
        count[0]++;
    }
}
