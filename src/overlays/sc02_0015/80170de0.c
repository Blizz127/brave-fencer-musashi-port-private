/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170DE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern void *D_8011F738;
extern void func_801718AC(void *a0);
extern s32 D_8011F73C;
extern s32 D_8011F740;

void func_80170DE0(u8 * _arg0)
{
    s32 arg;
    if (((u8 (*)(s32))func_80029178)(D_8011F738)) {
        arg = D_8011F740;
    } else {
        arg = D_8011F73C;
    }
    ((void (*)(s32))func_801718AC)(arg);
}
