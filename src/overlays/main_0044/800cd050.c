/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD050 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 a0);
extern s32 func_80146CA0(void *);
extern s32 func_80146CA0(void *a0);
extern u16 D_800B99DA;
extern u16 func_801487F4(s32*);
extern s32 func_80146608(s32, s32, s32, s32, s16, s32, s32, s32, s32);
extern s32 func_80146CA0(void*);
extern void func_80147324(s32);

void func_800CD050(s32 arg0) {
    s32 acc;
    s32 i;
    s32 ptr;

    ptr = *(s32*)(arg0 + 0x4C);
    if (!(func_801487F4((s32*)ptr) & 0x90)) {
        func_80146CA0(arg0);
        return;
    }
    *(u16*)(arg0 + 0x60) -= 1;
    if (*(s16*)(arg0 + 0x60) < 0) {
        *(u16*)(arg0 + 0x60) = 0;
    }
    if (D_800B99DA & 3) {
        return;
    }
    acc = 0;
    for (i = 0; i < 3; i++) {
        acc |= func_80146608(9, ptr, 0, -30, 0, (*(s32*)(arg0 + 0x50))++, 0, 12, 1);
    }
    if ((*(s16*)(arg0 + 0x60) == 0) && (acc != 0)) {
        func_80147324(0x747);
        *(u16*)(arg0 + 0x60) = 0xF;
    }
}
