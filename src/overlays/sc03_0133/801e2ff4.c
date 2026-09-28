/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2FF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_80178B18(s32 a0, s32 a1);

void func_801E2FF4(void *a0) {
    extern s32 D_801E904C;
    extern s16 D_801E3154;
    extern s16 D_801E3156;
    extern s16 D_801E3158;
    extern s16 D_801BEBF8;
    extern s32 D_801E3184;
    s32 v0;
    s32 v1;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
    } else {
        func_8001C214(v0, (s32)&D_801E904C);
        v1 = *(s32 *)((s32)a0 + 0x68);
        *(s16 *)((s32)a0 + 0x6) = D_801E3154;
        *(s16 *)((s32)a0 + 0xA) = D_801E3156;
        *(s16 *)((s32)a0 + 0xE) = D_801E3158;
        *(s16 *)(v1 + 0xC) = 0x7FFF;
        *(s16 *)((s32)a0 + 0x2) = 1;
        func_8012A828((s32)a0, (s32)&D_801BEBF8);
        *(s16 *)((s32)a0 + 0x34) = 0;
        func_80178B18((s32)a0, (s32)&D_801E3184);
    }
}
