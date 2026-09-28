/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012DFD4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012E014(s32 arg0);
extern void func_8012E138();

void func_8012DFD4(u8 *a0) {
    if (a0[0x74]) {
        ((void (*)(void))func_8012E014)();
    } else {
        func_8012E138();
    }
}
