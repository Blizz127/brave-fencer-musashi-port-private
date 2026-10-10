/* sc03_0098: func_8016D1D8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { int a[8]; } MTX_L1;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef struct { short vx, vy, vz, pad; } SVEC_L1;
typedef void (*code)(unsigned short *);
struct Fr {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_80167AE0 {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_8016A290 {
    SVEC_8016A290 center;
    SVEC_8016A290 diff;
    s32 pos[3];
    s32 _pad1c;
    s16 mtx[32];
    SVEC_8016A290 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
typedef struct { s16 x, y, z, pad; } SVec_801670E4;
typedef struct {
               u16 cx, cy, cz;
               u16 _p06;
               u16 a8[4];
               s32 pos[3];
               s32 _p1C;
               SVec_801670E4 v[4];
               struct { u8 r, g, b, cd; } col[4];
               u32 code;
               s32 _p54;
               u8 m1[0x20];
               u8 m2[0x20];
} Fr_801670E4;
extern void func_801465C0(void);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_800233CC(void *, unsigned short);
extern void func_80049A1C(void *a0, void *a1);
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_801465C0(void);
extern void func_800233CC(void*, unsigned short);
extern void func_8001CD9C(int, void*);
extern void func_80147324(int a);
extern int func_8005C49C(void);
extern void func_80049A1C(void *a, void *b);
extern void func_80048FBC(void *a, void *b, void *c);

void func_8016D1D8(int param_1) {
    extern u8 D_801C4928[];
    extern u8 D_801C4968[];
    int iVar5;
    int iVar2;
    u16 uVar1;
    unsigned int uVar3;
    short sVar4;
    SVEC_L1 sv;
    MTX_L1 mtx;
    iVar5 = *(int *)(param_1 + 0x34);
    if (*(int *)(param_1 + 0x2c) == 0) {
        D_801C4928[1] = 0xE0;
        D_801C4928[2] = 0xE0;
        D_801C4928[0] = 0xE0;
        D_801C4928[6] = 0;
        D_801C4928[5] = 0;
        D_801C4928[4] = 0;
        iVar5 = ((int (*)(void))func_801465C0)();
        if (iVar5 != 0) {
            int pp;
            *(int *)(param_1 + 0x20) = iVar5;
            ((void (*)(void *, int))func_800233CC)(D_801C4928, 0x28);
            ((void (*)(void *, void *))func_8001CD9C)((void *)iVar5, D_801C4928);
            *(short *)(iVar5 + 0x1a) = 0x1400;
            *(u32 *)(iVar5 + 4) |= 0x50000000;
            pp = *(int *)(param_1 + 0x30);
            *(u16 *)(param_1 + 0x28) = *(u16 *)(pp + 0x36);
            *(u16 *)(param_1 + 0x12) = *(u16 *)(pp + 6);
            *(short *)(param_1 + 0x16) = *(u16 *)(pp + 0xa) - 0x28;
            uVar1 = *(u16 *)(pp + 0xe);
            *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
            *(u16 *)(param_1 + 0x1a) = uVar1;
        }
        *(int *)(param_1 + 0x1c) = 8;
        func_80147324(0x647);
    } else {
        D_801C4968[1] = 0xE0;
        D_801C4968[2] = 0x20;
        D_801C4968[0] = 0x20;
        D_801C4968[5] = 0;
        D_801C4968[6] = 0;
        D_801C4968[4] = 0;
        iVar2 = ((int (*)(void))func_801465C0)();
        if (iVar2 != 0) {
            *(int *)(param_1 + 0x20) = iVar2;
            ((void (*)(void *, int))func_800233CC)(D_801C4968, 0x18);
            ((void (*)(void *, void *))func_8001CD9C)((void *)iVar2, D_801C4968);
            *(u32 *)(iVar2 + 4) |= 0x50000000;
            *(u16 *)(param_1 + 6) = *(u16 *)(iVar5 + 6);
            *(u16 *)(param_1 + 0xa) = *(u16 *)(iVar5 + 0xa);
            *(u16 *)(param_1 + 0xe) = *(u16 *)(iVar5 + 0xe);
            uVar3 = func_8005C49C();
            sv.vx = ((uVar3 & 0x7F) * 8) - 0x80;
            sv.vy = (uVar3 & 0x7F00) >> 3;
            sv.vz = 0;
            func_80049A1C(&sv, &mtx);
            sv.vy = 0;
            sv.vx = 0;
            sv.vz = 0x240;
            func_80048FBC(&mtx, &sv, &sv);
            *(int *)(param_1 + 0x10) = (int)sv.vx << 0xc;
            *(int *)(param_1 + 0x14) = (int)sv.vy << 0xc;
            sVar4 = (uVar3 & 0x3F0) + 0x200;
            *(int *)(param_1 + 0x18) = (int)sv.vz << 0xc;
            *(short *)(iVar2 + 0x1a) = sVar4;
            *(short *)(iVar2 + 0x18) = sVar4;
            *(int *)(param_1 + 0x1c) = 0x10;
            *(short *)(param_1 + 2) = 2;
        }
    }
}
