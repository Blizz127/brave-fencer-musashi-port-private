/* sc02_0037: func_801392C8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_801395D4(void *);
void func_801395D4(void * a0);

void func_801392C8(void *a0) {
    func_801395D4(a0);
    *(s8 *)((s32)a0 + 0x1E) = 0;
    *(s16 *)((s32)a0 + 0x4) = 5;
}
