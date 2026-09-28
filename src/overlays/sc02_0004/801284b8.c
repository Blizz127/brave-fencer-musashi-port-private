/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801284B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015310(void);
extern void func_80011C10(void);
extern s32 func_800D0588(void);

void func_801284B8(void) {
    if (func_800D0588()) {
        func_80015310();
        func_80011C10();
    }
}
