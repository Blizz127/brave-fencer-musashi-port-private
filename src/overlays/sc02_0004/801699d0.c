/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801699D0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);
extern void func_80146C3C(void);
extern s32 func_80169A4C(s32 a0, s32 a1);

void func_801699D0(void *arg0) {
    s32 temp_v1;
    temp_v1 = *(s32 *)((u8 *)arg0 + 0x1C);
    if (temp_v1 < 0xF) {
        *(s32 *)((u8 *)arg0 + 0x30) = 0xC0 - temp_v1 * 8;
        func_80169A4C((s32)arg0, (s32)arg0 + 0x38);
        func_800D22E4((s32)arg0);
        *(s32 *)((u8 *)arg0 + 0x14) = *(s32 *)((u8 *)arg0 + 0x14) + 0x10000;
        *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)((u8 *)arg0 + 0x1C) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)arg0);
    }
}
