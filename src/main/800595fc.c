/* Exact retail word export for [800595FC,80059658); EXE and assembly verified. */
#include "psx_types.h"

extern char D_80074110[];
extern u8 D_8007278A;
extern s32 D_80072794;
extern void (*D_80072784)(const char *, s32);

/* Recovered from retail and verified byte-exact with gcc-2.7.2-psx -O2. */
s32 func_800595FC(s32 arg0) {
    s32 temp_v0;

    if ((u8)D_8007278A >= 2U)
        D_80072784(D_80074110, arg0);
    temp_v0 = D_80072794;
    D_80072794 = arg0;
    return temp_v0;
}
