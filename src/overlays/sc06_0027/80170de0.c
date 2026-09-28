/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170DE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void *D_8011F738;
extern s32 D_8011F73C;
extern s32 D_8011F740;
extern s32 func_80029178(s32 arg);
extern void func_801718AC(void *a0);

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
