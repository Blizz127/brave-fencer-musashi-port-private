/* Overlay range [801377B4,80137840) from MAIN.CD member 0012.
 * SHA256(span)=a9fcbd0f2b8157531d1510d659f1d3da7f0f0ba1552bd9f14db3a040fd213e57.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Verified byte-exact against retail by tools/match_function.py
 * (35/35 words at 0x801377B4). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"
#include "m2c_macros.h"

void func_80137840(void *);                      /* static */
extern void *D_80127524;
extern void *D_80127528;

void func_801377B4(s32 arg0, s16 arg1, void *arg2) {
    func_80137840(arg2);
    M2C_FIELD(arg2, s16 *, 4) = 1;
    M2C_FIELD(arg2, s32 *, 0) = arg0;
    M2C_FIELD(arg2, s32 *, 8) = (s32) arg1;
    if (arg1 & 0x2000) {
        goto skip;
    }
    {
        void **pp = &D_80127524;
        if (*pp != 0) {
            D_80127528 = *pp;
            M2C_FIELD(*pp, s16 *, 0x1A) = 2;
        }
        *pp = arg2;
    }
skip:;
}
