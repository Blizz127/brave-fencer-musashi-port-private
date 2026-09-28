/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D7E0 - byte-exact against retail at -O2 (tools/register_match.py). */
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_8012C194(void);
extern void func_8001CEC0(s32 a0, s32 a1);
extern void func_8017D878(s32 a0);
extern void (*D_80181D7C[])(void);

void func_8017D7E0(s32 param_1) {
    s32 obj;
    void (*tbl)(void);

    tbl = D_80181D7C[*(s16 *)(param_1 + 0x70)];
    obj = func_8012C194();
    if (obj != 0) {
        *(s32 *)(param_1 + 0x20) = obj;
        func_8001CEC0(obj, (s32)tbl);
        *(u16 *)(obj + 0x2E) = 0;
        *(u16 *)(obj + 0x30) = 0;
        *(u16 *)(obj + 0x2C) = 1;
        func_80015978(param_1 + 4, (s32 *)(param_1 + 0xFC));
        func_8017D878(param_1);
        func_8012AD50((void *)param_1);
    }
}
