/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E558 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800D24A0(s32 a0);
extern void func_80141788(void);
extern void *D_8011DB24;

void func_8013E558(void) {
    func_800D24A0(2);
    D_8011DB24 = (void *)func_80141788;
}
