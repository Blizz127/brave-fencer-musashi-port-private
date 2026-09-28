/* Exact retail word export for [8002EE64,8002EE90); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002EE64 - byte-exact against retail at -O2 (tools/register_match.py). */

extern void func_80036EB4(void);
extern void func_8002EC10(void);

struct func_8002EE64_b { u8 c; };

void func_8002EE64(void) {
    s32 g1, g2, g3, g4;
    struct func_8002EE64_b b;

    b.c = 0x88;
    ((void (*)(s32, s32, s32, s32, struct func_8002EE64_b))func_80036EB4)(g1, g2, g3, g4, b);
    func_8002EC10();
}
