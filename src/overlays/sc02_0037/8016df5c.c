/* sc02_0037: func_8016DF5C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8016AE5C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { s32 w[8]; } Blk20;
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { s32 w0, w4, w8, wC; s16 h10, hpad; s32 t0, t1, t2; } Mat32;
typedef struct { s32 w[8]; } Blk20_8016DF5C;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
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
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern Mat32 D_800AE620;
extern void func_8004A0DC(int r, void *m);
extern s16 D_800B9A02;
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void func_80048FBC(void *m, Svec_801372B0 *in, Svec_801372B0 *out);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_800233CC(void *, unsigned short);
extern s32 func_8005C49C(void);
extern void func_80048FBC(void*, Svec_801372B0*, Svec_801372B0*);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 D_80127098;
extern s32 D_80127094;
extern s32 D_80127090;
extern void func_801465C0(void);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 D_8011D030;
extern void func_80146C3C(u8 *a0);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;
extern int func_8005C49C(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 aD_80127090 __asm__("D_80127090");
extern s32 aD_80127094 __asm__("D_80127094");
extern s32 aD_80127098 __asm__("D_80127098");
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_8001CD50(s32 a0, s32 a1);
void func_80146C3C(u8 *a0);
extern void func_80146C3C();
extern void func_80146C3C(u8*);
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_80146C3C(u8*);
extern void func_80146C3C(u8*);
extern void func_801465C0(void);
extern void func_80146C3C(u8*);
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_80146C3C(u8*);
extern void func_801465C0(void);
extern void func_800233CC(void*, unsigned short);
extern int func_8005C49C(void);
extern void func_80048FBC(void*, Svec_801372B0*, Svec_801372B0*);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_80146C3C();
extern void func_80146C3C(u8*);
extern void func_80146C3C(u8*);
extern void func_801465C0(void);
extern void func_80146C3C(u8*);
void func_80146C3C(u8 *a0);
extern void func_80146C3C();
extern void func_80146C3C(u8*);
extern void func_80146C3C();
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_80146C3C(u8*);
void func_8016E3CC(s32 a0);

void func_8016DF5C(s32 param_1)
{
    extern Blk20 aD800AE620 __asm__("D_800AE620");
    extern s32 D_8011D030;
    extern u16 D_80126B5E;
    extern u16 D_80126B62;
    extern u16 D_80126B66;
    extern void func_8016E3CC(s32);
    extern void func_8004A0DC(s32 a0, void *a1);
    extern u8 D_801C91F0;
    extern u8 D_801C91F1;
    extern u8 D_801C91F2;
    extern u8 D_801C91F4;
    extern u8 D_801C91F5;
    extern u8 D_801C91F6;
    s32 iVar8;
    short sVar1;
    iVar8 = *(s32 *)((u8 *)((void *)param_1) + 0x34);
    if ((*(u32 *)((u8 *)((void *)param_1) + 0x2c) & 0x8000) == 0) {
        unsigned short uVar7 = 0;
        u16 *psVar6 = (u16 *)&D_8011D030;
        s32 iNew;
        s32 base;
        do {
            if (psVar6 != (u16 *)((void *)param_1) && (*psVar6 == 0x41 || *psVar6 == 0x48)) {
                ((void (*)(void *))func_80146C3C)(psVar6);
            }
            uVar7++;
            psVar6 += 0x2c;
        } while (uVar7 < 0x1e);
        iNew = ((s32(*)())func_801465C0)();
        if (iNew == 0) {
            return;
        }
        base = (s32)&D_801C91F0;
        D_801C91F2 = 0xc0;
        *(u8 *)base = 0xc0;
        D_801C91F1 = 0;
        D_801C91F6 = 0;
        D_801C91F5 = 0;
        D_801C91F4 = 0;
        ((void(*)(void *, unsigned short))func_800233CC)((void *)base, 0x40);
        func_8001CD50(iNew, base);
        *(s32 *)(iNew + 0x34) = (s32)((u8 *)((void *)param_1) + 0x38);
        *(s16 *)(iNew + 0x1a) = 0;
        *(s16 *)(iNew + 0x18) = 0;
        *(u32 *)(iNew + 4) = *(u32 *)(iNew + 4) | 0x50000000;
        ((void (*)(void *))func_8016E3CC)(((void *)param_1));
        {
            register s32 t10 __asm__("$3");
            t10 = 0x10;
            *(s32 *)((u8 *)((void *)param_1) + 0x20) = iNew;
            *(s32 *)((u8 *)((void *)param_1) + 0x1c) = t10;
        }
        sVar1 = *(u16 *)((u8 *)((void *)param_1) + 2) + 1;
    } else {
        short asStack_60[20];
        Blk20_8016DF5C localMatrix;
        s32 uVar2;
        asStack_60[0] = 0;
        asStack_60[1] = 0;
        asStack_60[2] = 0x20;
        localMatrix = (*(Blk20_8016DF5C*)&aD800AE620);
        uVar2 = ((s32(*)())func_8005C49C)();
        func_8004A0DC((uVar2 & 0x7f00) >> 3, &localMatrix);
        func_80048FBC(&localMatrix, asStack_60, asStack_60);
        *(s16 *)((u8 *)((void *)param_1) + 6) = D_80126B5E + asStack_60[0];
        *(s16 *)((u8 *)((void *)param_1) + 0xa) = D_80126B62 - ((u16)uVar2 & 0x3f);
        *(s16 *)((u8 *)((void *)param_1) + 0xe) = D_80126B66 + asStack_60[2];
        *(Blk20_8016DF5C *)((u8 *)((void *)param_1) + 0x38) = *(Blk20_8016DF5C *)((u8 *)iVar8 + 0x38);
        *(s32 *)((u8 *)((void *)param_1) + 0x2c) = 0x1000;
        *(s32 *)((u8 *)((void *)param_1) + 0x30) = 0xff;
        *(s32 *)((u8 *)((void *)param_1) + 0x1c) = 0x10;
        __asm__ __volatile__("" ::: "memory");
        sVar1 = 4;
    }
    *(s16 *)((u8 *)((void *)param_1) + 2) = sVar1;
}
