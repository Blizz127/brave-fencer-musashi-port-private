/* sc03_0098: func_8018414C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 *D_80126B78;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801152A8[];
extern u8 D_801152A8[];
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 *D_80126B78;
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012B23C(void *a0);
extern void func_80181CFC(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B23C(void *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 *D_80126B78;
extern u8 D_8019E1F8[];
extern u8 D_801152A8[];
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
s32 aF80181CFC(s32 arg0, s32 arg1) __asm__("func_80181CFC");
s32 aF80181CFC(s32 arg0, s32 arg1) __asm__("func_80181CFC");
extern void func_8012B23C(void *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131B14(void);
extern void func_8012B23C(void *a0);
extern s32 func_80131A34(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_8018414C(s32 a0) {
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
