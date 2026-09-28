/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172C50 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8_80172780;
struct S8_80172780 { s16 m[4]; };
extern void func_80174684(void *);
extern s16 D_80126B30;
extern void func_80172CA0(void*);

void func_80172C50(void *a0) {
    extern s16 D_80126B30;
    *(struct S8_80172780 *)&D_80126B30 = *(struct S8_80172780 *)a0;
    func_80174684((void *)func_80172CA0);
}
