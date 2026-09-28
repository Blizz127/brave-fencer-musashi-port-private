/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164270 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146E90(s32*, s32);
void func_80162D88(s32 *a0);
extern void func_80162D88(s32 *a0);

void func_80164270(s32 *a0) {
    s32 *s = a0;
    func_80162D88(s);
    func_80146E90(s, 0x20);
    func_80146CA0(s);
}
