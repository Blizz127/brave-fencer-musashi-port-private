/* sc03_0001: func_8012F0BC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8004D504(void *a0, void *a1, void *a2);
extern void func_8004D504(void *a0, void *a1, void *a2);

void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2) {
    s32 in[3];
    s32 out[3];
    in[0] = a1[0] - (a0[5] << 16);
    in[1] = a1[1] - (a0[6] << 16);
    in[2] = a1[2] - (a0[7] << 16);
    func_8004D504(a0, in, out);
    a2[0] = out[0];
    a2[1] = out[1];
    a2[2] = out[2];
}
