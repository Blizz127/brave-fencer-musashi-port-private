/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2ED8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801E3004[];
extern s32 func_80183EE4(void *a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 D_801BF330;
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 D_801E2FFC;
extern s32 func_80178B18(s32 a0, s32 a1);
extern void *D_801E3084;

void func_801E2ED8(void *param_1) {
    if (func_80183EE4(param_1, D_801E3004) != 0) {
        *(s16 *)((s32)param_1 + 0x2) = 1;
        func_8012A828((s32)param_1, &D_801BF330);
        func_8012E8E0((s32)param_1, (s32)&D_801E2FFC);
        *(u16 *)((s32)param_1 + 0x34) = 0;
        func_80178B18((s32)param_1, (s32)&D_801E3084);
    }
}
