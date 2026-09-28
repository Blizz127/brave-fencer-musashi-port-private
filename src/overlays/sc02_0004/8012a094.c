/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A094 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *memcpy(void *, const void *, unsigned int);

void func_8012A094(s32 a0) {
    *(s32 *)(a0 + 0x8) = *(s32 *)(a0 + 0xC);
    *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x14);
    memcpy((void *)(a0 + 0x18), (void *)(a0 + 0x20), 8);
    *(u16 *)(a0 + 0x28) = *(u16 *)(a0 + 0x2E);
    *(u16 *)(a0 + 0x2A) = *(u16 *)(a0 + 0x30);
    *(u16 *)(a0 + 0x2C) = *(u16 *)(a0 + 0x32);
}
