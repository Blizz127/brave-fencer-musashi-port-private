/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128AF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* m2c compat (vendor/bfm-decomp/include/common.h). */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))

extern void func_8002AEF8(void);
extern void func_800CFBBC(void);
extern void func_80011B7C(int);
extern void func_80011C10(void);
extern u16 D_800B99F6;
extern M2C_UNK (*D_8017D2E0)();
extern s32 (*D_8017D2E4)();
extern s32 D_80195298;

void func_80128AF4(void) {
    switch (D_800B99F6) {                           /* irregular */
    case 0:
        D_80195298 = func_8002AF08();
        func_80011C10();
        return;
    case 1:
        D_8017D2E0();
        func_80011C10();
        return;
    case 2:
        if ((D_8017D2E4() << 0x10) != 0) {
            if (D_80195298 == 1) {
                if (func_800CFBE8() != 0) {
                    func_800CFBBC();
                    func_80011B7C(0x13);
                } else {
                    func_80011B7C(4);
                }
            } else {
                func_80010DE0();
            }
            func_8002AEF8();
        }
        return;
    }
}
