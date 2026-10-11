/* sc03_0001: func_8015B858 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 D_8011F730;
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern u8 D_800D4BE0[];
extern s32 D_8011F730;
extern s32 func_8014A51C();
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);

s32 func_8015B858(u8 *a0) {
    if (*(u8 *)(a0 + 0x1C6) != 0) return 0;
    if (*(s32 *)(a0 + 0x240) != 0) return 0;
    if (func_8014A51C() == 0) return 0;
    *(s32 *)(a0 + 0x23C) = *(s32 *)(a0 + 0xB4);
    *(u8 *)(a0 + 0x244) = *(u8 *)(a0 + 0xBC);
    func_801477E8((s32 *)a0, 0xFFF20000);
    func_80154274((s32 *)a0, (s32)D_800D4BE0);
    D_8011F730 |= 2;
    return 1;
}
