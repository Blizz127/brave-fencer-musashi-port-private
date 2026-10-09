/* SC02.CD member35 [801594E8,80159698): twin of main_0012 801594E8 (src/overlays/main_0012/801594e8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, rodata 0x801BCEDC, B28 inc 107 twin port). */
/* Overlay range [801594E8,80159698) from MAIN.CD member 0012.
 * SHA256(span)=2dd7108658b691a560ed104cdbda5b68d0b07ca4c7fee1603f68fa296c9847ac.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801594E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
extern s32 func_80029178(s32);
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern void func_800D185C(u8 *a0);
extern void func_80029124(s32, s32);
extern void func_80029514(s32);
extern u8 D_80078E78[];
extern void func_8014BEC0(void);
extern void func_80175454(void);
extern void func_800CF804(void);

/* func_801594E8 — shared body (overlay slot 0x80128158, h_text 8b10eab6). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
void func_801594E8(s32 param_1, s32 param_2)
{
    extern void func_80029274(void);
    extern void func_80029044(void);
    extern void func_8002906C(void);
    extern void func_80029094(void);
    extern void func_8002941C(void);
    extern void func_8002AB64(void);
    extern void func_800D1F90(void);
    extern s32 D_80128150;
    extern u8 D_800D3A44[];
    extern u8 D_800D39FC[];
    extern u8 D_800D3A20[];


    u8 *p = D_80078E78;

    func_80175454();
    switch (param_2) {
    case -1: {
        struct { u8 a, b, c; u8 pad[5]; u8 d, e; } t;
        s32 saved;
        t.a = ((s32(*)(s32))func_80029178)(0xB);
        t.b = ((s32(*)(s32))func_80029178)(0xC);
        t.c = ((s32(*)(s32))func_80029178)(0xD);
        t.d = ((s32(*)(s32))func_800291B4)(0x2C);
        t.e = ((s32(*)(s32))func_800291B4)(0x2D);
        saved = *(s32 *)(p + 0x4);
        func_80029274();
        func_80029044();
        func_8002906C();
        func_80029094();
        func_8002941C();
        ((void(*)(s32, s32))func_80029124)(0xB, t.a);
        ((void(*)(s32, s32))func_80029124)(0xC, t.b);
        ((void(*)(s32, s32))func_80029124)(0xD, t.c);
        func_800291A0(0x2C, t.d);
        func_800291A0(0x2D, t.e);
        *(s32 *)(p + 0x4) = saved;
        ((void (*)(s32))func_8014BEC0)(param_1);
        func_8002AB64();
        func_80029514(2);
        ((void(*)(u8 *))func_800D185C)(D_800D3A44);
        func_800CF804();
        break;
    }
    case 1:
        *(s16 *)(p + 0x3C) = 0x96;
        *(s16 *)(p + 0x40) = 0x96;
        *(s32 *)(p + 0x14) = D_80128150;
        break;
    case 2:
    case 3:
    case 4:
        func_800D1F90();
        break;
    case 5:
        func_800D1F90();
        ((void(*)(u8 *))func_800D185C)(D_800D39FC);
        func_80029514(0x636);
        break;
    case 6:
        func_800D1F90();
        ((void(*)(u8 *))func_800D185C)(D_800D3A20);
        func_80029514(0x636);
        break;
    }
}
