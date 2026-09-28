/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D330 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_8019AB92;
extern u8 D_8019AC06;
extern u8 D_8019AABA;
extern u8 D_8019AB74;
extern u8 D_8019AA98;
extern u8 D_8019AAB9;
extern s32 D_8019AB78;

void func_8013D330(void) {
    if ((D_8019AB92 & 0xff) != D_8019AC06) {
        D_8019AB92 = ((D_8019AB92 & 0xff) < D_8019AC06) ? (D_8019AB92 + 1) : (D_8019AB92 - 1);
    }
    if ((D_8019AABA & 0xff) != D_8019AB74) {
        D_8019AABA = ((D_8019AABA & 0xff) < D_8019AB74) ? (D_8019AABA + 1) : (D_8019AABA - 1);
    }
    if ((D_8019AA98 & 0xff) != D_8019AAB9) {
        D_8019AA98 = ((D_8019AA98 & 0xff) < D_8019AAB9) ? (D_8019AA98 + 1) : (D_8019AA98 - 1);
    }
    D_8019AB78 = 1;
}
