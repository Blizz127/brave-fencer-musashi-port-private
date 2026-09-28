/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E67C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800D24A0(s32 a0);
extern void *D_8011DB24;
void func_8013E5E8(void);
extern void func_8013E5E8(void);

void func_8013E67C(void) {
    func_800D24A0(0);
    D_8011DB24 = (void *)func_8013E5E8;
}
