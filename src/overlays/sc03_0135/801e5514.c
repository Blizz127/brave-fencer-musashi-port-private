/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E5514 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);

s32 func_801E5514(void) {
    extern s32 func_80029504(void);
    extern s32 func_80029178(s32);
    extern u8 D_801E67E8[];
    extern u8 D_801E6828[];
    extern s32 D_801E256C;
    s32 x;
    s32 t;
    s32 p;
    s32 v;

    x = func_80029504();
    if ((u32)(x - 200) < 100) {
        t = 0;
        goto join;
    }
    __asm__("");
    if (x < 300) {
        t = 1;
        goto join;
    }
    __asm__("");
    if (func_80029178(250) & 0xFF) {
        t = 0;
        goto join;
    }
    __asm__("");
    t = 1;
join:
    if (t != 0) {
        p = D_801E256C;
        v = (s32)&D_801E67E8;
    } else {
        p = D_801E256C;
        v = (s32)&D_801E6828;
    }
    *(s32 *)(p + 4) = v;
    return v;
}
