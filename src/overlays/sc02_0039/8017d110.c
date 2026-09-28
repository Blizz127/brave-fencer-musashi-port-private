/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D110 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    s16 v[4];
} Blk8_80126940;
extern s32 D_80126B58;
extern s32 *D_80126B78;
extern u16 func_80148800(s32 *a0);
extern s32 func_80012DBC(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern Blk8_80126940 D_80126940;
extern s16 D_80182BC4[];
extern u8 D_80182B7C;
extern s16 D_801A0C88;
extern void func_8017D2B8(s32 param_1, s32 param_2, s16 *param_3);
extern s32 func_8017D484(u8 *param_1, s16 *param_2, s16 *param_3);

void func_8017D110(s32 param_1)
{
    Blk8_80126940 sp10;
    Blk8_80126940 sp18;
    u8 t;
    s32 r;
    s32 sh;

    if (func_80148800(&D_80126B58) & 3) {
        t = (*(u8 *)(param_1 + 5) + 1) & 1;
        *(u8 *)(param_1 + 5) = t;
        *(s32 *)(param_1 + 0x14) = D_80182BC4[t];
    }
    sp10 = D_80126940;

    r = func_8004787C(((s16 *)D_80126B78)[9]);
    if (r < 0) {
        r += 0x7F;
    }
    sp18.v[0] = sp10.v[0] - (r >> 7);

    r = func_80047948(((s16 *)D_80126B78)[9]);
    if (r < 0) {
        r += 0x7F;
    }
    sh = r >> 7;
    sp18.v[2] = sp10.v[2] - sh;
    sp18.v[1] = sp10.v[1];

    *(s16 *)(param_1 + 0xA0) = func_8017D484(&D_80182B7C, sp10.v, sp18.v);

    if (sp10.v[1] > 0) {
        sp10.v[1] = 0;
    }
    if (sp10.v[2] >= -0x7F) {
        sp10.v[2] = -0x80;
    }
    if (*(s16 *)(param_1 + 0xA0) >= 0xB81) {
        *(s16 *)(param_1 + 0xA0) = 0xB80;
    }
    if (*(s16 *)(param_1 + 0xA0) < 0x480) {
        *(s16 *)(param_1 + 0xA0) = 0x480;
    }
    D_801A0C88 = func_80012DBC(D_801A0C88, *(s16 *)(param_1 + 0xA0), 4, 1);
    func_8017D2B8(param_1, D_801A0C88, sp10.v);
}
