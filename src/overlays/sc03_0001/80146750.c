/* sc03_0001: func_80146750 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");
void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern unsigned short D_8011FD10;
extern int D_8011FA1C;
extern unsigned short D_8011F9D6;
extern unsigned short D_8011F9DA;
extern unsigned short D_8011F9DE;
extern int D_8011FA20;
extern int D_8011FA24;
unsigned short *func_8014680C(short *param_1);

unsigned short *func_80146750(unsigned short *a0)
{
    int a6;
    register unsigned short *a7 __asm__("7");
    int a5;
    unsigned short *v1;
    unsigned short *v0;
    a6 = 0x8;
    a7 = &D_8011FD10;
    v1 = a7;
    a5 = 0x340;
    do {
        v0 = v1;
        if (*v0 != 0) {
            a7 = (unsigned short *)((char *)a7 + 0x68);
            v1 = (unsigned short *)((char *)v1 + 0x68);
            a6 = a6 + 1;
            a5 = a5 + 0x68;
        } else {
            *(int *)((char *)&D_8011FA1C + a5) = *(int *)((char *)a0 + 0x8);
            *v1 = *a0;
            *(unsigned short *)((char *)&D_8011F9D6 + a5) = *(unsigned short *)((char *)a0 + 0x2);
            *(unsigned short *)((char *)&D_8011F9DA + a5) = *(unsigned short *)((char *)a0 + 0x4);
            *(unsigned short *)((char *)&D_8011F9DE + a5) = *(unsigned short *)((char *)a0 + 0x6);
            *(int *)((char *)&D_8011FA20 + a5) = *(int *)((char *)a0 + 0xC);
            *(int *)((char *)&D_8011FA24 + a5) = *(int *)((char *)a0 + 0x10);
            return a7;
        }
    } while (a6 < 0x14);
    return (unsigned short *)0;
}
