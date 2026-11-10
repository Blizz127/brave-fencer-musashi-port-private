/* sc02_0037: func_80143D28 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013F350.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct {
    u8 pad[8];
    u16 f8;
    u16 fa;
} MatEntry;
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
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern s32 func_8012BEE8(s32);
extern int func_8012BEE8(int);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void func_80048FBC(void *m, Svec_801372B0 *in, Svec_801372B0 *out);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern short D_800B9A02;
extern short D_800B9A02;
extern u16 D_80115116;
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern void *memcpy(void *, const void *, u32);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_80048FBC(void*, Svec_801372B0*, Svec_801372B0*);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);

void func_80143D28(s32 param_1) {
    extern MatEntry D_80185568[];
    register s32 iVar3 __asm__("$18") = *(s32 *)(param_1 + 0x20);
    s32 iVar2 = *(s32 *)(param_1 + 0x64);
    MatEntry *p = &D_80185568[*(s16 *)(param_1 + 0x70)];
    s32 sVar4;
    s32 iVar1;
    *(s16 *)(iVar3 + 0x14) = p->f8;
    *(u16 *)(iVar3 + 0x12) = *(u16 *)(iVar3 + 0x12) + p->fa;
    sVar4 = 0x1000;
    ((void (*)(void *, void *, void *))func_80048FBC)((void *)(*(s32 *)(param_1 + 0x20) + 0x34), p, (void *)(param_1 + 0x50));
    if (*(s16 *)(param_1 + 0xfe) == 0 &&
        (iVar2 == 0 || *(s16 *)(iVar2 + 0x36) != *(s16 *)(param_1 + 0xfc) ||
         *(u8 *)(iVar2 + 0xc1) != 6)) {
        if (0x10 < *(s32 *)(param_1 + 0x1c)) {
            *(s32 *)(param_1 + 0x1c) = 0x10;
        }
        *(s16 *)(param_1 + 0xfe) = 1;
    }
    iVar1 = *(s32 *)(param_1 + 0x1c);
    if (iVar1 < 0x11) {
        sVar4 = iVar1 << 8;
    }
    if (0x73 < iVar1) {
        sVar4 = (0x78 - iVar1) << 10;
    }
    *(s16 *)(iVar3 + 0x18) = *(s16 *)(iVar3 + 0x1a) = *(s16 *)(iVar3 + 0x1c) = sVar4;
    if (func_8012BEE8(param_1)) {
        func_8012C218((void *)param_1);
    }
}
