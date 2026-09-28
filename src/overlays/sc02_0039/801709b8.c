/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801709B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void *D_8011F738;
extern void func_80170AD8(void *a0);
extern void func_80171904(s32 a0);
extern void func_80170B48(int a0);
extern u8 D_800D599C[];

void func_801709B8(void) {
    D_8011F738 = D_800D599C;
    func_80171904((s32)func_80170AD8);
    func_80170B48((int)&D_80126B58);
}
