/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB080 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB1F8(void *a0);
extern void func_800CB13C(s32 param_1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();

void func_800CB080(void *arg0) {
    if (*(u16 *)((u8 *)arg0 + 0xB8) & 0x4000) {
        ((void (*)(void))func_800CB1F8)();
    }
    if (*(u16 *)((u8 *)arg0 + 0xB8) == 0x8000) {
        func_801599A4(arg0);
        func_80159B3C(arg0);
    } else {
        if (*(s32 *)((u8 *)arg0 + 0x178) != 0) {
            func_800CB13C(arg0);
        }
        func_80161208(arg0);
    }
}
