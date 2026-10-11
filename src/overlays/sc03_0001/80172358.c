/* sc03_0001: func_80172358 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
struct U8;
struct U8 {
    char b[8];
} __attribute__((aligned(1)));
extern void func_8012A568(void (*a0)(void));

void func_80172358(u8 *a0, u8 *a1) {
    *(u16 *)(a0 + 6) = *(u16 *)(a1 + 0);
    *(u16 *)(a0 + 0xA) = *(u16 *)(a1 + 2);
    *(u16 *)(a0 + 0xE) = *(u16 *)(a1 + 4);
    *(struct U8 *)(a0 + 0x90) = *(struct U8 *)(a1 + 0);
    *(struct U8 *)(a0 + 0x88) = *(struct U8 *)(a0 + 0x90);
}
