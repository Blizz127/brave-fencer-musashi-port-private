/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F9A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern int func_80161208();
extern s32 func_80161208();
extern void func_80159B70(void *a0);
extern void (*D_80180378[])(void *);
extern void func_80159B70(void*);
extern void (*D_80180378[])(void*);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);
extern s32 func_80161208(void);
extern void func_80147078(s32 *, s16);

void func_8015F9A4(void *arg0) {
    if (*(u16 *)((u8 *)arg0 + 0xB8) & 0x8000) {
        D_80180378[*(u16 *)arg0](arg0);
        func_80147078(arg0, 0);
        func_80159B70(arg0);
    } else {
        ((s32 (*)(void *))func_80161208)(arg0);
    }
}
