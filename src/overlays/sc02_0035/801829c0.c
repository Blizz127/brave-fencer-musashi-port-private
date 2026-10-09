/* SC02.CD member35: func_801829C0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
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
extern void func_8012A828(s32*, s32);
extern s32 func_8012C588(s32 a0, s32 a1);
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
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);
extern void func_8012A828(s32*, s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012C588(s32 a0, s32 a1);
extern void func_8012A828(s32*, s32);

void func_801829C0(void *a0) {
    extern u8 D_801A86A8[];
    s16 val70;
    u16 val72;
    if (*(s32 *)(a0 + 0x94) == 0x17) {
        val70 = *(s16 *)(a0 + 0x70);
        if (val70 == 0x2) {
            func_8012C588(0x1A7, (s32)a0);
        } else {
            func_8002D4C8(0xCB3, 0);
            func_8012C588(0x19F, (s32)a0);
        }
    }
    val72 = *(u16 *)(a0 + 0x72);
    if ((val72 & 0x4000) != 0) {
        ((void (*)(s32, s32))func_8012A828)((s32)a0, (s32)D_801A86A8);
        *(s16 *)(a0 + 0x2) = 0x3;
        *(s16 *)(a0 + 0xFC) = 0;
        *(s16 *)(a0 + 0xFE) = 0;
    }
}
