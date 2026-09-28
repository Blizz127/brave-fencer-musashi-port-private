/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 a0);
extern void func_800CB428();
extern void func_800CB6A0(void *a0, void *a1, void *a2, s32 a3);
extern void func_800CB964(void *a0, void *a1, void *a2);

void func_800CB0B0(void *arg) {
    u16 sp10[3];
    u16 sp18[3];
    u16 temp;
    u16 cur;
    u8 b;

    sp10[0] = 0;
    sp10[1] = 0;
    sp10[2] = 0;
    sp18[0] = *(u16 *)((u8 *)arg + 0x234);
    sp18[2] = *(u16 *)((u8 *)arg + 0x236);
    sp18[1] = sp18[2];
    func_800CB428(arg, sp10, sp18);
    func_800CB6A0(arg, sp10, sp18, 1);
    func_800CB6A0(arg, sp10, sp18, 0);
    func_800CB964(arg, sp10, sp18);
    if (*(s16 *)((u8 *)arg + 0x234) != 0x2000) {
        temp = *(volatile u16 *)((u8 *)arg + 0x238) + 0x100;
        cur = *(volatile u16 *)((u8 *)arg + 0x234) + temp;
        *(u16 *)((u8 *)arg + 0x234) = cur;
        *(u16 *)((u8 *)arg + 0x238) = temp;
        if ((s16)cur >= 0x2001) {
            func_80147324(0x8EB);
            *(u16 *)((u8 *)arg + 0x234) = 0x2000;
        }
    } else {
        temp = *(volatile u16 *)((u8 *)arg + 0x23A) + 0x200;
        cur = *(volatile u16 *)((u8 *)arg + 0x236) + temp;
        *(u16 *)((u8 *)arg + 0x236) = cur;
        *(u16 *)((u8 *)arg + 0x23A) = temp;
        if ((s16)cur >= 0x2001) {
            b = *(u8 *)((u8 *)arg + 0x197);
            *(u16 *)((u8 *)arg + 0x236) = 0x2000;
            *(u8 *)((u8 *)arg + 0x197) = b + 1;
        }
    }
}
