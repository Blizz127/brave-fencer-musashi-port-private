/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8238 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801E8238(void *arg0) {

    extern s32 func_801789AC(s32 a0);
    extern void func_80178CBC(s32 a0, s32 a1);
    extern void func_80174438(s32 a0);
    extern void func_80186460(s32 a0);
    extern s16 func_80186450(void);
    extern u8 *D_80126B10;
    extern s32 D_801E88D4;
    extern s32 D_801E88EC;
    extern s32 D_801E8870;
    extern s32 D_801E8AE8[];

    switch (*(u16 *)((s32)arg0 + 0x34)) {
    case 0: {
        s32 v1 = func_801789AC((s32)arg0);
        switch (v1) {
        case 1:
            *(u16 *)((s32)arg0 + 0x34) = 2;
            func_80186460(2);
            break;
        case 2:
            func_80178CBC((s32)arg0, (s32)&D_801E88D4);
            *(u16 *)((s32)arg0 + 0x34) = 0;
            break;
        case 3:
            func_80178CBC((s32)arg0, (s32)&D_801E88EC);
            *(u16 *)((s32)arg0 + 0x34) = 3;
            break;
        }
        break;
    }
    case 1:
        break;
    case 2: {
        s16 v0 = func_80186450();
        if (v0 != 0) {
            func_80178CBC((s32)arg0, (s32)D_801E8AE8[v0]);
            *(u16 *)((s32)arg0 + 0x34) = 4;
        } else {
            func_80178CBC((s32)arg0, (s32)&D_801E8870);
            *(u16 *)((s32)arg0 + 0x34) = 0;
        }
        break;
    }
    case 3:
        if (func_801789AC((s32)arg0) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)arg0 + 0x34) = 1;
        }
        break;
    case 4:
        if (func_801789AC((s32)arg0) != 0) {
            *(u16 *)((s32)arg0 + 0x34) = 2;
            func_80186460(2);
        }
        break;
    }
}
