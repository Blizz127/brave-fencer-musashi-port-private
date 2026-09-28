/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6FD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_8019FF8A;
extern u16 D_800B99DA;
extern u8 D_801F88A8[];
extern u8 D_801F88B0[];
extern u8 D_801F8747[];
extern void func_801A5C44(void);
extern void func_801A5B5C(void *a0);
extern void func_801A5AC0(void *a0);
extern void func_801A5D68(void *a0);
extern void func_801A5CE8(void *a0);
extern void func_801A6428(void *a0);
extern s32 func_8017D7D4(void *a0, void *a1, void *a2, s32 a3);

void func_801A6FD4(void *arg0) {
    void *s1;
    s32 v0;

    s1 = *(void **)((u8 *)arg0 + 0xCC);
    func_801A5C44();
    func_801A5B5C(arg0);

    if ((D_8019FF8A & 4) && *(s16 *)((u8 *)arg0 + 0xFE) == 0xB) {
        func_801A5AC0(arg0);
        func_801A5D68(arg0);
        func_801A5CE8(arg0);
        D_801F8747[0] = 1;
        v0 = func_8017D7D4(D_801F88A8, D_801F88B0, D_801F8747 - 3, 6);
        *(s32 *)((u8 *)arg0 + 0xD0) = v0;
    } else if ((D_8019FF8A & 0x10) && *(s32 *)((u8 *)s1 + 4) >= 0 && (D_800B99DA & 1)) {
        func_801A6428(arg0);
    }
}
