/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE88 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800CC9E8;
extern s16 D_800CC9EA;
extern s16 D_800CC9F0;
extern s16 D_800CC9F2;
extern u16 D_800B99DA;
extern s32 D_800CC9EC;
extern s32 D_800CC9F4;
extern s32 D_800CCB18;
extern s32 D_800A2B78;
extern void func_800CB00C();

void func_800CAE88(s32 *arg0, s32 p1, s32 p2) {
    register s32 v0in __asm__("$2");
    s32 flag1;
    s32 flag2;
    s32 temp;

    if (!(v0in & 1)) {
        flag1 = D_800CC9EC;
        if (flag1 == 0) {
            D_800CC9E8++;
            D_800CC9EA++;
            if (D_800CC9EA >= 0x200)
                D_800CC9EC = 1;
        } else {
            D_800CC9E8--;
            D_800CC9EA--;
            if (D_800CC9E8 <= 0)
                D_800CC9EC = flag1 ^ 1;
        }
        if (!(D_800B99DA & 1)) {
            flag2 = D_800CC9F4;
            if (flag2 == 0) {
                D_800CC9F0++;
                D_800CC9F2++;
                if (D_800CC9F2 >= 0x200)
                    D_800CC9F4 = 1;
            } else {
                D_800CC9F0--;
                D_800CC9F2--;
                if (D_800CC9F0 <= 0)
                    D_800CC9F4 = flag2 ^ 1;
            }
        }
    }
    temp = *arg0;
    D_800CCB18 = temp;
    D_800A2B78 = (temp >> 28) & 7;
    func_800CB00C(arg0, p1, p2);
}
