/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801705C0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);

void func_801705C0(u8 * a0)
{
    ((void (*)(void))D_8011F738)();
    ((void (*)(s32))func_80171928)(a0);
}
