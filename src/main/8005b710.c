/* Exact retail word export for [8005B710,8005B75C); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (19/19 words at 0x8005B710). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern volatile s32 *D_8007285C;
extern volatile s32 *D_80072860;
extern volatile s32 *D_80072864;
extern volatile s32 *D_80072868;

void func_8005B710(s32 arg0) {
    *D_8007285C = 0x04000002;
    *D_80072860 = arg0;
    *D_80072864 = 0;
    *D_80072868 = 0x01000401;
}
