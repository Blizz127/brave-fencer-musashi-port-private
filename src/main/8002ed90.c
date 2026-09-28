/* Exact retail word export for [8002ED90,8002EDE4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002ED90 - byte-exact against retail at -O2 (tools/register_match.py). */

extern void func_8002EC10(void);
extern void func_800385C0(s16);
extern u16 D_800A4EA2;
extern s16 D_800A4E9A;

void func_8002ED90(void) {
    u16* ptr;

    func_8002EC10();

    ptr = &D_800A4EA2;
    if (*ptr & 0x4) {
        func_800385C0(D_800A4E9A);
        *ptr = 0;
    }
}
