/* sc03_0001: func_80170CF0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80147060(u8 * a0);
extern void func_80148634(void *a0);
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
extern void *D_8011F738;
extern void func_80147060(u8 *a0);
extern void func_80148634(void *a0);
extern void func_80148634(void *a0);
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
extern void func_80147060(u8 *a0);
extern void func_80147060(u8 *a0);
extern void func_801718AC(void *a0);
void func_801718AC(void *arg0);
void func_8017196C(s32 *a0, s8 a1);

void func_80170CF0(void* a0)
{
    extern void *D_8011F738;
    extern s32 D_8011F73C;
    extern s32 D_8011F740;
    s32 v1;
    void *p;
    ((void (*)(s32))D_8011F738)(a0);
    v1 = *(u8 *)(a0 + 0x217);
    if (v1 == 1) {
        goto case_1;
    }
    if (v1 <= 1) {
        goto done;
    }
    if (v1 == 2) {
        goto case_2;
    }
    goto done;
case_1:
    p = (*(void * *)&D_8011F73C);
    goto call;
case_2:
    p = (*(void * *)&D_8011F740);
call:
    func_801718AC(p);
done:
    ;
}
