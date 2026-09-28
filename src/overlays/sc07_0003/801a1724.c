/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1724 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801A19C8(s32 a0);
extern s32 func_80153BD8(s32 a0);
extern void func_801A1924(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80153C44(s32 a0, s32 a1, s16 a2);
extern u8 D_801F1340[];
extern u8 D_801F1238[];

void func_801A1724(s32 arg0) {
    volatile s32 pad[10];

    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        if (func_801A19C8(arg0) == 1) {
            *(u16 *)(arg0 + 0x34) += 1;
            *(s32 *)(arg0 + 0xE0) |= 0x40;
        } else if (*(s16 *)(arg0 + 0x98) == 0) {
            func_8012A828(arg0, D_801F1238);
            *(u16 *)(arg0 + 0x34) = 4;
        }
        break;
    case 1:
        if (func_80153BD8(arg0) != 0) {
            *(s32 *)(arg0 + 0xE0) |= 8;
            *(u16 *)(arg0 + 0x5C) &= ~0x800;
        } else {
            *(s32 *)(arg0 + 0xE0) &= ~0x40;
        }
        *(u16 *)(arg0 + 0x34) += 1;
    case 2:
        if ((*(s32 *)(arg0 + 0xE0) & 8) != 0) {
            func_801A1924(arg0);
        }
        if (*(s16 *)(arg0 + 0x98) == 0) {
            if ((*(s32 *)(arg0 + 0xE0) & 8) != 0) {
                func_8012A828(arg0, D_801F1340);
                *(u16 *)(arg0 + 0x34) = 3;
            } else {
                func_8012A828(arg0, D_801F1238);
                *(u16 *)(arg0 + 0x34) = 4;
            }
        }
        break;
    case 3:
        if (*(s32 *)(arg0 + 0x94) < 0x86) {
            func_801A1924(arg0);
        }
        if (*(s32 *)(arg0 + 0x94) == 0x3E) {
            func_8002D4C8(0xC18, 0);
        }
        if (*(s32 *)(arg0 + 0x94) == 0x86) {
            func_80153C44(1, 0x50, *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12));
            func_8002D4C8(0xC17, 0);
            func_8002D4C8(0xC7B, 0);
        }
    case 4:
        if (*(s16 *)(arg0 + 0x98) == 0) {
            *(u16 *)(arg0 + 2) = 3;
            *(u16 *)(arg0 + 0x5C) |= 0x800;
            *(s32 *)(arg0 + 0xE0) &= ~0x40;
        }
        break;
    }
}
