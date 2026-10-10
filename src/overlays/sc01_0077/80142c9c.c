/* sc01_0077: func_80142C9C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012CBF4(s32 a0);

void func_80142C9C(s32 * arg0)
{
    u32 uVar1;
    if (*(s16 *)((u8 *)arg0 + 0x102) < 2) {
        uVar1 = ((s32 (*)(void))func_8012CBF4)();
        if (0x180000 < *(s32 *)((u8 *)arg0 + 0x14)) {
            *(s32 *)((u8 *)arg0 + 0x14) = 0x180000;
        }
        if (((uVar1 & 0x6000) != 0) || (0x100 < *(s16 *)((u8 *)arg0 + 0xA))) {
            if (*(s16 *)((u8 *)arg0 + 0x102) == 0) {
                *(s32 *)((u8 *)arg0 + 0x14) = 0xFFF80000;
            }
            *(s16 *)((u8 *)arg0 + 0x102) = *(s16 *)((u8 *)arg0 + 0x102) + 1;
        }
    }
}
