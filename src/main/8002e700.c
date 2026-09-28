/* Exact retail word export for [8002E700,8002E79C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002E700 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u16 D_800A4E8E;
extern u16 D_800A4E8A;
extern s16 D_800A4E86;
extern s16 D_8006A9BC[];
extern u16 D_8006A9B0[];

extern s32 func_8003836C(s32 a0);
extern void func_8003819C(s32 a0, s32 a1, s32 a2, s32 a3);

void func_8002E700(s32 a0)
{
    u16 index;

    if ((D_800A4E8E & 0x4) == 0)
        return;

    if ((s16)func_8003836C(D_800A4E86) == 0)
        return;

    index = (u16)a0;
    if (index >= 5)
        index = 4;

    func_8003819C(D_800A4E86, 0, 0, D_8006A9BC[index]);
    D_800A4E8A = D_8006A9B0[index];
}
