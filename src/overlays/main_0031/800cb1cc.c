/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 a0);
extern void func_800CB428();
extern void func_800CB6A0(void *a0, void *a1, void *a2, s32 a3);
extern void func_800CB964(void *a0, void *a1, void *a2);
extern u16 func_80148800(s32 *a0);

void func_800CB1CC(void *arg0) {
    u16 sp10[3];
    u16 sp18[3];

    if (func_80148800((s32 *) arg0) & 0x20) {
        *(u32 *)((u8 *)arg0 + 0x238) = 0;
        *(u8 *)((u8 *)arg0 + 0x197) = *(u8 *)((u8 *)arg0 + 0x197) + 1;
        func_80147324(0x991);
    }
    sp10[0] = 0;
    sp10[1] = 0;
    sp10[2] = 0;
    sp18[0] = *(u16 *)((u8 *)arg0 + 0x234);
    sp18[2] = *(u16 *)((u8 *)arg0 + 0x236);
    sp18[1] = sp18[2];
    func_800CB428(arg0, sp10, sp18);
    func_800CB6A0(arg0, sp10, sp18, 1);
    func_800CB6A0(arg0, sp10, sp18, 0);
    func_800CB964(arg0, sp10, sp18);
}
