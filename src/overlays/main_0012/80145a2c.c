/* Overlay range [80145A2C,80145B24) from MAIN.CD member 0012.
 * SHA256(span)=12353e12221e2f20c0be36623abccb9b309596599ae068e825e726a94233d40a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80145A2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern void func_800D185C(u8 *a0);
extern void func_80145B24(void);

void func_80145A2C(void) {

    extern u8 D_80180948;
    extern u8 D_80180828;
    extern u8 D_80180804;
    extern u8 D_801807E0;
    extern u8 D_80180924;
    extern u8 D_80180900;
    extern u8 D_801808DC;
    extern u8 D_801807BC;
    s32 v;
    void *p;

    v = func_80029504();
    if (v >= 0x6A4) {
        p = &D_80180948;
         

        __asm__ __volatile__("" ::: "memory");
    } else if (v >= 0x5DC) {
        p = &D_80180828;
    } else if (v >= 0x578) {
        p = &D_80180804;
    } else if (v >= 0x514) {
        p = &D_801807E0;
    } else if (v >= 0x384) {
        p = &D_80180948;
    } else if (v >= 0x258) {
        p = &D_80180924;
    } else if (v >= 0xC8) {
        p = &D_80180900;
    } else if (v >= 0xA) {
        p = &D_801808DC;
    } else {
        p = &D_801807BC;
    }
    ((void (*)(void *))func_800D185C)(p);
    func_80145B24();
}
