/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E559C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_80029178(s32);

void func_801E559C(void) {
    extern s32 D_801E256C;
    extern u8 D_801E68BC[];
    extern u8 D_801E68F0[];

    s32 t;
    s32 flag;

    t = func_80029504();
    flag = ((u32)(t - 200) < 100u) ? 0 : ((t < 300) ? 1 : (((func_80029178(250) & 0xFF) ? 0 : ({ __asm__(""); 1; }))));
    if (flag) {
        *(s32 *)(*(s32 *)&D_801E256C + 4) = (s32)D_801E68BC;
    } else {
        *(s32 *)(*(s32 *)&D_801E256C + 4) = (s32)D_801E68F0;
    }
}
