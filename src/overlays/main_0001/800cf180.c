/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CF180 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CF180(void)
{
    extern u16 D_800B9A02;
    extern u8 D_800CF3F0[];
    extern u8 D_800CF420[];
    extern u8 D_800AA60C[];

    register u32 m24 __asm__("$8");
    register u32 mFF __asm__("$7");
    register u32 *tb __asm__("$9");
    register u32 *ab __asm__("$6");
    u32 *pp;

    m24 = 0x00FFFFFF;
    tb = (u32 *)D_800CF3F0;
    {
        register s32 i __asm__("$2") = D_800B9A02;
        mFF = 0xFF000000;
        *(u32 *)((s32)tb + i * 24) =
            (*(u32 *)((s32)tb + i * 24) & mFF) |
            (*(u32 *)((s32)D_800AA60C + (i << 14)) & m24);
    }

    {
        register s32 i __asm__("$4") = D_800B9A02;
        ab = (u32 *)D_800AA60C;
        pp = (u32 *)(i << 14);
        pp = (u32 *)((s32)pp + (s32)ab);
        *pp = (*pp & mFF) | ((u32)((s32)tb + i * 24) & m24);
    }

    {
        register s32 i __asm__("$2") = D_800B9A02;
        tb = (u32 *)D_800CF420;
        *(u32 *)((s32)tb + i * 24) =
            (*(u32 *)((s32)tb + i * 24) & mFF) |
            (*(u32 *)((s32)ab + (i << 14)) & m24);
    }

    {
        register s32 i __asm__("$4") = D_800B9A02;
        s32 frame_pad[1];
        (void)&frame_pad;
        pp = (u32 *)(i << 14);
        pp = (u32 *)((s32)pp + (s32)ab);
        *pp = (*pp & mFF) | ((u32)((s32)tb + i * 24) & m24);
    }
}
