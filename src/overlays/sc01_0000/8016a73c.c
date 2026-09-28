/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A73C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Blk20;
typedef struct Mat_8016A73C { int w[8]; } Mat_8016A73C;
typedef struct SubB_8016A73C { char pad[0x20]; int unk20; } SubB_8016A73C;
typedef struct SubA_8016A73C { char pad[0x34]; SubB_8016A73C *unk34; } SubA_8016A73C;
typedef struct Obj_8016A73C {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    char pad10[0x24];   /* 0x10 .. 0x33 */
    SubA_8016A73C *unk34;         /* 0x34 */
    Mat_8016A73C mat;             /* 0x38 .. 0x57 */
} Obj_8016A73C;
extern Blk20 D_800AE620;
extern s32 func_8005C49C(void);
extern void func_80048EAC(void *a0, void *a1);
extern void func_80049A1C(void *a0, void *a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);

s32 func_8016A73C(s32 arg0) {
    int sp10[8];
    short v[3];   /* sp30, sp32, sp34 */
    int r;
    short tmp;

    r = ((int(*)())func_8005C49C)();
    v[1] = ((r & 0x7F) << 4) + 0x400;
    v[0] = ((unsigned)(r & 0x7F00) >> 5) - 0x300;
    v[2] = 0;
    ((void(*)(short *, void *))func_80049A1C)(v, sp10);
    ((void(*)(int, void *))func_80048EAC)(((Obj_8016A73C *)arg0)->unk34->unk34->unk20 + 0x34, sp10);
    v[0] = 0;
    v[1] = 0;
    v[2] = -0x50;
    ((int(*)(void *, short *, short *))func_80048FBC)(sp10, v, v);

    ((Obj_8016A73C *)arg0)->mat = (*(Mat_8016A73C*)&D_800AE620);

    tmp = ((Obj_8016A73C *)arg0)->unk6 + v[0];
    ((Obj_8016A73C *)arg0)->unk6 = tmp;
    ((Obj_8016A73C *)arg0)->mat.w[5] = tmp;
    tmp = ((Obj_8016A73C *)arg0)->unkA + v[1];
    ((Obj_8016A73C *)arg0)->unkA = tmp;
    ((Obj_8016A73C *)arg0)->mat.w[6] = tmp;
    tmp = ((Obj_8016A73C *)arg0)->unkE + v[2];
    ((Obj_8016A73C *)arg0)->unkE = tmp;
    ((Obj_8016A73C *)arg0)->unk2 = ((Obj_8016A73C *)arg0)->unk2 + 1;
    ((Obj_8016A73C *)arg0)->mat.w[7] = tmp;
}
