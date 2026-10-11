/* sc03_0001: func_8017DB6C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, s32);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32, s32);
extern s32 D_801BE2F0;
extern s32 func_8012C354(s32 arg0, s32 arg1);
extern s32 func_80143970(s32 arg0);
extern void func_8012B23C(s32 arg0);

void func_8017DB6C(s32 arg0) {
    extern s32 D_80190FDC;
    extern s32 D_801BE2F0;
    s32 s0 = arg0;
    if (func_8012C354(arg0, (s32)&D_80190FDC) == 0) {
        return;
    }
    *(u8 *)(s0 + 0xC0) = 1;
    *(s32 *)(s0 + 0xB4) = -1;
    *(u8 *)(s0 + 0xC1) = 0;
    *(s32 *)(s0 + 0xC4) = 1;
    if (((u32)func_80029504() < 0x14) || ((u32)func_80029504() >= 0x46) ||
        (((func_80029178(0xE5) & 0xFF) != 0) && (func_80029504() != 0x3C))) {
        func_8012C218((void *)s0);
    } else {
        func_80143970(s0);
        *(s16 *)(s0 + 2) = 1;
        func_8012B23C(s0);
        func_8012A828(s0, (s32)&D_801BE2F0);
        *(s32 *)(s0 + 0x1C) = 1;
    }
}
