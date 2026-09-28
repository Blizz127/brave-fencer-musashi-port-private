/* Exact retail word export for [8002E638,8002E700); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002E638 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u16 D_800A4E8E;
extern s16 D_800A4E86;
extern s32 D_80078F10;
extern u16 D_8006A99C[];
extern u16 D_800A46B8;
extern u8 D_8006AEEC;
extern s32 D_800A46B4;
extern u8 D_800A46BA;
extern u16 D_800A4EF4;

extern s32 func_8003836C(s32 a0);
extern void func_8002E700(s32 a0);

void func_8002E638(s32 a0) {
    s32 s0;
    s16 temp;
    u16 a0_masked;
    u16 v1;

    s0 = a0;

    if ((D_800A4E8E & 4) != 0) {
        temp = D_800A4E86;
        if ((func_8003836C(temp) << 16) != 0) {
            func_8002E700(s0 & 0xFFFF);
            return;
        }
    }

    if (D_80078F10 == 0) {
        return;
    }

    a0_masked = s0 & 0xFFFF;

    if (a0_masked < 5) {
        v1 = *(u16 *)((u8 *)D_8006A99C + a0_masked * 4);
    } else {
        v1 = 0x1F;
    }

    D_800A46B8 = v1;
    v1 = D_8006AEEC;
    D_800A46B4 = 0xFFFF;
    D_800A46BA = 1;
    D_800A4EF4 = v1;
}
