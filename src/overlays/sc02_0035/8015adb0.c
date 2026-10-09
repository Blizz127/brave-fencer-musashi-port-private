/* SC02.CD member35: func_8015ADB0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 D_8011F730;
extern void func_80146CA0(void *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014C010(s32 a0, s32 a1);

void func_8015ADB0(s32 arg0) {
    extern s32 D_8011F730;
    extern void func_80161124(void *a0);
    extern void func_801477E8(s32 *a0, s32 a1);
    extern void func_8014C010(s32 a0, s32 a1);
    extern void func_80146CA0(void *a0);
    if (*(u8 *)(arg0 + 0xA8) >= 0x19) {
        *(u8 *)(arg0 + 0xA8) = 0x18;
    }
    func_80161124(arg0);
    ((void (*)(s32, s32))func_801477E8)(arg0, 0xFFEE0000);
    func_8014C010(arg0, 2);
    D_8011F730 |= 1;
    ((void (*)(s32))func_80146CA0)(arg0);
}
