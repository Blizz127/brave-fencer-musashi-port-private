/* SC02.CD member35: func_80174FBC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80175014(u8 *a0, u8 *a1, s32 a2);
extern s32 func_80175014(u8 *a0, u8 *a1, s32 a2);
s32 func_80175014(u8 *a0, u8 *a1, s32 a2);

void func_80174FBC(u8 *a0) {
    u16 *p = (u16 *)(a0 + 0x38);
    if ((*p & 0x7FFF) != 0) {
        func_80175014(a0, *(u8 **)(a0 + 0x34), *p & 0x7FFF);
        *p = *p - 1;
    } else {
        *p = *p | 0x8000;
    }
}
