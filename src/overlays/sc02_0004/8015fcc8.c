/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015FCC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800AE6B0;
extern void func_80146CA0(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8014BFF4(s32 a0, s32 a1);
extern void func_80159B70(void *a0);
extern void (*D_80180378[])(void *);
extern void func_80159B70(void*);
extern void (*D_80180378[])(void*);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);
extern void func_80147078(s32 *, s16);
extern void func_8016007C(s32 a0);

void func_8015FCC8(void *param_1) {
    if ((D_800AE6B0 & 0x80FFFFFF) != 0) {
        ((void (*)(void))func_8016007C)();
        D_80180378[*(u16 *)param_1](param_1);
        ((void (*)(void *, s32))func_80147078)(param_1, 0);
        func_80159B70(param_1);
    } else {
        *(u8 *)((s32)param_1 + 0x197) = 0;
        *(u8 *)((s32)param_1 + 0xBE) = 0;
        *(u8 *)((s32)param_1 + 0xBF) = 0;
        *(u8 *)((s32)param_1 + 0x1A0) = (u8)*(s32 *)((s32)param_1 + 0x184);
        ((s32 (*)(void *, s32))func_8014BFF4)(param_1, 1);
        func_80146CA0(param_1);
    }
}
