/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80176D00 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80078EA6;
extern u8  D_8011F7A8;
extern u16 D_8011F7B4;
extern u16 D_8011F7B6;
extern u8 D_8011F7A8;
extern s32 func_80178004();
extern u8 D_8011F7B1;
extern s16 D_8011F81E;

void func_80176D00(s32 a0) {
    u8 *arr = (u8 *)&D_8011F7A8;
    u8 *base;
    s32 tmp;
    s32 a1v, a2v;
    if (D_8011F7B1 != 0) {
        return;
    }
    base = arr + (s16)a0 * 4;
    tmp = *(s32 *)(base + 0x20) + 0x14;
    *(s32 *)(base + 0x38) = tmp;
    a1v = (s16)(D_8011F7B4 - 0x17);
    a2v = (s16)(D_8011F7B6 + 0x65);
    D_8011F81E = D_80078EA6;
    *(s32 *)(base + 0x40) = func_80178004(tmp, a1v, a2v) - 0x14;
}
