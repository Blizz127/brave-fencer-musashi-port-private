/* Exact retail word export for [8002D240,8002D29C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002D240 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_800A4ECC;
extern u16 D_8006ADD8[];
extern u16 D_800A4E74;
extern u16 D_800A4ED4;
extern u16 D_800A4ED6;
extern void func_8003B45C(s32 *a0);

void func_8002D240(s32 a0) {
    s32 index = (a0 << 16) >> 15;
    s32 *p = &D_800A4ECC;
    u16 value = *(u16 *)((u8 *)D_8006ADD8 + index);

    *p = 0x6;
    D_800A4E74 = (u16)a0;
    D_800A4ED4 = value;
    D_800A4ED6 = value;

    func_8003B45C(p);
}
