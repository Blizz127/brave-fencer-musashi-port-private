/* SC02.CD member35: func_8017D598 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C354(s32*, s32);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);

void func_8017D598(s32 a0) {
    extern void func_8012A828(s32 a0, s32 a1);
    extern u8 D_801847FC[];
    extern s16 D_801947F0;
    s32 t;
    if (((s32 (*)(s32, s32))func_8012C354)(a0, (s32)&D_801947F0) != 0) {
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801847FC);
        *(s16 *)(a0 + 0x2) = 1;
        *(u8 *)(a0 + 0x75) = 8;
        func_8001D0E8(*(s32 *)(a0 + 0x20), 0x104, 0xDC);
        t = *(u16 *)(a0 + 0xFC);
        *(u16 *)(a0 + 0xFC) = 0x60;
        *(u16 *)(a0 + 0xFE) = t;
    }
}
