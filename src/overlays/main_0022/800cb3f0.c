/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3F0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32  func_80017DC4(void *a0, void *a1);
extern void func_80017DF8(s16 *a0, void *a1);
extern void func_80149350(s32 a0, s32 a1, s32 a2);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_80015954(s32 a0, s32 a1);
extern u8 D_800CBCBC[];
extern u8 D_800CBCC4[];

void func_800CB3F0(void *a0) {
    u8 mat[0x20];
    s16 ang[3];
    s32 s3v;
    s32 s2v;
    u16 v;

    s3v = *(s32 *)((s32)a0 + 0x4C);
    s2v = *(s32 *)((s32)a0 + 0x20);
    v = *(u16 *)((s32)a0 + 0x62);

    ang[2] = v;
    ang[1] = v;
    ang[0] = v;

    func_80017DC4(ang, mat);
    func_80017DF8((s16 *)(s2v + 0x10), mat);
    func_80149350(s3v, (s32)D_800CBCBC, (s32)ang);

    *(s32 *)(mat + 0x14) = ang[0];
    *(s32 *)(mat + 0x18) = ang[1];
    *(s32 *)(mat + 0x1C) = ang[2];

    func_8012F14C((s32)mat, (s32)D_800CBCC4, (s32)ang);
    func_80015954((s32)ang, (s32)a0 + 4);
}
