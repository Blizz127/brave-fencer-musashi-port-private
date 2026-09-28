/* Exact retail word export for [8002CFE4,8002D034); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002CFE4 - byte-exact against retail at -O2 (tools/register_match.py). */

extern void func_80030F80(void);
extern void func_8002D320(void);
extern void func_80031BE0(void);

extern s16 D_800A4EFC;

void func_8002CFE4(void) {
    s16 *ptr = &D_800A4EFC;

    if (*ptr != 0) {
        *ptr = *ptr - 1;
    }
    func_80030F80();
    func_8002D320();
    func_80031BE0();
}
