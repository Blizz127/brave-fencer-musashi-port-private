/* Exact retail word export for [8001AE90,8001AF04); EXE and assembly verified. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8001AE90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_800747F4;

s32 func_8001AE90(s32 kind, s32 value, s32 *ptr) {
    switch (kind) {
    case 0:
    case 2:
        return *ptr == D_800747F4;
    case 1:
        return value == D_800747F4;
    }
    return 0;
}
