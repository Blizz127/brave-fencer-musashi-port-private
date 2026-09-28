/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013BD74 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef void (*code)(unsigned short *);
typedef struct {
        u8    pad0[8];
        void *f8;
        void *fC;
    } E_13BD74;
typedef struct {
        u8  pad0[3];
        u8  code;
        s32 f4;
        s32 f8;
    } P_13BD74;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_8019D078;
extern s16 D_8019D07A;
extern s16 D_8019D07C;
extern s16 D_8019D07E;

void func_8013BD74(void *a0, s32 a1) {
    /* §100 draft-LOCAL types: file-scope typedefs are NOT carried by extract_unit/remap_hseq, so a
       file-scope E_13BD74 banks the exemplar and then fails every sibling with `E_13BD74'
       undeclared (the §94 type-carry class, measured on ov_SC01_000). Block scope travels with the
       body and is byte-neutral (a type emits no code). */
    s32 *q;
    s32 *p;
    s32 i;
    s32 unused0;
    s32 unused1;
    P_13BD74 *e;
    P_13BD74 *end;
    s32 unused2;
    s32 base;
    s32 unused3;

    D_8019D078 = -0xA0;
    D_8019D07A = -0x78;
    D_8019D07C = 0x140;
    D_8019D07E = 0xF0;
    ((E_13BD74 *)a0)->f8 = (void *)a1;
    ((E_13BD74 *)a0)->fC = (void *)(a1 + 8);
    base = a1 + 0x4008;
    if (((u8 *)a1)[4] == 0) {
        p = (s32 *)((E_13BD74 *)a0)->fC;
        for (i = 0; i < 0x1000; i++) {
            if (*p != 0) {
                *p += (s32)((E_13BD74 *)a0)->fC;
                q = (s32 *)*p;
                q[0] += (s32)q;
                q[5] += (s32)q;
                e = (P_13BD74 *)q[5];
                q[6] = q[6] * 12 + q[5];
                end = (P_13BD74 *)q[6];
                while (e < end) {
                    switch (e->code) {
                    case 0x24:
                    case 0x2C:
                    case 0x34:
                    case 0x3C:
                        *(s32 *)e = (*(s32 *)e & 0xFFFFFF) + base;
                        break;
                    case 0x26:
                    case 0x2E:
                    case 0x36:
                    case 0x3E:
                        *(s32 *)e = (*(s32 *)e & 0xFFFFFF) + base;
                        break;
                    }
                    e++;
                }
            }
            p++;
        }
        ((u8 *)a1)[4] = 1;
    }
}
