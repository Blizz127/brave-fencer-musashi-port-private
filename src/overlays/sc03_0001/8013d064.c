/* sc03_0001: func_8013D064 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_801ED44C;
extern s32 D_801ED440;
extern s32 D_801ED440;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED44C;
extern s32 D_801ED440;
extern void func_8013D9B0();
extern s32 D_801ED458;
extern s32 D_801ED440;
extern s32 D_801ED45C;
extern s32 D_801ED44C;
extern void func_8013D9B0();
void func_8013D9B0(int param_1);

void func_8013D064(void)
{
    if (D_801ED458 != 0) {
        if (D_801ED458 != 2) {
            if (((D_801ED458 < 3) && (D_801ED458 == 1)) &&
                (D_801ED45C = D_801ED45C + 1, 0x23a < D_801ED45C)) {
                D_801ED440 = D_801ED458;
                D_801ED458 = 2;
            }
        } else {
            D_801ED440 = D_801ED440 + -1;
            if (D_801ED440 == 0) {
                D_801ED440 = D_801ED458;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801ED44C == 0) {
                    D_801ED458 = D_801ED458 + 1;
                }
            }
        }
    }
    return;
}
