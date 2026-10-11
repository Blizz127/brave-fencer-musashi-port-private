/* sc03_0001: func_80154AE0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015444C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80154B20(s32 a0, s32 a1, s32 a2);
void func_80154B20(s32 a0, s32 a1, s32 a2);

void func_80154AE0(s32 a0, s32 a1, s32 a2) {
    if (*(s32 *)(a0 + 0xD0) != ((s32 *)*(s32 **)(a0 + 0xCC))[a1]) {
        func_80154B20(a0, a1, a2);
    }
}
