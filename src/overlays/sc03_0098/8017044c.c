/* sc03_0098: func_8017044C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80147060(u8 * a0);
extern void func_80148634(void *a0);
extern s32 D_801151D4;
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
extern void func_80171928(void *a0);
extern void func_80171928(void *);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern void func_80171928(void *a0);
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171928(void *a0);
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171928(void *a0);
extern s32 D_801151D4;
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171928(void *a0);
void func_80171928(void * a0);
void func_8017196C(s32 *a0, s8 a1);
s16 func_80171AB0(s32 param_1, void * _arg1);

void func_8017044C(u8 * a0)
{
    s16 buf[3];
    s32 *p;
    p = (s32 *)D_801151D4;
    buf[0] = (s16)p[0xF];
    buf[1] = (s16)p[0x10];
    buf[2] = (s16)p[0x11];
    if (func_80171AB0(a0, buf) == 0) {
        func_80171928((void *)a0);
    }
}
