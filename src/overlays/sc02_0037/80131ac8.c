/* sc02_0037: func_80131AC8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80131CF4(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);

s32 func_80131AC8(void *a0) {
    s32 s0 = func_80131CF4(*(s32 *)((u8 *)a0 + 0xBC)) & 0xFFFF;
    if (s0 != 0) {
        func_8002D4C8(s0, 0);
        return s0;
    }
    return 0;
}
