/* sc03_0098: func_80172560 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80013450(s32);
extern s32 func_80013450(s32);

s32 func_80172560(u8 *a0, u8 *a1) {
    *(s16 *)(a1 + 2) = *(u16 *)(a0 + 0xA);
    return func_80013450((s32)(a0 + 4)) < 0x10;
}
