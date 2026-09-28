/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801734BC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80174684(void *);
extern s16 D_80126B32;
extern s16 D_80126B3E;

void func_801734BC(s32 arg0, s32 _unused1) {
    extern void func_80173544(void);
    extern s16 D_80126B40;

    s16 temp;
    switch (((u32)arg0)) {
    case 0: temp = -0x4; break;
    case 1: temp = -0x8; break;
    case 2: temp = -0x12; break;
    case 3: temp = -0x18; break;
    case 4: temp = -0x1C; break;
    default: goto after;
    }
    D_80126B32 = temp;
after:
    D_80126B3E = 0;
    D_80126B40 = 0;
    func_80174684(&func_80173544);
}
