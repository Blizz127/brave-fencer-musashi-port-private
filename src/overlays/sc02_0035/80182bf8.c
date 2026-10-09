/* SC02.CD member35: func_80182BF8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
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
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8012A828(s32*, s32);

void func_80182BF8(s32 a0) {
    extern s32 aD_801BB960 __asm__("D_801A8490");
    extern s32 aD_801AF698 __asm__("D_8019C1C8");
    u16 temp;
    if (*(s32 *)(a0 + 0x94) == 0xD) {
        func_8002D4C8(0x702, 0x107F);
    }
    func_8012CBCC(a0);
    temp = *(u16 *)(a0 + 0x102) + 1;
    *(u16 *)(a0 + 0x102) = temp;
    if ((s16)temp == 0x1E) {
        *(u16 *)(a0 + 0x2) = 0x9;
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)&aD_801BB960);
        *(u16 *)(a0 + 0x102) = 0;
        *(s32 *)(a0 + 0x14) = 0;
        *(s32 *)(a0 + 0x58) = ((s32)&aD_801AF698 | 0x40000000) | 0x20000000;
    }
}
