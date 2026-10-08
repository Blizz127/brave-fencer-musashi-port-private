/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165140 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_80165140;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_80165140;
typedef struct { B8_80165140 a; B4_80165140 b; s32 used; } Slot_80165140;

void func_80165140(s32 param_1) {
    extern Slot_80165140 D_801B6550[8];

    int i;
    Slot_80165140 *p;
    for (i = 0; i < 8; i++) {
        p = &D_801B6550[i];
        if (p->used == 0) {
            p->used = 8;
            p->a = *(B8_80165140 *)(((u8 *)param_1) + 0x2c);
            p->b = *(B4_80165140 *)(((u8 *)param_1) + 0x50);
            return;
        }
    }
}
