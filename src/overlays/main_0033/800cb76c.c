/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB76C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80049CAC(s32 arg0, s32 arg1);

void func_800CB76C(void *arg0) {
    extern void func_80049CAC(s32 a0, s32 a1);
    extern void func_800139C8(s32 a0, void *a1, void *a2);
    extern u8 D_800CB8FC[];
    s32 s2 = (s32)arg0;
    s32 s3;
    s32 s0;
    s32 s1;
    u16 sp10[3];
    s32 v;
    s32 q;

    s3 = *(s32 *)(s2 + 0x34);
    s0 = *(s32 *)(s2 + 0x20);
    s1 = *(s32 *)(s3 + 0x20);
    if (s0 != 0) {
        *(u16 *)(s0 + 0x12) = *(u16 *)(s1 + 0x12);
        func_80049CAC((s32)s0 + 0x10, *(s32 *)(s0 + 0x34));
        v = *(s16 *)(s1 + 0x1A);
        q = (v * 180) / 100;
        *(s16 *)(s0 + 0x1A) = q;
        *(s16 *)(s0 + 0x18) = q;
        func_800139C8(*(s16 *)(s0 + 0x12), D_800CB8FC, (s32)&sp10[0]);
        *(u16 *)(s2 + 6) = *(u16 *)(s3 + 6) + sp10[0];
        *(u16 *)(s2 + 0xA) = *(u16 *)(s3 + 0xA) + sp10[1];
        *(u16 *)(s2 + 0xE) = *(u16 *)(s3 + 0xE) + sp10[2];
    }
}
