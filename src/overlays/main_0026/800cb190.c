/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB190 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);

void func_800CB190(void *arg0) {
    extern void func_800CB5F4();
    extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_80146E90(s32 *, s32);
    extern void func_80146CA0(void *);
    extern s32 rand();

    s32 color;
    s32 tmp;

    func_800CB5F4(arg0);
    if (*(s32 *)((u8 *)arg0 + 0x50) == 0) {
        color = (rand() & 0xF) << 8;
        func_801466F0(0xC, arg0, 0, 0, 0, color, 0, 0);
        tmp = color + 0x555;
        func_801466F0(0xC, arg0, 0, 0, 0, tmp, 0, 0);
        tmp = color + 0xAAA;
        func_801466F0(0xC, arg0, 0, 0, 0, tmp, 0, 0);
        func_80146E90((s32 *)arg0, 8);
    } else {
        func_80146E90((s32 *)arg0, 0);
    }
    func_80146CA0(arg0);
}
