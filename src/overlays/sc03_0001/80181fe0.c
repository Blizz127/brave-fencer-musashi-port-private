/* sc03_0001: func_80181FE0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_80178BF8();
extern void func_80172710(void);
extern s32 func_80178BF8();
extern void func_80172710(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF8018166C(void *arg0) __asm__("func_8018166C");
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80188D1C(void *);
extern s32 func_80178BF8(void);

s32 func_80181FE0(void *a0)
{
    void *s0 = a0;
    void **v0p;
    u16 v1;
    v0p = (void **)(s0 + 0x64);
    v1 = *(u16 *)(*v0p + 0x2);
    if (v1 != 0x5) {
        return 0;
    }
    if (func_8018739C() == 0) {
        return 0;
    }
    if (func_80188D1C(*v0p) != 0) {
        return 0;
    }
    *(u16 *)(*v0p + 0x2) = 0x6;
    func_80178BF8();
    return (s32)func_80172710;
}
