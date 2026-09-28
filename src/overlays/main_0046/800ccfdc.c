/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCFDC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_800CD494(void *a0);
extern void func_800CD5CC(void *a0);
extern void func_8016151C(void *a0);
extern s16 D_801152B0;
extern s16 D_801152B4;
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80147F50(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_800CCFDC(void *arg0) {
    s32 ret;

    if (func_800CD240(arg0) != 0) {
        return;
    }
    func_80146DE8((s32 *)arg0, *(s32 *)((s32)arg0 + 0x234), *(s32 *)((s32)arg0 + 0x238), *(s32 *)((s32)arg0 + 0x23C));
    func_80147F50((s32)arg0);
    func_801473EC((s32 *)arg0);
    func_80148038((s32)arg0, 0x1A000);
    func_80147460((s32)arg0);
    if (((s32 (*)(void *))func_800CD494)(arg0) != 0) {
        return;
    }
    func_800CD5CC(arg0);
    ret = ((s32 (*)(void *))func_8016151C)(arg0);
    if (ret & 0x4000) {
        *(s32 *)((s32)arg0 + 0x234) = D_801152B0 << 6;
        *(s32 *)((s32)arg0 + 0x238) = 0x80000;
        *(s32 *)((s32)arg0 + 0x23C) = D_801152B4 << 6;
        *(s16 *)((s32)arg0 + 2) = 3;
    } else if (ret != 0) {
        func_80146E90((s32 *)arg0, 8);
        func_80146CA0(arg0);
    } else {
        *(s32 *)((s32)arg0 + 0x44) |= 0x1000;
    }
}
