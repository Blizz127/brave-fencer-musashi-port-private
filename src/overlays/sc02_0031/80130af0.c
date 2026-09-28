/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130AF0,80130C08).
 * Offset 0x8998 at overlay base 80128158. SHA256(span)=72946f1913d04362d414e88d5906faf24cf0c97b301a379cc1bca39c7b42778c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130af0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130AF0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80131B14();
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern int  func_80131A34(int a0, int a1);
extern void func_80131CA8(int a0, int a1);

void func_80130AF0(int param_1) {
    *(unsigned char *)(param_1 + 0xc1) = 0x13;
    if ((*(unsigned int *)(param_1 + 0xc4) & 2) != 0) {
        func_80131CA8(param_1, 3);
        return;
    }
    if ((*(unsigned int *)(param_1 + 0xb4) & 0x20000) != 0) {
        ((void (*)(int, int, int, int, int, int, int))func_80146A6C)(3, param_1, (int)*(short *)(param_1 + 0x7c),
                      (int)*(short *)(param_1 + 0x7e),
                      (int)*(short *)(param_1 + 0x80), 0xc0cfff8, 0xf000b000);
        if (((*(unsigned int *)(param_1 + 0xb4) & 1) != 0) ||
            ((*(unsigned int *)(param_1 + 0xc4) & 2) == 0)) {
            ((void (*)(int))func_80131B14)(param_1);
            if (*(short *)(param_1 + 0x76) < 1) {
                ((void (*)(int, int))func_80131E00)(param_1, 0xc);
                return;
            }
            if (func_80131A34(param_1, 4) != 0) {
                *(unsigned char *)(param_1 + 0xc2) = 0;
            } else {
                *(unsigned char *)(param_1 + 0xc2) = 1;
                *(short *)(param_1 + 0x98) = 0;
                *(int *)(param_1 + 0x1c) = 0x10;
            }
        }
        func_80131CA8(param_1, 3);
    }
    func_80131CA8(param_1, 0x37);
}
