/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D01C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126948[];
extern void func_8012A018(s32 a, s32 b);
extern s32 D_80126954;
extern s32 D_80126950;
extern s32 D_8012695C;
extern s16 D_80126968;
extern s16 D_8012696A;
extern s16 D_8012696C;
extern s16 D_80126976;
extern s16 D_80126978;
extern s16 D_8012697A;

void func_8017D01C(void) {

    extern s32 D_80126954;
    extern s32 D_80126950;
    extern s32 D_8012695C;
    extern s16 D_80126968;
    extern s16 D_8012696A;
    extern s16 D_8012696C;
    extern s16 D_80126976;
    extern s16 D_80126978;
    extern s16 D_8012697A;
    extern u8 D_80126948[];
    extern u16 D_801269E8;
    extern s16 D_801A0C88;
    extern void func_8017D0D4(void *);
    extern void func_8012A018(s32, s32);
    extern void func_8012A094(s32);

    D_80126954 = 0x190;
    D_80126950 = 0x190;
    D_8012695C = 0x3E8;
    D_80126968 = 0xE3;
    D_8012696A = 0;
    D_8012696C = 0;
    D_80126976 = 0;
    D_80126978 = -0x50;
    D_8012697A = 0;
    func_8012A018((s32)func_8017D0D4, 0);
    func_8012A094((s32)D_80126948);
    func_8017D0D4((void *)D_80126948);
    func_8012A094((s32)D_80126948);
    D_801A0C88 = D_801269E8;
}
