/* SC02.CD member35: func_80182D94 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 func_80153BD8(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BD8(s32 arg);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BD8(s32 arg);
extern void func_8012A828(s32*, s32);
extern s32 func_80153BD8(s32 a0);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_80153BD8(s32 a0);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_80153BD8(s32 a0);
extern void func_8012A828(s32*, s32);

void func_80182D94(s32 a0) {
    extern u8 D_801A96D0[];
    s32 result;
    result = func_80153BD8(a0);
    if (result == 0) {
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)&D_801A96D0);
        *(s16 *)(a0 + 0x2) = 3;
        *(s16 *)(a0 + 0xFC) = 0;
    } else {
        *(s16 *)(a0 + 0x2) = 4;
    }
}
