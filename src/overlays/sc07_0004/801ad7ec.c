/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD7EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Struct801AD7EC_Local;
extern void func_801AD914();

void func_801AD7EC(s32 a0) {
    /* register pins reproduce the target's density-priority regalloc order
       (cookbook §32#1 / regalloc-order): val->$s0, obj->$s1, i->$s2,
       c700->$s3, c100->$s4 -- matching the sw/addiu prologue order. */
    register s32 obj __asm__("$17") = a0;
    register s32 i __asm__("$18");
    register s32 c700 __asm__("$19");
    register s32 c100 __asm__("$20");
    register s32 val __asm__("$16");
    Struct801AD7EC_Local local;

    local.z = 0;

    i = 0;
    c100 = 0x100;
    c700 = 0x700;
    val = 0x200;
    for (; i < 4; i++) {
        local.y = val;
        local.x = c100;
        func_801AD914(obj, &local, 0x400000);
        local.x = c700;
        func_801AD914(obj, &local, 0x400000);
        val += 0x400;
    }

    i = 0;
    val = 0xC0;
    for (; i < 8; i++) {
        local.y = val;
        local.x = 0x200;
        func_801AD914(obj, &local, 0x400000);
        local.x = 0x300;
        func_801AD914(obj, &local, 0x400000);
        local.x = 0x400;
        func_801AD914(obj, &local, 0x400000);
        local.x = 0x500;
        func_801AD914(obj, &local, 0x400000);
        local.x = 0x600;
        func_801AD914(obj, &local, 0x400000);
        val += 0x200;
    }
}
