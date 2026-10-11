/* sc03_0001: func_80130088 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
s32 func_8012BCCC(s32 a0);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);
s32 func_80131AC8(void *a0);

void func_80130088(void *a0) {
    s32 v0 = func_8012BCCC((s32)a0);
    if (v0 <= 0x8FFF) {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x32)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x33);
    } else {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x33)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x32);
    }
}
