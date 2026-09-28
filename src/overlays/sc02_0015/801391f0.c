/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801391F0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80139634(void *);
extern void func_80139DC8(void);

void func_801391F0(void *a0) {
    *(s16 *)((s32)a0 + 0x12) = 0;
    *(s16 *)((s32)a0 + 0x14) = 0;
    *(s16 *)((s32)a0 + 0x16) = 0;
    func_80139634(a0);
    func_80139DC8();
}
