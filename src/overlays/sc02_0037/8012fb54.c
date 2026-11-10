/* sc02_0037: func_8012FB54 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_801319E0(s32 a0);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_8012FB54(s32 a0) {
    s32 s0 = a0;
    s32 v1;
    s32 p;
    if ((*(s32 *)(s0 + 0xB4) & 0x10000) != 0) {
        *(s32 *)(s0 + 0x4) = *(s32 *)(s0 + 0x4) + *(s32 *)(s0 + 0x10);
        *(s32 *)(s0 + 0x8) = *(s32 *)(s0 + 0x8) + *(s32 *)(s0 + 0x14);
        *(s32 *)(s0 + 0xC) = *(s32 *)(s0 + 0xC) + *(s32 *)(s0 + 0x18);
        v1 = *(s32 *)(s0 + 0x1C) - 1;
        *(s32 *)(s0 + 0x1C) = v1;
        if (v1 == 0) {
            func_801319E0(s0);
        } else {
            p = func_80143B6C(s0, 1);
            if (p != 0) {
                *(s16 *)(p + 0xA) = *(u16 *)(p + 0xA) + *(u16 *)(s0 + 0xAC);
            }
            if (*(s32 *)(s0 + 0x1C) == 0x13) {
                func_8002D4C8(0x8F2, 0);
            }
        }
    }
    func_80131CA8(s0, 0x36);
}
