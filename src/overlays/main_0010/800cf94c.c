/* Exact overlay word export for [800CF94C,800CF990) from MAIN.CD
 * member0010 (extracted/overlays/main/0010.bin offset 0x20B54, base 800CEDF8).
 * Live STOP 800CF94C: title overlay table entry, jal 80019A24.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF94C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AE890;
extern void *D_80072C74;
extern int func_80019A24(void *dst, void *src, int arg2, int arg3);
extern void func_80011A3C(void);

void func_800CF94C(void) {
    if (func_80019A24(&D_800AE890, D_80072C74, 0, 0) != 0) {
        func_80011A3C();
    }
}
