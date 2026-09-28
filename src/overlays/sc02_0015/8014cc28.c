/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CC28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014D3E0();
extern void func_8014D04C(void);
extern void func_8014CCB4(void);

void func_8014CC28(s32 a0) {
    if (*(s32 *)(a0 + 0x44) < 0) {
        if (*(s16 *)(a0 + 0xA) != *(s16 *)(a0 + 0x8A)) {
            func_8014D3E0(a0);
            return;
        }
        if (*(s16 *)(a0 + 0x6) != *(s16 *)(a0 + 0x88) ||
            *(s16 *)(a0 + 0xE) != *(s16 *)(a0 + 0x8C)) {
            func_8014D04C();
            return;
        }
    }
    func_8014CCB4();
}
