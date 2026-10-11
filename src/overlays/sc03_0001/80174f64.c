/* sc03_0001: func_80174F64 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80175014(u8 *a0, u8 *a1, s32 a2);
s32 func_80175014(u8 *a0, u8 *a1, s32 a2);

void func_80174F64(u8 *a0) {
    s32 r;
    u16 *p = (u16 *)(a0 + 0x38);
    r = func_80175014(a0, *(u8 **)(a0 + 0x34), *p & 0x7FFF);
    if (r != 0) {
        *p = *p | 0x8000;
    } else {
        *p = *p + 1;
    }
}
