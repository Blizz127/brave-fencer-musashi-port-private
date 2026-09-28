/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AEB04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u8 unk0[8];
} B8_801AEB04;
typedef struct {
    u8 unk0[4];
} M4_801AEB04;
extern const s8 D_801A022C[4];  /* data at its retail address */

void func_801AEB04(s32 a0, s16 a1, s32 a2, s32 a3) {
    *(u16 *)(a0 + 0x00) = 1;
    *(u16 *)(a0 + 0x02) = a1;
    *(B8_801AEB04 *)(a0 + 0x04) = *(B8_801AEB04 *)a2;
    *(u16 *)(a0 + 0x10) = 0x1000;
    *(u16 *)(a0 + 0x0E) = 0x1000;
    *(u16 *)(a0 + 0x0C) = 0x1000;
    *(u16 *)(a0 + 0x12) = 0;
    *(s32 *)(a0 + 0x20) = a3;
    *(M4_801AEB04 *)(a0 + 0x14) = *(M4_801AEB04 *)&D_801A022C;
    *(M4_801AEB04 *)(a0 + 0x18) = *(M4_801AEB04 *)&D_801A022C;
    *(M4_801AEB04 *)(a0 + 0x1C) = *(M4_801AEB04 *)&D_801A022C;
}
