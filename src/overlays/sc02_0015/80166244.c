/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80166244 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);

void func_80166244(void* arg0) {
    ((void (*)(s32, void*, s16, s16, s16, u32, u32))func_80146A6C)(3, arg0, *(s16*)((u8*)arg0 + 6), *(u16*)((u8*)arg0 + 0xA) - 0x10, *(s16*)((u8*)arg0 + 0xE), 0x8F8FFF8, 0xE000B000);
}
