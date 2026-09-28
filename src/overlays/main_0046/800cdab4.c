/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDAB4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_800CDBD4(void);
typedef struct { u32 a; u32 b; } U8x __attribute__((packed, aligned(1)));
extern s32 func_80146578(void);
extern void func_8001CC3C(s32 a0, void *a1, s32 a2, s32 a3);
extern void func_800CDBD4();
extern void func_800CDBF4();
extern u8 D_800CE068[];
extern u8 D_800CE08C[];

void func_800CDAB4(s32 *param_1) {
    s32 s0;
    s32 v0;

    s0 = func_80146578();
    *(s32 *)((s32)param_1 + 0x20) = s0;
    if (s0 != 0) {
        func_8001CC3C(s0, D_800CE068, 0x234, 0x1C0);
        *(u8 *)((s32)s0 + 0x27) = 0x26;
        *(u16 *)((s32)s0 + 0x1A) = 0x2000;
        *(u16 *)((s32)s0 + 0x18) = 0x2000;
        *(u32 *)((s32)s0 + 4) |= 0x8000000;
        v0 = *(s32 *)((s32)param_1 + 0x50) * 8;
        *(U8x *)((s32)param_1 + 0x60) = *(U8x *)(&D_800CE08C[v0]);
        func_80146E90(param_1, 0);
        ((void (*)(s32 *))func_800CDBF4)(param_1);
        func_80146CA0(param_1);
    } else {
        ((void (*)(s32 *))func_800CDBD4)(param_1);
    }
}
