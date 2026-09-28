/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB11C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 a0);
extern s32 func_80146CA0(void *a0);

void func_800CB11C(u8 *arg0) {
    u8 *s1;
    s32 var;
    s16 cur;
    s16 max;
    u16 val;
    s16 temp;

    s1 = *(u8 **)(arg0 + 0x20);
    var = *(s32 *)(arg0 + 0x58) + 0x30000;
    *(s32 *)(arg0 + 0x58) = var;
    *(s32 *)(arg0 + 8) += var;

    cur = *(s16 *)(arg0 + 0x60);
    max = *(s16 *)(arg0 + 0xA);
    if (cur < max) {
        *(s16 *)(arg0 + 0xA) = cur;
        if (*(s16 *)(arg0 + 0x62) == 0) {
            *(s16 *)(arg0 + 0x62) = *(s16 *)(arg0 + 0x62) + 1;
            func_80147324(0x8EC);
        }

        val = *(u16 *)(s1 + 0x1A);
        val -= 0x100;
        *(u16 *)(s1 + 0x1A) = val;

        temp = (s16)val;
        if (temp < 0xC00) {
            func_80146CA0(arg0);
        }
    }
}
