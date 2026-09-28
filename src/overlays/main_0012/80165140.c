/* Overlay range [80165140,801651B8) from MAIN.CD member 0012.
 * SHA256(span)=ea6f85930a93c01b4a4a4dcc2011309efce84bfb89c0bb18359322bf75062d80.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165140 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u8 d[4]; } __attribute__((packed, aligned(1))) B4;
typedef struct { u8 d[8]; } __attribute__((packed, aligned(1))) B8_80165140;
typedef struct { B8_80165140 a; B4 b; s32 used; } Slot;

s32 func_80165140(s32 param_1) {
    extern Slot D_80184398[8];

    int i;
    Slot *p;
    for (i = 0; i < 8; i++) {
        p = &D_80184398[i];
        if (p->used == 0) {
            p->used = 8;
            p->a = *(B8_80165140 *)(((u8 *)param_1) + 0x2c);
            p->b = *(B4 *)(((u8 *)param_1) + 0x50);
            return;
        }
    }
}
