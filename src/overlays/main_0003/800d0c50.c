/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0C50 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800EC894;
extern void func_800599B8(u16 *, u16 *);
extern void func_80011928(s32);

void func_800D0C50(void) {
    s16 sp10[8];
    u16 *addr2;
    u16 *addr1;

    addr1 = (u16 *)(D_800EC894 * 307744 + 0x80114014);
    addr2 = (u16 *)(D_800EC894 * 307744 + 0x80114220);
    sp10[0] = 0;
    sp10[1] = 0x1E0;
    sp10[2] = 0x100;
    sp10[3] = 1;
    sp10[4] = 0x280;
    sp10[5] = 0x10;
    sp10[6] = 0x140;
    sp10[7] = 0x1E0;
    func_800599B8(sp10, addr1);
    func_800599B8(&sp10[4], addr2);
    func_80011928(3);
}
