/* Overlay range [80135A4C,80135D20) from MAIN.CD member 0012.
 * SHA256(span)=c4b1d0488f17b92007aad33f82e4990e13d85d7916d43b2f885345405361ea17.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80135A4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { u8 b[8]; } Blk8;
typedef struct { u16 f0, f2, f4; s16 f6; } Box;
typedef struct { s16 x, y, z; } V3;

s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3) {
    typedef struct { s8 c[8]; } Blk8;
    extern s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4);
    extern s32 func_80135EB0(void *arg0, s32 arg1_);
    extern s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3);
    extern s32 func_80133AB0(s16, s16, s16, s32);
    extern u8 D_8017E910;
    extern u8 D_8017E914;
    extern s16 *D_8017E918;
    extern s16 D_8018412C;
    extern u16 D_80184130;
    extern s32 D_80184134;
    extern s32 D_80184154;
    extern u8 D_801152A8[];
    extern u8 D_801152B0;

    s32 *p;
    register s32 s7 __asm__("$23");
    s32 flag;
    s32 acc;
    s16 i;
    s32 eq;
    s32 ret;
    s32 frame_pad[8];
    (void)&frame_pad;

    switch (((s32 (*)(void))func_80135480)()) {
    case 0:
        return 0;
    case 1:
        s7 = a0 + 0x34;
        p = (s32 *)((a1 & 0xFFFFFFF) | 0x80000000);
        flag = 0;
        break;
    case 2:
        s7 = a0 + 0x34;
        p = (s32 *)((a1 & 0xFFFFFFF) | 0x80000000);
        flag = 1;
        break;
    case 3:
        s7 = a0 + 0x34;
        p = (s32 *)&D_80184154;
        flag = 0;
        break;
    case 4:
        s7 = (s32)&D_80184134;
        p = (s32 *)&D_80184154;
        flag = 1;
        break;
    }

    acc = 0;
    if (a1 < 0) {
        if (func_80135EB0(p, -0x8000) == 0) {
            p = (s32 *)*p;
            if (p == 0) return 0;
        loop:
            if (func_80135EB0(p, -0x8000) == 0) goto next;
        }
    docall:
        func_80136A94(flag, a0, a3, s7);
        return 1;
    next:
        p = (s32 *)*p;
        __asm__ __volatile__("");
        if (p != 0) goto loop;
        return 0;
    }

    i = 0;
    *(s16 *)((*(u8 **)&D_8017E910) + 6) = -0x7FFF;
    *(s16 *)((*(u8 **)&D_8017E914) + 6) = 0x7FFF;
    D_80184130 = 0;
    D_8018412C = 0;
    {
        s32 t = 0;
        if (((V3 *)a2)->x == ((V3 *)a3)->x && ((V3 *)a2)->y == ((V3 *)a3)->y) {
            s32 zt = (((V3 *)a2)->z == ((V3 *)a3)->z);
            __asm__("addu %0,%1,$zero" : "=r"(t) : "r"(zt));
        }
        eq = t;
    }

    while (1) {
        ret = func_80133AB0(0, (s16)(*(Box **)&D_8017E910)->f0, (s16)(*(Box **)&D_8017E910)->f4, (s32)p);
        if (ret == 0) goto out;
        acc |= ret;
        if (eq != 0) goto out;
        {
            s16 old = i;
            i = i + 1;
            if (old >= 5) return 0;
        }
    }

out:
    if ((s16)acc != 0 || D_8018412C != 0) {
        if ((*(Box **)&D_8017E910)->f6 >= -0xBCB) {
            *(Blk8 *)D_801152A8 = *(Blk8 *)&D_801152B0;
        }
        (*(Box **)&D_8017E918)->f0 = (*(Box **)&D_8017E914)->f0;
        (*(Box **)&D_8017E918)->f2 = (*(Box **)&D_8017E914)->f2;
        (*(Box **)&D_8017E918)->f4 = (*(Box **)&D_8017E914)->f4;
        goto docall;
    }
    return 0;
}
