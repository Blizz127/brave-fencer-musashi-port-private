/* sc03_0098: func_80162120 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_800291DC(s32);
extern void func_800291C8(s32, s32);
extern int func_800291DC(int);
extern s32 func_800291DC(s32);
extern s32 func_800D0D7C(s32, s32);
extern void func_800291C8(s32, s32);

void func_80162120(void) {
    s32 v0;
    if ((s16)func_800291DC(8) == 0) {
        v0 = func_800D0D7C(0, 1);
        func_800291C8(8, (s16)(v0 | 0x8000));
    }
}
