/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013BD74 - byte-exact against retail at -O0 (tools/register_match.py). */
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
extern s16 D_801A0C98;
extern s16 D_801A0C9A;
extern s16 D_801A0C9C;
extern s16 D_801A0C9E;

void func_8013BD74(void *a0, s32 a1) {
     



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

    D_801A0C98 = -0xA0;
    D_801A0C9A = -0x78;
    D_801A0C9C = 0x140;
    D_801A0C9E = 0xF0;
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
