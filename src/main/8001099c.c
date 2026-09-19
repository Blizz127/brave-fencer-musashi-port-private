/* Exact retail word export for [8001099C,80010A08); EXE and assembly verified. */
#include "psx_types.h"

extern u8 D_800AF630[];
extern s32 D_800AE810[];
extern s32 func_8004239C(s32);

void func_8001099C(void) {
    register u8 *p = D_800AF630;

    D_800AE810[*(u16 *)(p + 0xA3D2)] = func_8004239C(1);
}
