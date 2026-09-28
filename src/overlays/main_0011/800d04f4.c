/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D04F4 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

const char D_800CEE3C[] = "ON ";
const char D_800CEE40[] = "OFF";
const char D_800CEE44[] = "PLAYER DMG";
const char D_800CEE50[] = "ON";
const char D_800CEE54[] = "GET IN SEL";
const u32 D_800CEE60[] = { 0x59414C50, 0x48205245, 0x45482050, 0x414E4152, 0x01000049 };

void func_800D04F4(void) {
    typedef struct { s16 unk00; s16 unk02; s16 unk04; } S6;
    extern s32 func_80029504(void);
    extern s32 D_800D3344;
    extern s16 D_800D3348;
    extern s16 D_800D334A;
    extern S6 D_800D4A5C[];
    extern void func_800153CC(int, int, int, int, int, int);
    extern void func_8001534C(int, void *, int, int, int, int);
    extern s32 func_80029178(int);
    S6 *sp18;

    D_800D3344 = func_80029504();
    func_800153CC(0x11, D_800D3344, 0xC8, 0xA6, 0x44, 0);
    sp18 = &D_800D4A5C[D_800D3348];
    func_8001534C(0x12, sp18, 0x98, 0xB2, 0x43, 0);
    func_8001534C(0x13, (func_80029178(sp18->unk04) & 0xFF) ? D_800CEE3C : D_800CEE40, 0xC8, 0xB2, 0, 0);
    func_800153CC(0x14, (s16)(D_800D334A / 60), 0x68, 0xBE, 0x42, 0);
    func_800153CC(0x15, (s16)(D_800D334A % 60), 0x80, 0xBE, 0x42, 0);
    func_8001534C(0x16, D_800CEE44, 0x40, 0xCA, 0x43, 0);
    func_8001534C(0x17, (func_80029178(0) & 0xFF) ? D_800CEE40 : D_800CEE50, 0xA8, 0xCA, 0, 0);
    func_8001534C(0x18, D_800CEE54, 0x40, 0xD2, 0x43, 0);
    func_8001534C(0x19, (func_80029178(1) & 0xFF) ? D_800CEE50 : D_800CEE40, 0xA8, 0xD2, 0, 0);
    func_8001534C(0x1B, (void *)D_800CEE60, 0x40, 0xDA, 0x43, 0);
    func_8001534C(0x1D, (func_80029178(2) & 0xFF) ? D_800CEE50 : D_800CEE40, 0xE0, 0xDA, 0, 0);
}
