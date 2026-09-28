/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170A00 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void *D_8011F738;
extern void func_80170AD8(void *a0);
extern void func_80171904(s32 a0);
extern void func_80170B48(int a0);
extern u8 D_800D5934[];

void func_80170A00(void) {
    D_8011F738 = D_800D5934;
    func_80171904((s32)func_80170AD8);
    func_80170B48((int)&D_80126B58);
}
