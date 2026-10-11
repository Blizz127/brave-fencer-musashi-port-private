/* sc03_0001: func_8012F1A4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012F1A4(s32 *a0, s32 a1, s32 *a2) {
    func_800484EC((s32)a0, a1, (s32)a2);
    a2[0] += a0[0x14 / 4] << 16;
    a2[1] += a0[0x18 / 4] << 16;
    a2[2] += a0[0x1C / 4] << 16;
}
