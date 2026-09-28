/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801598E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80159968(void *a0);

void func_801598E0(u8 *a0) {
    switch (a0[0xA9]) {
    case 0x41:
        *(u16 *)(a0 + 0xAA) &= 0xAFFF;
        *(u16 *)(a0 + 0xAC) &= 0xAFFF;
        break;
    case 0x53:
    case 0x73:
        *(u16 *)(a0 + 0xAE) = a0[0xAE] | 0x8000;
        break;
    }
    func_80159968((void *)a0);
}
