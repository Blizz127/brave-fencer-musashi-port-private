/* Main-exec range [8002FA3C,8002FAE0) from the SLUS executable.
 * SHA256(span)=f29a61662d929a74181501ae5a9b69d24a7cfb1ddadb003e398f2b8abf5ce798.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

/* func_8002FA3C - byte-exact against retail at -O2 (tools/register_match.py). */

void func_8002FA3C(void) {
    extern s16 D_800760E8;
    extern s16 D_800760E4;
    extern s16 D_800760EC;
    extern void (*D_800A4F24)(void);
    extern int func_8003EDE8(int a0, int a1, int a2);
    u16 w;
    s16 t;

    w = *(u16 *)&D_800760E8;
    w = w + 1;
    D_800760E8 = (s16)w;
    if ((s16)w < 0x10) {
        if (D_800760E4 > D_800760EC) {
            D_800760E4 = t = D_800760E4 - D_800760EC;
            func_8003EDE8(0, t, t);
            return;
        }
    }
    func_8003EDE8(0, 0, 0);
    D_800A4F24 = NULL;
}
