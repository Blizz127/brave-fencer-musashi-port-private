/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E148 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s16 D_8018B074[];
extern void (*D_80181DBC[])(void);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012CAE4(void *a0);
extern s32 func_8012C1B8(void);
extern void func_8001C214(s32 a0, s32 a1);
extern void (*D_8018D924[])(void);

void func_8017E148(s32 param) {
    s32 x;

    x = func_80029504();
    if ((u32)(x - 0xE6) >= 10) {
        func_8012CAE4((void *)param);
        return;
    }
    *(s32 *)(param + 0x20) = func_8012C1B8();
    if (*(s32 *)(param + 0x20) == 0) {
        func_8012CAE4((void *)param);
    }
    func_8001C214(*(s32 *)(param + 0x20), (s32)D_8018D924);
    *(u16 *)(param + 0x2) = 1;
    func_8012E8E0(param, (s32)D_80181DBC);
    func_8012A828(param, (void *)D_8018B074);
    *(u16 *)(*(s32 *)(param + 0x68) + 0xC) = 0x7FFF;
}
