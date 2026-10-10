/* sc01_0077: func_801842C8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef struct { u8 b[8]; } Blk8;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012CBA4(s32 a0);
extern s32 func_8012CBA4(s32);
extern int func_8012BEE8(int a0);
extern s32 func_8012CBA4();

void func_801842C8(s32 a0) {
    typedef struct { s8 c[8]; } Blk8;
    extern s32 func_8012CBA4(s32);
    extern s32 func_8012BEE8(s32);
    s32 a3;
    s32 v0;
    a3 = *(s32 *)(a0 + 0xCC);
    if (a3 != 0) {
        *(s16 *)(a3 + 0x18) = 0x1800;
        *(u16 *)(a3 + 0x2C) |= 0x10;
        v0 = *(s32 *)(a0 + 0x20);
        *(Blk8 *)(a3 + 8) = *(Blk8 *)(v0 + 8);
        *(u16 *)(a3 + 0xA) -= 0x10;
        *(u16 *)(a3 + 0x10) = *(u16 *)(a3 + 0x10) + *(s16 *)(a0 + 0x1A) * -0x10;
    }
    if (*(u16 *)(a0 + 0x34) != 0 && *(u16 *)(a0 + 0x34) == 1) {
        if (*(s32 *)(a0 + 0x1C) >= 6) {
            *(s32 *)(a0 + 0x18) -= 0x10000;
        }
        func_8012CBA4(a0);
        if (func_8012BEE8(a0) != 0) {
            *(s16 *)(a0 + 2) = 3;
            *(u16 *)(a0 + 0x34) = 0;
            *(s32 *)(a0 + 0x18) = 0;
            *(u16 *)(a0 + 0x5C) = 0x800;
        }
    }
}
