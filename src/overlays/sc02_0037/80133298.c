/* sc02_0037: func_80133298 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { s32 w[8]; } Blk32L_80133298;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012B2CC(s32 a0);
extern u8 D_80126B5C;
extern void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2);
extern void func_8012F1A4(s32 *a0, s32 a1, s32 *a2);
extern void *memcpy(void *, const void *, u32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131CF4(s32 a0);
extern void func_8012B2CC(s32 a0);
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
extern void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2);
extern void func_8012B2CC(s32 a0);
extern void func_8013339C(s16 *a0, s16 *a1);
extern void func_8012F1A4(s32 *a0, s32 a1, s32 *a2);
void func_8013339C(short *param_1, short *param_2);

void func_80133298(s32 *a0)
{
    extern u8 D_80126B5C;
    extern s32 D_80126B5C_w __asm__("D_80126B5C");
    extern s32 D_80126B60;
    extern s32 D_80126B64;
    s32 in[3];
    s32 out[3];
    s32 tmp[3];
    Blk32L_80133298 m;
    in[0] = D_80126B5C_w;
    in[1] = D_80126B60;
    in[2] = D_80126B64;
    func_8012F0BC((s32 *)(a0[8] + 0x34), in, tmp);
    func_8012B2CC((s32)a0);
    m = *(Blk32L_80133298 *)(a0[8] + 0x34);
    func_8013339C((s16 *)&m, (s16 *)(a0[8] + 0x18));
    func_8012F1A4((s32 *)&m, (s32)tmp, out);
    D_80126B5C_w = out[0];
    D_80126B60 = out[1];
    D_80126B64 = out[2];
}
