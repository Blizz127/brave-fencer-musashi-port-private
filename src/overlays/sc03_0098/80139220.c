/* sc03_0098: func_80139220 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139DC8(void);
extern void func_80139DC8(void);
extern void func_80139DC8(void);
extern void func_801392C8(void *a0);
void func_801392C8(void *a0);
void func_80139DC8(void);

s32 func_80139220(s32 a0) {
    s32 v1;
    *(s16 *)(a0 + 0x14) = 0;
    *(s16 *)(a0 + 0x12) = (*(u16 *)(a0 + 0x12) + 1) % (*(s16 *)(a0 + 0x2E) + 1);
    func_80139DC8();
    v1 = *(u16 *)(a0 + 0x12) - *(u16 *)(a0 + 0x16);
    if (v1 != -1) {
        if (v1 < *(s16 *)(a0 + 0x2E)) {
            return 0;
        }
    }
    func_801392C8((void *)a0);
    return 1;
}
