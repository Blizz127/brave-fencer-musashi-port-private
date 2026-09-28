/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016CF04 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
#define RotMatrixYXZ func_80049A1C
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
extern void ApplyMatrixSV(void *a0, void *a1, void *a2);
extern void RotMatrixYXZ(void *a0, void *a1);
extern void func_800D23D0(void *a0);

short func_8016CF04(s32 param_1, s32 param_2) {
    extern Blk_8016CF04_8016CF04 D_801A0168[];


    Blk_8016CF04_8016CF04 *p = &D_801A0168[*(short *)(((int)param_1) + 0x2a)];
    u16 rot[4];
    u16 out[4];
    s32 mtx[8];

    switch (((short)param_2)) {
    case 0:
        p->f2 = 0;
        p->f1 = 0;
        p->f3 = 0xf0;
        break;
    case 1:
        p->f1 = p->f1 + 1;
        if ((u8)p->f1 >= 0x10)
            p->f1 = 0;
        if ((u8)p->f2 < 0xf)
            p->f2 = p->f2 + 1;
        break;
    case 2: {
        u8 c = p->f2 - 1;
        p->f2 = c;
        if (c == 0) {
            p->f0 = 0;
            return 1;
        }
        p->f3 = p->f3 - 0xf;
        return 0;
    }
    }

    rot[0] = *(s32 *)(((int)param_1) + 0x10) >> 12;
    rot[1] = *(s32 *)(((int)param_1) + 0x14) >> 12;
    rot[2] = *(s32 *)(((int)param_1) + 0x18) >> 12;
    func_800D23D0(rot);
    RotMatrixYXZ(rot, mtx);
    rot[0] = 9;
    rot[1] = 0;
    rot[2] = 0;
    ApplyMatrixSV(mtx, rot, out);
    p->ent[(u8)p->f1].a = *(u16 *)(((int)param_1) + 6)   + out[0];
    p->ent[(u8)p->f1].b = *(u16 *)(((int)param_1) + 0xa) + out[1];
    p->ent[(u8)p->f1].c = *(u16 *)(((int)param_1) + 0xe) + out[2];
    rot[0] = -rot[0];
    rot[1] = -rot[1];
    ApplyMatrixSV(mtx, rot, out);
    p->ent[(u8)p->f1].d = *(u16 *)(((int)param_1) + 6)   + out[0];
    p->ent[(u8)p->f1].e = *(u16 *)(((int)param_1) + 0xa) + out[1];
    p->ent[(u8)p->f1].g = *(u16 *)(((int)param_1) + 0xe) + out[2];
    return 0;
}
