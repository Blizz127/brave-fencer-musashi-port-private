/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBC14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CBEB8(void);

void func_800CBC14(void *arg0) {
    extern void func_80146578(void);
    extern void func_8001CB00(s32, void *, s32, s32);
    extern void func_80146DE8(s32 *, s32, s32, s32);
    extern void func_80146CA0(void *);
    extern void func_800CBEB8(void);
    extern u8 D_800CC00C;
    s32 v0;

    v0 = ((s32 (*)(void))func_80146578)();
    *(s32 *)((s32)arg0 + 0x20) = v0;
    if (v0 != 0) {
        func_8001CB00(v0,
            (void *)((s32)&D_800CC00C + (*(s32 *)((s32)arg0 + 0x50)) * 12),
            0x200, 0x100);
        *(s16 *)(v0 + 0x2C) = 1;
        *(u8 *)(v0 + 0x27) = 8;
        *(u8 *)(v0 + 0x25) = 0x20;
        *(u8 *)(v0 + 0x24) = 0x20;
        *(s32 *)(v0 + 0x4) |= 0x40000000;
        func_80146DE8((s32 *)arg0, 0, 0xFFFC0000, 0);
        func_80146CA0(arg0);
    } else {
        ((void (*)(void *))func_800CBEB8)(arg0);
    }
}
