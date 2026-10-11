/* sc03_0001: func_801565C0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef int s32;
extern s32 D_801151E0[];

s32 func_801565C0(void) {
    s32 result;
    u32 i;
    result = 0;
    for (i = 0; i < 3; i++) {
        if (D_801151E0[i] & 1) {
            result |= 1;
        }
    }
    return result;
}
