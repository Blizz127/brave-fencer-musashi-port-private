/* SC02.CD member31 [801468C8,80146924); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801468C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8011F750;
extern s32 D_8011F754;

u8 *func_801468C8(s32 arg0, u8 arg1) {
    register u8 *var_a2 __asm__("$6");   /* $a2 — returned base ptr  */
    register u8 *var_v1 __asm__("$3");   /* $v1 — scan/store ptr     */
    s32 var_t0;
    s32 var_a3;
    var_t0 = 0;
    var_a2 = (u8 *)(s32)&D_8011F750;
    var_v1 = var_a2;
    var_a3 = 0;
    do {
        if (*var_v1 != 0) {
            var_a2 += 0x2C;
            var_v1 += 0x2C;
            var_t0 += 1;
            var_a3 += 0x2C;
        } else {
            *(s32 *)((s32)&D_8011F754 + var_a3) = arg0;
            *var_v1 = arg1;
            return var_a2;
        }
    } while (var_t0 < 2);
    return (u8 *)0;
}
