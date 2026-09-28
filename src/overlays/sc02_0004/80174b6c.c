/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174B6C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126948[];
extern void func_8012A018(s32 a, s32 b);
extern void func_80174BBC(void *a0);
extern void func_8012A0E0(void);
extern void func_80174BF4(void *a0);

void func_80174B6C(void) {
    func_80174BBC(D_80126948);
    func_8012A018((s32)func_80174BF4, 0);
    func_8012A0E0();
    func_80174BF4(D_80126948);
}
