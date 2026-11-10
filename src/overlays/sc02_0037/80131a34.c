/* sc02_0037: func_80131A34 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012A828(s32 a0, void *a1);

s32 func_80131A34(s32 a0, s32 a1)
{
    extern s32 func_80131CF4(s32);
    void *p;
    p = (void *)((int (*)(int, int))func_80131CF4)(*(s32 *)(a0 + 0xBC), a1);
    if (p != 0) {
        if (a1 == 0xB || a1 == 8 || a1 == 0x20) {
            *(s32 *)(a0 + 0xC4) |= 4;
        } else {
            *(s32 *)(a0 + 0xC4) &= -5;
        }
        func_8012A828(a0, p);
        return 1;
    }
    return 0;
}
