/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80133060 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801330E0(void * param_1, s16 * param_2, s32 param_3);

void func_80133060(u8 *a0, s32 *a1, s32 a2) {
    s16 tmp[3];
    tmp[0] = *(u16 *)(a0 + 2);
    tmp[1] = *(u16 *)(a0 + 6);
    tmp[2] = *(u16 *)(a0 + 0xA);
    func_801330E0(tmp, tmp, (s16)a2);
    a1[0] = tmp[0] << 16;
    a1[1] = tmp[1] << 16;
    a1[2] = tmp[2] << 16;
}
