/* sc01_0077: func_8013D330 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 D_801DAAA0;
extern u8 D_801DA9C1;
extern u8 D_801DAB2E;
extern u8 D_801DAA9C;
extern u8 D_801DAABA;
extern u8 D_801DAB2E;
extern u8 D_801DA9C2;
extern u8 D_801DAA9C;
extern u8 D_801DA998;
extern u8 D_801DA9C1;
extern s32 D_801DAAA0;

void func_8013D330(void) {
    if ((D_801DAABA & 0xff) != D_801DAB2E) {
        D_801DAABA = ((D_801DAABA & 0xff) < D_801DAB2E) ? (D_801DAABA + 1) : (D_801DAABA - 1);
    }
    if ((D_801DA9C2 & 0xff) != D_801DAA9C) {
        D_801DA9C2 = ((D_801DA9C2 & 0xff) < D_801DAA9C) ? (D_801DA9C2 + 1) : (D_801DA9C2 - 1);
    }
    if ((D_801DA998 & 0xff) != D_801DA9C1) {
        D_801DA998 = ((D_801DA998 & 0xff) < D_801DA9C1) ? (D_801DA998 + 1) : (D_801DA998 - 1);
    }
    D_801DAAA0 = 1;
}
