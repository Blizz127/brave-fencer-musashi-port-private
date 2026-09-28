/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801602A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern int func_80161208();
extern s32 func_80161208();
extern void func_80154A74(int, int);
extern void func_80159B70(void *a0);
extern void (*D_80180378[])(void *);
extern void func_80159B70(void*);
extern void (*D_80180378[])(void*);
extern void func_80154A74(s32, s32);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);
extern s32 func_80161208(void);
extern void func_80147078(s32 *, s16);

void func_801602A4(s32 *a0) {
    if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
        ((void (**)())D_80180378)[*(u16 *)a0]();
        func_80154A74((s32)a0, 0x11);
        ((void (*)(s32, s32))func_80147078)((s32)a0, 0);
        func_80159B70(a0);
    } else {
        ((s32 (*)(s32 *))func_80161208)(a0);
    }
}
