/* sc03_0001: func_801627E8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c, rewritten so the handler gets its
 * argument explicitly: retail keeps a0 = &D_8011F750 live into the jalr (the
 * handlers read a0[1]); upstream used a $4 register-asm idiom under a (void)
 * table type. Byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;

extern u8 D_8011F750[];
extern void (*D_801900B0[])(u8 *);

void func_801627E8(void)
{
    u8 *p = D_8011F750;
    s32 idx;
    idx = *p;
    if (idx != 0) {
        idx = idx - 1;
        D_801900B0[idx](p);
    }
}
