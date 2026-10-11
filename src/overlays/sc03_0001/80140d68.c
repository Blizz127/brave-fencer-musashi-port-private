/* sc03_0001: func_80140D68 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { s16 x; s16 y; } Hw4;
typedef struct { u16 f0; s16 f2; } Prim4;
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
typedef struct {
        u32 *ot;
        u32 pad[4];
    } Env_800D29F8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_80140D68;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");

s32 *func_80140D68(out, src, idx, dx, ofs)
    s32 *out;
    Prim4 *src;
    s16 idx;
    s32 dx;
    s16 ofs;
{
    extern Hw4 D_8011516A[];
    extern Env_800D29F8 D_800AE7BC[];
    register u32 mhi __asm__("$8");
    s16 *q;
    s32 a;
    out[0] = 0x04000000;
    *((u8 *)out + 0xC) = 0x70;
    *((u8 *)out + 0xD) = 0x10;
    mhi = 0x64808080;
    out[1] = mhi;
    *(u16 *)((u8 *)out + 0xE) = 0x4056;
    dx -= 0xD;
    q = (s16 *)(ofs * 2 + (s32)src);
    a = (u16)q[0] + (u16)D_8011516A[idx].x;
    a += dx;
    *(s16 *)((u8 *)out + 0x8) = a;
    *(s16 *)((u8 *)out + 0xA) = q[1] - 4;
    *(s16 *)((u8 *)out + 0x12) = 0x10;
    *(s16 *)((u8 *)out + 0x10) = 0x10;
    ((PTag_80140D68 *)out)->addr = ((PTag_80140D68 *)((D_800AE7BC[*(u16 *)&D_800B9A02].ot) + 2))->addr;
    ((PTag_80140D68 *)((D_800AE7BC[*(volatile u16 *)&D_800B9A02].ot) + 2))->addr = (u32)out;
    return out + 5;
}
