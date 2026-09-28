/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF94 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixYXZ func_80049A1C


void func_800CAF94(s32 arg0) {

    extern u8   D_80078EC1;
    extern u16  D_800B99DA;
    extern void func_80146C3C();
    extern s32  func_80017DC4(void *a0, void *a1);
    extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
    extern void func_800D20C0(void *a0, void *a1, s32 a2);
    extern void func_800D23D0(void *a0);
    extern void RotMatrixYXZ(void *a0, void *a1);
    extern void func_80048D9C(void *a0, void *a1);

    s16 sv[4];
    s16 rot[4];
    s16 mtx[16];
    s32 node;
    s32 ent;
    s32 v;
    s16 t;

    node = *(s32 *)(arg0 + 0x20);
    if (D_80078EC1 == 2) {
        t = *(u16 *)(node + 0x1A) + 0xC0;
        *(s16 *)(node + 0x1A) = t;
        *(s16 *)(node + 0x18) = t;
        ent = *(s32 *)(arg0 + 0x34);
        sv[2] = 0x1000;
        sv[1] = 0x1000;
        sv[0] = 0x1000;
        func_80017DC4(sv, (void *)(arg0 + 0x38));
        sv[2] = 0;
        sv[0] = 0;
        sv[1] = -0x2C;
        func_8012F14C(*(s32 *)(ent + 0x20) + 0x34, (s32)sv, (s32)sv);
        { void *q0 = sv; void *q1 = rot;
          func_800D20C0(q0, q1, 5);
          __asm__ __volatile__("" : "=r"(q1)); }
        *(s16 *)(arg0 + 6)   = *(u16 *)&sv[0];
        *(s16 *)(arg0 + 0xA) = *(u16 *)&sv[1];
        *(s16 *)(arg0 + 0xE) = *(u16 *)&sv[2];
        { void *q2 = rot;
          func_800D23D0(q2);
          __asm__ __volatile__("" : "=r"(q2)); }
        { void *m1 = mtx;
          rot[2] = (D_800B99DA & 0x1F) << 7;
          RotMatrixYXZ(rot, m1);
          __asm__ __volatile__("" : "=r"(m1)); }
        func_80048D9C((void *)(arg0 + 0x38), mtx);

        v = *(s32 *)(arg0 + 0x1C) - 1;
        *(s32 *)(arg0 + 0x1C) = v;
        if (v == -1) {
            *(s16 *)(arg0 + 2) = *(u16 *)(arg0 + 2) + 1;
        }
        return;
    }
    func_80146C3C(arg0);
}
