/* Exact retail [800234E4,80023570).
 * Words from pinned SLUS_007.26.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800234E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);

void func_800234E4(void *a0, u16 a1, u16 a2) {
    s32 k = 0;
    s32 rad = a1;

    /* Struct-free spelling of the func_800233CC sibling: the only dependencies
     * are common.h types and the two callee externs, so the body survives any
     * splice model (whole-snippet or function-only extraction).  Addresses are
     * written as a0 + k*4 + 0x10/0x12 so LSR keeps the incoming pointer as the
     * IV base (addu s1,a0,zero) and folds the member offset into the sh
     * displacements, exactly as the struct form did. */
    while (k < 12) {
        *(u16 *)((u8 *)a0 + k * 4 + 0x10) = (func_8004787C(a2 + k * 0x155) * rad) >> 12;
        *(u16 *)((u8 *)a0 + k * 4 + 0x12) = (func_80047948(a2 + k * 0x155) * rad) >> 12;
        k++;
    }
}
