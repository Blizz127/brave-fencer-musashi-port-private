/* Complete retail function; independently matched ordinary C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C1B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *func_8001CFDC(s32 a, s32 b);

/* B28: returns 8001CFDC's record pointer. The retail tail call leaves it in
 * v0 and 80132018/801320D8 use it as the result; byte-identical
 * (rebuilt with gcc-2.7.2-psx -O2). */
void *func_8012C1B8(void) {
    return func_8001CFDC(0x26, 0x85);
}
