/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016D984 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);
extern void func_80146C3C(void);

void func_8016D984(s32 *a0) {
    if ((--*(s32 *)((char *)a0 + 0x1C)) == 0) {
        func_80146C3C();
    } else {
        func_800D22E4((s32)a0);
        *(s32 *)((char *)a0 + 0x10) -= *(s32 *)((char *)a0 + 0x10) >> 4;
        *(s32 *)((char *)a0 + 0x14) -= *(s32 *)((char *)a0 + 0x14) >> 4;
        *(s32 *)((char *)a0 + 0x18) -= *(s32 *)((char *)a0 + 0x18) >> 4;
    }
}
