/* Exact retail word export for [8005E1A4,8005E228); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (33/33 words at 0x8005E1A4). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

void func_8005EA54(u8 *);
void func_8005EA68(u8 *, s32);
void func_8005EAA8(u8 *, s32);

void func_8005E1A4(u8 *p) {
    switch (p[0x46]) {
    case 2:
        func_8005EA54(p);
        break;
    case 3:
        func_8005EA68(p, p[0xE4]);
        break;
    case 4:
        func_8005EAA8(p, p[0x47]);
        break;
    }
}
