/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
typedef struct {
    s8 pad00[0x12];
    s16 f12;
    s8 pad14[6];
    s16 f1A;
    s32 f1C;
    s8 pad20[8];
    u16 f28;
    u16 f2A;
    s8 pad2C[4];
    u32 f30;
} St;
extern u8 D_80078EC1;
extern s16 D_80126BCC;
extern u16 D_80126BCA;
extern s16 D_80126BC8;
extern u16 D_800B99DA;
s32 func_80146AB4(s32, void *, s32, s32, s32, s32, s32);
void func_80146C3C(void *);
void func_8002D4C8(s32, s32);

void func_800CB0D0(St *arg0) {
    s16 *p;
    s32 r;
    if (D_80078EC1 == 0x14) {
        switch (arg0->f30) {
        case 0:
            r = rand();
            arg0->f1A = r & 0xFFF;
            arg0->f2A = (r & 1) + 2;
            arg0->f30 = arg0->f30 + 1;
            break;
        case 1:
            if ((arg0->f1C++ & 1) == 0) {
                if (func_80146AB4(0x38, arg0, 0, 0, 0, arg0->f12,
                                  arg0->f1A | ((s16)arg0->f28 << 16)) == 0) {
                    arg0->f2A = 0;
                }
                arg0->f28++;
                if ((s16)arg0->f28 >= 3) {
                    arg0->f28 = 0;
                }
                arg0->f2A--;
                if ((s16)arg0->f2A <= 0) {
                    arg0->f1C = 0xE;
                    arg0->f30 = arg0->f30 + 1;
                }
            }
            break;
        case 2:
            if (--arg0->f1C == 0) {
                arg0->f30 = 0;
            }
            break;
        }
        p = &D_80126BCC;
        if (*p < 0x1000) {
            D_80126BCA -= 0x38;
            *p += 0xE0;
            D_80126BC8 = *p;
        }
        if ((D_800B99DA & 0xF) == 0) {
            func_8002D4C8(0x5FB, 0);
        }
    } else {
        D_80126BCC = 0x1000;
        D_80126BCA = 0x1000;
        D_80126BC8 = 0x1000;
        func_80146C3C(arg0);
    }
}
