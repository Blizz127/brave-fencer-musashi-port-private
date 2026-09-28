/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB158 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CAF84();
extern void func_800CAF84();

void func_800CB158(s32 arg0) {
    typedef struct { s32 w[4]; } Struct16;
    s32 a0;
    s32 v0;

    s32 cnt;

    a0 = *(s32 *)(arg0 + 0x34);

    if ((*(s32 *)(arg0 + 0x2C) & 0x8000) == 0) {
        cnt = *(s32 *)(arg0 + 0x1C);
        *(s32 *)(arg0 + 0x1C) = cnt + 1;

        if (cnt < 8) {
            *(u16 *)(arg0 + 0x28) += 0x120;
        } else {
            *(s32 *)(arg0 + 0x1C) = 0;
            *(u16 *)(arg0 + 0x2) = 4;
        }

        v0 = *(s32 *)(a0 + 0x20);
        *(Struct16 *)(arg0 + 0x38) = *(Struct16 *)(v0 + 0x34);
        *(Struct16 *)(arg0 + 0x48) = *(Struct16 *)(v0 + 0x44);

        func_800CAF84(arg0);
    } else {
        *(u16 *)(arg0 + 0x2) += 1;
    }
}
