/* sc02_0037: func_80131D68 from Druthulu/BFM-decomp
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
extern void func_8012C218(void *a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131E00(struct S80131E00*, s32);
extern void func_80131CA8(int a0, int a1);
extern void func_8002A04C(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_80131CF4(s32 a0);
extern void func_80131CA8(s32 a0, s32 a1);
extern s32 func_80131CF4(s32 a0);
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_8002A04C(s32 a0);
extern void func_8012C218(void *a0);
void func_80131E00(struct S80131E00 *a0, s32 a1);

int func_80131D68(int a0, int a1)
{
    s32 s0 = a0;
    s32 c = a1 & 0xFF;
    if (c == 2 || c == 0x1B) {
        func_80131E00((struct S80131E00 *)s0, 0x12);
        return 1;
    }
    if (c == 0x1A || c == 0x1C) {
        if (((s32 (*)(int, int))func_80131CA8)(s0, 0x11) != 0) {
            return 1;
        }
        if (*(s32 *)(s0 + 0x78) != 0) {
            func_8002A04C(s0);
        }
        func_8012C218((void *)s0);
        return 1;
    }
    return 0;
}
