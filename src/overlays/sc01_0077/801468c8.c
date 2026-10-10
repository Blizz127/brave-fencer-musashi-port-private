/* sc01_0077: func_801468C8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");
void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
unsigned short *func_80146750(unsigned short *a0);
unsigned short *func_8014680C(short *param_1);
extern s32 D_8011F750;
extern s32 D_8011F754;

u8 *func_801468C8(s32 arg0, u8 arg1) {
    u8 *var_a2;
    register u8 *var_v1 __asm__("$3");
    s32 var_t0;
    s32 var_a3;
    var_t0 = 0;
    var_a2 = (u8 *)(s32)&D_8011F750;
    var_v1 = var_a2;
    var_a3 = 0;
    do {
        if (*var_v1 != 0) {
            var_a2 += 0x2C;
            var_v1 += 0x2C;
            var_t0 += 1;
            var_a3 += 0x2C;
        } else {
            *(s32 *)((s32)&D_8011F754 + var_a3) = arg0;
            *var_v1 = arg1;
            return var_a2;
        }
    } while (var_t0 < 2);
    return (u8 *)0;
}
