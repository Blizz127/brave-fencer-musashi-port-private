/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013A250 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8013A250;
struct S8013A250 {
    u8 pad8[8];
    s32 unk8;       
    u8 unkC;        
};
extern void func_80138B88(s32 a0);
extern void func_80139B18(s32 a0);
void func_80138B88(s32 a0);
void func_80139A8C(s32 a0);
void func_80139B18(s32 a0);
extern void func_80139A8C(s32 a0);

void func_8013A250(struct S8013A250 *a0) {
    if (a0->unkC != 0) {
        a0->unkC = a0->unkC - 1;
        func_80139A8C((s32)a0);
        if ((a0->unk8 & 0x80020) == 0) {
            func_80139B18((s32)a0);
            return;
        }
    }
    func_80138B88((s32)a0);
}
