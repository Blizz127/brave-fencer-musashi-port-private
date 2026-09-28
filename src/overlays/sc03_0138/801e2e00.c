/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2E00 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 *D_80126B10;
extern void func_800D1724(void *);
extern s32 func_801789AC(s32 a0);
extern void func_80174438(s32 a0);

void func_801E2E00(void *param_1) {

    extern u8 D_800D39CC[];
    extern void func_800D1724(void *);
    extern void func_80029124(s32, s32);
    s32 st;

    st = *(u16 *)((s32)param_1 + 0x34);
    switch (st) {
    case 0:
        if (func_801789AC((s32)param_1) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)param_1 + 0x34) = 2;
        }
        break;
    case 1:
        switch (func_801789AC((s32)param_1)) {
        case 1:
            func_800D1724(D_800D39CC);
            func_80029124(0xFF, 1);
            *(u16 *)((s32)param_1 + 0x34) = 2;
            break;
        case 2:
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)param_1 + 0x34) = 2;
            break;
        }
        break;
    case 2:
        break;
    }
}
