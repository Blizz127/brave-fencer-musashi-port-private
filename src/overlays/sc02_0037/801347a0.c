/* sc02_0037: func_801347A0 from Druthulu/BFM-decomp
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
typedef struct {
              s16 f0;
              s16 f2;
              s16 f4;
              s16 f6;
} Elem;
typedef struct {
               u16 f0;
               s16 f2;
               s16 f4;
               s16 f6;
               s16 f8;
               s16 fa;
               s16 fc;
               s16 fe;
               s16 f10;
               s16 f12;
               s16 f14;
} S0;
typedef struct {
              u16 f0;
              u16 f2;
              u16 f4;
              u16 f6;
} SVec;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801152A8[];
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
s32 func_80134A28(s32 a0, s32 a1, s32 a2);

s32 func_801347A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern u8 D_801152A8[];
    extern s32 func_80134A28(s32 a0, s32 a1, s32 a2);
    extern s16 * D_801841A0;
    extern SVec * D_8018419C;
    extern SVec * D_801841A4;
    Elem *pElem;
    s32 val;
    s32 iv;
    s32 q;
    s32 dvsr;
    pElem = &((Elem *)arg2)[((S0 *)arg1)->f2];
    val = ((s32 *)arg3)[((S0 *)arg1)->f4];
    if (func_80134A28((s32)pElem, (s32)D_801841A0, val) >= 0) {
        return 0;
    }
    iv = func_80134A28((s32)pElem, (s32)D_8018419C, val);
    if (iv < 0) {
        return 0;
    }
    iv = -iv;
    dvsr = pElem->f2 * 48;
    q = (iv * 48) / dvsr;
    D_801841A4->f0 = D_8018419C->f0;
    D_801841A4->f2 = D_8018419C->f2 + q;
    D_801841A4->f4 = D_8018419C->f4;
    if (func_80134A28((s32)&((Elem *)arg2)[((S0 *)arg1)->f6], (s32)D_801841A4, ((s32 *)arg3)[((S0 *)arg1)->f8]) < -0x2F00) {
        return 0;
    }
    if (func_80134A28((s32)&((Elem *)arg2)[((S0 *)arg1)->fa], (s32)D_801841A4, ((s32 *)arg3)[((S0 *)arg1)->fc]) < -0x2F00) {
        return 0;
    }
    if (func_80134A28((s32)&((Elem *)arg2)[((S0 *)arg1)->fe], (s32)D_801841A4, ((s32 *)arg3)[((S0 *)arg1)->f10]) < -0x2F00) {
        return 0;
    }
    if ((s16)arg0) {
        if (func_80134A28((s32)&((Elem *)arg2)[((S0 *)arg1)->f12], (s32)D_801841A4, ((s32 *)arg3)[((S0 *)arg1)->f14]) < -0x2F00) {
            return 0;
        }
    }
    if ((((S0 *)arg1)->f0 & 0x300) != 0) {
        return 0;
    }
    D_801841A4->f0 = D_8018419C->f0;
    D_801841A4->f4 = D_8018419C->f4;
    (*(Elem*)D_801152A8) = *pElem;
    D_8018419C->f6 = pElem->f2;
    return 1;
}
