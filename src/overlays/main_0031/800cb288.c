/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB288 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB428();
extern void func_800CB6A0(void *a0, void *a1, void *a2, s32 a3);
extern void func_800CB964(void *a0, void *a1, void *a2);
extern u16 func_80148800(s32 *a0);

void func_800CB288(s32 arg0)
{
    s16 sp10[3];
    s16 sp18[3];
    u16 temp;
    u16 cur;
    register u16 temp2 __asm__("$2");
    register u16 cur2 __asm__("$3");

    if ((func_80146E98(arg0) == 0) || (!(func_80148800((s32 *) arg0) & 0x20))) {
        sp10[0] = 0;
        sp10[1] = 0;
        sp10[2] = 0;
        sp18[0] = *(u16 *) (arg0 + 0x234);
        sp18[2] = *(u16 *) (arg0 + 0x236);
        sp18[1] = sp18[2];
        func_800CB428(arg0, sp10, sp18);
        func_800CB6A0(arg0, sp10, sp18, 1);
        func_800CB6A0(arg0, sp10, sp18, 0);
        func_800CB964(arg0, sp10, sp18);
        if (*(s16 *) (arg0 + 0x236) != 0x10) {
            temp = *(volatile u16 *) (arg0 + 0x23A) + 0x100;
            cur = *(volatile u16 *) (arg0 + 0x236) - temp;
            *(u16 *) (arg0 + 0x236) = cur;
            *(u16 *) (arg0 + 0x23A) = temp;
            if ((s16) cur < 0x10) {
                *(u16 *) (arg0 + 0x236) = 0x10;
            }
            return;
        }
        temp2 = *(volatile u16 *) (arg0 + 0x238) + 0x200;
        cur2 = *(volatile u16 *) (arg0 + 0x234) - temp2;
        *(u16 *) (arg0 + 0x234) = cur2;
        *(u16 *) (arg0 + 0x238) = temp2;
        if ((s16) cur2 >= 0) {
            return;
        }
        *(u16 *) (arg0 + 0x234) = 0;
    }
    func_80165A78(arg0);
    func_80159B3C((void *) arg0);
}
