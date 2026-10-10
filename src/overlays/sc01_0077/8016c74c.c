/* sc01_0077: func_8016C74C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80047E98(void *a0, void *a1);

void func_8016C74C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 r; s32 lim; s32 sh2;
    sh2 = (s16)a2;
    __asm__ __volatile__("" : "=r"(sh2) : "0"(sh2));
    *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x10) + (*(s16 *)(a1 + 0x0) << sh2);
    *(s32 *)(a0 + 0x14) = *(s32 *)(a0 + 0x14) + (*(s16 *)(a1 + 0x2) << sh2);
    *(s32 *)(a0 + 0x18) = *(s32 *)(a0 + 0x18) + (*(s16 *)(a1 + 0x4) << sh2);
    *(s16 *)(a1 + 0x0) = *(u16 *)(a0 + 0x12);
    *(s16 *)(a1 + 0x2) = *(u16 *)(a0 + 0x16);
    *(s16 *)(a1 + 0x4) = *(u16 *)(a0 + 0x1a);
    lim = *(s32 *)&a4;
    __asm__ __volatile__("" ::: "memory");
    r = ((s32 (*)(void *))func_80047E98)((void *)a1);
    if (lim < r) {
        *(s32 *)(a0 + 0x10) = *(s16 *)(a1 + 0x0) << (s16)a3;
        *(s32 *)(a0 + 0x14) = *(s16 *)(a1 + 0x2) << (s16)a3;
        *(s32 *)(a0 + 0x18) = *(s16 *)(a1 + 0x4) << (s16)a3;
    }
}
