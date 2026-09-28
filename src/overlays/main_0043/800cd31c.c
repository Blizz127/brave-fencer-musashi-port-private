/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD31C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C308(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_8014C3A4(void *a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801202A0[];

void func_800CD31C(s32 arg0) {
    u8 sp10[8];
    u8 *p = D_801202A0;

    if (p < D_801202A0 + 0x6480) {
        u8 *end = p + 0x6480;
        do {
            if (func_8014C308(arg0, (s32)p, 0x22, 0)) {
                if (func_8014C278(arg0, (s32)p, 0x80)) {
                    func_80015978((s32)(p + 4), (s32 *)sp10);
                    *(u16 *)(sp10 + 6) = 0;
                    func_8014C3A4((void *)arg0, (s32)p, 0x22, (s32 *)sp10);
                }
            }
            p += 0x10C;
        } while (p < end);
    }
}
