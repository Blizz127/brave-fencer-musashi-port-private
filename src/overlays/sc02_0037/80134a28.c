/* sc02_0037: func_80134A28 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern void *memcpy(void *, const void *, u32);

s32 func_80134A28(s32 a0, s32 a1, s32 a2) {
    return *(s16*)(a0 + 0x0) * *(s16*)(a1 + 0x0)
         + *(s16*)(a0 + 0x2) * *(s16*)(a1 + 0x2)
         + *(s16*)(a0 + 0x4) * *(s16*)(a1 + 0x4)
         + a2;
}
