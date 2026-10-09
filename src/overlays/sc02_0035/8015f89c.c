/* SC02.CD member35 [8015F89C,8015F948): twin of main_0012 8015F89C (src/overlays/main_0012/8015f89c.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8015F89C,8015F948) from MAIN.CD member 0012.
 * SHA256(span)=71bb9524117d7daf2f481bf15f4700e1aab262ddf70ef60f948e5357477802b0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F89C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147078(s32 *a0, s16 a1);
extern int func_80161208();
extern s32 func_80161208();
extern void func_80159B70(void *a0);
extern void func_80159B70(void*);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80147078(s32 *, s16);

void func_8015F89C(void *arg0) {

    extern void (*D_80186B6C[])(void *);
    u16 flags = *(u16 *)((u8 *)arg0 + 0xB8);
    if (!(flags & 0x4000)) {
        if (flags & 0x8000) {
            D_80186B6C[*(u16 *)arg0](arg0);
            func_80147078(arg0, 0);
            func_80159B70(arg0);
            return;
        }
    } else {
        func_801466F0(1, arg0, 0, -0x1E, 0, 0, 0, 0);
    }
    ((s32 (*)(void *))func_80161208)(arg0);
}
