/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6AD0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012B2CC(s32 a0);
extern s32 func_8017DAEC();
extern void func_801A4570(void *a0);
extern u16 D_8019FF8A;
typedef struct { u16 a, b, c, d; } Blk8_801A6AD0;

void func_801A6AD0(s32 arg0) {
    /* sync three u16 fields from *(arg0+0x64) into arg0 itself */
    *(s16 *)(arg0 + 0x6) = *(s16 *)(*(s32 *)(arg0 + 0x64) + 0x6);
    *(s16 *)(arg0 + 0xA) = *(s16 *)(*(s32 *)(arg0 + 0x64) + 0xA);
    *(s16 *)(arg0 + 0xE) = *(s16 *)(*(s32 *)(arg0 + 0x64) + 0xE);

    /* 8-byte struct copy at offset 0x50 */
    *(Blk8_801A6AD0 *)(arg0 + 0x50) =
        *(Blk8_801A6AD0 *)(*(s32 *)(arg0 + 0x64) + 0x50);

    /* 8-byte struct copy at offset 0x10 of the nested (+0x20) struct */
    *(Blk8_801A6AD0 *)(*(s32 *)(arg0 + 0x20) + 0x10) =
        *(Blk8_801A6AD0 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x10);

    func_8012B2CC(arg0);

    if (*(s32 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x4) >= 0) {
        if ((D_8019FF8A & 0x200) == 0) {
            func_801A4570((void *)arg0);
        }
    }

    func_8017DAEC();
}
