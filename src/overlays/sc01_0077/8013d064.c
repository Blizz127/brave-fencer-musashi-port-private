/* sc01_0077: func_8013D064 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_801D958C;
extern s32 D_801D9580;
extern s32 D_801D9580;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D958C;
extern s32 D_801D9580;
extern void func_8013D9B0();
extern s32 D_801D9598;
extern s32 D_801D9580;
extern s32 D_801D959C;
extern s32 D_801D958C;
extern void func_8013D9B0();
void func_8013D9B0(int param_1);

void func_8013D064(void)
{
    if (D_801D9598 != 0) {
        if (D_801D9598 != 2) {
            if (((D_801D9598 < 3) && (D_801D9598 == 1)) &&
                (D_801D959C = D_801D959C + 1, 0x23a < D_801D959C)) {
                D_801D9580 = D_801D9598;
                D_801D9598 = 2;
            }
        } else {
            D_801D9580 = D_801D9580 + -1;
            if (D_801D9580 == 0) {
                D_801D9580 = D_801D9598;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801D958C == 0) {
                    D_801D9598 = D_801D9598 + 1;
                }
            }
        }
    }
    return;
}
