/* SC02.CD member35: func_80183024 from Druthulu/BFM-decomp
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
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80183024(s32 a0)
{
    s32 v1;
    if ((((s32 (*)(s32))func_8012CBCC)(a0) & 0x2000) != 0) {
        *(s16*)(a0 + 0x2) = 2;
        *(s32*)(a0 + 0x1C) = 0x3C;
        *(s16*)(a0 + 0x98) = 1;
        v1 = *(s32*)(a0 + 0x20);
        *(u16*)(v1 + 0x2C) |= 0x10;
        *(s32*)(*(s32*)(a0 + 0x20) + 0x4) |= 0x8000000;
        *(s16*)(*(s32*)(a0 + 0x20) + 0x12) = 0;
        func_8002D4C8(0xCB4, 0);
    }
}
