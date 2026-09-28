/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0964 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800D0964(void) {
    typedef struct {
        u32 pad00;      /* 0x00 */
        u32 unk04;      /* 0x04 */
        u32 unk08;      /* 0x08 */
        u32 unk0C;      /* 0x0C */
        u32 unk10;      /* 0x10 */
        u32 unk14;      /* 0x14 */
        u32 unk18;      /* 0x18 */
        u32 unk1C;      /* 0x1C */
        u32 unk20;      /* 0x20 */
        u32 unk24;      /* 0x24 */
        u32 unk28;      /* 0x28 */
        u32 unk2C;      /* 0x2C */
        u32 unk30;      /* 0x30 */
        s16 unk34;      /* 0x34 */
        u8  unk36;      /* 0x36 */
        u8  unk37;      /* 0x37 */
        s16 unk38;      /* 0x38 */
        s16 unk3A;      /* 0x3A */
        s16 unk3C;      /* 0x3C */
        s16 unk3E;      /* 0x3E */
        s16 unk40;      /* 0x40 */
        u8  unk42;      /* 0x42 */
        u8  unk43;      /* 0x43 */
        u8  unk44;      /* 0x44 */
        u8  unk45;      /* 0x45 */
        u8  unk46;      /* 0x46 */
        u8  unk47;      /* 0x47 */
        u8  unk48;      /* 0x48 */
        u8  unk49;      /* 0x49 */
        u8  unk4A;      /* 0x4A */
        u8  unk4B;      /* 0x4B */
        u8  unk4C;      /* 0x4C */
        u8  pad4D[3];   /* 0x4D */
        u32 unk50;      /* 0x50 */
        u32 unk54;      /* 0x54 */
        u32 unk58;      /* 0x58 */
        u32 unk5C;      /* 0x5C */
        u32 unk60;      /* 0x60 */
        u32 unk64;      /* 0x64 */
        u8  unk68;      /* 0x68 */
        u8  pad69[3];   /* 0x69 */
        u32 unk6C;      /* 0x6C */
        u32 unk70;      /* 0x70 */
        u32 unk74;      /* 0x74 */
        u32 unk78;      /* 0x78 */
        u32 unk7C;      /* 0x7C */
        u32 unk80;      /* 0x80 */
        u32 unk84;      /* 0x84 */
        u32 unk88;      /* 0x88 */
        u32 unk8C;      /* 0x8C */
        u32 unk90;      /* 0x90 */
        u32 unk94;      /* 0x94 */
    } Gs_80078E78_init;
    extern u8 D_80078E78[];
    Gs_80078E78_init *p = (Gs_80078E78_init *)D_80078E78;

    p->unk04 = 0;
    p->unk08 = 0;
    p->unk0C = 0;
    p->unk10 = 0;
    p->unk14 = 100;
    p->unk18 = 0x01FE0000;
    p->unk1C = 0;
    p->unk20 = 0;
    p->unk24 = 0x00640000;
    p->unk28 = 0;
    p->unk2C = 0x00640000;
    p->unk30 = 0;
    p->unk34 = 1;
    p->unk36 = 1;
    p->unk37 = 1;
    p->unk38 = 0x81E;
    p->unk3A = 150;
    p->unk3C = 150;
    p->unk3E = 150;
    p->unk40 = 150;
    p->unk42 = 0;
    p->unk43 = 0;
    p->unk44 = 3;
    p->unk45 = 0;
    p->unk46 = 0;
    p->unk47 = 0;
    p->unk48 = 0;
    p->unk49 = 0;
    p->unk4A = 0;
    p->unk4B = 0;
    p->unk4C = 0;
    p->unk50 = 0;
    p->unk54 = 0;
    p->unk58 = 0;
    p->unk5C = 0;
    p->unk60 = 0;
    p->unk64 = 0;
    p->unk68 = 0;
    p->unk6C = 0;
    p->unk70 = 0;
    p->unk74 = 0;
    p->unk78 = 0;
    p->unk7C = 0;
    p->unk80 = 0;
    p->unk84 = 0;
    p->unk88 = 0;
    p->unk8C = 0;
    p->unk90 = 0;
    p->unk94 = 0;
}
