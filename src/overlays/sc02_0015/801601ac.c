/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801601AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C98(s32 *a0, s16 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154150(int, int);
extern void func_80154150(s32, s32);

void func_801601AC(s32 *a0) {
    func_80154150((s32)a0, 0x21);
    func_80146C98(a0, 1);
}
