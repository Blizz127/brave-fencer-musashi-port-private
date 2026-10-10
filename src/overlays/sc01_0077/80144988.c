/* sc01_0077: func_80144988 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;

void func_80144988(s32 a0) {
    s32 t;
    *(u16*)(a0 + 0xA) = *(u16*)(a0 + 0xA) - 0x40;
    *(s32*)(a0 + 0x10) = *(s32*)(*(s32*)(a0 + 0x64) + 0x10);
    *(s32*)(a0 + 0x14) = *(s32*)(*(s32*)(a0 + 0x64) + 0x14);
    t = *(s32*)(*(s32*)(a0 + 0x64) + 0x18);
    *(u16*)(a0 + 0x2) = *(u16*)(a0 + 0x2) + 1;
    *(s32*)(a0 + 0x18) = t;
}
