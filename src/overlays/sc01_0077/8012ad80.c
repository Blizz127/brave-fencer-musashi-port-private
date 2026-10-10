/* sc01_0077: func_8012AD80 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012AD80(s32 a0) {
    *(s32*)(a0 + 0x10) += *(s32*)(a0 + 0x44);
    *(s32*)(a0 + 0x14) += *(s32*)(a0 + 0x48);
    *(s32*)(a0 + 0x18) += *(s32*)(a0 + 0x4C);
    *(s32*)(a0 + 0x4) += *(s32*)(a0 + 0x10);
    *(s32*)(a0 + 0x8) += *(s32*)(a0 + 0x14);
    *(s32*)(a0 + 0xC) += *(s32*)(a0 + 0x18);
}
