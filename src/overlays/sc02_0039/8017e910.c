/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E910 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixY func_8004A0DC
#define RotTransPers func_8004955C
#define RotTransSV func_8004945C
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void RotTransSV(void *a0, void *a1, void *a2);
typedef struct { s32 w[8]; } Mat32_8017E910;
typedef struct { s16 a, b, c, d; } SV4_8017E910;
typedef struct { s32 flag; u16 xy[2]; s32 sp1c; } Out_8017E910;

void func_8017E910(void *a0)
{
    extern Mat32_8017E910 D_800AE620;
    extern void RotMatrixY(s32 a0, void *a1);
    extern void func_8004914C(void *a0);
    extern void func_800491AC(void *a0);
    extern void RotTransSV(void *a0, void *a1, void *a2);
    extern s32 RotTransPers(s32 a0, s32 a1, s32 *a2, s32 *a3);
    extern void func_8012E32C(void);
    extern SV4_8017E910 D_8019B5AC;

    u16 input[3];
    Mat32_8017E910 m;
    Out_8017E910 out;

    m = D_800AE620;

    m.w[5] = *(s16 *)((s32)a0 + 0x6);
    m.w[6] = *(s16 *)((s32)a0 + 0xA);
    m.w[7] = *(s16 *)((s32)a0 + 0xE);

    RotMatrixY(*(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12), &m);

    func_8004914C(&m);
    func_800491AC(&m);

    RotTransSV(&D_8019B5AC, input, &out);

    func_8012E32C();

    *(s32 *)((s32)a0 + 0xE0) = RotTransPers((s32)input, (s32)out.xy, &out.sp1c, &out.flag);

    {
        u16 xy0 = out.xy[0];
        s32 flagval = out.flag;
        *(s16 *)((s32)a0 + 0x100) = xy0;
        if (flagval < 0) {
            *(s16 *)((s32)a0 + 0x100) = -0x3E7;
        }
    }
}
