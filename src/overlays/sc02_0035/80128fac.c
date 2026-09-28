/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128FAC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern M2C_UNK D_801BC3F4;

void func_80128FAC(u16 *arg0) {
    func_8001534C(4, &D_801BC3F4, 0x80, 0x90, 0, 0);
    func_800153CC(5, *arg0, 0xA8, 0x90, 0x40, 0);
}
