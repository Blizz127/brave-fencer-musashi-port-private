/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165140 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4_80165140;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_80165140;
typedef struct { B8_80165140 a; B4_80165140 b; s32 used; } Slot_80165140;

s32 func_80165140(s32 param_1) {
    extern Slot_80165140 D_8019FC30[8];

    int i;
    Slot_80165140 *p;
    for (i = 0; i < 8; i++) {
        p = &D_8019FC30[i];
        if (p->used == 0) {
            p->used = 8;
            p->a = *(B8_80165140 *)(((u8 *)param_1) + 0x2c);
            p->b = *(B4_80165140 *)(((u8 *)param_1) + 0x50);
            return;
        }
    }
}
