/* SC02.CD member35: func_8018087C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_801292C8(u8 *a0);
extern void func_801292C8(u8 *a0);

void func_8018087C(s32 *a0) {
        s32 v0;
        v0 = *(s32 *)((char *)a0 + 0x1c) - 1;
        *(s32 *)((char *)a0 + 0x1c) = v0;
        if (v0 == 0) {
            ((void (*)(void))func_801292C8)();
        }
    }
