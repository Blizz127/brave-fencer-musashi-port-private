/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80162AF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8011F9D0;
extern void func_80016714(void *a0, s32 a1);

void func_80162AF4(void) {
    func_80016714(&D_8011F9D0, 0x820);
}
