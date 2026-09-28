/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80135888 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80134A74(int param_1, s16 param_2, s16 param_3, int param_4);
extern u8 D_8017E270;
extern u8 D_8017E26C;
extern u8 D_8017E278;
extern int func_80134A74(int, s16, s16, int);
extern s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4);
extern s16 func_80135480(void*, s32, s16*, s16*);
extern s32 func_80135EB0(void *arg0, s32 arg1_);
extern s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 D_80194F9C;
extern s32 D_80194FBC;

s32 func_80135888(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad_[8];
    register s32 m __asm__("$2");
    s32 sp;
    register s32 p1   __asm__("$17");
    register s32 mode __asm__("$18");
    register s32 p0   __asm__("$19");
    register s32 base __asm__("$20");
    register s32 p3   __asm__("$21");

    p0 = arg0;
    p1 = arg1;
    p3 = arg3;

    switch (((s32 (*)(void *, s32, s16 *, s16 *))func_80135480)((void *)arg0, arg1, (s16 *)arg2, (s16 *)arg3)) {
    case 0:
        return 0;
    case 1:
        base = p0 + 0x34;
        m = p1 & 0xFFFFFFF;
        sp = m | 0x80000000;
        mode = 0;
        break;
    case 2:
        base = p0 + 0x34;
        m = p1 & 0xFFFFFFF;
        sp = m | 0x80000000;
        mode = 1;
        break;
    case 3:
        base = p0 + 0x34;
        sp = (s32)&D_80194FBC;
        mode = 0;
        break;
    case 4:
        base = (s32)&D_80194F9C;
        sp = (s32)&D_80194FBC;
        mode = 1;
        break;
    }

    if (p1 < 0) {
        if (func_80135EB0(sp, 0) != 0) {
            func_80136A94(mode, p0, p3, base);
            return 1;
        }
        sp = *(s32 *)sp;
        __asm__ __volatile__("");
        while (sp != 0) {
            if (func_80135EB0(sp, 0) != 0) {
hit:
                func_80136A94(mode, p0, p3, base);
                return 1;
            }
            sp = *(s32 *)sp;
        }
        return 0;
    }
    {
        u16 *pb = (*(u16 * *)&D_8017E270);
        u16 *pa = (*(u16 * *)&D_8017E26C);
        s16 *pc = (*(s16 * *)&D_8017E278);
        pc[0] = pb[0] - pa[0];
        pc[1] = pb[1] - pa[1];
        pc[2] = pb[2] - pa[2];
        if (func_80134A74(0, (s16)pa[0], (s16)pa[2], sp) == 0) {
            return 0;
        }
    }
    goto hit;
}
