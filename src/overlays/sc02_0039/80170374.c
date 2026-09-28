/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170374 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C168(s32 * param_1, s32 param_2);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);
extern s16 func_80171AB0(s32 a0, void *a1);
extern s32 func_8014C168(s32 *a0, s32 a1);

void func_80170374(u8 * a0)
{
    s16 sp[4];
    s32 v0;
    v0 = func_8014C168(a0, (s32)D_8011F738);
    sp[0] = *(u16 *)(v0 + 0x6);
    sp[1] = *(u16 *)(v0 + 0xA);
    sp[2] = *(u16 *)(v0 + 0xE);
    if (func_80171AB0((s32)a0, sp) == 0) {
        func_80171928(a0);
    }
}
