/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157580 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_8015BDD0(s32 *a0);
extern void func_801575E4(void *a0);

void func_80157580(s32 arg0) {
    s32 temp_s1;
     
    temp_s1 = ((s32 (*)(s32))func_8014CC28)(arg0);
     
    if ((((s32 (*)(s32))func_8014F3E8)(arg0) == 0) && (temp_s1 == 0)) {
        func_8015BDD0((s32 *)arg0);
        return;
    }
    func_801575E4((void *)arg0);
}
