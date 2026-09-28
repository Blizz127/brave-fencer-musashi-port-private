/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF104 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800EC678;
extern s32 D_800EC67C;
extern s32 D_800EC680;
extern s32 D_800EC690;
extern s32 D_800EC694;
extern s32 D_800EC698;
extern s32 func_800149E0(s32);
extern s32 func_80014B10(s32);
extern void func_8002D4C8(s32, s32);
extern void func_800CFE00(void);
extern void func_800118AC(void);
extern void func_800CF3E8(void);

void func_800CF104(void) {
    s32 pad;

    pad = func_800149E0(0);
    func_80014B10(0);
    if (D_800EC690 == 1) goto blk1;
    if (D_800EC690 < 2) goto done;
    if (D_800EC690 == 2) goto blk2;
    if (D_800EC690 == 3) goto blk3;
    goto done;

blk1:
    D_800EC694 = (D_800EC698 & 0x1F) < 0x18;
    D_800EC698++;
    if (pad & 0x840) {
        func_8002D4C8(0xC6E, 0);
        D_800EC690++;
    } else {
        D_800EC67C++;
    }
    goto done;

blk3:
    func_800CFE00();
    D_800EC690 = 2;
    goto done;

blk2:
    if (pad & 0x4000) {
        func_8002D4C8(0x9C1, 0);
        D_800EC678++;
        if (D_800EC678 >= 2) {
            D_800EC678 = 0;
        }
        D_800EC67C = 0;
    } else if (pad & 0x1000) {
        func_8002D4C8(0x9C1, 0);
        D_800EC678--;
        if (D_800EC678 < 0) {
            D_800EC678 = 1;
        }
        D_800EC67C = 0;
    } else if (pad & 0x840) {
        func_8002D4C8(0x9C0, 0);
        D_800EC680 = D_800EC678;
        func_800118AC();
    }

done:
    func_800CF3E8();
    if (D_800EC67C >= 0x1C3) {
        D_800EC680 = 4;
        func_800118AC();
    }
}
