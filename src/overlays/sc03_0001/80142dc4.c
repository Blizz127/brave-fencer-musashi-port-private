/* sc03_0001: func_80142DC4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern short D_800B9A02;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u16 D_80115116;
extern void func_8012C1B8(void);
extern void func_8001CA1C(s32 a0, s32 a1);
extern void func_8012CAE4(void *a0);
void func_80142B2C(void *arg0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CA1C(s32 a0, s32 a1);
extern void func_80142B2C(void *arg0);
extern int D_8018E948;

void func_80142DC4(int param_1)
{
    int v0;
    *(int *)(param_1 + 0x20) = v0 = ((int (*)(void))func_8012C1B8)();
    if (v0 == 0) {
        ((void (*)(int))func_8012CAE4)(param_1);
    } else {
        ((void (*)(s32, s32))func_8001CA1C)(v0, (s32)&D_8018E948);
        *(short *)(v0 + 0x1a) = 0x1800;
        *(short *)(v0 + 0x18) = 0x1800;
        *(short *)(param_1 + 0xfc) = 0;
        ((void (*)(int))func_80142B2C)(param_1);
    }
}
