/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB03C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32, s32, s32, s32);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(s32);
extern void func_80147324(s32 a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8014C050(s32 a0, s32 a1);
extern s32 func_8014C088(s32 a0, s32 a1);
extern void func_80146CA0(s32 a0);

void func_800CB03C(s32 *a0) {
    register s32 flag __asm__("$16");
    register s32 zz __asm__("$0");

    flag = 0;
    if (func_8014C088((s32)a0, 0x1C) || func_8014C050((s32)a0, 0x3E)) {
        flag = 1;
    }
    if (!flag) {
        func_80146994(0x41, (s32)a0, zz, zz);
        func_80147324(0x836);
        func_80146CA0((s32)a0);
    }
}
