/* sc01_0077: func_80154A74 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015444C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80154AB4(s32 a0, s32 a1);
void func_80154AB4(s32 a0, s32 a1);

void func_80154A74(s32 a0, s32 a1) {
    if (*(s32 *)(a0 + 0xD0) != ((s32 *)*(s32 **)(a0 + 0xCC))[a1]) {
        func_80154AB4(a0, a1);
    }
}
