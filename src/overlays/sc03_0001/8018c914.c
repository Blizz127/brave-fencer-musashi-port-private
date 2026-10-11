/* sc03_0001: func_8018C914 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 D_80078E8C;
extern void func_8012A568(void (*a0)(void));
extern s32 D_80078E8C;

s16 func_8018C914(s32 a0) {
    s32 var;
    var = D_80078E8C + a0;
    if (var > 99999) {
        var = 99999;
    }
    if (var < 0) {
        return 1;
    }
    D_80078E8C = var;
    return 0;
}
