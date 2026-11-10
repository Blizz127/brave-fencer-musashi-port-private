/* sc02_0037: func_80130AC4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

void func_80130AC4(s32 a0) {
    s16 v0;
    v0 = *(u16*)(a0 + 0xAC) - 1;
    *(u16*)(a0 + 0xAC) = v0;
    if (v0 == 0) {
        *(u8*)(a0 + 0xC1) = 0;
        *(s16*)(a0 + 0x5E) = 0;
    }
}
