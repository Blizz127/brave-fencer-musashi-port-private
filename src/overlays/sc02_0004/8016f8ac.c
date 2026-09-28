/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F8AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);
extern void func_80172358(u8 *a0, u8 *a1);

void func_8016F8AC(u8 *a0) {
    func_80172358(a0, (u8 *)&D_8011F738);
    func_80171928(a0);
}
