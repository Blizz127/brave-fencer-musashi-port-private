/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170670 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);
extern void func_8012A568(void (*a0)(void));

void func_80170670(void *a0) {
    func_8012A568((void (*)(void))D_8011F738);
    func_80171928(a0);
}
