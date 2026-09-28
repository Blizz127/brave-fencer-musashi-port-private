/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80140608 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80019064(void *);
extern u8 D_80115148[];
extern u16 D_8011511E;
extern u8 D_80062BDC;
extern s32 func_80028D58(void);
extern void func_80028D78(s32 a0);
extern void func_80019064(void *a0);
extern s32 func_80028DE0(void);
extern void func_80028E00(s32 a0);
extern s32 func_80028FBC(void);
extern void func_80028FDC(s32 a0);
extern s32 func_80029000(void);
extern void func_80029020(s32 a0);
extern s32 func_80028D9C(void);
extern void func_80028DBC(s32 a0);

s32 func_80140608(s32 a0) {
    s16 t;
    register s32 iVar2 __asm__("$2");
    register s32 zr __asm__("$0");
    s32 uVar3;
    u32 uVar4;
    s32 uVar5 = 1;

    switch (D_80115148[(s16)a0 * 2]) {
    case 0:
        t = func_80028D58() ^ 1;
        func_80028D78(t);
        if (t != 0) {
            return uVar5;
        }
        func_80019064(&D_80062BDC);
        return uVar5;
    case 1:
        func_80028E00((s16)(func_80028DE0() ^ 1));
        return uVar5;
    case 2:
        iVar2 = func_80028FBC();
        if (D_8011511E & 0x8000) {
            iVar2 = iVar2 - 1;
            uVar4 = iVar2 + zr;
            if ((s16)iVar2 < 0) {
                uVar4 = 0;
                uVar5 = 0;
            }
        } else {
            iVar2 = iVar2 + 1;
            uVar4 = iVar2 + zr;
            if ((s16)iVar2 >= 8) {
                uVar4 = 7;
                uVar5 = 0;
            }
        }
        func_80028FDC((s16)uVar4);
        func_8002D4C8(0x21, uVar4 & 0xFFFF);
        goto ret;
    case 3:
        iVar2 = func_80029000();
        if (D_8011511E & 0x8000) {
            iVar2 = iVar2 - 1;
            uVar4 = iVar2 + zr;
            if ((s16)iVar2 < 0) {
                uVar4 = 0;
                uVar5 = 0;
            }
        } else {
            iVar2 = iVar2 + 1;
            uVar4 = iVar2 + zr;
            if ((s16)iVar2 >= 8) {
                uVar4 = 7;
                uVar5 = 0;
            }
        }
        func_80029020((s16)uVar4);
        func_8002D4C8(0x22, uVar4 & 0xFFFF);
        goto ret;
    case 4:
        t = func_80028D9C() ^ 1;
        func_80028DBC(t);
        uVar3 = 0xB;
        if (t == 0) {
            uVar3 = 0xC;
        }
        func_8002D4C8(uVar3, 0);
        goto ret;
    default:
        goto ret;
    }
ret:
    return uVar5;
}
