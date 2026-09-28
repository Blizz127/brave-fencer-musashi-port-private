/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165E2C - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern M2C_UNK D_8019F40C;

void func_80165E2C(u16 *arg0) {
    func_8001534C(0, &D_8019F40C, 0x80, 0x80, 0, 0);
    func_800153CC(1, *arg0, 0xA8, 0x80, 0x40, 0);
}
