/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016380C - byte-exact against retail at -O2 (tools/register_match.py). */
struct M8;
struct S8016380C;
struct M8 { u8 b[8]; };
struct S8016380C {
    u8 _pad[0x44];
    struct M8 m;
};
typedef struct { char _b[8]; } M8;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015954(s32 a0, s32 a1);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern void func_80015954(s32, s32);

s32 func_8016380C(struct S8016380C *a0, s32 a1) {
    struct M8 local;
    s32 ret;
    local = a0->m;
    func_80015978((s32)((u8 *)a0 + 4), (s32 *)a1);
    ret = func_80133784(1, &local, a1);
    if (ret != 0) {
        func_80015954(a1, (s32)((u8 *)a0 + 4));
        return ret;
    }
    return 0;
}
