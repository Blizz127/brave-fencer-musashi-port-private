/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015EEE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_801473EC(s32 *a0);
extern void func_80147460(s32 a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80148038(s32 a0, s32 a1);
extern s32 func_801725A4(u8 *a0);
extern void func_80148038(int, int);
extern void func_80147460(int);
extern void func_80161418(void *a0);
extern void func_80159B70(void *a0);
extern void func_801473EC(s32*);
extern void (*D_80181798[])(void *);
extern void func_80159B70(void*);
extern void (*D_80181798[])(void*);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);

void func_8015EEE0(void *arg0)
{
    ((void (*)(void *, s32))func_80148038)(arg0, 0x10000);
    ((void (*)(void *))func_80147460)(arg0);
    ((void (*)(void *, s32, s32, s32))func_80147AD4)(arg0, 0, 0, 0x1000);
    ((void (*)(void *))func_801473EC)(arg0);
    if (*(u16 *)((u8 *)arg0 + 0xB8) & 0x8000) {
        D_80181798[*(u16 *)arg0](arg0);
        ((void (*)(void *, s32))func_80147078)(arg0, 0);
        func_80159B70(arg0);
    } else {
        if (((s32 (*)(void *))func_80161418)(arg0) == 0) {
            ((void (*)(void *))func_801725A4)(arg0);
        }
    }
}
