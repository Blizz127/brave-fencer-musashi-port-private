/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801449C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80185E74[])(void *);

void func_801449C8(void *a0) {
    D_80185E74[*(u16 *)((s32)a0 + 0x2)](a0);
}
