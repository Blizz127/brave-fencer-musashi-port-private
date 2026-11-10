/* sc02_0037: func_8013240C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void *memcpy(void *, const void *, u32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131CF4(s32 a0);
extern void func_80131CA8(s32 a0, s32 a1);
extern s32 func_80131CF4(s32 a0);
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void func_801325B8(int a0, int a1, int a2, int a3, int a4);
extern void func_801325B8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void func_801325B8(int dst, int src, int m0, int mm, int arg5);

void func_8013240C(s32 a0) {
    s32 *node;
    s32 ent;
    s32 v;
    s16 h6;
    ent = *(s32 *)(a0 + 0x0) + (*(s16 *)(a0 + 0x4) << 3);
    node = (s32 *)*(s32 *)(ent + 0);
    *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0xC) & 0xFFFF3FFF;
    if ((s32)node == -1) {
        *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0xC) | 0x4000;
        return;
    }
    if (*(s16 *)(ent + 0x6) < 0) {
        v = 0x1000 - ((*(s16 *)(a0 + 0x6) << 12) / *(s16 *)(ent + 0x4));
    } else {
        v = (*(s16 *)(a0 + 0x6) << 12) / *(s16 *)(ent + 0x4);
    }
    func_801325B8(*(s32 *)(a0 + 0x8), node[0], node[1], node[2], v);
    h6 = *(s16 *)(ent + 0x6);
    if (h6 < 0) {
        *(s16 *)(a0 + 0x6) = *(u16 *)(a0 + 0x6) - h6;
    } else {
        *(s16 *)(a0 + 0x6) = *(u16 *)(a0 + 0x6) + h6;
    }
    if (*(s16 *)(a0 + 0x6) < *(s16 *)(ent + 0x4)) {
        return;
    }
    *(s16 *)(a0 + 0x6) = 0;
    *(s16 *)(a0 + 0x4) = *(u16 *)(a0 + 0x4) + 1;
    {
        s32 *p = (s32 *)((*(s16 *)(a0 + 0x4) << 3) + *(s32 *)(a0 + 0x0));
        s32 w = p[0];
        s32 c;
        if (w != -1) {
            if (w != 0) {
                return;
            }
            *(s16 *)(a0 + 0x4) = 0;
            c = *(s32 *)(a0 + 0xC) | 0x8000;
        } else {
            c = *(s32 *)(a0 + 0xC) | 0x4000;
        }
        *(s32 *)(a0 + 0xC) = c;
    }
}
