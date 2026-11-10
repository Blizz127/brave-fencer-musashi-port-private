/* sc03_0098: func_80137DD4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { u32 addr : 24; u32 len : 8; u8 r0, g0, b0, code; } P_TAG_80137DD4;
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void *func_80010A08(s32);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void *func_80010A08(s32);
extern s16 D_800B9A02;
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
void func_80137030(s16 a0, s16 a1);
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void func_80137614(s32 a0, s32 a1, s32 a2);
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
s32 aF80137614(s32 a0, s32 a1, s32 a2) __asm__("func_80137614");
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_801376E8(int a0, int a1);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);
extern void func_80139BE0(s32 a0);
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
void * aF801376E8(int a0, int a1) __asm__("func_801376E8");
void *aF801376E8(int a0, int a1) __asm__("func_801376E8");
void func_801377B4(s32 a0, s32 a1, s32 a2);
extern s32 D_801269F0;
extern int D_801269F0;
extern short D_800B9A02;
extern int D_801269F0;
extern void *func_80010A08(s32);
extern void func_80137FD8(s32 a0, s32 a1, s32 a2, s32 a3);
void func_80137FD8(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80137DD4(s32 ent, u8 *arg, u8 *work) {
    register s32 t __asm__("$4");
    s32 d, c, c1, sub, y;
    u32 b;
    P_TAG_80137DD4 *q, *r;
    {
        register u32 h12 __asm__("$2"), h16 __asm__("$3");
        h12 = *(u16 *)(ent + 0x12);
        h16 = *(u16 *)(ent + 0x16);
        t = h12 - h16;
    }
    d = t;
    if ((s16)t < 0) {
        register s32 e __asm__("$2");
        e = t + 1;
        d = (u32)*(u16 *)(ent + 0x2e) + e;
    }
    b = *(volatile u8 *)(ent + 0x1f);
    c = (s8)b;
    sub = d - (u32)*(u8 *)(ent + 0x21);
    c1 = c + 1;
    y = (u32)*(u16 *)(ent + 0x32) + (s16)(sub + c1) * 0xe;
    q = (P_TAG_80137DD4 *)func_80010A08(0x48);
    *(u8 *)(arg + 3) = 0;
    func_80137FD8(ent, (s32)arg, (s32)q, (s16)y);
    q->addr = ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr;
    ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr = (u32)q;
    q = (P_TAG_80137DD4 *)((u8 *)q + 0x24);
    *(u8 *)(arg + 3) = 1;
    func_80137FD8(ent, (s32)arg, (s32)q, (s16)y);
    q->addr = ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr;
    ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr = (u32)q;
    r = (P_TAG_80137DD4 *)func_80010A08(8);
    r->len = 1;
    *(u32 *)((u8 *)r + 4) = 0xe100000a;
    r->addr = ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr;
    ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr = (u32)r;
}
