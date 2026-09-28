/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161B18 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800AE6B0;
extern void func_801599A4(void *a0);
void func_8015FA78(s32 *a0);
extern void func_801599A4(void*);
extern void func_8015FA78(s32 *a0);

s32 func_80161B18(void *a0) {
    if ((D_800AE6B0 & 0x80FFFFFF) != 0) return 0;
    if (*(s32 *)((u8 *)a0 + 0x44) & 0x10) {
        func_801599A4(a0);
        func_8015FA78((s32 *)a0);
        return 1;
    }
    return 0;
}
