/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016236C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void func_8014706C(void *arg0);
extern void func_8014706C(void *a0);

s32 func_8016236C(u8 *a0) {
    func_8014706C(&D_80126B58);
    *(s32 *)(a0 + 0x28) = 0xA;
    *(u8 *)(a0 + 0x15) += 1;
    return 0;
}
