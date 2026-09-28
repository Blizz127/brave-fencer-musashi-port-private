/* SC02 resident image [8017C180,8017C2B0) at overlay base 0x80128158.
 * SHA256(span)=0904f5d8587fd44b32cc3614784d1006822f65ff58312e6f9ef337d1183f2ac3.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017C180 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
typedef void (*code)(unsigned short *);
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MTX_L_8017C180;
typedef struct { s16 a, b, c, d; } SV4_L_8017C180;
extern void func_8012A568(void (*a0)(void));
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_80049A1C(void *a0, void *a1);

void func_8017C180(s32 param_1, s32 param_2)
{

    extern s32 D_801B75A8;
    extern s32 D_801B75AC;
    extern s32 D_801B75B0;
    extern s32 D_801B75B8;
    extern s32 D_801B75BC;
    extern s32 D_801B75C0;
    extern s32 D_801B75C8;
    extern s32 D_801B75CC;
    extern s32 D_801B75D0;
    /* 8-byte short-only vector (SVECTOR); 32-byte MATRIX_L48 (t[] at +0x14) */

    SV4_L_8017C180 vec;                              /* sp+0x10 */
    MTX_L_8017C180 mtx;                              /* sp+0x18 */
    s32 obj = *(s32 *)(param_1 + 0xCC);
    s32 prim = *(s32 *)(param_1 + 0x20);
    s32 mode;
    s32 val;
    s32 hi;
    s32 code;
    s32 t;

    if ((s16)param_2 != 0) {
        mode = 0x40000000;
        val = 0x1000;
    } else {
        mode = 0x50000000;
        val = 0x1333;
    }
    code = *(s32 *)(prim + 4) & 0xCFFFFFFF;
    hi = 0x40000000;
    *(s32 *)(prim + 4) = code | (mode | hi);

    if (*(u16 *)(*(s32 *)(param_1 + 0xCC)) != 0) {
        *(s16 *)(obj + 0x1A) = val;
        *(s16 *)(obj + 0x18) = val;
    }

    t = *(u16 *)(param_1 + 0xFC) + 0x80;
    *(u16 *)(param_1 + 0xFC) = t;
    vec.a = t;
    t = *(u16 *)(param_1 + 0xFE) + 0x100;
    *(u16 *)(param_1 + 0xFE) = t;
    vec.b = t;
    vec.c = 0;
    func_80049A1C(&vec, &mtx);

    vec.b = 0;
    vec.a = 0;
    vec.c = 0x100;
    func_80048FBC(&mtx, &vec, &vec);

    D_801B75C8 = vec.a;
    D_801B75B8 = vec.a;
    D_801B75A8 = vec.a;
    D_801B75CC = vec.b;
    D_801B75BC = vec.b;
    D_801B75AC = vec.b;
    D_801B75D0 = vec.c;
    D_801B75C0 = vec.c;
    D_801B75B0 = vec.c;
}
