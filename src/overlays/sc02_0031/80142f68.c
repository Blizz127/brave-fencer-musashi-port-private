/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142F68,80142FFC).
 * Offset 0x1AE10 at overlay base 80128158. SHA256(span)=419809d8e31c96257ffa179ac7b3d17c70f563bace19ba98ac74e4b48b00b002.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142f68.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142F68 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80142DB8(s32 *a0);
extern s32 func_8012C0EC(s32 a0);
extern void func_80142BB4(s32 *a0, s32 a1, s32 a2);
extern void func_80142C9C(s32 *a0);
extern s32 func_8012BF10(s32 a0, s32 a1);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_80142F68(s32 *a0) {
    if (func_80142DB8(a0) == 1) {
        func_80142BB4(a0, 1, 3);
        return;
    }
    if (*(s16 *)((u8 *)a0 + 0x100) != 0) {
        if (func_8012C0EC(a0) == 0) {
            return;
        }
        func_80142BB4(a0, 0, 3);
        return;
    }
    func_80142C9C(a0);
    if (func_8012BF10((s32)a0, 0x30) != 0) {
        func_8012AD44(a0, 2);
    }
}
