/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD0DC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_800CD494(void *a0);
extern void func_800CD5CC(void *a0);
extern s16 D_801152B0;
extern s16 D_801152B4;
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80147F50(s32 a0);
extern void func_801473EC(s32 *a0);
extern s32 func_801612B8(void *a0, s32 a1);
extern s32 func_80146E98(s32 a0);

void func_800CD0DC(void *arg0) {
    s32 ret;

    if (func_800CD240() != 0) {
        return;
    }
    func_80146DE8((s32 *)arg0, *(s32 *)((s32)arg0 + 0x234), *(s32 *)((s32)arg0 + 0x238), *(s32 *)((s32)arg0 + 0x23C));
    func_80147F50((s32)arg0);
    func_801473EC((s32 *)arg0);
    if (((s32 (*)(void *))func_800CD494)(arg0) != 0) {
        return;
    }
    func_800CD5CC(arg0);
    ret = func_801612B8(arg0, 0);
    if (func_80146E98((s32)arg0) != 0) {
        if (ret & 0x4000) {
            *(s32 *)((s32)arg0 + 0x234) = D_801152B0 << 6;
            *(s32 *)((s32)arg0 + 0x238) = 0x80000;
            *(s32 *)((s32)arg0 + 0x23C) = D_801152B4 << 6;
            *(s16 *)((s32)arg0 + 2) = 3;
        } else if (ret == 0 || ret == 0x8000) {
            func_801477E8((s32 *)arg0, 0xFFEA0000);
            *(s16 *)((s32)arg0 + 2) = 2;
        } else {
            *(s32 *)((s32)arg0 + 0x23C) = 0;
            *(s32 *)((s32)arg0 + 0x238) = 0;
            *(s32 *)((s32)arg0 + 0x234) = 0;
            *(s16 *)((s32)arg0 + 2) = 1;
        }
    } else {
        *(s32 *)((s32)arg0 + 0x44) |= 0x1000;
    }
}
