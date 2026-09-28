/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD6A4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8001382C(s32 a0, void *a1, void *a2);
extern s32 func_8014C59C(void *a0, void *a1);
extern s32 D_800CE058[3];

void func_800CD6A4(void *arg0, void *arg1) {
    s32 sp10[4];
    s32 ret;

    ret = func_8014C59C(arg0, arg1);
    func_8001382C((ret + 0x800) & 0xFFF, D_800CE058, sp10);
    *(s32 *)((s32)arg0 + 0x234) = sp10[0];
    *(s32 *)((s32)arg0 + 0x238) = sp10[1];
    *(s32 *)((s32)arg0 + 0x23C) = sp10[2];
}
