/* sc03_0001: func_801776EC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
extern void func_8012A568(void (*a0)(void));
extern u8 D_8011F7AB;
extern u8 D_8011F7AB;

void func_801776EC(u8 *a0)
{
    u8 *p;
    switch (D_8011F7AB) {
    default:
        D_8011F7AB = 0;
    case 0:
        a0[4] = 0xFF;
        a0[6] = 0x30;
        a0[5] = 0x30;
        break;
    case 1:
        a0[5] = 0xFF;
        a0[6] = 0x30;
        a0[4] = 0x30;
        break;
    case 2:
        a0[6] = 0xFF;
        a0[5] = 0x30;
        a0[4] = 0x30;
        break;
    }
    p = &D_8011F7AB;
    *p = *p + 1;
}
