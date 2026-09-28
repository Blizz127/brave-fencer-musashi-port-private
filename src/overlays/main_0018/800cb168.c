/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB168 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_80146C3C(void);

void func_800CB168(void *arg0) {
    extern u8 D_80078EC1;
    extern s32 rand(void);
    extern s32 func_80146AB4(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6);
    extern void func_80146C3C();
    extern void func_8002D4C8(s32 a0, s32 a1);
    extern u16 D_80126BC8;
    extern u16 D_80126BCA;
    extern u16 D_80126BCC;
    extern u16 D_800B99DA;

    u32 *obj = (u32 *)arg0;
    s16 *pb;
    s32 state;
    s32 r;
    s32 ret;
    u16 v2a;

    if (D_80078EC1 == 3) {
        state = *(s32 *)(obj + 12);
        if (state == 1) {
            goto L1DC;
        }
        if (state == 0) {
            goto L1B0;
        }
        if (state == 2) {
            goto L270;
        }
        goto L288;

L1B0:
        r = rand();
        *(u16 *)((s32)obj + 0x1A) = r & 0xFFF;
        *(u16 *)((s32)obj + 0x2A) = (r & 1) + 2;
        *(s32 *)(obj + 12) = *(s32 *)(obj + 12) + 1;
        goto L288;

L1DC:
        if ((*(s32 *)(obj + 7))++ & 3) {
            goto L288;
        }
        ret = func_80146AB4(0x23, (s32)arg0, 0, 0, 0,
                            *(s16 *)((s32)obj + 0x12),
                            *(s16 *)((s32)obj + 0x1A) |
                                (((*(u16 *)((s32)obj + 0x28))++ & 7) << 16));
        if (ret == 0) {
            *(u16 *)((s32)obj + 0x2A) = 0;
        }
        v2a = *(u16 *)((s32)obj + 0x2A) - 1;
        *(u16 *)((s32)obj + 0x2A) = v2a;
        if ((s16)v2a > 0) {
            goto L288;
        }
        *(s32 *)(obj + 7) = 0x10;
        *(s32 *)(obj + 12) = *(s32 *)(obj + 12) + 1;
        goto L288;

L270:
        if (--*(s32 *)(obj + 7) == 0) {
            *(s32 *)(obj + 12) = 0;
        }

L288:
        pb = (s16 *)&D_80126BCC;
        if (*pb >= 0x1001) {
            D_80126BC8 = *pb = *pb - 0xE0;
            D_80126BCA = D_80126BCA + 0x38;
        }
        if ((D_800B99DA & 0xF) == 0) {
            func_8002D4C8(0x5FB, 0);
        }
    } else {
        D_80126BC8 = D_80126BCA = D_80126BCC = 0x1000;
        ((void (*)(s32))func_80146C3C)((s32)arg0);
    }
}
