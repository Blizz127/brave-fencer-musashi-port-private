/* sc03_0001: func_80178CBC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern short D_801EF464;
extern s32 D_801EE1C8;

void func_80178CBC(s32 arg0, s32 arg1) {
    extern s32 D_801EE1C8;
    extern short D_801EF464;
    D_801EE1C8 = arg1;
    do {
        func_80178D40(arg0, D_801EE1C8);
    } while (D_801EF464 == 3);
}
