/* sc03_0098: func_8012DF34 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 D_80126B58;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80126B58;
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 D_80126B58;
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern s32 D_80126B58;
extern u8 D_801152A8[];
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
void func_8012F568(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6);

s32 func_8012DF34(s32 a0, s32 a1, s32 a2) {
    s32 s0 = a2;
    s32 *p = &D_80126B58;
    if (a0 != 0) {
        if (*(s16 *)(a0 + 0xAA) != 0) {
            return 0;
        }
    }
    if (func_80135888(*(s32 *)((s32)p + 0x20), *(s32 *)((s32)p + 0x38), a1, s0) != 0) {
        func_8012F568(1, 1, 0, 0xA, s0, (s32)D_801152A8);
        return 1;
    }
    return 0;
}
