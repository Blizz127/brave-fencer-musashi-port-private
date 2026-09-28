/* Overlay range [80145934,80145A2C) from MAIN.CD member 0012.
 * SHA256(span)=23139b2ac6638b167b36202987026764b59fa41f869084a198084239d04cffe9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80145934 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern void func_800D185C(u8 *a0);
extern void func_80145B24(void);

void func_80145934(void) {

    extern u8 D_801808B8;
    extern u8 D_80180828;
    extern u8 D_80180804;
    extern u8 D_801807E0;
    extern u8 D_80180894;
    extern u8 D_80180870;
    extern u8 D_8018084C;
    extern u8 D_801807BC;
    s32 v;
    void *p;

    v = func_80029504();
    if (v >= 0x6A4) {
        p = &D_801808B8;
         

        __asm__ __volatile__("" ::: "memory");
    } else if (v >= 0x5DC) {
        p = &D_80180828;
    } else if (v >= 0x578) {
        p = &D_80180804;
    } else if (v >= 0x514) {
        p = &D_801807E0;
    } else if (v >= 0x384) {
        p = &D_801808B8;
    } else if (v >= 0x258) {
        p = &D_80180894;
    } else if (v >= 0xC8) {
        p = &D_80180870;
    } else if (v >= 0xA) {
        p = &D_8018084C;
    } else {
        p = &D_801807BC;
    }
    ((void (*)(void *))func_800D185C)(p);
    func_80145B24();
}
