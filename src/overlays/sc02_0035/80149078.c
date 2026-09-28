/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149078 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801490E0(s32 *a0, s16 a1);
extern void func_801490E8(s32 *a0, s16 a1);
extern void func_801490F0(s32 *a0, s16 a1);

void func_80149078(s32 *a0, s32 a1, s32 a2, s32 a3) {
    func_801490E0(a0, (s16)a1);
    func_801490E8(a0, (s16)a2);
    func_801490F0(a0, (s16)a3);
}
