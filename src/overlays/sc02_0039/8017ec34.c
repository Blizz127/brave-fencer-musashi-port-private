/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017EC34 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransPers func_8004955C
#define rand func_8005C49C
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 rand(void);
extern int rand(void);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s16 D_8019B5E6[][4];
extern void func_8012CC64(s32 a0, s32 a1);
extern void func_8012CC40(s32 a0, s32 a1);
extern void func_8012C218(void *a0);
extern s32  func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32  func_80132EF4(s32 a0, s32 a1);
extern void func_8012E32C(void);
extern s32  RotTransPers(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8017EED8(s32 a0);
extern s32  rand(void);
extern u8   D_8019B5E4[];
extern s16  D_8019B5E6[][4];
extern u16  D_8019B5EA[][4];
typedef struct { u16 xy[2]; s32 sp1c; s32 flag; } Out_8017EC34;

void func_8017EC34(s32 param_1)
{
    s32 v1;
    s32 s1;

    if (*(s16 *)(param_1 + 0x102) == 0) {
        v1 = ((s32 (*)(s32, s32))func_8012CC64)(param_1, (s32)D_8019B5E4);
    } else {
        v1 = ((s32 (*)(s32, s32))func_8012CC40)(
                 param_1, (s32)&D_8019B5E4[*(s16 *)(param_1 + 0x102) * 8]);
    }

    if (*(s16 *)(param_1 + 0xA) >= -0x200) {
        func_8012C218((void *)param_1);
        return;
    }

    if (v1 != 0) {
        v1 &= 0x2000;                                    
        s1 = D_8019B5EA[*(s16 *)(param_1 + 0x102)][0];

        if (v1 != 0) {
            *(s16 *)(param_1 + 0x16) = -*(u16 *)(param_1 + 0x16);
            if (*(s16 *)(param_1 + 0xFE) == 0) {
                *(s16 *)(param_1 + 0xFE) = *(s16 *)(param_1 + 0xFE) + 1;
                *(s16 *)(param_1 + 0x16) = *(u16 *)(param_1 + 0x16) - 8;
            }
        } else {
            *(s16 *)(param_1 + 0xFE) = 0;
            *(s16 *)(param_1 + 0x16) = -4;
            if (*(s16 *)(param_1 + 0x102) < 2) {
                if ((rand() & 0x7FFF) < (s16)s1) {
                    func_8012C658(0x1A9, 2, param_1);
                }
            }
        }

        if (s1 != 0) {
            s32 p = func_80132EF4(param_1, 0x22);
            if (p != 0) {
                 

                *(s16 *)(p + 0xA) = *(u16 *)(p + 0xA) +
                    *(u16 *)&D_8019B5E6[*(s16 *)(param_1 + 0x102)][0];
                *(s16 *)(p + 0x34) = s1 + 1;
            }
        }

        s1 = (*(u16 *)(param_1 + 0x70) & 0x80) ? 0x6DC : 0;
        if (*(u16 *)(param_1 + 0x70) & 0x40) {
            s1 = 0x6DB;
        }

        if (s1 != 0) {
            u16 input[3];
            Out_8017EC34 out;
            s16 x;
            s32 r;
            u16 q;                                       

            input[0] = *(u16 *)(param_1 + 0x6);
            input[1] = *(u16 *)(param_1 + 0xA);
            input[2] = *(u16 *)(param_1 + 0xE);

            func_8012E32C();
            RotTransPers((s32)input, (s32)out.xy, &out.sp1c, &out.flag);

            x = out.xy[0];
            r = (x + 0xA0) / 20;
            if (x < 0) {
                q = (x >> 1) + 0x7F;
            } else {
                q = 0x7F - (x >> 1);
            }
            if ((u16)r < 0x10 && q >= 0x2F && q < 0x80) {
                 

                func_8002D4C8(s1, (u16)(((r << 8) | 0x3000) | q));
            }
        }
    }

    *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x10) =
        *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x10) + *(u16 *)(param_1 + 0x100);
    func_8017EED8(param_1);
}
