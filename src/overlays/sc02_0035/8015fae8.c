/* SC02.CD member35 [8015FAE8,8015FBE0): twin of main_0012 8015FAE8 (src/overlays/main_0012/8015fae8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8015FAE8,8015FBE0) from MAIN.CD member 0012.
 * SHA256(span)=eb3ab79c9c4799fcf9d6549c0fc8c521aeee2ee5c5ab505b76c6bb060c1ce943.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015FAE8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015BE94();
s32 func_8015BE94(s32 *a0);
extern void func_8015C0C4(s32 a0);
extern void func_8015C0C4(s32);
void func_8015C0C4(s32 a0);
extern void func_80147078(s32*, s16);
extern void func_80147078(s32 *, s16);
extern void func_8015FBE0(s32 *a0);
extern s32 func_801612B8(void *a0, s32 a1);
extern void func_8016007C(s32 a0);

void func_8015FAE8(void *arg0) {

    extern void (*D_80186B6C[])(void *);
    s32 v;

    v = func_801612B8(arg0, 0);
    if (v == 0 || v == 0x8000) {
        ((void (*)(void *))func_8016007C)(arg0);
        *(u32 *)((u8 *)arg0 + 0x184) |= 0x80000000;
        D_80186B6C[*(u16 *)arg0](arg0);
        ((void (*)(void *, s16))func_80147078)(arg0, 3);
        ((void (*)(void *))func_8015BE94)(arg0);
    } else if ((v & 0x4000) != 0) {
        ((void (*)(void *))func_8016007C)(arg0);
        *(u32 *)((u8 *)arg0 + 0x184) |= 0x80000000;
        D_80186B6C[*(u16 *)arg0](arg0);
        ((void (*)(void *, s16))func_80147078)(arg0, 4);
        ((void (*)(void *))func_8015C0C4)(arg0);
    } else {
        ((void (*)(void *))func_8015FBE0)(arg0);
    }
}
