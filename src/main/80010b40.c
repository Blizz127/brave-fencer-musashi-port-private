/* Exact retail word export for [80010B40,80010BB4); EXE and assembly verified. */
/* Guest pointers held as u32 for the 64-bit native lane. */
#include "psx_types.h"

extern u8 D_800AF630[];
extern u32 D_800629F4[]; /* guest void (*)(void) table */

void func_80010B40(void) {
    register u8 *p = D_800AF630;
    register void (*fn)(void);

    fn = (void (*)(void))D_800629F4[*(u16 *)(p + 0xA3AE)];
    fn();
}
