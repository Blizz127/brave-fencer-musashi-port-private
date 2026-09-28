/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801718AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern s32 D_80126D50;
extern s32 D_80126D54;
extern u8 D_80126D6C;
extern void func_80171A1C(u8 *a0);

void func_801718AC(void *arg0) {
    D_80126D54 = (s32)arg0;
    D_80126D6C = 0;
    D_80126D50 = *(s32 *)arg0 | (D_80126D50 & 0x7F000000);
    func_80171A1C((u8 *)&D_80126B58);
}
