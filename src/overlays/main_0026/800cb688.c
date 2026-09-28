/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB688 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *arg0);

void func_800CB688(void *a0) {
    s32 v1 = -0x100;
    *(u16 *)((s32)a0 + 0x12) = v1;
    *(u16 *)((s32)a0 + 0x16) = v1;
    v1 = *(s32 *)((s32)a0 + 0x50);
    *(u16 *)((s32)a0 + 0x14) = 8;
    *(u16 *)((s32)a0 + 0x10) = 0;
    *(u8 *)((s32)a0 + 0x58) = 0xFF;
    *(u8 *)((s32)a0 + 0x59) = 0xFF;
    *(u8 *)((s32)a0 + 0x5A) = 0xFF;
    *(u8 *)((s32)a0 + 0x5B) = 0;
    *(u8 *)((s32)a0 + 0x5C) = 0;
    *(u8 *)((s32)a0 + 0x5D) = 0;
    *(u8 *)((s32)a0 + 0x5E) = 0xFF;
    *(u8 *)((s32)a0 + 0x5F) = 0;
    *(u16 *)((s32)a0 + 0x18) = v1;
    func_80146CA0(a0);
}
