/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC658 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CC6A4();

void func_800CC658(void *a0) {
    void *v1;
    s16 v;

    v1 = *(void **)((u8 *)a0 + 0x20);
    v = *(u16 *)((u8 *)v1 + 0x1E) + 0x80;
    *(u16 *)((u8 *)v1 + 0x1E) = v;
    if (v >= 0x1000) {
        func_800CC6A4(a0);
    }
}
