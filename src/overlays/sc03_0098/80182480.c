/* sc03_0098: func_80182480 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 *D_80126B78;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801152A8[];
extern u8 D_801152A8[];
extern void func_8012A568(void (*a0)(void));
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 *D_80126B78;
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80181CFC(s32 a0, s32 a1);
extern s32 *D_80126B78;
extern u8 D_8019E1F8[];
extern u8 D_801152A8[];
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
s32 aF80181CFC(s32 arg0, s32 arg1) __asm__("func_80181CFC");
s32 aF80181CFC(s32 arg0, s32 arg1) __asm__("func_80181CFC");
extern void func_801292C8(u8 *a0);
extern void func_801827A0(s32 a0);
extern void func_801292C8(u8 *a0);
extern void func_801827A0(s32 a0);
extern void func_801292C8(u8 *a0);
extern void func_801292C8(u8 *a0);
extern void func_801827A0(s32 a0);
void func_801827A0(s32 a0);

void func_80182480(s32 arg0) {
    register s32 s0 __asm__("$16");
    s0 = arg0;
    func_801827A0(arg0);
    if (*(u16 *)(*(s32 *)(s0 + 0x2C)) == 0) {
        func_801292C8((u8 *)s0);
    }
    *(s32 *)(s0 + 0x1C) += 1;
}
