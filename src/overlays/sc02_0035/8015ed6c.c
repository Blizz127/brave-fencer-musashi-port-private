/* SC02.CD member35: func_8015ED6C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80149048(s32 *a0);
extern u8 D_80078EBF;
extern void func_80149048(s32 *a0);

void func_8015ED6C(s32 *a0) {
    D_80078EBF = 0;
    *(s32 *)((s32)a0 + 0x44) &= -2;
    func_80149048(a0);
}
