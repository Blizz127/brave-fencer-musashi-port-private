/* sc01_0077: func_801701C8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80147060(u8 * a0);
extern void func_80148634(void *a0);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern s16 D_80078EB4;
extern u8 D_800B9A17;
extern void func_801511A8(u8 *a0);
extern u8 D_800B9A17;
extern u8 D_800B9A17;
extern void func_8017196C(s32 *a0, s8 a1);
extern void func_80147060(u8 *a0);
extern void func_801511A8(u8 *a0);
extern void func_80148634(void *a0);
void aF8016F0E4(u8 *p) __asm__("func_8016F0E4");
extern void func_80148634(void *a0);
extern u8 D_800B9A17;
extern u8 D_800B9A17;
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80147060(u8 *a0);
extern void func_80171928(void *a0);
extern void func_80148634(void *a0);
extern void func_80171928(void *a0);
extern void func_80148634(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void func_80171928(void *);
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_80171928(void *a0);
extern void *D_8011F738;
void func_80171928(void * a0);
void func_8017196C(s32 *a0, s8 a1);

void func_801701C8(u8 * a0)
{
    s16 *p;
    s32 r;
    r = func_80012B04(((s16 **)a0)[8][9], *(s16 *)&D_8011F738, 4);
    if ((s16)r == 0) {
        func_80171928(a0);
    }
    p = ((s16 **)a0)[8];
    ((u16 *)p)[9] = (((u16 *)p)[9] + r) & 0xFFF;
}
