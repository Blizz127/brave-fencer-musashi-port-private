/* sc03_0001: func_801719A4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void func_8012A568(void (*a0)(void));
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;
extern void *D_8011F738;

void func_801719A4(int a0, int a1)
{
    u32 i;
    s32 off;
    s32 pad[1];
    for (i = 0; i < a1; i++) {
        off = i * 4;
        *(s32*)((s32)&D_8011F738 + off) =
            *(s32*)(((*(u8*)(a0 + 0x214) + i) << 2) + *(s32*)(a0 + 0x1FC));
    }
    *(u8*)(a0 + 0x214) += i;
}
