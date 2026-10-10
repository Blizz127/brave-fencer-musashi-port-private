/* sc03_0098: func_8012FC30 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A5F8(void (*a0)(void), s32 a1);
void func_8012B23C(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131B14();
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131B14();
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131A34(s32 a0, s32 a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131B14();
extern void func_8012B23C(s32 a0);
extern s32 func_80131A34(s32, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
s32 func_80131A34(s32 a0, s32 a1);
void func_80131B14();

void func_8012FC30(s32 a0) {
    *(s8 *)(a0 + 0xC1) = 0xA;
    if (*(s32 *)(a0 + 0xB4) & 0x400) {
        func_80131B14();
        *(s8 *)(a0 + 0xC2) = 0;
        *(u16 *)(a0 + 0x98) = 0;
        func_8012B23C(a0);
        func_80131A34(a0, 8);
        func_8002D4C8(0xA74, 0);
    }
    func_80131CA8(a0, 0x1A);
}
