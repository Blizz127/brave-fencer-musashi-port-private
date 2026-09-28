/* Complete SC02 retail span [8014AC10,8014ACC0).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014AC10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);
extern s32 D_8011D030;

void func_8014AC10(s32 arg0) {
    u8 *p;
    u8 *end;
    u8 *t;
    s32 one;
    void *a0;
    s32 a1;
    p = (u8 *)&D_8011D030;
    t = p + 0xA50;
    if (p < t) {
        one = 1;
        end = t;
        do {
            if (*(u16 *)p == arg0) {
                a0 = *(void **)(p + 0x20);
                if (a0 != 0) {
                    a1 = 0x38;
                    if (*(u16 *)a0 == one) {
                        a1 = 0x84;
                    }
                    func_80016714(a0, a1);
                }
                func_80016714(p, 0x58);
            }
            p += 0x58;
        } while (p < end);
    }
}
