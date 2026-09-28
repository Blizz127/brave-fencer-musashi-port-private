/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBCD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
typedef struct { char c[8]; } Blk8;

void func_800CBCD4(u8 *s0) {
    extern s32 func_80012ABC(s32, s32, s32);
    extern void func_80162F08(s32, s32, s32, s32);
    extern void func_80013B64(s32, s32, s32);
    extern void func_80162FC0(s32 *);
    extern void func_800CBED8(s32 *);
    extern void func_80146DE8(s32 *, s32, s32, s32);
    extern s32 rand(void);
    extern u8 D_800CC13C[];
    extern u8 D_800CC140[];
    s32 v0, v1, flag;
    u8 *s1;
    s32 i;
    s32 sp10[3];
    u8 *a2, *a3;
    u16 w;

    v0 = *(s32 *)(s0 + 0x54);
    s1 = *(u32 **)(s0 + 0x20);
    if (v0 == 0) {
        v0 = func_80012ABC(*(s16 *)(s1 + 0x14), *(s16 *)(s0 + 0x60), 0xA);
        *(s16 *)(s1 + 0x14) = v0;
        func_80162F08(s0, 0, 0xC00, 0);
        func_80013B64(*(s16 *)(s1 + 0x14), s0 + 0x24, sp10);
        *(s32 *)(s0 + 0x10) = sp10[0];
        *(s32 *)(s0 + 0x14) = sp10[1];
        *(s32 *)(s0 + 0x18) = sp10[2];
        func_80162FC0(s0);
        func_800CBED8(s0);
        flag = *(s32 *)(s0 + 0x28) >= (s32)0xFFFE0000;
        if (flag) {
            func_80146DE8(s0, 0, 0xFFFC0000, 0);
            v0 = rand();
            v0 = v0 & 0x1F;
            v0 = v0 << 6;
            v1 = *(u16 *)(s0 + 0x60);
            v0 = v0 - 0xC00;
            v1 = v1 - v0;
            v1 = v1 & 0xFFF;
            *(u16 *)(s0 + 0x60) = v1;
        }
        i = 0xF;
        v0 = (s32)D_800CC13C;
        a3 = (u8 *)v0 + 0x78;
        a2 = (u8 *)v0 + 0x70;
        do {
            *(Blk8 *)a3 = *(Blk8 *)a2;
            a3 -= 8;
            i--;
            a2 -= 8;
        } while (i > 0);
        *(u16 *)D_800CC13C = *(u16 *)(s0 + 0x6);
        *(u16 *)(D_800CC13C + 2) = *(u16 *)(s0 + 0xA);
        *(u16 *)D_800CC140 = *(u16 *)(s0 + 0xE);
        *(u16 *)(D_800CC140 + 2) = *(u16 *)(s1 + 0x14);
    } else {
        v0 = *(s32 *)(s0 + 0x54);
        v0 = (v0 - 1) << 4;
        v1 = *(u16 *)(D_800CC13C + v0);
        *(u16 *)(s0 + 0x6) = v1;
        v0 = *(s32 *)(s0 + 0x54);
        v0 = (v0 - 1) << 4;
        v1 = *(u16 *)(D_800CC13C + 2 + v0);
        *(u16 *)(s0 + 0xA) = v1;
        v0 = *(s32 *)(s0 + 0x54);
        v0 = (v0 - 1) << 4;
        v1 = *(u16 *)(D_800CC140 + v0);
        *(u16 *)(s0 + 0xE) = v1;
        v0 = *(s32 *)(s0 + 0x54);
        v0 = (v0 - 1) << 4;
        w = *(u16 *)(D_800CC140 + 2 + v0);
        *(u16 *)(s1 + 0x14) = w;
    }
}
