/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2D68 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D2E64();
extern void func_8005C604();
extern volatile s32 *aD800DB670 __asm__("D_800DB670");
extern volatile s32 *aD800DB644 __asm__("D_800DB644");
extern volatile s32 *aD800DB650 __asm__("D_800DB650");
extern s32 D_800DB52C;
extern s32 D_800DB5B0;
extern char D_800CEE1C[];

void func_800D2D68(s32 arg0) {
    s32 dummy;
    switch (arg0) {
    case 0:
        *aD800DB670 = 0x80000000;
        *aD800DB644 = 0;
        *aD800DB650 = 0;
        *aD800DB670 = 0x60000000;
        func_800D2E64((s32)&D_800DB52C, 0x20);
        func_800D2E64((s32)&D_800DB5B0, 0x20);
        break;
    case 1:
        *aD800DB670 = 0x80000000;
        *aD800DB644 = 0;
        *aD800DB650 = 0;
        dummy = *aD800DB650;
        *aD800DB670 = 0x60000000;
        break;
    default:
        func_8005C604(D_800CEE1C, arg0);
        break;
    }
}
