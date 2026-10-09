/* SC02.CD member35: func_8015987C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_800167B8(s32 a0);

s32 func_8015987C(s32 a0) {
    func_800167B8(4);
    *(u8 *)(a0 + 0x15) = *(u8 *)(a0 + 0x15) + 1;
    return 0;
}
