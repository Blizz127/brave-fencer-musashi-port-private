/* sc03_0098: func_80145C54 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef int s32;
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);

void func_80145C54(void) {
    s32 a1;
    register s32 v1 __asm__("$3");
    s32 s0;
    a1 = func_800291B4(0x4A) & 0xFF;
    if (a1 >= 0x20) {
        v1 = a1 + 1;
        a1 = v1;
        if ((v1 & 0xF) == 0) {
            a1 = (u32)v1 >> 4;
        }
        s0 = a1 & 0xFF;
        func_800291A0(0x4A, s0);
        func_800291A0(0x50, s0);
    }
    a1 = func_800291B4(0x4D) & 0xFF;
    if (a1 >= 0x20) {
        v1 = a1 + 1;
        a1 = v1;
        if ((v1 & 0xF) == 0) {
            a1 = (u32)v1 >> 4;
        }
        func_800291A0(0x4D, a1 & 0xFF);
    }
}
