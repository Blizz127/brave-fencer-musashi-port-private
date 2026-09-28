/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80162F08 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80162F60(s32 arg0, s32 arg1);
extern void func_80162F80(s32 arg0, s32 arg1);
extern void func_80162FA0(s32 arg0, s32 arg1);

void func_80162F08(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_80162F60(a0, a1);
    func_80162F80(a0, a2);
    func_80162FA0(a0, a3);
}
