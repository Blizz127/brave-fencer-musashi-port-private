/* sc03_0098: func_8012F5F4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131B14();
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
s32 func_80131A34(s32 a0, s32 a1);
void func_80131B14();
void func_80131E00(struct S80131E00 *a0, s32 a1);

void func_8012F5F4(s32 arg0) {
    *(u8 *)(arg0 + 0xC1) = 1;
    if ((*(s32 *)(arg0 + 0xC4) & 2) != 0) {
        func_80131CA8(arg0, 3);
        return;
    }
    ((void (*)(s32))func_80131B14)(arg0);
    if (*(s16 *)(arg0 + 0x76) < 1) {
        func_80131E00((struct S80131E00 *)arg0, 0xC);
        return;
    }
    if (func_80131A34(arg0, 4) != 0) {
        *(u8 *)(arg0 + 0xC2) = 0;
    } else {
        *(s16 *)(arg0 + 0x98) = 0;
        *(u8 *)(arg0 + 0xC2) = 1;
        *(s32 *)(arg0 + 0x1C) = 0x10;
    }
    func_80131CA8(arg0, 3);
}
