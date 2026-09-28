/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130974,80130A18).
 * Offset 0x881C at overlay base 80128158. SHA256(span)=72120d9e2f2194445caaf8795ce987e35a141fe3f860cbfec2abbee200abffbd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130974.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130974 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_8012BEE8(int);
extern void func_80166244();
extern void func_801319E0(int);
extern void func_80131CA8(int, int);

void func_80130974(int param_1) {
    short sVar1;
    if ((*(unsigned int *)(param_1 + 0xb4) & 0x8000) != 0) {
        sVar1 = *(short *)(*(int *)(param_1 + 0x20) + 0x18);
        if (sVar1 < 0x1000) {
            *(short *)(*(int *)(param_1 + 0x20) + 0x18) = sVar1 + 0x400;
            *(short *)(*(int *)(param_1 + 0x20) + 0x1c) =
                *(unsigned short *)(*(int *)(param_1 + 0x20) + 0x1c) + 0x400;
        }
        if (func_8012BEE8(param_1) != 0) {
            ((void (*)(int))func_80166244)(param_1);
            func_801319E0(param_1);
            return;
        }
    }
    func_80131CA8(param_1, 0x2b);
}
