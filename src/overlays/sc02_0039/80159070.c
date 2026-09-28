/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80159070 - byte-exact against retail at -O2 (tools/register_match.py). */
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_80146CA0(void *a0);
extern void func_80139914(s32 a0);
extern s32 func_8013767C(s32 a0);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_801399F0(s32 a0);
extern u8 D_80110C94[];
extern u8 D_80110CD4[];

void func_80159070(void *a0) {
    s32 obj;
    s32 r;
    s32 v;
    u8 *tbl;
    obj = *(s32 *)((u8 *)a0 + 0x20);
    *(u16 *)(obj + 0x12) = (*(u16 *)(obj + 0x12) + 0x16) & 0xFFF;
    r = func_801399F0(*(s32 *)((u8 *)a0 + 0x198));
    *(s16 *)((u8 *)a0 + 0x244) = r;
    if ((s16)r != 0) {
        func_80139914(*(s32 *)((u8 *)a0 + 0x198));
        v = *(s16 *)((u8 *)a0 + 0x244);
        *(s32 *)((u8 *)a0 + 0x198) = 0;
        switch (v) {
        default:
        case 1:
            tbl = D_80110C94;
            break;
        case 2:
            tbl = D_80110CD4;
            break;
        }
        *(s32 *)((u8 *)a0 + 0x198) = func_8013767C((s32)tbl);
        func_80146CA0(a0);
    }
}
