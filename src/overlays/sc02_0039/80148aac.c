/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148AAC - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80148AFC(void *a0);

void func_80148AAC(u8 *a0) {
    u8 *v1;
    if ((func_80148AFC(a0) & 0xff) != 0) {
        v1 = *(u8 **)(a0 + 0x20);
        *(u16 *)(v1 + 0x12) = (*(u16 *)(v1 + 0x12) + 0xFA) & 0xFF8;
    }
}
