/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1CC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB1CC(void *arg0) {
    extern s32 func_801465C0();
    extern void func_80146AB4(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6);
    extern void func_8001CC3C(s32 a0, void *a1, s32 a2, s32 a3);
    extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
    extern u8 D_800CB324[];
    extern u8 D_800CB330[];

    s32 pad[6];
    s16 i;
    s32 obj;
    s16 result;

    if (*(s32 *)((s32)arg0 + 0x2C) & 0x8000) {
        for (i = 0; i < 4; i++) {
            func_80146AB4(0x20, (s32)arg0, 0, 0, 0, i * 0x400, 0);
        }
        *(s16 *)((s32)arg0 + 0x16) = -0x38;
        result = 1;
    } else {
        obj = func_801465C0();
        if (obj == 0) {
            return;
        }
        func_8001CC3C(obj, D_800CB324, 0, 0);
        *(u16 *)(obj + 0x1A) = 0x1C00;
        *(u16 *)(obj + 0x18) = 0x1C00;
        *(u8 *)(obj + 0x27) = 0x19;
        *(s32 *)(obj + 4) |= 0xC0000000;
        func_80128EA8(obj, (s32)arg0 + 0x24, (s32)D_800CB330);
        result = 2;
        *(s32 *)((s32)arg0 + 0x20) = obj;
    }
    *(s16 *)((s32)arg0 + 0x2) = result;
}
