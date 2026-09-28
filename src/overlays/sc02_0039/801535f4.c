/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801535F4 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80146D90(s32 a0);
void func_8014CC28(s32 a0);
void func_8014ED28(s32 _arg0);
void func_8014FA04(s32 a0);
extern void func_8014CC28(s32 a0);
extern void func_80146D90(s32 a0);
extern void func_8014ED28();
extern void func_8014FA04(s32 a0);

s32 func_801535F4(void *arg0) {
    s32 var_s1;
    register u32 flags __asm__("$4");
    register u32 fcopy __asm__("$3");
    s32 ret;
    var_s1 = 0;
    if (((s32 (*)(void))func_8014ED28)() != 0) {
        func_80146D90((s32)arg0);
    }
    if ((*(s32 *)((u8 *)arg0 + 0x34) > 0) &&
        (((s32 (*)(s32))func_8014CC28)((s32)arg0) != 0)) {
        var_s1 = 1;
    }
    flags = ((s32 (*)(s32))func_8014FA04)((s32)arg0);
    fcopy = flags;
    if (flags & 0x4000) {
        ret = 2;
    } else if (flags & 0x2000) {
        ret = 1;
    } else {
        ret = 4;
        if ((fcopy & 0x8000) == 0) {
            ret = var_s1;
        }
    }
    __asm__ __volatile__("" : : "r"(flags));
    return ret;
}
