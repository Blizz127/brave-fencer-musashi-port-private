/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A238 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 f_0;
    u8 pad_2[0xA8];
    s16 f_AA;
    u8 pad_AC[0x60];
} Entry8014A238;
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern s32 func_8014C2B0(void *a0, void *a1, s32 a2);
extern u8 D_801202A0[];

s32 func_8014A238(s32 arg0) {
    u32 i;
    Entry8014A238 *p;
    for (i = 0; i < 0x60; i++) {
        p = &((Entry8014A238 *)D_801202A0)[i];
        if ((p->f_0 != 0) && (p->f_AA != 0) &&
            (func_8014C278(arg0, (s32)p, 0x30) != 0) &&
            (func_8014C2B0((void *)arg0, (void *)p, 0x200) != 0)) {
            return (s32)p;
        }
    }
    return 0;
}
