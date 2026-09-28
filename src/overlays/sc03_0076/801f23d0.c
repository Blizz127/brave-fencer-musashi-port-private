/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F23D0 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801F23D0(void) {
    extern s32 func_80029504(void);
    extern s32 func_80029178(s32);
    extern u8 D_801F3830[];
    extern u8 D_801F3864[];
    extern s32 D_801EF3EC;
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
        p = D_801EF3EC;
        v = (s32)&D_801F3830;
    } else {
        p = D_801EF3EC;
        v = (s32)&D_801F3864;
    }
    *(s32 *)(p + 4) = v;
    return v;
}
