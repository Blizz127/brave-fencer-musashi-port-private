/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147B5C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;

void func_80147B5C(s32 arg0, void *arg1) {
    if (*(s32 *)(arg0 + 0x44) & 0x400000) {
        D_80127090 = *(s32 *)(arg0 + 0x24);
    } else {
        D_80127090 = *(s32 *)arg1;
    }
    if (*(s32 *)(arg0 + 0x44) & 0x800000) {
        D_80127094 = *(s32 *)(arg0 + 0x28);
    } else {
        D_80127094 = *(s32 *)((u8 *)arg1 + 0x4);
    }
    if (*(s32 *)(arg0 + 0x44) & 0x1000000) {
        D_80127098 = *(s32 *)(arg0 + 0x2C);
    } else {
        D_80127098 = *(s32 *)((u8 *)arg1 + 0x8);
    }
    *(s32 *)(arg0 + 0x10) = D_80127090;
    *(s32 *)(arg0 + 0x14) = D_80127094;
    *(s32 *)(arg0 + 0x18) = D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
