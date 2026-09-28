/* Main-exec range [80015144,80015208) from the SLUS executable.
 * SHA256(span)=6ad62d5925c7f85a798c02b205f31b40896b77551a2152570af1c466d32c5f13.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80015144 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80034B98(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8003500C(void);
extern void func_8002D034(void);
extern int func_8004239C(int mode);
extern s32 func_8001AA78(void);
extern void func_8002F67C(void);
extern void func_80019990(void);
extern u8 D_800AF630[];
extern s16 D_800B9A04[];

s32 func_80015144(void) {
    u8* base = D_800AF630;

    if (func_80034B98() != 0) {
        func_8002D4C8(2, 0);

        while (1) {
            func_8003500C();
            func_8002D034();
            func_8004239C(*(s32*)(base + 0xA3E8));
            if (func_80034B98() == 0) {
                break;
            }
        }

        *(s16*)(base + 0xA3D4) = 1;
    } else {
        if (func_8001AA78() != 0) {
            return 0;
        }
        D_800B9A04[0] = 1;
        func_8002D4C8(2, 0);
    }

    func_8002F67C();
    func_80019990();
    return 1;
}
