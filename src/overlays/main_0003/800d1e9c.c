/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1E9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800EC9A4[];
extern s32 D_800EC9AC;
extern s32 D_800EC9B8;
extern s16 D_800EC9BC[];
extern s16 D_800EC9BE[];
extern s32 D_800EC9CC;
extern s32 D_800EC9E0;
extern s32 D_800EC9E4;
extern s32 D_800EC9F0;
extern s32 D_800EC9F4;
extern s32 D_800EC9F8;
extern u8 D_800EC9FC[];
struct S_D2394;
struct S_D2394B;
extern void func_800D2394(struct S_D2394 *t, s16 a1, s16 a2, s16 a3, s32 a4, struct S_D2394B *a5);
extern void func_800D2454();
extern void func_800D24D0();
extern s32 func_800D2704();
extern void func_800D298C();
extern void func_800D2AA0();
extern void func_800D2C0C();
extern void func_800D2C88();
extern void func_800D2D44();
extern void func_800468FC(void);
extern void func_8002D8D4(void);
extern void func_8002D8A8(void);
extern void func_8002D034(void);
extern void func_800189A8(void);
extern s32 func_80014CAC(s32 a0, s32 a1);
extern void func_80043830(s32 a0, s32 a1, s32 a2);
extern void func_80010A98(void);
extern void func_80059658(s32 a0);
extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_80059FC0(u8 *a0);
extern s32 func_8004239C(s32 a0);
extern void *func_80058B04(void *a0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_800D1E9C(void *arg0) {
    s32 sp18[30];
    s16 sp90[4];
    s16 sp98[8];
    s32 *p;
    s32 i;
    register s32 v0r __asm__("$2");

    p = (s32 *) arg0;
    D_800EC9F0 = 1;
    ((void (*)()) func_800D2394)(D_800EC9A4,
                                 p[1] ? (p[4] * 3) / 2 : p[4],
                                 p[5],
                                 p[1] ? (p[4] * 3) / 2 : p[4],
                                 p[5] + p[7],
                                 p);
    if (((s32 (*)()) func_800D2454)(D_800EC9FC, func_800D24D0, p) != 0) {
        func_800D2D44(0);
        func_800468FC();
        func_8002D8D4();
        func_800D2AA0(0);
        __asm__ __volatile__("");
        goto ret;
    }
    if (func_800D2704(D_800EC9A4, p) != 0) {
        func_800D2D44(0);
        func_800468FC();
        func_8002D8D4();
        func_800D2AA0(0);
        goto ret;
    }
    D_800EC9F4 = 0;
    D_800EC9F8 = 0;
    func_80059658(0);
    func_8004239C(0);
    sp90[0] = 0;
    sp90[1] = 0;
    sp90[2] = p[1] ? (p[6] * 3) / 2 : p[6];
    sp90[3] = p[7] * 2;
    if (p[1] != 0) {
        func_80059888(sp90, 0, 0, 0);
        sp98[0] = 0x1E0;
        sp98[1] = 0;
        sp98[2] = 0xA0;
        sp98[3] = 0x1E0;
        func_80059888(sp98, 0xFF, 0xFF, 0xFF);
    } else {
        func_80059888(sp90, 0, 0, 0);
        sp98[0] = 0x140;
        sp98[1] = 0;
        sp98[2] = 0x140;
        sp98[3] = 0x1E0;
        func_80059888(sp98, 0xFF, 0xFF, 0xFF);
    }
    for (;;) {
        func_800D2C0C(D_800EC9A4[D_800EC9AC], p[1] ? 3 : 2);
        ((void (*)()) func_800D2C88)((&D_800EC9A4[3])[D_800EC9B8],
                                     ((*(s16 *) ((u8 *) D_800EC9A4 + 0x30) << 4) *
                                      ((*(s16 *) ((u8 *) D_800EC9A4 + 0x32) - 1) / 16 + 1)) >> 1);
        if (func_800D2704(D_800EC9A4, p) != 0) {
            func_800D2D44(0);
            func_800468FC();
            func_8002D8D4();
            goto after;
        }
        func_800D298C(D_800EC9A4, 0);
        func_8004239C(0);
        i = (D_800EC9CC == 0);
        func_80058B04(sp18,
                      D_800EC9BC[i * 4] -
                          (p[1] ? (p[4] * 3) / 2 : p[4]),
                      D_800EC9BE[i * 4] - p[5],
                      p[1] ? (p[6] * 3) / 2 : p[6],
                      p[7]);
        if (p[1] != 0) {
            *((u8 *) sp18 + 0x11) = p[1];
            *(s16 *) ((u8 *) sp18 + 4) = (*(s16 *) ((u8 *) sp18 + 4) * 2) / 3;
        }
        func_80059FC0((u8 *) sp18);
        func_80059658(1);
        if (D_800EC9F4 == 1) {
            goto done;
        }
        func_800189A8();
        if (D_800EC9F8 == 0) {
            if (D_800EC9E0 == 0) {
                if (func_80014CAC(0, 0x800) != 0) {
                    D_800EC9E0 = 1;
                    D_800EC9E4 = 0x10;
                    func_8002D8A8();
                }
            } else {
                D_800EC9E4 -= 1;
                if (D_800EC9E4 == 0) {
                    goto done;
                }
            }
        }
        func_8002D034();
    }
done:
    func_800D2D44(0);
    func_800468FC();
    func_8002D8D4();
    func_80043830(9, 0, 0);
after:
    func_800D2AA0(0);
    func_80059658(1);
ret:
    func_80010A98();
    v0r = 1;
    __asm__ __volatile__("" : : "r"(v0r));
}
