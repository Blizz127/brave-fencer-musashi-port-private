/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C308 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_8014C308(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");
    if (*(u16 *)((u8 *)arg1 + 0x0) == 0) {
        return 0;
    }
    if (*(s32 *)((u8 *)arg1 + 0x58) == 0) {
        return 0;
    }
    if (*(u16 *)((u8 *)arg1 + 0x5E) != arg2) {
        if ((*(s32 *)((u8 *)arg1 + 0x5C) & 0xC100) != 0x8000) {
            return 0;
        }
        if ((*(s16 *)((u8 *)arg1 + 0xAE) & (u16)arg3) == 0) {
            v0 = 1;
            v1 = 9;
            if (arg2 == v1) return v0;
            v1 = 0x11;
            if (arg2 == v1) return v0;
            v1 = 0x29;
            if (arg2 == v1) return v0;
            v1 = 0xA;
            if (arg2 == v1) return v0;
            return *(s32 *)((u8 *)arg0 + 0x178) != arg1;
        }
    }
    return 0;
}
