/* SC02.CD member35: func_801825BC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B23C(void *a0);
extern void func_8012B23C(void *a0);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B23C(void *a0);
extern void func_8012B23C(void *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012B23C(void *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131B14(void);
extern void func_8012B23C(void *a0);
extern s32 func_80131A34(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_801825BC(s32 a0) {
    s32 s0 = a0;
    u16 v0 = *(u16 *)(s0 + 0x100);
    u16 v1 = *(u16 *)(s0 + 0x60);
    v0 |= 0x8000;
    v1 <<= 2;
    *(u16 *)(s0 + 0x100) = v0;
    *(u16 *)(s0 + 0x60) = v1;
    func_80131B14();
    *(u8 *)(s0 + 0xC2) = 0;
    *(u16 *)(s0 + 0x98) = 0;
    func_8012B23C((void *)s0);
    func_80131A34(s0, 0x8);
    func_8002D4C8(0xA74, 0);
}
