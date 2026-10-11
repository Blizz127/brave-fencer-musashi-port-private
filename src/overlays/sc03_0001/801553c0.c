/* sc03_0001: func_801553C0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern void func_8001D150(s32, s32);
extern s32 func_80029178(s32);
extern void func_8001D150(s32, s32);

void func_801553C0(s32 a0) {
    s32 *flags;
    flags = (s32 *)(a0 + 0x44);
    if ((*flags & 4) != 0 || (func_80029178(0x12F) & 0xFF) != 0) {
        *flags = *flags & 0xEFFFFFFF;
    } else {
        *flags = *flags | 0x10000000;
    }
    func_8001D150(*(s32 *)(*(s32 *)(a0 + 0x20) + 0x24), 0x15);
}
