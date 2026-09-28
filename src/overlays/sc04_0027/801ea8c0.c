/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EA8C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801E7DA4(void);
extern s32 func_801E7DCC(void);
extern s32 func_801789AC(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_80174438(s32 a0);
extern u8 *D_80126B10;
extern s16 func_80186450(void);
extern void func_80186460(s32 a0);

void func_801EA8C0(void *param_1) {

    extern s32 D_801EBD00;
    extern s32 D_801EBD18;
    extern s32 D_801EBC94;

    switch (*(u16 *)((s32)param_1 + 0x34)) {
    case 0: {
        s32 v0 = func_801789AC((s32)param_1);
        switch (v0) {
        case 1:
            *(u16 *)((s32)param_1 + 0x34) = 2;
            func_80186460(4);
            break;
        case 2:
            func_80178CBC((s32)param_1, (s32)&D_801EBD00);
            *(u16 *)((s32)param_1 + 0x34) = 0;
            break;
        case 3:
            func_80178CBC((s32)param_1, (s32)&D_801EBD18);
            *(u16 *)((s32)param_1 + 0x34) = 3;
            break;
        }
        break;
    }
    case 1:
        break;
    case 2:
        if (func_80186450() != 0) {
            func_801E7DA4();
            *(u16 *)((s32)param_1 + 0x34) = 4;
        } else {
            func_80178CBC((s32)param_1, (s32)&D_801EBC94);
            *(u16 *)((s32)param_1 + 0x34) = 0;
        }
        break;
    case 3:
        if (func_801789AC((s32)param_1) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)param_1 + 0x34) = 1;
        }
        break;
    case 4:
        if ((func_801E7DCC() << 16) != 0) {
            *(u16 *)((s32)param_1 + 0x34) = 2;
            func_80186460(4);
        }
        break;
    }
}
