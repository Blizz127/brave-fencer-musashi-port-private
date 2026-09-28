/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB8B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void (*D_800CC01C[])(void);
extern void func_80146C3C(void);

void func_800CB8B4(void *arg0) {
    if (D_80078EC1 == 0x17) {
        u16 v0 = *(u16 *)((u8 *)arg0 + 2);
        D_800CC01C[v0]();
    } else {
        func_80146C3C();
    }
}
