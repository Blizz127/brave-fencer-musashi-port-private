/* Exact retail word export for [8001D388,8001D3FC); EXE and assembly verified. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8001D388 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern void (*D_8006351C[])(void *);

void func_8001D388(u8 *obj) {
    if (*(s32 *)(obj + 4) >= 0 && *(s32 *)(obj + 0x20) != 0 &&
        *(u16 *)obj == 2 && *(u16 *)(obj + 2) < 11) {
        D_8006351C[*(u16 *)(obj + 2)](obj);
    }
}
