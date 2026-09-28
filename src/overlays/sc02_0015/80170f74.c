/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170F74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80029124(s32, s32);
extern void func_80029124(s32 a0, s32 a1);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);

void func_80170F74(void *a0) {
    func_80029124((s32)D_8011F738, 1);
    func_80171928(a0);
}
