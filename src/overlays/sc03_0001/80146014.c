/* sc03_0001: func_80146014 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80059A80(void *a0, s32 a1, s32 a2);

void func_80146014(s32 a0) {
    s32 *r = (s32 *)a0;
    if (r[3] == 0) {
        return;
    }
    do {
        func_80059A80(r, r[2], r[3]);
        r += 4;
    } while (r[3] != 0);
}
