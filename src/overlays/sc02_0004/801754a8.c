/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801754A8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef int (*DispatchFn)();
extern s32 func_80029504(void);
extern s32 D_80126B9C;
extern u8  D_8011F7A8;
extern u8 D_8011F7A8;

void func_801754A8(void) {

    extern u8 D_8011F7A8;
    extern unsigned char D_800B9A13;
    extern s32 D_80126B9C;
    extern DispatchFn D_801814C8[];
    u8 *p = &D_8011F7A8;
    s32 r = func_80029504();
    s32 flag = 0;

    if (((D_800B9A13 == 0) && ((D_80126B9C & 0x80) == 0)) ||
        (0x4AF < (u32)(r - 10))) {
        flag = 1;
    }
    p[9] = flag;
    D_801814C8[p[0]]((void *)p);
}
