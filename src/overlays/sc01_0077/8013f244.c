/* sc01_0077: func_8013F244 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern u16 D_8011511E;
extern u16 D_8011511A;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern void func_80141C0C(s32);
void func_80141C0C(s32 param_1);

void func_8013F244(void)
{
    u16 *p = &D_8011511A;
    u16 uVar1;
    s32 iVar2;
    iVar2 = 0;
    if (*p < 3) {
        if ((D_8011511E & 0x2000) != 0) {
            uVar1 = *p + 1;
            iVar2 = 1;
            *p = *p + 1;
            if (2 < uVar1) {
                *p = 0;
            }
        }
        if ((D_8011511E & 0x8000) != 0) {
            D_8011511A = D_8011511A - 1;
            if (2 < D_8011511A) {
                D_8011511A = 2;
            }
            iVar2 = iVar2 + 1;
        }
        if ((D_8011511E & 0x5000) != 0) {
            D_8011511A = 3;
            iVar2 = iVar2 + 1;
        }
    } else {
        iVar2 = 0;
        if ((D_8011511E & 0x5000) == 0)
            goto done;
        *p = 0;
        iVar2 = 1;
    }
done:
    if ((iVar2 << 0x10) != 0) {
        func_80141C0C(2);
    }
    return;
}
