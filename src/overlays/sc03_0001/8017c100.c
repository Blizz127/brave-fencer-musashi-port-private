/* sc03_0001: func_8017C100 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A568(void (*a0)(void));
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_80190EF8[];

void func_8017C100(s32 param_1)
{
    s32 s0;
    s0 = *(s32 *)(param_1 + 0x20);
    if (*(s16 *)(param_1 + 0x2e) == 0) {
        func_8001CB6C((u8 *)s0, (s32)D_80190EF8, 0x3c0, 0xa0);
    } else {
        func_8001CC3C(s0, (s32)D_80190EF8, 0x3c0, 0xa0);
    }
    *(u8 *)(s0 + 0x27) = 0xfc;
    *(u16 *)(s0 + 0x1a) = 0x3c00;
    *(u16 *)(s0 + 0x18) = 0x3c00;
    *(u32 *)(s0 + 0x4) |= 0x01000000;
    *(u32 *)(s0 + 0x34) = *(u32 *)(param_1 + 0x30);
    (*(u16 *)(param_1 + 0x2))++;
}
