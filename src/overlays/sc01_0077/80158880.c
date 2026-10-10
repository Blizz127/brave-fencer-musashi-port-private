/* sc01_0077: func_80158880 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80149020(s32 *a0);
extern void func_80149020(s32 *a0);
extern void (*D_80188EB8[])(s32 *);

void func_80158880(s32 *param) {
    func_80149020(param);
    D_80188EB8[*(u8 *)((s32)param + 0x4F)](param);
}
