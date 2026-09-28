/* Overlay range [8013D3D4,8013D53C) from MAIN.CD member 0012.
 * SHA256(span)=2c74119d27de1bd32a00f9f27d0f4ccf07872642d0a4d933be779aaf6cfce4c0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D3D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

// @class: regalloc-order
// @stuck: none — MATCH (match_one 90/90); base &D_80078E78 cached in a pointer local so gcc pins it into callee-saved $s1 and hoists the addr to the prologue (live across all 4 calls); direct array access D_80078E78[0x37] instead folds %lo per use (no $s1, frame 0x18 not 0x20)




extern void func_8013D53C(void *);
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);

void func_8013D3D4(int param_1, int param_2)
{

    extern u8 D_80078E78[];
    extern void *D_801841A0;
    extern void *D_801841A4;
    extern void *D_801841A8;
    extern s32 D_801841D0;
    extern s32 D_801841D4;
    extern s32 D_801841D8;
    extern s32 D_80185B64[];
    extern u8 D_8017EBC0[];
    extern u8 D_8017EC68[];
    extern u8 D_8017EB18[];
    extern u8 D_8017EC14[];
    extern u8 D_8017EC94[];
    extern u8 D_8017EB6C[];
    u8 *p = D_80078E78;

    D_801841D0 = param_2;
    D_801841D4 = (param_2 >> 2) & 3;
    D_801841D8 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801841A0 = D_8017EBC0;
        D_801841A4 = D_8017EC68;
        D_801841A8 = D_8017EB18;
    } else {
        D_801841A0 = D_8017EC14;
        D_801841A4 = D_8017EC94;
        D_801841A8 = D_8017EB6C;
    }
    func_8013D53C((void *)param_1);
    if ((param_2 & 1) != 0) {
        if (D_801841D8 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801841D0 & 2) != 0) {
            D_80185B64[0] = 0x140;
            D_80185B64[3] = 0x80;
            if (p[0x37] == 4) {
                D_80185B64[0] = 0x140;
                D_80185B64[3] = 0;
            }
            if (p[0x37] == 0) {
                D_80185B64[0] = 0x140;
                D_80185B64[3] = 0x80;
            }
        }
    }
}
