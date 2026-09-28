/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFCAC - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 *D_80126B10;
extern s32 func_801789AC(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_80174438(s32 a0);

void func_801EFCAC(void *param_1) {

    extern s32 D_801EFF84;

    switch (*(u16 *)((s32)param_1 + 0x34)) {
    case 0:
        if (func_801789AC((s32)param_1) != 0) {
            func_80178CBC((s32)param_1, (s32)&D_801EFF84);
            *(u16 *)((s32)param_1 + 0x34) = 1;
        }
        break;
    case 1:
        if (func_801789AC((s32)param_1) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)param_1 + 0x34) = 2;
        }
        break;
    case 2:
        break;
    }
}
