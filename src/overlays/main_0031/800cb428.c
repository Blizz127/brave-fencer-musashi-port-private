/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB428 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800183E0(s32 a0);
extern u8 D_800CBF3C[];
extern u8 D_800CBF7C[];
extern u8 D_800CBF5C[];
extern u8 D_800CBFA8[];

void func_800CB428(void *a0) {
    extern u32 func_80029204(s32 arg0);
    extern void func_800CB5C8(void *a0, void *a1);
    extern void func_800183E0(s32 a0);
    extern u8 D_800CC0FC[];
    extern u8 D_800CBF7C[];
    extern u8 D_800CC11C[];
    extern u8 D_800CBFA8[];
    extern u8 D_800CBF3C[];
    extern u8 D_800CBF5C[];
    u16 sp10[3];
    u16 *s0;
    s32 *s1;
    s32 id;
    s32 flag;
    s32 v;

    id = func_80029204(4);
    __asm__("" : "=r"(id) : "0"(id));

    flag = 0;
    s0 = (u16 *)D_800CC0FC;
    s1 = (s32 *)D_800CBF7C;
loop1:
    v = *s1;
    if (v == 0) {
        goto done1;
    }
    if (id == v) {
        sp10[0] = *s0 & 0x1F;
        sp10[1] = (*s0 >> 5) & 0x1F;
        sp10[2] = (*s0 >> 10) & 0x1F;
        func_800CB5C8(sp10, (u8 *)a0 + 0xBE);
        *s0 = ((sp10[2] << 10 | sp10[1] << 5) | sp10[0]) | 0x8000;
        flag = 1;
    }
    s0++;
    s1++;
    if (flag == 0) {
        goto loop1;
    }
done1:
    flag = 0;
    s0 = (u16 *)D_800CC11C;
    s1 = (s32 *)D_800CBFA8;
loop2:
    v = *s1;
    if (v == 0) {
        goto done2;
    }
    if (id == v) {
        sp10[0] = *s0 & 0x1F;
        sp10[1] = (*s0 >> 5) & 0x1F;
        sp10[2] = (*s0 >> 10) & 0x1F;
        func_800CB5C8(sp10, (u8 *)a0 + 0xBF);
        *s0 = ((sp10[2] << 10 | sp10[1] << 5) | sp10[0]) | 0x8000;
        flag = 1;
    }
    s0++;
    s1++;
    if (flag == 0) {
        goto loop2;
    }
done2:
    func_800183E0((s32)&D_800CBF3C);
    func_800183E0((s32)&D_800CBF5C);
}
