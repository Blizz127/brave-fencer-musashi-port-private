/* sc03_0098: func_8015DD74 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_8014C1A0(s32 arg0, s32 arg1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

int func_8015DD74(int arg0)
{
    s16 sp18[4];
    s32 s0;
    s0 = *(s32 *)(arg0 + 0x178);
    if (s0 != 0) {
        func_8014C1A0(arg0, s0);
        func_80015978(s0 + 4, (s32 *)sp18);
        sp18[3] = 0;
        func_8014C4AC(s0, 9, func_80029AAC(), sp18,
                      *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12));
        *(s32 *)(arg0 + 0x178) = 0;
    }
}
