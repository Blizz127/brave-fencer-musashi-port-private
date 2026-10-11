/* sc03_0001: func_8013D330 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_801EF3F2;
extern u8 D_801EF466;
extern u8 D_801EF2F2;
extern u8 D_801EF3BC;
extern u8 D_801EF2C8;
extern u8 D_801EF2F1;
extern s32 D_801EF3C0;

void func_8013D330(void) {
    if ((D_801EF3F2 & 0xff) != D_801EF466) {
        D_801EF3F2 = ((D_801EF3F2 & 0xff) < D_801EF466) ? (D_801EF3F2 + 1) : (D_801EF3F2 - 1);
    }
    if ((D_801EF2F2 & 0xff) != D_801EF3BC) {
        D_801EF2F2 = ((D_801EF2F2 & 0xff) < D_801EF3BC) ? (D_801EF2F2 + 1) : (D_801EF2F2 - 1);
    }
    if ((D_801EF2C8 & 0xff) != D_801EF2F1) {
        D_801EF2C8 = ((D_801EF2C8 & 0xff) < D_801EF2F1) ? (D_801EF2C8 + 1) : (D_801EF2C8 - 1);
    }
    D_801EF3C0 = 1;
}
