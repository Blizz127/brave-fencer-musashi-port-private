/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6560 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A5C44(void);
extern void func_801A5B5C(void *a0);
extern void func_801A5D68(void *a0);
extern void func_801A5CE8(void *a0);
extern void func_8017E5D4(void *a0);
extern void func_8017E1E8(void *a0, void *a1, void *a2);
extern u16 D_8019FF8A;
extern u8 D_801F88A8[];
extern u8 D_801F88B0[];
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A6560(s32 arg0) {
    func_801A5C44();
    func_801A5B5C((void *)arg0);

    if (!(D_8019FF8A & 4)) {
        if (*(void **)(arg0 + 0xD0) != NULL) {
            func_8017E5D4(*(void **)(arg0 + 0xD0));
            *(void **)(arg0 + 0xD0) = NULL;
        }
        func_8012AD44((s32 *)arg0, 1);
    } else {
        func_801A5D68((void *)arg0);
        func_801A5CE8((void *)arg0);
        if (*(s32 *)(arg0 + 0xD0) != 0) {
            func_8017E1E8(*(void **)(arg0 + 0xD0), D_801F88A8, D_801F88B0);
        }
    }
}
