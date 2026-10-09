/* SC02.CD member35: func_8017D710 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 *D_80126B78;
extern void func_8012A568(void (*a0)(void));

void func_8017D710(s32 a0) {
    s16 t;
    *(u16 *)(*(u32 *)(a0 + 0x20) + 0x10) += *(u16 *)(a0 + 0xFE);
    *(u16 *)(*(u32 *)(a0 + 0x20) + 0x12) += *(u16 *)(a0 + 0x100);
    *(u16 *)(*(u32 *)(a0 + 0x20) + 0x14) += *(u16 *)(a0 + 0x102);
    t = *(s16 *)(a0 + 0x100);
    if (t != 0 && *(u8 *)(a0 + 0x74) != 0) {
        *(u16 *)((s32)D_80126B78 + 0x12) += t;
    }
}
