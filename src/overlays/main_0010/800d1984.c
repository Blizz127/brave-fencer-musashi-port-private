/* MAIN10 resident retail span [800D1984,800D19DC), offset 0x22B8C at base 800AEDF8.
 * Donor: Druthulu resident_jr_800D128C func_800D1984, cleaned to house style. */
#include "psx_types.h"

typedef struct {
    u8 pad_00[0xC];
    s32 (*fn_0c)(void);
    u8 pad_10[0x4];
    u8 f14;
    u8 f15;
} S800D1984;

extern s32 func_800D19DC(S800D1984 *);

s32 func_800D1984(S800D1984 *arg0) {
    if (arg0->fn_0c() != 0) {
        register S800D1984 *a0 __asm__("$4") = arg0;
        u8 val = arg0->f14 + 1;
        a0->f14 = val;
        return func_800D19DC(a0);
    }
    return 0;
}



