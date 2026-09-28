/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDCA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_80146E90(s32 *a0, s32 a1);
extern s32 func_80146E98(s32 a0);
extern s32 rand(void);

void func_800CDCA8(void *arg0) {
    s16 *ptr = *(s16 **)((s32)arg0 + 0x20);
    s32 val;

    if (func_80146E98((s32)arg0) != 0) {
        if ((rand() & 0x1F) == 0) {
            func_80146E90((s32 *)arg0, (rand() & 0x1F) | 0x20);
        }
        val = *(u16 *)((s32)ptr + 0x12);
        val += 0x38;
    } else {
        val = *(u16 *)((s32)ptr + 0x12);
        val += 0x155;
    }
    *(u16 *)((s32)ptr + 0x12) = val & 0xFFF;
}
