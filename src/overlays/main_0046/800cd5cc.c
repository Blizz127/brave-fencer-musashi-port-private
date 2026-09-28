/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD5CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];
extern s32 func_8014C308(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_8014C3A4(void *a0, s32 a1, s32 a2, s32 a3);

void func_800CD5CC(void *arg0) {
    register s32 rv __asm__("$2");
    s32 a0 = (s32)arg0;
    s32 found = 0;
    u8 *p = D_801202A0;
    s32 t = 0x25;
    s16 buf[4];
    *(u8 *)(a0 + 0x1AB) ^= 1;
    if (p < p + 0x6480) {
        do {
            if (func_8014C308(a0, (s32)p, t, 0x10) != 0) {
                if (func_8014C278(a0, (s32)p, 0x40) != 0) {
                    func_80015978((s32)(p + 4), (s32 *)buf);
                    buf[3] = 0;
                    func_8014C3A4((void *)a0, (s32)p, t, (s32)buf);
                    found = (s32)p;
                }
            }
            p += 0x10C;
        } while (p < D_801202A0 + 0x6480);
    }
    rv = found;
    __asm__ __volatile__("" : : "r"(rv));
}
