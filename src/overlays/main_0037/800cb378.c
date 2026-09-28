/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB378 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];
extern s32 func_8014C308(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_8014C3A4(void *a0, s32 a1, s32 a2, s32 a3);

void func_800CB378(s32 a0) {
    u8 *p;
    s16 buf[4];
    s32 s1;
    s1 = a0;
    p = D_801202A0;
    if (p < p + 0x6480) {
        do {
            if (func_8014C308(s1, (s32)p, 0x27, 0x80) != 0) {
                if (func_8014C278(s1, (s32)p, 0x60) != 0) {
                    func_80015978((s32)(p + 4), (s32 *)buf);
                    buf[3] = 0;
                    func_8014C3A4((void *)s1, (s32)p, 0x27, (s32)buf);
                }
            }
            p += 0x10C;
        } while (p < D_801202A0 + 0x6480);
    }
}
