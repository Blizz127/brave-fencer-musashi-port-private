/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBBF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8011F9D0[];
extern void func_80162CCC();

void func_800CBBF8(void) {
    extern s32 D_8011F9D0[];
    extern void func_80016714(s8 *a0, s32 a1);
    extern void func_80162CCC(void);
    u8 *p;

    for (p = (u8 *)&(*(s32 *)D_8011F9D0); p < (u8 *)&(*(s32 *)D_8011F9D0) + 0x820; p += 0x68) {
        if (*(u16 *)p == 0x27) {
            if (*(s32 *)(p + 0x10) != 0) {
                func_80016714(*(s8 **)(p + 0x10), 0x38);
            }
            ((void (*)(u8 *))func_80162CCC)(p);
        }
    }
}
