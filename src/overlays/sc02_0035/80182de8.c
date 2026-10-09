/* SC02.CD member35: func_80182DE8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern u16 D_80126B96;
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
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
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);

void func_80182DE8(s32 a0) {
    extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
    extern void func_8012A828(s32*, s32);
    extern u16 D_80126B96;
    extern s16 D_80126B98;
    extern s32 D_80127078;
    extern u8 D_8019C460[];
    extern u8 D_8019C468[];
    extern u8 D_801A9290[];
    extern char D_801A9B40[];
    s32 result;
    result = func_8012DEB8(a0, (s32)&D_8019C460, (s32)&D_8019C468);
    if (result == 1) {
        D_80126B96 = 0x400F;
        D_80126B98 = 0;
        D_80127078 = a0;
        *(u16 *)(a0 + 0x2) = 0x12;
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)&D_801A9290);
    } else {
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)&D_801A9B40);
        *(u16 *)(a0 + 0x2) = 0x6;
    }
}
