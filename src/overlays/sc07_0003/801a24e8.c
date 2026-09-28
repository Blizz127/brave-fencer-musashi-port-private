/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A24E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8   D_801202A0[];
extern s32  func_8012BC60(void *a0, void *a1);
extern s32  func_8012B6D4(s16 *a0, s16 *a1);
extern void func_8012B0B4(u32 *a0, s32 a1, s32 a2);
extern s32  func_8012CEB0(s32 a0, s32 a1, s32 a2);
extern void func_8012ADE4(u8 *a0);

void func_801A24E8(s32 a0) {
    u8 *p;
    s16 *self4;
    unsigned int *sc;
    s32 i;
    s32 ang;
    s16 v10[4];  /* sp+0x10 */
    s16 v18[4];  /* sp+0x18 */
    s32 sp20[2]; /* sp+0x20 — func_8012B0B4 output */

    p = D_801202A0;
    i = 0;
    self4 = (s16 *)(a0 + 4);
    sc = (unsigned int *)sp20;
    do {
        switch (*(u16 *)p) {
        case 0x4B:
            if (func_8012BC60((void *)self4, (void *)(p + 4)) <= 0x30FFF) {
                ang = func_8012B6D4(self4, (s16 *)(p + 4));
                func_8012B0B4(sc, ang, 0x1C0);
                v18[0] = *(u16 *)(p + 6);
                v18[1] = *(u16 *)(p + 0xA);
                v18[2] = *(u16 *)(p + 0xE);
                v18[0] += sp20[0];
                v18[1] = *(u16 *)(a0 + 0xA);
                v18[2] += sp20[0] >> 16;
                v10[0] = *(u16 *)(a0 + 0x3A);
                v10[1] = *(u16 *)(a0 + 0x3E);
                v10[2] = *(u16 *)(a0 + 0x42);
                if ((func_8012CEB0((s32)v10, (s32)v18, 0) & 0x2000) == 0) {
                    func_8012ADE4((u8 *)a0);
                    return;
                }
                *(u16 *)(a0 + 6) = v18[0];
                *(u16 *)(a0 + 0xA) = v18[1];
                *(u16 *)(a0 + 0xE) = v18[2];
                return;
            }
            break;
        }
        i++;
        p += 0x10C;
    } while (i < 0x60);
}
