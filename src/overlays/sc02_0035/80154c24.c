/* SC02.CD member35 [80154C24,80154ED8): twin of main_0012 80154C24 (src/overlays/main_0012/80154c24.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, rodata 0x801BCE70, B28 inc 107 twin port). */
/* Overlay range [80154C24,80154ED8) from MAIN.CD member 0012.
 * SHA256(span)=a56313701b31ff869b7dcfe37d71e87675256b524a3f0a23a18cd0fda4b89c22.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154C24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
extern void func_80154ED8(s32 a0, s32 a1);

/* func_80154C24 — shared body (overlay slot 0x80128158, h_text 09f0cdf7). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
void func_80154C24(s32 param_1, s32 *param_2, s32 *param_3) {
    u16 uVar2;
    s32 iVar3;
    s32 uVar5;
    s32 uVar6;

    if (*(u8 *)(param_1 + 0xd4) == 0) {
        return;
    }
    if (*param_2 == 0) {
        *(u16 *)(param_1 + 0xd4) = (u16)*(u8 *)(param_1 + 0xd4);
        *param_2 = *param_2 + 1;
    }
    uVar2 = *(u16 *)(param_1 + 0xd4) - 1;
    *(u16 *)(param_1 + 0xd4) = uVar2;
    if ((uVar2 & 0xff) != 0) {
        goto LAB_80154e6c;
    }
    switch (*(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0))) {
    case 0:
        *(u16 *)(param_1 + 0xd4) = 0;
        *param_3 = *param_3 | 0x8000;
        *(u16 *)(param_1 + 0xd6) = 0;
        *(u8 *)(param_1 + 0xd8) = 0;
        *(u8 *)(param_1 + 0xd9) = 0;
        break;
    case 1:
        *(u16 *)(param_1 + 0xd4) = 1;
        *param_3 = *param_3 | 0x8000;
        *(u8 *)(param_1 + 0xd8) = 0;
        *(u8 *)(param_1 + 0xd9) = 0;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 2:
        *(u16 *)(param_1 + 0xd4) = 0;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        goto LAB_80154e9c;
    case 3:
        uVar5 = *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0) + 4);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 2;
        *(s16 *)(param_1 + 0xd6) = (s16)uVar5;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 5:
        iVar3 = (u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0);
        uVar5 = *(s32 *)(iVar3 + 4);
        uVar6 = *(s32 *)(iVar3 + 8);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = (s8)uVar6;
        *(s32 *)(param_1 + 0xd0) = uVar5;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 6:
        uVar6 = *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0) + 4);
        *(u16 *)(param_1 + 0xd4) = 1;
        *(s8 *)(param_1 + 0xd8) = (s8)uVar6;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 7:
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *param_3 = *param_3 | 0x4000;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        *(s8 *)(param_1 + 0xd9) = *(s8 *)(param_1 + 0xd9) + 1;
        func_80154C24(param_1, param_2, param_3);
        break;
    case 8:
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *param_3 = *param_3 | 0x2000;
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        *(s8 *)(param_1 + 0xd9) = *(s8 *)(param_1 + 0xd9) + 1;
        func_80154C24(param_1, param_2, param_3);
        break;
    default:
        func_80154ED8(param_1, *(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0)));
        *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd6);
        *(s8 *)(param_1 + 0xd8) = *(s8 *)(param_1 + 0xd8) + 1;
        break;
    }
    goto LAB_80154eac;

LAB_80154e6c:
    if (uVar2 != 1) {
        goto LAB_80154eac;
    }
    if (*(s32 *)((u32)*(u8 *)(param_1 + 0xd8) * 4 + *(s32 *)(param_1 + 0xd0)) != 0) {
        goto LAB_80154eac;
    }
LAB_80154e9c:
    *param_3 = *param_3 | 0x8000;
LAB_80154eac:
    *(u16 *)(param_1 + 0xd4) = *(u16 *)(param_1 + 0xd4) | *param_3;
    return;
}
