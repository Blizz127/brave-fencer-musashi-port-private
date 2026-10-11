/* sc03_0001: func_8018CF90 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8012A568(void (*a0)(void));
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_8012A828(s32, s32);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 arg0, s32 arg1);
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(s32, s32);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern s32 func_8018D088(void *a0);
s32 func_8018D088(void *a0);

void func_8018CF90(s32 a0) {
    extern M2C_UNK D_801EB390;
    extern u8 D_8018D838[];
    s32 s0 = a0;
    if (func_8012C354(a0, (s32)&D_801EB390)) {
        *(u8 *)(s0 + 0xC0) = 1;
        *(u16 *)(s0 + 0x2) = 1;
        ((void (*)(s32*, s32))func_8012A828)((s32 *)s0, (s32)D_8018D838);
        func_801788B8(s0, (s32)func_8018D088);
    }
}
