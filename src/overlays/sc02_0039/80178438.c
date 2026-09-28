/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178438 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern M2C_UNK D_8019F654;

void func_80178438(u16 *arg0) {
    func_8001534C(2, &D_8019F654, 0x80, 0x88, 0, 0);
    func_800153CC(3, *arg0, 0xA8, 0x88, 0x40, 0);
}
