/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB4C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149374(s32 a0, s32 a1);
typedef struct { u8 b[8]; } Blk8;
extern void func_80015978(s32 a0, s32 *a1);
extern u8 D_800CC5B0[];

void func_800CB4C8(void *arg0) {
    s32 s1 = (s32)arg0;
    s32 off;
    s32 t;
    s32 s2;
    u8 *dst;
    s32 i;

    s2 = *(s32 *)(s1 + 0x4C);
    off = *(s32 *)(s1 + 0x50) * 160;
    dst = D_800CC5B0 + off;
    func_80015978(s1 + 4, (s32 *)(s1 + 0x10));
    for (i = 0; i < 20; i++) {
        *(Blk8 *)dst = *(Blk8 *)(s1 + 0x10);
        dst += 8;
    }
    func_80149374(s2, s1 + 4);
    t = *(s32 *)(s1 + 0x50);
    *(u16 *)(s1 + 0x60) = 0;
    *(u16 *)(s1 + 0x64) = t << 10;
}
