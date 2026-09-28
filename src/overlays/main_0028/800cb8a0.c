/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB8A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixYXZ func_80049A1C


void func_800CB8A0(void *a0) {
    extern s32 func_80017DC4(void *a0, void *a1);
    extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
    extern void func_800D20C0(void *a0, void *a1, s32 a2);
    extern void func_800D23D0(void *a0);
    extern void func_80017E68(void *a0, void *a1);
    extern void RotMatrixYXZ(void *a0, void *a1);
    extern void func_80048D9C(void *a0, void *a1);
    extern s32 func_80017758(void *a0, void *a1);
    extern u8 D_800CBECC[];

    s16 vecA[4];
    s16 rot[4];
    u8 info[0x38];
    u8 s2vec[0x20];
    s16 mtx[16];
    u16 fld;
    u16 fld2;
    s16 ang;
    u8 *tbl;
    s8 last;
    s16 i;

    fld = *(u16 *)((s32)a0 + 0x28);
    vecA[2] = fld;
    vecA[1] = fld;
    vecA[0] = fld;
    func_80017DC4(vecA, s2vec);

    vecA[2] = 0;
    vecA[0] = 0;
    vecA[1] = -0x2C;
    func_8012F14C((s32)a0 + 0x38, (s32)vecA, (s32)vecA);

    func_800D20C0(vecA, rot, 5);
    func_800D23D0(rot);

    *(s16 *)(info + 0x0C) = 0;
    *(s16 *)(info + 0x0A) = 0;
    *(s16 *)(info + 0x08) = 0;
    *(s16 *)(info + 0x1C) = 0;
    *(s16 *)(info + 0x14) = 0;
    *(s16 *)(info + 0x04) = 0;

    fld2 = *(u16 *)((s32)a0 + 0x28);

    *(u8 *)(info + 0x26) = 0;
    *(u8 *)(info + 0x22) = 0;
    *(u8 *)(info + 0x21) = 0;
    *(u8 *)(info + 0x20) = 0;
    *(u8 *)(info + 0x2A) = 0;
    *(u8 *)(info + 0x29) = 0;
    *(u8 *)(info + 0x28) = 0;
    *(u8 *)(info + 0x2E) = 0;
    *(u8 *)(info + 0x2D) = 0;
    *(u8 *)(info + 0x2C) = 0;
    *(u32 *)(info + 0x30) = 0x50000000;

    ang = (s16)fld2 >> 6;
    ang = ang + 0x60;
    *(s8 *)(info + 0x25) = (s8)ang;
    *(s8 *)(info + 0x24) = (s8)ang;
    func_80017E68(vecA, s2vec);

    RotMatrixYXZ(rot, mtx);
    func_80048D9C(s2vec, mtx);

    tbl = D_800CBECC;
    for (i = 0; i < 4; i++) {
        *(s16 *)(info + 0x00) = (s8)*tbl; tbl++;
        *(s16 *)(info + 0x02) = (s8)*tbl; tbl++;
        *(s16 *)(info + 0x10) = (s8)*tbl; tbl++;
        *(s16 *)(info + 0x12) = (s8)*tbl; tbl++;
        *(s16 *)(info + 0x18) = (s8)*tbl; tbl++;
        last = (s8)*tbl; tbl--;
        *(s16 *)(info + 0x1A) = last;
        func_80017758(info, s2vec);
    }
}
