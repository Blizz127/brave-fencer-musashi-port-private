/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801717A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801719A4(int a0, int a1);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);
extern int func_800D0F8C(int a0);
extern void func_801719A4(int, int);
extern int func_800D0FE0(int a0);

void func_801717A0(void *a0) {
    int v0;
    func_801719A4((int)a0, 1);
    v0 = func_800D0F8C(*(u8 *)&D_8011F738);
    if (v0 != 0) {
        func_800D0FE0(v0);
    }
    func_80171928(a0);
}
