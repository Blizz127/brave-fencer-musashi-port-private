/* sc03_0098: func_8012A094 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void *memcpy(void *, const void *, unsigned int);

void func_8012A094(s32 a0) {
    *(s32 *)(a0 + 0x8) = *(s32 *)(a0 + 0xC);
    *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x14);
    memcpy((void *)(a0 + 0x18), (void *)(a0 + 0x20), 8);
    *(u16 *)(a0 + 0x28) = *(u16 *)(a0 + 0x2E);
    *(u16 *)(a0 + 0x2A) = *(u16 *)(a0 + 0x30);
    *(u16 *)(a0 + 0x2C) = *(u16 *)(a0 + 0x32);
}
