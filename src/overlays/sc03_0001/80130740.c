/* sc03_0001: func_80130740 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_80130740(void *a0, u16 *a1) {
    u16 *p = (u16 *)a0;
    func_80146A6C(0x10, a0,
                  (s16)(p[3] + a1[0]),
                  (s16)(p[5] + a1[1]),
                  (s16)(p[7] + a1[2]),
                  0, 0);
}
