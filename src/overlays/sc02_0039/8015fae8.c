/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015FAE8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015BE94();
extern s32 func_8015BE94(s32 *a0);
extern void func_8015C0C4(s32 a0);
extern void func_8015C0C4(s32);
extern void (*D_80181798[])(void *);
extern void (*D_80181798[])(void*);
extern void func_80147078(s32*, s16);
extern void func_80147078(s32 *, s16);
extern void func_8015FBE0(s32 *a0);
extern s32 func_801612B8(void *a0, s32 a1);
extern void func_8016007C(s32 a0);

void func_8015FAE8(void *arg0) {
    s32 v;

    v = func_801612B8(arg0, 0);
    if (v == 0 || v == 0x8000) {
        ((void (*)(void *))func_8016007C)(arg0);
        *(u32 *)((u8 *)arg0 + 0x184) |= 0x80000000;
        D_80181798[*(u16 *)arg0](arg0);
        ((void (*)(void *, s16))func_80147078)(arg0, 3);
        ((void (*)(void *))func_8015BE94)(arg0);
    } else if ((v & 0x4000) != 0) {
        ((void (*)(void *))func_8016007C)(arg0);
        *(u32 *)((u8 *)arg0 + 0x184) |= 0x80000000;
        D_80181798[*(u16 *)arg0](arg0);
        ((void (*)(void *, s16))func_80147078)(arg0, 4);
        ((void (*)(void *))func_8015C0C4)(arg0);
    } else {
        ((void (*)(void *))func_8015FBE0)(arg0);
    }
}
