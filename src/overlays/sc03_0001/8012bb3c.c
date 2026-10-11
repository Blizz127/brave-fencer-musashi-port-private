/* sc03_0001: func_8012BB3C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 x, s32 y);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8012BB3C(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    s32 a;
    register s32 div __asm__("$16");
    s32 q;
    s32 d;
    s32 ang;
    s32 diff;
    u32 cur;
    a = arg2;
    div = arg3;
    ang = func_8004CFEC(*(s16 *)(arg0 + 0xA) - *(s16 *)(arg1 + 0xA),
                 *(s16 *)(arg1 + 0x2) - *(s16 *)(arg0 + 0x2));
    ang = ang - 0x400;
    __asm__ __volatile__("" : : "r"(ang));
    div = (s16)div;
    a = a & 0xFFF;
    cur = ang & 0xFFF;
    if (a == cur) {
        d = 0;
    } else {
        s32 t;
        diff = cur - a;
        if (0x800 < diff) {
            t = a + 0x1000;
            diff = cur - t;
        }
        if (diff < -0x800) {
            t = a - 0x1000;
            diff = cur - t;
        }
        if (diff >= 0) {
            q = diff / div;
            if (q == 0) {
                q = 1;
            }
        } else {
            q = diff / div;
            if (q == 0) {
                q = -1;
            }
        }
        d = q;
    }
    return (s16)d;
}
