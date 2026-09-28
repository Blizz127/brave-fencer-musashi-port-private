/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F804 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void func_80171928(void *);

void func_8016F804(void *a0) {
    if (*(u8 *)((s32)a0 + 0x1C2) != 0) {
        *(u8 *)((s32)a0 + 0x1C2) = 0;
        func_80171928(a0);
    }
}
