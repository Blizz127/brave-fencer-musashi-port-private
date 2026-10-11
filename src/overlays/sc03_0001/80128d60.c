/* sc03_0001: func_80128D60 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_80018450(s32 a0, s32 a1);
extern void func_800183E0(s32 a0);

void func_80128D60(s32 a0, s32 *a1, s32 *a2) {
    a1[0] = (s32)a2;
    *(s16 *)((u8 *)a1 + 4) = 0;
    *(s16 *)((u8 *)a1 + 6) = a2[1] & 0x3F;
    if (a0 != 0) {
        func_80018450(a0, a2[0]);
    } else {
        func_800183E0(a2[0]);
    }
}
