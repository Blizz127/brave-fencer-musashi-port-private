/* sc01_0077: func_8016D778 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 D_80126B9C;
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern s32 D_80126B9C;
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern s32 D_80126B9C;

void func_8016D778(s32 a0) {
    s32 s0 = a0;
    s32 p;
    s16 sp[6];
    if (*(s16 *)(s0 + 0x28) == *(s16 *)(*(s32 *)(s0 + 0x30) + 0x36)) {
        if ((D_80126B9C & 0x20) != 0) {
            goto func_80010178;
        }
    }
    ((void (*)(s32))func_80146C3C)(s0);
    return;
func_80010178:
    p = *(s32 *)(s0 + 0x20);
    *(u16 *)(p + 0x18) = *(u16 *)(p + 0x18) ^ 0x400;
    *(u16 *)(p + 0x1A) = *(u16 *)(p + 0x1A) ^ 0x200;
    sp[0] = *(u16 *)(s0 + 0x12);
    sp[1] = *(u16 *)(s0 + 0x16);
    sp[2] = *(u16 *)(s0 + 0x1A);
    func_800D20C0(&sp[0], &sp[4], 6);
    *(u16 *)(s0 + 6) = sp[0];
    *(u16 *)(s0 + 0xA) = sp[1];
    *(u16 *)(s0 + 0xE) = sp[2];
}
