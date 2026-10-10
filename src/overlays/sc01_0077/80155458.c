/* sc01_0077: func_80155458 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern int (*D_80188988[])(void);

s32 func_80155458(s32 param_1)
{
    int idx;
    idx = *(unsigned char *)(param_1 + 0x4e);
    if (idx != 0) {
        idx = idx - 1;
        if ((*D_80188988[idx])() == 0) {
            *(unsigned char *)(param_1 + 0x4e) = 0;
        }
    }
    return *(unsigned char *)(param_1 + 0x4e);
}
