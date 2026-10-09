/* SC02.CD member35: func_80179B28 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80178D40.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80139914(s32 a0);
extern void func_80139914(s32);
extern void func_8012A568(void (*a0)(void));
extern void func_80139914(s32 a0);

void func_80179B28(s32 a0) {
    s32 v1;
    if (a0 == 0) return;
    if (*(s32 *)a0 == 0) return;
    v1 = *(s16 *)(a0 + 4);
    if (v1 == 0) return;
    if (v1 == 0xE) return;
    func_80139914(a0);
}
extern short D_801DA710;
