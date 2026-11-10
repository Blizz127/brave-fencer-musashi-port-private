/* sc02_0037: func_8012B030 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 func_80134510(s32 arg);

s32 func_8012B030(u8 *a0) {
    u16 local[3];
    local[0] = *(u16 *)(a0 + 0x6);
    local[1] = *(u16 *)(a0 + 0xA);
    local[2] = *(u16 *)(a0 + 0xE);
    if (func_80134510((s32)local) == 0) {
        return 0;
    }
    *(u16 *)(a0 + 0x6) = local[0];
    *(u16 *)(a0 + 0xA) = local[1];
    *(u16 *)(a0 + 0xE) = local[2];
    *(u16 *)(a0 + 0xC) = 0;
    *(u16 *)(a0 + 0x8) = 0;
    *(u16 *)(a0 + 0x4) = 0;
    return 1;
}
