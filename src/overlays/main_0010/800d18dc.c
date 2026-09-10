/* MAIN10 resident retail span [800D18DC,800D1938), offset 0x22AE4 at base 800AEDF8.
 * External from MAIN.CD member 0012 (jal at 80128604 in func_801285E4).
 * NOT SC02_031 PAC0. Donor: Druthulu resident_jr_800D128C func_800D18DC,
 * cleaned to house style. Callee is indirect via D_801141BC[D_800AE6BC].
 */
#include "psx_types.h"

typedef struct {
    void (*fn[3])(void *);
} FnTbl3;

extern u8 D_800AE6BC;
extern FnTbl3 D_801141BC;
extern s32 D_800AE6A8;

void func_800D18DC(void) {
    u8 idx = D_800AE6BC;
    FnTbl3 local = D_801141BC;
    local.fn[idx](&D_800AE6A8);
}
