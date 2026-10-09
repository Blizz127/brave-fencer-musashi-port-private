/* SC02.CD member35: func_8017E8A0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012C354(s32*, s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012C354(s32*, s32);
extern void func_8012A828(s32*, s32);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);

void func_8017E8A0(s32 a0) {
    extern u8 D_801968F0[];
    extern u8 D_801968D0[];
    extern u8 D_801847FC[];
    s32 t;
    if (((s32 (*)(s32, s32))func_8012C354)(a0, (s32)D_801968F0) != 0) {
        *(u8 *)(a0 + 0xC0) = 1;
        t = *(s32 *)(a0 + 0xC4);
        *(s32 *)(a0 + 0xBC) = (s32)D_801968D0;
        *(s32 *)(a0 + 0xC4) = t | 0x2;
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801847FC);
        *(s16 *)(a0 + 0x2) = 1;
        *(u8 *)(a0 + 0x75) = 0;
        *(s16 *)(a0 + 0xFE) = 1;
        func_8012C658(0x164, 0x555, a0);
        func_8012C658(0x164, 0xAAA, a0);
        func_8012C658(0x164, 0x1000, a0);
    }
}
