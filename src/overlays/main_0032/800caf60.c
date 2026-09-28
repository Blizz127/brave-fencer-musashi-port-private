/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF60 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAF60(void *a0) {
    extern void func_80147A84(s32 a0);
    extern void func_801473EC(s32 *a0);
    extern void func_80148038(s32 a0, s32 a1);
    extern void func_80147460(s32 a0);
    extern s32  func_80161418(void *a0);
    extern s32  func_80155FD4(s32 a0, s32 a1);

    *(u32 *)((u8 *)a0 + 0x44) |= 2;
    func_80147A84((s32)a0);
    func_801473EC((s32 *)a0);
    func_80148038((s32)a0, 0x20000);
    func_80147460((s32)a0);
    if (func_80161418(a0) == 0) {
        func_80155FD4((s32)a0, *(u8 *)((u8 *)a0 + 0x1AA));
    }
}
