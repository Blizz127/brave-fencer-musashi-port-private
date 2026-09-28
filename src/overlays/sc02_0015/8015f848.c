/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F848 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8011F730;
extern void func_80146CA0(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154150(int, int);
extern void func_80154150(s32, s32);

void func_8015F848(s32 *a0) {
    func_801553A8(a0);
    func_80154150((s32)a0, 0x1F);
    D_8011F730 |= 0x5;
    func_80146CA0(a0);
}
