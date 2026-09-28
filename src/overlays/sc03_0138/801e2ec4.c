/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2EC4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 func_80178B18(s32 a0, s32 a1);
extern s32 func_80029178(s32 arg);
extern s32 func_80029504(void);

void func_801E2EC4(s32 a0) {
    extern s32 D_801E33A4;
    extern s32 D_801E33DC;
    extern s32 D_801E33F4;
    extern s32 D_801E342C;
    s32 v0;
    s32 ptr;
    s32 flag;

    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    func_8001C214(v0, 0);
    ptr = *(s32 *)(a0 + 0x68);
    *(s16 *)(ptr + 0xC) = 0x7FFF;
    flag = 1;
    *(s16 *)(a0 + 0x2) = flag;
    func_8012E8E0(a0, (s32)&D_801E33A4);
    if (func_80029504() < 0x140) {
        *(s16 *)(a0 + 0x34) = 0;
        func_80178B18(a0, (s32)&D_801E33DC);
    } else {
        if ((func_80029178(0xFF) & 0xFF) != 0) {
            *(s16 *)(a0 + 0x34) = flag;
            func_80178B18(a0, (s32)&D_801E342C);
        } else {
            *(s16 *)(a0 + 0x34) = flag;
            func_80178B18(a0, (s32)&D_801E33F4);
        }
    }
}
