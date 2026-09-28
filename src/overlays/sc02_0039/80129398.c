/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80129398 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800B9AAC[];
extern s16 D_800B9AAE[];
extern s16 D_800B9AB0[];
extern s16 D_800B9AB2[];
extern s16 D_800B9AB4[];
extern s16 D_800B9AB6[];
extern s16 D_800B9AB8[];
extern s16 D_800B9ABA[];

void func_80129398(void)
{
    s32 i;
    s32 off;
    for (i = 0; i < 2; i++) {
        off = i * 0x54;
        *(s16 *)((char *)D_800B9AAC + off) = 0x7FFF;
        *(s16 *)((char *)D_800B9AAE + off) = 0;
        *(u16 *)((char *)D_800B9AB0 + off) = 0xFFFF;
        *(s16 *)((char *)D_800B9AB2 + off) = 0;
        *(s16 *)((char *)D_800B9AB4 + off) = 0x140;
        *(s16 *)((char *)D_800B9AB6 + off) = 0xEE;
        *(s16 *)((char *)D_800B9AB8 + off) = 0;
        *(s16 *)((char *)D_800B9ABA + off) = 0;
        off += 0x54;
    }
}
