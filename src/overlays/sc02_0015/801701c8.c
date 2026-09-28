/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801701C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);

void func_801701C8(u8 * a0)
{
    s16 *p;
    s32 r;
    r = func_80012B04(((s16 **)a0)[8][9], *(s16 *)&D_8011F738, 4);
    if ((s16)r == 0) {
        func_80171928(a0);
    }
    p = ((s16 **)a0)[8];
    ((u16 *)p)[9] = (((u16 *)p)[9] + r) & 0xFFF;
}
