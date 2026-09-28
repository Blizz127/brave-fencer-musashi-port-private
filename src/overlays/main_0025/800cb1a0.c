/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void (*D_800CBEBC[])(void);
extern s32 func_800CB7B0(s32 a0);
extern void func_80147364(u16 a0, s32 a1);
extern void func_800CB6CC(void*);

void func_800CB1A0(s32 a0) {
    s32 pad[2];
    u16 index;
    s16 value;
    s32 self = a0;

    if (D_80078EC1 != 0xF) {
        ((void (*)(s32))func_800CB6CC)(a0);
        return;
    }
    index = *(u16 *)(self + 2);
    ((void (*)(s32))D_800CBEBC[index])(self);

    if (*(u16 *)self != 0 && func_800CB7B0(self) != 0) {
        func_80147364(4, 0x649);
    }

    value = *(s16 *)(self + 0xA);
    if (value < 0x401) {
        return;
    }
    ((void (*)(s32))func_800CB6CC)(self);
}
