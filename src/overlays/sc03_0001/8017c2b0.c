/* sc03_0001: func_8017C2B0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80049CAC(s32 a0, s32 a1);
extern s16 D_801EE880;
extern s16 D_801EE880;
extern s16 D_801EE880;
extern void func_80049CAC(s32 a0, s32 a1);

void func_8017C2B0(s32 a0)
{
    extern u16 D_80126B62;
    s32 unused[2];
    s32 s0;
    s0 = *(s32 *)(a0 + 0x20);
    if ((s32)*(s16 *)(a0 + 0xA) - (s32)(*(s16 *)&D_80126B62) >= 0x40) {
        *(s16 *)(a0 + 0x5C) = 0x40;
    } else {
        *(s16 *)(a0 + 0x5C) = 0x800;
    }
    if (*(s16 *)(s0 + 0x12) != D_801EE880) {
        *(s16 *)(s0 + 0x12) = D_801EE880;
        func_80049CAC(*(s32 *)(a0 + 0x20) + 0x10, *(s32 *)(a0 + 0x20) + 0x34);
        *(u16 *)(s0 + 0x2C) |= 0x11;
    }
}
