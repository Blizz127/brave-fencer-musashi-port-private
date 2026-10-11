/* sc03_0001: func_8016D464 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
short func_8016CF04(s32 param_1, s32 param_2);
extern void func_800D22E4(s32 a0);
extern short func_8016CF04();

void func_8016D464(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x34);
    s32 v0;
    func_800D22E4((s32)a0);
    func_8016CF04((s32)a0, 1);
    v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == -1 || *(u16 *)s1 != 1) {
        *(u16 *)(a0 + 0x2) = *(u16 *)(a0 + 0x2) + 1;
    }
}
