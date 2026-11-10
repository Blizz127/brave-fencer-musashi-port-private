/* sc02_0037: func_8012CB64 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;

s32 func_8012CB64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register s32 v0 __asm__("$2");
    s32 v1;
    v0 = 0;
    v1 = *(s16*)arg0;
    if (((arg1 <= v1) && (v1 < arg2)) && (arg3 <= *(s16*)(arg0 + 4))) {
        v0 = *(s16*)(arg0 + 4) < arg4;
    }
    return v0;
}
