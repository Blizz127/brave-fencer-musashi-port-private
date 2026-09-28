/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB188 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149374(s32 a0, s32 a1);
typedef struct { s32 w[4]; } func_800CB188_Blk16;

void func_800CB188(void *arg0) {
    extern u16 D_800B99DA;
    s32 s0;
    s32 s1;
    s32 v0;
    s32 v1;

    s0 = *(s32 *)((s32)arg0 + 0x4C);
    s1 = *(s32 *)((s32)arg0 + 0x20);
    *(s32 *)((s32)arg0 + 0xC) = 0;
    *(s32 *)((s32)arg0 + 0x8) = 0;
    *(s32 *)((s32)arg0 + 0x4) = 0;
    func_80149374(s0, (s32)arg0 + 4);
    v0 = *(s32 *)(s0 + 0x20);
    *(func_800CB188_Blk16 *)(s1 + 0x34) = *(func_800CB188_Blk16 *)(v0 + 0x34);
    *(func_800CB188_Blk16 *)(s1 + 0x44) = *(func_800CB188_Blk16 *)(v0 + 0x44);
    v1 = *(s32 *)(s1 + 4) & 0x7FFFFFFF;
    *(s32 *)(s1 + 4) = v1;
    if (D_800B99DA & 1) {
        *(s32 *)(s1 + 4) = v1 | 0x80000000;
    }
}
