/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80145934 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800D185C(u8 *a0);
extern s32 func_80029504(void);
extern void func_80145B24(void);
extern u8 D_8018077C;
extern u8 D_801806EC;
extern u8 D_801806C8;
extern u8 D_801806A4;
extern u8 D_80180758;
extern u8 D_80180734;
extern u8 D_80180710;
extern u8 D_80180680;

void func_80145934(void) {
    s32 v;
    void *p;

    v = func_80029504();
    if (v >= 0x6A4) {
        p = &D_8018077C;
         

        __asm__ __volatile__("" ::: "memory");
    } else if (v >= 0x5DC) {
        p = &D_801806EC;
    } else if (v >= 0x578) {
        p = &D_801806C8;
    } else if (v >= 0x514) {
        p = &D_801806A4;
    } else if (v >= 0x384) {
        p = &D_8018077C;
    } else if (v >= 0x258) {
        p = &D_80180758;
    } else if (v >= 0xC8) {
        p = &D_80180734;
    } else if (v >= 0xA) {
        p = &D_80180710;
    } else {
        p = &D_80180680;
    }
    ((void (*)(void *))func_800D185C)(p);
    func_80145B24();
}
