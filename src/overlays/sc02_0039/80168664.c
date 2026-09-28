/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80168664 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixX func_80049F3C
typedef struct { s32 w[8]; } Blk20;
extern void func_80048EAC(void *a0, void *a1);
s32 func_801670E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_801670E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern Blk20 D_800AE620;
extern s32  RotMatrixX(s32 a0, void *a1);

void func_80168664(void *arg0) {
    s32 iVar3;
    void *blk;
    iVar3 = *(s32 *)((u8 *)arg0 + 0x34);
    *(s32 *)((u8 *)arg0 + 0x1c) = 0x20;
    *(s16 *)((u8 *)arg0 + 0x10) = 0x80;
    *(s16 *)((u8 *)arg0 + 0x12) = 0;
    *(s32 *)((u8 *)arg0 + 0x30) = 0x1800;
    *(Blk20 *)((u8 *)arg0 + 0x38) = D_800AE620;
    blk = (u8 *)arg0 + 0x38;
    RotMatrixX(0x400, blk);
    func_80048EAC((void *)(*(s32 *)((u8 *)iVar3 + 0x20) + 0x34), blk);
    func_801670E4((s32)arg0, -6, -0x44, -0x18);
    *(s16 *)((u8 *)arg0 + 2) = *(s16 *)((u8 *)arg0 + 2) + 1;
}
