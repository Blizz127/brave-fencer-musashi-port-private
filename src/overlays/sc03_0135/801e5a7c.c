/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E5A7C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801EAC70;
extern s32 D_801EADF0;
extern void func_80016714(void *a0, s32 a1);

void func_801E5A7C(void) {
    func_80016714(&D_801EAC70, 0x180);
    D_801EADF0 = 0;
}
