/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801601E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern int func_80161208();
extern s32 func_80161208();
extern void func_80154A74(int, int);
extern void func_80154150(int, int);
extern void func_80154A74(s32, s32);
extern void func_80154150(s32, s32);
extern s32 func_80161208(void);

void func_801601E4(s32 *a0) {
    if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
        func_80154150((s32)a0, 0x22);
        func_80154A74((s32)a0, 0x1A);
        func_80146CA0(a0);
    } else {
        ((s32 (*)(s32 *))func_80161208)(a0);
    }
}
