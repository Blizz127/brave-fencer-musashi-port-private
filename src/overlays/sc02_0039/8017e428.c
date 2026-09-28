/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E428 - byte-exact against retail at -O2 (tools/register_match.py). */
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_8001C810(s32 a0, s32 a1);
void func_8017DE00();
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8012AD50(void *arg0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8017DE00(s32 a0);
extern s32  func_8012AD50(void *a0);
extern s32 D_8019CA6C;
extern s32 D_8019DEE0;

void func_8017E428(s32 param_1) {
    s32 obj;
    s32 obj2;

     

    obj = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(param_1 + 0x20) = obj;
    if (obj == 0) {
        func_8012CAE4((void *)param_1);
        return;
    }

    func_8001C810(obj, (s32)&D_8019CA6C);
    *(s32 *)(*(s32 *)(param_1 + 0x20) + 4) =
        *(s32 *)(*(s32 *)(param_1 + 0x20) + 4) | 0x8040;
     
    *(s32 *)(*(s32 *)(param_1 + 0x20) + 0x28) = 0x1800180;

    obj2 = ((s32 (*)(void))func_8012C1B8)();
    if (obj2 != 0) {
        func_8001C214(obj2, (s32)&D_8019DEE0);
        *(u16 *)(obj2 + 8)   = *(u16 *)(param_1 + 6);
        *(u16 *)(obj2 + 0xA) = *(u16 *)(param_1 + 0xA) + 0xC0;
        *(u16 *)(obj2 + 0xC) = *(u16 *)(param_1 + 0xE) - 0xB0;
    }

    func_8017DE00(param_1);
    func_8012AD50((void *)param_1);
}
