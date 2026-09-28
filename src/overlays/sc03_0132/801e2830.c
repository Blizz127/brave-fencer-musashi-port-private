/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2830 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80175414(s32 _arg0);
extern void func_80171A1C(void*);

void func_801E2830(void) {
    ((void (*)(void))func_80171A1C)();
    ((void (*)(void))func_80175414)();
}
