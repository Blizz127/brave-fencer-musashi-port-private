/* sc02_0037: func_801300F4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
s32 func_8012BCCC(s32 a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131A34(s32 a0, s32 a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);
extern s32 func_80131A34(s32, s32);
extern s32 func_8012BCCC(s32);
extern s32 func_80131AC8(void *a0);
extern void func_80131CA8(int a0, int a1);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);

void func_801300F4(s32 a0) {
    s32 done = 0;
    s32 r;
    *(u8 *)(a0 + 0xC1) = 0xD;
    if ((*(u32 *)(a0 + 0xB4) & 0x2000) != 0) {
        *(u16 *)(a0 + 0x5C) = 0;
        *(s32 *)(a0 + 0x1C) = 0x1E;
        *(u16 *)(a0 + 0x98) = 0;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0;
        r = func_80131A34(a0, 0x27);
        if (r != 0) {
            *(u8 *)(a0 + 0xC3) = 1;
        } else {
            *(u8 *)(a0 + 0xC3) = 0;
        }
        r = func_8012BCCC(a0);
        if (r < 0x9000) {
            r = ((s32 (*)(s32, s32))func_80131AC8)(a0, 0x30);
            done = 1;
            if (r != 0) goto skip;
            ((s32 (*)(s32, s32))func_80131AC8)(a0, 0x31);
        } else {
            r = ((s32 (*)(s32, s32))func_80131AC8)(a0, 0x31);
            done = 1;
            if (r != 0) goto skip;
            ((s32 (*)(s32, s32))func_80131AC8)(a0, 0x30);
        }
        done = 1;
    }
skip:
    r = ((s32 (*)(s32, s32))func_80131CA8)(a0, 0x25);
    if (r != 0) {
        done = 1;
    }
    if (!done) {
        ((void (*)(s32, s32))func_80131E00)(a0, 6);
    }
}
