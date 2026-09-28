/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CE004 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80146C3C(void *a0);
extern s32 func_80169A4C(s32 a0, s32 a1);
extern void func_800D22E4(s32 a0);
extern s32 func_80135168(u16 a0, u16 *a1, u16 *a2);

void func_800CE004(s32 param_1)
{
    u16 sp20[4];
    u16 sp28[4];
    s32 *p;
    s32 *q;

    *(s32 *)(param_1 + 0x30) = *(s32 *)(param_1 + 0x1C) * 8;
    func_80169A4C(param_1, param_1 + 0x38);
    if (--*(s32 *)(param_1 + 0x1C) == 0)
        goto L_c3c;
    p = (s32 *)(param_1 + 4);
    func_80015978((s32)p, (s32 *)sp20);
    func_800D22E4(param_1);
    q = (s32 *)sp28;
    func_80015978((s32)p, q);
    if ((s16)func_80135168(1, sp20, sp28) == 0)
        goto L_ret0;
    func_80015954((s32)q, (s32)p);
    if (*(u8 *)((s32)q + 6) != 2)
        goto L_cnt;
    if (*(u32 *)(param_1 + 0x2C) < 0x1E01)
        goto L_c3c;
    func_80146A6C(0x11, (void *)param_1, *(s16 *)(param_1 + 6),
                  (s16)(*(u16 *)(param_1 + 0xA) - 8),
                  *(s16 *)(param_1 + 0xE), 0, 0);
    goto L_c3c;

L_cnt:
    *(u16 *)(param_1 + 2) += 1;
    return;
L_ret0:
    *(s32 *)(param_1 + 0x14) += 0x10000;
    return;
L_c3c:
    func_80146C3C((void *)param_1);
}
