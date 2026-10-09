/* SC02.CD member35: func_801808F0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_80180C10(s32 a0);
extern void func_801292C8(u8 *a0);
extern void func_80180C10(s32 a0);
extern void func_801292C8(u8 *a0);
extern void func_80180C10(s32 a0);
extern void func_801292C8(u8 *a0);
void func_80180C10(s32 param);

void func_801808F0(s32 arg0) {
    register s32 s0 __asm__("$16") = arg0;
    func_80180C10(s0);
    if (*(u16 *)(*(s32 *)(s0 + 0x2C)) == 0) {
        func_801292C8((u8 *)s0);
    }
    *(s32 *)(s0 + 0x1C) += 1;
}
