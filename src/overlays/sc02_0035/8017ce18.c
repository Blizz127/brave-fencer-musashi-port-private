/* SC02.CD member35: func_8017CE18 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_800167B8(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_8017D00C(void);
extern void func_800167B8(s32 a0);
void func_8017D00C(void);

s32 func_8017CE18(s32 a0) {
    func_8017D00C();
    func_800167B8(0);
    *(u8 *)(a0 + 0x15) += 1;
    return 0;
}
