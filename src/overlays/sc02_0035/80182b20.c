/* SC02.CD member35: func_80182B20 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern u16 D_80126B96;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
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
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80182B20(s32 a0) {
    extern u8 D_8019C498[];
    extern u8 D_8019C470[];
    extern u8 D_8019C478[];
    extern u8 D_801A8490[];
    extern u16 D_80126B96;
    extern s16 D_80126B98;
    s32 result;
    u16 val70;
    u16 *q;
    if ((*(u16 *)(a0 + 0x72) & 0x4000) != 0) {
        *(s16 *)(a0 + 0x2) = 0xC;
        func_8012B1B4(a0, (s32)D_8019C498);
        *(s16 *)(a0 + 0x16) = -0x8;
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801A8490);
        *(s16 *)(a0 + 0x98) = 0x1;
    }
    if (*(s32 *)(a0 + 0x94) == 0xF) {
        result = func_8012D5E4(a0, (s32)D_8019C470, (s32)D_8019C478, 0x14);
        if (result == 1) {
            func_8002D4C8(0xCB2, 0);
            val70 = *(u16 *)(a0 + 0x70);
            if (((u32)val70 - 2) < 2) {
                q = &D_80126B96;
                D_80126B98 = 0x18;
                *q = *q | 0x2000;
            }
        }
    }
}
