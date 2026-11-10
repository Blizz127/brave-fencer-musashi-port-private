/* sc02_0037: func_8013D064 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8013D9B0();
extern void func_8013D9B0();
void func_8013D9B0(int param_1);

void func_8013D064(void)
{
    extern s32 D_801C84C0;
    extern s32 D_801C84A8;
    extern s32 D_801C84C4;
    extern s32 D_801C84B4;
    if (D_801C84C0 != 0) {
        if (D_801C84C0 != 2) {
            if (((D_801C84C0 < 3) && (D_801C84C0 == 1)) &&
                (D_801C84C4 = D_801C84C4 + 1, 0x23a < D_801C84C4)) {
                D_801C84A8 = D_801C84C0;
                D_801C84C0 = 2;
            }
        } else {
            D_801C84A8 = D_801C84A8 + -1;
            if (D_801C84A8 == 0) {
                D_801C84A8 = D_801C84C0;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801C84B4 == 0) {
                    D_801C84C0 = D_801C84C0 + 1;
                }
            }
        }
    }
    return;
}
