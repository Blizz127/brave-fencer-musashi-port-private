/* SC02.CD member35: func_8017D3F4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef void (*code_fn)(void);
extern void func_8012A568(void (*a0)(void));

void func_8017D3F4(s32 a0) {
    extern s32 func_8012C438(s32 a0, s32 a1);
    extern void func_8012A828(s32 a0, s32 a1);
    extern s32 func_8012C588(s32 a0, s32 a1);
    extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
    extern u8 D_8019489C[];
    extern u8 D_801847FC[];
    extern u16 D_801949A0[];
    extern u16 D_801949A2[];
    extern u16 D_801949A4[];
    extern u16 D_801949A6[];
    s32 v0 = *(u16 *)(a0 + 0x70) & 0xF;
    u16 flag;
    if (func_8012C438(a0, (s32)(D_8019489C + v0 * 52)) != 0) {
        ((void (*)(s32, s32))func_8012A828)(a0, (s32)D_801847FC);
        *(u8 *)(a0 + 0x75) = 0;
        *(u32 *)(*(s32 *)(a0 + 0x20) + 0x4) |= 0x8040;
        *(u16 *)(a0 + 0xFE) = D_801949A0[*(s16 *)(a0 + 0xFC) * 4];
        *(u16 *)(a0 + 0x100) = D_801949A2[*(s16 *)(a0 + 0xFC) * 4];
        *(u16 *)(a0 + 0x102) = D_801949A4[*(s16 *)(a0 + 0xFC) * 4];
        *(u16 *)(a0 + 0x104) = D_801949A6[*(s16 *)(a0 + 0xFC) * 4];
        func_8001D0E8(*(s32 *)(a0 + 0x20), 0x104, 0xDC);
        flag = *(u16 *)(a0 + 0x70) & 0xF0;
        switch (flag) {
        case 0:
            *(s16 *)(a0 + 0x2) = 1;
            break;
        case 0x10:
            *(s16 *)(a0 + 0x2) = 2;
            break;
        case 0x20:
            *(s16 *)(a0 + 0x2) = 3;
            break;
        }
        func_8012C588(0x1C4, a0);
    }
}
extern code_fn D_801949F0[];
