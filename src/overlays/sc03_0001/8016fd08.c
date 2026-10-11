/* sc03_0001: func_8016FD08 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80146D90(s32 a0);
extern void func_80147060(u8 * a0);
extern void func_80148634(void *a0);
extern void func_801511A8(u8 *a0);
extern void func_80146D90(int);
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
extern void *D_8011F738;
extern void func_80147060(u8 *a0);
extern void func_80148634(void *a0);
extern void func_80148634(void *a0);
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern s32 func_80171990(u8 *a0);
extern s32 func_80171990(u8 *a0);
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern s32 func_80171990(u8 *a0);
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern s32 func_80171990(u8 *a0);
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern s32 func_80171990(u8 *a0);
extern s32 func_80172658(s32 *a0);
extern void func_80146D90(s32 a0);
extern s32 func_80171990(u8 *a0);
extern void *D_8011F738;
void func_8017196C(s32 *a0, s8 a1);
s32 func_80171990(u8 *a0);

void func_8016FD08(u8 *s0) {
    s32 *p;
    if (func_80172658((s32 *)s0)) {
        func_80146D90((s32)s0);
        *(u16 *)(s0 + 0xAC) = *(u16 *)(s0 + 0xAC) | 0x40;
        *(u16 *)(s0 + 0xAA) = *(u16 *)(s0 + 0xAA) | 0x40;
        p = (s32 *)&D_8011F738;
        if ((*p = *p - 1) == 0) {
            func_80171990(s0);
        }
    }
}
