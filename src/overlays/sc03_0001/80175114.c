/* sc03_0001: func_80175114 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *, s16);
extern void func_8012A568(void (*a0)(void));
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80175184(s32 *a0);
void func_80175184(s32* arg0);

void func_80175114(s32 *a0) {
    func_80147078(a0, 8);
    *(s16 *)((s32)a0 + 2) = 1;
    func_80175184(a0);
}
