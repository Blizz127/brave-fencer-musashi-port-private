/* sc02_0037: func_801458E8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801458E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_800AE6AC;
extern s32 D_800AE6B0;
extern s16 D_800B9A0A;
extern u8 D_80078E50;
extern void func_800D185C(u8 *a0);

void func_801458E8(void) {
    D_800AE6B0 = D_800AE6AC | 0x1000000;
    func_800D185C(&D_80078E50);
    D_800B9A0A = 0x3000;
}
