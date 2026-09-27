/* MAIN10 resident retail span [800D185C,800D18DC), offset 0x22A64 at base 800AEDF8. */
#include "psx_types.h"

typedef struct {
    u32 words[9];
} Data0x24;

typedef struct {
    u8 pad_00[8];
    u32 f8;
    u8 pad_0c[10];
    u8 f16;
    u8 pad_17[2];
    u8 f19;
} StructAE6A8;

extern Data0x24 D_80078E50;
extern StructAE6A8 D_800AE6A8;

void func_800D185C(u8 *arg0) {
    StructAE6A8 *p = &D_800AE6A8;
    u8 b3;
    D_80078E50 = *(Data0x24 *)arg0;
    p->f16 = arg0[2];
    b3 = arg0[3];
    p->f8 = (u32)arg0 | (p->f8 & 0x01000000);
    p->f19 = b3;
}



