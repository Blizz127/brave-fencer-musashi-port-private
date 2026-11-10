/* sc02_0037: func_801290DC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 *func_8012913C(s32 a0);
u8 * func_8012913C(s32 arg0);

u8 *func_801290DC(s32 a0, u8 *a1) {
    u8 *v1 = func_8012913C(a0 & 0xFFFF);
    if (v1 != 0) {
        *(u16 *)(v1 + 0x6) = *(u16 *)(a1 + 0x0);
        *(u16 *)(v1 + 0xA) = *(u16 *)(a1 + 0x2);
        *(u16 *)(v1 + 0xE) = *(u16 *)(a1 + 0x4);
    }
    return v1;
}
