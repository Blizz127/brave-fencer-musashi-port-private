/* sc02_0037: func_80135EB0 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80135EB0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80126720[];
extern u8 D_801152A8[];
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern s32 func_80047E98(void *a0, void *a1);
extern u8 D_8018419C;
extern u8 D_801841A0;
extern s16 *D_801841A4;
extern u8 D_801841A8;
extern s32 D_801150D8;
extern u8 D_80126720[];
extern s32 func_80047E98(void *a0, void *a1);
extern s32 func_801365B8(void *arg0, s32 arg1, s32 arg2);
extern s32 func_80136334(void *arg0, s32 arg1, s32 arg2);
extern s32 func_80136824(s32, s32, s32);
s32 func_80136334(void *arg0, s32 arg1, s32 arg2);
s32 func_801365B8(void *arg0, s32 arg1, s32 arg2);
s32 func_80136824(s32 arg0, s32 arg1, s32 arg2);

s32 func_80135EB0(void *arg0, s32 arg1_) {
    extern u8 D_801152A8[];
    extern s16 D_801152AA;
    extern s16 D_801152AC;
    extern s16 D_80126722;
    extern s16 D_80126724;
    register s32 arg1 __asm__("$19") = arg1_;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 m1;
    s32 m2;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 n1;
    s32 n2;
    s32 r;
    s32 sv;
    register s32 w __asm__("$5");
    void *q;
    t1 = (*(s16 **)&D_8018419C)[0];
    if (t1 < (*(s16 *)((s8 *)(arg0) + (4)))) {
        m1 = 1;
    } else {
        m1 = ((*(s16 *)((s8 *)(arg0) + (6))) < t1) << 1;
    }
    t2 = (*(s16 **)&D_8018419C)[2];
    if (t2 < (*(s16 *)((s8 *)(arg0) + (0xC)))) {
        m1 |= 4;
    } else if ((*(s16 *)((s8 *)(arg0) + (0xE))) < t2) {
        m1 |= 8;
    }
    t3 = (*(s16 **)&D_8018419C)[1];
    if (t3 < (*(s16 *)((s8 *)(arg0) + (8)))) {
        m2 = 0x10;
    } else {
        m2 = ((*(s16 *)((s8 *)(arg0) + (0xA))) < t3) << 5;
    }
    if ((m1 | m2) == 0) {
        u16 *ac;
        s16 *b4;
        s32 c0;
        s32 c1;
        s32 h0;
        s32 h1;
        ac = *(u16 **)&D_8018419C;
        b4 = D_801841A4;
        c0 = ac[0];
        b4[0] = c0;
        h0 = ((*(s16 *)((s8 *)(arg0) + (4))) + (*(s16 *)((s8 *)(arg0) + (6)))) >> 1;
        D_801152AA = 0;
        (*(s16 *)D_80126720) = h0;
        (*(s16 *)D_801152A8) = c0 - h0;
        __asm__ __volatile__("");
        c1 = ac[2];
        b4[2] = c1;
        h1 = ((*(s16 *)((s8 *)(arg0) + (0xC))) + (*(s16 *)((s8 *)(arg0) + (0xE)))) >> 1;
        D_80126724 = h1;
        D_801152AC = c1 - h1;
        __asm__ __volatile__("");
        b4[1] = ac[1];
        D_80126722 = ((*(s16 *)((s8 *)(arg0) + (8))) + (*(s16 *)((s8 *)(arg0) + (0xA)))) >> 1;
        func_80047E98(D_801152A8, D_801152A8);
        D_801150D8 |= 1;
        return 1;
    }
    t4 = (*(s16 **)&D_801841A0)[0];
    if (t4 < (*(s16 *)((s8 *)(arg0) + (4)))) {
        n1 = 1;
    } else {
        n1 = ((*(s16 *)((s8 *)(arg0) + (6))) < t4) << 1;
    }
    t5 = (*(s16 **)&D_801841A0)[2];
    if (t5 < (*(s16 *)((s8 *)(arg0) + (0xC)))) {
        n1 |= 4;
    } else if ((*(s16 *)((s8 *)(arg0) + (0xE))) < t5) {
        n1 |= 8;
    }
    t6 = (*(s16 **)&D_801841A0)[1];
    if (t6 < (*(s16 *)((s8 *)(arg0) + (8)))) {
        n2 = 0x10;
    } else {
        n2 = ((*(s16 *)((s8 *)(arg0) + (0xA))) < t6) << 5;
    }
    if (((m1 | m2) & (n1 | n2)) != 0) {
        goto ret0;
    }
    {
        u16 *b0 = *(u16 **)&D_801841A0;
        u16 *ac = *(u16 **)&D_8018419C;
        s16 *b8 = *(s16 **)&D_801841A8;
        b8[0] = b0[0] - ac[0];
        b8[1] = b0[1] - ac[1];
        b8[2] = b0[2] - ac[2];
    }
    switch (m1) {
    case 4:
        q = arg0;
        sv = (*(s16 *)((s8 *)(arg0) + (0xC)));
        w = arg1 << 16;
        goto L288;
    case 1:
        r = func_801365B8(arg0, (s16) arg1, (*(s16 *)((s8 *)(arg0) + (4))));
        __asm__ __volatile__("");
        goto done;
    case 2:
        r = func_801365B8(arg0, (s16) (arg1 | 1), (*(s16 *)((s8 *)(arg0) + (6))));
        __asm__ __volatile__(" ");
        goto done;
    case 5:
        if (func_80136334(arg0, (s16) arg1, (*(s16 *)((s8 *)(arg0) + (0xC)))) != 0) {
            return 1;
        }
        r = func_801365B8(arg0, (s16) arg1, (*(s16 *)((s8 *)(arg0) + (4))));
        goto done;
    case 6:
        if (func_80136334(arg0, (s16) arg1, (*(s16 *)((s8 *)(arg0) + (0xC)))) != 0) {
            return 1;
        }
        r = func_801365B8(arg0, (s16) (arg1 | 1), (*(s16 *)((s8 *)(arg0) + (6))));
        goto done;
    case 9:
        if (func_801365B8(arg0, (s16) arg1, (*(s16 *)((s8 *)(arg0) + (4)))) != 0) {
            return 1;
        }
    case 8:
        q = arg0;
        sv = (*(s16 *)((s8 *)(arg0) + (0xE)));
        w = (arg1 | 1) << 16;
    L288:
        r = func_80136334(q, w >> 16, sv);
        goto done;
    ret0:
        return 0;
    case 10:
        if (func_801365B8(arg0, (s16) (arg1 | 1), (*(s16 *)((s8 *)(arg0) + (6)))) != 0) {
            return 1;
        }
        r = func_80136334(arg0, (s16) (arg1 | 1), (*(s16 *)((s8 *)(arg0) + (0xE))));
    done:
        if (r != 0) {
            return 1;
        }
    case 0:
        if (m2 == 0) {
            goto ret0;
        }
        if (m2 == 0x10) {
            if (((s32 (*)(void *, s32, s32))func_80136824)(arg0, (s16) arg1, (*(s16 *)((s8 *)(arg0) + (8)))) == 0) {
                goto ret0;
            }
        } else {
            if (((s32 (*)(void *, s32, s32))func_80136824)(arg0, (s16) (arg1 | 1), (*(s16 *)((s8 *)(arg0) + (0xA)))) == 0) {
                goto ret0;
            }
        }
    default:
        return 1;
    }
}
