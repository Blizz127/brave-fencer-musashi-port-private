/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEE8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014B2F8(void);
extern s32 func_80146994(s32, s32, s32, s32);
extern void func_80147324(s32 arg0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_800CAEE8(void *a0) {
    func_8014B2F8();
    func_80146994(0x41, (s32)a0, 0, 0);
    func_80147324(0x836);
    func_801599A4(a0);
    func_80159B3C(a0);
}
