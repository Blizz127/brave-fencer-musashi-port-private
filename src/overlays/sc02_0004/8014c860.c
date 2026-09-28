/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C860 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8;
struct S8 { u32 a; u32 b; } __attribute__((packed, aligned(1)));
typedef struct { s16 a; s16 b; s16 c; s16 d; } S8;

s32 func_8014C860(s32 a0, s32 a1) {
    s32 r = 1;
    *(struct S8 *)(a0 + 0x154) = *(struct S8 *)a1;
    *(s16*)(a0 + 0x15A) = r;
    return r;
}
