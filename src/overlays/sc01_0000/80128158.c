/* SC01.CD member0 PAC0, decoded [80128158,80128420).
 * tools/decode_title_pac.py pins the archive; no matched C claim.
 * Words must equal the live guest RAM before execution. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128158 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80128288(void);

void func_80128158(void) {
    func_80128288();
}
