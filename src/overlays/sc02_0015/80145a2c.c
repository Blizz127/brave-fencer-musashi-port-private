/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80145A2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800D185C(u8 *a0);
extern s32 func_80029504(void);
extern void func_80145B24(void);
extern u8 D_801806EC;
extern u8 D_801806C8;
extern u8 D_801806A4;
extern u8 D_80180680;
extern u8 D_8018080C;
extern u8 D_801807E8;
extern u8 D_801807C4;
extern u8 D_801807A0;

void func_80145A2C(void) {
    s32 v;
    void *p;

    v = func_80029504();
    if (v >= 0x6A4) {
        p = &D_8018080C;
         

        __asm__ __volatile__("" ::: "memory");
    } else if (v >= 0x5DC) {
        p = &D_801806EC;
    } else if (v >= 0x578) {
        p = &D_801806C8;
    } else if (v >= 0x514) {
        p = &D_801806A4;
    } else if (v >= 0x384) {
        p = &D_8018080C;
    } else if (v >= 0x258) {
        p = &D_801807E8;
    } else if (v >= 0xC8) {
        p = &D_801807C4;
    } else {
        p = &D_80180680;
        if (v >= 0xA) {
            p = &D_801807A0;
        }
    }
    ((void (*)(void *))func_800D185C)(p);
    func_80145B24();
}
