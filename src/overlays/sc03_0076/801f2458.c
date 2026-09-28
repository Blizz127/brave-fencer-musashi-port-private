/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F2458 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_80029178(s32);
extern void func_80029124(s32, s32);

s32 func_801F2458(void) {
    s32 x;
    s32 t;

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
    if (t != 0 && (func_80029178(276) & 0xFF) == 0) {
        func_80029124(276, 1);
        return 1;
    }
    return 0;
}
