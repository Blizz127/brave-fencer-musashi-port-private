/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBD54 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015978(s32 a0, s32 *a1);
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_800CBD54;
extern s32  func_80017DC4(void *a0, void *a1);
extern void func_80017DF8(s16 *a0, void *a1);
extern void func_80017E68(void *a0, void *a1);
extern void func_80016EF8(void *a0, void *a1);

void func_800CBD54(s32 param_1, s32 *param_2)
{
    s32 p;
    MTX_800CBD54 mtx;
    s16 buf[4];

    p = *(s32 *)(param_1 + 0x20);
    *(s32 *)((s32)param_2 + 0x34) = 0x50000000;

    func_80017DC4((void *)(p + 0x18), &mtx);
    func_80017DF8((s16 *)(p + 0x10), &mtx);
    func_80015978(param_1 + 4, (s32 *)buf);
    func_80017E68((void *)buf, &mtx);
    func_80016EF8((void *)param_2, &mtx);

    mtx.t[0] += *(s16 *)(param_1 + 0x38);
    mtx.t[1] += *(s16 *)(param_1 + 0x3A);
    mtx.t[2] += *(s16 *)(param_1 + 0x3C);
    func_80016EF8((void *)param_2, &mtx);
    func_80017E68((void *)buf, &mtx);

    mtx.t[0] += *(s16 *)(param_1 + 0x3E);
    mtx.t[1] += *(s16 *)(param_1 + 0x40);
    mtx.t[2] += *(s16 *)(param_1 + 0x42);
    func_80016EF8((void *)param_2, &mtx);
    func_80017E68((void *)buf, &mtx);

    mtx.t[0] += *(s16 *)(param_1 + 0x44);
    mtx.t[1] += *(s16 *)(param_1 + 0x46);
    mtx.t[2] += *(s16 *)(param_1 + 0x48);
    func_80016EF8((void *)param_2, &mtx);
}
