/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCDD8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CCE80(void*);
extern void func_800CCE80(void *);

void func_800CCDD8(s32 a0) {
    s16 flag;
    u8 *v1;
    u16 w;

    flag = *(s16 *)(a0 + 0x60);
    v1 = *(u8 **)(a0 + 0x20);
    if (flag != 0) {
        *(u16 *)(v1 + 0x18) = w = *(u16 *)(v1 + 0x18) + 0x100;
        if ((s16)w >= 0x1001) {
            *(u16 *)(v1 + 0x18) = 0x1000;
        }
    } else {
        *(u16 *)(v1 + 0x18) = w = *(u16 *)(v1 + 0x18) - 0x100;
        if ((s16)w < 0) {
            *(u16 *)(v1 + 0x18) = 0;
        }
    }
    w = *(u16 *)(v1 + 0x18);
    *(u16 *)(v1 + 0x1C) = w;
    *(u16 *)(v1 + 0x1A) = w;
    func_800CCE80((void *)a0);
}
