/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170B90 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147060(u8 * a0);
extern void func_80147060(u8 *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *);

void func_80170B90(u8 *a0) {
    if (*(u16 *)(a0 + 0xB8) & 0x8000) {
        func_80147060(a0);
        func_80171928(a0);
    }
}
