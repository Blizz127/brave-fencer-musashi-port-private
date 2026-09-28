/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801710DC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);
extern u16 D_8011F73A;

void func_801710DC(u8 * arg0)
{
    ((M2C_UNK (*)(u16, u16))func_8002D4C8)(D_8011F738, D_8011F73A);
    ((M2C_UNK (*)(s32))func_80171928)(arg0);
}
