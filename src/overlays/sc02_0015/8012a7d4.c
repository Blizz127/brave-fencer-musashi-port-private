/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A7D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801151D4;

void func_8012A7D4(void *arg0, void *arg1) {
    s32 p;
    p = D_801151D4;
    *(s16 *)((u8 *)arg0 + 0x0) = *(s32 *)(p + 0x3C);
    *(s16 *)((u8 *)arg0 + 0x2) = *(s32 *)(p + 0x40);
    *(s16 *)((u8 *)arg0 + 0x4) = *(s32 *)(p + 0x44);
    *(s16 *)((u8 *)arg1 + 0x0) = *(s32 *)(p + 0x48);
    *(s16 *)((u8 *)arg1 + 0x2) = *(s32 *)(p + 0x4C);
    *(s16 *)((u8 *)arg1 + 0x4) = *(s32 *)(p + 0x50);
}
