/* sc03_0001: func_80156648 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80156A14(s32 *a0);
void func_80156A14(s32 *a0);

void func_80156648(s32 *a0) {
    *((u8 *)a0 + 0x1A8) = 0;
    *((u8 *)a0 + 0x1A9) = 0;
    *((u8 *)a0 + 0x1C0) = 0;
    func_80156A14(a0);
}
