/* sc03_0098: func_80154B98 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015444C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80154BC8(void *a0, s32 a1, s32 a2);
void func_80154BC8(void *a0, s32 a1, s32 a2);

void func_80154B98(void *a0, s32 a1, s32 a2) {
    if (*(s32 *)((s32)a0 + 0xD0) != a1) {
        func_80154BC8(a0, a1, a2);
    }
}
