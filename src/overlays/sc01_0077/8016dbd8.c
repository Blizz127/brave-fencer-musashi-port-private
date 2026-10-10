/* sc01_0077: func_8016DBD8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80149374(s32 a0, s32 a1);
extern void func_80149374(s32 arg0, s32 arg1);
extern void func_80149374(int, int);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern void func_800D1FC8(s32 a0, s32 a1);

void func_8016DBD8(u8 *a0) {
    *(s32 *)(a0 + 0x4) = 0;
    *(s32 *)(a0 + 0x8) = 0;
    *(s32 *)(a0 + 0xC) = 0;
    func_80149374(*(s32 *)(a0 + 0x34), (s32)(a0 + 0x4));
    func_800D1FC8((s32)a0, 5);
}
