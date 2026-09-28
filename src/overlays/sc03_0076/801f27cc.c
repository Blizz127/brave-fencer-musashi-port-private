/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F27CC - byte-exact against retail at -O2 (tools/register_match.py). */
s32 *func_801F2690(void);
extern s32 *func_801F2690(void);
extern s32 D_801F9F54;
extern s32 D_801F9DDC[];
extern s32 D_801F9DD8[];

s32 func_801F27CC(s32 a0) {
    s32 s0 = a0;
    s32 v0;
    s32 v1;
    ((s32 (*)(void))func_801F2690)();
    v0 = D_801F9F54;
    if (v0 > 0) {
        v1 = 0;
        a0 = v0 << 4;
        do {
            if (*(s32 *)((s32)&D_801F9DDC + v1) == s0) {
                v0 = *(s32 *)((s32)&D_801F9DD8 + v1);
                goto end;
            }
            v1 += 0x10;
        } while (v1 < a0);
    }
    v0 = 0;
end:
    return v0;
}
