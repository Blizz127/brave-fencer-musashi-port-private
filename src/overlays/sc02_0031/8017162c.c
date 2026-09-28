/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017162C,801716AC).
 * Offset 0x494D4 at overlay base 80128158. SHA256(span)=99b0c815a85ddb0ff6987a0396c6fa66797297345fd43b62143eb1fc7afbb553.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017162c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017162C - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 func_801716AC(s32 a0, void *a1, s32 *a2);
extern void func_80171928(void *a0);

void func_8017162C(void *a0) {
    void *s1 = a0;
    void *s0 = D_8011F738;
    s32 local;
    local = 0;
    func_801716AC(0, s0, &local);
    func_801716AC(1, s0, &local);
    func_801716AC(2, s0, &local);
    if (local == 0) {
        func_80171928(s1);
    }
}
