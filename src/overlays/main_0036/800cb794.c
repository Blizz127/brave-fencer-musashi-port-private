/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB794 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB794(s32 arg0) {
    extern u8 D_801202A0[];
    extern u8 D_80126720[];
    extern s32 func_8014C308(s32 a0, s32 a1, s32 a2, s32 a3);
    extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
    extern s32 func_8014C3D0(void *a0, s32 a1, s32 a2, s32 a3);

    u8 *p;
    s32 ptr;
    s16 buf[4];

    p = D_801202A0;
    if (p < D_801202A0 + 0x6480) {
        do {
            if (func_8014C308(arg0, (s32)p, 0x33, 0x4000) != 0) {
                if (func_8014C278(arg0, (s32)p, 0xC0) != 0) {
                    func_80015978((s32)(p + 4), (s32 *)buf);
                    buf[3] = 0;
                    if (func_8014C3D0((void *)arg0, (s32)p, 0x33, (s32)buf) != 0) {
                        if (*(u16 *)p == 0x219) {
                            ptr = *(s32 *)(p + 0x78);
                            if (ptr != 0) {
                                *(s16 *)(p + 0x60) = *(s16 *)(p + 0x76) * 0x1000 /
                                                    *(s16 *)(ptr + 0x30) + 1;
                            }
                        }
                    }
                }
            }
            p += 0x10C;
        } while (p < D_80126720);
    }
}
