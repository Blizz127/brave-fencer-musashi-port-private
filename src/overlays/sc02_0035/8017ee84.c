/* SC02.CD member35: func_8017EE84 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C354(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C588(s32 a0, s32 a1);

void func_8017EE84(s32 a0) {
    extern u8 D_80196D48[];
    extern u8 D_801847FC[];
    extern u16 D_80196D7C[];
    extern u16 D_80196D7E[];
    extern u16 D_80196D80[];
    extern s16 D_80196D82[];
    if (((s32 (*)(s32, s32))func_8012C354)(a0, (s32)D_80196D48) != 0) {
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801847FC);
        *(s16 *)(a0 + 0x2) = 1;
        *(u8 *)(a0 + 0x75) = 0;
        *(u16 *)(a0 + 0x12) = D_80196D7C[*(s16 *)(a0 + 0xFC) * 4];
        *(u16 *)(a0 + 0x16) = D_80196D7E[*(s16 *)(a0 + 0xFC) * 4];
        *(u16 *)(a0 + 0x1A) = D_80196D80[*(s16 *)(a0 + 0xFC) * 4];
        *(s32 *)(a0 + 0x1C) = D_80196D82[*(s16 *)(a0 + 0xFC) * 4];
        func_8012C588(0x1C4, a0);
    }
}
