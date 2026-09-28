/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD2EC - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern void func_80147324(s32 a0);
extern s32 func_80146CA0(void *);
extern s32 func_80146CA0(void *a0);
extern u16 D_800B99DA;
extern s32 func_80146CA0(void*);
extern void func_80147324(s32);
extern void func_80146E90(s32*, s32);
extern s16 currentLocationId;
extern s32 func_80146E98(s32 a0);
extern void func_800CD57C(void *arg0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_800CD848(s32 param_1);
extern void func_800CD780(s32 param_1);
extern void func_800CD7A8(s32 a0, s32 a1);
extern void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg4);
extern void func_80162FC0(s32 *a0);
extern void func_800CD758(s32 param_1);
extern void func_800CD63C(s32 a0, s32 a1);
extern s32 func_800CD894(void *a0);
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146C98(s32 *a0, s16 a1);
extern s32 func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80163328();
extern s32 func_801632F0();
extern s32 func_801632E0();

void func_800CD2EC(s32 *s1) {
    u8 buf[0x40];
    u8 *p;
    s32 s2;
    s32 v0;

    s2 = *(s32 *)(s1 + 8);
    if (func_80146E98((s32)s1) == 0) {
        if ((*(u16 *)&D_800B99DA & 3) == 0) {
            func_800CD57C(s1);
        }
        func_80146A6C(0x26, s1, *(s16 *)((s32)s1 + 6), *(s16 *)((s32)s1 + 0xA),
                      *(s16 *)((s32)s1 + 0xE), *(s16 *)(s2 + 0x12), 0);
        func_800CD848((s32)s1);
        func_800CD780((s32)s1);
        p = buf + 0x20;
        func_800CD7A8((s32)s1, (s32)p);
        func_80163194((s32)s1, 0, -0x1000, 0x14000, (s32)p);
        func_80162FC0(s1);
        func_800CD758((s32)s1);
        func_800CD63C((s32)s1, (s32)p);
        if (currentLocationId == 0x3067) {
            if (func_800CD894(s1) != 0) {
                func_80146DE8(s1, 0, 0xFFF40000, 0x20000);
                func_80146E90(s1, 0x10);
                *(s32 *)(s2 + 4) |= 0x50000000;
                func_80146C98(s1, 3);
                func_80147324(0x990);
                return;
            }
        }
        func_80163408((s32)s1, 0x23, 0x80, 8);
        func_80163328(s1);
        v0 = func_801632F0(s1);
        if ((v0 & 1) != 0) {
            func_801632E0(s1);
        } else if ((v0 & 6) == 0) {
            return;
        }
    }
    func_80146CA0(s1);
}
