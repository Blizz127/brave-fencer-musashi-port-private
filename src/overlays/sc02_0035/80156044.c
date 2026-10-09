/* SC02.CD member35 [80156044,8015616C): twin of main_0012 80156044 (src/overlays/main_0012/80156044.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80156044,8015616C) from MAIN.CD member 0012.
 * SHA256(span)=9af3bee5544e8de9658bfd91c05037b477ff6aca8257c32119bd61a05fd956a9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80156044 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80156044(int param_1, int param_2)
{
    extern u32 func_8015616C(s32 a0, u16 a1);
    extern void func_80156670(s32, s32, s32, s32, s32, u16);
    extern void func_801567BC(s32 a0);
    extern void func_80156848(s32, s32);
    extern void func_80156A88(s32 a0, s32 a1);
    extern s32 func_801565C0(void);
    extern u8 D_801864F8;
    extern u8 D_8018650C;
    extern u8 D_80186390;

    register s32 puVar2 __asm__("$2");
    register s32 iVar3 __asm__("$3");
    u8 *puVar4;
    s32 uVar1;

    if (((u32)param_2) & 0x10000) {
        iVar3 = (((u32)param_2) & 0xffff) * 0x14;
        puVar2 = (s32)&D_801864F8;
    } else if (((u32)param_2) & 0x20000) {
        iVar3 = (((u32)param_2) & 0xffff) * 0x14;
        puVar2 = (s32)&D_8018650C;
    } else {
        iVar3 = (((u32)param_2) & 0xffff) * 0x14;
        puVar2 = (s32)&D_80186390;
    }
    puVar4 = (u8 *)(iVar3 + puVar2);
    uVar1 = func_8015616C(((s32)param_1), *(u16 *)puVar4) & 0xffff;
    if (*(u8 *)(((s32)param_1) + 0x1a8) != 0) {
        ((void (*)(s32, s32, s32, s32, s32, s32))func_80156670)(((s32)param_1), *(s32 *)puVar4, uVar1, *(s32 *)(puVar4 + 4),
                      *(u8 *)(puVar4 + 0xA), *(u16 *)(puVar4 + 0x12));
        if (*(u8 *)(puVar4 + 0x10) != 0) {
            func_801567BC(((s32)param_1));
        }
        ((void (*)(s32, s32, s32))func_80156848)(((s32)param_1), (s32)puVar4, uVar1);
        func_80156A88(((s32)param_1), (s32)puVar4);
        if (((s32 (*)(s32))func_801565C0)(((s32)param_1)) != 0) {
            *(u8 *)(((s32)param_1) + 0x1c0) = 1;
        }
    }
}
