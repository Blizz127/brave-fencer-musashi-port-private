/* SC02.CD member35: func_80182A54 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern void func_80153C74(s16 a0, s16 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80153BD8(s32 arg);
extern s32 func_80153BF0(s32 a0);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern s32 func_80153BD8(s32 arg);
extern s32 func_80153BF0(s32 a0);
extern void func_8012A828(s32*, s32);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern void func_8012A828(s32*, s32);
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80153C74(s16 a0, s16 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern void func_8012A828(s32*, s32);
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80153C74(s16 a0, s16 a1);

void func_80182A54(s32 a0) {
    extern s32 aD801BC890 __asm__("D_801A93C0");
    extern s32 aD801AF930 __asm__("D_8019C460");
    extern s32 aD801AF938 __asm__("D_8019C468");
    u16 val;
    if (func_80153BD8(a0) == 0) {
        ((void (*)(s32))func_80153BF0)(a0);
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)&aD801BC890);
        *(s16 *)(a0 + 0x34) = 7;
        *(s16 *)(a0 + 0x2) = 0x13;
        *(s32 *)(a0 + 0x1C) = 0x1E;
    }
    if (*(s32 *)(a0 + 0x94) == 0x17) {
        if (func_8012DEB8(a0, (s32)&aD801AF930, (s32)&aD801AF938) == 1) {
            func_8002D4C8(0xCB2, 0);
            val = *(u16 *)(a0 + 0x70);
            if ((u16)(val - 2) < 2u) {
                func_80153C74(3, 0x18);
            } else {
                func_80153C74(1, 0x14);
            }
        }
    }
}
