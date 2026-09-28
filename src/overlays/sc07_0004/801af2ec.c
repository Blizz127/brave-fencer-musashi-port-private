/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AF2EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_8005C49C(void);

void func_801AF2EC(void *a0) {
    s32 *s1;
    s32 *s0;
    u16 v0_const;
    s32 rand_val;
    u16 *val_ptr;

    s1 = (s32 *)a0;
    v0_const = 0x0B;
    __asm__("");
    s0 = *(s32 **)((u8 *)s1 + 0x20);

    
    *(u16 *)((u8 *)s0 + 0x2) = v0_const;

    
    *(s32 *)((u8 *)s0 + 0x4) |= 0x50000000;

    
    if (*(s16 *)((u8 *)s0 + 0x18) == 0) {
        *(s16 *)((u8 *)s0 + 0x18) = 0x600;
    }

    
    rand_val = func_8005C49C();
    *(u16 *)((u8 *)s0 + 0x14) = (u16)(rand_val & 0xFF0);

    
    val_ptr = (u16 *)((u8 *)s1 + 0x2);
    *val_ptr = *val_ptr + 1;

    
    *(s16 *)((u8 *)s1 + 0x30) = 0x100;
}
