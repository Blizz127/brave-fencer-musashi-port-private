/* SC02.CD member35: func_80176FF4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern u32 func_801783D0(s32, s32);
extern u32 func_801783D0(s32 a0, s32 a1);
extern u16 D_8011F82C;
extern u16 D_8011F82A;
extern u32 func_801783D0(s32 a0, s32 a1);
extern void func_801778A8(int param_1, unsigned int param_2, short param_3, short param_4);
extern u16 D_8011F82C;
extern u16 D_8011F82A;
void func_801778A8(int param_1, unsigned int param_2, short param_3, short param_4);
u32 func_801783D0(s32 a0, s32 a1);

void func_80176FF4(s32 a0) {
    s32 v0;
    a0 += 0x50;
    func_801778A8(a0, (s16)func_801783D0(D_8011F82C, 4), 3, 0xFF);
    a0 += 0x3C;
    func_801778A8(a0, (s16)func_801783D0(D_8011F82A, 4), 3, 0xFF);
    a0 += 0x3C;
    *(s16 *)(a0 + 0xC) = (u32)(D_8011F82C * 10355) >> 15;
    a0 += 0x14;
    v0 = ((s32)(D_8011F82A * 10355) << 1) >> 16;
    *(s16 *)(a0 + 0xC) = v0;
    *(s16 *)(a0 + 0x20) = v0 + 2;
}
