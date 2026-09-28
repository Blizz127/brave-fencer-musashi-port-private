/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFF50 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8018D0E4(void);

void func_801EFF50(void) {
    extern s32 D_801EF3EC;
    extern s16 D_801EF318;
    extern u8 D_801F0340[];
    extern u8 D_801F0360[];
    s32 p;
    s32 v;

    func_8018D0E4();
    if (D_801EF318 == 0) {
        p = D_801EF3EC;
        v = (s32)&D_801F0340;
    } else {
        p = D_801EF3EC;
        v = (s32)&D_801F0360;
    }
    *(s32 *)(p + 4) = v;
}
