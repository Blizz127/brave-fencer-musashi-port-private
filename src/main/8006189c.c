/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_800617CC;
extern s32 D_800617E0;
extern s32 D_800617F4;
extern s32 D_80061808;
extern s32 D_8006181C;
extern s32 D_80061830;
extern s32 D_80061844;
extern s32 D_80061858;

s32 func_8005CE78(s32, s32, s32, void *);                    /* static */
void func_8005CEB8(s32);                               /* static */
s32 func_8005CF08();                                /* static */
void func_8005CF18();                                  /* static */
void func_80061B58();                                  /* static */
extern s32 D_80078C3C;
extern s32 D_80078C40;
extern s32 D_80078C44;
extern s32 D_80078C48;
extern s32 D_80078C4C;
extern s32 D_80078C50;
extern s32 D_80078C54;
extern s32 D_80078C58;

void func_8006189C(void) {
    s32 temp_s0;

    temp_s0 = func_8005CF08();
    D_80078C3C = func_8005CE78(0xF4000001, 4, 0x1000, &D_800617CC);
    D_80078C40 = func_8005CE78(0xF4000001, 0x8000, 0x1000, &D_800617E0);
    D_80078C44 = func_8005CE78(0xF4000001, 0x100, 0x1000, &D_800617F4);
    D_80078C48 = func_8005CE78(0xF4000001, 0x2000, 0x1000, &D_80061808);
    D_80078C4C = func_8005CE78(0xF0000011, 4, 0x1000, &D_8006181C);
    D_80078C50 = func_8005CE78(0xF0000011, 0x8000, 0x1000, &D_80061830);
    D_80078C54 = func_8005CE78(0xF0000011, 0x100, 0x1000, &D_80061844);
    D_80078C58 = func_8005CE78(0xF0000011, 0x2000, 0x1000, &D_80061858);
    func_8005CEB8(D_80078C3C);
    func_8005CEB8(D_80078C40);
    func_8005CEB8(D_80078C44);
    func_8005CEB8(D_80078C48);
    func_8005CEB8(D_80078C4C);
    func_8005CEB8(D_80078C50);
    func_8005CEB8(D_80078C54);
    func_8005CEB8(D_80078C58);
    func_80061B58();
    if (temp_s0 == 1) {
        func_8005CF18();
    }
}

