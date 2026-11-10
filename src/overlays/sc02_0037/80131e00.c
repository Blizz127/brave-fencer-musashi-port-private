/* sc02_0037: func_80131E00 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131E00(struct S80131E00*, s32);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131CF4(s32 a0);
extern void func_80131CA8(s32 a0, s32 a1);
extern s32 func_80131CF4(s32 a0);
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int, int);

void func_80131E00(struct S80131E00 *a0, s32 a1) {
    extern void (*D_801840DC[])(struct S80131E00 *a0);
    a0->field_B0 = a1;
    D_801840DC[a1](a0);
}
