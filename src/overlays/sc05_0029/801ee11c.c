/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE11C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 *D_80126B10;
extern s32 func_801789AC(s32 arg0);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_80174438(s32 a0);
extern void func_800D1724(void *);
extern s32 func_80186150();
extern void func_80186160(s32 a0);

void func_801EE11C(void *a0) {

    extern s32 D_801EE5A0;
    extern s32 D_801EE604;
    extern s32 D_801EE61C;
    extern s32 D_800D39CC;

    switch (*(u16 *)((s32)a0 + 0x34)) {
    case 0: {
        s32 v1 = func_801789AC((s32)a0);
        switch (v1) {
        case 1:
            *(u16 *)((s32)a0 + 0x34) = 2;
            func_80186160(5);
            break;
        case 2:
            func_80178CBC((s32)a0, (s32)&D_801EE604);
            *(u16 *)((s32)a0 + 0x34) = 0;
            break;
        case 3:
            func_80178CBC((s32)a0, (s32)&D_801EE61C);
            *(u16 *)((s32)a0 + 0x34) = 3;
            break;
        }
        break;
    }
    case 1:
        break;
    case 2: {
        s32 v0 = func_80186150();
        if ((v0 << 16) != 0) {
            func_800D1724((void *)&D_800D39CC);
            *(u16 *)((s32)a0 + 0x34) = 1;
        } else {
            func_80178CBC((s32)a0, (s32)&D_801EE5A0);
            *(u16 *)((s32)a0 + 0x34) = 0;
        }
        break;
    }
    case 3:
        if (func_801789AC((s32)a0) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)a0 + 0x34) = 1;
        }
        break;
    }
}
