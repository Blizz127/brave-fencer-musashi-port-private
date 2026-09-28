/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE0C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801789AC(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_80174438(s32 a0);
extern s32 func_80186150(void);
extern void func_80186160(s32 a0);
extern u8 *D_80126B10;

void func_801EE0C0(void *param_1) {

    extern s32 D_801EE75C;
    extern s32 D_801EE774;
    extern s32 D_801EE6F8;
    extern s32 D_801EE970[];

    switch (*(u16 *)((s32)param_1 + 0x34)) {
    case 0: {
        s32 v0 = func_801789AC((s32)param_1);
        switch (v0) {
        case 1:
            *(u16 *)((s32)param_1 + 0x34) = 2;
            func_80186160(2);
            break;
        case 2:
            func_80178CBC((s32)param_1, (s32)&D_801EE75C);
            *(u16 *)((s32)param_1 + 0x34) = 0;
            break;
        case 3:
            func_80178CBC((s32)param_1, (s32)&D_801EE774);
            *(u16 *)((s32)param_1 + 0x34) = 3;
            break;
        }
        break;
    }
    case 1:
        break;
    case 2: {
        s16 v0 = func_80186150();
        if (v0 != 0) {
            func_80178CBC((s32)param_1, D_801EE970[v0]);
            *(u16 *)((s32)param_1 + 0x34) = 4;
        } else {
            func_80178CBC((s32)param_1, (s32)&D_801EE6F8);
            *(u16 *)((s32)param_1 + 0x34) = 0;
        }
        break;
    }
    case 3:
        if (func_801789AC((s32)param_1) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)param_1 + 0x34) = 1;
        }
        break;
    case 4:
        if (func_801789AC((s32)param_1) != 0) {
            *(u16 *)((s32)param_1 + 0x34) = 2;
            func_80186160(2);
        }
        break;
    }
}
