/* sc03_0098: func_8013D064 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_801C4294;
extern s32 D_801C4288;
extern s32 D_801C4288;
extern s32 D_801C4294;
extern s32 D_801C4294;
extern s32 D_801C4294;
extern s32 D_801C4294;
extern s32 D_801C4288;
extern void func_8013D9B0();
extern s32 D_801C42A0;
extern s32 D_801C4288;
extern s32 D_801C42A4;
extern s32 D_801C4294;
extern void func_8013D9B0();
void func_8013D9B0(int param_1);

void func_8013D064(void)
{
    if (D_801C42A0 != 0) {
        if (D_801C42A0 != 2) {
            if (((D_801C42A0 < 3) && (D_801C42A0 == 1)) &&
                (D_801C42A4 = D_801C42A4 + 1, 0x23a < D_801C42A4)) {
                D_801C4288 = D_801C42A0;
                D_801C42A0 = 2;
            }
        } else {
            D_801C4288 = D_801C4288 + -1;
            if (D_801C4288 == 0) {
                D_801C4288 = D_801C42A0;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801C4294 == 0) {
                    D_801C42A0 = D_801C42A0 + 1;
                }
            }
        }
    }
    return;
}
