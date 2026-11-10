/* sc02_0037: func_8013D330 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;

void func_8013D330(void) {
    extern u8 D_801C9A72;
    extern u8 D_801C9AE6;
    extern u8 D_801C999A;
    extern u8 D_801C9A54;
    extern u8 D_801C9978;
    extern u8 D_801C9999;
    extern s32 D_801C9A58;
    if ((D_801C9A72 & 0xff) != D_801C9AE6) {
        D_801C9A72 = ((D_801C9A72 & 0xff) < D_801C9AE6) ? (D_801C9A72 + 1) : (D_801C9A72 - 1);
    }
    if ((D_801C999A & 0xff) != D_801C9A54) {
        D_801C999A = ((D_801C999A & 0xff) < D_801C9A54) ? (D_801C999A + 1) : (D_801C999A - 1);
    }
    if ((D_801C9978 & 0xff) != D_801C9999) {
        D_801C9978 = ((D_801C9978 & 0xff) < D_801C9999) ? (D_801C9978 + 1) : (D_801C9978 - 1);
    }
    D_801C9A58 = 1;
}
