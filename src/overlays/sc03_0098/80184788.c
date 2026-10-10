/* sc03_0098: func_80184788 from Druthulu/BFM-decomp
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
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 *D_80126B78;
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_80181CFC(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 *D_80126B78;
extern u8 D_8019E1F8[];
extern u8 D_801152A8[];
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
s32 aF80181CFC(s32 arg0, s32 arg1) __asm__("func_80181CFC");
s32 aF80181CFC(s32 arg0, s32 arg1) __asm__("func_80181CFC");
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8012A828(s32 a0, s32 a1);

void func_80184788(s32 a0) {
    extern s32 aD_801BB960 __asm__("D_801AD884");
    extern s32 aD_801AF698 __asm__("D_801A15BC");
    u16 temp;
    if (*(s32 *)(a0 + 0x94) == 0xD) {
        func_8002D4C8(0x702, 0x107F);
    }
    func_8012CBCC(a0);
    temp = *(u16 *)(a0 + 0x102) + 1;
    *(u16 *)(a0 + 0x102) = temp;
    if ((s16)temp == 0x1E) {
        *(u16 *)(a0 + 0x2) = 0x9;
        func_8012A828(a0, (s32)&aD_801BB960);
        *(u16 *)(a0 + 0x102) = 0;
        *(s32 *)(a0 + 0x14) = 0;
        *(s32 *)(a0 + 0x58) = ((s32)&aD_801AF698 | 0x40000000) | 0x20000000;
    }
}
