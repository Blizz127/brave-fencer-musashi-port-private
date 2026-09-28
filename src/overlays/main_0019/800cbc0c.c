/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBC0C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015954(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_8014C308(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern s32 func_8014C3A4(void *a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801202A0[];
extern u8 D_80126720[];

void func_800CBC0C(void *a0) {
    u8 *r04;
    u8 *p;
    s16 buf10[4];
    s16 buf18[4];

    r04 = (u8 *)a0 + 4;
    func_80015978((s32)r04, (s32 *)buf18);
    func_80015954((s32)a0 + 0x10, (s32)r04);
    *(s16 *)((s32)a0 + 0xA) = 0;
    func_80149374((s32)a0, (s32)r04);
    p = D_801202A0;
    if (p < p + 0x6480) {
        do {
            if (func_8014C308((s32)a0, (s32)p, 0x1E, 0x2000) != 0) {
                if (*(s16 *)(p + 0xAA) == 0) {
                    if (func_8014C278((s32)a0, (s32)p, 0x40) != 0) {
                        func_80015978((s32)(p + 4), (s32 *)buf10);
                        buf10[3] = 0;
                        func_8014C3A4((void *)a0, (s32)p, 0x1E, (s32)buf10);
                    }
                }
            }
            p += 0x10C;
        } while (p < D_80126720);
    }
    func_80015954((s32)buf18, (s32)((u8 *)a0 + 4));
}
