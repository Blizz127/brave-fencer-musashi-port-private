/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017C294 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
#define PopMatrix func_8004871C
#define PushMatrix func_8004867C
#define ReadRotMatrix func_800487BC
extern void ApplyMatrixSV(void *a0, void *a1, void *a2);
extern void ReadRotMatrix(void *a0);
extern void PushMatrix(void);
extern void func_8004974C(void *a0, void *a1);
extern void PopMatrix(void);

void func_8017C294(u16 *a0, void *a1) {
    s32 mat[8];
    s32 buf[8];
    s16 sv[4];
    ReadRotMatrix((void *)mat);
    PushMatrix();
    sv[0] = (s16)(a0[0] - *(s32 *)((u8 *)mat + 0x14));
    sv[1] = (s16)(a0[1] - *(s32 *)((u8 *)mat + 0x18));
    sv[2] = (s16)(a0[2] - *(s32 *)((u8 *)mat + 0x1C));
    func_8004974C((void *)mat, (void *)buf);
    ApplyMatrixSV((void *)buf, (void *)sv, a1);
    PopMatrix();
}
