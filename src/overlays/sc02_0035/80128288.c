/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128288 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_800B99F6;
extern void (*D_80184768[])(void);

void func_80128288(void) {
    u32 v1;
    v1 = D_800B99F6;
    if (v1 < 9) {
        D_80184768[v1]();
    }
}
