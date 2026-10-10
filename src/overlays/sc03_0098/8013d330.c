/* sc03_0098: func_8013D330 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_801C5842;
extern u8 D_801C58B6;
extern u8 D_801C576A;
extern u8 D_801C5824;
extern u8 D_801C5748;
extern u8 D_801C5769;
extern s32 D_801C5828;

void func_8013D330(void) {
    if ((D_801C5842 & 0xff) != D_801C58B6) {
        D_801C5842 = ((D_801C5842 & 0xff) < D_801C58B6) ? (D_801C5842 + 1) : (D_801C5842 - 1);
    }
    if ((D_801C576A & 0xff) != D_801C5824) {
        D_801C576A = ((D_801C576A & 0xff) < D_801C5824) ? (D_801C576A + 1) : (D_801C576A - 1);
    }
    if ((D_801C5748 & 0xff) != D_801C5769) {
        D_801C5748 = ((D_801C5748 & 0xff) < D_801C5769) ? (D_801C5748 + 1) : (D_801C5748 - 1);
    }
    D_801C5828 = 1;
}
