/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D9E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_80015978(s32 a0, s32 *a1);
extern s32 rand(void);
extern int rand(void);
extern s32 func_8012BEE8(s32 a0);
extern u8 *func_801290DC(s32 a0, u8 *a1);
extern void func_8012BF4C(s32 *a0, s32 a1);

void func_8017D9E4(s32 param_1) {
    u16 delta[4];
    register s32 t __asm__("$3");
    s32 t2;
    s16 d;
    s32 obj;

    if (func_8012BEE8(param_1) == 0) {
        return;
    }
    func_80015978(param_1 + 4, (s32 *)delta);
    if (*(s32 *)(param_1 + 0xDC) != 0) {
        t = rand() % 352;
        d = t;
        if (t & 1) {
            d = -t;
        }
        delta[0] += d;
        t2 = rand();
        t2 = t2 % 256;
        d = t2;
        if (t2 & 1) {
            d = -t2;
        }
        delta[2] += d;
    }
    obj = (s32)func_801290DC(0x27, (u8 *)delta);
    if (obj == 0) {
        return;
    }
    func_8012BF4C((s32 *)param_1, (rand() & 0x7F) + 0x60);
    *(u16 *)(obj + 0x2E) = *(u16 *)(param_1 + 0xFC);
}
