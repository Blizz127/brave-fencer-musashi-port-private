/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014462C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);

void func_8014462C(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0xCC);
    func_8012AD80((s32)a0);
    *(u16 *)(s1 + 8) = *(u16 *)(a0 + 6);
    *(u16 *)(s1 + 0xA) = *(u16 *)(a0 + 0xA);
    *(u16 *)(s1 + 0xC) = *(u16 *)(a0 + 0xE);
    if (func_80128ED8(s1, a0 + 0xD0)) {
        func_80016714(s1, 0x38);
        func_8012C218(a0);
    }
}
