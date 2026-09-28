/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A68C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012A7D4(void *a0, void *a1);
extern s32 func_8012A6D0(void *a0, void *a1);

s16 func_8012A68C(void) {
    s16 a[4];
    s16 b[4];
    func_8012A7D4(a, b);
    return (s16)func_8012A6D0(a, b);
}
