/* SC02.CD member35: func_8018071C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_80180C10(s32 a0);
void func_80180C10(s32 param);

void func_8018071C(s32 arg0) {
    s32 temp_v0;
    func_80180C10(arg0);
    if (*(s32 *)(arg0 + 0x30) == 0) {
        *(s16 *)(arg0 + 0x2) = 6;
        *(s32 *)(arg0 + 0x1c) = 0;
    } else {
        temp_v0 = *(s32 *)(arg0 + 0x1c) + 1;
        *(s32 *)(arg0 + 0x1c) = temp_v0;
    }
}
