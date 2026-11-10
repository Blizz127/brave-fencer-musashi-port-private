/* sc02_0037: func_8013361C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void *memcpy(void *, const void *, u32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131CF4(s32 a0);
extern void func_80131CA8(s32 a0, s32 a1);
extern s32 func_80131CF4(s32 a0);
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void *memcpy(void *, const void *, u32);

s32 func_8013361C(s16 *a0, s16 *a1, s16 *a2, s16 *a3) {
    if ((*(s16 *)((s32)a0 + 4) + *(s16 *)((s32)a2 + 0) > *(s16 *)((s32)a1 + 6) + *(s16 *)((s32)a3 + 0)) ||
        (*(s16 *)((s32)a0 + 6) + *(s16 *)((s32)a2 + 0) < *(s16 *)((s32)a1 + 4) + *(s16 *)((s32)a3 + 0)) ||
        (*(s16 *)((s32)a0 + 0xC) + *(s16 *)((s32)a2 + 4) > *(s16 *)((s32)a1 + 0xE) + *(s16 *)((s32)a3 + 4)) ||
        (*(s16 *)((s32)a0 + 0xE) + *(s16 *)((s32)a2 + 4) < *(s16 *)((s32)a1 + 0xC) + *(s16 *)((s32)a3 + 4)) ||
        (*(s16 *)((s32)a0 + 8) + *(s16 *)((s32)a2 + 2) > *(s16 *)((s32)a1 + 0xA) + *(s16 *)((s32)a3 + 2)) ||
        (*(s16 *)((s32)a0 + 0xA) + *(s16 *)((s32)a2 + 2) < *(s16 *)((s32)a1 + 8) + *(s16 *)((s32)a3 + 2))) {
        return 0;
    }
    return 1;
}
