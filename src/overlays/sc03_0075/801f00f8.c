/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F00F8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 func_80178B18(s32 a0, s32 a1);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern void func_8012E88C(u8 *a0);
extern s32 D_801F6CAC;
extern s32 D_801F6CA8;
extern s32 D_801F0640[];
extern s32 D_801F0628[][2];
extern s32 D_801F0658[];
extern s32 D_801F070C;

void func_801F00F8(void *a0) {
    s32 v0;
    s32 cur;
    s32 target;

    if ((u32)(func_80029504() - 0x122) >= 0xA) {
        func_8012CAE4(a0);
        return;
    }

    if (*(s16 *)((s32)a0 + 0x70) == 0) {
        D_801F6CAC = func_8012C658(0x1C1, 1, 0);
        D_801F6CA8 = func_8012C658(0x1C1, 2, 0);
    }

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }

    func_8001C214(v0, D_801F0640[*(s16 *)((s32)a0 + 0x70)]);
    *(s16 *)(*(s32 *)((s32)a0 + 0x68) + 0xC) = 0x7FFF;
    func_8012E8E0((s32)a0, (s32)&D_801F0628[*(s16 *)((s32)a0 + 0x70)]);
    *(s16 *)((s32)a0 + 0x2) = 1;
    func_8012E8E0((s32)a0, (s32)&D_801F0628[*(s16 *)((s32)a0 + 0x70)]);
    func_8012E88C((u8 *)a0);

    cur = *(s32 *)((s32)a0 + 0x90);
    target = D_801F0658[*(s16 *)((s32)a0 + 0x70)];
    if (cur != target) {
        func_8012A828((s32)a0, target);
    }

    if (*(s16 *)((s32)a0 + 0x70) != 0) {
        func_80178B18((s32)a0, (s32)&D_801F070C);
    }
}
