/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80152714 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void func_80159B3C(void *a0);
extern u8 D_80062BF4[];
extern void func_80019064(void *a0);
extern int func_80151204(int arg, int a1);
int func_80151204(int a0, int a1);
extern void func_80165718(s32 a0);
extern void func_80152790(s32 a0);

void func_80152714(s32 a0) {
    s32 sp[8];
    func_80019064((void *)D_80062BF4);
    func_80151204(a0, *(s16 *)(a0 + 0xF2));
    if (D_80078EC1 != 2) {
        *(s32 *)(a0 + 0x1AC) = 0x3C0000;
        *(s32 *)(a0 + 0x44) = *(s32 *)(a0 + 0x44) | 0x100;
    }
    func_80152790(a0);
    func_80159B3C((void *)a0);
    func_80165718(a0);
    (void)sp;
}
