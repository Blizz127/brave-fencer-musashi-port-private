/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF9C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void (*D_800CB7EC[])(void);
extern void func_80162D28(s32 *a0);
extern void func_800CB338(void);

void func_800CAF9C(s32 a0) {
    u16 index;
    s16 value;

    if (D_80078EC1 == 0x1E) {
        index = *(u16 *)(a0 + 2);
        D_800CB7EC[index]();

        if (*(s32 *)(a0 + 0x20) != 0) {
            func_80162D28((s32 *)a0);
        }

        value = *(s16 *)(a0 + 0xA);
        if (value < 0x401) {
            return;
        }
        ((void (*)(s32))func_800CB338)(a0);
    } else {
        ((void (*)(s32))func_800CB338)(a0);
    }
}
