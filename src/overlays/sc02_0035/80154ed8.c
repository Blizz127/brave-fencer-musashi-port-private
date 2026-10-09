/* SC02.CD member35: func_80154ED8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern u8 D_80078E78[];
extern s16 D_80078E96;
extern u16 D_80078EA6;
extern u8 D_800D8D10[];
extern s16 D_80078E9E;
extern u16 D_80078EA6;
extern void func_801550FC(s32 a0);
void func_801550FC(s32 arg0);

void func_80154ED8(s32 a0, s32 a1) {
    *(s32 *)(a0 + 0xC8) = a1;
    if (D_80078E96 & 0x8000) {
        *(s32 *)(a0 + 0xC8) = a1 | 0x1000000;
        func_801550FC((s32)D_800D8D10);
        return;
    }
    if (D_80078E9E >= 0x10) {
        if (*(s16 *)&D_80078EA6 >= 0x10) {
            goto and_path;
        }
    }
    if ((*(s32 *)(a0 + 0x44) & 0xC0) != 0) {
        goto and_path;
    }
    *(s32 *)(a0 + 0xC8) = a1 | 0x1000000;
    func_801550FC(0x40000002);
    return;
and_path:
    *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) & 0xC0FFFFFF;
    func_801550FC(a1);
}
extern u8 D_80078E78[];
