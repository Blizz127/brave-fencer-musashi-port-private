/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC968 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CC968(void *a0) {
    s32 *t = *(s32 **)((u8 *)a0 + 0x4C);
    *(u16 *)((u8 *)a0 + 6) = *(u32 *)((u8 *)*(s32 **)((u8 *)t + 0x20) + 0x48);
    *(u16 *)((u8 *)a0 + 10) = *(u32 *)((u8 *)*(s32 **)((u8 *)t + 0x20) + 0x4C);
    *(u16 *)((u8 *)a0 + 14) = *(u32 *)((u8 *)*(s32 **)((u8 *)t + 0x20) + 0x50);
}
