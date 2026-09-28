/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801347A0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
      s16 f0;
      s16 f2;
      s16 f4;
      s16 f6;
} Elem_801347A0;
typedef struct {
      u16 f0;
      s16 f2;
      s16 f4;
      s16 f6;
      s16 f8;
      s16 fa;
      s16 fc;
      s16 fe;
      s16 f10;
      s16 f12;
      s16 f14;
} S0_801347A0;
typedef struct {
      u16 f0;
      u16 f2;
      u16 f4;
      u16 f6;
} SVec_801347A0;
extern u8 D_801152A8[];

s32 func_801347A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 func_80134A28(s32 a0, s32 a1, s32 a2);
    extern s16 * D_8017E7D8;
    extern SVec_801347A0 * D_8017E7D4;
    extern SVec_801347A0 * D_8017E7DC;

    Elem_801347A0 *pElem;
    s32 val;
    register s32 iv __asm__("$4");
    s32 q;
    s32 dvsr;

    pElem = &((Elem_801347A0 *)arg2)[((S0_801347A0 *)arg1)->f2];
    val = ((s32 *)arg3)[((S0_801347A0 *)arg1)->f4];
    if (func_80134A28((s32)pElem, (s32)D_8017E7D8, val) >= 0) {
        return 0;
    }
    iv = func_80134A28((s32)pElem, (s32)D_8017E7D4, val);
    if (iv < 0) {
        return 0;
    }
    iv = -iv;
    dvsr = pElem->f2 * 48;
    q = (iv * 48) / dvsr;
    D_8017E7DC->f0 = D_8017E7D4->f0;
    D_8017E7DC->f2 = D_8017E7D4->f2 + q;
    D_8017E7DC->f4 = D_8017E7D4->f4;
    if (func_80134A28((s32)&((Elem_801347A0 *)arg2)[((S0_801347A0 *)arg1)->f6], (s32)D_8017E7DC, ((s32 *)arg3)[((S0_801347A0 *)arg1)->f8]) < -0x2F00) {
        return 0;
    }
    if (func_80134A28((s32)&((Elem_801347A0 *)arg2)[((S0_801347A0 *)arg1)->fa], (s32)D_8017E7DC, ((s32 *)arg3)[((S0_801347A0 *)arg1)->fc]) < -0x2F00) {
        return 0;
    }
    if (func_80134A28((s32)&((Elem_801347A0 *)arg2)[((S0_801347A0 *)arg1)->fe], (s32)D_8017E7DC, ((s32 *)arg3)[((S0_801347A0 *)arg1)->f10]) < -0x2F00) {
        return 0;
    }
    if ((s16)arg0) {
        if (func_80134A28((s32)&((Elem_801347A0 *)arg2)[((S0_801347A0 *)arg1)->f12], (s32)D_8017E7DC, ((s32 *)arg3)[((S0_801347A0 *)arg1)->f14]) < -0x2F00) {
            return 0;
        }
    }
    if ((((S0_801347A0 *)arg1)->f0 & 0x300) != 0) {
        return 0;
    }
    D_8017E7DC->f0 = D_8017E7D4->f0;
    D_8017E7DC->f4 = D_8017E7D4->f4;
    (*(Elem_801347A0*)D_801152A8) = *pElem;
    D_8017E7D4->f6 = pElem->f2;
    return 1;
}
