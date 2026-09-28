/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD57C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801469C8(s32, void *, s32, s32, u16, s32, s32, s32);

void func_800CD57C(void *arg0) {
    if (((s32 (*)(void *, void *, s32, s32, s32, s32, s32, s32))func_801469C8)(
            (void *)0x27, arg0,
            *(s16 *)((char *)arg0 + 6),
            *(s16 *)((char *)arg0 + 0xA),
            *(s16 *)((char *)arg0 + 0xE),
            *(s32 *)((char *)arg0 + 0x50) & 7,
            0, 8) != 0) {
        (*(s32 *)((char *)arg0 + 0x50)) += 1;
    }
}
