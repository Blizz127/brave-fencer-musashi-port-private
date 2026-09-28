/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2F88 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
extern const char D_800CEE38[];  /* string at its retail address */
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 *D_800DB670;
extern void func_800D30D0(char *a0);

u32 aF800D2F88(void) __asm__("func_800D2F88");
u32 aF800D2F88(void)
{
    volatile int count = 0x100000;
    while (*(*(u32 **)&D_800DB670) & 0x20000000) {
        if (--count == -1) {
            func_800D30D0(D_800CEE38);
            return -1;
        }
    }
    return 0;
}
