/* Exact retail word export for [80031BE0,80031CC8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80031BE0 - byte-exact against retail at -O2 (tools/register_match.py). */

extern void func_80031BE0(void);
extern s8 D_800A4F17;
extern u16 D_800A2BB0[];
extern u16 D_800BA108[];
extern void func_8003388C();

void func_80031BE0(void)
{
    u8 *e;
    s32 i;

    if (*(u8 *)&D_800A4F17 != 0) {
        return;
    }

    e = (u8 *)&D_800A4F17 - 0x82F;

    for (i = 0; i < 8; i++, e += 0x54) {
        u16 v1;

        D_800A2BB0[i] = *(u16 *)(e + 4);
        D_800BA108[i] = *(u16 *)(e + 6);

        v1 = *(u16 *)(e + 0) & 0x3F;
        switch (v1) {
        case 1:
            if (*(u16 *)(e + 8) != 0) {
                *(u16 *)(e + 8) = *(u16 *)(e + 8) - 1;
            }
            break;
        case 0:
            break;
        case 5:
            func_8003388C(e, i);
            break;
        }
    }
}
