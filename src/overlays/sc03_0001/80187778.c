/* sc03_0001: func_80187778 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012E8E0(s32, s32);
extern void func_8012E8A8(u8 *a0);
extern void func_8012E8E0(s32 a0, s32 a1);

void func_80187778(s32 *a0, s32 a1) {
    func_8012E8A8((u8 *)a0);
    *(s16 *)((s32)a0 + 0x98) = 0;
    *(s16 *)((s32)a0 + 0x5C) = 0;
    func_8012E8E0((s32)a0, a1);
}
