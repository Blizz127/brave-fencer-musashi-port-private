/* Exact retail word export for [8005FBC8,8005FC68); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (40/40 words at 0x8005FBC8). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern u32 D_80078F24;
extern u32 D_800C5320;

s32 func_8005FBC8(void) {
    u32 count;

    count = *(volatile u16 *) 0x1F801120;
    if (count < D_80078F24) {
        if (*(volatile u16 *) 0x1F801128 != 0) {
            count += *(volatile u16 *) 0x1F801128;
        } else {
            count += 0x10000;
        }
    }
    if (*(volatile u16 *) 0x1F801124 & 0x200) {
        return (count - D_80078F24) >= D_800C5320;
    } else {
        return ((count - D_80078F24) >> 3) >= D_800C5320;
    }
}
