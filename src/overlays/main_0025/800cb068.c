/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB068 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801466F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern void func_80147324(s32 arg0);

void func_800CB068(void *a0) {
    u16 bits = *(u16 *)((s32)a0 + 0xB8);
    if (bits & 0x4000) {
        func_801466F0(10, (s32)a0, 0, 0, 0, *(u8 *)((s32)a0 + 0xBE), 0, 0);
        func_80147324(0x649);
    } else if (bits & 0x8000) {
        *(u8 *)((s32)a0 + 0x197) += 1;
    }
}
