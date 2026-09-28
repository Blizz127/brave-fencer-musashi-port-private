/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD508 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80162CCC(void);
extern s32 func_80146E98(s32 a0);
extern void func_800CD7A8(s32 a0, s32 a1);
extern void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg4);
extern void func_80162FC0(s32 *a0);
extern void func_800CD7A8();

void func_800CD508(s32 param_1) {
    register s32 obj __asm__("$17") = param_1;    
    register s32 bufp __asm__("$16");             
    u8 dead[0x20];
    char buf[0x20];
    s32 ret;

    ret = ((s32 (*)(void))func_80146E98)();
    if (ret != 0) {
        ((void (*)(s32))func_80162CCC)(obj);
    } else {
        bufp = (s32)buf;
        ((void (*)(s32, void *))func_800CD7A8)(obj, bufp);
        ((void (*)(s32, s32, s32, s32, void *))func_80163194)(obj, 0, 0x20000, 0, bufp);
        ((void (*)(s32 *))func_80162FC0)((s32 *)obj);
    }
}
