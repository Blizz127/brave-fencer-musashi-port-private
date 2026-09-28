/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCEEC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_800CD494(void *a0);
extern void func_800CD5CC(void *a0);
extern void func_8016151C(void *a0);

void func_800CCEEC(void *arg0) {
    s32 v1;
    s32 v0;

    if (func_800CD240() != 0) {
        return;
    }
    func_800CD288(arg0);
    if (((s32 (*)(void *))func_800CD494)(arg0) != 0) {
        return;
    }
    func_80148038((s32)arg0, 0x1A000);
    func_80147460((s32)arg0);
    v0 = ((s32 (*)(void *))func_800CD5CC)(arg0);
    if (v0 != 0) {
        func_800CD6A4(arg0, v0);
    }
    v1 = ((s32 (*)(void *))func_8016151C)(arg0);
    if ((v1 & 0x4000) != 0) {
        func_800CCFA8(arg0);
        return;
    }
    if (v1 != 0) {
        *(s16 *)((s32)arg0 + 2) = 1;
        return;
    }
    *(s32 *)((s32)arg0 + 0x44) |= 0x1000;
}
