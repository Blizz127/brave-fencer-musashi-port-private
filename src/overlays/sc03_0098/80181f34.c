/* sc03_0098: func_80181F34 from Druthulu/BFM-decomp
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
extern u8 D_801202A0[];

s32 func_80181F34(void)
{
    s32 a1, a0;
    u8 *v1;
    a1 = 0;
    a0 = 0;
    v1 = D_801202A0;
    do {
        if (*(u16 *)(v1 + 0) == 0x17F && (*(u16 *)(v1 + 0x70) & 0xF) == 0)
            a1++;
        a0++;
        v1 += 0x10C;
    } while (a0 < 0x60);
    return a1 < 0xB;
}
