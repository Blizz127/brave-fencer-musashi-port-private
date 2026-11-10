/* sc02_0037: func_80132DC4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
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
extern s32 func_80047E98(void *a0, void *a1);

void func_80132DC4(s32 a0, s32 a1, s32 a2) {
    s16 in[3];
    s16 out[4];
    in[0] = (u16)*(u16 *)(a1 + 0x0) - *(u16 *)(a0 + 0x6);
    in[1] = (u16)*(u16 *)(a1 + 0x2) - *(u16 *)(a0 + 0xA);
    in[2] = (u16)*(u16 *)(a1 + 0x4) - *(u16 *)(a0 + 0xE);
    func_80047E98(&in[0], &out[0]);
    *(s32 *)(a0 + 0x10) = out[0] * a2;
    *(s32 *)(a0 + 0x14) = out[1] * a2;
    *(s32 *)(a0 + 0x18) = out[2] * a2;
}
