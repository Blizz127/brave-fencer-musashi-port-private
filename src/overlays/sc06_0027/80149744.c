/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149744 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S_80149744 {
    char pad44[0x44];
    s32 w44;       /* 0x44 */
    char pad48[0xAC - 0x48];
    u16 h_AC;      /* 0xAC */
};
extern u8 D_80078EBF;

s32 func_80149744(struct S_80149744 *a0) {
    if ((a0->w44 & 0x4) == 0 && D_80078EBF >= 0x80) {
        if (a0->h_AC & 0x80) {
            return 1;
        }
    }
    return 0;
}
