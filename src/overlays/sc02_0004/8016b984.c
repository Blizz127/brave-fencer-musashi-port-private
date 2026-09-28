/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016B984 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern void func_80146C3C();
extern void func_80146C3C(void);

void func_8016B984(void *a0) {
    if (*(s32*)((s32)a0 + 0x10) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x10), 0x38);
    }
    if (*(s32*)((s32)a0 + 0x14) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x14), 0x38);
    }
    if (*(s32*)((s32)a0 + 0x18) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x18), 0x38);
    }
    ((void (*)(void *))func_80146C3C)(a0);
}
