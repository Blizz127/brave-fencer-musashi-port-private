/* sc02_0037: func_80133784 from Druthulu/BFM-decomp
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
typedef struct { u16 f0, f2, f4; s16 f6; } Box_80133784;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80047D3C(s32 a0);
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
extern void *memcpy(void *, const void *, u32);
s32 func_80133AB0(s16 flag, s16 x, s16 y, s32 arg3);

s32 func_80133784(s32 arg0, void *arg1, s32 arg2) {
    extern s32 D_801C8418;
    extern s32 func_80047D3C(s32);
    extern s32 func_80133AB0(s16, s16, s16, s32);
    extern Box_80133784 * D_8018419C;
    extern Box_80133784 * D_801841A0;
    extern s16 D_801C8424;
    extern u16 D_801C8428;
    s32 s1;
    s32 s2;
    register s16 s3 __asm__("$19");
    register s32 s4 __asm__("$20");
    s16 a0v;
    register s16 arg0s __asm__("$21");
    s32 dx, dy, dz;
    s32 r, ret;
    a0v = ((s16)arg0);
    s1 = 0;
    s3 = 0;
    s4 = 0;
    s2 = 0;
    arg0s = a0v;
    D_8018419C->f6 = -0x7FFF;
    D_801841A0->f6 = 0x7FFF;
    D_8018419C->f0 = ((Box_80133784 *)arg1)->f0;
    D_8018419C->f4 = ((Box_80133784 *)arg1)->f4;
    D_801841A0->f0 = ((Box_80133784 *)arg2)->f0;
    D_801841A0->f4 = ((Box_80133784 *)arg2)->f4;
    D_801C8428 = 0;
    D_801C8424 = 0;
    if ((s16)a0v == 0) {
        s16 sx = ((Box_80133784 *)arg2)->f0 - ((Box_80133784 *)arg1)->f0;
        s16 sy = ((Box_80133784 *)arg2)->f2 - ((Box_80133784 *)arg1)->f2;
        s16 sz = ((Box_80133784 *)arg2)->f4 - ((Box_80133784 *)arg1)->f4;
        if (sx == 0 && sy == 0) {
            s32 zt = (sz == 0);
            __asm__("addu %0,%1,$zero" : "=r"(s2) : "r"(zt));
        }
        D_8018419C->f2 = ((Box_80133784 *)arg1)->f2 - 4;
        r = func_80047D3C(sx * sx + sz * sz);
        if (r < 3) {
            r = 4;
        } else if (r < 5) {
            r += 1;
        }
        D_801841A0->f2 = ((Box_80133784 *)arg2)->f2 + r + 1;
    } else {
        D_8018419C->f2 = ((Box_80133784 *)arg1)->f2;
        if ((s16)a0v == 2) {
            D_801841A0->f0 = D_8018419C->f0;
            D_801841A0->f2 = D_8018419C->f2 + 6;
            s2 = 1;
            D_801841A0->f4 = D_8018419C->f4;
        } else {
            D_801841A0->f2 = ((Box_80133784 *)arg2)->f2;
        }
    }
    while (1) {
        s32 ret0;
        register s32 retc __asm__("$3");
        ret0 = func_80133AB0(arg0s, (s16)D_8018419C->f0, (s16)D_8018419C->f4, (*(s32*)&D_801C8418));
        __asm__("addu %0,%1,$zero" : "=r"(retc) : "r"(ret0));
        ret = retc;
        if (ret == 0) goto after;
        s4 |= ret;
        if (s2 != 0) goto after;
        {
            s16 oldc = s3;
            s3 = s3 + 1;
            if (oldc >= 5) break;
        }
    }
    D_801841A0->f0 = D_8018419C->f0;
    D_801841A0->f2 = D_8018419C->f2;
    s1 = 0x2000;
    D_801841A0->f4 = D_8018419C->f4;
    goto store_out;
after:
    if ((s16)s4 != 0 || D_801C8424 != 0) {
        s16 t;
        __asm__ __volatile__("" :: "r"(s4));
        t = D_8018419C->f6;
        if (t >= -0xBCB) {
            if (t < -0x578) {
                s1 |= 0x4000;
            } else {
                s1 |= 0x8000;
            }
        }
        if ((s16)D_801841A0->f6 < -0xBCB) {
            s1 |= 0x2000;
        }
    store_out:
        ((Box_80133784 *)arg2)->f0 = D_801841A0->f0;
        ((Box_80133784 *)arg2)->f2 = D_801841A0->f2;
        ((Box_80133784 *)arg2)->f4 = D_801841A0->f4;
        ((Box_80133784 *)arg2)->f6 = D_801C8428;
        return s1 & 0xFFFF;
    }
    ((Box_80133784 *)arg2)->f6 = D_801C8428;
    return 0;
}
