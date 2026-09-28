/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139E84 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80139B18(s32 a0);
void func_80139A8C(s32 a0);
void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);

void func_80139E84(s32 a0) {
    s32 s0 = a0;
    if (*(u16 *)(s0 + 0xE) == 0) {
        *(s16 *)(s0 + 0x4) = 2;
    } else {
        func_80139A8C(s0);
        if ((*(s32 *)(s0 + 0x8) & 0x80020) != 0) {
            *(s16 *)(s0 + 0x4) = 2;
            *(s16 *)(s0 + 0xE) = 0;
            if ((*(s32 *)(s0 + 0x8) & 0x20000) == 0) {
                *(s32 *)(s0 + 0x8) = *(s32 *)(s0 + 0x8) & -0x21;
            }
        }
    }
    func_80139B18(s0);
}
