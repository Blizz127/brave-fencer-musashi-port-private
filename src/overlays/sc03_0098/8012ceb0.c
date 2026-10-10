/* sc03_0098: func_8012CEB0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
s32 func_80133784(s32 arg0, void *arg1, s32 arg2);

s32 func_8012CEB0(s32 a0, s32 a1, s32 a2) {
    s32 sp10[2];
    s32 r;
    s32 v;
    s32 t;
    if ((a2 & 1) != 0) {
        s32 u;
        r = func_80133784((s16)a2, (void *)a0, a1);
        u = *(u8 *)(a1 + 6);
        r |= u;
        if (u == 2 || u == 0x1B) {
            r |= 0x1000;
        }
        return r;
    } else {
        r = func_80133784(0, (void *)a0, a1);
        if (r == 0) {
            return 0;
        }
        v = func_80133784(2, (void *)a1, (s32)sp10);
        if ((v & 0x6000) == 0) {
            return 0;
        }
        v &= 0xFFFF7FFF;
        v |= (r & 0x8000);
        t = *(u8 *)(a1 + 6);
        *(s16 *)(a1 + 2) = *(u16 *)((s32)sp10 + 2);
        v |= t;
        if (t == 2 || t == 0x1B) {
            v |= 0x1000;
        }
        return v;
    }
}
