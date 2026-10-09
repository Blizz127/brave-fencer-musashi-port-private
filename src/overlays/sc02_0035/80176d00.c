/* SC02.CD member35: func_80176D00 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int uint;
extern u16 D_80078EA6;
extern void func_8012A568(void (*a0)(void));
extern u16 D_8011F7B4;
extern u16 D_8011F7B6;
extern s32 func_80178004();
extern u8 D_8011F7B1;
extern u8 D_8011F7A8;
extern u16 D_80078EA6;
extern u16 D_8011F7B4;
extern u16 D_8011F7B6;
extern s16 D_8011F81E;
s32 func_80178004(uint *param_1, uint param_2, int param_3);

void func_80176D00(s32 a0) {
    u8 *arr = (u8 *)&D_8011F7A8;
    u8 *base;
    s32 tmp;
    s32 a1v, a2v;
    if (D_8011F7B1 != 0) {
        return;
    }
    base = arr + (s16)a0 * 4;
    tmp = *(s32 *)(base + 0x20) + 0x14;
    *(s32 *)(base + 0x38) = tmp;
    a1v = (s16)(D_8011F7B4 - 0x17);
    a2v = (s16)(D_8011F7B6 + 0x65);
    D_8011F81E = D_80078EA6;
    *(s32 *)(base + 0x40) = func_80178004(tmp, a1v, a2v) - 0x14;
}
