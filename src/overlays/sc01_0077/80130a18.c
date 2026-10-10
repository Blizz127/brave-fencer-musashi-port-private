/* sc01_0077: func_80130A18 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int, int);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
s32 func_80133784(s32 arg0, void *arg1, s32 arg2);

void func_80130A18(u8 *a0) {
    s16 b1[4];
    s16 b2[4];
    *(u16 *)(a0 + 0x5C) = *(u16 *)(a0 + 0x5C) & 0xFFFE;
    if (((s32 (*)(int, int))func_80131CA8)((int)a0, 0x34) != 0) {
        return;
    }
    b1[0] = *(u16 *)(a0 + 6);
    b1[1] = *(u16 *)(a0 + 0xA) - 0x10;
    b1[2] = *(u16 *)(a0 + 0xE);
    b2[0] = *(u16 *)(a0 + 6);
    b2[1] = *(u16 *)(a0 + 0xA) + 8;
    b2[2] = *(u16 *)(a0 + 0xE);
    if ((func_80133784(0x11, b1, (s32)b2) & 0x6000) != 0) {
        *(s8 *)(a0 + 0xC1) = 0x11;
        *(s16 *)(a0 + 0xAC) = 0x78;
    }
}
