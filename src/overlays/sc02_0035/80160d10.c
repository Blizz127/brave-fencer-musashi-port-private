/* SC02.CD member35 [80160D10,80160DEC): twin of main_0012 80160D10 (src/overlays/main_0012/80160d10.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80160D10,80160DEC) from MAIN.CD member 0012.
 * SHA256(span)=ab6efa723fac9a80f29b99a7454d2cc1f5e0f54a8b60f6db748e81024b9a5fca.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80160D10 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern u16 func_80148800(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_80159B70(void *a0);
extern u16  func_80148800(s32 *a0);
extern void func_80159B70(void*);
extern u16 func_80148800(s32*);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);
extern void func_80147078(s32 *, s16);
extern s32  func_80161208();

void func_80160D10(void *arg0) {

    extern void (*D_80186B6C[])(void *);
    if (*(u32 *)((u8 *)arg0 + 0x44) & 0x10) {
        D_80186B6C[*(u16 *)arg0](arg0);
    } else {
        if (*(s32 *)((u8 *)arg0 + 0x1AC) == 0) {
            if ((((s32 (*)(void *))func_80148800)(arg0) & 0xF0) == 0) {
                goto dd0;
            }
        } else {
            s32 t = *(s32 *)((u8 *)arg0 + 0x1AC) - 0xAAA8;
            *(s32 *)((u8 *)arg0 + 0x1AC) = t;
            if (t >= 0) {
                goto dd0;
            }
        }
        D_80186B6C[*(u16 *)arg0](arg0);
    }
    ((void (*)(void *, s16))func_80147078)(arg0, 0);
    func_80159B70(arg0);
    return;
dd0:
    ((s32 (*)(void *))func_80161208)(arg0);
}
