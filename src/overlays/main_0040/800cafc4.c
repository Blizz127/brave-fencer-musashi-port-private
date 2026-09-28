/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFC4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void (*D_800CB8D4[])(void);
extern void func_800CB3BC(void);

void func_800CAFC4(s32 a0) {
    u16 index;
    s16 value;

    if (D_80078EC1 == 0x1D) {
        index = *(u16 *)(a0 + 2);
        D_800CB8D4[index]();

        value = *(s16 *)(a0 + 0xA);
        if (value < 0x401) {
            return;
        }
        ((void (*)(s32))func_800CB3BC)(a0);
    } else {
        ((void (*)(s32))func_800CB3BC)(a0);
    }
}
