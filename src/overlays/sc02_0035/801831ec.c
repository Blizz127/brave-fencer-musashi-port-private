/* SC02.CD member35: func_801831EC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);

void func_801831EC(void *a0) {
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18) = *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18) + 0x200;
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1a) = *(s16 *)(*(s32 *)(a0 + 0x20) + 0x1a) + -0x200;
    if (*(s16 *)(*(s32 *)(a0 + 0x20) + 0x1a) < 0x401) {
        func_8012C218(a0);
    }
}
